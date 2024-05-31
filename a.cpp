#include <string>
#include <cctype>
#include <iterator>

class Str {
	//입력 연산자
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream&, Str&);
	//getline();
public:
	typedef Vec<char>::size_type size_type;

	//비어 있는 Str 객체를  만드는 기본 생성자
	Str() {}

	//c의 복사본 n개가 있는 Str 객체를 생성
	Str(size_type n, char c): data(n, c) {}

size_type size() const {
	return data.size();
}

std::ostream operator<<(std::ostream&, const Str&); //추가

#endif