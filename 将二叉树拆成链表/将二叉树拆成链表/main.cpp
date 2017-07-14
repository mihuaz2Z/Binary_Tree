//
//  main.cpp
//  将二叉树拆成链表
//
//  Created by Ruiwen Feng on 2017/7/14.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>

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
    TreeNode* littleTree(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        
        TreeNode* leftChild = littleTree(root->left); // tail of left linked list
        TreeNode* rightChild = littleTree(root->right); // tail of left linked list
        //分治的思想，分解成小的。
        /*
             a
            / \
           b   c
         先序转化为列表，a->b->c,如果没有b则不用变化，如果有b则先把c赋值给b的右子树，在把b赋值给a的右子树。
         */
        
        if(leftChild != NULL)
        {
            leftChild->right = root->right;
            root->right = root->left;
        }
        
        //清除左边。
        root->left = NULL;
        
        if(rightChild!= NULL)
            return rightChild;
        else if(leftChild != NULL)
            return leftChild;
        else
            return root;
    }
    
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        littleTree(root);
    }

};




void createTree(string temp,TreeNode *root) {
    queue<TreeNode *> node_queue;
    node_queue.push(root);
    TreeNode * currentNode = nullptr;
    long size = temp.length();
    for (int i = 0,index = 1; i < size; i ++) {
        
        if (temp[i] == '#') {
            continue;
        }
        
        currentNode = node_queue.front();
        
        int leftChildIndex = index*2-1;
        int rightChildIndex = index*2;
        
        if (leftChildIndex < size && temp[leftChildIndex]!='#') {
            char value_char = temp.c_str()[leftChildIndex];
            currentNode->left = new TreeNode(stoi(&value_char));
            node_queue.push(currentNode->left);
        }
        if (rightChildIndex < size && temp[rightChildIndex]!='#') {
            char value_char = temp.c_str()[rightChildIndex];
            currentNode->right = new TreeNode(stoi(&value_char));
            node_queue.push(currentNode->right);
        }
        
        node_queue.pop();
        index ++;
    }
}


int main(int argc, const char * argv[]) {
   string temp = "12345#6";
    char value_char = temp.c_str()[0];
    TreeNode * root = new TreeNode(stoi(&value_char));
    createTree(temp, root);
    Solution solution;
    solution.flatten(root);
    
    
    while (root) {
        cout<<root->val << " ";
        root = root->right;
    }
    
    return 0;
}
