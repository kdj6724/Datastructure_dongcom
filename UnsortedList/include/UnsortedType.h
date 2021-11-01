#include "ItemType.h"
class UnsortedType {
  public:
    UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void InsertItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
  private:
    int length_;
    ItemType info_[MAX_ITEMS];
    int currentPos_;
};
