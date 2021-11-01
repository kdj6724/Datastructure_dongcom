class FullStack {
public:
    void report();
};
class EmptyStack {
public:
    void report();
};

void FullStack::report() {
    std::cerr << "FullStack exception thrown" << std::endl;
}

void EmptyStack::report() {
    std::cerr << "EmptyStack exception thrown" << std::endl;
}

const int MAX_ITEMS = 5;
template<class ItemType>
class StackType {
public:
    StackType();
    StackType(int max);
    ~StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top() const;
private:
    int top_;
    int maxStack_;
    ItemType* info_;
};

template<class ItemType>
StackType<ItemType>::StackType() {
    top_ = -1;
    maxStack_ = 10;
    info_ = new ItemType[maxStack_];
}

template<class ItemType>
StackType<ItemType>::StackType(int max) {
    top_ = -1;
    maxStack_ = max;
    info_ = new ItemType[maxStack_];
}

template<class ItemType>
StackType<ItemType>::~StackType() {
    delete [] info_;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
    return (top_ == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const {
    return (top_ == maxStack_ - 1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType item) {
    if (IsFull())
        throw FullStack();
    top_++;
    info_[top_] = item;
}

template<class ItemType>
void StackType<ItemType>::Pop() {
    if (IsEmpty())
        throw EmptyStack();
    top_--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top() const {
    if (IsEmpty())
        throw EmptyStack();
    return info_[top_];
}