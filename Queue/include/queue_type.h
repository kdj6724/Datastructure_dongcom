class FullQueue{};
class EmptyQueue{};
typedef int ItemType;
class QueueType {
public:
    QueueType(int max);
    QueueType();
    ~QueueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
private:
    int front_;
    int rear_;
    ItemType* items_;
    int maxQueue_;
};

QueueType::QueueType(int max) {
    maxQueue_ = max + 1;
    front_ = maxQueue_ - 1;
    rear_ = maxQueue_ - 1;
    items_ = new ItemType[maxQueue_];
}

QueueType::QueueType() {
    QueueType(501);
}

QueueType::~QueueType() {
    delete [] items_;
}

void QueueType::MakeEmpty() {
    front_ = maxQueue_ - 1;
    rear_ = maxQueue_ - 1;
}

bool QueueType::IsEmpty() const {
    return (rear_ == front_);
}

bool QueueType::IsFull() const {
    return ((rear_ + 1) % maxQueue_ == front_);
}

void QueueType::Enqueue(ItemType item) {
    if (IsFull()) {
        throw FullQueue();
    } else {
        rear_ = (rear_ + 1) % maxQueue_;
        items_[rear_] = item;
    }
}

void QueueType::Dequeue(ItemType& item) {
    if (IsEmpty()) {
        throw EmptyQueue();
    } else {
        front_ = (front_ + 1) % maxQueue_;
        item = items_[front_];
    }
}