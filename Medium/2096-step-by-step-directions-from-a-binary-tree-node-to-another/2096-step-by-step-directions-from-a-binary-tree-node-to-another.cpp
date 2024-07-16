/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, string& path, int n){
        if(root == NULL)
            return false;
        if(root->val == n)
            return true;
        path.push_back('L');
        if(findPath(root->left, path, n))
            return true;
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right, path, n))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* Naive(TreeNode* root, int p, int q){
        if(root == NULL)
            return NULL;
        if(root->val == p || root->val == q)
            return root;
        TreeNode* lca1 = Naive(root->left, p, q);
        TreeNode* lca2 = Naive(root->right, p, q);
        if(lca1 != 0 && lca2 != 0)
            return root;
        if(lca2 == 0)
            return lca1;
        else
            return lca2;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathP, pathQ;
        TreeNode* lca = Naive(root, startValue, destValue);
        string ans;
        
        findPath(lca, pathP, startValue);
        findPath(lca, pathQ, destValue);
        ans.append(pathP.length(), 'U');
        ans.append(pathQ);
        return ans;
    }
};