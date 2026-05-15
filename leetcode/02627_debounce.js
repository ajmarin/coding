/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function (fn, t) {
  let timeout = null;
  return function (...args) {
    if (timeout) clearTimeout(timeout);
    timeout = setTimeout(() => fn(...args), t);
  };
};
