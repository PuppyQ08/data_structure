#include "potd.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
	// test your code here!
	std::vector<string> v;
	v = topThree("in1.txt");
	for(auto it = v.begin(); it != v.end(); it++){
		cout<<"all "<< *it <<endl;
	}
	return 0;
}
