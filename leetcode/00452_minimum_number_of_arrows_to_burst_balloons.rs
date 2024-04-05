impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable();
        points.iter().fold((1, points[0][1]), |(arrows, reach), p| {
            if p[0] > reach { (arrows + 1, p[1]) }
            else { (arrows, reach.min(p[1])) }
        }).0
    }
}

