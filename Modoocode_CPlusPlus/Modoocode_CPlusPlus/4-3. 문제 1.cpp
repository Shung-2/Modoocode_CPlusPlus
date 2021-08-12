/* 
���� 1
�Ʒ��� ���� ���ڿ� Ŭ������ �ϼ��غ�����(���̵� : ��)
*/

#include <string.h>
#include <iostream>
using namespace std;

class String {
	char* str = nullptr;
	int len = 0;

public:
	String(char c, int n);  // ���� c �� n �� �ִ� ���ڿ��� ����
	String(const char* s);
	String(const String& s);
	~String();

	void add_string(const String& s);   // str �ڿ� s �� ���δ�.
	void copy_string(const String& s);  // str �� s �� �����Ѵ�.
	int strlen();                       // ���ڿ� ���� ����
	char* get_string();
};

String::String(char c, int n)
{
	str = new char[n + 1];
	for (int i = 0; i < n; ++i)
		str[i] = c;

	str[n] = 0;
	len = n;
}

String::String(const char* s)
{
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}

	s -= len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	str[len] = 0;
}

String::String(const String& s)
{
	str = new char[s.len + 1];
	len = s.len;
	strcpy_s(str, s.len + 1, s.str);
}

String::~String()
{
	if (str != nullptr)
		delete str;
}

char* String::get_string()
{
	return str;
}

void String::add_string(const String& s)
{
	int size = len + s.len + 1;
	char* temp = new char[size];

	strcpy_s(temp, size, str);
	strcpy_s(temp + len, size - len, s.str);

	delete str;

	len = len + s.len;
	temp[len] = 0;
	str = temp;
}

void String::copy_string(const String& s)
{
	delete str;

	str = new char[s.len + 1];
	len = s.len;

	strcpy_s(str, len + 1, s.str);
}

int String::strlen()
{
	return len;
}