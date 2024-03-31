impl Solution {
    pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {
        let mut digit_sum = 0;
        let mut num = x;
        while num > 0 {
            digit_sum += num % 10;
            num /= 10;
        }
        if x % digit_sum != 0 { return -1 }
        return digit_sum;
    }
}

