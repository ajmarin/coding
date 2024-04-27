use std::collections::VecDeque;

impl Solution {
    pub fn find_rotate_steps(ring: String, key: String) -> i32 {
        let n = ring.len();
        let ring: Vec<char> = ring.chars().collect();
        let key: Vec<char> = key.chars().collect();

        let make_key = |ring_pos, key_pos| (ring_pos << 7) | key_pos;
        let mut costs = vec![100_000; make_key(n - 1, key.len())];
        let mut q = VecDeque::from([make_key(0, 0)]);
        costs[0] = 0;

        fn maybe_enqueue(q: &mut VecDeque<usize>, c: &mut Vec<i32>, state: usize, cost: i32) {
            if cost >= c[state] { return; }
            c[state] = cost;
            q.push_back(state);
        };

        while let Some(s) = q.pop_front() {
            let (ring_pos, key_pos) = (s >> 7, s & 127);
            let c = 1 + costs[s];
            if ring[ring_pos] == key[key_pos] {
                if key_pos == key.len() - 1 { return c; }
                maybe_enqueue(&mut q, &mut costs, make_key(ring_pos, key_pos + 1), c);
            }
            maybe_enqueue(&mut q, &mut costs, make_key((ring_pos + n - 1) % n, key_pos), c);
            maybe_enqueue(&mut q, &mut costs, make_key((ring_pos + 1) % n, key_pos), c);
        }

        -1
    }
}

