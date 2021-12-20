#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;



/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("myfirstprogram");
	PyErr_Print();

	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"myfirstprogram");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"myfirstprogram");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

char menuSelection;				//this variable hpld the user selection for the display menu
string itemName;				//this variable holds string information from file opened
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);		//here we geet the handle to the output device allowing text editing


void DisplayMenu();				//this is the delaration for the display menu function
void Selection1();				//this is the delaration for the selection1 function
void Selection2();				//this is the delaration for the selection2 function
void Selection3();				//this is the delaration for the selection3 function
void Selection4();				//this is the delaration for the selection4 function
void DailyPurchaseList();		//this is the delaration for the daily purchase list function



int main() {
	DailyPurchaseList();	//Here we call the Daily purchase list function	
	return 0;
}

void DisplayMenu() {
	cout << '\n';
	
	cout << "1: Display items and times purchased"<< endl; //Here the menu is displayed for the user to make
	cout << "2: Display a specific item and times purchased" << endl;				//a selection
	cout << "3: Display an histogram of all items purchased" << endl;
	cout << "4: Exit" << endl;
	cout << "Please enter your selection as a number 1, 2, 3 or 4" << endl;
	cout << "Option: ";
	cin >> menuSelection;				//Here we take the users selection
	std::system("CLS");
}
void Selection1() {
	CallProcedure("printTodaysPurchases"); //here we call the print function procedure in python
}
void Selection2() {
	cout << "Enter the name of the item: ";				//Here we ask for an item from user
	cin >> itemName;									//we get that item and store it in the itemName variable
	if (callIntFunc("PrintMe", itemName) == 0) {		//here we call the print me function in python
		SetConsoleTextAttribute(h, 12);					//if python returns 0 for item quantity					//text is colored red to alert user of error
		cout << endl;									//the user is notified
		cout << itemName << " was not purchased today." << endl;									
		cout << "Make sure item name entered matches the name on items purchased list (option 1)";
		cout << endl;									//the user is also reminded of item name accuracy
		cout << endl;									//and where they can check item names
		SetConsoleTextAttribute(h, 7);
	}						//text is returned to default color
	else {
		SetConsoleTextAttribute(h, 2);		//text is colored green to alert user of success
		cout << endl;										//if python returns a quantity for the item
		cout << "Item and amount purchased: " << endl;		//C++ prints the item and the quantity
		cout << itemName << " : " << callIntFunc("PrintMe", itemName);
		cout << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 7);
	}
}
void Selection3() {							//This function calls the print histogram function in python
	CallProcedure("printhistogram");
	fstream file;
	string item;
	int occurance;
	string filename = "frequency.dat";							//Python creates the frequency.dat file
	file.open(filename.c_str());								//C++ opens and reads the files contents
	while (file >> item && file >> occurance) {					//Here we iterate through the file, printing each
		cout << item << " " << string(occurance, '*') << endl;	//string and adding asterisks next to that string based
	}															//on the integer next to that string. i.e (potato 4 will
	file.close();												//give us potato *****1
	cout << endl;												
	cout << "Histogram complete" << endl;						//histogram complete lets the user know this is all the information provided
}
void Selection4() {						//This function prints goodbye and exits the program
	cout << endl;
	cout << "Goodbye!!!" << endl;		
}
void DailyPurchaseList() {
	char quit;
	do {
		try {
			std::system("CLS");
			DisplayMenu();
			if (menuSelection == '1') {				//Here we call the selection1 function if the user chooses option 1.
				Selection1();
				system("pause");			//we pause to prevent screen from displaying results then immidietly going back to menu
			}
			else if (menuSelection == '2') {		//Here we call the selection2 function if the user chooses option 2.
				Selection2();
				system("pause");			//we pause to prevent screen from displaying results then immidietly going back to menu
			}
			else if (menuSelection == '3') {		//Here we call the selection3 function if the user chooses option 3.
				Selection3();
				system("pause");			//we pause to prevent screen from displaying results then immidietly going back to menu
			}
			else if (menuSelection == '4') {		//Here we call the selection4 function if the user chooses option 4.
				Selection4();
				break;		//Here we break out of the loop of going back to the menu
			}
			else {
				throw runtime_error("Error: Please only enter 1, 2, or 3"); //Here we have the printed Error message 
			}																//if there user inputs a selection other than 1,2 or 3 in the main menu
		}
		catch (runtime_error& excpt) {			//Here we print out the error if user
			cout << excpt.what() << endl;		//enters invalid information
		}
	} while (menuSelection != 3);	
	
}
