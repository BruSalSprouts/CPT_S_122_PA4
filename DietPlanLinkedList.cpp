/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "DietPlanLinkedList.h"
/*
* Name: Bruno Sanchez
* Function:DietPlanLinkedList()
* Date: 2/20/2022
* Inputs:
* Returns:
* Description: Default Constructor for DietPlanLinkedList
* Preconditions:
* Postconditions:
*/
DietPlanLinkedList::DietPlanLinkedList() {
	size = 0;
	pHead = nullptr;
}
/*
* Name: Bruno Sanchez
* Function:~DietPlanLinkedList()
* Date: 2/20/2022
* Inputs:
* Returns:
* Description: Default Destructor for DietPlanLinkedList
* Preconditions:
* Postconditions:
*/
DietPlanLinkedList::~DietPlanLinkedList() {
	DietPlanNode* next;
	while (pHead != nullptr) {
		next = pHead->getNext();
		delete(pHead);
		pHead = next;
	}
}
/*
* Name: Bruno Sanchez
* Function:getHead()
* Date: 2/20/2022
* Inputs:
* Returns: DietPlanNode* pHead
* Description: Gets pHead of Linked List
* Preconditions:
* Postconditions:
*/
DietPlanNode* DietPlanLinkedList::getHead() {
	return pHead;
}
/*
* Name: Bruno Sanchez
* Function: add(DietPlanNode* node)
* Date: 2/20/2022
* Inputs:DietPlanNode* node
* Returns:
* Description: Adds an DietPlanNode to the Linked List
* Preconditions:
* Postconditions: DietPlanLinkedList has a new Node in it
*/
void DietPlanLinkedList::add(DietPlanNode* node) {
	if (node == nullptr) {
		return;
	}
	size++;
	if (pHead == nullptr) {
		pHead = node;
		return;
	}
	DietPlanNode* curr = pHead;
	while (curr->getNext() != nullptr) {
		curr = curr->getNext();
	}
	curr->setNext(node);
}
/*
* Name: Bruno Sanchez
* Function: insert(DietPlanNode* node)
* Date:2/20/2022
* Inputs: DietPlanNode* node
* Returns:
* Description: Inserts a node into the Linked List
* Preconditions:
* Postconditions:
*/
void DietPlanLinkedList::insert(DietPlanNode* node) {
	if (node == nullptr) {
		return;
	}
	size++;
	node->setNext(pHead);
	pHead = node;
}
/*
* Name: Bruno Sanchez
* Function: get_size()
* Date:2/20/2022
* Inputs:
* Returns: int size
* Description: Gets size of the list
* Preconditions:
* Postconditions:
*/
int DietPlanLinkedList::get_size() {
	return size;
}

/*
* Name: Bruno Sanchez
* Function: operator<<(std::ostream& os, DietPlanLinkedList& obj)
* Date:2/22/2022
* Inputs: std::ostream& os, DietPlanLinkedList& obj
* Returns: ostream& os
* Description: Overloads << operator to print out a Linked List
* Preconditions: DietPlanLinkedList must have objects in it already
* Postconditions:
*/
std::ostream& operator<<(std::ostream& os, DietPlanLinkedList& obj) {
	DietPlanNode* curr = obj.getHead();
	while (curr != nullptr) {
		os << *curr->getDietData();
		curr = curr->getNext();
	}
	return os;
}