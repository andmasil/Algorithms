#pragma once
#include <string>

class Stack
{
public:
	Stack();

	void push(std::string item);
	std::string pop();
	bool isEmpty();
	int size();
	void print();

private:
	class Node
	{
	public:
		std::string data;
		Node* next;
	};

	int m_size;
	Node* m_first;
};

