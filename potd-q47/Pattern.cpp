 #include "Pattern.h"
#include <string>
#include <iostream>
#include <utility>
#include <vector>
using std::pair;
using namespace std;


bool wordPattern(std::string pattern, std::string str) {
    std::vector<pair<string,string>> v;
    std::vector<pair<string,string>> vp;
    //because the end of str is not ' '....
    str+= ' ';
    //write your code here
    string word = "";
    string charr;
    int idx = 0;
    for(size_t i = 0; i < str.length();i++){
      //go over str if meet " " then insert into vector and mark its position
      if(str[i] != ' ')
         word+= str[i];
      else{
        int idx_word = find(v, word);
        //didn't find the word in the vector
        if( idx_word == -1){
        pair<string,string> p (word, to_string(idx));
        v.push_back(p);
      }
        //we find it!
        else{
          v[idx_word].second.append(to_string(idx));
        }
        idx++;
        word = "";
      }
    }
    //same thing for Pattern
    idx = 0;
    for(size_t i = 0; i < pattern.length(); i++){
      charr = pattern[i];
      int idx_char = find(vp, charr);
      if(idx_char == -1){
        pair<string, string> p (charr, to_string(idx));
        vp.push_back(p);
      }
      else{
        vp[idx_char].second.append(to_string(idx));
      }
      idx++;
    }
    //compare two vector
    bool judge = true;
    if(v.size() != vp.size()) judge = false;
    else{
      for(size_t i = 0; i < v.size();i++){
        if(v[i].second != vp[i].second) judge = false;
      }
    }
    return judge;
}

int find(const vector<pair<string, string>> &v, string str){
  if(v.size()!= 0){
    for(size_t i = 0; i < v.size(); i++){
      if(v[i].first == str) return i;
    }
  }
  return -1;
}
