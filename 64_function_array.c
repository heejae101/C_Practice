/* 함수에서 배열을 매개변수로 사용하면 연속된 값을 전달할 수 있고, 전달한 배열의 요소를 함수 안에서 변경할 수 있습니다.
반환값 자료형 함수 이름(자료형 매개변수[])
반환값 자료형 함수 이름(자료형 *매개변수)
*/

#include <stdio.h>

void printArray(int arr[], int count) // arr[]은 배열의 메모리 주소를 담고 있는 포인터이며 배열의 실제 크기를 알 수 없다.
{
    for(int i = 0; i < count; i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int numArr[10] = {1,2,3,4,5,6,7,8,9,10};

    printArray(numArr, sizeof(numArr)/sizeof(int));

    return 0;
}

// 

#include <stdio.h>

void setElement(int arr[]) 
{
    arr[2] = 300;
}

int main()
{
    int numArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    setElement(numArr); // 배열의 메모리 주소를 전달

    print("%d\n", numArr[2]);

    return 0;
}

// 대괄호 대신 매개변수 포인터로 지정해 보겠습니다.

#include <stdio.h>

void printArray(int* arr, int count) // 1차원 배열은 int* arr과 같이 int형 포인터로 받을 수 있습니다. 물론 포인터로는 배열의 크기를 알 수 없으므로 다른 매개변수를 통해 배열의 크기를 받습니다.
{
    for(int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    print("\n");
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printArray(numArr, sizeof(numArr) / sizeof(int));

    return 0;
}

// arr은 포인터이므로 함수 안에서 배열의 요소를 변경하면 함수 바깥에 있는 배열의 요소가 바뀌게 됩니다. 
#include <stdio.h>

void swapElement(int arr[], int first, int second)
{
    int temp;

    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    swapElement(numArr, 0, 1);

    printf("%d %d\n", numArr[0], numArr[1]);

    return 0;
}

// 함수에 배열을 넘겨줄 때 복합 리터럴을 사용하면 배열을 따로 선언하지 않아도 됩니다. 
#include <stdio.h>

void printArray(int arr[], int count)
{
    for(int i = 0; i < count; i++)
    {
        print("%d" , arr[i]);
    }

    print("\n");
}

int main()
{
    // 복합 리터럴 방식으로 배열을 넘겨줌
    printArray((int[]) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);

    return 0;
}

// 함수 배열 매개변수에서 요소의 최소 개수 지정하기
// 함수의 배열 매개변수에 static과 숫자를 사용하면 요소의 최소 개수를 지정할 수 있습니다.
#include <stdio.h>

void printArray(int arr[static 5], int count) // 배열의 개수를 최소 5개로 설정
{
    for(int i = 0; i < count; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");
}

int main()
{
    int numArr1[5] = { 1, 2, 3, 4, 5};

    printArray(numArr1, sizeof(numArr1) / sizeof(int));

    int numArr2[3] = { 1, 2, 3};

    printArray(numArr2, sizeof(numArr1) / sizeof(int));

    return 0;
}

// 함수에서 2차원 배열을 매개변수로 사용하려면 ()안에서 매개변수 이름 뒤에 [][가로크기]를 두개 붙이고 가로 크기를 지정하거나 괄호로 묶은 포인터 뒤에 []를 붙이고 가로크기를 지정
// 반환값자료형 함수이름(자료형 매개변수[][가로 크기])
// 반환값 자료형 함수이름 (자료형 (*매개변수)[가로 크기])

#include <stdio.h>

void print2DArray(int arr[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d", arr[i][j]);
        }

        print("\n");
    }
}

int main()
{
    int numArr[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };

    int col = sizeof(numArr[0]) / sizeof(int);

    int row = sizeof(numArr) / sizeof(numArr[0]);

    print2DArray(numArr, col, row);

    return 0;
}

// 복합 리터럴 사용하기
// (자료형)[][가로크기]{{값1,값2,값3},{값4,값5,값6}}
// (자료형)[세로크기][가로크기] {{값1,값2,값3}, {값4,값5,값6}}
#include <stdio.h>

void print2DArray(int (*arr)[5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d",arr[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    print2DArray((int[2][5]){{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, 5, 2);

    return 0;
}