
#include <iostream>

int main() {

	// ������ ����
	int i1;
	char c;
	double d;
	float f;

	// C++�� for��
	int i2;
	for (int i2 = 0; i2 < 10; i2++)
	{
		std::cout << i2 << std::endl;
	}
	std::cout << std::endl;

	/* 1 ���� 10 ���� ��*/
	int i3, sum = 0;
	for (int i3 = 1; i3 <= 10; i3++)
	{
		sum += i3;
	}

	std::cout << "���� : " << sum << std::endl;
	std::cout << std::endl;

	int sum2 = 0;
	/* ������ ���� ��� ������ �����ص� �ȴ�.*/
	for (int i4 = 1; i4 <= 10; i4++)
	{
		sum2 += i4;
	}
	std::cout << "���� : " << sum << std::endl;
	std::cout << std::endl;

	/* while �� �̿��ϱ� */
	int i5 = 0, sum3 = 0;

	while (i5 <= 10)
	{
		sum3 += i5;
		i5++;
	}

	std::cout << "���� : " << sum << std::endl;
	std::cout << std::endl;

	/* ����� ���� ���߱�*/
	int lucky_number = 3;
	std::cout << "�� ����� ���� ���߾� ������~" << std::endl;

	int user_input;

	while (1)
	{
		std::cout << "�Է� : ";
		std::cin >> user_input;
		if (lucky_number == user_input)
		{
			std::cout << "���߼̽��ϴ�~~" << std::endl;
			break;
		}
		else
		{
			std::cout << "�ٽ� �����غ�����~" << std::endl;
		}
	}
	std::cout << std::endl;

	// switch �� �̿��ϱ�
	using std::cout;
	using std::endl;
	using std::cin;

	int user_input2;
	cout << "���� ������ ǥ�����ݴϴ� " << endl;
	cout << "1. �̸� " << endl;
	cout << "2. ���� " << endl;
	cout << "3. ���� " << endl;
	cin >> user_input2;

	switch (user_input2)
	{
	case 1:
		cout << "Psi ! " << endl;
		break;

	case 2:
		cout << "99 ��" << endl;
		break;

	case 3:
		cout << "����" << endl;
		break;

	default:
		cout << "�ñ��Ѱ� ������~" << endl;
		break;		
	}

	return 0;
}