#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

#include "QuickFindUF.h"
#include "QuickUnion.h"

using namespace std;

int main()
{
	ifstream inFile("tinyUF.txt", ifstream::in);
	int p = 0, q = 0, n = 0;
	string line;

	if (inFile.is_open())
	{
		cout << "File opened" << endl;

		getline(inFile, line);
		n = stoi(line);
		QuickFindUF quickFindUF(n);
		QuickUnion quickUnionUF(n);

		while (getline(inFile, line))
		{
			p = stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" "));
			q = stoi(line);
			quickFindUF.connect(p, q);
			quickUnionUF.connect(p, q);
		}
		inFile.close();

		line.clear();
		while (line != "q")
		{
			getline(cin, line);
			try 
			{
				p = stoi(line.substr(0, line.find(" ")));
				line.erase(0, line.find(" "));
				q = stoi(line);
				quickFindUF.isConnected(p, q);
				quickUnionUF.isConnected(p, q);
			}
			catch (const std::exception & e) { cout << e.what() << endl; }
		}
	}
}