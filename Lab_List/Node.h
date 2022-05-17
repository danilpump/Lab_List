#include <cstdio>
#include <string>
using namespace std;

class Node {
	string val;
	int color = 7;
	class Node* prev;
	class Node* next;
	friend class List;
};