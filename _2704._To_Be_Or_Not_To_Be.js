
var expect = function(val) {
    return{
        // toBe function for 1st condition
        toBe: (val2) =>{    
            if(val === val2){
                return true   // return true as given for specific condition 
            }
            else{
                throw new Error("Not Equal")  // throw an error as Not Equal as given
            }
        },
        // notToBe function for 2st condition
        notToBe: (val3) =>{  
            if(val !== val3){
                return true     // return true as given for specific condition
            }
            else{
                throw new Error("Equal")   //throw an error as Equal as given
            }
        }

    }
};
