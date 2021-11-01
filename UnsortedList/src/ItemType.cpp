#include <fstream>
#include "ItemType.h"

ItemType::ItemType() {
    value_ = 0;
}

void ItemType::Initialize(int number) {
    value_ = number;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
    if (value_ < otherItem.value_)
        return LESS;
    else if (value_ > otherItem.value_)
        return GREATER;
    else
        return EQUAL;
}

void ItemType::Print(std::ofstream& out) const {
    out << value_ << " ";
}
