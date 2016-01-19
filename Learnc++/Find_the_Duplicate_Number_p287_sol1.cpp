// LearnC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

/*
#ifndef ORIG_H
#define ORIG_H
#include "LinkedList.h"
#include <iostream>
#endif
*/

using namespace std;

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);

	int slow = 0, fast = 0;
	
	do {
		slow = vec[slow];
		fast = vec[vec[fast]];
	} while (slow != fast);

	fast = 0;

	while (slow != fast) {
		fast = vec[fast];
		slow = vec[slow];
	}

	return slow;
}