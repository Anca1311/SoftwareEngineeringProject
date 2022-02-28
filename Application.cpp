#include "Application.h"

void Application::selectOption() {
	int option;
	cout << "Please select an option: ";
	cin >> option;
	this->selectedOption = option;
	cout << "Option selected: " << option << endl;
}

void Application::Menu() {
	do {
		switch (flag) {
		case -1:
			cout << "Starting menu: \n";
			cout << "0. Exit \n";
			cout << "1. Configuration \n";
			cout << "2. Operational \n";
			selectOption();
			if (selectedOption == 0) {
				cout << "Exiting... \n";
				flag = 0;
			}
			else if (selectedOption == 1) flag = 1;
			else flag = 2;
		case 1:
			cout << "Configuration: \n";
			cout << "0. Back \n";
			cout << "1. View family members \n";
			cout << "2. Add family members \n";
			cout << "3. Remove family member \n";
			cout << "4. Monthly spending limit \n";
			selectOption();
			if (selectedOption == 0) flag = -1;
			else {
				if (selectedOption == 1) flag = 11;
				if (selectedOption == 2) flag = 12;
				if (selectedOption == 3) flag = 13;
				if (selectedOption == 4) flag = 14;
			}
		case 2:
			cout << "Operationl: \n";
			cout << "0. Back \n";
			cout << "1. Select the family member \n";
			selectOption();
			if (selectedOption == 0) flag = -1;
			else {
				if (selectedOption == 1) {
					flag = 21;
					displayMembers();
				}
				selectOption();// Choosing the family member - ?
				if (selectedOption == 0) flag = -1;
				else {
					OpenTableFor(selectedOption);
				}
				cout << "0. Back \n";
				cout << "1. Reporting  \n";
				cout << "2. Add income \n";
				cout << "3. Add expense \n";
				if (selectedOption == 0) flag = -1;
				else {
					if (selectedOption == 1){
						flag = 211;
						cout << "Reporting: \n";
						cout << "0. Back \n";
						cout << "1. View remaining budget \n";
						cout << "2. View incomes \n";
						cout << "3. View expenses \n";
						cout << "4. Aggregated statistics \n";
						selectOption();
						if (selectedOption == 0) flag = -1;
						else {
							if (selectedOption == 1) flag = 2111;
							if (selectedOption == 2) flag = 2112;
							if (selectedOption == 3) flag = 2113;
							if (selectedOption == 4) flag = 2114;
						}
					if (selectedOption == 2) flag = 212;
					if (selectedOption == 3) flag = 213;
					}
			
				}			
			}
		case 0:
			break;
		}
	} while (selectedOption != 0);
}
