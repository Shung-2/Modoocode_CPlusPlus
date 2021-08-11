#include <iostream>
using namespace std;

void printf(char x) { cout << "char : " << x << endl; }
void printf(int x) { cout << "int : " << x << endl; }
void printf(double x) { cout << "double : " << x << endl; }

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
	// 해당 월의 총 일 수를 구한다.
	int GetCurrentMonthTotalDays(int year, int month);
	void ShowDate();

	/* 생성자 (오버로딩) */
	Date(int year, int month, int day)
	{
		cout << "인자 3개인 생성자 호출!" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	/* 디폴트 생성자 */
	Date()
	{
		cout << "디폴트 생성자 호출!" << endl;
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
		return 29;  // 윤년
	else 
		return 28;
}

void Date::AddDay(int inc) 
{
	while (true) 
	{
		// 현재 달의 총 일 수
		int current__monthtotal_days = GetCurrentMonthTotalDays(_year, _month);

		// 같은 달 안에 들어온다면;
		if (_day + inc <= current__monthtotal_days) 
		{
			_day += inc;
			return;
		}
		else 
		{
			// 다음달로 넘어가야 한다.
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
	std::cout << "오늘은 " << _year << " 년 " << _month << " 월 " << _day << " 일 입니다 " << std::endl;
}

int main()
{
	/* 함수의 오버로딩 */
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	printf(a);
	printf(b);
	printf(c);

	/* 생성자 */
	//Date day(2011, 3, 1);
	//day.ShowDate();

	//day.AddYear(10);
	//day.ShowDate();

	// 생성자의 정의
	/* 객체를 초기화하는 역할을 하기 때문에 리턴값이 없다! */
	/* 클래스 이름 */ /* ( 인자 ) {} */

	/* 디폴트 생성자 */
	//Date day = Date();
	//Date day2;

	//day.ShowDate();
	//day2.ShowDate();

	/* 생성자 오버로딩 */
	Date day = Date();
	Date day2(2021, 8, 11);

	day.ShowDate();
	day2.ShowDate();

	return 0;
}