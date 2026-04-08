/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  let chunk = [];
  const res = [];
  for (let i = 0; i < arr.length; ++i) {
    chunk.push(arr[i]);
    if (chunk.length == size) {
      res.push(chunk);
      chunk = [];
    }
  }
  if (chunk.length) res.push(chunk);
  return res;
};
