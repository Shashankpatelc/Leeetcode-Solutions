class Solution {
    public boolean canCreate( String s, String next, int i, HashMap<String, List<Character>> map, HashSet<String> memo) {

        if ( s.length() == 1 ) {
            return true;
        }

        if ( i==0 && memo.contains(s)) {
            return false;
        }

        if ( i == s.length() - 1) {
            return canCreate(next, "", 0, map, memo);
        }

        String sub = s.substring(i,i+2);
        
        if( map.get(sub) == null ) {
            memo.add(s);
            return false;
        }

        List<Character> row = map.get(sub);
        for( char ch : row ) {
            if(canCreate(s, next+ch, i+1, map, memo)) {
                return true;
            }
        }

        if( i == 0 ){
            memo.add(s);
        }

        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        HashMap<String, List<Character>> map = new HashMap<>();
        for(String s : allowed) {
            String key = s.substring(0, 2);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s.charAt(2));
        }

        HashSet<String> memo = new HashSet<>();
        return canCreate(bottom, "", 0, map, memo);
    }
}