// Given the root of a binary tree, return an array of the largest value in each row of the tree

/**
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
 */

class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int depth, vector<int>& ans) {
    if (!root)
      return;
    if (depth + 1 > ans.size())
      ans.push_back(root->val);
    else
      ans[depth] = max(ans[depth], root->val);

    dfs(root->left, depth + 1, ans);
    dfs(root->right, depth + 1, ans);
  }
};
