
if (Array.isArray(a)) {
    let newarr = []
        for (let i = 0; i < a.length; i++) {
            let sub = fun(a[i])
            if (sub) {
                newarr.push(sub)
            }
        }
    return newarr
}