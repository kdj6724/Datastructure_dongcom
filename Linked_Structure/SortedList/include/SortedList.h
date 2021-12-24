template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class SortedList {
public:
    SortedList();
    ~SortedList();
    bool IsFull() const;
    int LengthIs() const;
    void MakeEmpty();
    ItemType* RetrieveItem(ItemType item, bool& found);
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
SortedList<ItemType>::SortedList() {
    length_ = 0;
    listData_ = nullptr;
}

template <class ItemType>
SortedList<ItemType>::~SortedList() {

}

template <class ItemType>
bool SortedList<ItemType>::IsFull() const {
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
int SortedList<ItemType>::LengthIs() const {
    return length_;
}

template <class ItemType>
void SortedList<ItemType>::MakeEmpty() {
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
ItemType* SortedList<ItemType>::RetrieveItem(ItemType item, bool& found) {
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
    return location;
}

template <class ItemType>
void SortedList<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* temp;
    NodeType<ItemType>* location = listData_;

    temp = new NodeType<ItemType>;
    temp->info = item;
    temp->next = nullptr;

    if (location == nullptr) {
        location = temp;
        listData_ = location;
        length_++;
        return;
    }

    while (1) {
        if (location->next == nullptr) 
            break;
        if (location->next->info > item)
            break;
        location = location->next;
    }

    if (location->info > item) {
        temp->next = location;
        listData_ = temp;
    } else {
        temp->next = location->next;
        location->next = temp;
    }
    length_++;
}

template <class ItemType>
void SortedList<ItemType>::DeleteItem(ItemType item) {
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
void SortedList<ItemType>::ResetList() {
    currentPos_ = nullptr;
}

template <class ItemType>
void SortedList<ItemType>::GetNextItem(ItemType& item) {
    if (currentPos_ == nullptr)
        currentPos_ = listData_;
    else
        currentPos_ = currentPos_->next;
    item = currentPos_->info;
}
