class Solution
{
public:
  void solve(TreeNode *root, vector<int> &ans)
  {
    if (root == NULL)
    {
      return;
    }
    // left
    solve(root->left, ans);
    // node
    ans.push_back(root->val);
    // right
    solve(root->right, ans);
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    // lnr
    vector<int> ans;
    solve(root, ans);
    return ans;
  }
};