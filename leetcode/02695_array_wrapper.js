/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function (nums) {
  this.sum = nums.reduce((total, n) => total + n, 0);
  this.asString = `[${nums.join(",")}]`;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function () {
  return this.sum;
};

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function () {
  return this.asString;
};
