/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/#include "Header.h"

class ExercisePlan{
private:
	int stepGoal; //Goal for steps taken
	std::string name; //User's name
	std::string date; //Number of desired steps for a day
public:
	ExercisePlan();
	ExercisePlan(int newGoal, std::string newName, std::string newDate);
	//~ExercisePlan();
	//Getters
	int getGoal();
	std::string getName();// { return name; }
	std::string getDate();
	//Setters
	void setGoal(int newGoal);
	void setName(std::string newName);
	void setDate(std::string newDate);

	bool isEmpty();
	void editGoal();
	void editName();
	void editDate();
	void editPlan();
};
ostream& operator<< (ostream& lhs, ExercisePlan& rhs);
istream& operator>> (istream& lhs, ExercisePlan& rhs);
ofstream& operator<< (ofstream& lhs, ExercisePlan& rhs);
