
#include <iostream>

int main() {

	// 변수의 정의
	int i1;
	char c;
	double d;
	float f;

	// C++의 for문
	int i2;
	for (int i2 = 0; i2 < 10; i2++)
	{
		std::cout << i2 << std::endl;
	}
	std::cout << std::endl;

	/* 1 부터 10 까지 합*/
	int i3, sum = 0;
	for (int i3 = 1; i3 <= 10; i3++)
	{
		sum += i3;
	}

	std::cout << "합은 : " << sum << std::endl;
	std::cout << std::endl;

	int sum2 = 0;
	/* 변수는 변수 사용 직전에 선언해도 된다.*/
	for (int i4 = 1; i4 <= 10; i4++)
	{
		sum2 += i4;
	}
	std::cout << "합은 : " << sum << std::endl;
	std::cout << std::endl;

	/* while 문 이용하기 */
	int i5 = 0, sum3 = 0;

	while (i5 <= 10)
	{
		sum3 += i5;
		i5++;
	}

	std::cout << "합은 : " << sum << std::endl;
	std::cout << std::endl;

	/* 행운의 숫자 맞추기*/
	int lucky_number = 3;
	std::cout << "내 비밀의 수를 맞추어 보세요~" << std::endl;

	int user_input;

	while (1)
	{
		std::cout << "입력 : ";
		std::cin >> user_input;
		if (lucky_number == user_input)
		{
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else
		{
			std::cout << "다시 생각해보세요~" << std::endl;
		}
	}
	std::cout << std::endl;

	// switch 문 이용하기
	using std::cout;
	using std::endl;
	using std::cin;

	int user_input2;
	cout << "저의 정보를 표시해줍니다 " << endl;
	cout << "1. 이름 " << endl;
	cout << "2. 나이 " << endl;
	cout << "3. 성별 " << endl;
	cin >> user_input2;

	switch (user_input2)
	{
	case 1:
		cout << "Psi ! " << endl;
		break;

	case 2:
		cout << "99 살" << endl;
		break;

	case 3:
		cout << "남자" << endl;
		break;

	default:
		cout << "궁금한게 없군요~" << endl;
		break;		
	}

	return 0;
}