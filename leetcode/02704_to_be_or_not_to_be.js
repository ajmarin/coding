/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  return {
    notToBe: function (cmp) {
      if (cmp === val) throw "Equal";
      return true;
    },
    toBe: function (cmp) {
      if (cmp !== val) throw "Not Equal";
      return true;
    },
  };
};
