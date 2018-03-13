#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    unsigned i = 0;
    if(root!= NULL){
        //use a loop to find where the key is in the root elements_
        while (i < root->elements_.size()) {
          if(key == root->elements_[i])
            return root;//we just hit it !
          else if(key < root->elements_[i])
            break;
          else
            i++;//if key is larger than present value then move forward
        }
        //if it is leaf then we need to get rid of value outside and return the root
        if(root->is_leaf_)
          return NULL;
        // if it is not a leaf then we just move to next one.
        else
          return  find(root->children_[i],key);
        }

  return NULL;//if root is NULL return NULL
}
