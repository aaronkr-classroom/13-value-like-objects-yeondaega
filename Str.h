#pragma once
#include <algorithm>
#include <cctype>
#include <iterator>

class Str {
	//입력 연산자
	friend std::istream& operator>>(std::istream&, Str&)
		friend std::istream& getline(std::istream&, Str&);

	public;
	typedef size_t size_type;;


//비어 있는 Str 객체를 만드는 기본 생성자
Str(size_type n, char c) {
	//메모리 할당
	length = n;
	value = new char[length];

	//배열이 c char로 채우기
	for (size_type i = 0; i != length; ++i) {
		value{ i] = c;
		}
			//c의 복사본 n개가 있는 Str 객체에 Str객체를 형성
			
			Str(size_type n, char c) : data(n, c) {}

		//null로 끝나는 char 타입의 배열에서  Str 객체를 생성
		Str(const char*cp) {
			//메모리 할당
			length = std::strlen(cp);
			value = new char[length];

			std::copy(cp, cp + length, value);
}

		//반복자 b와 e가 가르키는 범위에서 Str 객체 생성
		template<class Input> Str(Input b, Input e) {
			std::copy(b, e, std::back_inserter(data));

			//다른 Str에서 사본 만들기
			Str(const Str & s) {
				length = s.length;
				value = new char[length];

				std::copy(s.value, s.value + s.length, value);
			}
			//반복자 b와 e가 가리키는 번위에서 Str 객체를 생성

			//메모리 해체하기 위해 원래 value 소멸하기
			if (value != 0)
				delete[] value;

			//새로운 value와 length 값을 지정하기
			std::copy(s.value, s.value + s.length, new_value + new_length);
			value = new_value;
			length = new_length;
			return this;
		}

		Str& operator+=(const char c) {
			//메모리 할당
			size_type new_length = length + 1;
			char* new_value = new char[new_length];
			std::copy(value, value + length, new_value);

			//메모리 해체를 위해
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