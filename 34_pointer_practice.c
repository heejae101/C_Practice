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
/*
#include <stdio.h>
int main()
{
    int num1 = 10;

    printf("%p\n",&num1);

    return 0;
}

#include <stdio.h>

int main()
{
    int *numPtr;
    int num1 = 10;

    numPtr = &num1;

    printf("%p\n", numPtr);
    printf("%p\n", &num1);

    return 0;
}

// 역참조 (dereference) 연산자 
#include <stdio.h>

int main()
{
    int *numPtr;
    int num1 = 10;

    numPtr = &num1;

    printf("%d\n",*numPtr);

    return 0;
}

// 포인터를 선언 할 때도 *를 사용하고 역참조를 할 때도 *를 사용합니다. 선언 과 사용 을 구분해서 생각하면 됨
//int *numPtr;                포인터. 포인터를 선언할 때 *
//printf("%d\n", *numPtr);    역참조. 포인터에 사용할 때 *

#include <stdio.h>

int main()
{
    int *numPtr; 포인터 변수 선언
    int num1;    정수형 변수를 선언 하고 10저장
  
    numPtr = &num1; num1 의 메모리 주소를 포인터 변수에 저장
    *numPtr = 20;   역참조 연산자로 메모리 주소에 접근하여 20을 저장 

    printf("%d\n",*numPtr);  20: 역참조 연산자로 메모리 주소에 접근하여 값을 가져옴 
    printf("%d\n", num1);    20: 실제 num1의 값도 바뀜

    return 0;
}

int *numPtr;
int num1 = 10;

numPtr = num1;   // 컴파일 경고, numPtr은 int 포인터형이고 num1은 int형이라 자료형이 일치하지 않음

*numPtr = num1;  // *numPtr은 int형이고 num1도 int형이라 자료형이 일치함

int *numPtr;
int num1;

numPtr = &num1;    // numPtr은 int 포인터형이고, &num1은 int형 변수의 주소이므로 자료형이 일치함
                    // numPtr은 pointer to int, &num1은 address of int이므로 자료형이 일치함
포인터에도 const 키워드를 붙일 수 있는데 const 의 위치에 따라 특성이 달라집니다. 먼저 상수를 가리키는 포인터(pointer to constant)입니다.

const int num1 = 10;    // int형 상수
const int *numPtr;      // int형 상수를 가리키는 포인터. int const *numPtr도 같음

numPtr = &num1;
*numPtr = 20;    // 컴파일 에러. num1이 상수이므로 역참조로 값을 변경할 수 없음

먼저 num1이 const int이므로 이 변수의 주소를 넣을 수 있는 포인터는 const int *로 선언해야 합니다. 그리고 num1의 주소를 numPtr에 넣은 뒤 역참조로 값을 변경하려고 해도 num1은 상수이므로 컴파일 에러가 발생합니다. 즉, pointer to constant는 메모리 주소에 저장된 값을 변경할 수 없다는 뜻입니다.

이번에는 포인터 자체가 상수인 상황입니다(constant pointer). 이때는 * 뒤에 const를 붙입니다.

int num1 = 10;    // int형 변수
int num2 = 20;    // int형 변수
int * const numPtr = &num1;    // int형 포인터 상수

numPtr = &num2;    // 컴파일 에러. 포인터(메모리 주소)를 변경할 수 없음

numPtr에 num1의 주소가 들어가 있는 상태에서 다시 num2의 주소를 넣으려고 하면 컴파일 에러가 발생합니다. numPtr은 포인터 자체가 상수이므로 다른 포인터(메모리 주소)를 할당할 수 없습니다. 즉, constant pointer는 메모리 주소를 변경할 수 없다는 뜻입니다.

마지막으로 포인터가 상수이면서 상수를 가리키는 상황입니다(constant pointer to constant). 이때는 포인터를 선언하는 자료형에도 const를 붙이고 * 뒤에도 const를 붙입니다.

const int num1 = 10;    // int형 상수
const int num2 = 20;    // int형 상수
const int * const numPtr = &num1;    // int형 상수를 가리키는 포인터 상수
                                     // int const * const numPtr도 같음

*numPtr = 30;      // 컴파일 에러. num1이 상수이므로 역참조로 값을 변경할 수 없음
numPtr = &num2;    // 컴파일 에러. 포인터(메모리 주소)를 변경할 수 없음
여기서는 numPtr을 역참조한 뒤 값을 변경하려고 해도 num1은 상수이므로 컴파일 에러가 발생합니다. 그리고 numPtr 자체도 상수이므로 num2의 주소를 넣으려고 하면 컴파일 에러가 발생합니다. 즉, constant pointer to constant는 메모리 주소도 변경할 수 없고 메모리 주소에 저장된 값도 변경할 수 없다는 뜻입니다.

*/

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

#include <stdio.h>

int main()
{
    int *numPtr;      // 포인터 변수 선언
    int num1 = 10;    // 정수형 변수를 선언하고 10 저장

    numPtr = &num1;   // num1의 메모리 주소를 포인터 변수에 저장

    *numPtr = 20;     // 역참조 연산자로 메모리 주소에 접근하여 20을 저장

    printf("%d\n", *numPtr);    // 20: 역참조 연산자로 메모리 주소에 접근하여 값을 가져옴
    printf("%d\n", num1);       // 20: 실제 num1의 값도 바뀜

    return 0;
}
