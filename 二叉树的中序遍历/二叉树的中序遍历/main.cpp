//
//  main.cpp
//  二叉树的中序遍历
//
//  Created by Ruiwen Feng on 2017/7/12.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//Definition of TreeNode:
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
    
    void inorderTree(vector<int> *array,TreeNode *root) {
        if (!root) {
            return;
        }
        inorderTree(array,root->left);
        array->push_back(root->val);
        inorderTree(array,root->right);
    }
    
    //中序遍历并取值
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> array;
        inorderTree(&array, root);
        return array;
    }
};


//创建二叉树
void createTree(string treeString,TreeNode *root) {
    queue<TreeNode *> Tree_queue;
    TreeNode * current_node = root;
    Tree_queue.push(current_node);
    int node_index = 0;
    for (int i = 0; i < treeString.size(); i ++) {
        if (treeString[i] == '#') {
            continue;
        }
        int left_index = (node_index+1)*2-1;
        int right_index = (node_index+1)*2;
        if (left_index < treeString.size() && treeString[left_index] != '#') {
            char value = treeString.c_str()[left_index];
            current_node->left = new TreeNode(stoi(&value));
            cout << value << " " << current_node->left->val << endl;
            Tree_queue.push(current_node->left);
        }
        if (right_index < treeString.size() && treeString[right_index] != '#') {
            char value = treeString.c_str()[right_index];
            current_node->right = new TreeNode(stoi(&value));
            cout << value << " " << current_node->right->val << endl;
            Tree_queue.push(current_node->right);
        }
        if (Tree_queue.size()>1) {
            node_index++;
            Tree_queue.pop();
            current_node = Tree_queue.front();
        }
    }
}


int main(int argc, const char * argv[]) {
    string treeString = {'1','2','#','4','#','6','7','8'};
    char value = treeString.c_str()[0];
    TreeNode *root = new TreeNode(atoi(&value));
    createTree(treeString, root);
    Solution solution;
    vector<int> result;
    result = solution.inorderTraversal(root);

    for (int i =0; i < result.size(); i++) {
        cout << result[i] <<" ";
    }
    cout<<endl;
    
    return 0;
}
