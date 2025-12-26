class Solution {
    public int bestClosingTime(String customers) {
    int minIndex = 0, minPenalty = customers.length(), currentPenalty = 0;
    int yCount = 0;
    
    for (char c : customers.toCharArray()) {
        if (c == 'Y') yCount++;
    }
    
    for (int j = 0; j <= customers.length(); j++) {
        if (j > 0) {
            if (customers.charAt(j - 1) == 'Y') yCount--;
            else currentPenalty++;
        }
        int penalty = currentPenalty + yCount;
        if (penalty < minPenalty) {
            minPenalty = penalty;
            minIndex = j;
        }
    }
    return minIndex;
}
}