#pragma once
#include "ExercisePlan.h"
class ExercisePlanNode
{
private:
	ExercisePlan* exerciseData;
public:
	ExercisePlanNode* pNext;
	ExercisePlanNode();
	ExercisePlanNode(ExercisePlan* newPlanPlus);
	~ExercisePlanNode();
	
	ExercisePlan* getExerciseData();
	void setExerciseData(ExercisePlan* newPlan);
	ExercisePlanNode* getNext();
	void setNext(ExercisePlanNode* upcoming);

	
};
ostream& operator<< (ostream& lhs, ExercisePlanNode& rhs);
istream& operator>> (istream& lhs, ExercisePlanNode& rhs);
ofstream& operator<< (ofstream& lhs, ExercisePlanNode& rhs);

