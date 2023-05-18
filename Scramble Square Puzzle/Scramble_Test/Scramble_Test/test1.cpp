#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class Part {
	HEAD = 1,
	TAIL = -1
};

enum class PartIndex {
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4
};

class Side {
private:
	Part part;
	PartIndex index;
	
public:
	Side(Part part, PartIndex index) : part(part), index(index) {}

	int getValue() const {
		return static_cast<int>(part) * static_cast<int>(index);
	}

	bool canJoin(const Side& side) const {
		if (&side == nullptr)
			return true;
		return getValue() + side.getValue() == 0;
	}
};

int main() {

	return 0;
}