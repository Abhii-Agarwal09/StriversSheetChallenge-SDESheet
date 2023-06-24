class Solution
{
public:
public:
  void solve(TreeNode *root, vector<int> &ans)
  {
    if (root == NULL)
    {
      return;
    }
    // node
    ans.push_back(root->val);
    // left
    solve(root->left, ans);
    // right
    solve(root->right, ans);
  }
  vector<int> preorderTraversal(TreeNode *root)
  {
    // nlr
    vector<int> ans;
    solve(root, ans);
    return ans;
  }
};