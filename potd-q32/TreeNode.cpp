#include "TreeNode.h"
#include <iostream>
#include <cmath>

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  //everything is set
  getHeight_setB(root);
  //begin to get those Nodes
  return findlast(root);

}
TreeNode* findlast(TreeNode * subroot){
  if(subroot==NULL) return NULL;
  //std::cout<<subroot->val_<<"value"<<subroot->balance_<<"balance"<<std::endl;
  TreeNode* leftB = findlast(subroot->left_);
  TreeNode* rightB = findlast(subroot->right_);
  if(leftB==NULL && rightB == NULL){
    if(!isBalance(subroot))
      return subroot;
    else
      return NULL;
    }
  if(leftB != NULL&& rightB != NULL){
    if(leftB->distance > rightB->distance)
          return leftB;
    else
          return rightB;
  }
  if(leftB == NULL && rightB != NULL)
      return rightB;
  if(rightB == NULL && leftB != NULL)
      return leftB;
  return NULL;
}
bool isBalance(TreeNode* subroot){
   if(std::fabs(subroot->balance_) > 1) return false;
   return true;
}
void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
//get Height and set its balcance and to set the distance from the root
int getHeight_setB(TreeNode* subroot){
  if(subroot == NULL) return -1;

  if(subroot->left_!= NULL) subroot->left_->distance = subroot->distance+1;
  int leftH = getHeight_setB(subroot->left_);

  if(subroot->right_!= NULL) subroot->right_->distance = subroot->distance+1;
  int rightH = getHeight_setB(subroot->right_);

  subroot->balance_ = leftH - rightH;
  return 1 + std::max(leftH,rightH);
  
}
