#include "UnsortedType.h"

UnsortedType::UnsortedType() {
    length_ = 0;
}

void UnsortedType::MakeEmpty() {
    length_ = 0;
}

bool UnsortedType::IsFull() const {
    return (length_ == MAX_ITEMS);
}

int UnsortedType::LengthIs() const {
    return length_;
}

void UnsortedType::InsertItem(ItemType item) {
    info_[length_] = item;
    length_++;
}

void UnsortedType::ResetList() {
    currentPos_ = -1;
}

void UnsortedType::GetNextItem(ItemType& item) {
    currentPos_++;
    item = info_[currentPos_];
}