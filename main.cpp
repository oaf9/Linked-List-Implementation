
#include "List.h"
#include <iostream>
using namespace std;


int main()
{

    
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
