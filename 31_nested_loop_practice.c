#include <stdio.h>

// 입력한 값 높이 만큼 별 트리 만들기 
int main()
{
    int count;
    scanf("%d",&count);

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count+i; j++)
        {
            if (j <count-i-1)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
int main()
{
    for (int i = 0; i < 5; i++)    // 5번 반복. 바깥쪽 루프는 세로 방향
    {
        for (int j = 0; j < 5; j++)    // 5번 반복. 안쪽 루프는 가로 방향
        {
            printf("j:%d ", j);        // j값 출력
        }

        printf("i:%d\\n", i);      // i값 출력, 개행 문자 모양도 출력
        printf("\n");              // 가로 방향으로 숫자를 모두 출력한 뒤 다음 줄로 넘어감
    }
    return 0;
}
*/

/* 5X5 별 출력 
int main()
{
    for(int i=0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("*");
        }
        printf("*");
    }
    return 0;
}

#include <stdio.h>

int main()
{
    for (int i = 0; i < 3; i++)    // 3번 반복. 세로 방향
    {
        for (int j = 0; j < 7; j++)   // 7번 반복. 가로 방향
        {
            printf("*");              // 별 출력
        }
        printf("\n");              // 가로 방향으로 별을 다 그린 뒤 다음 줄로 넘어감
    }

    return 0;
}
*/

/* 계단식 별 출력 
include <stdio.h>

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        if (i >= j)
        printf("*");
    }
    printf("\n")
}
*/

/* 대각선으로 별 그리기 
for(int i = 0; i < 5; i++)
{
    for(int j = 0; j < 5; j++)
    {
        if (i == j)
            printf("*");
        else
            printf(" ");
    }
    print("\n")

    return 0;
}*/

