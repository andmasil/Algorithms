#pragma once
class QuickFindUF
{
public:

	QuickFindUF(int N);
	~QuickFindUF();

	void connect(int p, int q);
	bool isConnected(int p, int q);
	int count();

private:
	void printArray();

	int m_count;
	int* m_idArray;
};

