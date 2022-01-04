#include <iostream>

typedef int ItemType;
bool BinarySearch(ItemType* info, ItemType item,
                int from, int to) {
        if (from > to)
                return false;
        else {
                int mid;
                mid = (to + from) / 2;
                
                if (item < info[mid])
                        return BinarySearch(info, item, from, mid-1);
                else if (item == info[mid])
                        return true;
                else
                        return BinarySearch(info, item, mid+1, to);
        }
}

int main(void) {
        ItemType info[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int val = 0;

        for (val=0; val<20; val++) {
                if (BinarySearch(info, val, 0, 9)) {
                        std::cout << "found value : " << val << std::endl;
                } else {
                        std::cout << "not found value : " << val << std::endl;
                }
        }
}
