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

// 두점사이의 거리는 피타고라스 정리를 이용하여 구한다. sprt 함수를 사용하면 제곱근을 뜻하는 square root에서 따왔으며 math.h헤더 파일에 선언

#include <stdio.h>
#include <math.h> 


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

    int a = p2.x - p1.x;
    int b = p2.y - p2.y;

    double c = sqrt((a*a)+(b*b));

    printf("p1: %d %d \n",p1.x,p1.y);
    printf("p2: %d %d \n",p2.x,p2.y);

    return 0;
}

// sprt 함수에 값을 넣으면 해당 값의 제곱근을 구해줍니다. 제곱근은 소수로 나오므로 double형 변수에 저장해줍니다.
// 거듭제곱(power)을 구하는 pow함수를 사용해도 됩니다. 
// a^2을 구하고 싶다면 pow(a,2)처럼 사용합니다.