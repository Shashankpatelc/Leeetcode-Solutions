class Solution {
    public int minDeletionSize(String[] strs) {
        int count = 0;
        boolean[] isSorted = new boolean[strs.length - 1 ];
        for( int i = 0; i < strs[0].length(); i++){
            boolean wrong = false;
            for( int j = 0; j < strs.length - 1; j++){
                if(!isSorted[j] && strs[j].charAt(i) > strs[j+1].charAt(i) ){
                    wrong = true;
                    break;
                }
            }
            if( wrong ){
                count++;
            } else {
                for(int j = 0; j < strs.length - 1; j++){
                    if( strs[j].charAt(i) < strs[j+1].charAt(i) ){
                        isSorted[j] = true;
                    }
                }
            }
        }
        return count;
    }
}