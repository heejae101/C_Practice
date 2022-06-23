//구조체도 변수를 선언하거나 메모리를 할당하면 결국 메모리 공간을 차지하게 되므로 
//메모리 관련된 함수도 사용할 수 있게됩니다. 구조체와 메모리에 값을 설정하는 방법과 구조체와 메모리의 내용을
//복사하는 방법을 알아보겟습니다.

//구조체 변수를 선언할 때 {0, }처럼 중괄호를 사용하여 0으로 초기화 할 수 있지만 변수에만 사용할 수 있고,
//malloc 함수로 할당한 메모리에는 사용할 수 없습니다.
struct 구조체이름 변수이름 = {0, };

// 일일이 맴버에 값을 설정하거나 중괄호를 사용하지 않고 구조체 변수나 메모리의 내용을 한꺼번에 값을 설정하려면
// memset 함수를 사용하면 됩니다.

//memset(구조체 포인터,설정할값,sizeof(struct 구조체));

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Point2D {
    int x;
    int y;
}

int main()
{
    struct Point2D p1;

    memset(&p1,0,sizeof(struct point2D));

    printf("%d %d\n",p1.x,p1.y);

    return 0;

}

//metset 함수로 메모리에 값을 설정할 때는 포인터를 그대로 넣어줍니다. 왜냐하면 포인터는 안에 메모리 주소를 담고 있으므로 &를 사용하지 않아도 됩니다.

//매번 내용이 같은 구조체를 만드려면 상당히 번거롭습니다. 이미 생성하여 값을 저장한 구조체나 메모리를 다른 곳에 복사할 경우가 있다.
//memcpy함수를 이용하여 메모리의 내용을 다른곳으로 복사할 수 있습니다.

#include <stdio.h>
#include <string.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D p1;
    struct Point2D p2;

    p1.x = 10;
    p1.y = 20;

    memcpy(&p2,&p1,sizeof(struct Point2D));

    printf("%d %d\n",p2.x,p2.y);

    return 0;
}

// 이번에는 malloc 함수로 할당한 동적 메모리 끼리 복사하는 방법입니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D *p1 = malloc(sizeof(struct Point2D));
    struct Point2D *p2 = malloc(sizeof(struct Point2D));

    p1->x = 10;
    p1->y = 20;

    memcpy(p2,p1,sizeof(struct Point2D));

    printf("%d %d\n",p2->x,p2->y);

    free(p2);
    free(p1);

    return 0;
}

struct Point2D p1;
struct Point2D* p2 = malloc(sizeof(struct Point2D));

memcpy(p2,&p1,sizeof(struct Point2D));

// 구조체 변수에 동적 메모리로 내용복사 가능
