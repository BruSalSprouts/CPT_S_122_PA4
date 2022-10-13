/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "ExercisePlanNode.h"
/*
* Name: Bruno Sanchez
* Function: ExercisePlanNode()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Constructor for ExercisePlanNode
* Preconditions:
* Postconditions:
*/
ExercisePlanNode::ExercisePlanNode() { 
	pNext = nullptr; 
}
/*
* Name: Bruno Sanchez
* Function: ExercisePlanNode(ExercisePlan* newPlanPlus)
* Date: 2/22/2022
* Inputs: ExercisePlan* newPlanPlus
* Returns:
* Description: Constructor for ExercisePlanNode
* Preconditions:
* Postconditions:
*/
ExercisePlanNode::ExercisePlanNode(ExercisePlan* newPlanPlus) { 
	exerciseData = newPlanPlus;
	pNext = nullptr;
}
/*
* Name: Bruno Sanchez
* Function: ~ExercisePlanNode()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Destructor for ExercisePlanNode
* Preconditions:
* Postconditions:
*/
ExercisePlanNode::~ExercisePlanNode() {
	if (exerciseData != nullptr) {
		delete(exerciseData);
	}
}
/*
* Name: Bruno Sanchez
* Function: getExerciseData()
* Date: 2/22/2022
* Inputs:
* Returns: exercisePlan* exerciseData
* Description: Returns exerciseData
* Preconditions:
* Postconditions:
*/
ExercisePlan* ExercisePlanNode::getExerciseData() {
	return exerciseData;
}
/*
* Name: Bruno Sanchez
* Function: setExerciseData(ExercisePlan* newPlan)
* Date: 2/22/2022
* Inputs: ExercisePlan* newPlan
* Returns:
* Description: Sets ExerciseData
* Preconditions:
* Postconditions:
*/
void ExercisePlanNode::setExerciseData(ExercisePlan* newPlan) {
	exerciseData = newPlan;
}
/*
* Name: Bruno Sanchez
* Function: getNext()
* Date: 2/22/2022
* Inputs: 
* Returns: returns ExercisePlanNode* pNext
* Description: Gets pNext
* Preconditions: 
* Postconditions:
*/
ExercisePlanNode* ExercisePlanNode::getNext() {
	return pNext;
}
/*
* Name: Bruno Sanchez
* Function: setNext(ExercisePlanNode* upcoming)
* Date: 2/22/2022
* Inputs: ExercisePlanNode* upcoming
* Returns:
* Description: sets pNext with ExercisePlanNode* upcoming
* Preconditions:
* Postconditions:
*/
void ExercisePlanNode::setNext(ExercisePlanNode* upcoming) {
	pNext = upcoming;
}

/*
* Name: Bruno Sanchez
* Function: operator<< (ostream& lhs, ExercisePlanNode& rhs)
* Date: 2/22/2022
* Inputs: ostream& lhs, ExercisePlanNode& rhs
* Returns: ostream& lhs
* Description: prints out exerciseData from the Node
* Preconditions: lhs must be open
* Postconditions:
*/
ostream& operator<< (ostream& lhs, ExercisePlanNode& rhs) {
	lhs << rhs.getExerciseData(); 
	return lhs;
}
/*
* Name: Bruno Sanchez
* Function: operator>> (istream& lhs, ExercisePlanNode& rhs)
* Date: 2/22/2022
* Inputs: istream& lhs, ExercisePlanNode& rhs
* Returns: istream& lhs
* Description: gets Data from rhs to load onto lhs
* Preconditions: lhs must be open
* Postconditions:
*/
istream& operator>> (istream& lhs, ExercisePlanNode& rhs) {
	lhs >> *rhs.getExerciseData();
	return lhs;
}
/*
* Name: Bruno Sanchez
* Function: operator<< (ofstream& lhs, ExercisePlanNode& rhs)
* Date: 2/22/2022
* Inputs: ofstream& lhs, ExercisePlanNode& rhs
* Returns: ofstream& lhs
* Description: Prints data from rhs to lhs
* Preconditions: lhs must be open
* Postconditions:
*/
ofstream& operator<< (ofstream& lhs, ExercisePlanNode& rhs) {
	lhs << rhs.getExerciseData();
	return lhs;
}