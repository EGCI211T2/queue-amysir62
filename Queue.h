#ifndef queue_h
#define queue_h
#include "Node.h"

#include <iostream>

using namespace std;

class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node = new NODE(x);
  if (!new_node) {
    cerr << "Error for some reason" << endl;
  }
  ++size;

  if (!headPtr) {
    headPtr = new_node;
    tailPtr = new_node;
  } else {
    tailPtr->set_next(new_node);
    tailPtr = new_node;
  }
}

int Queue::dequeue(){
  if(size > 0) {
    NodePtr tmp = headPtr;
    int val = headPtr->get_value();
    headPtr = headPtr->get_next();
    delete tmp;
    --size;
    return val;
  }
  cout<<"Empty Queue"<<endl;
  return -1;
}


Queue::Queue(){
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}
Queue::~Queue(){
  cout<<"Clearing queue"<<endl;
  while (size) {
    int x = dequeue();
    cout << "dequeing "<< x << endl;
  }
}


#endif
