#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class singlyLinkdedList {
private:
	node* head;
	node* tail;
	int listSize;
public:
	singlyLinkdedList();
	bool empty();
	void append(int data);
	void insertion(int i, int data);
	void deletion(int i);
	void print();
	void AfterMin(int i);
	void Sum();
};

singlyLinkdedList::singlyLinkdedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}
bool singlyLinkdedList::empty() {
	return listSize == 0;
}
void singlyLinkdedList::append(int data) {
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	listSize++;
}
void singlyLinkdedList::insertion(int i, int data) {
	if (i < 0 || i > listSize)
		return;
	else if (i == listSize)
		append(data);
	else if (i == 0) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		listSize++;
	}
	else {
		node* newNode = new node;
		newNode->data = data;
		node* curNode = head;
		for (int j = 1; j < i; j++) {
			curNode = curNode->next;
		}
		newNode->next = curNode->next;
		curNode->next = newNode;
		listSize++;
	}
}
void singlyLinkdedList::deletion(int i) {
	if (empty() || i < 0 || i > listSize) {
		cout << "-1" << endl;
		return;
	}
	node* curNode = head;
	if (i == 0) {
		if (listSize == 1) {
			tail = head = NULL;
		}
		else {
			head = head->next;
		}
	}
	else {
		node* preNode = head;
		for (int k = 0; k < i; k++) {
			preNode = curNode;
			curNode = curNode->next;
		}
		preNode->next = curNode->next;
		if (curNode == tail) {
			tail = preNode;
		}
	}
	cout << curNode->data << endl;
	delete curNode;
	listSize--;
}
void singlyLinkdedList::print() {
	if (empty()) {
		cout << "empty";
	}
	node* curNode = head;
	while (curNode != NULL) {
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
	cout << endl;
}
void singlyLinkdedList::AfterMin(int i) {
	if (empty() || i >= listSize) {
		cout << "error" << endl;
		return;
	}
	int min = 10001;
	node* curNode = head;
	for (int j = 0; j < i; j++) {
		curNode = curNode->next;
	}
	for (int j = i; j < listSize; j++) {
		int data = curNode->data;
		if (data < min)
			min = data;
		curNode = curNode->next;
	}
	cout << min << endl;
}

void singlyLinkdedList::Sum() {
	int sum = 0;
	node* curNode = head;
	for (int i = 0; i < listSize; i++) {
		sum += curNode->data;
		curNode = curNode->next;
	}
	cout << sum << endl;
}

int main() {
	int M;
	cin >> M;
	singlyLinkdedList singlyLinkedlist;
	while (M--) {
		string input;
		cin >> input;
		if (input == "Print") {
			singlyLinkedlist.print();
		}
		else if (input == "Append") {
			int x;
			cin >> x;
			singlyLinkedlist.append(x);
			singlyLinkedlist.print();
		}
		else if (input == "Delete") {
			int index;
			cin >> index;
			singlyLinkedlist.deletion(index);
		}
		else if (input == "AfterMin") {
			int index;
			cin >> index;
			singlyLinkedlist.AfterMin(index);
		}		
		else if (input == "Sum") {
			singlyLinkedlist.Sum();
		}
	}
}