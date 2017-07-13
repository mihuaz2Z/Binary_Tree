//
//  main.cpp
//  二叉树的前序遍历
//
//  Created by Ruiwen Feng on 2017/7/13.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// * Definition of TreeNode:
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
    vector<int> vector_out;
public:
    void printTree(TreeNode * root) {
        
        if (root == NULL) {
            return;
        }
        vector_out.push_back(root->val);
        printTree(root->left);
        printTree(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        printTree(root);
        return vector_out;
    }
};




void createTree(string temp,TreeNode * root) {
    
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    TreeNode * commonNode;
    for (int i = 0, index = 1; i < temp.size() ; i ++) {
        
        if (temp[i] == '#') {
            continue;
        }
        commonNode = nodeQueue.front();
        
        int left_child_index = index*2 -1;
        int right_child_index = index*2;
        
        if (left_child_index < temp.size() && temp[left_child_index] != '#') {
            char value_char = temp[left_child_index];
            TreeNode * newNode = new TreeNode(stoi(&value_char));
            commonNode->left = newNode;
            nodeQueue.push(newNode);
        }
        
        if (right_child_index < temp.size() && temp[right_child_index] != '#') {
            char value_char = temp[right_child_index];
            TreeNode * newNode = new TreeNode(stoi(&value_char));
            commonNode->right = newNode;
            nodeQueue.push(newNode);
        }
        
        nodeQueue.pop();
        index ++;
    }
}



int main(int argc, const char * argv[]) {
    
    string temp = "1234567";
    char value_char = temp[0];
    TreeNode * root = new TreeNode(stoi(&value_char));
    createTree(temp,root);
    Solution so;
    vector<int> result = so.preorderTraversal(root);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
