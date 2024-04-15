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
    pub fn sum(root: &Option<Rc<RefCell<TreeNode>>>, value: i32) -> i32 {
        if root.is_none() { return 0; }
        let node = root.as_ref().unwrap();
        let n = node.borrow();
        let v = 10 * value + n.val;
        if n.left.is_none() && n.right.is_none() { v }
        else { Self::sum(&n.left, v) + Self::sum(&n.right, v) }
    }
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::sum(&root, 0)
    }
}

