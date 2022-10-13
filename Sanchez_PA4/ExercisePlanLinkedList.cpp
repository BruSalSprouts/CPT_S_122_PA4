/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "ExercisePlanLinkedList.h"
/*
* Name: Bruno Sanchez
* Function:
* Date:
* Inputs:
* Returns:
* Description:
* Preconditions:
* Postconditions:
*/
/*
* Name: Bruno Sanchez
* Function:ExercisePlanLinkedList()
* Date: 2/20/2022
* Inputs:
* Returns:
* Description: Default Constructor for ExercisePlanLinkedList
* Preconditions:
* Postconditions:
*/
ExercisePlanLinkedList::ExercisePlanLinkedList() {
	size = 0;
	pHead = nullptr;
}
/*
* Name: Bruno Sanchez
* Function:~ExercisePlanLinkedList()
* Date: 2/20/2022
* Inputs:
* Returns:
* Description: Default Destructor for ExercisePlanLinkedList
* Preconditions:
* Postconditions:
*/
ExercisePlanLinkedList::~ExercisePlanLinkedList() {
	ExercisePlanNode* next;
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
* Returns: ExercisePlanNode* pHead
* Description: Gets pHead of Linked List
* Preconditions: 
* Postconditions:
*/
ExercisePlanNode* ExercisePlanLinkedList::getHead() {
	return pHead;
}

/*
* Name: Bruno Sanchez
* Function: add(ExercisePlanNode* node)
* Date: 2/20/2022
* Inputs:ExercisePlanNode* node
* Returns:
* Description: Adds an ExercisePlanNode to the Linked List
* Preconditions:
* Postconditions: ExcercisePlanLinkedList has a new Node in it
*/
void ExercisePlanLinkedList::add(ExercisePlanNode* node) {
	if (node == nullptr) {
		return;
	}
	size++;
	if (pHead == nullptr) {
		pHead = node;
		return;
	}
	ExercisePlanNode* curr = pHead;
	while (curr->getNext() != nullptr) {
		curr = curr->getNext();
	}
	curr->setNext(node);
}
/*
* Name: Bruno Sanchez
* Function: insert(ExercisePlanNode* node)
* Date:2/20/2022
* Inputs: ExercisePlanNode* node
* Returns:
* Description: Inserts a node into the Linked List
* Preconditions:
* Postconditions:
*/
void ExercisePlanLinkedList::insert(ExercisePlanNode* node) {
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
int ExercisePlanLinkedList::get_size() {
	return size;
}

/*
* Name: Bruno Sanchez
* Function: operator<<(std::ostream& os, ExercisePlanLinkedList& obj)
* Date:2/22/2022
* Inputs: std::ostream& os, ExercisePlanLinkedList& obj
* Returns: ostream& os
* Description: Overloads << operator to print out a Linked List
* Preconditions: ExercisePlanLinkedList must have objects in it already
* Postconditions:
*/
std::ostream& operator<<(std::ostream& os, ExercisePlanLinkedList& obj) {
	ExercisePlanNode* curr = obj.getHead();
	while (curr != nullptr) {
		os << *curr->getExerciseData();
		curr = curr->getNext();
	}
	return os;
}