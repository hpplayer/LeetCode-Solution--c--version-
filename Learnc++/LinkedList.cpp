
#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

Node* addNode(Node *node, int val) {
	Node *newNode = new Node;
	newNode->val = val;
	newNode->next = node;
	return newNode;
}

void printList(const Node* node) {
	const Node* curr = node;
	while (curr != NULL) {
		cout << curr->val << endl;
		curr = curr->next;
	}
}