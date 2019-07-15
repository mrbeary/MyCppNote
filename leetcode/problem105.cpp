
//使用的内存有点多，待改善
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        TreeNode * root = new TreeNode(preorder[0]);
        int i = 0;
        for (i = 0; i < inorder.size() && inorder[i] != preorder[0]; i++);
        vector<int> lInorder(inorder.begin(), inorder.begin() + i);
        vector<int> rInorder(inorder.begin() + i + 1, inorder.end());
        vector<int> lPreorder(preorder.begin()+1, preorder.begin()+i+1);
        vector<int> rPreorder(preorder.begin()+i+1, preorder.end());
        root->left = buildTree(lPreorder, lInorder);
        root->right = buildTree(rPreorder, rInorder);
        return root;
    }

};
