
var debounce = function(fn, t) {
    let r;
    return function(...args) {
        clearTimeout(r)
        r = setTimeout(()=>{
            fn(...args)
        },t)
    }
};
