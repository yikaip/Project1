#include <iostream>
using namespace std;

class Node
{
public:
	Node * next;
	float data;
};

class LinkedList
{
public:
	int lenth;
	Node* head;

	LinkedList();
	~LinkedList();
	void add(float data);
	void insertToList(Node* current, float data);
	void printSummary();
};