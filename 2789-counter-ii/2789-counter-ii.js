/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var d = 0;
var r = 0;
var createCounter = function (init) {
    d = init;
    r = init;
    return {

        increment: function () {
            d++;
            return d;
        },
        decrement: function () {
            d--;
            return d;
        },
        reset: function () {
            d = r;
            return d;
        },



    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */