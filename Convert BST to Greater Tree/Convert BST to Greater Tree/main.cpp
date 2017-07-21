//
//  main.cpp
//  Convert BST to Greater Tree
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 
 Given a binary search Tree ｀{5,2,3}｀:
 
    5
  /   \
 2     13
 Return the root of new tree
 
    18
   /   \
 20     13
 
 //解题：每个节点加上比他值大的节点的值。
 */

#include <iostream>
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

void printTree(TreeNode*node) {
    if (!node) {
        return;
    }
    printTree(node->left);
    cout << node->val << " ";
    printTree(node->right);
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

class Solution {
public:
    int sum = 0;
    
    void travelTree(TreeNode* root){
        if (root == NULL) {
            return;
        }
        travelTree(root->right);
        cout << root->val <<" + " << sum << endl;
        root->val += sum;
        sum = root->val;
        travelTree(root->left);
    }
    
    void addValue(TreeNode* root){
        travelTree(root);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        if (root == NULL) {
            return root;
        }
        
        addValue(root);
        
        return root;
    }
};



int main(int argc, const char * argv[]) {
    string fullString = "529";
    TreeNode *root = new TreeNode(0);
    createTree(&fullString,root);
    printTree(root);

    Solution solution;
    
    solution.convertBST(root);
    
    printTree(root);
    
    
    return 0;
}
