/* 
문제 1
아래와 같은 문자열 클래스를 완성해보세요(난이도 : 中)
*/

#include <string.h>
#include <iostream>
using namespace std;

class String {
	char* str = nullptr;
	int len = 0;

public:
	String(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
	String(const char* s);
	String(const String& s);
	~String();

	void add_string(const String& s);   // str 뒤에 s 를 붙인다.
	void copy_string(const String& s);  // str 에 s 를 복사한다.
	int strlen();                       // 문자열 길이 리턴
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