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

type OptNode = Option<Rc<RefCell<TreeNode>>>;
impl Solution {
    pub fn add_row(root: &OptNode, val: i32, depth: i32, left: bool) -> OptNode {
        if depth == 0 {
            let mut node = TreeNode::new(val);
            if left { node.left = root.clone(); }
            else { node.right = root.clone(); }
            return Some(Rc::new(RefCell::new(node)));
        }
        if root.is_none() { None }
        else {
            let mut n = root.as_ref().unwrap().borrow_mut();
            n.left = Self::add_row(&n.left, val, depth - 1, true);
            n.right = Self::add_row(&n.right, val, depth - 1, false);
            root.clone()
        }
    }
    pub fn add_one_row(root: OptNode, val: i32, depth: i32) -> OptNode {
        Self::add_row(&root, val, depth - 1, true)
    }
}

