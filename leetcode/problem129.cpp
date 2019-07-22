

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        vector<int> path = {};
        func(root, path, result);
        return result;
    }
    
    void func(TreeNode * root, vector<int> & path, int & result)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            int tmp = 0;
            for (int i = 0; i < path.size(); i++)
                tmp = tmp * 10 + path[i];
            result += tmp;
            path.pop_back();
            return;
        }
        
        func(root->left, path, result);
        func(root->right, path, result);
        path.pop_back();
    }
};