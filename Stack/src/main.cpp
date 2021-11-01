#include <iostream>
#include "StackType.h"

using namespace std;

int main(void) {
    StackType stack;

    for (int i=0; i<5; i++) {
        ItemType item;

        item.Initialize(i);
        try {
            stack.Push(item);
        } catch (FullStack exceptionObject) {
            exceptionObject.report();
        }
    }

    while(!stack.IsEmpty()) {
        ItemType item;

        try {
            item = stack.Top();
            stack.Pop();
        } catch (EmptyStack exceptionObject) {
            exceptionObject.report();
        }
        item.Print();
    }
}