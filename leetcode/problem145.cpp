
//用递归实现
/* 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        func(root, result);
        return result;
    }
private:
    void func(TreeNode * root, vector<int> & res)
    {
        if (!root)
            return;
        func(root->left, res);
        func(root->right, res);
        res.push_back(root->val);
    }
};
*/

//迭代实现，利用了栈
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode * tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            if (tmp->left)
                stk.push(tmp->left);
            if (tmp->right)
                stk.push(tmp->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};