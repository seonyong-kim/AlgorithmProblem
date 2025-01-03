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
	~singlyLinkdedList();
	bool empty();
	void append(int data);
	void insertion(int i, int data);
	void deletion(int i);
	int getSize();
	int getData(int index);
	void print();
	void findData(int findData);
};

singlyLinkdedList::singlyLinkdedList() {
	head = NULL;
	tail = NULL;
	listSize = 0;
}

singlyLinkdedList::~singlyLinkdedList() {
	while (!empty()) {
		deletion(head->data); // 메모리 누수 방지를 위해 모든 노드 삭제
	}

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
void singlyLinkdedList::deletion(int deleteData) {
	node* curNode = head;
	node* preNode = head;
	while (curNode != NULL) {
		if (curNode->data == deleteData) {
			break;
		}
		preNode = curNode;
		curNode = curNode->next;
	}
	if (curNode == head) {
		head = head->next;
	}
	else {
		preNode->next = curNode->next;
		if (curNode == tail) {
			tail = preNode;
		}
	}
	delete curNode;
	listSize--;
}
int singlyLinkdedList::getSize() {
	return listSize;
}
int singlyLinkdedList::getData(int index) {
	node* curNode = head;
	for (int i = 0; i < index; i++) {
		curNode = curNode->next;
	}
	return curNode->data;
}
void singlyLinkdedList::print() {
	node* curNode = head;
	while (curNode != NULL) {
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
	cout << endl;
}
void singlyLinkdedList::findData(int findData) {
	node* curNode = head;
	for (int i = 0; i < getSize(); i++) {
		if (curNode->data == findData) {
			cout << i << endl;
			return;
		}
		curNode = curNode->next;
	}
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		singlyLinkdedList singlyLinkedList1, singlyLinkedList2;
		int num;
		cin >> num;
		while (num--) {
			int data;
			cin >> data;
			singlyLinkedList1.append(data);
		}
		cin >> num;
		while (num--) {
			int data;
			cin >> data;
			singlyLinkedList2.append(data);
		}
		for (int i = 0; i < singlyLinkedList2.getSize(); i++) {
			singlyLinkedList1.append(singlyLinkedList2.getData(i));
		}
		singlyLinkedList1.print();
		int deleteData;
		cin >> deleteData;
		singlyLinkedList1.deletion(deleteData);
		singlyLinkedList1.print();
		int findData;
		cin >> findData;
		singlyLinkedList1.findData(findData);
	}
}