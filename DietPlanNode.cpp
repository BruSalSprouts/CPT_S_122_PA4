/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "DietPlanNode.h"
/*
* Name: Bruno Sanchez
* Function: DietPlanNode()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Constructor for DietPlanNode
* Preconditions:
* Postconditions:
*/
DietPlanNode::DietPlanNode() {
	pNext = nullptr;
}
/*
* Name: Bruno Sanchez
* Function: DietPlanNode(DietPlan* newPlanPlus)
* Date: 2/22/2022
* Inputs: DietPlan* newPlanPlus
* Returns:
* Description: Constructor for DietPlanNode
* Preconditions:
* Postconditions:
*/
DietPlanNode::~DietPlanNode() {
	if (dietData != nullptr) {
		delete(dietData);
	}
}
/*
* Name: Bruno Sanchez
* Function: getDietData()
* Date: 2/22/2022
* Inputs:
* Returns: dietPlan* dietData
* Description: Returns dietData
* Preconditions:
* Postconditions:
*/
DietPlan* DietPlanNode::getDietData() {
	return dietData;
}
/*
* Name: Bruno Sanchez
* Function: setData(DietPlan* newPlan)
* Date: 2/22/2022
* Inputs: DietPlan* newPlan
* Returns:
* Description: Sets DietData
* Preconditions:
* Postconditions:
*/
void DietPlanNode::setData(DietPlan* newPlan) {
	dietData = newPlan;
}
/*
* Name: Bruno Sanchez
* Function: getNext()
* Date: 2/22/2022
* Inputs:
* Returns: returns DietPlanNode* pNext
* Description: Gets pNext
* Preconditions:
* Postconditions:
*/
DietPlanNode* DietPlanNode::getNext() {
	return pNext;
}
/*
* Name: Bruno Sanchez
* Function: setNext(DietPlanNode* upcoming)
* Date: 2/22/2022
* Inputs: DietPlanNode* upcoming
* Returns:
* Description: sets pNext with DietPlanNode* upcoming
* Preconditions:
* Postconditions:
*/
void DietPlanNode::setNext(DietPlanNode* upcoming) {
	pNext = upcoming;
}

/*
* Name: Bruno Sanchez
* Function: operator<< (ostream& lhs, DietPlanNode& rhs)
* Date: 2/22/2022
* Inputs: ostream& lhs, DietPlanNode& rhs
* Returns: ostream& lhs
* Description: prints out DietData from the Node
* Preconditions: lhs must be open
* Postconditions:
*/
ostream& operator<< (ostream& lhs, DietPlanNode& rhs) {
	lhs << rhs.getDietData();
	return lhs;
}
/*
* Name: Bruno Sanchez
* Function: operator>> (istream& lhs, DietPlanNode& rhs)
* Date: 2/22/2022
* Inputs: istream& lhs, DietPlanNode& rhs
* Returns: istream& lhs
* Description: gets Data from rhs to load onto lhs
* Preconditions: lhs must be open
* Postconditions:
*/
istream& operator>> (istream& lhs, DietPlanNode& rhs) {
	lhs >> *rhs.getDietData(); 
	return lhs;
}

/*
* Name: Bruno Sanchez
* Function: operator<< (ofstream& lhs, DietPlanNode& rhs)
* Date: 2/22/2022
* Inputs: ofstream& lhs, DietPlanNode& rhs
* Returns: ofstream& lhs
* Description: Prints data from rhs to lhs
* Preconditions: lhs must be open
* Postconditions:
*/
ofstream& operator<< (ofstream& lhs, DietPlanNode& rhs) {
	lhs << rhs.getDietData();
	return lhs;
}