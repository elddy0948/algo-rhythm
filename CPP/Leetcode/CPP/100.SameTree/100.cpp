#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if ((!p && q) || (p && !q) || (p->val != q->val))
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode p = TreeNode(1);
    p.left = new TreeNode(2);
    p.right = new TreeNode(3);

    TreeNode q = TreeNode(1);
    q.left = new TreeNode(2);
    q.right = new TreeNode(3);

    std::cout << sol.isSameTree(&p, &q);

    return 0;
}