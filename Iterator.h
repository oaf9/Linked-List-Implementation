//
//  Iterator.h
//  hw5
//
//  Created by Omar Afifi on 11/24/21.
//

// this file contains the declaration of the iterator class


#ifndef Iterator_h
#define Iterator_h

#include <stdio.h>
#include "Node.h"
#include "List.h"
#include <cassert>






class Iterator
{
    // we want to make Node, List, freind classes so we can access fields
    friend class List;
    friend class Node;
    
private:
    // the fields of an iterator are a pointer to a node, i.e. a position in the linekd list
    // and also a pointer to the lsit the iterator is assigned to (i.e. container).
    //Node* position;
    const List* container;
    Node* position;

public:
    Iterator(){}; // a constructor
    // we overload a couple of operators : dereferecing operator (*), increment (++)
    int  operator * () const; //return the data at a given node the iterator is at
    Iterator& operator ++ (int); // move the iterator to the next node in the container linekd list
    void operator ++ ();
    void operator -- (); // move the iterator to the previous node in the container linekd list
    bool operator == (const Iterator& b) const; // see if two iterators are at the same node
    bool operator != (const Iterator& b) const;
};


#endif /* Iterator_hpp */
