#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

enum class Part {
    HEAD = 1,
    TAIL = -1
};

enum class PartColor {
    RED = 1,
    YELLOW = 2,
    BLUE = 3,
    GREEN = 4
};

class Side {
private:
    Part part;
    PartColor color;

public:
    Side(Part part, PartColor color) : part(part), color(color) {}

    int getValue() const {
        return static_cast<int>(part) * static_cast<int>(color);
    }

    bool canJoin(const Side& side) const {
        if (&side == nullptr)
            return true;
        return getValue() + side.getValue() == 0;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << static_cast<int>(part) << "-" << static_cast<int>(color);
        return ss.str();
    }

    Side clone() const {
        return Side(part, color);
    }
};

class Card {
private:
    static int counter; // 정적 멤버 변수를 사용하여 카드 이름의 유일성 보장
    std::string name;
    Side top;
    Side left;
    Side bottom;
    Side right;

public:
    Card(Side top, Side left, Side bottom, Side right)
        : name("Card" + std::to_string(counter++)), top(top), left(left), bottom(bottom), right(right) {}

    // 복사 생성자
    Card(const Card& other)
        : name("Card" + std::to_string(counter++)),
        top(other.top.clone()), left(other.left.clone()), bottom(other.bottom.clone()), right(other.right.clone()) {}

    // 대입 연산자
    Card& operator=(const Card& other) {
        if (this != &other) {
            name = "Card" + std::to_string(counter++);
            top = other.top.clone();
            left = other.left.clone();
            bottom = other.bottom.clone();
            right = other.right.clone();
        }
        return *this;
    }

    bool isCompatible(const Card& leftCard, const Card& topCard) const {
        if (&leftCard == nullptr && &topCard != nullptr) {
            return top.canJoin(topCard.bottom);
        }
        else if (&leftCard != nullptr && &topCard == nullptr) {
            return left.canJoin(leftCard.right);
        }
        else if (&leftCard == nullptr && &topCard == nullptr) {
            return true;
        }
        return left.canJoin(leftCard.right) && top.canJoin(topCard.bottom);
    }

    std::string toString() const {
        return name;
    }

    Card clone() const {
        return Card(top.clone(), left.clone(), bottom.clone(), right.clone());
    }
};

int Card::counter = 1; // 정적 멤버 변수 초기화

class DraftSpace {
private:
    std::vector<std::vector<Card>> cards;
    int dim;

    int getRow(int pos) const {
        return pos / dim;
    }

    int getColumn(int pos) const {
        return pos % dim;
    }

    const Card* getLeftCard(int pos) const {
        int r, c;
        if (pos >= dim * dim) {
            return nullptr;
        }
        r = getRow(pos);
        c = getColumn(pos);
        try {
            return &cards[r][c - 1];
        }
        catch (const std::exception&) {
            return nullptr;
        }
    }

    const Card* getTopCard(int pos) const {
        int r, c;
        if (pos >= dim * dim) {
            return nullptr;
        }
        r = getRow(pos);
        c = getColumn(pos);
        try {
            return &cards[r - 1][c];
        }
        catch (const std::exception&) {
            return nullptr;
        }
    }

public:
    DraftSpace(int dim) : dim(dim) {
        cards.resize(dim, std::vector<Card>(dim));
    }

    bool tryAdd(const Card& card, int pos) {
        const Card* l = getLeftCard(pos);
        const Card* t = getTopCard(pos);
        int r = getRow(pos);
        int c = getColumn(pos);

        if (card.isCompatible(*l, *t)) {
            cards[r][c] = card.clone();
            return true;
        }

        return false;
    }
};

int main() {
    // Card 객체 생성
    Card card1(Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE),
        Side(Part::HEAD, PartColor::GREEN), Side(Part::TAIL, PartColor::YELLOW));
    Card card2(Side(Part::HEAD, PartColor::YELLOW), Side(Part::TAIL, PartColor::GREEN),
        Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE));

    // DraftSpace 객체 생성
    DraftSpace draftSpace(3);

    // 카드 추가 시도
    bool success = draftSpace.tryAdd(card1, 0);
    if (success) {
        std::cout << card1.toString() << " added successfully!" << std::endl;
    }
    else {
        std::cout << card1.toString() << " cannot be added!" << std::endl;
    }

    success = draftSpace.tryAdd(card2, 1);
    if (success) {
        std::cout << card2.toString() << " added successfully!" << std::endl;
    }
    else {
        std::cout << card2.toString() << " cannot be added!" << std::endl;
    }

    return 0;
}








