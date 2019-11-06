#include "UnionFindBase.h"
#include <iostream>
#include <string>

using namespace std;

UnionFindBase::UnionFindBase(int N)
{
	m_count = N;
	m_idArray = new int[m_count];
	for (int i = 0; i < m_count; ++i)
	{
		m_idArray[i] = i;
	}
}

UnionFindBase::~UnionFindBase()
{
	delete[] m_idArray;
}

int UnionFindBase::count()
{
	return m_count;
}

void UnionFindBase::printArray(bool visible)
{
	if (visible)
	{
		string header = "", ids = "";

		header.append("Header |");
		ids.append("ID     |");
		for (int i = 0; i < m_count; ++i)
		{
			header.append(to_string(i) + "|");
			ids.append(to_string(m_idArray[i]) + "|");
		}

		cout << header << endl << ids << endl << endl;
	}
}

