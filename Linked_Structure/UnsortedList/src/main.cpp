#include <iostream>
#include "UnsortedList.h"

int main(void) {
    UnsortedList<char> list;

    list.InsertItem('a');
    list.InsertItem('b');
    list.InsertItem('c');
    list.InsertItem('d');
    list.InsertItem('e');

    list.ResetList();
    for (int i=0; i<list.LengthIs(); i++)
    {
        /* code */
        char value;
        list.GetNextItem(value);
        std::cout << value << std::endl;
    }
    
}