#include  "queue.h"

Queue::Queue() {
	rearPtr = nullptr;
	count = 0;
}
// Queue()
// Initializes all private variables to indicate an empty queue

Queue::~Queue() {
	MakeEmpty();
	delete rearPtr;
}
//~Queue()
// Deallocates all queue nodes

void Queue::MakeEmpty() {
	while (!IsEmpty()) {
		Dequeue();
	}
}
// MakeEmpty()
// Deallocates all queue nodes and returns queue to empty ready-to-use state 

void Queue::Enqueue(int n) {
	Node *temp = rearPtr;
	if (IsFull()) {
		throw QueueFull();
	}
	else {
		temp->data = n;
		temp->nextPtr = rearPtr;
		rearPtr = temp;
		this->count++;
	}
}
// Enqueue()
// Adds value n to rear of queue and increments count.
// If queue is already full, throws QueueFull exception

void Queue::Dequeue() {
	Node *temp = rearPtr;
	int counter = 0;
	if (IsEmpty()) {
		throw QueueEmpty();
	}
	else {
		while (counter < this->count) {
			temp = temp->nextPtr;
			counter++;
		}
		delete temp;
	}
}
// Dequeue()
// Removes front value from queue and decrements count.
// If queue is empty, throws QueueEmpty exception

int Queue::Front() const {
	Node *temp = rearPtr;
	int counter = 0;
	while (counter < this->count) {
		temp = temp->nextPtr;
		counter++;
	}
	return temp->data;
}
// Front()
// Returns integer from front of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Rear() const {
	return rearPtr->data;
}
// Rear()
// Returns integer from rear of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Peek(int n) const {
	int counter = 0;
	Node *temp = rearPtr;
	if (n > Size()) {
		throw QueueInvalidPeek();
	}
	else {
		while (counter < n) {
			temp = temp->nextPtr;
			counter++;
		}
		return temp->data;	
	}
}
// Peek()
// Returns integer n positions from front of queue
// If queue is empty, throws QueueEmpty
// If position n does not exist, throws QueueInvalidPeek
// DOES NOT MODIFY THE QUEUE

bool Queue::IsFull() const {
	if (this->count >= 10) {
		return true;
	}
	else {
		return false;
	}
}
// IsFull()
// Returns true if queue is full.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE

bool Queue::IsEmpty() const {
	if (rearPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
// IsEmpty()
// Returns true if queue is empty.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE

int Queue::Size() const {
	int counter = 0;
	Node temp = rearPtr;
	while (temp->next != nullptr) {
		temp = temp->next;
		counter++;
	}
	return counter;
}
// Size()
// Returns number of items stored in queue.  DOES NOT MODIFY THE QUEUE
