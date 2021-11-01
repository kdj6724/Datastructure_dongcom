#include <iostream>
#include "StackType.h"

void FullStack::report() {
    std::cerr << "FullStack exception thrown" << std::endl;
}

void EmptyStack::report() {
    std::cerr << "EmptyStack exception thrown" << std::endl;
}

StackType::StackType() {
    top_ = -1;
}

bool StackType::IsEmpty() const {
    return (top_ == -1);
}

bool StackType::IsFull() const {
    return (top_ == MAX_ITEMS - 1);
}

void StackType::Push(ItemType item) {
    if (IsFull())
        throw FullStack();
    top_++;
    info_[top_] = item;
}

void StackType::Pop() {
    if (IsEmpty())
        throw EmptyStack();
    top_--;
}

ItemType StackType::Top() const {
    if (IsEmpty())
        throw EmptyStack();
    return info_[top_];
}