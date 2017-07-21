//
//  main.cpp
//  二叉树深度
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*求二叉树最大深度。*/

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


int treedeep(TreeNode * root){
    if (root == NULL) {
        return 0;
    }
    int leftDeep = treedeep(root->left);
    int rightDeep = treedeep(root->right);
    return leftDeep>rightDeep?leftDeep+1:rightDeep+1;
}


int main(int argc, const char * argv[]) {
    
    string fullString = "1234567";
    TreeNode *root = new TreeNode(0);
    createTree(&fullString,root);
    
    int deep = treedeep(root);
    
    std::cout << deep << endl;
    return 0;
}
