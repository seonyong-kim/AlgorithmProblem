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
	void print();
	int size();
	int getData(int index);
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
void singlyLinkdedList::insertion(int data, int newData) {
	node* curNode = head;
	int index = 0;
	for (int i = 0; i < size(); i++) {
		if (curNode->data == data) {
			index = i;
			break;
		}
		curNode = curNode->next;
	}
	if (index == listSize)
		append(newData);
	else if (index == 0) {
		node* newNode = new node;
		newNode->data = newData;
		newNode->next = head;
		head = newNode;
		listSize++;
	}
	else {
		node* newNode = new node;
		newNode->data = newData;
		node* curNode = head;
		for (int j = 1; j < index; j++) {
			curNode = curNode->next;
		}
		newNode->next = curNode->next;
		curNode->next = newNode;
		listSize++;
	}
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
int singlyLinkdedList::getData(int index) {
	node* curNode = head;
	for (int i = 0; i < index; i++) {
		curNode = curNode->next;
	}
	return curNode->data;
}
int singlyLinkdedList::size() {
	return listSize;
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		singlyLinkdedList singlyLinkedlist1, singlyLinkedlist2;
		int num1;
		cin >> num1;
		while (num1--) {
			int data;
			cin >> data;
			singlyLinkedlist1.append(data);
		}
		cin >> num1;
		while (num1--) {
			int data;
			cin >> data;
			singlyLinkedlist2.append(data);
		}
		for (int i = 0; i < singlyLinkedlist2.size(); i++) {
			singlyLinkedlist1.append(singlyLinkedlist2.getData(i));
		}
		singlyLinkedlist1.print();
		int e, v;
		cin >> e >> v;
		singlyLinkedlist1.insertion(e, v);
		singlyLinkedlist1.print();
	}
}