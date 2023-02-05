//
//  List.h
//  hw5
//
//  Created by Omar Afifi on 11/24/21.
//

// this file contains the declaration for the List class
#ifndef List_h
#define List_h

#include <stdio.h>

// include iterator class: really what we want is the node file though. but that's included in the Iterator h_file

#include "Iterator.h"


class List
{
// It maked sense to make Iterator, Node friend classes. I might change this if it proves to not strictly necessary,
// but for now it will probalby make the coding easier
friend class Iterator;
friend class Node;
    
private:
    // fields are pointers to the first (initial) and terminal nodes in the list
    Node* initial_node;
    Node* terminal_node;
public:
    
    // a constructor;
    List(): initial_node(nullptr), terminal_node(nullptr) {};
    
    ~List()
    {
        Node* present = initial_node;
        Node* next;
        while(present!= nullptr)
        {
            std ::  cout << "destroyed " << std :: endl;
            next = present->next;
            delete present;
            present = next;
        }
    }
    // methods to find the begining and end of the list
    Iterator begin() const;
    Iterator end() const;
    // method to insert and remove nodes in the list
    Iterator insert(Iterator pos, int y);
    Iterator erase(Iterator pos);
    // a push_back, and push_front method
    void push_back(int y);
    void push_front(int y);
    //a print and size method
    void print() const;
    int size() const;
    
    // the sorting, reverse, merging functions and their helpers.
    void reverse();
    void merge(const List& other);
    void sorted_merge(const List& other);
   
    void sort();
    // all functions are written in the cpp file :)
};

#endif /* List_h */
