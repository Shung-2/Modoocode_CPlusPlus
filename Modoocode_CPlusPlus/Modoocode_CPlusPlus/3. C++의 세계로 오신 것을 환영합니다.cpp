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
	cout << "동물의 이름? ";
	cin >> animal->name;

	cout << "동물의 나이? ";
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
	cout << animal->name << "의 상태" << endl;
	cout << "체력 : " << animal->health << endl;
	cout << "배부름 : " << animal->food << endl;
	cout << "청결 : " << animal->clean << endl;
}

int main()
{
	/* new 와 delete 의 사용 */
	
	/*
		new 를 사용하는 방법은
		T * pointer = new T;
		와 같습니다.
	*/
	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;

	/* 지역 변수 delete 하기 */
	
	/* 
		int a = 5;
		delete &a;
	*/
	
	// Heap이 아닌 공간을 해제하려고 하기 때문에 에러가 나온다.


	/* new 로 배열 할당하기 */
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

	/* 돌아온 마이펫 */
	Animal* list2[10];
	int animal_num = 0;

	for (;;)
	{
		cout << "1. 동물 추가하기. " << endl;
		cout << "2. 놀기. " << endl;
		cout << "3. 상태 보기. " << endl;

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
				cout << "누구랑 놀까요? : ";
				cin >> play_with;

				if (play_with < animal_num)
					play(list2[play_with]);
				break;

			case 3:
				cout << "누구껄 보게? : ";
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

