# include <iostream>
# include <string>
using namespace std;

class Node {
public:
	int nomhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of student: ";
	cin >> nim;
	cout << "\nEnter the name of strundet: ";
	cin >> nm;
	Node* newNode = new Node();	//step 1
	newNode->nomhs = nim;		//step 2
	newNode->name = nm;			//step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->nomhs) {
		if (START != NULL && nim == START->nomhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;		//step 3
		if (START != NULL)		
			START->prev = newNode;	//step 4
		newNode->prev = NULL;		//step 5
		START = newNode;			//step 6
		return;
	}

	/*inserting a Node Between Two Nodes in List*/
	Node* current = START;	//step 1.a
	Node* previous = NULL;	//step 1.b
	while (current->next != NULL && current->next->nomhs < nim) //step 1.c
	{
		previous = current;			//1.d
		current = current->next;	//1.e
	}

	if (current->next != NULL && nim == current->next->nomhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = current->next;		//step 4
	newNode->prev = current;			//step 5
	if (current->next != NULL)
		current->next->prev = newNode;	//step 6
	current->next = newNode;			//step 7
}

bool DoubleLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = START;		//step 1.a
	*current = START;		//step 1.b
	while (*current != NULL && rollno != (*current)->nomhs) {	//step 1.c
		*previous = *current;			//step 1.d
		*current = (*current)->next;	//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollno) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollno, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;		//step 2
	if (previous != NULL)
		previous->next = current->next;		//step 3
	else
		START = current->next;

	delete current;		//step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty()){
		cout << "\nList is empty" << endl;
	}
	else {
		cout << "\Record in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\List is empty" << endl;
	}

	else {
		cout << "\nRecord in descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;

			while (currentNode != NULL) {
				cout << currentNode->nomhs << " " << currentNode->name << endl;
				currentNode = currentNode->prev;
			}
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be delete: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "record not found" << endl;
	else
		cout << "record with roll number" << rollNo << "delete" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "nList is Empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll Number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->nomhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}
