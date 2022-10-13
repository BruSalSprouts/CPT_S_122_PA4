/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "DietPlan.h"
class DietPlanNode
{
private:
	DietPlan* dietData;
public:
	DietPlanNode* pNext;
	DietPlanNode(); 
	//DietPlanNode(DietPlan* newPlan);
	DietPlanNode(DietPlan* p) : dietData(p), pNext(nullptr) {};
	~DietPlanNode();

	DietPlan* getDietData();
	void setData(DietPlan* newPlan);
	DietPlanNode* getNext();
	void setNext(DietPlanNode* upcoming);


};
ostream& operator<< (ostream& lhs, DietPlanNode& rhs);
istream& operator>> (istream& lhs, DietPlanNode& rhs);
ofstream& operator<< (ofstream& lhs, DietPlanNode& rhs);
