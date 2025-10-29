
var chunk = function(arr, size) {

    let res = []                        // result array

    for(let i=0;i<arr.length;i+=size)   // loop to travel through array
        res.push(arr.slice(i,i+size))   // divide and add array to result

    return res                          // return result
};

