
Array.prototype.groupBy = function(fn) {

    let obj = {}

    for(let i=0;i<this.length;i++){

        let key = fn(this[i])

        if( obj[key] !== undefined ) {
            obj[key].push(this[i])
        }
        else{
            obj[key] = [this[i]]
        }
    }

    return obj
};
