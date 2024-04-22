use std::collections::VecDeque;

impl Solution {
    pub fn open_lock(deadends: Vec<String>, target: String) -> i32 {
        let mut q = VecDeque::from([(0, 0)]);
        let mut seen = vec![false; 10_000];
        let target = target.parse::<usize>().unwrap();
        deadends.iter().for_each(|s| seen[s.parse::<usize>().unwrap()] = true);
        if seen[0] { q.pop_front(); }
        while let Some((at, turns)) = q.pop_front() {
            if at == target { return turns; }
            for div in &[1, 10, 100, 1000] {
                let d = (at / div) % 10;
                let state = at - d * div;
                for rotate in &[1, 9] {
                    let next = state + div * ((d + rotate) % 10);
                    if !seen[next] {
                        seen[next] = true;
                        q.push_back((next, turns + 1));
                    }
                }
            }
        }
        -1
    }
}

