var createCounter = function(n) {   // n is a variable which the value we have to increment
    return function() {  // return function
        return n++;     // where n value is going to increment
    };
};
