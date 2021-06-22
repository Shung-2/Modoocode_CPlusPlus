#include <iostream>

/* �������� ���� */
int change_val(int* p)
{
	*p = 3;
	return 0;
}

/* �Լ� ���ڷ� ���۷��� �ޱ� */
int change_val2(int& p)
{
	p = 3;
	return 0;
}

int main()
{
	/* �������� ���� */
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

	/* ������ �����ϱ� */
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

	/* ����� ���� ������ */
	//int &ref = 4;
	//std::cout << ref << std::endl;

	/* ���۷����� �迭�� �迭�� ���۷��� */
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	std::cout << std::endl;

	/*
		���� 1
		���۷����� �޸� �� �ݵ�� �����ؾ� �ϴ� ���� � ��찡 �������? 
		�׸��� �޸� �� ������ �ʿ䰡 ���� ���� �� � ��찡 ���� ��� ? (���̵� : ߾)
	*/

	/*
		Q.
		�Ʒ� �۵��� ���鼭 �����غ��⸦ �� �Ĵ�� �����غ��ҽ��ϴ�..
		�Լ��� �Ű������� ���۷����� ������ ���� �ּҸ� �����Ѵٶ�� �ϼ̴µ�,
		�̰��� ��, ����, ������ �޸� ���� �и� ��������
		ȣ�� ������ �߰��� �� �ּҰ��� �����Ѵ� ��� �����ص� �ɱ��?

		���� �������� �����غ����� ������
		1) ȣ�� ������ �޶��� ��, �ش� �޸𸮿� �����ϱ� ���� �ּҰ� �ʿ��ϴ�. �ּ� �޸� ������ �ʿ��ϴ�.
		2) ȣ�� ������ ���� ��, �ٷ� �����ϸ� ���� �ּ� �޸� ������ ���ʿ��ϴ�.
		�̷��� �����ص� �ɱ��?

		A. �� �� �����Ͻ� �� ���׿�!
	*/

	return 0;
}