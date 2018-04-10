#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    unordered_map<string, int> mp;
    vector<string> ret;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            mp[line]+=1;
        }
    }
    auto storit = mp.begin();
    while(ret.size()<3){
    for(auto it = mp.begin(); it != mp.end();it++){
      if(it->second > storit->second) storit = it;
    }
    ret.push_back(storit->first);
    mp.erase(storit);
    storit = mp.begin();
  }
  infile.close();
  return ret;
}
