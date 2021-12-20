#include <iostream>
#include "stack.h"

int main(void) {
    StackType<char> stack;

    stack.Push('a');
    stack.Push('b');
    stack.Push('c');
    stack.Push('d');
    stack.Push('e');
    
    while (!stack.IsEmpty()) {
        std::cout << stack.Top() << std::endl;
        stack.Pop();
    }
    
    return 0;
}