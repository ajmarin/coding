/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  const memo = {};

  return function (...args) {
    const key = JSON.stringify(args);
    if (key in memo) return memo[key];
    const res = (memo[key] = fn.apply(this, args));
    return res;
  };
}
