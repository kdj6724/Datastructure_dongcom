#include <iostream>
#include "SortedList.h"

int main(void) {
    SortedList<char> list;

    list.InsertItem('e');
    list.InsertItem('a');
    list.InsertItem('d');
    list.InsertItem('b');
    list.InsertItem('c');

    list.ResetList();
    for (int i=0; i<list.LengthIs(); i++) {
        char value;
        list.GetNextItem(value);
        std::cout << value << std::endl;
    }
}