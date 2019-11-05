#pragma once
class QuickUnion
{
public:
	QuickUnion(int N);
	~QuickUnion();

	void connect(int p, int q);
	bool isConnected(int p, int q);
	int count();

private:
	void printArray();
	int getRoot(int i);

	int m_count;
	int* m_idArray;
};

