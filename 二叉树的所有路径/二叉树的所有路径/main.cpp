//
//  main.cpp
//  二叉树的所有路径
//
//  Created by Ruiwen Feng on 2017/7/13.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 
 给一棵二叉树，找出从根节点到叶子节点的所有路径。
 样例
 给出下面这棵二叉树：
 
   1
 /   \
 2     3
  \
   5
 
 所有根到叶子的路径为：
 
 [
 "1->2->5",
 "1->3"
 ]
 
 */

#include <iostream>
#include <string>
#include <vector>
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


class Solution {
    vector<TreeNode*> node_vector;
public:
    vector<string> string_vector;
    
    void alltrade(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        else{
            //添加进数组
            node_vector.push_back(root);
        }
        //是叶子节点就输出路径。
        if (root->left == NULL && root -> right == NULL) {
            string data;
            for (int i = 0; i < node_vector.size(); i ++) {
                if (i > 0) {
                    data += "->";
                }
                data += to_string(node_vector[i]->val);
            }
            string_vector.push_back(data);
        }
        else
        {
            alltrade(root->left);
            alltrade(root->right);
        }
        //跑完一圈删除节点。
        node_vector.erase(node_vector.end()-1);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        alltrade(root);
        return string_vector;
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
    solution.binaryTreePaths(root);
    for (int i =0; i < solution.string_vector.size(); i ++) {
        cout << solution.string_vector[i] << endl;
    }
    
    return 0;
}
