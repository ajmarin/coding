class Calculator {
  /**
   * @param {number} value
   */
  constructor(value) {
    this.val = value;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  add(value) {
    this.val += value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  subtract(value) {
    this.val -= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  multiply(value) {
    this.val *= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  divide(value) {
    if (value === 0) throw "Division by zero is not allowed";
    this.val /= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  power(value) {
    this.val = Math.pow(this.val, value);
    return this;
  }

  /**
   * @return {number}
   */
  getResult() {
    return this.val;
  }
}
