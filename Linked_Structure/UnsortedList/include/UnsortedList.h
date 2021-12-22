template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class UnsortedList {
public:
    UnsortedList();
    ~UnsortedList();
    bool IsFull() const;
    int LengthIs() const;
    void MakeEmpty();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
private:
    NodeType<ItemType>* listData_;
    int length_;
    NodeType<ItemType>* currentPos_;
};

template <class ItemType>
UnsortedList<ItemType>::UnsortedList() {
    length_ = 0;
    listData_ = nullptr;
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList() {

}

template <class ItemType>
bool UnsortedList<ItemType>::IsFull() const {
    NodeType<ItemType>* location;
    try {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

template <class ItemType>
int UnsortedList<ItemType>::LengthIs() const {
    return length_;
}

template <class ItemType>
void UnsortedList<ItemType>::MakeEmpty() {
    NodeType<ItemType>* temp;

    while (listData_ != nullptr)
    {
        /* code */
        temp = listData_;
        listData_ = listData_->next;
        delete temp;
    }
    length_ = 0;
}

template <class ItemType>
void UnsortedList<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData_;
    found = false;
    moreToSearch = (location != nullptr);

    while (moreToSearch && !found)
    {
        /* code */
        if (item == location->info) {
            found = true;
        } else {
            location = location->next;
            moreToSearch = (location != nullptr);
        }
    }
    
}

template <class ItemType>
void UnsortedList<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData_;
    listData_ = location;
    length_++;
}

template <class ItemType>
void UnsortedList<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType>* location = listData_;
    NodeType<ItemType>* temp;

    if (item == location->info) {
        temp = location;
        listData_ = location->next;
    } else {
        while (!(item == (location->next)->info))
            location = location->next;
        temp = location->next;
        location->next = (location->next)->next;
    }
    delete temp;
    length_--;
}

template <class ItemType>
void UnsortedList<ItemType>::ResetList() {
    currentPos_ = nullptr;
}

template <class ItemType>
void UnsortedList<ItemType>::GetNextItem(ItemType& item) {
    if (currentPos_ == nullptr)
        currentPos_ = listData_;
    else
        currentPos_ = currentPos_->next;
    item = currentPos_->info;
}
