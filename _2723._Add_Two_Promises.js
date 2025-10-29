
var addTwoPromises = async function(promise1, promise2) {       // Async function which take the resolved value of the promises
    return await promise1 + await promise2                      // wait for two promises and return there sum
};

