#pragma once
#include <algorithm>
#include <cctype>
#include <iterator>

class Str {
	//�Է� ������
	friend std::istream& operator>>(std::istream&, Str&)
		friend std::istream& getline(std::istream&, Str&);

	public;
	typedef size_t size_type;;


//��� �ִ� Str ��ü�� ����� �⺻ ������
Str(size_type n, char c) {
	//�޸� �Ҵ�
	length = n;
	value = new char[length];

	//�迭�� c char�� ä���
	for (size_type i = 0; i != length; ++i) {
		value{ i] = c;
		}
			//c�� ���纻 n���� �ִ� Str ��ü�� Str��ü�� ����
			
			Str(size_type n, char c) : data(n, c) {}

		//null�� ������ char Ÿ���� �迭����  Str ��ü�� ����
		Str(const char*cp) {
			//�޸� �Ҵ�
			length = std::strlen(cp);
			value = new char[length];

			std::copy(cp, cp + length, value);
}

		//�ݺ��� b�� e�� ����Ű�� �������� Str ��ü ����
		template<class Input> Str(Input b, Input e) {
			std::copy(b, e, std::back_inserter(data));

			//�ٸ� Str���� �纻 �����
			Str(const Str & s) {
				length = s.length;
				value = new char[length];

				std::copy(s.value, s.value + s.length, value);
			}
			//�ݺ��� b�� e�� ����Ű�� �������� Str ��ü�� ����

			//�޸� ��ü�ϱ� ���� ���� value �Ҹ��ϱ�
			if (value != 0)
				delete[] value;

			//���ο� value�� length ���� �����ϱ�
			std::copy(s.value, s.value + s.length, new_value + new_length);
			value = new_value;
			length = new_length;
			return this;
		}

		Str& operator+=(const char c) {
			//�޸� �Ҵ�
			size_type new_length = length + 1;
			char* new_value = new char[new_length];
			std::copy(value, value + length, new_value);

			//�޸� ��ü�� ����
	//Q7
	typedef char* iterator;
	typedef const char* const_iterator;
//begin()
iterator begin() {
	return data.begin();
}
const_iterator begin() const { return data.begin(); }

//end()
iterator end() {
	return data.end();
}
const_iterator end() const {
	return data.size(
	);
}
size_type size() const {
	return data.size();
}
const char* c_str() const {
	return value + 'W0';
}
const char* data() const {
	return value;
}
void copy(char* p, size_type n) {
	std::copy(value, value + n, p);
}
private;
char *

Str operator+(const Str&, const Str&);

#endif