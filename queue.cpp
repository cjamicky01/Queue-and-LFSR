#include  "queue.h"

Queue::Queue() {
	rearPtr = nullptr;
}
// Queue()
// Initializes all private variables to indicate an empty queue


//~Queue()
// Deallocates all queue nodes

void Queue::MakeEmpty() {
	while (!IsEmpty()) 
	{
		Dequeue();
	}
}
// MakeEmpty()
// Deallocates all queue nodes and returns queue to empty ready-to-use state 

bool Queue::IsEmpty() const {
	if (rearPtr == nullptr) {
		return true;
	}
	return false;
}
// IsEmpty()
// Returns true if queue is empty.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE

void Queue::Enqueue(int n) {
	Node *temp = new Node;	
	if (IsFull()) {
		throw QueueFull();
	}
	else {
		if(count == 0)
		{
			temp->data = n;
			temp->nextPtr = temp;
			rearPtr=temp;
			count++;
		} else {
			Node *first = rearPtr->nextPtr;
			temp->data = n;
			temp->nextPtr = first;
			rearPtr->nextPtr = temp;
			rearPtr = temp;
			count++;
		}
	}
}
// Enqueue()
// Adds value n to rear of queue and increments count.
// If queue is already full, throws QueueFull exception

void Queue::Dequeue() {
	if (IsEmpty()) {
		throw QueueEmpty();
	}
	else {
		if(count == 1){
			Node *temp = rearPtr;
			rearPtr = nullptr;
			delete temp;
			count--;
		} else {
			Node *temp = rearPtr->nextPtr;
			Node *newHead = temp->nextPtr;
			rearPtr->nextPtr = newHead;
			delete temp;
			count--;
		}
	}
}
// Dequeue()
// Removes front value from queue and decrements count.
// If queue is empty, throws QueueEmpty exception

int Queue::Front() const {
	if(IsEmpty()){
		throw QueueEmpty();
	} else {
		return rearPtr->nextPtr->data;	
	}

}
// Front()
// Returns integer from front of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Rear() const {
	if(IsEmpty()){
		throw QueueEmpty();
	} else {
		return rearPtr->data;
	}
}
// Rear()
// Returns integer from rear of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Peek(int n) const {
	
	if (Size() > n) {
		Node *temp = rearPtr->nextPtr;
		for (int i = 0; i < n; i++)
		{
			temp = temp->nextPtr;
		}
		return temp->data;
	}
	else {
		throw QueueInvalidPeek();	
	}
}
// Peek()
// Returns integer n positions from front of queue
// If queue is empty, throws QueueEmpty
// If position n does not exist, throws QueueInvalidPeek
// DOES NOT MODIFY THE QUEUE

bool Queue::IsFull() const {
	return false;
}
// IsFull()
// Returns true if queue is full.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE



int Queue::Size() const {
	return count;
}
// Size()
// Returns number of items stored in queue.  DOES NOT MODIFY THE QUEUE

Queue::~Queue() {
	MakeEmpty();
}
