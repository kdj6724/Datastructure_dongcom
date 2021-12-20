#include "queue.h"
#include <iostream>

using namespace std;

int main(void) {
    Queue<char> queue;

    queue.Enqueue('a');
    queue.Enqueue('b');
    queue.Enqueue('c');
    queue.Enqueue('d');
    queue.Enqueue('e');

    while(!queue.IsEmpty()) {
        char val;
        queue.Dequeue(val);
        cout << val << endl;
    }
    
    return 0;
}