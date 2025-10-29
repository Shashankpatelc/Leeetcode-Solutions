
var reduce = function(nums, fn, init) {

    let val = init              // Value to store the result

    if(nums.length === 0)           // check the array length
        return init                 // return if the condition true    

    for(let i = 0; i < nums.length; i++)        // Loop through the array num to pass only one element at a time
        val = fn( val, nums[i])             // fn function

    return val                          // return the result 
};