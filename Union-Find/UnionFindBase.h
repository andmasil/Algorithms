#pragma once
class UnionFindBase
{
public:
	UnionFindBase(int N);
	~UnionFindBase();

protected:
	int count();
	void printArray(int* array, int size, bool visible = true);
	int m_count;
	int* m_idArray;
};

