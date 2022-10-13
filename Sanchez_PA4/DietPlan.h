/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/#include "Header.h"

class DietPlan{
private:
	int calorieGoal; //Where maximum intake of calories is stored
	std::string name; //User's name
	std::string date; //Date for which plan is intended
public:
	DietPlan();
	DietPlan(int newGoal, std::string newName, std::string newDate);
	~DietPlan();
	//Getters
	int getGoal();
	std::string getName();
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
ostream& operator<< (ostream& lhs, DietPlan& rhs);
istream& operator>> (istream& lhs, DietPlan& rhs);
ofstream& operator<< (ofstream& lhs, DietPlan& rhs);
