use std::collections::VecDeque;

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, from: i32, to: i32) -> bool {
        let n = n as usize;
        let to = to as usize;
        let mut adj = vec![vec![]; n];
        edges.iter().for_each(|e| {
            let (u, v) = (e[0] as usize, e[1] as usize);
            adj[u].push(v);
            adj[v].push(u);
        });

        let mut q = VecDeque::from([from as usize]);
        let mut r = vec![false; n];

        r[from as usize] = true;

        while let Some(at) = q.pop_front() {
            for &next in adj[at].iter() {
                if !r[next] {
                    r[next] = true;
                    q.push_back(next);
                }
            }
            if r[to] { return true; }
        }
        false
    }
}

