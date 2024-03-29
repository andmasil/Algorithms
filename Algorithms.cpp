#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

#include "Union-Find/QuickFind.h"
#include "Union-Find/QuickUnion.h"
#include "Union-Find/WeightedQuickUnion.h"
#include "Data-Structures/Stack.h"

using namespace std;

void startUnionFind();
void startDataStructure();

int main()
{
	string command;

	while (command != "q")
	{
		cout << "1. Union Find\n2. Data Structure" << endl;
		getline(cin, command);

		try
		{
			switch (stoi(command))
			{
			case 1:
				startUnionFind();
				break;
			case 2:
				startDataStructure();
				break;
			default:
				break;
			}
		}
		catch (const std::exception & e) { cout << e.what() << endl; }
	}	
}

void startUnionFind()
{
	ifstream inFile("Union-Find/tinyUF.txt", ifstream::in);
	int p = 0, q = 0, n = 0;
	string line;

	if (inFile.is_open())
	{
		cout << "File opened" << endl;

		getline(inFile, line);
		n = stoi(line);
		QuickFind quickFindUF(n);
		QuickUnion quickUnionUF(n);
		WeightedQuickUnion weightedQuickUnion(n);

		while (getline(inFile, line))
		{
			p = stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" "));
			q = stoi(line);
			quickFindUF.connect(p, q);
			quickUnionUF.connect(p, q);
			weightedQuickUnion.connect(p, q);
		}
		inFile.close();

		line.clear();
		while (line != "q")
		{
			cout << "Command: ";
			getline(cin, line);
			try
			{
				p = stoi(line.substr(0, line.find(" ")));
				line.erase(0, line.find(" "));
				q = stoi(line);
				quickFindUF.isConnected(p, q);
				quickUnionUF.isConnected(p, q);
				weightedQuickUnion.isConnected(p, q);
			}
			catch (const std::exception & e) { cout << e.what() << endl; }
		}
	}
}

void startDataStructure()
{
	Stack stack;
	string word;
	ifstream inFile("Data-Structures/strings.txt", ifstream::in);

	if (inFile.is_open())
	{
		while (inFile >> word)
		{
			if (word == "-")
			{
				string s = stack.pop();
			}
			else
			{
				stack.push(word);
			}
		}
		cout << endl;
	}
	inFile.close();
}