/* 공용체라는 특별한 자료형은 구조체와 정의 방법이 같지만 맴버를 저장하는 방식이 다릅니다.
공용체는 맴버 중에서 가장 큰 자료형의 공간을 공유합니다.

union 공용체이름
{
    자료형 맴버이름;
};
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

union Box
{
    short candy;
    float snack;
    char doll[8];
};

int main()
{
    union Box b1;

    printf("%d\n",sizeof(b1));

    strcpy(b1.doll,"bear");

    printf("%d\n",b1.candy);
    printf("%f\n",b1.snack);
    printf("%s\n",b1.doll);

    return 0;
    
}

// 공용체 의 맴버 short 2바이트 float 4바이트 doll[8] 8바이트입니다. 따라서 가장 큰 자료형이 배열이므로 전체 크기는 8입니다.
// 구조체와 달리 공용체는 맴버 중에서 가장 큰 자료형의 공간을 공유합니다. 따라서 어느 한 멤버에 값을 저장하면 나머지 멤버의 값은 사용할 수 없습니다.(쓰레기값이 출력;)'
// 그래서 공용체의 맴버는 한번에 하나씩 쓰면 값을 정상적으로 사용할 수 있습니다.
b1.candy = 10;
printf("%d\n",b1.candy);

b1.snack = 500.0f;
printf("%d\n",b1,snack);

// 구조체로 만들었다면 2+4+8 =14바이트 구조체 맴버 정렬이되면 16바이트 입니다. 공용체로 맴버를 한번에 하나씩만 쓰는 상황이면 8바이트이므로 6바이트 이득입ㄴ디ㅏ.

#include <stdio.h>

union Data
{
    char c1;
    short num1;
    int num2;
};

int main()
{
    union Data d1;

    d1.num2 = 0X12345678; //리틀 엔디언에서는 메모리에 저장될 때 78 56 34 12로 저장됨

    printf("0x%x",d1.num2); // num2 4바이트 전체 값 출력
    printf("0x%x",d1.num1); // 0x5678 앞의 2바이트 값만 출력
    printf("0x%x",d1.c1); // 0x78 앞의 1바이트 값만 출력

    printf("0x%x",sizeof(d1));

    return 0;
}

//우리가 사용하는 x86(x86-64)계열 cpu는 리틀 엔디언이라는 방법으로 값을 저장합니다. 간단하게 리틀 엔디언은 숫자를 1바이트씩 쪼개서 낮은 자릿수가 앞에 옵니다.

/*      0x  12  34  56  78
            78  56  34  12  리틀 엔디언 
        0x  12  34  56  78
            12  34  56  78  빅 엔디언 
*/

/* typedef와 익명 공용체 
typedef union 공용체이름 // 공용체 이름은 _box
{
    자료형 맴버이름;
} 공용체별칭;

typedef union _box {
    short candy;
    float snack;
    char doll[8];
}Box;                  //typedef를 사용하여 공용체 별칭을 Box로 정의

*/

//구조체와 마찬가지로 공용체도 포인터로 선언할 수 있으며 공용체 포인터에는 malloc함수를 사용하여 동적 메모리를 할당할 수 있습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Box
{
    short candy;
    float snack;
    char doll[8];
};

int main()
{
    union Box *b1 = malloc(sizeof(union Box));

    printf("%d\n",sizeof(union Box));

    strcpy(b1->doll,"bear");

    printf("%d\n",b1->candy);
    printf("%d\n",b1->snack);
    printf("%d\n",b1->doll);

    free(b1);

    return 0;
}

// 공용체 별칭과 익명 공용체 포인터에 메모리 할당하기
typedef union _Box
{
    short candy;
    float snack;
    char doll[8];
}Box;

Box *b1 = malloc(sizeof(Box))

// 포인터에 메모리를 할당하지 않고, 공용체 변수를 그대로 활용할 수 있습니다.
union Box
{
    short candy;
    float snack;
    char doll[8];
};

int main()
{
    union Box b1;
    union Box *ptr;

    ptr = &b1;

    strcpy(ptr->doll,"bear");

    printf("%d\n",ptr->candy);
    printf("%d\n",ptr->snack);
    printf("%d\n",ptr->doll);

    return 0 ;
}


