// 2차원 평면에서 위치를 표현 하려면 x값과 y값이 필요합니다.
#include <stdio.h>

struct Point2D
{
    int x;
    int y;
};

int main()
{
    struct Point2D p1;
    struct Point2D p2;

    p1.x = 30;
    p1.y = 20;

    p2.x = 60;
    p2.y = 50;

    printf("p1: %d %d \n",p1.x,p1.y);
    printf("p2: %d %d \n",p2.x,p2.y);

    return 0;
}

