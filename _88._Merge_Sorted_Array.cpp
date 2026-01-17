class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n, i = 0, j = 0;
        
        vector<int> new_array;
        
        while ( i < m && j < n ) {
            if ( i < m && nums1[i] < nums2[j] ) {
                new_array.push_back(nums1[i]);
                i++;
            } else {
                new_array.push_back(nums2[j]);
                j++;
            }
        }

        for(i; i < m; i++ ) {
            new_array.push_back(nums1[i]);
        }

        for(j; j < n; j++ ) {
            new_array.push_back(nums2[j]);
        }

        for(i = 0; i < m+n; i++ ) {
            nums1[i] = new_array[i];
        }
    }
};