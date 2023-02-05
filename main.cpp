
#include "List.h"
#include <iostream>
using namespace std;

/**
 the merge fucntion merges two lsits into a bigger list
 @param1 a a List of ints
 @param2 b a List of ints
 @ return new_list a list of ints containting the elements of a and b
 

List merge ( const List& a, const List& b)
{
    // declare a new list
    List new_list;
    // make iterators set to the beginning of  each list
    Iterator iter1 = a.begin();
    Iterator iter2 = b.begin();
    
    while((iter1 != a.end()) || (iter2 != b.end()) ) // while we are not at the end of both lists
        {
            if(iter1 != a.end()) // check if we are at the end of a
            { new_list.push_back(*iter1); ++iter1;}  //add current node in a  new_list
            
            if(iter2 != b.end()) // check if we are at the end of b
            { new_list.push_back(*iter2);  ++iter2;}  //add current node in b to  new_list

        }
    return new_list; // return new_list
}



/**
 this function returns the size of a list
 @param a a list
 @return size an int storing the length of a
 
int size(const List& a)
{
    int size = 0; // counter starting at zero
    Iterator pos = a.begin(); // iterator initilized to the first node in a
    while(pos != a.end())  // while not at the end of a
    {
        size ++; // add one to size
        pos++; // move the position
    }
    return size; // return size
}




/**
 this funtion reverses a linked list
 @param a the list
 @return return_list the reverted list
 
List reverse (const List& a)
{
    // declare a new list
    List return_list;
    // make an iterator to point to the begining of the list
    Iterator iter = a.begin();
    // while we aren't at the end of the list
    while( iter != a.end())
    // push_front the current element of a
    { return_list.push_front(*iter); iter++;}
    
    return return_list; // return returnlist
}



// finally the sorting algorithms :

/**
 this function merges to sorted lists into a sorted list
 @param1 a the first sorted lsit
 @param2 b the second sorted lsit
 @return merged the merged list

List merge2(const List& a, const List& b)
{
    //declaring iterators
    Iterator iter1 = a.begin();
    Iterator iter2 = b.begin();
    
    List merged;
    
    while(iter1 != a.end() || iter2!=b.end()) // while neither list has been traversed
    {
        
        if ( (iter1 == a.end()) && (iter2 != b.end()) ) // if a has been traversed, but not b;
        { merged.push_back(*iter2); iter2++; } // add the current node in b, increment pointer to b
        else if ( (iter1 != a.end()) && (iter2 == b.end()) ) // if b has been traversed, but not a;
        { merged.push_back(*iter1); iter1++;} // add the current node in a, increment pointer to a
        
        else if(*iter1 == *iter2)// if both values are the same
        {merged.push_back(*iter1); merged.push_back(*iter2);iter1++; iter2++;} // add current node in both lists and increment both pointers
        else if(*iter1 > *iter2)
        {merged.push_back(*iter2); iter2++;}
        else
        {merged.push_back(*iter1); iter1++;}
    }
        return merged;
}

 */

/**
 this function will generate a list from an old list by adding either the even or odd indeces of the original list to the new list
 @param1 a the generating list
 @param2 y a boolean
 @return first_half or second_half, depending on what y was

List list_splitter(const List& a, bool y)
{
// declaring two new lists;
List one_half; // one half will take on the even indeces, second half take son the odd ones. we return one_half when y is true, second_half when y is false
List second_half;
    
Iterator pos = a.begin(); // new iterator at the beginning of the list.
    
if(a.size() == 1){return a;} // if the list has one node, return it
    
else if(a.size()== 2) // if the list has two nodes, split it into two lists of one node
{
    one_half.push_back(*pos);
    ++pos;
    second_half.push_back(*pos);
    if (y == true) {return one_half;}
    else {return second_half;}
}
        
else{ // in the general case, we loop through the list, adding even indeces to one_half, odd ones to second_half
while(pos != a.end())
{
    one_half.push_back(*pos);
    ++pos;
    if(pos != a.end())
       { second_half.push_back(*pos); ++pos;}
}

    if (y == true) {return one_half;} // return according to y
    else {return second_half;}
}

}

 */


/**
 a merge_sott implementation to sort a list
 @param1 a the lsit we want to sort
 @return the sorted list
 
List merge_sort( const List& a)
{
    // base case a is a singleton list or empty list
    if( (a.size() == 1) || (a.size() == 0) )
        { return a; }
    // use list splitter to generate two lists.
    // I just want to point out that list splitter
    //is lowkey kind of  brilliant because we never
    //have to worry about when there is an odd number of nodes.
    List first = list_splitter(a, true);
    List second = list_splitter(a, false);
    
    // return the merged recursiely sorted halves;
    return merge2( merge_sort(first), merge_sort(second));
}

*/


























int main()
{

    

    
    /*
    
    
    List x;
    List y;
    
    x.push_back(0);
    x.push_back(4);
    x.push_back(8);
    x.push_back(9);
    x.push_back(45);
    x.push_back(67);
    
    x.print();
    cout << size(x) << endl;
    
    y.push_back(1);
    y.push_back(2);
    y.push_back(4);
    y.push_back(18);
    y.push_back(34);
    y.push_back(99);
    y.push_back(100);
    y.push_back(1001);
    
    y.print();
    cout << size(y) << endl;
    List f = merge2(y,x);
    
    f.print();
    cout << size(f) << endl;
    
    
    cout << endl;
    cout << endl;
    
    
    
    List g;
    
    g.push_back(4);
    g.push_back(2);
    g.push_back(3);
    g.push_back(1);
    g.push_back(50);
    g.push_back(0);
    g.push_back(32);
    g.push_back(33);
    g.push_back(31);
    g.push_back(46);
    g.push_back(31);
    g.push_back(51);
    
    g.print();
    
    List c = reverse(g);
    c.print();
    
    List d = merge(g,c);
    d.print();
    
   // List f = merge_sort(d);
    
   // f.print();
    
    List y = list_splitter(d, true);
    y.print();
    
    /*
    Iterator iter = g.begin();
    iter++;
    iter++;
    iter++;
    cout << *iter << endl;
    iter = g.erase(iter);
    cout << *iter << endl;
  
    g.print();
    
    
    cout << "hey" << endl;
    
    List c = merge_sort(g);
    
    c.print();
    
    //List m = list_splitter(g,true);
    //List n = list_splitter(g,false);
    
    //m.print();
    //n.print();
    
   // List h;
    //cout << h.size();
   // h.push_back(1);
  //  h.push_back(2);
    //h.push_back(1);
    //
    
   // list_splitter(h,1);
    
    /*
    cout << endl;
    cout << "hey " << endl;
    List a;
    List b;
    
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    
    List d = merge2(b,a);
    
   d.print();
    
    
    */
    
    List b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(7);
    b.push_back(11);

    List x;
    
    x.push_back(0);
    x.push_back(4);
    x.push_back(8);
    x.push_back(9);
    x.push_back(45);
    x.push_back(67);
    x.push_back(90);
    x.print();
    /*
    x.print();
    b.print();
    b.merge(x);
    b.print();
*/
  
    b.print();
    cout << b.size() << endl;
   b.reverse();
    
   // b.merge(x);
    b.print();
    //delete b;
    
    
    return 0;
}