//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <map>
//
//enum class Part {
//    HEAD = 1,
//    TAIL = -1
//};
//
//enum class PartColor {
//    RED = 1,
//    YELLOW = 2,
//    BLUE = 3,
//    GREEN = 4
//};
//
//class Side {
//private:
//    Part part;
//    PartColor color;
//
//public:
//    Side(Part part, PartColor color) : part(part), color(color) {}
//
//    int getValue() const {
//        return static_cast<int>(part) * static_cast<int>(color);
//    }
//
//    bool canJoin(const Side& side) const {
//        if (&side == nullptr)
//            return true;
//        return getValue() + side.getValue() == 0;
//    }
//
//    std::string toString() const {
//        std::stringstream ss;
//        ss << static_cast<int>(part) << "-" << static_cast<int>(color);
//        return ss.str();
//    }
//
//    Side clone() const {
//        return Side(part, color);
//    }
//};
//
//class Card {
//private:
//    std::string name;
//    Side top;
//    Side left;
//    Side bottom;
//    Side right;
//
//public:
//    Card(std::string name, Side top, Side left, Side bottom, Side right)
//        : name(name), top(top), left(left), bottom(bottom), right(right) {}
//
//    bool isCompatible(const Card& leftCard, const Card& topCard) const {
//        if (&leftCard == nullptr && &topCard != nullptr) {
//            return top.canJoin(topCard.bottom);
//        }
//        else if (&leftCard != nullptr && &topCard == nullptr) {
//            return left.canJoin(leftCard.right);
//        }
//        else if (&leftCard == nullptr && &topCard == nullptr) {
//            return true;
//        }
//        return left.canJoin(leftCard.right) && top.canJoin(topCard.bottom);
//    }
//
//    std::string toString() const {
//        return "Card" + name;
//    }
//
//    Card clone() const {
//        return Card(name, top.clone(), left.clone(), bottom.clone(), right.clone());
//    }
//};
//
//class DraftSpace {
//private:
//    std::vector<std::vector<Card>> cards;
//    int dim;
//
//    int getRow(int pos) const {
//        return pos / dim;
//    }
//
//    int getColumn(int pos) const {
//        return pos % dim;
//    }
//
//    const Card* getLeftCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r][c - 1];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//    const Card* getTopCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r - 1][c];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//public:
//    DraftSpace(int dim) : dim(dim) {
//        cards.resize(dim, std::vector<Card>(dim));
//    }
//
//    bool tryAdd(const Card& card, int pos) {
//        const Card* l = getLeftCard(pos);
//        const Card* t = getTopCard(pos);
//        int r = getRow(pos);
//        int c = getColumn(pos);
//
//        if (card.isCompatible(*l, *t)) {
//            cards[r][c] = card.clone();
//            return true;
//        }
//
//        return false;
//    }
//};
//
//int main() {
//    // Card 객체 생성
//    Card card1("Card1", Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE),
//        Side(Part::HEAD, PartColor::GREEN), Side(Part::TAIL, PartColor::YELLOW));
//    Card card2("Card2", Side(Part::HEAD, PartColor::YELLOW), Side(Part::TAIL, PartColor::GREEN),
//        Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE));
//
//    // DraftSpace 객체 생성
//    DraftSpace draftSpace(3);
//
//    // 카드 추가 시도
//    bool success = draftSpace.tryAdd(card1, 0);
//    if (success) {
//        std::cout << "Card1 added successfully!" << std::endl;
//    }
//    else {
//        std::cout << "Card1 cannot be added!" << std::endl;
//    }
//
//    success = draftSpace.tryAdd(card2, 1);
//    if (success) {
//        std::cout << "Card2 added successfully!" << std::endl;
//    }
//    else {
//        std::cout << "Card2 cannot be added!" << std::endl;
//    }
//
//    return 0;
//}
