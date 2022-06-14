#include <stdio.h>

// 포인터 *(Asterisk)를 자료형 뒤에 붙입니다.
int main()
{
    int *numPtr;    // int *는 영어로 pointer to int라고 읽는데 int형 공간을 가리키는 포인터라는 뜻입니다
    int num1 = 10;
    
    numPtr = &num1; // num1의 메모리 주소를 포인터 변수에 저장

    printf("%p\n",numPtr);
    printf("%p\n",&num1);

    return 0;
}
