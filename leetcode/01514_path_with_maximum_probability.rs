use std::collections::VecDeque;

impl Solution {
    pub fn max_probability(n: i32, edges: Vec<Vec<i32>>, succ_prob: Vec<f64>, source: i32, target: i32) -> f64 {
        let n = n as usize;
        let mut adj = vec![vec![]; n];
        edges.iter().zip(succ_prob).for_each(|(e, p)| {
            let (u, v) = (e[0] as usize, e[1] as usize);
            adj[u].push((v, p));
            adj[v].push((u, p));
        });

        let mut q = VecDeque::new();
        q.push_back((source as usize, 1.));
        let mut best = vec![0.; n];
        best[source as usize] = 1.;

        while let Some((u, p)) = q.pop_front() {
            if p < best[u] { continue; }
            for &(v, cost) in adj[u].iter() {
                let prob = p * cost;
                if prob > best[v] {
                    best[v] = prob;
                    q.push_back((v, prob));
                }
            }
        }
        best[target as usize]
    }
}

