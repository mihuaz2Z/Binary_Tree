//
//  main.cpp
//  链表求和
//
//  Created by Ruiwen Feng on 2017/7/15.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

using namespace std;

//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    
    void add(ListNode* left ,ListNode * right , int flags) {
        
        if (left == NULL && right == NULL) {
            return ;
        }
        
        if (right == NULL)
        {
            left->val = left->val+ flags;
        }
        else  {
            left->val = left->val + right->val + flags;
        }

        //上一层的进位
        int i = left->val/10;
    
        if (left != NULL && right != NULL) { //等长，但是有进位
            if (left->next == NULL && right->next == NULL){
                if (i != 0) { //新建结点
                    left->next = new ListNode(i);
                    i = 0;
                }
            }
            else if (left->next == NULL) { //解决不等长问题。
                left->next = right->next; //左边不够长，从右边挪到左边
                right->next = NULL;
            }
            //继续加下一位
            left->val = left->val %10;
            add(left->next, right->next,i);
        }
        else //没有右节点
        {
            //继续加下一位
            left->val = left->val %10;
            add(left->next,NULL,i);
        }
    }
    
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        add(l1, l2, 0);
        return l1;
    }
};

void createList (ListNode * head,int *arry, int size) {
    head->val = arry[0];
    ListNode * currentNode = head;
    for (int i = 1; i < size; i ++) {
        ListNode * node = new ListNode(arry[i]);
        currentNode->next = node;
        currentNode = node;
    }
}


int main(int argc, const char * argv[]) {
    
    int left[] = {2,8,2,8,2,9,6,4,5,2,5,2};
    int right[] = {5,8,9,5,6,5,1,8,7,5,5};
    int left_size = sizeof(left)/sizeof(int);
    int right_size = sizeof(right)/sizeof(int);
    ListNode * leftNode = new ListNode(left[0]);
    ListNode * rightNode = new ListNode(right[0]);
    createList(leftNode, left, left_size);
    createList(rightNode, right, right_size);
    

    Solution solution;
    solution.addLists(leftNode, rightNode);
    
    while (leftNode != NULL) {
        cout<<leftNode->val<< " ";
        leftNode = leftNode->next;
    }
    
    return 0;
}
