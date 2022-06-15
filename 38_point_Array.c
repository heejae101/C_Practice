// 지금까진 크기가 고정된 배열을 사용했다. 이번엔 포인터에 메모리를 할당하여 배열로 사용

#define _CRI_SECUER_NO_WARNING
#include <stdio.h>

int main()
{
    int size;

    scanf("%d",&size);

    int numArr[size];

    return 0;
}

/* 포인터를 배열처럼 사용하는 방법 포인터에 malloc 함수로 메모리를 할당 해주면 된다.
자료형 *포인터이름 = malloc(sizeof(자료형) * 크기);
*/
#include <stdio.h>

int main()
{
    int *numPtr = malloc(sizeof(int)*10);

    numPtr[0] = 10;
    numPtr[9] = 20;

    printf("%d\n", numPtr[0]);
    printf("%d\n", numPtr[9]);

    free(numPtr);

    return 0;
}

/*
int *numPtr = malloc(sizeof(int) * 10);과 같이 int 크기에 10을 곱하여 동적으로 메모리를 할당합니다(sizeof(int)를 곱하지 않으면 배열처럼 사용할 수 없습니다). 
그리고 배열처럼 [ ] 안에 인덱스를 지정하여 값을 할당하거나 가져올 수 있습니다. 
즉, 배열과 메모리가 할당된 포인터는 생성 방법만 다를 뿐 값을 다루는 방법은 같습니다.
*/

// 사용자가 입력한 크기만큼 메모리를 할당하여 배열처럼 사용해보겠습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    scanf("%d",&size);

    int *numPtr = malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\n",numPtr[i]);
    }

    free(numPtr);

    return 0;
}

/*포인터에 할당된 메모리를 2차원 배열처럼 사용
자료형 **포인터이름 = malloc(sizeof(자료형 *) * 세로크기);와 같이 세로 공간 메모리 할당
반복문으로 반복하면서 포인터[i] = malloc(sizeof(자료형) * 가로크기);와 같이 가로 공간 메모리 할당
반복문으로 반복하면서 free(포인터[i]);와 같이 가로 공간 메모리 해제
free(포인터);와 같이 세로 공간 메모리 해제
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **m = malloc(sizeof(int *)* 3);// 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼

    for (int i = 0; i < 3; i++)
    {
        m[i] = malloc(sizeof(int)*4);
    }

    m[0][0] = 1;
    m[2][0] = 5;
    m[2][3] = 2;

    printf("%d\n",m[0][0]);
    printf("%d\n",m[2][0]);
    printf("%d\n",m[2][3]);

    for (int i = 0; i < 3; i++)
    {
        free(m[i]);
    }

    free(m);

    return 0;
}

// 입력한 크기 만큼 메모리를 할당하여 포인터를 2차원배열로 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
    
    scanf("%d %d",&row,&col);

    int **m = malloc(sizeof(int *) * row);

    for (int i = 0; i < row; i++)
    {
        m[i] = malloc(sizeof(int) * col);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m[i][j] = i+j;
        }
    }

    for (int i = 0; i <row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d",m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        free(m[i]);
    }

    free(m);

    return 0;
}

//연습문제 포인터에 할당된 메모리 3차원 배열
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long ***m = malloc(sizeof(long long **) * 2);

    for (int depth = 0; depth < 2; depth++)
    {   
        m[depth] = malloc(sizeof(long long *) * 3);

        for (int row = 0; row < 3; row++)
        {
        m[depth][row] = malloc(sizeof(long long) * 5);
        }
    }


    for (int depth = 0; depth < 2; depth++)
    {
        for (int row = 0; row < 3; row++)
        {
            free(m[depth][row]);
        }

        free(m[depth]);
    }

    free(m);
    return 0;
    
}

/*표준 입력으로 정사각행렬의 크기가 입력됩니다(입력 값의 범위는 2~10). 입력된 크기만큼의 단위행렬을 출력하는 프로그램을 만드세요(scanf 함수 호출 전에 문자열을 출력하면 안 됩니다). 숫자와 숫자 사이는 공백으로 띄웁니다.

단위행렬은 왼쪽 위부터 오른쪽 아래까지의 대각선(주대각선)이 1이며 나머지는 모두 0인 행렬입니다.

정답에는 C 언어 컴파일러에서 정상적으로 컴파일되는 전체 코드를 입력해야 합니다.
*/
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
// 이런식으로 코드를 짯는데 이거보다 줄이란다..
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

// 지뢰 찾기 심사 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m, n;
    int i, j;

    scanf("%d %d", &m, &n);

    char **matrix = malloc(sizeof(char *) * m); // char* 형 세로 공간 메모리 할당

    for (i = 0; i < m; i++)
    {
        matrix[i] = malloc(sizeof(char) * (n + 1)); // char 형 가로 공간 메모리 할당
        memset(matrix[i], 0, sizeof(char) * (n + 1)); // 배열 0으로 초기화
    }

    for (i = 0; i < m; i++)
    {
        scanf("%s", matrix[i]); // 한 줄씩 문자열 입력받기
    }

    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) // m,n 만큼 반복하며 모든 요소를 검사
        {
            if (matrix[i][j] == '*') // 요소가 *이면 그대로 출력하고 continue
            {
                printf("%c", matrix[i][j]);
                continue;
            }

            else // 요소가 *이 아니면 요소 주변 8개를 탐색
            {
                matrix[i][j] = 0;

                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x<0 || x>=n || y<0 || y>=n)
                            continue;

                        else if (matrix[x][y] == '*')
                            matrix[i][j] += 1; // 요소 주변 8개 중 지뢰가 발견될 때마다 요소를 1씩 증가시킴
                    }

                }                         
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) // 가로 공간 메모리 해제
        free(matrix[i]);

    free(matrix); // 세로 공간 메모리 해제

    return 0;

}