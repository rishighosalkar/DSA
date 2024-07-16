/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, vector<TreeNode*>& dp, TreeNode* n){
        if(root == NULL)
            return false;
        dp.push_back(root);
        if(root == n)
            return true;
        if(findPath(root->left, dp, n) || findPath(root->right, dp, n))
            return true;
        dp.pop_back();
        return false;
    }
    TreeNode* Naive(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> path1, path2;
        if(!findPath(root, path1, p) || !findPath(root, path2, q))
            return NULL;
        int i=0;
        for(i=0; i<path1.size()-1 && i<path2.size()-1; i++){
            if(path1[i+1] != path2[i+1])
                return path1[i];
        }
        if(path1.size() > path2.size())
            return path1[i];
        else
            return path2[i];
    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);

        if(lca1 && lca2)
            return root;
        if(lca1 == NULL)
            return lca2;
        else
            return lca1;
    }
};