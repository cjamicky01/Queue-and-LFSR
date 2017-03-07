#include "lfsr.h"

LFSR::LFSR(string seed, int tap1, int tap2) {
	//this.t1 = tap1;
	//this.t2 = tap2;

}
// LFSR(...) 
// Initializes t1 and t2 to tap1 and tap2, respectively
// and parses seed string to loading queue with starting values

void LFSR::NextState() {
	//temp = XOR(Peek(this.t1), Peek(this.t2));

}
// NextState()
// Iterator method computes and queues next pseudo-random number in sequence 
// Algorithm
//  (1)  temp = Peek(tap1) XOR Peek(tap2)
//  (2)  Dequeue
//  (3)  Enqueue(temp)