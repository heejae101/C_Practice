/* 지금까지 구조체의 멤버는 각 자료형의 크기만큼 공간을 차지
하지만 구조체 비트 필드를 사용하면 구조체 멤버를 비트 단위로 저장 

cpu나 기타칩의 플레그를 다루는 저수준 프로그래밍을 할 때 기본 자료형보다 더 작은 비트
단위로 값을 가져오거나 저장하는 경우가 많으므로 구조체 비트필드가 유용하게 사용

비트필드로 사용할 수 있는 자료형을 _Bool,signed int, unsigned int, int 로 규정
하지만 대부분의 컴파일러에서는 모든 정수 자료형을 사용가능 
보통은 비트필드에 부호 없는 unsigned 자료형을 주로 사용합니다. 단, 실수 자료형은 비트 필드로 사용불가

struct 구조체이름{
    정수자료형 맴버이름: 비트수;
}
7비트,3비트,1비트 
*/

#include <stdio.h>

struct Flags
{
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 7,
};

int main()
{
    struct Flags f1;

    f1.a = 1; // 1: 0000 0001 비트1개
    f1.b = 15;// 15: 0000 1111 비트 4개
    f1.c = 255; // 127: 1111 1111 비트 8개

    printf("%u\n",f1.a); // 1: 비트 1개만 저장됨
    printf("%u\n",f1.b); // 7: 비트 3개만 저장됨
    printf("%u\n",f1.c); // 127: 111 1111, 비트 7개만 저장이됨

    return 0;
}

// 비트 필드에는 지정한 비트 수만큼 저장되며 나머지 비트는 버려집니다. 
// 비트 필드의 각 멤버는 최하위 비트(Least significant Bit,LSB) 부터 차례대로 배치됩니다. 
// 따라서 a가 최하위 비트에 오고 나머지 멤버들은 각각 상위비트에 배치

/* size 연산자로 Flags 비트 필드 구조체의 크기를 구해보면 4가 나옵니다. 
unsigned int 로 선언했기 때문에 구조체의 크기는 4가 됩니다.

비트 필드 비트 수 제한
unsigned 비트필드의 맴버를 선언하는 자료형보다 큰 비트 수는 저장할 수 없음.
*/

/* 보통 사람이 코드에서 값을 지정할 때는 비트 필드를 사용하지만 cpu나 칩에 값을 설정할 때는 
모든 비트를 묶어서 한꺼번에 저장합니다. 이번에는 비트 필드의 값을 한꺼번에 사용할 수 있도록 비트 필드와 공용체를 함께 사용
*/

#include <stdio.h>

struct Flags
{
    union 
    {
        struct 
        {
            unsigned short a : 3;
            unsigned short b : 2;
            unsigned short c : 7;
            unsigned short d : 4;
        };
        unsigned short e;
    };
};

int main()
{
    struct Flags f1 = {0, };

    f1.a = 4;
    f1.b = 2;
    f1.c = 80;
    f1.d = 15;

    printf("%u\n",f1.e);

    return 0;
}
//  1111   1010000  10  100
//   d       c       b   a

// 연습문제: 구조체로 플래스 비트 필드 만들기
#include <stdio.h>

struct Flags {
    unsigned a : 2;
    unsigned b : 1;
    unsigned c : 6;
};

int main()
{
    struct Flags f1;

    f1.a = 0xffffffff;
    f1.b = 0xffffffff;
    f1.c = 0xffffffff;

    printf("%u %u %u\n", f1.a, f1.b, f1.c);

    return 0;
}

//구조체와 공용체로 플래그 비트 필드 만들기
#include <stdio.h>

struct Flags
{
    union 
    {
        struct 
        {
            unsigned short a : 4;
            unsigned short b : 2;
            unsigned short c : 2;
            unsigned short d : 8;
        };
        unsigned short e;
    };
    
};

int main()
{
    struct Flags f1 = {0, };

    f1.a = 8;
    f1.b = 2;
    f1.c = 2;
    f1.d = 128;

    printf("%u\n",f1.e);

    return 0;
}
