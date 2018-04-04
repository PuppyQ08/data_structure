#include "Heap.h"
#include <iostream>

void swap(std::vector<int> &_data,int first, int second);
void swap(std::vector<int> &_data, int first, int second){
   int temp = _data[first];
  _data[first] = _data[second];
  _data[second] = temp;
}

void Heap::_percolateDown(int hole) {
    // your code here
    int largest = hole;
    //always update index!!
    if((size_t)(2 * hole) < _data.size() && _data[2 * hole] > _data[largest])
      largest = 2 * hole;
    if((size_t)(2* hole + 1) < _data.size() && _data[2 * hole + 1] > _data[largest])
      largest = 2 * hole + 1;
    if(largest !=  hole){
      swap(_data, hole, largest);
      _percolateDown(largest);
    }
    return;
    }
int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
