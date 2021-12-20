#include <cstddef>
#include <new>

class FullQueue {};
class EmptyQueue {};

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class Queue {
public:
    Queue();
    ~Queue();
    void MakeEmpty();
    void Enqueue(ItemType);
    void Dequeue(ItemType&);
    bool IsEmpty() const;
    bool IsFull() const;
private:
    NodeType<ItemType>* front_;
    NodeType<ItemType>* rear_;
};

template <class ItemType>
Queue<ItemType>::Queue() {
    front_ = nullptr;
    rear_ = nullptr;
}

template <class ItemType>
Queue<ItemType>::~Queue() {
    MakeEmpty();
}

template <class ItemType>
void Queue<ItemType>::MakeEmpty() {
    NodeType<ItemType>* temp;
    while (front_ != nullptr)
    {
        /* code */
        temp = front_;
        front_ = front_->next;
        delete temp;
    }
    rear_ = nullptr;
}

template <class ItemType>
void Queue<ItemType>::Enqueue(ItemType item) {
    if (IsFull()) {
        throw FullQueue();
    } else {
        NodeType<ItemType>* newNode;
        newNode = new NodeType<ItemType>;
        newNode->info = item;
        newNode->next = nullptr;
        if (rear_ == nullptr)
            front_ = newNode;
        else
            rear_->next = newNode;

        rear_ = newNode;
    }
}

template <class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item) {
    if (IsEmpty()) {
        throw EmptyQueue();
    } else {
        NodeType<ItemType>* temp;
        temp = front_;
        item = front_->info;
        front_ = front_->next;
        if (front_ == nullptr)
            rear_ = nullptr;
        delete temp;
    }
}

template <class ItemType>
bool Queue<ItemType>::IsEmpty() const {
    return (front_ == nullptr);
}

template <class ItemType>
bool Queue<ItemType>::IsFull() const {
    NodeType<ItemType>* temp;
    try {
        temp = new NodeType<ItemType>;
        delete temp;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}