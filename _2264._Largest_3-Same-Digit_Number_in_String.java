class Solution {
    public String largestGoodInteger(String num) {
        String s[] = {"000","111","222","333","444","555","666","777","888","999"};
        for(int i=s.length-1; i>-1; i--){
            if(num.contains(s[i])){
                return s[i];
            }
        }
        return "";
    }
}
