#include <fstream>

const int MAX_ITEMS = 5;
enum RelationType {
    LESS,
    GREATER,
    EQUAL,
};

class ItemType {
    public:
        ItemType();
	    void Initialize(int number);
        RelationType ComparedTo(ItemType) const;
        void Print(std::ofstream&) const;
    private:
        int value_;
};
