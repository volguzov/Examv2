#include "StudentModel.hpp"
#include "Teacher.hpp"
#include <iostream>

void teacher::checkWorks(vector <equal>& eqList, queue <student*>& completed) {
	for (int i = 0; i < eqList.size(); ++i) {
		answer ans;
		solver(eqList.at(i), ans);
		_rightAns.push_back(ans);
	}
	_totalCntOfEqs = eqList.size();
	while (!completed.empty()) {
		result res;
		res.studentName = completed.front()->getname();
		for (int i = 0; i < eqList.size(); ++i)
			if (_rightAns.at(i) == completed.front()->getroots().at(i))
				res.rightAns++;
		double percent = res.rightAns / (double)eqList.size() * 100;
		if (percent < 50)
			res.grade = 2;
		else if (percent >= 50 && percent < 65)
			res.grade = 3;
		else if (percent >= 65 && percent < 90)
			res.grade = 4;
		else
			res.grade = 5;
		_resAllStudents.push_back(res);
		delete completed.front();
		completed.pop();
	}
}

void teacher::printTable() {
	int nameLen = 40;
	cout << "+" << std::setfill('-') << std::setw(59) << "+" << endl;
	cout << "||                 Имя                 " << "| Баллы  | Оценка || " << endl;
	cout << "+" << std::setfill('-') << std::setw(59) << "+" << endl;
	for (int i = 0; i < _resAllStudents.size(); ++i) {
		cout << "|| " << _resAllStudents.at(i).studentName << std::setfill(' ') << std::setw(nameLen - _resAllStudents.at(i).studentName.length()) << "|   " << _resAllStudents.at(i).rightAns << "/" << _totalCntOfEqs << "   |    " << _resAllStudents.at(i).grade << "   ||" << endl;
		cout << "+" << std::setfill('-') << std::setw(59) << "+" << endl;
	}
}