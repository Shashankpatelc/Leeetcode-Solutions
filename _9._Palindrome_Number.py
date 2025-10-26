class Solution {
    public boolean isPalindrome(int x) {
        // Create a StringBuilder res to reverse the number
        StringBuilder res = new StringBuilder();

        // Append the numbers in x to rev StringBuilder
        res.append(x);

        // Reverse the StringBulder
        res.reverse();

        // Check the number is palindrome or not and return 
        return (Integer.toString(x).equals(res.toString()));
    }
}