#include <fstream>
#include "StudentModel.hpp"
#include "Teacher.hpp"


const vector <string> firstName = { "Волгузов Артём", "Волобуев Артемий", "Калиткин Пётр", "Стас Асафьев", "Лев Ерёминко", "Сева Ловкачёв", "Артемий Лебедев", "Бьёрн Страуструп"};

void readFile(vector<equal>& eqList) {
	std::ifstream input("Eqs.txt");
	if (!input.is_open())
		return;
	equal eq;
	while (input >> eq.a >> eq.b >> eq.c) {
		eqList.push_back(eq);
	}
	input.close();
	return;
}

void fillStudentQueue(queue <student*>& completed, vector <equal>& eqList) {
	goodStudent* stud1;
	normStudent* stud2;
	badStudent* stud3;
	int random;
	for (int i = 0; i < firstName.size(); ++i) {
		random = rand() % 3;
		switch (random) {
		case 0:
			stud1 = new goodStudent(firstName.at(i));
			stud1->solveEq(eqList);
			stud1->sendAnswers(completed);
			break;
		case 1:
			stud2 = new normStudent(firstName.at(i));
			stud2->solveEq(eqList);
			stud2->sendAnswers(completed);
			break;
		case 2:
			stud3 = new badStudent(firstName.at(i));
			stud3->solveEq(eqList);
			stud3->sendAnswers(completed);
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	queue <student*> completed;
	vector <equal> eqList;
	readFile(eqList);
	fillStudentQueue(completed, eqList);
	teacher teach("teacher");
	teach.checkWorks(eqList, completed);
	teach.printTable();
	return 0;
}