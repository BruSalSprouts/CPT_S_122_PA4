/*******************************************************************************************
* Programmer: Bruno Sánchez
* Class: CptS 122, Spring 2021;
* Programming Assignment: PA 4
* Date: March 2, 2022
* Description: Contains functions for PA 4
*******************************************************************************************/
#include "FitnessAppWrapper.h"
/*
* Name: Bruno Sanchez
* Function: FitnessAppWrapper()
* Date: 2/25/2022
* Inputs:
* Returns:
* Description: Constructor for FitnessAppWrapper()
* Preconditions: Files are alraedy open
* Postconditions:
*/
//Pre-condition: File is alrady open
FitnessAppWrapper::FitnessAppWrapper() {
	
}
/*
* Name: Bruno Sanchez
* Function: runApp()
* Date: 2/25/2022
* Inputs:
* Returns:
* Description: Runs the main program and calls functions of FitnessAppWrapper
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::runApp() {
	int choice = 0;
	do {
		clrscr();
		std::cout << "Choose from one of the following options" << std::endl;
		this->displayMenu();
		std::cin >> choice;
		if (choice < 0 || choice > 9) {
			std::cout << "ERROR: Invalid input, please choose from one of the options above" << std::endl;
			std::cin >> choice;
		}
		switch (choice) {
		case 1:
			dietInfile.open("dietPlans.txt");
			this->loadWeeklyPlan(dietInfile, dietPlans); 
			dietInfile.close();
			system("pause");
			break;
		case 2:
			exerciseInfile.open("exercisePlans.txt");
			this->loadWeeklyPlan(exerciseInfile, exercisePlans); 
			exerciseInfile.close();
			system("pause");

			break;
		case 3:
			dietOutfile.open("exercisePlansOut.txt");
			this->storeWeeklyPlan(dietOutfile, dietPlans);
			dietOutfile.close();
			system("pause");

			break;
		case 4:
			dietOutfile.open("dietPlansOut.txt");
			this->storeWeeklyPlan(exerciseOutfile, exercisePlans);
			dietOutfile.close();
			system("pause");

			break;
		case 5:
			this->displayWeeklyPlan(dietPlans);
			system("pause");

			break;
		case 6:
			this->displayWeeklyPlan(exercisePlans);
			system("pause");

			break;
		case 7:
			this->editDailyDietPlan(dietPlans);
			system("pause");

			break;
		case 8:
			this->editDailyDietPlan(exercisePlans);
			system("pause");

			break;
		case 9:
			dietOutfile.open("exercisePlansOut.txt");
			this->storeWeeklyPlan(dietOutfile, dietPlans);
			dietOutfile.close();
			dietOutfile.open("dietPlansOut.txt");
			this->storeWeeklyPlan(exerciseOutfile, exercisePlans);
			dietOutfile.close();
			std::cout << "Stored plans before closing \nGoodbye!" << std::endl;
			break;
		}
	} while (choice != 9);
}
/*
* Name: Bruno Sanchez
* Function:loadDailyPlan(ifstream& fileStream, DietPlan& plan)
* Date:2/25/2022
* Inputs: ifstream& fileStream, DietPlan& plan
* Returns:
* Description: Reads a singular plan from file)
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}
/*
* Name: Bruno Sanchez
 Function:loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
* Date:2/25/2022
* Inputs: ifstream& fileStream, ExercisePlan& plan
* Returns:
* Description: Reads a singular plan from file)
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}
/*
* Name: Bruno Sanchez
* Function: loadWeeklyPlan(ifstream& fileStream, DietPlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: ifstream& fileStream, DietPlanLinkedList& plan)
* Returns:
* Description: Loads a file's plans into a DietPlan Linked list
* Preconditions: fileStream is open
* Postconditions:
*/
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlanLinkedList& plan) {
	string line;
	do {
		if (!fileStream.eof()) {
			DietPlan* newPlan = new DietPlan();
			loadDailyPlan(fileStream, *newPlan);
			if (newPlan->isEmpty()) {
				delete(newPlan);
			}
			else {
				plan.add(new DietPlanNode(newPlan));
			}
		}
	} while (getline(fileStream, line));
}
/*
* Name: Bruno Sanchez
* Function: loadWeeklyPlan(ifstream& fileStream, ExercisePlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: ifstream& fileStream, ExercisePlanLinkedList& plan)
* Returns:
* Description: Loads a file's plans into a ExercisePlan Linked list
* Preconditions: fileStream is open
* Postconditions:
*/
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExercisePlanLinkedList& plan) {
	string line;
	do {
		if (!fileStream.eof()) {
			ExercisePlan* newPlan = new ExercisePlan();
			loadDailyPlan(fileStream, *newPlan);
			if (newPlan->isEmpty()) {
				delete(newPlan);
			}
			else {
				plan.add(new ExercisePlanNode(newPlan));
			}
		}
	} while (getline(fileStream, line));
}
/*
* Name: Bruno Sanchez
* Function:displayDailyPlan(ExercisePlan plan)
* Date:2/25/2022
* Inputs:ExercisePlan plan
* Returns:
* Description:Prints a singular ExcercisePlan to the screen
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::displayDailyPlan(ExercisePlan plan) {
	std::cout << plan << std::endl;
}
/*
* Name: Bruno Sanchez
* Function:displayDailyPlan(DietPlan plan)
* Date:2/25/2022
* Inputs:DietPlan plan
* Returns:
* Description:Prints a singular DietPlan to the screen
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::displayDailyPlan(DietPlan plan) {
	std::cout << plan << std::endl;
}
/*
* Name: Bruno Sanchez
* Function: displayWeeklyPlan(ExercisePlanLinkedList& plans)
* Date: 2/25/2022
* Inputs: ExercisePlanLinkedList& plans
* Returns:
* Description: Displays all information from an ExercisePlan Linked list onto the console
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlanLinkedList& plans) {
	if (plans.getHead() == nullptr) {
		std::cout << "ERROR: There are no plans to display" << std::endl;
		return;
	}
	ExercisePlanNode* pCur = plans.getHead();
	ExercisePlan temp;
	while (pCur != nullptr) {
		temp = *(pCur->getExerciseData());
		displayDailyPlan(temp);
		pCur = pCur->getNext();
	}
}
/*
* Name: Bruno Sanchez
* Function: displayWeeklyPlan(DietPlanLinkedList& plans)
* Date: 2/25/2022
* Inputs: DietPlanLinkedList& plans
* Returns:
* Description: Displays all information from an DietPlan Linked list onto the console
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::displayWeeklyPlan(DietPlanLinkedList& plans) {
	if (plans.getHead() == nullptr) {
		std::cout << "ERROR: There are no plans to display" << std::endl;
		return;
	}
	DietPlanNode* pCur = plans.getHead();
	DietPlan temp;
	while (pCur != nullptr) {
		temp = *(pCur->getDietData());
		displayDailyPlan(temp);
		pCur = pCur->getNext();
	}
	pCur = nullptr;
}
/*
* Name: Bruno Sanchez
* Function: storeDailyPlan(ofstream& fileStream, ExercisePlan plan)
* Date: 2/25/2022
* Inputs: ofstream& fileStream, ExercisePlan plan
* Returns:
* Description: Prints a singular ExercisePlan to the fileStream
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan plan) {
	fileStream << plan;
}
/*
* Name: Bruno Sanchez
* Function: storeDailyPlan(ofstream& fileStream, DietPlan plan)
* Date: 2/25/2022
* Inputs: ofstream& fileStream, DietPlan plan
* Returns:
* Description: Prints a singular DietPlan to the fileStream
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan plan) {
	fileStream << plan;
}
/*
* Name: Bruno Sanchez
* Function: storeWeeklyPlan(ofstream& fileStream, ExercisePlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: ofstream& fileStream, ExercisePlanLinkedList& plan
* Returns:
* Description: Prints all contents in ExercisePlan Linked list to fileStream
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, ExercisePlanLinkedList& plan) {
	ExercisePlanNode* pCur = plan.getHead();
	ExercisePlan temp;
	while (pCur != nullptr) {
		temp = *(pCur->getExerciseData());
		storeDailyPlan(fileStream, temp);
		fileStream << "" << std::endl;
		pCur = pCur->getNext();
	}
}
/*
* Name: Bruno Sanchez
* Function: storeWeeklyPlan(ofstream& fileStream, DietPlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: ofstream& fileStream, DietPlanLinkedList& plan
* Returns:
* Description: Prints all contents in DietPlan Linked list to fileStream
* Preconditions: fileStream must be open
* Postconditions:
*/
void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, DietPlanLinkedList& plan) {
	DietPlanNode* pCur = plan.getHead();
	DietPlan temp;
	while (pCur != nullptr) {
		temp = *(pCur->getDietData());
		storeDailyPlan(fileStream, temp);
		fileStream << "" << std::endl;
		pCur = pCur->getNext();
	}
}
/*
* Name: Bruno Sanchez
* Function: editDailyDietPlan(DietPlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: DietPlanLinkedList& plan
* Returns:
* Description: Edits a singular DietPlan in the LinkedList by listing out the names of all contents in the LinkedList
*				before prompting the user to select one of the Plans
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::editDailyDietPlan(DietPlanLinkedList& plan) {
	if (plan.getHead() == nullptr) {
		std::cout << "ERROR: There are no plans to display" << std::endl;
		return;
	}
	DietPlanNode* pCur = plan.getHead();
	std::cout << "Curent Plans" << std::endl;
	int n = 1, select = 1, choice = 0;
	while (pCur != nullptr) {
		std::cout << n << ")" << pCur->getDietData()->getName() << std::endl;
		n++;
		pCur = pCur->pNext;
	}
	std::cout << "Choose which plan you want to edit " << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > n) {
		std::cout << "ERROR: Invalid option selected, please choose from one of the following options listed above" << std::endl;
		std::cin >> choice;
	}
	pCur = plan.getHead();
	while (select != choice) {
		pCur = pCur->getNext();
		++select;
	}
	pCur->getDietData()->editPlan();
	pCur = nullptr;
	delete(pCur);}
/*
* Name: Bruno Sanchez
* Function: editDailyDietPlan(ExercisePlanLinkedList& plan)
* Date: 2/25/2022
* Inputs: ExercisePlanLinkedList& plan
* Returns:
* Description: Edits a singular ExercisePlan in the LinkedList by listing out the names of all contents in the LinkedList
*				before prompting the user to select one of the Plans
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::editDailyDietPlan(ExercisePlanLinkedList& plan) {
	if (plan.getHead() == nullptr) {
		std::cout << "ERROR: There are no plans to display" << std::endl;
		return;
	}
	ExercisePlanNode* pCur = plan.getHead();
	std::cout << "Curent Plans" << std::endl;
	int n = 1, select = 1, choice = 0;
	while (pCur != nullptr) {
		std::cout << n << ")" << pCur->getExerciseData()->getName() << std::endl;
		n++;
		pCur = pCur->pNext;
	}
	std::cout << "Choose which plan you want to edit " << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > n) {
		std::cout << "ERROR: Invalid option selected, please choose from one of the following options listed above" << std::endl;
		std::cin >> choice;
	}
	pCur = plan.getHead();
	while (select != choice) {
		pCur = pCur->getNext();
		++select;
	}
	pCur->getExerciseData()->editPlan();
}
/*
* Name: Bruno Sanchez
* Function: displayMenu()
* Date: 2/25/2022
* Inputs:
* Returns:
* Description: Prints out menu of options to screen
* Preconditions:
* Postconditions:
*/
void FitnessAppWrapper::displayMenu() {
	std::cout << "1) Load weekly diet plan from file" << std::endl;
	std::cout << "2) Load weekly exercise plan from file" << std::endl;
	std::cout << "3) Store weekly diet plan to file" << std::endl;
	std::cout << "4) Store weekly exercise plan to file" << std::endl;
	std::cout << "5) Display weekly diet plan to screen" << std::endl;
	std::cout << "6) Display weekly exercise plan to screen" << std::endl;
	std::cout << "7) Edit daily diet plan" << std::endl;
	std::cout << "8) Edit daily exercise plan" << std::endl;
	std::cout << "9) Exit" << std::endl;
}
/*
* Name: Bruno Sanchez
* Function: clrscr()
* Date: 2/25/2022
* Inputs:
* Returns:
* Description: Clears the screen
* Preconditions:
* Postconditions:
*/
void clrscr() {
	cout << "\033[2J\033[1;1H";
}