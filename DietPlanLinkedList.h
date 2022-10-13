/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/#include "DietPlanNode.h"
class DietPlanLinkedList{
private:
	int size;
	DietPlanNode* pHead;
public:
	DietPlanLinkedList();
	~DietPlanLinkedList();
	DietPlanNode* getHead();
	void add(DietPlanNode*);
	void insert(DietPlanNode*);
	//void remove(ExercisePlanNode*); Maybe not needed until later
	int get_size();
};
std::ostream& operator<<(std::ostream& os, DietPlanLinkedList& obj);

