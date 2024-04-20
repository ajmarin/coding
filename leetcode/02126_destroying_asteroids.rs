impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        let mut mass = mass as i64;
        asteroids.sort_unstable();

        for a in asteroids {
            let a64 = a as i64;
            if a64 > mass { return false; }
            mass += a64;
        }
        true
    }
}

