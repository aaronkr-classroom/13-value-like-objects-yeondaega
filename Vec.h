#ifndef GUARD_H_VEC
#define GUARD_H_VEC

#include <algorithm> //max �Լ�
#include <cstddef> //size_t, ptrdiff_t
#include <memory>//memory allocator

using namespace std;
//std::max, uninitialized_fill, uninitialized_copy, allocator

//Vec Ŭ���� �߻� ������ Ÿ��
template <class T> class Vec { 
public:

	//�������̽�

	//Ÿ�� ���ǹ�
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_refernece;

	//������
	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) {
		create(n, val);
	}

	//�ݺ� ������
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec&); //���� (�̷��� �ϰڽ��ϴ�!)
	~Vec() { uncreate(); }//�Ҹ���

	//���� ũ��� �ε����� ���� ���ο� �Լ�
	size_type size() const { return avail - data; }
	T& operator[](size_type i) const { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	//�ݺ��ڸ� ��ȯ�ϴ� ���ο� �Լ�
	iterator begin() { return data; }
	const_iterator begin() const { return data };

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	//��� �߰��ϴ� �Լ� (�޸𸮸� ä���,Ȯ���մϴ�)
	void push_back(const T& val) {
		if (avail == limit) //�ʿ��ϴٸ� ���� ���� Ȯ��
			grow();

		unchecked_append(val); // ���ο� ��� �߰�
	}

	//�߰��ϴ� �Լ�
	void clear() { uncreate(); }
	bool empty() {	return data == avail;}

private;
	 iterator data; //Vec�� ù ��° ��Ҹ� ����Ű�� ������
	 iterator avail;//���������� ���� ����� ������ ����Ű�� ������
	 iterator limit// ����� �� �ִ� ������ ����� ������ ����Ű�� ������

	allocator<T> alloc;//�޸𸮸� �Ҵ��ϴ� ��ü

	 //��� �Լ� ����
	 void create();
	 void create(size_type, const T&);
	 void create(const_iterator, const_iterator);

	 void uncreate();

	 void grow();
	 void unchecked_append(const T&);
};

//������ ��� �Լ��� (3��)
template <class T> void Vec<T>::create() {
	data = avail = limit = 0;

}


template <class T> void Vec<T>::create(size_type n, const T& val) {
	data = allo.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val); //allocator ���� �Լ�

}

template <class T> void Vec<T>::create(const_iterator i, const_iterator i) {
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data); //allocator ���� �Լ�
}


//�Ҹ��� ��� �Լ�
template <class T> void Vec<T> ::uncreate() {
	if (data) {
		//������ ��ҵ��� �������� �Ҹ�
		iterator it = avail; //������ ����� ����Ű�� ������
		while (it != data) //ù ���� ����� ����Ű�� �����ͱ���
			alloc.destroy(--it);//it �����ϱ�

		//�Ҵ�� ��� ���� ������ ��ȯ
		alloc.deallocate(data, limit - data);

	}
	//��� �ִ� Vec ����Ű���� �����͸� �缳��
	data = avail = limit = 0;
}

//�޸� ������ �ø��� �Լ�
template<class T> void Vec<T>::grow() {
	//���� ������ �ø� ���� ���� ����ϴ� 
	//���� ������ 2�踦 �Ҵ�
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

	//���ο� ���� ������ �Ҵ��ϰ� ���� ��ҵ��� ���ο� ���� ������ ����
	iterator new data = alloc.allocate(new_size); //�޸� Ȯ���ϱ�
	iterator new_avail = uninitialzed_copy(data, avail, new_data);

	//���� ������ ��ȯ
	uncreate();

	//���Ӱ� �Ҵ��� ���� ������ ����Ű���� ������ �缳��
	data = new_data;
	avail= new_avail;
	limit = data + new_size;
	

}

//���ο� ��Ҹ� �߰��ϱ�
template <class T>void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}


//=�ǿ��� ����
template<class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	//�ڰ� �Ҵ� ���� Ȯ��
	if (&rhs != this) {
		//�º��� ���� �迭�� �����ϴ� �޸𸮸� ����
		uncreate();

		//�캯�� ���� ��Ҹ� �º����� ����
		create(rhs.begin(), rhs.end());
	}
	return*this;
}

#endif
