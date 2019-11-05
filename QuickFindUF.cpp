#include "QuickFindUF.h"
#include <iostream>
#include <string>

using namespace std;

const bool PRINT = true;

QuickFindUF::QuickFindUF(int N)
{
	cout << "QuickFindUF " << N << endl << endl;
	m_count = N;
	m_idArray = new int[m_count];

	//fill array with uniqe ids
	for (int i = 0; i < m_count; ++i)
	{
		m_idArray[i] = i;
	}
}

QuickFindUF::~QuickFindUF()
{
	delete[] m_idArray;
}

void QuickFindUF::connect(int p, int q)
{
	cout << "QuickFind connect " << p << " - " << q << endl;

	if (!isConnected(p, q) && (p < m_count) && (q < m_count))
	{
		int pid = m_idArray[p];
		int qid = m_idArray[q];

		//change all entries whose ID is equal to the first ID to the second one
		for (int i = 0; i < m_count; ++i)
		{
			if (m_idArray[i] == pid)
			{
				m_idArray[i] = qid;
			}
		}
	}
	printArray();
}

bool QuickFindUF::isConnected(int p, int q)
{
	bool result = false;

	if ((p < m_count) && (q < m_count) && (m_idArray[p] == m_idArray[q]))
	{
		result = true;
	}

	cout << "QuickFind isConnected (" << p << " - " << q << ") = " << boolalpha << result << endl;
	return result;
}

int QuickFindUF::count()
{
	return m_count;
}

void QuickFindUF::printArray()
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

		cout << header << endl  << ids <<  endl << endl;
	}
}
