#include <iostream>

/* 참조자의 도입 */
int change_val(int* p)
{
	*p = 3;
	return 0;
}

/* 함수 인자로 레퍼런스 받기 */
int change_val2(int& p)
{
	p = 3;
	return 0;
}

int main()
{
	/* 참조자의 도입 */
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
	std::cout << std::endl;

	int a = 3;
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	std::cout << std::endl;

	int number2 = 5;
	std::cout << number2 << std::endl;
	change_val2(number2);
	std::cout << number2 << std::endl;
	std::cout << std::endl;

	/* 참조자 이해하기 */
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
								  				  
	y = 2;						  				  
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
								  				  
	z = 3;						  				  
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
	std::cout << std::endl;

	/* 상수에 대한 참조자 */
	//int &ref = 4;
	//std::cout << ref << std::endl;

	/* 레퍼런스의 배열과 배열의 레퍼런스 */
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	std::cout << std::endl;

	/*
		문제 1
		레퍼런스가 메모리 상에 반드시 존재해야 하는 경우는 어떤 경우가 있을까요? 
		그리고 메모리 상에 존재할 필요가 없는 경우는 또 어떤 경우가 있을 까요 ? (난이도 : 上)
	*/

	/*
		Q.
		아래 글들을 보면서 생각해보기를 제 식대로 생각해보았습니다..
		함수의 매개변수로 레퍼런스를 전달할 때는 주소를 전달한다라고 하셨는데,
		이것을 힙, 스택, 데이터 메모리 영역 분리 관점에서
		호출 스택이 추가될 때 주소값을 전달한다 라고 생각해도 될까요?

		같은 관점에서 생각해보기의 답으로
		1) 호출 스택이 달라질 때, 해당 메모리에 접근하기 위해 주소가 필요하다. 주소 메모리 공간이 필요하다.
		2) 호출 스택이 같을 때, 바로 접근하며 따로 주소 메모리 공간이 불필요하다.
		이렇게 생각해도 될까요?

		A. 네 잘 이해하신 것 같네요!
	*/

	return 0;
}