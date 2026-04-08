/**
 * @return {Generator<number>}
 */
var fibGenerator = function* () {
  let prev = 1,
    prev_prev = 0;
  yield 0;
  yield 1;
  while (true) {
    curr = prev + prev_prev;
    yield curr;
    prev_prev = prev;
    prev = curr;
  }
};
