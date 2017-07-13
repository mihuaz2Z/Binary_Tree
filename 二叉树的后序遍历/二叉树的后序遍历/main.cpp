//
//  main.cpp
//  二叉树的后序遍历
//
//  Created by Ruiwen Feng on 2017/7/13.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

//* Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


void printTree(TreeNode * root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printTree(root->right);
    cout<<root->val<<" ";
}


class Solution {
    vector<int> vector_value;
public:
    
    void printTree(TreeNode * root) {
        if (root == NULL) {
            return;
        }
        printTree(root->left);
        printTree(root->right);
        vector_value.push_back(root->val);
        cout << root -> val;
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        printTree(root);
        return vector_value;
    }
};


void createTree(string string,TreeNode * root) {
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    TreeNode * commonNode;
    for (int i = 0,index = 0; i < string.size(); i ++) {
        if (string[i] == '#') {
            continue;
        }
        commonNode = nodeQueue.front();
        int left_child = (index+1)*2-1;
        int right_child = (index+1)*2;
        if (left_child<string.size() && string[left_child] != '#') {
            char value_c = string.c_str()[left_child];
            TreeNode * newNode = new TreeNode(stoi(&value_c));
            commonNode->left = newNode;
            nodeQueue.push(newNode);
        }
        if (right_child<string.size() && string[right_child] != '#') {
            char value_c = string.c_str()[right_child];
            TreeNode * newNode = new TreeNode(stoi(&value_c));
            commonNode->right = newNode;
            nodeQueue.push(newNode);
        }
        nodeQueue.pop();
        index ++;
    }
}


int main(int argc, const char * argv[]) {
    string temp = "1234567";
    char value_c = temp.c_str()[0];
    TreeNode *root = new TreeNode(stoi(&value_c));
    createTree(temp,root);
    Solution solution;
    solution.postorderTraversal(root);
    return 0;
}
