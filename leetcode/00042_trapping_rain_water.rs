impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut right = height.len() as usize - 1;
        let mut water_height = 0;
        let mut trapped = 0;

        while left <= right {
            let land = height[left].min(height[right]);
            water_height = water_height.max(land);
            trapped += water_height;
            if land == height[left] { left += 1 }
            else { right -= 1 }
        }
        trapped - height.iter().fold(0, |sum, h| sum + h)
    }
}

