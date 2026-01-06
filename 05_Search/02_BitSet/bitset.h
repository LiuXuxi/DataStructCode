#pragma once
#include<string>

class Bitset
{
public:
	Bitset(int num);
	~Bitset();

    void fix(int idx);

    void unfix(int idx);

    void flip();

    bool all();

    bool one();

    int count();

	std::string toString();

private:
	int size;
	int zeros;
	int ones;
	bool reverse;
	int* set;
};

