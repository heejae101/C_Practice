// 자료형 변환하기

int num1 = 10;
unsigned int num2 = num1; // int와 unsigned int는 자료형이 같음
long long num3 = num1; // long long이 int 보다 큼 

// 자료형이 다르면서 크기가 작은 쪽, 표현 범위가 좁은 쪽으로 저장하면 컴파일 경고가 발생

// 실수에서 소수점 이하 자리를 버리는 기능을 구현하고자 실수를 정수로 저장했을 때 프로그래머가 의도한 상황
float num1 = 3.56f;
int num2 = num1; //실수형 값을 정수형 변수에 저장하여 컴파일 경고 발생

/* 자료형의 크기가 큰 쪽, 표현범위가 넓은 족으로 자동 변환되는것을 형 확장이라고 하고,
이런 변환을 암시적 형변환이라고 합니다. 반대로 자료형 크기가 작은쪽, 표현범위가 좁은 쪽으로 변환되는 것이 형 축소입니다.
이때 형 축소에서 컴파일 경고가 나오지 않도록 만드는 것을 형변환(type conversion, type casting, 타입캐스팅)이라 합니다.

자료형을 지정하여 변환하는것을 명시적 자료형 변환(explicit type conversion, type casting)이라고 하며 변수나 값 앞에 변환할 자료형을 
붙인뒤 ()괄호로 묶어주면 됩니다.
*/
#include <stdio.h>

int main()
{
    int num1 = 32;
    int num2 = 7;
    float num3;

    num3 = num1 / num2;     //컴파일 경고 발생
    printf("%f\n",num3);    // 4.000000

    num3 = (float)num1 / num2 ; //num1을 float로 변환
    printf("%f\n",num3);        // 4.571429

    return 0;
}

// 포인터 변환하기
// 포인터끼리 변환하는 방법입니다. 이때는 자료형 뒤에 포인터를 나탄는 *(애스터리스크)를 붙여주고 괄호로 묶어줍니다.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numPtr = malloc(sizeof(int));
    char *cPtr;

    *numPtr = 0x12345678;

    cPtr = (char *)numPtr;

    printf("0x%x\n",*cPtr);

    free(numPtr);

    return 0;

}

// 결과 0x78
// char 포인터로 변환하여 메모리 주소를 저장했습니다.  즉 char 포인터이므로 1바이트만큼만 값을 가져옵니다.
// 0x12345678을 리틀 엔디언으로 저장하면 78 56 34 12 이므로  0X78이 됩니다.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    short *numPtr1 = malloc(sizeof(short));
    int *numPtr2;

    *numPtr1 = 0X1234;

    numPtr2 = (int *)numPtr1;
    printf("0x%x\n",*numPtr2);

    free(numPtr1);

    return 0;
}

// 이번에는 numptr1에 2바이트 크기로 메모리를 할당하고 역참조하여 0x1234를 저장했습니다. 
// numPtr2 = (int *)numPtr1; 같이 short포인터를 int 포인터로 변환하여 메모리 주소를 저장했습니다.
// 크기가 작은 메모리를 할당한 뒤 큰 자료형의 포인터로 역참조하면 옆의 메모리 공간을 침법하여 값을 가져오게 됩니다.

/* 0x1234를 리틀 엔디언으로 저장하면
 34  12  ??   ??이므로  malloc 함수로 2바이트만큼 메모리를 할당했으므로 0x1234 만 저장되었습니다. 4바이트 int 크기만큼 값을 가져오면 2바이트만큼 값을 가져오면
 2바이트 크기를 벗어나서 malloc함수로 할당하지 않는 공간까지 가져오게됩니다.

 일반 변수와 마찬가지로 포인터도 반환할 때 자료형이 다르면 컴파일 경고가 발생합니다.
 int *numPtr = malloc(sizeof(int));
 char *cPtr;
 cPtr = numPtr;
 free(numPtr);

*(자료형 *)포인터 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numPtr = malloc(sizeof(int));
    char *cPtr;

    *numPtr = 0x12345678;

    print("0x%x\n",*(char *)numPtr);

    free(numPtr);

    return 0;
}

// void 포인터 변환하기
// void 포인터는 자료형이 정해져 있지 않으므로 역참조 연산을 할 수 없습니다.
// 하지만 void 포인터를 다른 자료형으로 반환하면 역참조를 할 수 있습니다. 

#include <stdio.h>

int main()
{
    int num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';
    void *ptr;

    ptr = &num1;
    print("%d\n",*(int *)ptr);

    ptr = &num2;
    printf("%f\n",*(float * )ptr);

    ptr = &c1;
    printf("%c\n",*(char *)ptr);

    return 0;
}

/* 자료형 변환을 주로 사용하는 상황은 구조체 포인터를 변환할 때입니다.
(struct 구조체 이름 *)포인터 
((struct 구조체이름 *)포인터)-> 맴버
*/
#include <stdio.h>
#include <stdlib.h>

struct Data
{
    char c1;
    int num1;
};

int main()
{
    struct Data *d1 = malloc(sizeof(struct Data));
    void *ptr;

    d1->c1 = 'a';
    d1 -> num1 = 10;

    ptr = d1;  // void 포인터에 d1 할당. 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.

    printf("%c\n",((struct Data *)ptr)->c1);  //'a' : 구조체 포인터로 변환하여 멤버에 접근 
    printf("%d\n",((struct Data *)ptr)->num1); // 10 : 구조체 포인터로 변환하여 멤버에 접근

    free(d1); // 동적메모리 해제

    return 0;
}
// ptr은 void 포인터라 Data 구조체의 형태를 모르는 상태이므로 ((struct Data *)ptr)-> c1 구조체 포인터로 변환하여 멤버에 접근

/* typedef로 구조체 포인터 별칭을 정의하는 방법 
typedef를 사용하면 구조체 별칭 뿐만아니라 구조체 포인터 별칭도 정의할 수 있습니다.
typedef struct 구조체 이름{
    자료형 멤버이름;
}구조체 별칭, *구조체 포인터 별칭;
*/

#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

typedef struct _Data {
    char c1;
    int num1;
} Data, *PData;     // 구조체 별칭, 구조체 포인터 별칭 정의

int main()
{
    PData d1 = malloc(sizeof(Data));    // 구조체 포인터 별칭으로 포인터 선언
    void *ptr;   // void 포인터 선언

    d1->c1 = 'a';
    d1->num1 = 10;

    ptr = d1;    // void 포인터에 d1 할당. 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.

    printf("%c\n", ((Data *)ptr)->c1);     // 'a' : 구조체 별칭의 포인터로 변환
    printf("%d\n", ((PData)ptr)->num1);    // 10  : 구조체 포인터 별칭으로 변환

    free(d1);    // 동적 메모리 해제

    return 0;
}