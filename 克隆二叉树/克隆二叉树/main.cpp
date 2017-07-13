//
//  main.cpp
//  克隆二叉树
//
//  Created by Ruiwen Feng on 2017/7/13.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

class Solution {
public:
    
    void clone (TreeNode * src_root, TreeNode * dst_root) {
        if (src_root == NULL) {
            return;
        }
        dst_root->val = src_root->val;
        if (src_root->left != NULL) {
            dst_root->left = new TreeNode(0);
            clone(src_root->left,dst_root->left);
        }
        if (src_root->right != NULL) {
            dst_root->right = new TreeNode(0);
            clone(src_root->right,dst_root->right);
        }
    }
    
    TreeNode* cloneTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* cloneRoot = new TreeNode(0);
        clone(root,cloneRoot);
        return cloneRoot;
    }
};

void printTree (TreeNode * root ) {

    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void createTree(string *fullString,TreeNode * root) {
    queue<TreeNode*>nodeQueue;
    nodeQueue.push(root);
    int index = 0;
    for (int i = 0; i < fullString->size(); i ++) {
        if (fullString->c_str()[i] == '#') {
            continue;
        }
        root = nodeQueue.front();
        char value = fullString->c_str()[i];
        root->val = stoi(&value);
        int left_child = (index+1)*2-1;
        int right_child = (index+1)*2;
        if (left_child < fullString->size() && fullString->c_str()[left_child] != '#') {
            char value = fullString->c_str()[left_child];
            root->left = new TreeNode(stoi(&value));
        }
        if (right_child < fullString->size() && fullString->c_str()[right_child] != '#') {
            char value = fullString->c_str()[right_child];
            root->right = new TreeNode(stoi(&value));
        }
        if (root->left != NULL) {
            nodeQueue.push(root->left);
        }
        if (root->right != NULL) {
            nodeQueue.push(root->right);
        }
        nodeQueue.pop();
        index += 1;
    }
}



int main(int argc, const char * argv[]) {
    string fullString = "1234567";
    TreeNode *root = new TreeNode(0);
    createTree(&fullString,root);
    Solution solution;
    TreeNode * clonde_root  = solution.cloneTree(root);
    printTree(clonde_root);
    
    return 0;
}
