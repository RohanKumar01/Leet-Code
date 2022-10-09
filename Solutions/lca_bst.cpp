// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// lc 235. Lowest Common Ancestor of a Binary Search Tree

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > max(p->val, q->val))
      return lowestCommonAncestor(root->left, p, q);
    if (root->val < min(p->val, q->val))
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};
