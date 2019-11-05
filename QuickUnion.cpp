#include "QuickUnion.h"
#include <iostream>
#include <string>

using namespace std;

const bool PRINT = true;

QuickUnion::QuickUnion(int N)
{
	cout << "QuickUnion " << N << endl << endl;
	m_count = N;
	m_idArray = new int[m_count];

	//fill array parent reference
	for (int i = 0; i < m_count; ++i)
	{
		m_idArray[i] = i;
	}
}

QuickUnion::~QuickUnion()
{
	delete[] m_idArray;
}

void QuickUnion::connect(int p, int q)
{
	cout << "QuickUnion connect " << p << " - " << q << endl;

	if (!isConnected(p, q))
	{
		int pRoot = getRoot(p);
		int qRoot = getRoot(q);

		if ((p < m_count) && (q < m_count))
		{
			m_idArray[pRoot] = m_idArray[qRoot];
		}
		printArray();
	}
}

bool QuickUnion::isConnected(int p, int q)
{
	bool result = false;

	if ((p < m_count) && (q < m_count) && (getRoot(p) == getRoot(q)))
	{
		result = true;
	}

	cout << "QuickUnion isConnected (" << p << " - " << q << ") = " << boolalpha << result << endl;
	return result;
}

int QuickUnion::count()
{
	return m_count;
}

void QuickUnion::printArray()
{
	if (PRINT)
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

int QuickUnion::getRoot(int i)
{
	while (m_idArray[i] != i)
	{
		i = m_idArray[i];
	}

	return i;
}

/* EXAMPLE
10
4 3
3 8
6 5
9 4
2 1
5 0
7 2
6 1
7 3

ID - 1 8 1 8 3 0 5 1 8 8
*/