#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  TreeNode * find = root;
  TreeNode * former = root;
//to find the value of wanted TreeNode
while(find != NULL){
  if(key < find-> val_){
    former = find;
    find = find->left_;
  }
  if(key > find-> val_){
    former = find;
    find = find->right_;
  }
  if(key == find->val_)
    break;
  }
  //to remove the TreeNode
if(find != NULL && former != NULL){
  //no child or just one child
  if(find->left_ == NULL && find->right_ == NULL){
   if(former->val_ > find->val_)
      former->left_ = NULL;
      if(former->val_ < find->val_)
        former->right_ = NULL;
        delete find;
        return root;
  }

  if(find->left_ != NULL && find->right_ == NULL){
    if(former->val_ > find->val_){
      former->left_ = find->left_;
    }
    else if(former->val_ < find->val_){
      former->right_ = find->left_;
    }
    find->left_ = NULL;
    delete find;
    return root;
  }
  if(find->left_ == NULL && find->right_ != NULL){
    if(former->val_ > find->val_){
      former->left_ = find->right_;
    }
    else if(former->val_ < find->val_){
      former->right_ = find->right_;
    }
    find->right_ = NULL;
    delete find;
    return root;
  }
  //two child! really complecated operation
  if(find->left_ != NULL && find->right_ != NULL){
    TreeNode * inordleft = find->right_;
    TreeNode * inordformer = find->right_;
    //to get the left most leave
    while(inordleft->left_ != NULL){
      inordformer = inordleft;
      inordleft = inordleft->left_;
}
  //left
  if(find->right_->left_ == NULL){
    inordleft->left_ = find->left_;
  }
  else{
    inordformer -> left_ = NULL;
    inordleft -> left_ = find-> left_;
    inordleft -> right_ = find->right_;
  }
    if(former->val_ > find->val_)
      former->left_ = inordleft;
    if(former->val_ < find->val_)
      former->right_ = inordleft;
    delete find;
    return root;
  }

}
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (node==NULL)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
