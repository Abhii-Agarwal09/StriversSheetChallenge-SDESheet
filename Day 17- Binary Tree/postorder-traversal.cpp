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
    // left
    solve(root->left, ans);
    // right
    solve(root->right, ans);
    // node
    ans.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root)
  {
    // lrn
    vector<int> ans;
    solve(root, ans);
    return ans;
  }
};