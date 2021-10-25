// Menachem Heller 305567943
// Bezalel Jacober 312033236

#include <iostream>
#include <list>
#include <string>
#include "Tree.h"

using namespace std;
int main()
{
	Tree t;
	string father, val, sol;
	char ch;
	cout << "\nDECISION TREE\n";
	cout << "Choose one of the following:" << endl;
	cout << "n: New decision tree" << endl;
	cout << "s: Add a new option for a question" << endl;
	cout << "d: Delete a subtree" << endl;
	cout << "p: Print all tree" << endl;
	cout << "w: Print how to get a node" << endl;
	cout << "r: Run a process of questions" << endl;
	cout << "t: Print to a string" << endl;
	cout << "e: exit:" << endl;
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':cout << "enter the main question (with no space) "; cin >> val; t.addRoot(val); break;
		case 's':cout << "enter the question (with no space) "; cin >> father;
			cout << "enter the new answer (with no space) "; cin >> val;
			cout << "enter the new solution(possible a new question, with no space) "; cin >> sol;
			if (t.addSon(father, val, sol)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'd':cout << "enter value of subtree to delete (with no space) "; cin >> val; t.deleteSubTree(val);  break;
		case 'p':t.printAllTree();  break;
		case 'w':cout << "enter a value (with no space) "; cin >> val; t.searchAndPrint(val); cout << endl;  break;
		case 'r':t.process(); cout << endl;  break;
		case 'e':cout << "bye "; break;
		case 't':cout << t.printToString(); cout << endl;  break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');
}

/*
DECISION TREE
Choose one of the following:
n: New decision tree
s: Add a new option for a question
d: Delete a subtree
p: Print all tree
w: Print how to get a node
r: Run a process of questions
t: Print to a string
e: exit:
n
enter the main question (with no space) is_it_cloudy?
s
enter the question (with no space) is_it_cloudy?
enter the new answer (with no space) yes
enter the new solution(possible a new question, with no space) what_is_the_temp?
success
s
enter the question (with no space) what_is_the_temp?
enter the new answer (with no space) less_then_zero
enter the new solution(possible a new question, with no space) there_may_be_snow
success
s
enter the question (with no space) what_is_the_temp?
enter the new answer (with no space) warm
enter the new solution(possible a new question, with no space) no_rain_is_expected
success
s
enter the question (with no space) is_it_cloudy?
enter the new answer (with no space) partly
enter the new solution(possible a new question, with no space) prepare_for_rain
success
s
enter the question (with no space) is_it_cloudy?
enter the new answer (with no space) no
enter the new solution(possible a new question, with no space) no_rain
success
p
is_it_cloudy?
: yes
 what_is_the_temp?
 : less_then_zero
  there_may_be_snow
 : warm
  no_rain_is_expected
: partly
 prepare_for_rain
: no
 no_rain
w
enter a value (with no space) no_rain
no_rain=>is_it_cloudy?
t
(is_it_cloudy?(yes,what_is_the_temp?(less_then_zero,there_may_be_snow)(warm,no_rain_is_expected))(partly,prepare_for_rain)(no,no_rain))
w
enter a value (with no space) prepare_for_rain
prepare_for_rain=>is_it_cloudy?
w
enter a value (with no space) there_may_be_snow
there_may_be_snow=>what_is_the_temp?=>is_it_cloudy?
r
is_it_cloudy?
yes
what_is_the_temp?
warm
no_rain_is_expected
w
enter a value (with no space) super_hot
Value not found

d
enter value of subtree to delete (with no space) what_is_the_temp?
p
is_it_cloudy?
: partly
 prepare_for_rain
: no
 no_rain
e
bye
C:\Users\mybj2\Source\Repos\menachem-h\DAST-2021\MedicalDispatch\x64\Debug\MedicalDispatch.exe (process 19676) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/