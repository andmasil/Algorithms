#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() :
	m_size(0),
	m_first(NULL) {}

void Stack::push(std::string item)
{
	cout << "PUSH -> " << item << endl;
	Node *newNode = new Node();
	newNode->data = item;
	newNode->next = m_first;
	m_first = newNode;
	m_size++;
	print();
}

std::string Stack::pop()
{
	string ret;
	if (m_first != NULL)
	{
		cout << "POP <- " << m_first->data << endl;
		Node* tmp = m_first;
		ret = m_first->data;
		m_first = m_first->next;
		delete tmp;
		print();
	}
	m_size--;
	return ret;
}

bool Stack::isEmpty()
{
	return (m_size == 0);
}

int Stack::size()
{
	return m_size;
}

void Stack::print()
{
	cout << "STACK: ";
	Node* tmp = m_first;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

/* EXAMPLE
to be or not to - be - - that - - - is
*/