#include <vector>
#include <map>
#include "Primes.h"

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    // your code here
    //use dict probably more convenient
    std::map<int, int> mp;
    for(int i = 2; i < M + 1; i ++){
      mp[i];
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
      int times = 2;
       while(times * it->first < M + 1){
         auto findit = mp.find(times * it->first);
         if(findit != mp.end()) mp.erase(findit);
         times++;
       }
    }
    for(auto it = mp.begin(); it != mp.end();it++){
       v->push_back(it->first);
    }

    /*for(int i = 0; i < M +1; i++)
      v.push_back(i);
    for(int i = 1; i < )*/
    return v;
}
