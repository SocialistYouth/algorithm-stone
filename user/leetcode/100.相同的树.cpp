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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        }
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while(!queue1.empty() && !queue2.empty()) {
            TreeNode* a = queue1.front();
            TreeNode* b = queue2.front();
            queue1.pop();
            queue2.pop();
            if(a->val != b->val) return false;
            else if (a->val == b->val && ((a->left==NULL)^(b->left==NULL)|| ((a->right==NULL)^(b->right==NULL)))) return false;
            else {
                if (a->left != NULL) {
                    queue1.push(a->left);
                    queue2.push(b->left);
                }
                if (a->right != NULL) {
                    queue1.push(a->right);
                    queue2.push(b->right);
                }
            }
        }
        if(queue1.empty() && queue2.empty())return true;
        else return false;
    }
};