class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        if( n < 3){
            return false;
        }

        if(arr[n - 2] < arr[n - 1] ){
            return false;
        }

        if( arr[0] > arr[1])
            return false;
            
        for(i = 0; i < n - 1; i++){
            if(arr[i] == arr[i+1]){
                return false;
            } else if( arr[i] > arr[i+1] ){
                break;
            }
        }
        cout<<i;
        for(i; i < n - 1; i++){
            if(arr[i] < arr[i+1] || arr[i] == arr[i+1]){
                return false;
            }
        }

        return true;
    }
};