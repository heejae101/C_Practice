/* 함수를 정의하는 방법 

반환값 자료형 함수이름()
{
    코드;
}
*/

#include <stdio.h>
void hello() // 반환값이 없는 hello함수 정의
{
    int num1 = 10;   // 지역변수 
    printf("hello, world");
}

int main()
{
    hello();  //함수 호출 

    return 0;
}

#include <stdio.h>
int main()
{
    hello();

    return 0;
}

void hello()
{
    printf("hello, world\n");
}

//hello 함수를 main함수 아래에 작성하면 컴파일 경고와 에러가 발생합니다. 
// 어떤 함수가 있다는 사실을 알려주려면 함수 선언 (function delcaration)을 해줘야합니다.
// 함수 형태만 선언하는 함수 원형(function prototype) 입니다.
#include <stdio.h>

void hello(); // 함수 원형 

int main()
{
    hello();

    return 0;
}

void hello() // 함수 헤더(function header)
{
    printf("Hello, world\n"); // 함수 본체(function body)
}

