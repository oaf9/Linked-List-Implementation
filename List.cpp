//
//  List.cpp
//  hw5
//
//  Created by Omar Afifi on 11/24/21.
//
#include<iostream>
#include "List.h"

/*
 this file contains the implememntations for the
 methods in the List h_file
*/

/**
 this method returns an iterator located at the initlal node of the linked list
 @return return_iterator the iterator whos container is this, and whos position is initial_node
 */
Iterator List :: begin() const 
{
    Iterator return_iterator; // make a new iterator
    return_iterator.position = initial_node; // change position to initial_node
    return_iterator.container = this; // initialize container to this
    
    return return_iterator; // return return_iterator
}

/**
 this method returns an iterator located pst the terminal node  of the linked list
 @return return_iterator the iterator whos container is this, and whos position is one past the terminal node
 */
Iterator List :: end() const
{
    Iterator return_iterator; // make a new iterator
    return_iterator.position = nullptr; //point to nullptr cause we are at the end of the list.
    return_iterator.container = this; // initialize container to this
    return return_iterator; // return return_iterator
}


/**
 this method inserts a node into a linked list
 @param1 pos an iterator pointing to where we want to insert
 @param2 y the int we want to insert
 @return return_iterator the iterator whos container is this, and whos position is initial_node
 */
Iterator List :: insert(Iterator pos, int y)
{
    // so we create a new node on the heap with our int, y
    
    
    // case 1: empty list
    
    if( initial_node == terminal_node && terminal_node == nullptr)
    { this->push_back(y); pos.position = terminal_node;}
    // case 2: actually tying to pushback:
    else if(pos.position == nullptr) {this->push_back(y); pos.position = terminal_node;}
    // case 3: trying to add at the beginning:
    else if( pos.position == initial_node)
    {
        Node* new_node = new Node(y);
        initial_node->previous = new_node;
        new_node->next = initial_node;
        new_node->previous = nullptr;
        initial_node = new_node;
        pos.position = initial_node;
    }
    else
    {
        Node* new_node = new Node(y);
        
        Node* after = pos.position;
        Node* before = after->previous;
        
        new_node->previous = before;
        new_node->next = after;
        after->previous = new_node;
        before->next = new_node;
        
        pos.position = new_node;
        }
    return pos;
}
/**
 this method deletes a node in the linekd list
 */
Iterator List :: erase(Iterator pos)
{
    // we can't remove a nonexistent node
    assert(pos.position != nullptr);
    
    // creating a remove, before, after node
    Node* remove = pos.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    // if remove is the first node in the list, we jsut update first to after
    if(remove == initial_node)
    { initial_node = after; initial_node->previous = nullptr; pos.position = initial_node;}
    else
    { before->next= after; }
    // similarly, if remove == terminal_node, we jsut update terminal_node
    if (remove == terminal_node)
    { terminal_node = before; terminal_node->next = nullptr; pos.position = terminal_node;}
    // in the general case, we just switch the pointers of before and after:
    else
    { after->previous = before; pos.position = after;}
    
    delete remove;
    return pos;
}



/**
 the push_back  procedure adds a new node to the end of the linked list
 @param y the int data we want to add
 */
void List :: push_back(int y)
{
    Node* new_node = new Node(y); // make a new node on the heap with the int value
    
    if( terminal_node == nullptr) // list is empty: end = end end
    {
        // we make the first and last nodes equal to the new node, and now we have a list with one node.
        new_node->next = nullptr;
        new_node->previous = nullptr; // its a double linked lsit, so we want the initial node to point null too
        initial_node = new_node;
        terminal_node = new_node;
    }
    else
    {
        // in the general case, we let new node point to the last node, make the last node = to the new_node,
        // and then update last_node to new_node. make new_node point to nullptr
        new_node->previous = terminal_node;
        terminal_node->next = new_node;
        terminal_node = new_node;
        new_node->next = nullptr;
    }
}
/**
 the push_back  procedure adds a new node to the begining of the linked list
 @param y the int data we want to add
 */
void List :: push_front(int y)
{
    // the insert function will take care of all the special cases for us
    //(ie.e empty list): so we can just program the general case:
    
    Iterator iter = this->begin();
    this->insert(iter,y);
}

// a print fucntion is helpfull for debugging and well, printing.

/**
 this fucntion prints the elements of a linked list
 */
void List :: print() const
{
    assert(initial_node != nullptr); // can't print an empty list
    // make an iterator intialized to the begining
    Iterator pos;
    pos.position = initial_node;
    // print up to the terminal node
    std :: cout << "(";
    while(pos.position  != terminal_node)
    {
        //print node with comma
        std :: cout << *pos << ", ";
        ++pos;
    }
    // print the terminal node with no comma
    std :: cout << terminal_node->data << ")" << std :: endl;
}


int List :: size() const
{
    if( (terminal_node == initial_node) && (initial_node == nullptr) ){return 0;}
    else if((terminal_node == initial_node) && (terminal_node != nullptr) ){return 1;}
    else
    {
        int size = 0; // counter starting at zero
        Iterator pos = this->begin(); // iterator initilized to the first node in a
        while(pos != this->end())  // while not at the end of a
        {
            size++; // add one to size
            pos++; // move the position
        }
        return size; // return size
    }
}


void List :: reverse()
{
    
    Node* current = initial_node;
    Node* next;
    Node* next2;
    
    while(current != nullptr)
    {
        Node* temp = current->previous;
        std :: cout << current->data << std :: endl;
        
        current->previous = current->next;
        current->next= temp;
        
        
        current = current->previous;
        
    }

}

/**
 this function will merge our current list with another list
 @param other the lsit we want to merge
 */
void List :: merge(const List &other)
{
    // declare new iterators to the beginning of each list
    Iterator object = this->begin();
    Iterator b = other.begin();
    if(this->begin().position != nullptr){++object;}
    while ( (object != this->end()) && (b != other.end()) )
    {
        if(  (object != this->end()) && (b == other.end())   ){ break;}
        else if( (object == this->end()) && (b != other.end())   )
        {  this->push_back(*b); ++b; }
        else
        {   this->insert(object, *b); ++b; ++object;}
        
    }
}
    
    






