/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
  let val = init;
  nums.forEach(function (num) {
    val = fn(val, num);
  });
  return val;
};
