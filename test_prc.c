#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char s1[10];
    char s2[10];

    printf("문자열을 두 개 입력하세요 ");
    scanf("%s %s",s1,s2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    
    scanf("%d",&n);

    int **matrix = malloc(sizeof(int *)* n);

    for(int i = 0; i < n; i++)
    {
        matrix[i]= malloc(sizeof(int)* n);
        memset(matrix[i], 0,sizeof(int) * n);
    } 

    for(int i = 0; i < n; i++)
    {
        matrix [i][i]= 1;
        
        for(int j = 0; j < n; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");

    }

    for(int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int num1 = 0;

    scanf("%d",&num);

    int **m = malloc(sizeof(int *) * num);

    for (int i = 0; i < num; i++)
    {
        m[i] = malloc(sizeof(int)* num);
    }

    for (int i = 0; i < num; i++)
    {
        m[i][num1] = 1;

        for (int j = 0; j < num; j++)
        {
            if (m[i][j] == 1)
            {
                printf("1");
                continue;
            }
            else
            {
                m[i][j] = 0;
                printf("%d",m[i][j]);
            }
        }
        printf("\n");
        num1++;
    }

    for (int i = 0; i < num; i++)
    {
        free(m[i]);
    }

    free(m);

    return 0;
}

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

int num = 0;

for(int i = 0; i < col; i++)
{
    printf("%d",matrix[i][num]);
    num++;
}

/*#include <stdio.h>
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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int numArr[5];
    int smallestNumber;

    scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);

    smallestNumber = numArr[0];

    for (int i = 0; i < sizeof(numArr)/sizeof(int); i++)
    {
        if (numArr[i] < smallestNumber)
        {
            smallestNumber = numArr[i];
        }
    }

    printf ("%d\n",smallestNumber);

    return 0;
}
*/

/*
#include <stdio.h>

int main()
{
    int decimal = 0;
    int binary[4] = {1,1,0,1};
    int position = 0;
    
    for (int i = sizeof(binary) / sizeof(int) - 1; i >= 0; i--)
    {
        if (binary[i] == 1)
            decimal +=1 << position;

        position++;
    }

    printf("%d\n",decimal);

    return 0;
}

#include <stdio.h>

int main()
{
    float scores[10] = {67.2f,67.2f, 84.3f, 97.0f, 87.1f, 71.9f, 63.0f, 90.1f, 88.0f, 79.7f, 95.3f };
    float sum = 0.0f;
    float average;

    for (int i = 0; i < sizeof(scores)/sizeof(float); i++)
    {
        sum += scores[i];
    }
    average = sum / sizeof(scores)/sizeof(float);

    printf("%f\n",average);

    return 0;
}


int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};
    int *numPtr = numArr;

    printf("%d\n", *numPtr); // 11 배열의 주소가 들어가있는 포인터를 역참조하면 배열의 첫번째 요소

    printf("%p\n", numArr); // 11 배열 자체를 역참조해도 배열의 첫번째 요소에 접근
 
    printf("%p\n", numPtr[4]); // 66 배열의 주소가 들어있는 포인터는 인덱스로 접근가능

    printf("%d\n", sizeof(numPtr)); // 4 sizeof로 배열의 주소가 들어있는 포인터 크기를 구하면 포인터의 크기가 됨

    printf("%d\n", sizeof(numArr)); // 40 sizeof로 배열의 크기를 구하면 배열이 메모리에 차지하는 공간이됨

    return 0;
}
*/