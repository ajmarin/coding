/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let val = init;
  return {
    decrement: function () {
      return --val;
    },
    increment: function () {
      return ++val;
    },
    reset: function () {
      val = init;
      return init;
    },
  };
};
