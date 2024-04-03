use std::collections::HashSet;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut smap = [0; 128];
        let mut tmap = [0; 128];
        for (sb, tb) in s.bytes().zip(t.chars()) {
            let sb = sb as usize;
            let tb = tb as usize;
            if smap[sb] == 0 && tmap[tb] == 0 {
                smap[sb] = tb;
                tmap[tb] = sb;
            } else if smap[sb] != tb || tmap[tb] != sb {
                return false;
            }
        }
        true
    }
}

