#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    int balance_;
    int distance;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
      distance = 0;
    }
};
//to get the fartest unbalanced Node from root
TreeNode* findLastUnbalanced(TreeNode* root);
//to recursively find the fartest one
TreeNode* findlast(TreeNode * subroot);
//to set balance and distance
int getHeight_setB(TreeNode* subroot);
//to judge if it is balanced
bool isBalance(TreeNode* subroot);
void deleteTree(TreeNode* root);

#endif
