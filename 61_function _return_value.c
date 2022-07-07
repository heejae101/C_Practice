// 반환값은 함수를 정의할 때 반환값의 자료형을 지정해 주고 함수 안에서 return 키워드로 값을 반환한다.
/* 반환값자료형 함수이름()
{
    return 반환값;
}

한가지 중요한 점은 반환값과 자료형이 일치해야한다는 점, 반환값이 정수면 자료형은 정수에 해당하는 int long사용 
실수면 float,double을 써야함.
*/
#include <stdio.h>

int one()
{
    return 1;
}

int main()
{
    int num1;
    num1 = one();
    printf("%d\n",num1);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

float realNumber()
{
    return 1.23123f;
}

bool trurh()
{
    return true;
}

int main()
{
    float num1;
    bool b1;

    num1 = realNumber();
    b1 = trurh();

    printf("%f\n",num1);
    printf("%f\n",num1);

    return 0;
}

// 자료형이 다르다면  (자료형)함수()로 이용하면 된다.

/* 포인터를 반환하려면 반환값 자료형과 함수 이름 사이에 *(애스터 리스크)를 붙여주면 됩니다.
반환값 자료형 *함수이름()
{
    return 반환값;
}
*/
#include <stdio.h>

int *ten() // int 포인터를 반환하는 ten
{
    int num1 = 10; // num1은 함수ten이 끝나면 사라짐

    return &num1; // 함수에서 지역변수의 주소로 반환하는것은 잘못된방법 
}

int main()
{
    int* numPtr;
    numPtr = ten();
    printf("%d\n",*numPtr);
    return 0;
}
// 출력 결과에서 10이 잘 나오는 것은 예제 프로그램이 매우 간단해서 10이 저장된 변수가 덮어 쓰여지지 않았기 때문입니다.
// 포인터를 반환하려면 다음과 같이 malloc 함수로 메모리를 할당한 뒤 반환해야 합니다.

#include <stdio.h>
#include <stdlib.h>

int* ten()
{
    int *numPtr = malloc(sizeof(int)); //int 크기만큼 동적 메모리 할당 
    *numPtr = 10; // 역참조로 10 저장 
    return numPtr; // 포인터 반환. malloc으로 메모리 할당하면 함수가 끝나도 사라지지 않음
}

int main()
{
    int* numPtr;

    numPtr = ten(); // 함수를 호출하고 반환값을 numPtr에 저장

    printf("%d\n",*numPtr); // 10: 메모리 해제하기 전까지 안전함

    free(numPtr); // 다른 함수에서 할당한 메모리라도 반드시 해제해야함

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS //strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일 
#include <string.h> // strcpy 함수가 선언된 헤더 파일

char* helloLiteral() // char 포인터를 반환하는 함수 
{
    char *s1 = "hello, world";

    return s1; // 문자열 hello, world는 메모리에 저장되어 있으므로 사라지지 않음
}

char* helloDynamicMemory() // char 포인터를 반환하는 함수 정의
{
    char *s1 = malloc(sizeof(char)*20);

    strcpy(s1,"hello, world");

    return s1;
}

int main()
{
    char *s1;
    char *s2;

    s1 = helloLiteral();
    s2 = helloDynamicMemory();

    printf("%s\n",s1);
    printf("%s\n",s2);

    free(s2);

    return 0;
}

// 지금까지 자료형을 정해서 값을 받아왔습니다. 자료형에 상관없이 값을 꺼내오고 싶다면 void 포인터를 활용하면 편리합니다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocMemory()
{
    void* ptr = malloc(100);

    return ptr;
}

int main()
{
    char *s1 = allocMemory(); // void 포인터를 char 포인터에 넣어서 문자열처럼 사용 
    strcpy(s1,"Hello, world");// s1에 hello, world! 복사
    printf("%s\n",s1);      
    free(s1); // 동적 메모리 해제

    int* numPtr1 = allocMemory();
    numPtr1[0] = 10;
    numPtr1[1] = 20;
    printf("%d %d\n",numPtr1[0],numPtr1[1]);
    free(numPtr1);

    return 0;
}

// 코드 줄이기  코드를 줄일려면 ptr 변수를 선언하지말고, malloc함수를 호출하면서 바로 반환해도 됩니다.
void* allocMemory()
{
    return malloc(100);
}

// C언어의 함수는 값을 하나만 반환할 수 있습니다. 그럼 인적 정보를 반환값으로 얻오려면 어떻게 해야할까요?

struct 
{
    /* data */
};

#define _CRT_SECURE_NO_WARNINGS  //strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h> // strcpy 함수가 선언된 헤더 파일

struct Person
{
    char name[20];
    int age;
    char address[100];
};

struct Person getPerson() // Person 구조체를 반환하는 getPerson 함수 정의
{
    struct Person p;

    strcpy(p.name,"홍길동");
    p.age = 30;
    strcpy(p.address,"서울시 용산구");

    return p; // 구조체 변수 반환
};

int main()
{
    struct Person p1;

    p1 = getPerson();  // 반환된 구조체 변수의 내용이 p1로 모두 복사됨 

    printf("이름: %s\n",p1.name); // 홍길동
    printf("이름: %s\n",p1.age);
    printf("이름: %s\n",p1.address);

    return 0;
}

// 구조체 크기가 커지면 복사할 공간이 그만큼 더 필요하게 되어 공간이 낭비되므로 비효율적입니다.
// 함수가 끝나면 구조체 변수도 사라집니다. 따라서 & (주소 연산자)로 구조체 변수의 메모리 주소를 반환하면 안됩니다.

#define _CRT_SECURE_NO_WARNINGS // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h> // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h> // malloc,free 함수가 선언된 헤더 파일

struct Person
{
    char name[20];
    int age;
    char address[100];
};

struct Person *allocPerson() // Person 구조체 포인터를 반환하는 allocPerson 함수 정의
{
    struct Person *p = malloc(sizeof(struct Person)); // 구조체 포인터에 동적 메모리 할당.

    strcpy(p->name,"홍길동");
    p->age = 30;
    strcpy(p->address,"서울시 용산구");

    return p;  // 구조체 포인터 반환
}

int main()
{
    struct Person *p1;
    p1 = allocPerson(); // 포인터를 반환하여 p1에 메모리 주소 저장

    printf("이름: %s\n",p1->name);
    printf("나이: %s\n",p1->age);
    printf("주소: %s\n",p1->address);

    free(p1); // 동적 메모리 해제

    return 0;
}

// p1에서 ->(화살표 연산자)로 멤버에 접근할 수 있고, 값을 출력해보면 앞에서 저장한 값들이 잘 출력됩니다.
// allocPerson에서 메모리를 할당한 뒤 메모리 주소가 들어있는 포인터만 반환하여 사용하므로 구조체의 내용을 모두 복사하지 않아서 훨씬 효율적입니다.

#include <stdio.h>

union Box
{
    short candy;
    float snack;
    char doll[8];
};

enum BOX_TYPE {
    BOX_PAPER = 0,
    BOX_WOOD,
    BOX_PLASTIC
};

union Box getBox()
{
    union Box b;
    b.candy = 10;
    return b;
};

enum BOX_TYPE getBoxType()
{
    return BOX_WOOD;
}

int main()
{
    union Box box;
    enum BOX_TYPE boxType();

    printf("%d\n",box.candy);
    printf("%d\n", boxType);

    return 0;
}

// 포인터, 구조체 포인터 반환 부분은 문법이 복잡하므로 반복 학습 하는것이 좋습니다.

// 연습문제 

#include <stdio.h>
#include <stdbool.h>

void getMana()
{
    int mana = 222;
    return mana;
}

void getAttackSpeed()
{
    float attackSpeed = 0.679f;
    return attackSpeed;
}

bool isMelee()
{
    int melee = 1;
    return melee;
}

int main()
{
    int mana;
    float attackSpeed;
    bool melee;

    mana = getMana(); // int 
    attackSpeed = getAttackSpeed(); // float
    melee = isMelee();

    printf("%d\n",mana);
    printf("%d\n",attackSpeed);
    printf("%d\n",melee);

    return 0;
}

// 연습문제 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *getName()
{
    char *str = malloc(sizeof(char)* 20);
    strcpy(str, "Mars");
    return str;
}

int main()
{
    char *name;
    name = getName();
    printf("%s\n",name);
    free(name);

    return 0;
}

// 연습문제 3 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *allocMemory()
{
    void *ptr = malloc(100);
    return ptr;
}

int main()
{
    char *s1;

    s1 = allocMemory();
    strcpy(s1,"Uranus");
    printf("%s\n",s1);
    free(s1);

    return 0;
}
// 함수 allocMemory을 호출하여 반환된 포인터에 문자열을 복사해서 출력하고 있으며 반환된 포인터를 free함수로 해제하고 있습니다.
// 따라서 allocMemory 함수 안에서 malloc함수로 메모리를 할당한 뒤 포인터를 반환해주면 됩니다. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[20];
    int age;
};

struct Person *allocPerson()
{
    struct Person *p = malloc(sizeof(struct Person));
    strcpy(p->name,"Kayle");
    p->age = 22;
    return p;
};

int main()
{
    struct Person *p1;
    p1 = allocPerson();

    printf("%s\n", p1->name);
    printf("%s\n", p1->name);

    free(p1);

    return 0;
}

// 심사 문제 
float getArmor()
{
    return 20.500000;
}

bool hasSlowSkill()
{
    return false;
}

// 심사문제 2 
void *getName()
{
    void *ptr = malloc(100);
    strcpy(ptr,"Neptune");
    return ptr;
}

// 심사문제 3 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

void *allocMemory()
{
    return malloc(100); // 포인터를 반환해도 되고, 바로 반환해도 된다
}

struct Point2D *allocPoint2D()
{
    struct point2D *p = malloc(sizeof(struct Point2D));
    p->x = 90;
    p->y = 75;
    return p;
}
