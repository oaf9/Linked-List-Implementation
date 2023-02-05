//
//  Iterator.cpp
//  hw5
//
//  Created by Omar Afifi on 11/24/21.
//

#include <iostream>
#include "Iterator.h"

// operator implementations:

Iterator& Iterator :: operator ++ (int)
{
    // we want to ensure we aren't past the end of the list. in this case, we will be pointing to nullptr.
    // it doesn't make sense to go
    assert(position != nullptr);
    position = position->next; // move it to the next node
    return *this;
}

void Iterator :: operator ++()
{
    // we want to ensure we aren't past the end of the list. in this case, we will be pointing to nullptr.
    // it doesn't make sense to go
    assert(position != nullptr);
    position = position->next; // move it to the next node
}



void Iterator :: operator -- ()
{
    // we want to make sure we aren't at the beginning of the list, in which case the -- operation is senseless
    assert( position != (*container).initial_node);
    // if we are at the end end of the list, we just want to move to the last node
    if(position == nullptr)
    {
        position = (*container).terminal_node;
    }
    else //in the general case, we simply move our iterator to the previous node
    {
        position = (*position).previous;
    }
}

int Iterator :: operator * () const
{
    // if we are at the end end of the list, there is nothing to return
    assert(position != nullptr);
   // std :: cout << 0 << std :: endl;
    
    return position->data;
}

bool Iterator :: operator == ( const Iterator& b) const
{
    if (position == b.position) { return true; }
    else { return false; }
}

bool Iterator :: operator != (const Iterator& b) const
{
    if (position == b.position) { return false; }
    else { return true; }
}

