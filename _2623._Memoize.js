
function memoize(fn) {

    let cache = {};                         // To store the result

    return function(...args) {

        let key = JSON.stringify(args);     // Convert the argument to string

        if (key in cache){                  // check the value is present or not

            return cache[key];              // return if the value is present
        }

        let result = fn.apply(this,args)    // call the fn function 
        cache[key] = result;                // store the argument and result in the cache object
        return result;                      // return the result
    }
}

