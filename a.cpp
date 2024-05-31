#include <string>
#include <cctype>
#include <iterator>

class Str {
	//�Է� ������
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream&, Str&);
	//getline();
public:
	typedef Vec<char>::size_type size_type;

	//��� �ִ� Str ��ü��  ����� �⺻ ������
	Str() {}

	//c�� ���纻 n���� �ִ� Str ��ü�� ����
	Str(size_type n, char c): data(n, c) {}

size_type size() const {
	return data.size();
}

std::ostream operator<<(std::ostream&, const Str&); //�߰�

#endif