impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let parts = |s: String| s.split(".")
            .map(|v| v.parse::<i32>().unwrap())
            .collect::<Vec<i32>>();
        let (v1, v2) = (parts(version1), parts(version2));
        let mut index = 0;
        while index < v1.len() || index < v2.len() {
            let r1 = if index < v1.len() { v1[index] } else { 0 };
            let r2 = if index < v2.len() { v2[index] } else { 0 };
            if r1 < r2 { return -1; }
            else if r1 > r2 { return 1; }
            index += 1;
        }
        0
    }
}

