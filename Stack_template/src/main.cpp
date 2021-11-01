#include <iostream>
#include "StackType.h"

using namespace std;

int main(void) {
    StackType<int> nStack;
    StackType<char> chStack;

    for (int i=0; i<5; i++) {
        try {
            nStack.Push(i);
        } catch (FullStack exceptionObject) {
            exceptionObject.report();
        }
    }
    while(!nStack.IsEmpty()) {
        int nVal;
        try {
            nVal = nStack.Top();
            nStack.Pop();
        } catch (EmptyStack exceptionObject) {
            exceptionObject.report();
        }
        std::cout << "int  type : " << nVal << std::endl;
    }

    for (int i=0; i<5; i++) {
        char val = 'a';
        try {
            chStack.Push(val+i);
        } catch (FullStack exceptionObject) {
            exceptionObject.report();
        }
    }
    while(!chStack.IsEmpty()) {
        char val;
        try {
            val = chStack.Top();
            chStack.Pop();
        } catch (EmptyStack exceptionObject) {
            exceptionObject.report();
        }
        std::cout << "char type : " << val << std::endl;
    }

    return 0;
}