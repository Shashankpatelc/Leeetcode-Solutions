
var once = function(fn) {

    let con = false                 // used to check the function is called or not
    let res                         // used to store the result

    return function(...args){       //return function

        if(!con){                   // if to check the function is called or not

            con = true              // change con value if function is called 
            res = fn(...args)       // call the fn function
            return res              // return the result
        }

        else{

            return undefined        // to return the undefined

        }
    }
};

