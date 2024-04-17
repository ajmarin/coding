// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut q = VecDeque::from([(root, "".to_string())]);
        let mut ans = str::repeat(&"z", 10_000);
        let az = ('a'..='z').into_iter().collect::<Vec<char>>();
        while let Some((Some(node), mut s)) = q.pop_front() {
            let n = node.borrow();
            s.push(az[n.val as usize]);
            if n.left.is_none() && n.right.is_none() {
                ans = ans.min(s.chars().rev().collect::<String>());
            } else {
                if n.left.is_some() { q.push_back((n.left.clone(), s.clone())); }
                if n.right.is_some() { q.push_back((n.right.clone(), s.clone())); }
            }
        }
        ans
    }
}

