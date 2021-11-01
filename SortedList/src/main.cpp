#include <iostream>
#include <fstream>
#include "SortedType.h"

void GetData(std::ifstream& dataFile, ItemType& item) {
    std::string str;

    std::getline(dataFile, str);
    if (str != "") {
        item.Initialize(stoi(str));
    }
}
  
void PrintList(std::ofstream& dataFile, SortedType list) {
    int length;
    ItemType item;

    list.ResetList();
    length = list.LengthIs();
    for (int counter = 0; counter < length; counter++) {
        list.GetNextItem(item);
        item.Print(dataFile);
    }    
}

void CreateListFromFile(std::ifstream& dataFile, SortedType& list) {
    ItemType item;
    
    list.MakeEmpty();
    GetData(dataFile, item);
    while (dataFile) {
        if (!list.IsFull())
            list.InsertItem(item);
        GetData(dataFile, item);
    }
}

int main(void) {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    SortedType list;

    if (!input)
        std::cout << "Can not found input.txt" << std::endl;

    CreateListFromFile(input, list);
    PrintList(output, list);
    return 0;
}
