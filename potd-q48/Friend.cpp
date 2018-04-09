#include "Friend.h"
#include <unordered_map>
#include <iostream>
using namespace std;
int find(int x, std::vector<int>& parents) {
    return -1;// your code
    // we don't need to use this one
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
    std::vector<int> parent(M.size(),M.size()+1);
    //make sure initial element in parent is different
    for(size_t i = 0; i < M.size(); i++){
      parent[i]+= i;
    }
    //to check Matrix and then update paretn
    for(size_t i = 0; i < M.size(); i++){
      for(size_t j = i + 1; j< M.size(); j++){
        if(M[i][j] == 1){
          size_t minn = std::min(parent[i], parent[j]);
          int maxx = std::max(parent[i], parent[j]);
          //if two element's min root is < i then we update the root to min
          if(minn <= i){
            //here we need to find same root elem then update the root
            //update elem in same circle
            for(size_t m = 0; m < M.size(); m++){
              if(parent[m] == maxx)
                parent[m] = minn;
            }
            parent[i] = minn;
            parent[j] = minn;
          }
          //otherwise update to i
          else{
            parent[i] = i;
            parent[j] = i;
          }
        }
      }
    }
    //for(int i =  0; i < parent.size(); i++){
      //std::cout<< parent[i]<<std::endl;
    //}
    // here we use a hash table to find out how many different elem in
    // parent vector
    std::unordered_map<int, int> mymap;
    for(size_t i = 0; i < M.size(); i++){
      std::unordered_map<int, int>::iterator it = mymap.find(parent[i]);
      if(it == mymap.end()) mymap.insert({parent[i],1});
    }
    return mymap.size();
}
