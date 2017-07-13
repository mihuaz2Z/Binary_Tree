//
//  main.cpp
//  二叉树的层次遍历
//
//  Created by Ruiwen Feng on 2017/7/13.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//


/*
 
 给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）
 
 样例
 给一棵二叉树 {3,9,20,#,#,15,7} ：
 
 3
 / \
 9  20
 /  \
 15   7
 
 [
 [3],
 [9,20],
 [15,7]
 ]
 
 */


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


void printTree(TreeNode*node) {
    if (!node) {
        return;
    }
    printTree(node->left);
    printTree(node->right);
    cout << node->val << " ";
}



class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    
    vector<int> find_all (queue<TreeNode*>*nodeQueue) {
        vector<int> node_vector;
        if (nodeQueue->size() == 0) {
            return node_vector;
        }
        long size = nodeQueue->size();
        for (int i = 0; i < size; i ++) {
            TreeNode * node = nodeQueue->front();
            if (node->left != NULL) {
                nodeQueue->push(node->left);
                node_vector.push_back(node->left->val);
            }
            if (node->right != NULL) {
                nodeQueue->push(node->right);
                node_vector.push_back(node->right->val);
            }
            nodeQueue->pop();
        }
        return node_vector;
    }
    
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode*>nodeQueue;
        nodeQueue.push(root);
        vector<vector<int>> vector_out;
        if (root == nullptr) {
            return vector_out;
        }
        
        vector<int> vectorroot;
        vectorroot.push_back(root->val);
        vector_out.push_back(vectorroot);
        int flag = 0;
        do {
            vector<int> nodeArray = find_all(&nodeQueue);
            if (nodeArray.size() >= 1) {
                flag = 1;
                vector_out.push_back(nodeArray);
            }
            else
            {
                flag = 0;
            }
        } while (flag);
        
        return vector_out;
    }
};



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
    
    
    vector<vector<int>> result = solution.levelOrder(root);

    
    for (int i = 0; i < result.size(); i ++) {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j ++) {
            cout<<result[i][j]<<" ";
        }
        cout << "]";
    }

    return 0;
}
