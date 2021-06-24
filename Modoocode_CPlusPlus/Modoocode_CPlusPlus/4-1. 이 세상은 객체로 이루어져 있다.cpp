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
		cout << "�� ������ food : " << food << endl;
		cout << "�� ������ weight : " << weight << endl;
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
	���� �غ� ����. 1
	�������� �Ʒ��� ���� Date Ŭ������ ������ �Ϸ��� �մϴ�.
	SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰� AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �˴ϴ�.
	�� ���� ������ ���� ���� 2012�� 2�� 28�Ͽ� 3���� ���ϸ�
	2012�� 2�� 31���� �Ǵ� ���� �ƴ϶� 2012�� 3�� 2���� �ǰ�����? (���̵� : ߾)

	class Date {
		int year_;
		int month_;  // 1 ���� 12 ����.
		int day_;    // 1 ���� 31 ����.

	public: 
		void SetDate(int year, int month, int date);
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);
		void ShowDate();
	*/
}