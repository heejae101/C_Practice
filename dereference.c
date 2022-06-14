#include <stdio.h>

// 메모리 주소가 있는 곳으로 이동해서 값을 가져오고 싶다면 역참조 (dereference) 연산자 *를 사용합니다.
int main()
{
    /*
    int *numPtr;                // 포인터. 포인터를 선언할 때 *
    printf("%d\n", *numPtr);    // 역참조. 포인터에 사용할 때 *
    */

    int *numPtr;
    int num1 = 10;

    numPtr = &num1;

    printf("%d\n", *numPtr);

    // numPtr2 = num2;는 numPtr2은 int 포인터 형이고 num2는 int형이라 자료형이 일치하지않음
    // *numPtr2 = num2;는 *numPtr은 int형이고 num1도 int형이라 자료형이 일치함; 

    int *numPtr2;
    int num2 = 10;

    // 주소 연산자 &도 자료형을 맞춰주는 역할을 합니다
    // numPtr은 int 포인터형이고, &num1은 int형 변수의 주소이므로 자료형이 일치함
    // numPtr은 pointer to int, &num1은 address of int이므로 자료형이 일치함
    numPtr2 = &num2;
    *numPtr2 = 20;

    printf("%d\n",*numPtr2);
    printf("%d\n",num2);

    return 0;
}

