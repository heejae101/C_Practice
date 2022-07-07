/* 포인터 연산하기 
포인터로 선언한 변수에는 메모리 주소가 들어있습니다. 이 포인터 변수에 덧셈이나 뺄셈연산을 하면 어떻게 될까요?
양의 정수에 양의 정수를 더하면 값이 증가하고 빼면 감소합니다. 여기서 메모리 주소가 커지는 상황을 순방향으로 이동 (forward),
메모리 주소가 작아지는 상황을 역방향 이동 (backward)

포인터연산은 포인터 변수에 +- 연산자를 사용하여 값을 더하거나 뺍니다. 또는 ++ -- 가능
*/
#include <stdio.h>

int main()
{
    int numArr[5]= {11,22,33,44,55};
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;

    numPtrB = numPtrA +1;
    numPtrC = numPtrA +2;

    printf("%p\n",numPtrA); //00A3FC00 메모리주소. 컴퓨터마다, 실행할 때 마다 달라짐
    printf("%p\n",numPtrB); //00A3FC04 sizeof(int) * 1이므로 numPtrA에서 4가 증가함
    printf("%p\n",numPtrC); //00A3FC08 sizeof(int) * 2이므로 numPtrA에서 8이 증가함

    return 0;
}
// 뺄셈도 마찬가지 
// ++ -- 는 4씩 증감소 하고 자료형에 따라 short 는 2바이트 char는 1바이트 longlong에서는 8바이트 만큼 포인터 이동

#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;    // 배열 첫 번째 요소의 주소를 포인터에 저장

    numPtrB = numPtrA + 1;    // 포인터 연산. numPtrA + 4바이트
    numPtrC = numPtrA + 2;    // 포인터 연산. numPtrA + 8바이트

    printf("%d\n", *numPtrB);    // 22: 역참조로 값을 가져옴, numArr[1]과 같음
    printf("%d\n", *numPtrC);    // 33: 역참조로 값을 가져옴, numArr[2]와 같음

    return 0;
}

// *(numPtrA +1) 로 간추릴 수 있음 printf("%d\n",*numPtrB); 와도 같음 

#include <stdio.h>

int main()
{
    int numArr[5] = {11,22,33,44,55};
    int *numPtrA;

    numPtrA = numArr;

    printf("%d\n",*(numPtrA+1)); // 22: numPtrA에서 순방향으로 4바이트 만큼 떨어진 메모리에 주소에접근 
    printf("%d\n",*(numPtrA+2)); // 33: numPtrA에서 순방향으로 8바이트 만큼 떨어진 메모리에 주소에 접근

    return 0;
}
// 역참조 연산보다 포인터 연산이 먼저 실행될 수 있도록 괄호로 묶어주는 것

//void 포인터
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *ptr = malloc(100);

    printf("%p\n",ptr);
    printf("%p\n",ptr + 1);

    free(ptr);

    return 0;
}

// void는 자료형의 크기가 정해지지 않기 대문에 연산을 할 수 없습니다.
// 만약 void 포인터로 포인터 연산을 하고 싶다면 다른 포인터로 변환뒤 연산을 하면 됩니다.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *ptr = malloc(100);

    printf("%p\n",ptr);
    printf("%p\n",(int *)ptr + 1);
    printf("%p\n",(int *)ptr - 1);

    void *ptr2 = ptr;
    printf("%p\n",++(int *)ptr2);
    printf("%p\n",--(int *)ptr2);

    printf("%p\n", ((int *)ptr2)++);   // 00FADD20: 다른 포인터로 변환한 뒤 포인터 연산
    printf("%p\n", ((int *)ptr2)--);   // 00FADD24: 다른 포인터로 변환한 뒤 포인터 연산

    free(ptr);

    return 0;
}

#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    void *ptr = &numArr[2];    // 두 번째 요소의 메모리 주소

    printf("%d\n", *(int *)ptr);    // 33: 포인터 연산을 하지 않은 상태에서 역참조

    // void 포인터를 다른 포인터로 변환하여 포인터 연산을 한 뒤 역참조
    printf("%d\n", *((int *)ptr + 1));    // 44
    printf("%d\n", *((int *)ptr - 1));    // 22

    printf("%d\n", *(++(int *)ptr));      // 44
    printf("%d\n", *(--(int *)ptr));      // 33

    printf("%d\n", *(((int *)ptr)++));    // 33
    printf("%d\n", *(((int *)ptr)--));    // 44

    return 0;
}

// 구조체 포인터도 포인터 연산을 할 수 있습니다.
// 다음과 같이 포인터 연산을 한 부분을 ()괄호로 묶어준 뒤 -> 화살표 연산자를 사용하여 멤버에 접근하면 됩니다.
// (포인터 +값 )-> 멤버 (포인터 - 값)->멤버
#include <stdio.h>

struct Data
{
    int num1;
    int num2;
};

int main()
{
    struct Data d[3] = { {10, 20}, {30,40}, {50,60} };
    struct Data *ptr;

    ptr = d;

    printf("%d %d\n",(ptr + 1)->num1, (ptr+1)-> num2);
    printf("%d %d\n",(ptr + 2)->num1, (ptr+2)-> num2);

    return 0;
}

// 이번에는 void 포인터에 구조체 3개 크기 만큼 동적 메모리를 할당한 뒤 포인터 연산을 해보겠습니다.
((struct 구조체이름 *)포인터 + 값)-> 멤버
((struct 구조체이름 *)포인터 + 값)-> 멤버

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
    int num1;
    int num2;
};

int main()
{
    void *ptr = malloc(sizeof(struct Data)* 3);
    struct Data d[3];

    ((struct Data *)ptr)->num1 = 10;
    ((struct Data *)ptr)->num2 = 20;

    ((struct Data *)ptr + 1)->num1 =30;
    ((struct Data *)ptr + 1)->num2 =40;

    ((struct Data *)ptr + 2)->num1 = 50;    // 포인터 연산으로 메모리에 값 저장
    ((struct Data *)ptr + 2)->num2 = 60;    // 포인터 연산으로 메모리에 값 저장
    
    memcpy(d,ptr,sizeof(struct Data)* 3);

    printf("%d %d\n", d[1].num1, d[1].num2);
    printf("%d %d\n", ((struct Data *)ptr + 2)->num1,((struct Data *)ptr + 2)-> num2);

    free(ptr);

    return 0;
}
