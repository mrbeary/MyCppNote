
//利用递归实现前序遍历二叉树
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
private:
    void preorder(TreeNode * root, vector<int> & result)
    {
        if (!root)
            return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};