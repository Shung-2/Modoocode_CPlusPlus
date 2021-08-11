#include <iostream>
using namespace std;

/*
���� �غ� ����. 1
�������� �Ʒ��� ���� Date Ŭ������ ������ �Ϸ��� �մϴ�.
SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰� AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �˴ϴ�.
�� ���� ������ ���� ���� 2012�� 2�� 28�Ͽ� 3���� ���ϸ�
2012�� 2�� 31���� �Ǵ� ���� �ƴ϶� 2012�� 3�� 2���� �ǰ�����? (���̵� : ߾)
*/

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
	void ShowDate();
};

void Date::SetDate(int year, int month, int date)
{
	_year = year;
	_month = month;
	_day = date;
}

void Date::AddDay(int inc)
{
	int date_num = 0;

	_day += inc;
	while (_day > 0)
	{
		switch (_month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			date_num = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			date_num = 30;
			break;
		case 2:
			/* ���� ��� */
			if ((_year % 4 == 0) && (_year % 100 != 0) || (_year % 400 == 0))
				date_num = 29;
			else
				date_num = 28;
			break;
		}

		if (_day > date_num)
		{
			_day -= date_num;
			AddMonth(1);
		}
		else
			break;
	}
}

void Date::AddMonth(int inc)
{
	_month += inc;
	if (_month > 12)
	{
		_month = _month % 12;
		AddYear(1);
	}
}

void Date::AddYear(int inc)
{
	_year += inc;
}

void Date::ShowDate()
{
	cout << _year << "�� " << _month << "�� " << _day << "�� " << endl;
}

int main()
{
	Date date;
	date.SetDate(1995, 2, 9);
	date.ShowDate();

	date.AddYear(26);
	date.AddMonth(6);
	date.AddDay(2);
	date.ShowDate();

	return 0;
}