/*
지금까지 자료형별로 변수를 하나씩 선언해서 사용했습니다. 변수한두개로 처리하기 힘든상황이 옵니다.
char name[20];
int age;
char address[100];
그런데 한사람의 정보만 저장할 수 있고 여러명의 정보를 저장하려면 변수의 name1 name2 이런식으로 변수이름을 바꾸서 계속 추가해야한다.

c언어는 자료를 체계적으로 관리하기 위해 구조체라는 문법 제공 
*/

struct person
{
    char name[20];
    int age;
    char address[100];
};

// 구조체는 관련 정보를 하나의 의미로 묶을 때 사용합니다. 특히 목적에 맞는 자료형을 만들어서 사용하는데 기본 자료형을 조합하여
// 만든 자료형을 파생형(derived type)이라고 한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct person p1;

    strcpy(p1.name,"홍길동");
    p1.age = 30;
    strcpy(p1.address,"서울시 용산구 한남동");

    printf("이름: %s\n",p1.name);
    printf("나이: %s\n",p1.age);
    printf("주소: %s\n",p1.address);

    return 0;
}

// 구조체 안에 들어있는 변수를 멤버라고 합니다. 그리고 구조체를 정의할 때 } 닫는 중괄호 뒤에는 반드시 ; 세미콜론을 붙여줍니다.

// 구조체 정의와 변수 선언을 동시에 하는 코드

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
}p1;

int main()
{
    strcpy(p1.name,"홍길동");
    p1.age =30;
    strcpy(p1.address,"서울시 용산구 한남동");

    printf("이름: %s\n",p1.name);
    printf("나이: %d\n",p1.age);
    printf("주소: %s\n",p1.address);

    return 0;
}

// 구조체 변수를 선언하는 동시에 초기화하기 
#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct Person p1 = {.name = "홍길동",.age = 30,.address = "서울시 용산구 한남동"};

    printf("이름: %s\n",p1.name);
    printf("나이: %s\n",p1.age);
    printf("주소: %s\n",p1.address);

    struct Person p2 = {"고길동",40,"서울시 서초구 반포동"};

    printf("이름: %s\n",p1.name);
    printf("나이: %s\n",p1.age);
    printf("주소: %s\n",p1.address);

    return 0;
}

/* 구조체 변수를 선언할 때 일일이 struct 키워드를 붙이려니 귀찮다. 키워드를 생략하는 방법은 typedef로 구조체를 정의하면서
별칭(alias)을 지정해주면됩니다.
*/
typedef struct 
{
    /* data */
};

//소스코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Person
{
    char name[20];
    int age;
    char address[100];
}Person;

int main()
{
    Person p1; // 구조체 별칭 person으로 변수 선언

    // 점으로 구조체 맴버에 접근하여 값 할당
    strcpy(p1.name,"홍길동");
    p1.age =30;
    strcpy(p1.address, "서울시 용산구 한남동");

    printf("이름 : %s\n",p1.name);
    printf("나이 : %s\n",p1.age);
    printf("주소 : %s\n",p1.address);

    return 0;
}

/*
typedef struct _Person {    // 구조체 이름은 _Person
    char name[20];             // 구조체 멤버 1
    int age;                   // 구조체 멤버 2
    char address[100];         // 구조체 멤버 3
} Person;                   // typedef를 사용하여 구조체 별칭을 Person으로 정의
*/

//만약 구조체 별칭을 사용하지 않고 구조체 이름을 변수를 선언하고 싶다면 struct _person p1;

/* typedef 는 자료형의 별칭을 만드는 기능 따라서 구조체 뿐만 아니라 모든 자료형의 별칭을 만들수 있음
typedef int myint;
typedef* int PMYINT;

MYINT num1l;
PMYIMT numPtr1;
numPtr1 = &num1;

PMYINT안에 *가 이미 포함되 있어서 이중 포인터가 선언 
PMYINT* numPtr1;
int* *numPtr2;
*/
/* 구조체 태그 
strut 뒤에 붙는 구조체 이름은 원래 구조체 태그라 부릅니다. 나중에 배울 공용체 열거형도 마찬가지로 공용체 태그 열거형 태그라 부릅니다.

struct 태그 {
    자료형 멤버이름;
};

typedef struct 태그 {
    자료형 멤버이름;
}타입이름;

typedef struct Person { //구조체 이름도 Person
    char name[20];
    int age;
    char address[100];
} Person; //typedef로 정의한 타입 이름도 Person
*/

// 익명 구조체 를 사용하면 구조체 이름을 지정하지 않아도 됩니다.
typedef struct 
{
    /* data */
};

// 다음 코드

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[20];
    int age;
    char address[100];
}Person;

int main()
{
    Person p1;

    strcpy(p1.name,"홍길동");
    p1.age = 30;
    strcpy(p1.address,"서울시");

    printf("이름: %s\n", p1.name);
    printf("나이: %s\n", p1.age);
    printf("주소: %s\n", p1.address);

    return 0;
}






