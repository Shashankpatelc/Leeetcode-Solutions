class Solution {
    public int countCollisions(String directions) {
        int left = 0, right = directions.length() - 1;
        
        while ( left < directions.length() && directions.charAt(left) == 'L' )
            left++;
        
        while ( right >= 0 && directions.charAt(right) == 'R' )
            right--;
        
        int colision = 0;
        
        for ( int i = left; i < right+1; i++ ){
            if ( directions.charAt(i) != 'S' ){
                colision++;
            }
        }

        return colision;
    }
}