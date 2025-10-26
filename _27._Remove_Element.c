int removeElement(int* nums, int numsSize, int val) {
    int i = 0,j,temp;
    if(numsSize < 1){
        return numsSize;
    }
    for(i = 0; i < numsSize; i++){
        if(nums[i] == val){
            j = 0;
        }
        else{
            j = 1;
            break;
        }
    }
    if(j == 0){
        return j;
    }
    i = 0;
    j = numsSize-1;
    while(i <= j){
        while(nums[i] != val && i < j){
            i++;
        }
        while(nums[j] == val && j > i){
            j--;
        }
        nums[i] = nums[i] + nums[j] - (nums[j] = nums[i]);
        i++;
        j--;
    }
    while(i >= 0 && nums[i-1] == val){
        i--;
    }
    return i;
}
