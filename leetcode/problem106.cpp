

//用的空间有点多，待改善
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!inorder.size())
            return NULL;
        int rootVal = postorder[postorder.size() - 1];
        TreeNode * root = new TreeNode(rootVal);
        int i = 0;
        for (i = 0; i < inorder.size() && inorder[i] != rootVal ; i++);
        vector<int> lInorder(inorder.begin(), inorder.begin()+i);
        vector<int> lPostorder(postorder.begin(), postorder.begin() + i);
        vector<int> rInorder(inorder.begin() + i + 1, inorder.end());
        vector<int> rPostorder(postorder.begin() + i,postorder.end() - 1);
        root->left = buildTree(lInorder, lPostorder);
        root->right = buildTree(rInorder, rPostorder);
        return root;
    }
};