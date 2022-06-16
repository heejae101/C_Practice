/* 2차원 배열은 [] 대괄호를 두번 사용하여 선언
첫번째 대괄호는 세로 크기, 두번째 대괄호에는 가로 크기 
일반적으로 2차원 공간은 가로X 세로로 표기하지만 배열로 만들 때는 
세로X 가로로 표기합니다.

자료형 배열이름 [세로크기][가로크기];
자료형 배열이름 [세로크기][가로크기]={{값,값,값},{값,값}}

마찬가지로 가로 세로 크기보다 {} 안의값과 줄의 개수는 작아도 되지만 크면 안됨

int numArr[3][4] = {
    {가로 요소 4개}
    {가로 요소 4개}
    {가로 요소 4개}
}

마찬가지로 배열에 값을 할당하는 방법은 배열을 선언할 때만 사용할 수 있으며 이미 선언된 배열에는 사용할 수 없습니다.

2차원 배열의 요소에 접근하려면 배열 뒤에 [ ] (대괄호)를 두 번 사용하며 [ ] 안에 세로와 가로 인덱스를 지정해주면 됩니다.
*/

#include <stdio.h>

int main ()
{
    int numArr[3][4]={
        {11,22,33,44},
        {55,66,77,88},
        {99,110,121,132}
    };

    printf("d\n",numArr[0][0]);
    printf("d\n",numArr[1][2]);
    printf("d\n",numArr[2][0]);
    printf("d\n",numArr[2][3]);

    return 0;
}

//int numArr[3][4] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132 }; 이렇게작성해도 되지만 이해하기 어려워 잘 사용안한다.

#include <stdio.h>

int main()
{
    int numArr[3][4] = { 0, };       // 2차원 배열의 요소를 모두 0으로 초기화

    printf("%d\n", numArr[0][0]);    // 0: 세로 인덱스 0, 가로 인덱스 0인 요소 출력
    printf("%d\n", numArr[1][2]);    // 0: 세로 인덱스 1, 가로 인덱스 2인 요소 출력
    printf("%d\n", numArr[2][0]);    // 0: 세로 인덱스 2, 가로 인덱스 0인 요소 출력
    printf("%d\n", numArr[2][3]);    // 0: 세로 인덱스 2, 가로 인덱스 3인 요소 출력

    return 0;
}

//값 할당 
#include <stdio.h>

int main()
{
    int numArr[3][4];

    numArr[0][0] = 11;    // 세로 인덱스 0, 가로 인덱스 0인 요소에 값 할당
    numArr[0][1] = 22;    // 세로 인덱스 0, 가로 인덱스 1인 요소에 값 할당
    numArr[0][2] = 33;    // 세로 인덱스 0, 가로 인덱스 2인 요소에 값 할당
    numArr[0][3] = 44;    // 세로 인덱스 0, 가로 인덱스 3인 요소에 값 할당

    numArr[1][0] = 55;    // 세로 인덱스 1, 가로 인덱스 0인 요소에 값 할당
    numArr[1][1] = 66;    // 세로 인덱스 1, 가로 인덱스 1인 요소에 값 할당
    numArr[1][2] = 77;    // 세로 인덱스 1, 가로 인덱스 2인 요소에 값 할당
    numArr[1][3] = 88;    // 세로 인덱스 1, 가로 인덱스 3인 요소에 값 할당

    numArr[2][0] = 99;    // 세로 인덱스 2, 가로 인덱스 0인 요소에 값 할당
    numArr[2][1] = 110;   // 세로 인덱스 2, 가로 인덱스 1인 요소에 값 할당
    numArr[2][2] = 121;   // 세로 인덱스 2, 가로 인덱스 2인 요소에 값 할당
    numArr[2][3] = 132;   // 세로 인덱스 2, 가로 인덱스 3인 요소에 값 할당

    printf("%d\n", numArr[0][0]);    // 11 : 세로 인덱스 0, 가로 인덱스 0인 요소 출력
    printf("%d\n", numArr[1][2]);    // 77 : 세로 인덱스 1, 가로 인덱스 2인 요소 출력
    printf("%d\n", numArr[2][0]);    // 99 : 세로 인덱스 2, 가로 인덱스 0인 요소 출력
    printf("%d\n", numArr[2][3]);    // 132: 세로 인덱스 2, 가로 인덱스 3인 요소 출력

    return 0;
}

//범위 벗어나면? 쓰레기값 출력
#include <stdio.h>

