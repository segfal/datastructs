#include <iostream>
#include "Data_Structures.hpp"
using namespace std;





int main()
{
   
   

DoublyLinkedList<int> dll;
dll.push_back(1);
dll.push_back(2);
dll.push_back(3);
dll.pop_front();
dll.insert(4,1);
dll.print();
dll.remove(1);
dll.print();



    
}