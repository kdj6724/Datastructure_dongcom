template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

class FullStack {
};

class EmptyStack {
};

template <class ItemType>
class StackType {
public:
    StackType();
    ~StackType();
    void Push(ItemType item);
    void Pop();
    ItemType Top();
    bool IsEmpty() const;
    bool IsFull() const;
private:
    NodeType<ItemType>* topPtr_;
};

template <class ItemType>
StackType<ItemType>::StackType() {
    topPtr_ = nullptr;
}

template <class ItemType>
StackType<ItemType>::~StackType() {
    NodeType<ItemType>* tempPtr;

    while (topPtr_ != nullptr) {
        tempPtr = topPtr_;
        topPtr_ = topPtr_->next;
        delete tempPtr;
    }
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType item) {
    if (IsFull()) {
        throw FullStack();
    } else {
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        location->info = item;
        location->next = topPtr_;
        topPtr_ = location;
    }
}

template <class ItemType>
void StackType<ItemType>::Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    } else {
        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr_;
        topPtr_ = topPtr_->next;
        delete tempPtr;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::Top() {
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr_->info;
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const {
    return (topPtr_ == nullptr);
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const {
    NodeType<ItemType>* location;
    try {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}
