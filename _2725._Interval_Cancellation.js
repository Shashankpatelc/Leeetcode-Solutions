
var cancellable = function( fn, args, t) {

    fn( ...args)

    let cancelFn = () =>{

        clearInterval( interval)
    }

    let interval = setInterval(()=>{

        fn( ...args)
    }, t)

    return cancelFn
};

