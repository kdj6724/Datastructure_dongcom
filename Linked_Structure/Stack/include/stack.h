typedef char ItemType;
struct NodeType;

struct NodeType {
    ItemType info;
    NodeType* next;
};

class FullStack {
};

class EmptyStack {
};

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
    NodeType* topPtr_;
};

StackType::StackType() {
    topPtr_ = nullptr;
}

StackType::~StackType() {
    NodeType* tempPtr;

    while (topPtr_ != nullptr) {
        tempPtr = topPtr_;
        topPtr_ = topPtr_->next;
        delete tempPtr;
    }
}

void StackType::Push(ItemType item) {
    if (IsFull()) {
        throw FullStack();
    } else {
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = topPtr_;
        topPtr_ = location;
    }
}

void StackType::Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    } else {
        NodeType* tempPtr;
        tempPtr = topPtr_;
        topPtr_ = topPtr_->next;
        delete tempPtr;
    }
}

ItemType StackType::Top() {
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr_->info;
}

bool StackType::IsEmpty() const {
    return (topPtr_ == nullptr);
}

bool StackType::IsFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}
