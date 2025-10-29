
var promiseAll = function(functions) {

    return new Promise((resolve,reject)=>{

        let result = new Array(functions.length)    // array to store result
        let count = 0       // variable to check when to resolve the promise

        functions.forEach((fn,i)=>{

            fn().then(              // resolved value of fn
                val => {
                    result[i] = val
                    count++
                    if(count === functions.length) resolve(result)  // return result in the array formet
                }
            )

            .catch(r => reject(r))      // rejected value of fn
        })
    })
};
