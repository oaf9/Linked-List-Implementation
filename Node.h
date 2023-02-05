//
//  Node.h
//  hw5
//
//  Created by Omar Afifi on 11/24/21.
//

#ifndef Node_h
#define Node_h
#include <stdio.h>
#include <string>
#include<iostream>

class List;
class Iterator;

// the node class: a node essentially consists of pointers to antecedent nodes: as well as a data unit: in this class an int
class Node
{
// we want to be able to access private members of the Nodes in the list or iterator functions
friend class Iterator;
friend class List;
  
private:
    // the data types
    Node* previous;
    Node* next;
    int data;

public:
    // constructors
    Node(int y): data(y){};
    ~Node(){}
};










#endif /* Node_h */
