#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    traversal(root, v);
    return v;
}
void traversal(BTreeNode * root, std::vector<int> &v){
  if(!root->is_leaf_){
    unsigned i = 0;//for elements_
    unsigned j = 0;//for children_
      while(i < root->elements_.size() && j < root->children_.size()){
        traversal(root->children_[j], v);
        v.push_back(root->elements_[i]);
        i++;
        j++;
      }
      traversal(root->children_[j],v);
  }
  else{
    for(std::vector<int>::const_iterator n = root->elements_.begin(); n != root->elements_.end(); ++n)
      v.push_back(*n);
  }
}
