#include "stdafx.h"
#include <unordered_map>


using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;

		unordered_map<RandomListNode*, RandomListNode*> hs;

		RandomListNode* dummy = new RandomListNode(head->label);
		RandomListNode* curr = dummy;

		while (head != NULL) {
			if (head->next) {
				if (hs.find(head->next) == hs.end()) hs[head->next] = new RandomListNode(head->next->label);
				curr->next = hs[head->next];
			}

			if (head->random) {
				if (hs.find(head->random) == hs.end()) hs[head->random] = new RandomListNode(head->random->label);
				curr->random = hs[head->random];
			}

			head = head->next;
			curr = curr->next;
		}

		return dummy;
	}
};
