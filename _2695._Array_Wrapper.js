
var ArrayWrapper = function(nums) {
    this.num = nums
};

ArrayWrapper.prototype.valueOf = function() {
    let sum = 0
    for(let i=0;i<this.num.length;i++){
        sum = sum+this.num[i]
    }
    return sum
}


ArrayWrapper.prototype.toString = function() {
    return `[${this.num}]`
}
