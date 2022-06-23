// 2차원 좌표를 10개를 만들어야한다
struct Point2D
{
    int x;
    int y;
};

struct Point2D p1;
struct Point2D p2;

//이런식으로 여러번 선언해야한다 .. 하지만 구조체도 배열로 만든다면 쉽다..

struct Point2D p[3000];

//구조체 배열은 변수 이름 뒤에 []대괄호를 붙인 뒤 크기를 설정합니다.

#include <stdio.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D p[3];

    p[0].x = 10;
    p[0].y = 20;
    p[1].x = 30;
    p[2].y = 40;

    printf("%d %d\n",p[0].x,p[0].y);
    printf("%d %d\n",p[1].x,p[1].y);
    printf("%d %d\n",p[2].x,p[2].y);

    return 0;
}

// 구조체 배열을 선언하는 동시에 초기화 하기
/* struct 구조체이름 변수이름[크기] = {{.멤버이름1 = 값1,.맴버이름2 = 값2},{.멤버이름1 = 값3,.맴버이름2= 값4}};
struct 구조체이름 변수이름[크기] = {{값1,값2},{값3,값4}};
*/

#include <stdio.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D p1[3]= {{.x = 10, .y = 20}, {.x = 30, .y= 40}};

    printf("%d %d \n",p1[0].x,p1[0].y);
    printf("%d %d \n",p1[1].x,p1[1].y);
    printf("%d %d \n",p1[2].x,p1[2].y);

    struct Point2D p2[3] = {{10,20},{30,40},{50,60}};

    printf("%d %d \n",p2[0].x,p2[0].y);
    printf("%d %d \n",p2[1].x,p2[1].y);
    printf("%d %d \n",p2[2].x,p2[2].y);

    return 0;
    
}
// 만약 모든요소의 맴버를 0으로 초기화하고 싶다면 구조체 배열을 선언하면서 { 0, };을 할당하면됩니다.

/* 구조체 요소가 한꺼번에 뭉쳐져 있는 배열이 아닌 요소마다 메모리를 할당하고 싶을 수도 있다.
이때는 구조체 포인터 배열을 만들고 malloc 함수로 각 요소에 메모리를 할당하면 됩니다.

구조체 포인터 배열은 포인터 변수 이름 뒤에 []를 붙인 뒤 크기를 설정합니다.

struct 구조체이름 *포인터이름 [크기];
*/

#include <stdio.h>
#include <stdlib.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D *p[3];

    for (int i = 0; i < sizeof(p) / sizeof(struct Point2D *); i++)
    {
        p[i]= malloc(sizeof(struct Point2D *));
    }

    p[0] -> x =10;
    p[0] -> x =10;
    p[1] -> x =10;
    p[1] -> x =10;
    p[2] -> x =10;
    p[2] -> x =10;
    
    printf("%d %d\n",p[0]->x, p[0]->y);
    printf("%d %d\n",p[0]->x, p[0]->y);
    printf("%d %d\n",p[0]->x, p[0]->y);

    for (int i= 0; i < sizeof(p) / sizeof(struct Point2D *); i++) // sizeof(struct Point2D)는 구조체가 차지하는 크기, sizeof(struct Point2D *)는 구조체 포인터의 크기
    {
        free(p[i]);
    }

    return 0;
}

//구조체 포인터 배열에서 각 요소에 접근하려면 배열 뒤에 [] 대괄호를 사용하며 대괄호 안에 인덱스를 지정해 주면 됨

//심사문제 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct Point2D {
    int x;
    int y;
};

int main()
{
    struct Point2D p[4];
    double length = 0.0f;

    scanf("%d %d %d %d %d %d %d %d", 
        &p[0].x, &p[0].y, &p[1].x, &p[1].y,& p[2].x, &p[2].y, &p[3].x, &p[3].y
    );

    for (int i = 0; i < sizeof(p)/sizeof(struct Point2D)-1;i++)
    {
        int a = p[i+1].x - p[i].x;
        int b = p[i+1].y - p[i].y;

        length += sqrt((a*a)+(b*b));
    }

    printf("%f\n", length);

    return 0;
}

// 입력 10 10 20 20 30 30 40 40
// 결과 42.426407

//심사문제 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person *p[5];

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        p[i] = malloc(sizeof(struct Person *));
        scanf("%s %d",p[i]->name,p[i]->age);
    }

    int age = 0;

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        if (p[i]-> age > age)
        {
            age = p[i]->age;
        }
        free(p[i]);
    }

    printf("%s\n",p[age]->name);
    return 0;
}