int main()
{
    int numArr[3][4];

    numArr[0][0] = 11;    // 세로 인덱스 0, 가로 인덱스 0인 요소에 값 할당
    numArr[0][1] = 22;    // 세로 인덱스 0, 가로 인덱스 1인 요소에 값 할당
    numArr[0][2] = 33;    // 세로 인덱스 0, 가로 인덱스 2인 요소에 값 할당
    numArr[0][3] = 44;    // 세로 인덱스 0, 가로 인덱스 3인 요소에 값 할당

    numArr[1][0] = 55;    // 세로 인덱스 1, 가로 인덱스 0인 요소에 값 할당
    numArr[1][1] = 66;    // 세로 인덱스 1, 가로 인덱스 1인 요소에 값 할당
    numArr[1][2] = 77;    // 세로 인덱스 1, 가로 인덱스 2인 요소에 값 할당
    numArr[1][3] = 88;    // 세로 인덱스 1, 가로 인덱스 3인 요소에 값 할당

    numArr[2][0] = 99;    // 세로 인덱스 2, 가로 인덱스 0인 요소에 값 할당
    numArr[2][1] = 110;   // 세로 인덱스 2, 가로 인덱스 1인 요소에 값 할당
    numArr[2][2] = 121;   // 세로 인덱스 2, 가로 인덱스 2인 요소에 값 할당
    numArr[2][3] = 132;   // 세로 인덱스 2, 가로 인덱스 3인 요소에 값 할당

    printf("%d\n", numArr[-1][-1]);   // 음수이므로 잘못된 인덱스
    printf("%d\n", numArr[0][4]);     // 가로 인덱스가 배열의 범위를 벗어남
    printf("%d\n", numArr[4][0]);     // 세로 인덱스가 배열의 범위를 벗어남
    printf("%d\n", numArr[5][5]);     // 세로, 가로 인덱스 모두 배열의 범위를 벗어남

    return 0;
}
/*
2차원 배열은 값이 일렬로 쭉 늘어서 있으므로 numArr[0][4]와 같이 가로 인덱스가 범위를 벗어나도록 지정하면 
그다음 세로 인덱스 요소인 numArr[1][0]에 접근하게 됩니다.
*/

/*2차원 배열을 선언한 뒤 배열의 가로, 세로 크기를 늘려야 할 경우 
관련된 반복문의 조건식도 함께 수정해야 하는데 빠뜨리고 넘어갈 수가 있습니다. 
따라서 2차원 배열의 가로, 세로 크기를 구해놓고 반복문에 사용하면 실수를 방지할 수 있습니다.
*/
#include <stdio.h>

int main()
{
    int numArr[3][4] = {    // 세로 크기 3, 가로 크기 4인 int형 2차원 배열 선언
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };

    printf("%d\n", sizeof(numArr));    // 48: 4바이트 크기의 요소가 12(4*3)개이므로 48

    int col = sizeof(numArr[0]) / sizeof(int);    // 4: 2차원 배열의 가로 크기를 구할 때는 
                                                  // 가로 한 줄의 크기를 요소의 크기로 나눠줌

    int row = sizeof(numArr) / sizeof(numArr[0]); // 3: 2차원 배열의 세로 크기를 구할 때는 
                                    // 배열이 차지하는 전체 공간을 가로 한 줄의 크기로 나눠줌

    printf("%d\n", col);    // 4
    printf("%d\n", row);    // 3

    return 0;
}

// 반복문을 이용하여 2차원 배열의 요소를 모두 출력
#include <stdio.h>

