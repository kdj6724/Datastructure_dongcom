#include <iostream>
#include <fstream>
#include "UnsortedType.h"

void GetData(std::ifstream& dataFile, ItemType& item) {
    std::string str;

    std::getline(dataFile, str);
    if (str != "")
        item.Initialize(stoi(str));
}
  
void PrintList(std::ofstream& dataFile, UnsortedType list) {
    int length;
    ItemType item;

    list.ResetList();
    length = list.LengthIs();
    for (int counter = 0; counter < length; counter++) {
        list.GetNextItem(item);
        item.Print(dataFile);
    }    
}

void CreateListFromFile(std::ifstream& dataFile, UnsortedType& list) {
    ItemType item;
    
    list.MakeEmpty();
    GetData(dataFile, item);
    while (dataFile) {
        if (!list.IsFull())
            list.InsertItem(item);
        GetData(dataFile, item);
    }
}

#if 0
int main(void) {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    UnsortedType list;

    if (!input)
        std::cout << "Can not found input.txt" << std::endl;

    CreateListFromFile(input, list);
    PrintList(output, list);
    return 0;
}
#else
int main(void) {
    std::ofstream output("output.txt");
    UnsortedType list;
    ItemType item1, item2, item3, item4, item5;
    item1.Initialize(8);
    item2.Initialize(2);
    item3.Initialize(3);
    item4.Initialize(11);
    item5.Initialize(1);
    list.MakeEmpty();
    list.InsertItem(item1);
    list.InsertItem(item2);
    list.InsertItem(item3);
    list.InsertItem(item4);
    list.InsertItem(item5);
    list.ResetList();
    for (int count=0; count<list.LengthIs(); count++) {
        ItemType item;
        list.GetNextItem(item);
        item.Print(output);
    }
    output.close();
}
#endif
