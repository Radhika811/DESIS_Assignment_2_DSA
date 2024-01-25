#include <bits/stdc++.h>
using namespace std;

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
    vector<long long> dfs(TreeNode* root) {
        if (root==nullptr) return {-100000000,-100000000,1};
        vector <long long> t1=dfs(root->left);
        vector <long long> t2=dfs(root->right);
        bool ch=t1[2] & t2[2];
        if (t1[1]!=-100000000 && t1[1]>=root->val) ch=false;
        if (t2[0]!=-100000000 && t2[0]<=root->val) ch=false;
        vector <long long> tm={t1[0],t2[1],ch};
        if (tm[0]==-100000000) tm[0]=root->val;
        if (tm[1]==-100000000) tm[1]=root->val;
        return tm;
    }
    bool isValidBST(TreeNode* root) {
       
        vector <long long> tm=dfs(root);
        if (tm[2]==1) return true;
        return false;
    }
};