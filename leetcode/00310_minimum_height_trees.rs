use std::collections::{HashSet, VecDeque};
impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut n = n as usize;
        let mut graph = vec![0; n];
        let mut counts = vec![0; n];
        let mut min_height = 15_000;

        edges.iter().for_each(|e| {
            let (u, v) = (e[0] as usize, e[1] as usize);
            counts[u] += 1;
            counts[v] += 1;
            graph[u] ^= v;
            graph[v] ^= u;
        });

        let mut ans = vec![];
        let mut q = VecDeque::new();
        for (i, &c) in counts.iter().enumerate() {
            if c <= 1 { q.push_back(i); }
        }
        while !q.is_empty() {
            ans.clear();
            for _ in 0..q.len() {
                let rm = q.pop_front().unwrap();
                let other = graph[rm];
                counts[other] -= 1;
                graph[other] ^= rm;
                ans.push(rm as i32);
                if counts[other] == 1 { q.push_back(other); }
            }
        }
        ans
    }
}

