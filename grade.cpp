//grade.cpp
#include<"grade.h">
#include<"median.h">
#include<"Student_info..h">
#include <vector>
#include<stdexcept>

//�л��� ���� ���θ� �����ϴ� ���� �Լ�
bool fgrade(const Student_info& s) {
	return grade(s) < 60

}

//�߰����� ����, �⸻���� ����, ���� ���� ��������
//�л��� ���� ������ ����
double grade(double mt, double ft, double hw)

//�߰����� ����, �⸻���� ����,���� ������ ���ͷ�
//�л��� ���� ������ ����.
//�� �Լ��� �μ��� �����ϱ�
double frade(double mt, double ft,const vector <double>

	double frade(const Student_info& s)

	///�� ��° ����
	//�ε��� ��� �ݺ��ڸ� ��������� ������
	//���� ���ϰ� �����
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