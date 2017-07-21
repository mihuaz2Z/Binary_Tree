//
//  main.cpp
//  把排序数组转换为高度最小的二叉搜索树
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给一个排序数组（从小到大），将其转换为一棵高度最小的排序二叉树。
 注意事项
 
 There may exist multiple valid solutions, return any of them.
 样例
 给出数组 [1,2,3,4,5,6,7], 返回
     4
   /   \
  2     6
 / \    / \
1   3  5   7
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void printTree(TreeNode*root){
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->val;
    printTree(root->right);
}


class Solution {
public:
    
    
    TreeNode * createRoot(int left,int right,vector<int> nums) {
        cout <<"left " << left <<"right "<<right<<endl;
        if (left > right) {
            return NULL;
        }
        else if (left == right) {
            TreeNode * root = new TreeNode(nums[left]);
            return  root;
        }
        int mid = int((right+left)/2.+0.5);
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = createRoot(left, mid-1, nums);
        root->right = createRoot(mid+1, right, nums);
        return root;
    }
    
    
    TreeNode *sortedArrayToBST(vector<int> &A) {
        if (A.size() == 0) {
            return NULL;
        }
        
        TreeNode * root = createRoot(0, (int)A.size()-1, A);
        
        return root;
        
    }
};



int main(int argc, const char * argv[]) {
   
    Solution s;
    vector<int> A = {};
    TreeNode * root = s.sortedArrayToBST(A);
    printTree(root);
    
    return 0;
}
