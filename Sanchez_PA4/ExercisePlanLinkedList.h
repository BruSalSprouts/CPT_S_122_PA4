/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "ExercisePlanNode.h" 
class ExercisePlanLinkedList{
private:
	int size;
	ExercisePlanNode* pHead;
public:
	ExercisePlanLinkedList();
	~ExercisePlanLinkedList();
	ExercisePlanNode* getHead();
	void add(ExercisePlanNode*);
	void insert(ExercisePlanNode*);
	//void remove(ExercisePlanNode*); Maybe not needed until later
	int get_size();		
};
std::ostream& operator<<(std::ostream& os, ExercisePlanLinkedList& obj);

 