//grade.cpp
#include<"grade.h">
#include<"median.h">
#include<"Student_info..h">
#include <vector>
#include<stdexcept>

//학생의 과락 여부를 결정하는 서술 함수
bool fgrade(const Student_info& s) {
	return grade(s) < 60

}

//중간시험 점수, 기말시험 점수, 종합 과제 점수에서
//학생의 종합 점수를 가힘
double grade(double mt, double ft, double hw)

//중간시험 점수, 기말시험 점수,과제 점수의 백터로
//학생의 종합 점수를 가함.
//이 함수는 인수를 복사하기
double frade(double mt, double ft,const vector <double>

	double frade(const Student_info& s)

	///세 번째 버전
	//인덱스 대신 반복자를 사용하지만 여전히
	//성능 저하가 우려됨
	list<Strudent_info>extract_fails(vector<Student_info>& students) {
	list<Student_info> fail;
	llist<Student_info>::_iteratorr iter = students.begin();

	while (iter != student.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}

	return fail;
}