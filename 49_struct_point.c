/* 구조체 포인터 사용하기 
보통 구조체는 멤버 변수가 여러 개 들어있어서 크기가 큰 편입니다.
그래서 구조체 변수를 일일이 선언해서 사용하는 것 보다는 포인터에 메모리를 할당해서
사용하는 편이 효율적입니다. 

다른자료형과 마찬가지로 구조체도 포인터를 선언할 수 있으며 구조체 포인터에는 malloc함수를 사용하여 동적 메모리 할당할 수 있습니다.
struct 구조체이름*포인터이름 = malloc(sizeof(stuct 구조체이름));
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct Person* p1 = malloc(sizeof(struct Person));

    strcpy(p1 -> name, "홍길동");    //구조체의 맴버에 접근하는 방법은 조금 특이합니다. 원래 점을 이용해서 접근했지만 구조체 포인터는 ->를 사용합니다. 화살표 연산자(arrow operator)
    p1 ->age = 30;
    strcpy(p1 ->address,"서울시");

    //화살표 연산자로 구조체 멤버에 접근하여 값 출력
    printf("이름: %s\n", p1->name);
    printf("나이: %s\n", p1->age);
    printf("주소: %s\n", p1->address);

    free(p1);

    return 0;
}

// 구조체 포인터에서 .으로 맴버에 접근하기 p1 -> age; (*p1).age;

/* 구조체의 맴버가 포인터일때 역참조하기 
구조체의 맴버가 포인터일 때 역참조를 하려면 맨 앞에 *를 붙이면 됩니다. 이때 구조체 변수 앞에 *가 붙어 있더라도 맴버의 역참조이지 구조체 변수의 역참조가 아닙니다.
*/

#include <stdio.h>
#include <stdlib.h>

struct Data
{
    char c1;
    int* numPtr;
};

int main()
{
    int num1 = 10;
    struct Data d1;
    struct Data* d2 = malloc(sizeof(struct  Data));

    d1.numPtr = &num1;
    d2->numPtr =&num1;

    printf("%d\n",*d1.numPtr);
    printf("%d\n",*d2->numPtr);

    d2->c1 = 'a';
    printf("%c\n",(*d2).c1);

    printf("%d\n",*(*d2).numPtr);

    free(d2);

    return 0;
    
}

//역 참조한 것을 괄호로 묶으면 구조체 변수를 역참조한뒤 맴버에 접근한다.
//(* 구조체포인터).맴버
//*(*구조체포인터).맴버
d2->c1 ='a';                //a: 구조체 포인터를 역참조 하여 c1에 접근
printf("%c\n",(*d2).c1);    //d2 -> c1과 같음 
printf("%d\n",*(*d2).numPtr);// 10 : 구조체 포인터를 역참조하여 numPtr에 접근한 뒤 다시 역참조
                             //*d2 -> numPtr과 같음

/* struct 키워드로 포인터를 선언하고 메모리를 할당 했으니 typedef로 정의한 구조체 별칭으로도 포인터를 선언하고 메모리 할당
구조체별칭 *포인터이름 = malloc(sizeof(구조체별칭));
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Person
{
    char name[20];
    int age;
    char address[100];
}Person;

int main()
{
    Person *p1 = malloc(sizeof(Person));

    strcpy(p1->name,"홍길동");
    p1->age =30;
    strcpy(p1->address,"서울시");

    printf("이름: %s\n",p1 -> name);
    printf("나이: %d\n",p1 -> age);
    printf("주소: %s\n",p1 -> address);

    free(p1);

    return 0;

}

// 구조체 별칭을 사용하면 포인터를 선언하고 메모리를 할당하는 방법이 좀 더 간단하빈다. Person *p1과 같이 구조체 별칭으로 
// 포인터를 바로 선언한 뒤 malloc 함수로 메모리를 할당합니다. 이때 할당할 메모리 크기도 sizeof(Person) 처럼 구조체 별칭으로 구하면됨

strcpy(p1->name,"홍길동");
p1->age =30;
strcpy(p1->address,"서울시");

// 구조체 별칭으로 선언한 포인터도 구조체 맴버에 접근할 때는 -> (화살표 연산자)를 사용합니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy 함수가 선언된 헤더파일
#include <stdlib.h> // malloc, free 함수가 선언된 헤더파일 

typedef struct 
{
    char name[20];
    int age;
    char address;
}Person;

int main()
{
    Person *p1 = malloc(sizeof(Person));

    strcpy(p1->name,"홍길동");
    p1->age = 30;
    strcpy(p1->address,"서울시");

    printf("이름 %s\n",p1->name);
    printf("나이 %s\n",p1->age);
    printf("주소 %s\n",p1->address);

    free(p1);

    return 0;

}

// 지금까지 malloc 함수로 구조체 포인터에 동적 메모리를 할당했습니다. 그럼 동적 메모리를 할당하지 않고 구조체
//포인터를 사용하는 방법은 없을까요? 이때는 구조체 변수에 &(주소연산자)를 사용하면됩니다.

#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct Person p1;
    struct Person* ptr;

    ptr = &p1;

    ptr->age = 30;

    printf("나이: %d\n",p1.age);   //나이: 30 : 구조체 변수의 맴버 값 출력
    printf("나이: %d\n",ptr->age); //나이: 30 : 구조체 포인터의 맴버 값 출력 

    return 0;
    
}
