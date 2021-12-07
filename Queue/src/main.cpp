#include "queue_type.h"
#include  <iostream>

int main() {
    QueueType queue(100);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(6);
    queue.Enqueue(7);
    queue.Enqueue(8);
    queue.Enqueue(9);
    queue.Enqueue(10);

    while (queue.IsEmpty() == false) {
        ItemType item;
        /* code */
        queue.Dequeue(item);
        std::cout << "out : " << item << std::endl;
    }

    return 0;
    
}