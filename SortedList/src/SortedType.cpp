#include <iostream>
#include "SortedType.h"

SortedType::SortedType() {
    length_ = 0;
}

void SortedType::MakeEmpty() {
    length_ = 0;
}

bool SortedType::IsFull() const {
    return (length_ == MAX_ITEMS);
}

int SortedType::LengthIs() const {
    return length_;
}

void SortedType::RetrieveItem(ItemType& item, bool& found) {
    int midPoint;
    int first = 0;
    int last = length_ -1;
    bool moreToSearch = (first <= last);
    
    found = false;

    while (moreToSearch && !found) {
        switch (item.ComparedTo(info_[midPoint])) {
            case LESS:
                last = midPoint -1;
                moreToSearch = (first <= last);
                break;
            case GREATER:
                first = midPoint + 1;
                moreToSearch = (first <= last);
                break;
            case EQUAL:
                found = true;
                item = info_[midPoint];
                break;
        }
    }
}

void SortedType::InsertItem(ItemType item) {
    bool moreToSearch;
    int location = 0;

    moreToSearch = (location < length_);
    while (moreToSearch) {
        switch (item.ComparedTo(info_[location])) {
            case LESS:
                moreToSearch = false;
                break;
            case GREATER:
                location++;
                moreToSearch = (location < length_);
                break;            
        }
    }
    for (int index=length_; index>location; index--) {
        info_[index] = info_[index-1];
    }
    info_[location] = item;
    length_++;
}

void SortedType::DeleteItem(ItemType item) {
    int location = 0;
    while (item.ComparedTo(info_[location]) != EQUAL) {
        location++;
    }
    for (int index=location+1; index<length_; index++)
        info_[index-1] = info_[index];
    length_--;
}
void SortedType::ResetList() {
    currentPos_ = 0;
}

void SortedType::GetNextItem(ItemType& item) {
    currentPos_++;
    item = info_[currentPos_];
}
