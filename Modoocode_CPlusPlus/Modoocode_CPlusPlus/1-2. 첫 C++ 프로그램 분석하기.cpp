#include <iostream>

namespace {
	// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
	// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
	int OnlyInThisFile() { return 0; }

	// 이 변수 역시 static int x 와 동일합니다.
	int only_in_this_file = 0;
}  // namespace

int main()
{
	OnlyInThisFile();
	only_in_this_file = 3;

	// 문제 1
	// 화면에 출력되는 것들을 바꾸어보자

	// 문제 2
	// 아래 문장은 화면에 어떻게 출력될까요?
	std::cout << "hi" << std::endl
		<< "my name is"
		<< "Psi" << std::endl;
}