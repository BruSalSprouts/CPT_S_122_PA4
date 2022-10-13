/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/#include "Header.h"
#include "ExercisePlanLinkedList.h"
#include "DietPlanLinkedList.h"
class FitnessAppWrapper{
private:
	ExercisePlanLinkedList exercisePlans;
	DietPlanLinkedList dietPlans;
	ifstream exerciseInfile;
	ifstream dietInfile;
	ofstream exerciseOutfile;
	ofstream dietOutfile;
public:
	FitnessAppWrapper();
	void runApp();
	void loadDailyPlan(ifstream& fileStream, DietPlan& plan); 
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(ifstream& fileStream, DietPlanLinkedList& bigPlan);
	void loadWeeklyPlan(ifstream& fileStream, ExercisePlanLinkedList& bigPlan);
	void displayDailyPlan(ExercisePlan plan);
	void displayDailyPlan(DietPlan plan);
	void displayWeeklyPlan(ExercisePlanLinkedList& plans);
	void displayWeeklyPlan(DietPlanLinkedList& plans);
	void storeDailyPlan(ofstream& fileStream, ExercisePlan plan);
	void storeDailyPlan(ofstream& fileStream, DietPlan plan);
	void storeWeeklyPlan(ofstream& fileStream, ExercisePlanLinkedList& plan);
	void storeWeeklyPlan(ofstream& fileStream, DietPlanLinkedList& plan);
	void editDailyDietPlan(DietPlanLinkedList& plan);
	void editDailyDietPlan(ExercisePlanLinkedList& plan);
	void displayMenu();
};
void clrscr();
