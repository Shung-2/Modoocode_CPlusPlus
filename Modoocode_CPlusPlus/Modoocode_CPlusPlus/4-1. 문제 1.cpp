#include <iostream>
using namespace std;

/*
생각 해볼 문제. 1
여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다.
SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다.
한 가지 주의할 점은 만일 2012년 2월 28일에 3일을 더하면
2012년 2월 31일이 되는 것이 아니라 2012년 3월 2일이 되겠지요? (난이도 : 上)
*/

class Date
{
private:
	int _year;
	int _month;  // 1 부터 12 까지.
	int _day;    // 1 부터 31 까지.

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
			/* 윤년 계산 */
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
	cout << _year << "년 " << _month << "월 " << _day << "일 " << endl;
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