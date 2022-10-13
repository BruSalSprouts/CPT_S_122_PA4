/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "DietPlan.h"
/*
* Name: Bruno Sanchez
* Function: DietPlan()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Constructor for DietPlan
* Preconditions:
* Postconditions:
*/
DietPlan::DietPlan() {
	calorieGoal = 0;
	name = "\0";
	date = "\0";
}
/*
* Name: Bruno Sanchez
* Function: DietPlan(int newGoal, std::string newName, std::string newDate)
* Date: 2/22/2022
* Inputs: int newGoal, std::string newName, std::string newDate
* Returns:
* Description: Copy constructor for DietPlan
* Preconditions:
* Postconditions:
*/
DietPlan::DietPlan(int newGoal, std::string newName, std::string newDate) {
	calorieGoal = newGoal;
	name = newName;
	date = newDate;
}
/*
* Name: Bruno Sanchez
* Function: ~DietPlan()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Destructor for DietPlan
* Preconditions:
* Postconditions:
*/
DietPlan::~DietPlan(){
	
}
/*
* Name: Bruno Sanchez
* Function: getGoal()
* Date: 2/22/2022
* Inputs:
* Returns: int stepGoal
* Description: Gets int stepGoal
* Preconditions:
* Postconditions:
*/
int DietPlan::getGoal() {
	return calorieGoal;
}
/*
* Name: Bruno Sanchez
* Function: getName()
* Date: 2/22/2022
* Inputs:
* Returns: string name
* Description: Gets string name
* Preconditions:
* Postconditions:
*/
std::string DietPlan::getName() {
	return name;
}
/*
* Name: Bruno Sanchez
* Function: getData()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: string data
* Preconditions:
* Postconditions:
*/
std::string DietPlan::getDate() {
	return date;
}
/*
* Name: Bruno Sanchez
* Function: setGoal(int newGoal)
* Date: 2/22/2022
* Inputs: int newGoal
* Returns:
* Description: sets stepGoal with new int newGoal
* Preconditions:
* Postconditions:
*/
void DietPlan::setGoal(int newGoal) {
	calorieGoal = newGoal;
}
/*
* Name: Bruno Sanchez
* Function: setName(std::string newName)
* Date: 2/22/2022
* Inputs: std::string newName
* Returns:
* Description: sets name with string newName
* Preconditions:
* Postconditions:
*/
void DietPlan::setName(std::string newName) {
	name = newName;
}
/*
* Name: Bruno Sanchez
* Function: setDate(std::string newDate)
* Date: 2/22/2022
* Inputs: std::string newDate
* Returns:
* Description: sets date with string newDate
* Preconditions:
* Postconditions:
*/
void DietPlan::setDate(std::string newDate) {
	date = newDate;
}
/*
* Name: Bruno Sanchez
* Function: isEmpty()
* Date: 2/22/2022
* Inputs:
* Returns: boolean true or false
* Description: returns true if none of the stuff in the dietPlan is empty, false if otherwise
* Preconditions:
* Postconditions:
*/
bool DietPlan::isEmpty() {
	return (name.empty() && date.empty() && calorieGoal == 0);
}
/*
* Name: Bruno Sanchez
* Function: editGoal()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Prompts user to get an int that will replace the step count
* Preconditions:
* Postconditions:
*/
void DietPlan::editGoal() {
	int temp = 0;
	std::cout << "What do you want your new calorie maximum to be?" << std::endl;
	std::cin >> temp;
	setGoal(temp);
}
/*
* Name: Bruno Sanchez
* Function: editName()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Prompts user to get a string that will replace the step count
* Preconditions:
* Postconditions:
*/
void DietPlan::editName() {
	string line;
	std::cout << "What do you want to change the name of this plan to?" << std::endl;
	std::cin >> line;
	setName(line); 
}
/*
* Name: Bruno Sanchez
* Function: editDate()
* Date: 2/22/2022
* Inputs:
* Returns:
* Description: Prompts users for ints that will be concatenated together into a string format of M/D/Y
* Preconditions:
* Postconditions:
*/
void DietPlan::editDate() {
	string date = "";
	int tempTime;
	//Insert new month
	std::cout << "The date format is as follows: Month/Date/Year \nWhat is the new month?" << std::endl;
	std::cin >> tempTime;
	if (tempTime < 1 || tempTime > 12) {
		std::cout << "ERROR: Invalid month number, please type in a different month" << std::endl;
		std::cin >> tempTime;
	}
	date = date + "/" + std::to_string(tempTime);
	//Insert new Day
	std::cout << "What is the new day?" << std::endl;
	std::cin >> tempTime;
	if (tempTime < 1 || tempTime > 31) {
		std::cout << "ERROR: Invalid day in a month, please type in a different day" << std::endl;
		std::cin >> tempTime;
	}
	date = date + "/" + std::to_string(tempTime);
	//Insert new year
	std::cout << "What is the new year?" << std::endl;
	std::cin >> tempTime;
	date = date + "/" + std::to_string(tempTime);
	setDate(date);
}
/*
* Name: Bruno Sanchez
* Function: editPlan()
* Date: 2/20/2022
* Inputs:
* Returns:
* Description: Prompts user to edit one part of an ExercisePlan
* Preconditions:
* Postconditions:
*/
void DietPlan::editPlan() {
	int choice = 0;
	 do{
		std::cout << "What parts of the plan do you want to change?\n1) The Name \n2) The Goal \n3) The Date \n 4) Exit" << std::endl;
		std::cin >> choice;
		while (choice < 1 || choice > 4) {
			std::cout << "ERROR: This input is invalid, choose from one of the options above" << std::endl;
		}
		switch (choice) {
		case 1:
			editName();
			break;
		case 2:
			editGoal();
			break;
		case 3:
			editDate();
			break;
		case 4:
			break;
		}
	} while (choice != 4);
}
/*
* Name: Bruno Sanchez
* Function: operator<< (ostream& lhs, DietPlan& rhs)
* Date: 2/22/2022
* Inputs: ostream& lhs, DietPlan& rhs
* Returns: ostream& lhs
* Description: Prints out DietePlan to console screen
* Preconditions: lhs must be open beforehand
* Postconditions:
*/
ostream& operator<< (ostream& lhs, DietPlan& rhs) {
	lhs << "The current calorie max is: " << rhs.getGoal() << "\nThe user's name is: " << rhs.getName() << "\nThe goal date is: " << rhs.getDate();
	return lhs;
}
/*
* Name: Bruno Sanchez
* Function: operator>> (istream& lhs, DietPlan &p1)
* Date: 2/22/2022
* Inputs: istream& lhs, DietPlan &p1
* Returns: istream& lhs
* Description: Loads data from istream onto DietPlan
* Preconditions: lhs must be open beforehand
* Postconditions:
*/
istream& operator>> (istream& lhs, DietPlan& p1) {

	string line = "\0";
	getline(lhs, line);
	if (line > "" || line < "") {
		p1.setName(line);
		if (getline(lhs, line)) {
			p1.setGoal(stoi(line));
			if (getline(lhs, line)) {
				p1.setDate(line);
			}
		}
	}
	else {
		if (getline(lhs, line)) {
				p1.setName(line);
				if (getline(lhs, line)) {
					p1.setGoal(stoi(line));
					if (getline(lhs, line)) {
						p1.setDate(line);
					}
				}
			}
	}
	
	return lhs;
}
/*
* Name: Bruno Sanchez
* Function: operator<< (ofstream& lhs, DietPlan& rhs)
* Date: 2/22/2022
* Inputs: ofstream& lhs, DietPlan& rhs
* Returns: ofstream& lhs
* Description: Prints out DietPlan to file ofstream
* Preconditions: lhs must be open beforehand
* Postconditions:
*/
ofstream& operator<< (ofstream& lhs, DietPlan& rhs) {
	lhs << rhs.getName() << std::endl;
	lhs << rhs.getGoal() << std::endl;
	lhs << rhs.getDate() << std::endl;
	return lhs;
}