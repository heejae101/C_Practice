// 매개변수를 사용하려면 함수를 정의할 때 () (괄호) 안에 자료형과 변수 이름을 지정해주면 됩니다.

#include <stdio.h>

void helloNumber(int num1)
{
    printf("hello, %d\n",num1);
}

int main()
{
    helloNumber(10);
    helloNumber(20);

    return 0;
}

// 덧셈 함수 
#include <stdio.h>

int add(int a, int b)
{
    return a+b;
}

int main()
{
    int num1;
    num1 = add(10,20);
    printf("%d\n",num1);
    return 0;
}

// 매개변수, 파라미터 , 인자 인수 , 아규먼트
/* 매개변수,파라미터(parameter), 형식 매개변수 (formal parameter), 인자: 함수 바깥에서 전달된 값이 저장되는 변수

인수, 전달인자, 아규먼트(argument), 실행 전달인자(actual argument): 함수를 호출할 때 전달하는 값이나 변수를 뜻함
*/

