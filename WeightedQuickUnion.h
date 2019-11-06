#pragma once
#include "UnionFindBase.h"

class WeightedQuickUnion : public UnionFindBase
{
	WeightedQuickUnion(int N);

	void connect(int p, int q);
	bool isConnected(int p, int q);

private:
	int getRoot(int i);
};

