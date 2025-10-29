var filter = function(arr, fn) {
    let filteredArr =[]         // Array to store the result
    for(let i=0; i< arr.length;i++)         // Loop through array
    {
        if(fn(arr[i],i)){               // check the condition for value to decide wether to add or not 
            filteredArr.push(arr[i])            // Adding the array elemnt to array
        }
    }
    return filteredArr              // return the result of the function
};