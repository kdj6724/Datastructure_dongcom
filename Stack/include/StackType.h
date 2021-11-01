#include "ItemType.h"

class FullStack {
public:
    void report();
};
class EmptyStack {
public:
    void report();
};

class StackType {
public:
    StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top() const;
private:
    int top_;
    ItemType info_[MAX_ITEMS];
};