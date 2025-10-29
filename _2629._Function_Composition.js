var compose = function( functions ) {
    return function( x ) {
        let r = x;              // variable to store result
        for(let i = functions.length -1 ; i >= 0; i--){        // loop through all function in reverse order
            r = functions[i](r);                     // call each function and store the return value in r and pass it again ti calculate the same value
        }
        return r;               //return the result value
    }
};