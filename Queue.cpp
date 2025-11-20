//queue

#include <iostream>
using namespace std;

struct Node {
  
  string data;
  Node*next;
  
};

class Queue {
  
private :
  Node* front;   // pointer Head
  Node* rear ;   //pointer tail
  
public :
  Queue() {
    
    front = nullptr;
    rear = nullptr;
    
  }
  
  //enqueue
  void Enqueue (string value){
    
    Node* newNode = new Node;
    
    newNode ->data = value;
    newNode ->next = nullptr;
    
    if(rear == nullptr){
      //queue empty
      front = rear = newNode;
      
    }
    else {
      
    //add new element
    rear-> next = newNode;
    rear = newNode;
    
    }
    
  }
  
  //dequeue
  
  void Dequeue(){
    
    //check for underflow 
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    cout <<"[ " << front ->data <<" ] " << " Removed From Queue "<< endl;
    
    Node* temp = front;
    
    front = front->next;
    
    //check if the queue is empty after Dequeue process
    if (front == nullptr){
      rear = nullptr;
    }
    
    //delete the element on the front
    delete temp;
    
    cout << endl;
  }
  
  //peek element in the front and rear
  void Peek(){
    
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    
    cout << "Front element: " << front->data << endl;
    cout << "Rear element: " << rear->data << endl;
    cout << endl;
  }
  
  void Display(){
    
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    
    Node * current = front;
    cout << "Queue :"<<endl;
    
    while (current != nullptr){
      cout << current-> data << endl;
      current = current-> next;
    }
    cout << endl;
    
    
  }
  
  //get size of Queue
  void Count(){
    
    if (front == nullptr){
      cout << "Queue size is Null "<< endl;
      return ;
      
    }
    Node * current = front;
    int count = 0 ;
    
    while (current != nullptr){
      count++;
      current = current-> next;
    }
    cout << "Size of The Queue: "<< count<< endl;
    
  }
  
};

int main (){
  
  Queue q;
  
  q.Enqueue("test1");
  q.Enqueue("test2");
  q.Enqueue("test3");
  q.Enqueue("test4");
  q.Enqueue("test5");

  q.Count();
  q.Display();
  q.Peek();

  q.Dequeue();
  q.Display();
  q.Count();
  

  return 0;
}
 void Pop(){
   
    cout <<"["<< head->data <<"]"<< " popped from stack\n"<< endl;
    Node* temp = head;
    head = head->next; 
    delete temp;
    
    if (head == nullptr){
        tail = nullptr;
    }
    cout << endl;
  }
  
   void Display() {
     
        Node* current = head;
        cout << "Stack contents: "<< endl;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
    
    void Peek(){
      
      cout << "Head Element : "<< head->data << endl;
      
      Node* current = head;
      while (current->next != nullptr) {
        current = current->next;
    }

    cout << "Tail element: " << current->data << endl;
    cout << endl;
    }
    
  
};


int main() {
    Stack s;
    s.Push("test1");
    s.Push("test2");
    s.Push("test3");
    s.Push("test4");
    s.Push("test5");
    
    s.Peek();
    
    s.Pop();
    
    s.Display();
    
  
  return 0;
  
}
 
