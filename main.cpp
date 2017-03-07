//
// main.cpp

// Driver program which is used to test each
// class member function.
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#include <iostream>
#include <fstream>
#include <new>
#include <cstddef>
#include "queue.h"
#include "lfsr.h"

using namespace std;

void Bar(int n);                        // Prototype for Bar function


int main(int argc, char* argv[])
{
  ifstream inputs;						// Input file for commands
  char op, ch;							// Hold operation and optional char input
  Queue* queuePtr = NULL;               // Will point to Queue object
  LFSR* lfsrPtr = NULL;                 // Will point to LFSR object
  string comment;                       // Stores comment read from input file
  int n;                                // Integer temporary variable
  string seed;                          // Stores seed value
  int tap1, tap2;                       // Store tap index values
  
  
  // Output usage message if one input file name is not provided
  switch (argc)
  {
    case 2:    // Correct number of command line arguments
               break;

    default:   // Incorrect number of command line arguments
               cout << "Usage:\n  program04  <inputfile>\n";
	           return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  Bar(60);                                           // Output long bar

  // Process comment line from input file
  getline(inputs, comment);                          // Input file header comment
  cout << endl << comment << endl << endl;           // Output file header comment

  // Process commands from input file
  inputs >> op;				// Attempt to input first command
  while (inputs)
  {
    switch (op)
    {
      case '#':   // Test file comment
	        getline(inputs, comment);      // Input and echo the comment appearing in the test file
	        cout << '#' << comment << endl;
	        break;

      case '~':   // Print Bar
	        Bar(40);                         // Output short bar
	        break;	

      case 'c':   // Constructor
                  inputs >> op;
                  
                  try
				  {
                    if (op == 'Q')
                    {
                        cout << "Queue::Queue() -- Status = ";
				        queuePtr = new Queue;
                        cout << "Completed" << endl;
                    }
                    else if (op == 'L')
                    {
                        inputs >> seed >> tap1 >> tap2;
                        cout << "LFSR::LFSR(" << seed << ", " << tap1 << ", " << tap2 << ") -- Status = ";
				        lfsrPtr = new LFSR(seed, tap1, tap2);
                        cout << "Completed" << endl;
                    }
                    
				  }
				  catch ( std::bad_alloc )
				  {
				    cout << "Failed Constructor: Terminating now..." << endl;
					return 1;
				  }
                  break;

      case '+':   // Enqueue
                  inputs >> n;

                  if (queuePtr != NULL)
                  {
                     cout << "Queue::Enqueue('" << n << "') -- Status = ";
                  }
                  else if (lfsrPtr != NULL)
                  {
                     cout << "LFSR::Enqueue('" << n << "') -- Status = ";
                  }

                  if (queuePtr != NULL) 
                  {
                     try
                     {
                        queuePtr->Enqueue(n);
                        cout << "Completed" << endl;
                     }
                     catch (QueueFull)
                     {
                        cout << "Failed QueueFull" << endl;
                     };
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;

      case '-':   // Dequeue
                  if (queuePtr != NULL)
                  {
                     cout << "Queue::Dequeue() -- Status = ";
                  }
                  else if (lfsrPtr != NULL) 
                  {
                     cout << "LFSR::Dequeue() -- Status = ";
                  }

                  if (queuePtr != NULL)
                  {
                     try
                     {
                        queuePtr->Dequeue();
                        cout << "Completed" << endl;
                     }
                     catch (QueueEmpty)
                     {
                        cout << "Failed QueueEmpty" << endl;
                     };
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;

      case 'f':   // Front
                  if (queuePtr != NULL)
                  {
                     cout << "Queue::Front() -- Status = ";
                  }
                  else if (lfsrPtr != NULL) 
                  {
                     cout << "LFSR::Front() -- Status = ";
                  }

                  if (queuePtr != NULL) 
                  {
                     try
                     {
                        n = queuePtr->Front();
                        cout << "Completed, Value = " << n << endl;
                      }
                     catch (QueueEmpty)
                     {
                        cout << "Failed QueueEmpty" << endl;
                     }
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;

      case 'r':   // Rear
                  if (queuePtr != NULL)
                  {
                     cout << "Queue::Rear() -- Status = ";
                  }
                  else if (lfsrPtr != NULL) 
                  {
                     cout << "LFSR::Rear() -- Status = ";
                  }

                  if (queuePtr != NULL) 
                  {
                     try
                     {
                        n = queuePtr->Rear();
                        cout << "Completed, Value = " << n << endl;
                     }
                     catch (QueueEmpty)
                     {
                        cout << "Failed QueueEmpty" << endl;
                     }
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;

      case 'e':   // IsEmpty
                  if (queuePtr != NULL)
                  {
                     cout << "Queue::IsEmpty() -- Status = ";
                  }
                  else if (lfsrPtr != NULL) 
                  {
                     cout << "LFSR::IsEmpty() -- Status = ";
                  }

                  if (queuePtr != NULL)
                  {
                     if (queuePtr->IsEmpty())
                        cout << "Empty" << endl;
                     else
                        cout << "Not Empty" << endl;
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;

      case 'm':   // MakeEmpty
                  if (queuePtr != NULL)
                  {
                     cout << "Queue::MakeEmpty() -- Status = ";
                  }
                  else if (lfsrPtr != NULL)
                  {
                     cout << "LFSR::MakeEmpty() -- Status = ";
                  }

                  if (queuePtr != NULL)
                  {;
                     queuePtr->MakeEmpty();
                     cout << "Completed" << endl;
                  }
                  else
                  {
                     cout << "Failed" << endl;
                  }
                  break;
				  
      case 'l':   // Size/Length
                  if (queuePtr != NULL)
                  {
                    cout << "Queue::Size() -- " << queuePtr->Size() << endl;
                  }
                  break;

      case 'n':   // NextState
                  if (lfsrPtr != NULL)
                  {
                    try
                    {
                        cout << "LFSR::NextState() -- ";
                        lfsrPtr->NextState();
                        cout << "Completed" << endl;
                    }
                    catch (...)
                    {
                        cout << "Failed" << endl;
                    }
                  }
                  break;

      case '?':   // Peek
                  inputs >> n;
                  cout << "Queue::Peek(" << n << ") -- ";
                  if (queuePtr != NULL)
                  {
                    try 
                    {
                        cout << queuePtr->Peek(n) << endl;
                    }
                    catch (QueueEmpty)
                    {
                        cout << "Failed QueueEmpty" << endl;
                    }
                    catch (QueueInvalidPeek)
                    {
                        cout << "Failed QueueInvalidPeek" << endl;
                    }
                  }
                  break;

      case 'p':   // Print
                  if (queuePtr != NULL)
                  {
                    cout << "Queue::PrintQ() -- ";
                    queuePtr->PrintQ();	
                    cout << endl;
                  }
                  else if (lfsrPtr != NULL)
                  {
                    cout << "LFSR::Print() -- ";
                    lfsrPtr->Print();	
                    cout << endl;
                  }

                  break;
				  
      case 'd':   // Destructor
                  try
                  {
                        if (queuePtr != NULL)
                        {
                            cout << "Queue::~Queue() -- Status = ";
                            delete queuePtr;
                            queuePtr = NULL;
                            cout << "Completed" << endl;
                        }
                        else if (lfsrPtr != NULL)
                        {
                            cout << "LFSR::~LFSR() -- Status = ";
                            delete lfsrPtr;
                            lfsrPtr = NULL;
                            cout << "Completed" << endl;
                        }
                  }
                  catch (...)
                  {
                        cout << "Failed Destructor : Terminating now..." << endl;
                        return 1;
                  }
                  
				  break;

      default:    // Error
                  cout << "Error - unrecognized operation : Terminating now..." << endl;
				  return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }
  
  cout << endl;
  Bar(60);                                           // Output long bar

  return 0;
} // End main()

void Bar(int n)
// Bar() -- prints horizontal bar
{
	for(int k = 0; k < n; k++)
        cout << '#'; 
    cout << endl;
}  // End Bar()



