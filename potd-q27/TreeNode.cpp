#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  int leftHeight = -1, rightHeight = -1;
  if(this->left_ != NULL)
      leftHeight = this->left_->getHeight();
  if(this->right_ != NULL)
      rightHeight = this->right_->getHeight();
  int height =1 + max(leftHeight, rightHeight);

  return height;
}
/*int TreeNode::_getHeight(TreeNode *root){
  if(root == NULL)
    return 0;
  return 1 + max(getHeight(root->left_), getHeight(root->right_));
}
*/
