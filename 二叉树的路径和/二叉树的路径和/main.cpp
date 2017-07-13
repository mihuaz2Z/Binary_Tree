//
//  main.cpp
//  二叉树的路径和
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
    vector<vector<int>> sum_vector;
    vector<int> num_vector;

    void treePath(TreeNode *root, int target) {
        
        if (root == NULL) {
            return;
        }
        num_vector.push_back(root->val);
        //叶子节点
        if (root->left == NULL && root->right == NULL) {
            int sum = 0;
            vector<int> num_vector_saved;
            for (int i = 0; i < num_vector.size(); i++) {
                sum += num_vector[i];
                num_vector_saved.push_back(num_vector[i]);
            }
            if (sum == target) {
                sum_vector.push_back(num_vector_saved);
            }
        }
        else
        {
            treePath(root->left,target);
            treePath(root->right,target);
        }
        //跑完一条路径，删掉一个回头。
        num_vector.erase(num_vector.end()-1);
    }
    
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        treePath(root,target);
        return sum_vector;
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
    string fullString = "1236745";
    TreeNode *root = new TreeNode(0);
    createTree(&fullString,root);
    
    Solution solution;
    solution.binaryTreePathSum(root,9);
    for (int i =0; i < solution.sum_vector.size(); i ++) {
        for (int j =0; j < solution.sum_vector[i].size(); j ++) {
            cout << solution.sum_vector[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
