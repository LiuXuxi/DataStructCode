#include"bitset.h"

Bitset::Bitset(int num):size(num),ones(0),zeros(num),reverse(false)
{
	set = new int[(num + 31) / 32]();
}

Bitset::~Bitset()
{
	delete[]set;
}

void Bitset::fix(int idx) {
	int index = idx / 32;
	int bite = idx % 32;
	if (!reverse) {
		if ((set[index]>>bite&1)==0) {
			set[index] |= (1 << bite);
			--zeros;
			++ones;
		}
	}
	else {
		if ((set[index] >> bite & 1) != 0) {
			set[index] ^= (1 << bite);
			--zeros;
			++ones;
		}
	}
}

void Bitset::unfix(int idx) {
	int index = idx / 32;
	int bite = idx % 32;
	if (!reverse) {
		if ((set[index] >> bite & 1) != 0) {
			set[index] ^= (1 << bite);
			++zeros;
			--ones;
		}
	}
	else {
		if ((set[index] >> bite & 1) == 0) {
			set[index] |= (1 << bite);
			++zeros;
			--ones;
		}
	}
}

void Bitset::flip() {
	reverse = !reverse;
	int temp = zeros;
	zeros = ones;
	ones = temp;
}

bool Bitset::all() {
	return ones == size;
}

bool Bitset::one() {
	return ones > 0;
}

int Bitset::count() {
	return ones;
}

std::string Bitset::toString()
{
	std::string str;
	for (int i = 0, k = 0; i < size; k++) {
		int num = set[k];
		for (int j = 0; j < 32 && i < size; j++, i++) {
			int status = (num >> j) & 1;
			status ^= reverse ? 1 : 0;
			str.push_back(status?'1':'0');
		}
	}
	return str;
}
