#include <fstream>

const int MAX_ITEMS = 6;
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
        void Print(void);
    private:
        int value_;
};
