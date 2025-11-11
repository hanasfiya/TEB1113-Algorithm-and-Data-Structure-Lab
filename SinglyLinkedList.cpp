//singly linked list

#include <iostream>
using namespace std;

struct Node{
  string data;
  Node* ptr;
  Node* previousptr;
};

int main(){
  
  Node node1, node2, node3, node4;

  
  node1.data = "test1";
  node1.ptr = &node2;
  
  node2.data = "test2";
  node2.ptr = &node3;
  
  node3.data = "test3";
  node3.ptr = &node4;
  
  node4.data = "test4";
  node4.ptr = NULL;

  cout << "Output:" << endl;
  Node* current = &node1;
  while ( current != nullptr){
    
    cout << current -> data<< " "<<"\n";
    current = current -> ptr;
    
  }
  
  cout << endl;
  
  return 0;
  
 
  
}