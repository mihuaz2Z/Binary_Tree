//
//  main.cpp
//  平衡二叉树
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 平衡二叉树
 给定一个二叉树,确定它是高度平衡的。对于这个问题,一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。
 
 给出二叉树 A={3,9,20,#,#,15,7}, B={3,#,20,15,7}
 
 A)  3            B)    3
 / \                  \
 9  20                 20
 /  \                 / \
 15   7               15  7
 
 */

#include <iostream>
#include <string>
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
public:
    
    bool flag = false;

    int trevalTree(TreeNode *root){
        if (flag) {
            return 0;
        }
        if (root == NULL) {
            return 0;
        }
        int left_deep = trevalTree(root->left);
        int right_deep = trevalTree(root->right);
        
        if (left_deep - right_deep > 1 || left_deep - right_deep < -1) {
            return flag = true;
        }
        
        return left_deep>=right_deep?left_deep+1:right_deep+1;
    }
    
    
    bool isBalanced(TreeNode *root) {

        if (root == NULL) {
            return true;
        }
       
        trevalTree(root);
  
        if (flag) {
            return false;
        }
        else
        {
            return true;
        }
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
    string fullString = "1234#56789111";
    char value = fullString.c_str()[0];
    TreeNode *root = new TreeNode(stoi(&value));
    createTree(&fullString,root);
    
    Solution s;
    bool result = s.isBalanced(root);
    
    std::cout << result << endl;
    return 0;
}
