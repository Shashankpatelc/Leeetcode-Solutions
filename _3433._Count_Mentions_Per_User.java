class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {

        events.sort((event1, event2) -> {

            int t1 = Integer.parseInt(event1.get(1));
            int t2 = Integer.parseInt(event2.get(1));

            if (t1 != t2) {
                return t1 - t2;
            }

            int p1 = event1.get(0).equals("OFFLINE") ? 0 : 1;
            int p2 = event2.get(0).equals("OFFLINE") ? 0 : 1;

            return p1 - p2;
        });

        int [] mentions = new int[numberOfUsers];
        long [] timestamp = new long[numberOfUsers];

        for(List<String> event: events){
            String msg = event.get(0);
            long time = Long.parseLong(event.get(1));
            String ids = event.get(2);

            if ( msg.equals("MESSAGE") ){
                
                if( ids.equals("ALL") ){
                    for( int i = 0; i < numberOfUsers; i++){
                        mentions[i]++;
                    }
                } else if( ids.equals("HERE") ){
                    for( int i = 0; i < numberOfUsers; i++){
                        if( time >= timestamp[i] ){
                            mentions[i]++;
                        }
                    }
                } else {
                    String[] tokens = ids.split(" ");
                    for( String token : tokens ){
                        int id = Integer.parseInt(token.substring(2));
                        mentions[id]++;
                    }
                }

            } else if ( msg.equals("OFFLINE") ){
                int offlineUserId = Integer.parseInt(ids);
                timestamp[offlineUserId] = time + 60;
            }
        }
        return mentions;
    }
}