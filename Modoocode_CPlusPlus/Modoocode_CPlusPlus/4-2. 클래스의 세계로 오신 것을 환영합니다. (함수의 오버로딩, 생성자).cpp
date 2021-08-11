#include <iostream>
using namespace std;

void printf(char x) { cout << "char : " << x << endl; }
void printf(int x) { cout << "int : " << x << endl; }
void printf(double x) { cout << "double : " << x << endl; }

class Date
{
private:
	int _year;
	int _month;  // 1 ���� 12 ����.
	int _day;    // 1 ���� 31 ����.

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);
	// �ش� ���� �� �� ���� ���Ѵ�.
	int GetCurrentMonthTotalDays(int year, int month);
	void ShowDate();

	/* ������ (�����ε�) */
	Date(int year, int month, int day)
	{
		cout << "���� 3���� ������ ȣ��!" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	/* ����Ʈ ������ */
	Date()
	{
		cout << "����Ʈ ������ ȣ��!" << endl;
		_year = 2021;
		_month = 8;
		_day = 11;
	}
};

void Date::SetDate(int year, int month, int day) 
{
	_year = year;
	_month = month;
	_day = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) 
{
	static int _monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2) 
		return _monthday[month - 1];
	else if (year % 4 == 0 && year % 100 != 0) 
		return 29;  // ����
	else 
		return 28;
}

void Date::AddDay(int inc) 
{
	while (true) 
	{
		// ���� ���� �� �� ��
		int current__monthtotal_days = GetCurrentMonthTotalDays(_year, _month);

		// ���� �� �ȿ� ���´ٸ�;
		if (_day + inc <= current__monthtotal_days) 
		{
			_day += inc;
			return;
		}
		else 
		{
			// �����޷� �Ѿ�� �Ѵ�.
			inc -= (current__monthtotal_days - _day + 1);
			_day = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) 
{
	AddYear((inc + _month - 1) / 12);
	_month = _month + inc % 12;
	_month = (_month == 12 ? 12 : _month % 12);
}

void Date::AddYear(int inc) 
{ 
	_year += inc; 
}

void Date::ShowDate() 
{
	std::cout << "������ " << _year << " �� " << _month << " �� " << _day << " �� �Դϴ� " << std::endl;
}

int main()
{
	/* �Լ��� �����ε� */
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	printf(a);
	printf(b);
	printf(c);

	/* ������ */
	//Date day(2011, 3, 1);
	//day.ShowDate();

	//day.AddYear(10);
	//day.ShowDate();

	// �������� ����
	/* ��ü�� �ʱ�ȭ�ϴ� ������ �ϱ� ������ ���ϰ��� ����! */
	/* Ŭ���� �̸� */ /* ( ���� ) {} */

	/* ����Ʈ ������ */
	//Date day = Date();
	//Date day2;

	//day.ShowDate();
	//day2.ShowDate();

	/* ������ �����ε� */
	Date day = Date();
	Date day2(2021, 8, 11);

	day.ShowDate();
	day2.ShowDate();

	return 0;
}