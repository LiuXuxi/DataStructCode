#pragma once
#include<vector>
template<class T>
class QFSet {
private:
	T* data;
	int* groupID;
	int capacity;
	int n;
	int findIndex(T v) {
		for (int i = 0; i < n; i++) {
			if (data[i] == v)return i;
		}
		return -1;
	}
public:
	QFSet(int x) :capacity(x) {
		data = new int[capacity];
		groupID = new int[capacity];
		n = 0;
	}
	~QFSet(){
		n = 0, capacity = 0;
		delete(data);
		delete(groupID);
		
	}
	void initQFSet(std::vector<int>nums) {
		int len = nums.size();
		if (len > capacity)len = capacity;
		for (int i = 0; i < len; i++) {
			data[i] = nums[i];
			groupID[i] = i;
		}
		n = len;
	}
	int isSameQF(T a, T b) {
		int IndexA = findIndex(a), IndexB = findIndex(b);
		if (IndexA == -1 || IndexB == -1)return -1;
		int IDA = groupID[IndexA], IDB = groupID[IndexB];
		return IDA == IDB;
	}
	void UnionQF(T a, T b) {
		int IndexA = findIndex(a), IndexB = findIndex(b);
		if (IndexA == -1 || IndexB == -1)return;
		int IDA = groupID[IndexA], IDB = groupID[IndexB];
		if (IDA == IDB)return;
		for (int i = 0; i < n; i++) { if (groupID[i] == IDA)groupID[i] = IDB; }
	}
};