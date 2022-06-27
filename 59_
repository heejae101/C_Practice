/* 포인터 연산하기 
포인터로 선언한 변수에는 메모리 주소가 들어있습니다. 이 포인터 변수에 덧셈이나 뺄셈연산을 하면 어떻게 될까요?
양의 정수에 양의 정수를 더하면 값이 증가하고 빼면 감소합니다. 여기서 메모리 주소가 커지는 상황을 순방향으로 이동 (forward),
메모리 주소가 작아지는 상황을 역방향 이동 (backward)

포인터연산은 포인터 변수에 +- 연산자를 사용하여 값을 더하거나 뺍니다. 또는 ++ -- 가능
*/
#include <stdio.h>

int main()
{
    int numArr[5]= {11,22,33,44,55};
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;

    numPtrB = numPtrA +1;
    numPtrC = numPtrA +2;

    printf("%p\n",numPtrA); //00A3FC00 메모리주소. 컴퓨터마다, 실행할 때 마다 달라짐
    printf("%p\n",numPtrB); //00A3FC04 sizeof(int) * 1이므로 numPtrA에서 4가 증가함
    printf("%p\n",numPtrC); //00A3FC08 sizeof(int) * 2이므로 numPtrA에서 8이 증가함

    return 0;
}
// 뺄셈도 마찬가지 
// ++ -- 는 4씩 증감소 하고 자료형에 따라 short 는 2바이트 char는 1바이트 longlong에서는 8바이트 만큼 포인터 이동

#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;    // 배열 첫 번째 요소의 주소를 포인터에 저장

    numPtrB = numPtrA + 1;    // 포인터 연산. numPtrA + 4바이트
    numPtrC = numPtrA + 2;    // 포인터 연산. numPtrA + 8바이트

    printf("%d\n", *numPtrB);    // 22: 역참조로 값을 가져옴, numArr[1]과 같음
    printf("%d\n", *numPtrC);    // 33: 역참조로 값을 가져옴, numArr[2]와 같음

    return 0;
}

// *(numPtrA +1) 로 간추릴 수 있음 59_2