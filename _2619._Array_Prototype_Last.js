
Array.prototype.last = function() {

    if( this.length !== 0)                       // check any element is in array or not
        return this[this.length - 1]             // return the last elment 

    else
        return -1                                // return -1 if there is no element  
};

