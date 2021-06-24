#include <iostream>
using namespace std;

typedef struct Animal
{
	char name[30];
	int age;
	int health;
	int food;
	int clean;
} Animal;

void create_animal(Animal* animal)
{
	cout << "������ �̸�? ";
	cin >> animal->name;

	cout << "������ ����? ";
	cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal* animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(Animal* animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal* animal)
{
	cout << animal->name << "�� ����" << endl;
	cout << "ü�� : " << animal->health << endl;
	cout << "��θ� : " << animal->food << endl;
	cout << "û�� : " << animal->clean << endl;
}

int main()
{
	/* new �� delete �� ��� */
	
	/*
		new �� ����ϴ� �����
		T * pointer = new T;
		�� �����ϴ�.
	*/
	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;

	/* ���� ���� delete �ϱ� */
	
	/* 
		int a = 5;
		delete &a;
	*/
	
	// Heap�� �ƴ� ������ �����Ϸ��� �ϱ� ������ ������ ���´�.


	/* new �� �迭 �Ҵ��ϱ� */
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;
	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		std::cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "th element of list : " << list[i] << std::endl;		
	}
	delete[] list;

	/* ���ƿ� ������ */
	Animal* list2[10];
	int animal_num = 0;

	for (;;)
	{
		cout << "1. ���� �߰��ϱ�. " << endl;
		cout << "2. ���. " << endl;
		cout << "3. ���� ����. " << endl;

		int input;
		cin >> input;		

		switch (input)
		{
			int play_with;

			case 1:
				list2[animal_num] = new Animal;
				create_animal(list2[animal_num]);
				animal_num++;
				break;

			case 2:
				cout << "������ ����? : ";
				cin >> play_with;

				if (play_with < animal_num)
					play(list2[play_with]);
				break;

			case 3:
				cout << "������ ����? : ";
				cin >> play_with;
				if (play_with < animal_num)
					show_stat(list2[play_with]);
				break;
		}
		
		for (int i = 0; i != animal_num; i++)
		{
			one_day_pass(list2[i]);
		}
	}
	for (int i = 0; i != animal_num; i++)
	{
		delete list2[i];
	}	
}

