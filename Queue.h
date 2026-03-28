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

  if (!headPtr) {
    headPtr = new_node;
    tailPtr = new_node;
  } else {
    tailPtr->set_next(new_node);
    tailPtr = new_node;
  }
  ++size;

}

int Queue::dequeue(){
  if(size > 0) { //size is number of node in the queue
    NodePtr tmp = headPtr; //temp point to head
    int val = headPtr->get_value(); //val=data inside the node
    headPtr = headPtr->get_next(); //move head pointer to next node in the queue
    delete tmp;
    --size;
    return val; //return val after dequeue success to main.cpp
  }
  cout<<"Empty Queue"<<endl; //if queue is empty
  return -1;
}


Queue::Queue(){
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}
Queue::~Queue(){
  cout<<"Clearing queue"<<endl;
  while (size) { //loop stop when size is 0 (false)
    int x = dequeue();
    cout << "dequeing "<< x << endl;
  }
}


#endif