int main()
{
    int numArr[3][4] = {
        {11,22,33,44},
        {55,66,77,88},
        {99,110,121,132}
    };

    int col = sizeof(numArr[0]) / sizeof(int);
    int row = sizeof(numArr) / sizeof(numArr[0]);

    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d",numArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 반복문 역순 

#include <stdio.h>

int main()
{
    int numArr[3][4] = {
        {11,22,33,44},
        {55,66,77,88},
        {99,110,121,132}
    };

    int col = sizeof(numArr[0]) / sizeof(int);
    int row = sizeof(numArr) / sizeof(numArr[0]);

    for (int i = row-1; i >= 0; i--)
    {
        for(int j = col-1; j>= 0; j--)
        {
            printf("%d",numArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 2차원 배열에 포인터 넣기
/*
2차원 배열을 포인터에 담으려면 다음과 같이 특별한 방법이 필요합니다.

자료형 (*포인터이름)[가로크기];

설명하면 가로 크기가 4인 배열을 가리키는 포인터라는 뜻입니다.
*/
#include <stdio.h>

int main()
{
    int numArr[3][4] = {    // 세로 3, 가로 4 크기의 int형 2차원 배열 선언
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };

    int (*numPtr)[4] = numArr;

    printf("%p\n", *numPtr); // 002BFE5C: 2차원 배열 포인터를 역참조하면 세로 첫 번째의 주소가 나옴
                             // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%p\n", *numArr); // 002BFE5C: 2차원 배열을 역참조하면 세로 첫 번째의 주소가 나옴
                             // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%d\n", numPtr[2][1]);    // 110: 2차원 배열 포인터는 인덱스로 접근할 수 있음

    printf("%d\n", sizeof(numArr));  // 48: sizeof로 2차원 배열의 크기를 구하면 배열이 메모리에 
                                     // 차지하는 공간이 출력됨

    printf("%d\n", sizeof(numPtr));  // 4 : sizeof로 2차원 배열 포인터의 크기를 
                                     // 구하면 포인터의 크기가 출력됨(64비트라면 8)

    return 0;
}

/*
3차원 배열은 [ ]에 높이, 세로 크기, 가로 크기를 지정하여 선언합니다. 값을 초기화할 때는 면 단위로 중괄호를 묶어주면 편리합니다.
자료형 배열이름[높이][세로크기][가로크기];

3차원 배열에 접근하려면 [ ]를 세 번 사용하여 높이, 세로, 가로 인덱스를 지정해주면 됩니다.

배열[높이인덱스][세로인덱스][가로인덱스];
배열[높이인덱스][세로인덱스][가로인덱스] = 값;

3차원 배열의 높이(깊이), 세로, 가로를 구하는 방법은 다음과 같습니다(보통 높이는 깊이를 뜻하는 depth로 표현).
int depth = sizeof(numArr) / sizeof(numArr[0]);     // 2: 3차원 배열이 차지하는 전체 공간을 
                                                    // 면의 크기로 나눠줌
int row = sizeof(numArr[0]) / sizeof(numArr[0][0]); // 3: 한 면의 크기를 가로 한 줄의 크기로 나눠줌
int column = sizeof(numArr[0][0]) / sizeof(int);    // 4: 가로 한 줄의 크기를 요소의 크기로 나눠줌

3차원 배열을 포인터에 할당하려면 세로x가로로 구성된 면을 가리키는 포인터를 선언하면 됩니다.

자료형 (*포인터이름)[세로크기][가로크기]

int (*numPtr)[3][4] = numArr; 
*/

// 연습문제 행렬의 주대각선 성분 구하기
#include <stdio.h>
int main()
{
    int matrix[8][8] = {
        {  1,  2,  3,  4,  5,  6,  7,  8 },
        {  9, 10, 11, 12, 13, 14, 15, 16 },
        { 17, 18, 19, 20, 21, 22, 23, 24 },
        { 25, 26, 27, 28, 29, 30, 31, 32 },
        { 33, 34, 35, 36, 37, 38, 39, 40 },
        { 41, 42, 43, 44, 45, 46, 47, 48 },
        { 49, 50, 51, 52, 53, 54, 55, 56 },
        { 57, 58, 59, 60, 61, 62, 63, 64 }
    };

    int row = sizeof(matrix[0])/ sizeof(int);
    int col = sizeof(matrix)/ sizeof(matrix[0]);
    int num = 0;

    for(int i =0; i < col; i++)
    {
        printf("%d",matrix[i][num]);
        num++;
    }
    return 0;
}
/* 생각해보니 col만 구하면 됐다.. 
for (int m = 0; m < sizeof(matrix) / sizeof(matrix[0]); m++)
{
    printf("%d ", matrix[m][m]);
}
*/

//심사 문제 정치 행렬
/*
표준 입력으로 5x5 정사각행렬이 입력됩니다. 다음 소스 코드를 완성하여 입력된 행렬의 전치행렬이 출력되게 만드세요.

전치행렬은 왼쪽 위부터 오른쪽 아래까지의 대각선(주대각선)을 기준으로 값을 뒤집은 행렬을 말합니다.

정답에는 밑줄 친 부분에 들어갈 코드만 작성해야 합니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int matrix[5][5];

    scanf("%d %d %d %d %d", 
        &matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3], &matrix[0][4]);
    scanf("%d %d %d %d %d", 
        &matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3], &matrix[1][4]);
    scanf("%d %d %d %d %d", 
        &matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3], &matrix[2][4]);
    scanf("%d %d %d %d %d", 
        &matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3], &matrix[3][4]);
    scanf("%d %d %d %d %d", 
        &matrix[4][0], &matrix[4][1], &matrix[4][2], &matrix[4][3], &matrix[4][4]);
    
    int col = sizeof(matrix)/sizeof(matrix[0]); 
    int row = sizeof(matrix[0])/ sizeof(int);
    int temp = 0;

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            temp = matrix[i][j+1];
            matrix[i][j+1] = matrix[j+1][i];
            matrix[j+1][i] = temp;
            printf("%d",matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
// 사실 값을 바꾸라는 얘기는 없었다.. 심지어 틀렸다.
// 전치 행렬은 (0,0) (1,0) (2,0) (3,0) 이렇게 프린트하기 때문에 실제 값을 바꾸는거 아닌이상은 
// i와 j만 바꿔서 출력하는게 맞는거 같다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int matrix[5][5];

    scanf("%d %d %d %d %d",
        &matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3], &matrix[0][4]);
    scanf("%d %d %d %d %d",
        &matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3], &matrix[1][4]);
    scanf("%d %d %d %d %d",
        &matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3], &matrix[2][4]);
    scanf("%d %d %d %d %d",
        &matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3], &matrix[3][4]);
    scanf("%d %d %d %d %d",
        &matrix[4][0], &matrix[4][1], &matrix[4][2], &matrix[4][3], &matrix[4][4]);

    int col = sizeof(matrix) / sizeof(matrix[0]);
    int row = sizeof(matrix[0]) / sizeof(int);

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            printf("%d ", matrix[j][i]);

        printf("\n");
    }

    return 0;
}
// 이게 정답이지 싶다.