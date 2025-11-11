//stack

#include <iostream>
using namespace std;

struct Node{
  string data;
  Node* next;
};

class Stack {
  
  private :
    Node* head;
    Node* tail;
    
  public:
    Stack() {
      head = nullptr;
      tail = nullptr;
    }
    
  void Push(string value) {
  
    Node* newNode = new Node;
    newNode ->data = value;
    newNode ->next = head;
    head =newNode;
    
    if (tail == nullptr){
      tail = newNode;
    }
  
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
 