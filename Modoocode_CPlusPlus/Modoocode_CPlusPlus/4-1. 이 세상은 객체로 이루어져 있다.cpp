#include <iostream>
using namespace std;

class Animal
{
private:
	int food;
	int weight;

public :
	void set_animal(int _food, int _weight)
	{
		food = _food;
		weight = _weight;
	}

	void increase_food(int inc)
	{
		food += inc;
		weight += (inc / 3);
	}

	void view_stat()
	{
		cout << "이 동물의 food : " << food << endl;
		cout << "이 동물의 weight : " << weight << endl;
	}
};

int main()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);
	animal.view_stat();
	return 0;

	/* 
	생각 해볼 문제. 1
	여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다.
	SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다.
	한 가지 주의할 점은 만일 2012년 2월 28일에 3일을 더하면
	2012년 2월 31일이 되는 것이 아니라 2012년 3월 2일이 되겠지요? (난이도 : 上)

	class Date {
		int year_;
		int month_;  // 1 부터 12 까지.
		int day_;    // 1 부터 31 까지.

	public: 
		void SetDate(int year, int month, int date);
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);
		void ShowDate();
	*/
}