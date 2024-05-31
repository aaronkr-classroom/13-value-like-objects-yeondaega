//Student_info.cpp
#include "Student_info.h"

//결합 연산자
Str& operator+=(const Str& s) {
	std::copy(s.data.begin(), s.data.end(),
		std::back_inserter(data));
	return*this;
}

St

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name; //T/F

}

istream& read(istream& is, Student_info& s) {
	//학생의 이름, 중간고사 점수, 기말고사 점수 읽어 저장
	is >> s.name >> s.midterm >> s, final;
	//과제 점수를 읽음
	read_hw(is, s.homework);
	return is;
}