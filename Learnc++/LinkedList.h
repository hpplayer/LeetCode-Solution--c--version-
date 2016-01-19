#pragma once
struct Node {
	Node *next;
	int val;
};
Node* addNode(Node* node, int val);
void printList(const Node* node);
