class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings,(a,b)->{
            if(a[0] != b[0]){
                return Integer.compare(a[0],b[0]);
            } else {
                return Integer.compare(a[1],b[1]);
            }
        });

        int [] count = new int[n];
        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();
        PriorityQueue<long[]> busyRooms = new PriorityQueue<>((a,b) -> {
            if(a[0] != b[0]){
                return Long.compare(a[0],b[0]);
            }
            return Long.compare(a[1],b[1]);
        });

        for( int i = 0; i < n ; i++ ) {
            freeRooms.add(i);
        }

        for( int [] meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            long duration = end - start;

            while( !busyRooms.isEmpty() && busyRooms.peek()[0] <= start ) {
                long [] room = busyRooms.poll();
                freeRooms.add((int)room[1]);
            }

            if(!freeRooms.isEmpty()) {
                int room = freeRooms.poll();
                busyRooms.add(new long [] { start + duration, room });
                count[room]++;
            } else {
                long [] room = busyRooms.poll();
                busyRooms.add(new long [] { room[0] + duration, room[1] });
                count[(int)room[1]]++;
            }
        }

        int max = -1;
        int max_index = -1;
        for( int i = 0; i < count.length; i++){
            if( count[i] > max ){
                max = count[i];
                max_index = i;
            }
        }

        return max_index;
    }
}