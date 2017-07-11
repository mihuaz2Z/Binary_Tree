//
//  main.cpp
//  在二叉树中寻找值最大的节点并返回。
//
//  Created by Ruiwen Feng on 2017/7/10.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
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

//找到二叉树中最大值
class Solution {
public:
    TreeNode *max_Node;

    TreeNode* max_node(TreeNode* root){
        if (!root) {
            return nullptr;
        }
        if (root->val > max_Node->val) {
            max_Node = root;
        }
        max_node(root->left);
        max_node(root->right);
        return max_Node;
    }
    
    TreeNode* maxNode(TreeNode* root) {
        max_Node = root;
        TreeNode * maxnode  = max_node(root);
        std::cout << maxnode->val <<endl;
        return maxnode;
    }
};

//先序遍历
void printTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    printf("%d",root->val);
    printTree(root->left);
    printTree(root->right);
}

//创建完全二叉树
TreeNode* CreateBiTreeAuto(int *nums,int length)
{
    vector<TreeNode*> nodeQueue;
    for (int i = 0; i < length; i ++) {
        nodeQueue.push_back(new TreeNode(nums[i]));
    }
    TreeNode * root = nodeQueue[0];
    for (int i = 0; i < nodeQueue.size(); i ++) {
        int j = i + 1;
        TreeNode* node = nodeQueue[i];
        if (j*2-1 < nodeQueue.size()) {
            node->left = nodeQueue[j*2-1];
        }
        if (j*2 < nodeQueue.size()) {
            node->right = nodeQueue[j*2];
        }
    }
//    printTree(root);
    return root;
}


int main(int argc, const char * argv[]) {
    Solution solution;
    
    int nums[3] = {1,1,2};
    TreeNode* tree = CreateBiTreeAuto(nums,3);
    TreeNode * maxnode = solution.maxNode(tree);
    
    std::cout << maxnode->val <<endl;
    return 0;
}
