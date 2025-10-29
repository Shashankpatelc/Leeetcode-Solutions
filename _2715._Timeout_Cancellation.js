var cancellable = function(fn, args, t) {
    let cancelFn = function(){
        clearTimeout(timer)
    }
    let timer = setTimeout(()=>{
        fn(...args)
    },t)
    return cancelFn
};
