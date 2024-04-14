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
impl Solution {
    fn solve(root: &Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let n = node.borrow();
                match is_left && n.left.is_none() && n.right.is_none() {
                    true => n.val,
                    false => Self::solve(&n.left, true) + Self::solve(&n.right, false),
                }
            }
        }
    }
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::solve(&root, false)
    }
}

