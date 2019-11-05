#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("tinyUF.txt", ifstream::in);

	if (inFile.is_open())
	{
		int p = 0, q = 0, n = 0;
		string line;
		cout << "File opened" << endl;

		getline(inFile, line);
		n = stoi(line);

		while (getline(inFile, line))
		{
			p = stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" "));
			q = stoi(line);
		}
		inFile.close();
	}
}
