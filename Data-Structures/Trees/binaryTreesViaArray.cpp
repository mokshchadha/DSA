#include<iostream>
using namespace std;
#define capacity 10

class BinaryTree {
public:
  int array[capacity]
  int currentSize;

  BinaryTree();
  int getLeft(int);
  int getRight(int);
  int getParent(int);
  int searchKey(int);
  void deleteKey(int);
  void insertKey(int);

  bool isEmpty();
}

BinaryTree:: BinaryTree(){
  currentSize =0;
}

int BinaryTree :: getLeft(idx) {return 2* idx +1;}

int BinaryTree :: getRight(idx) {return 2*idx + 2;}

bool BinaryTree:: isEmpty() {return currentSize==0;}

int BinaryTree :: searchKey(int key) {
  for(int i : array) { if(i==key) return i;}
  return -1;
}

void BinaryTree :: deleteKey(key){
    for(int i : array) { if(i==key) currentSize-- ;}
}

void BinaryTree :: insertKey(key) {
  if(currentSize == capacity) {
    cout<<"My tree is full "<<endl;
    return;
  }
  array[currentSize] = key;
  currentSize ++;
}


int main(){
  return 0;
}
