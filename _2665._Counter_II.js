var createCounter = function(init) {

    let val = init
    
    function increment(){               // increment function
        val++;                          // increment value
        return val;                     // return the incremented value
    }
    
    function decrement(){               // decremnt function
        val--;                          // decrement the value
        return val;                     // return the decremnted value
    }
    
    function reset(){                   // reset function
        val = init;                     // reset the value
        return (val);                   // return the reseted value
    }
   
   return{increment,decrement,reset}    // return all function from createCounter
};
