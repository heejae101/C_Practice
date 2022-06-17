/*
회문(palindrome)은 순서를 거꾸로 읽어도 제대로 읽은 것과 같은 단어와 문장을 말합니다. 예를 들면 "level", "SOS", "rotator", "nurses run"과 같은 단어와 문장이 있지요.

그럼 문자열이 회문인지 판별하려면 어떻게 해야 할까요? 먼저 회문을 잘 살펴보면 첫 번째 글자와 마지막 글자가 같습니다. 그리고 안쪽으로 한 글자씩 좁혔을 때 글자가 서로 같으면 회문입니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[30];
    int length;
    bool ispalindrome = true;

    printf("단어를 입력하세요"); 
    scanf("%s",word);

    length = strlen(word);

    for(int i = 0;i < length/2; i++)
    {
        if(word[i] != word[length -1 -i])
        {
            ispalindrome = false;
            break;
        }
    }

    printf("%d\n",ispalindrome);

    return 0;
}
// 회문은 1 회문이 아닐경우 0

/*
N-gram 만들기 문자열에서 N개의 연속된 요소를 추출하는 방법입니다. 만약 "Hello"라는 문자열을 문자(글자) 단위 2-gram으로 추출하면 다음과 같이 됩니다.
He
el
ll
lo
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char text[30] = "hello";
    int length;

    length = strlen(text);

    for (int i = 0; i < length -1; i++)
    {
        printf("%c%c\n",text[i],text[i+1]);

    }
    return 0;
}

// 단어 단위 N-gram 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100]= "this is c language";
    char* tokens[30] = {NULL, };
    int count = 0;

    char* ptr = strtok(text," ");

    while (ptr != NULL)
    {
        tokens[count] = ptr;
        count++;

        ptr = strtok(NULL," ");
    }

    for (int i = 0; i < count - 1; i++)
    {
        printf("%s %s\n",tokens[i],tokens[i+1]);
    }

    return 0;
}

/*
char *ptr = strtok(text, " ");   // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

while (ptr != NULL)            // 자른 문자열이 나오지 않을 때까지 반복
{
    tokens[count] = ptr;       // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
    count++;                   // 인덱스 증가

    ptr = strtok(NULL, " ");   // 다음 문자열을 잘라서 포인터를 반환
}
*/

//연습문제 정수 회문 판별하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    long long num1;
    char text[30];

    printf("정수를 입력하세요: ");
    scanf("%lld", &num1);

    sprintf(text,"%lld",num1);

    int length;
    bool isPalindrome = true;

    length = strlen(text);

    int begin = 0;
    int end = length - 1;
    while (begin < end)
    {
        if (text[begin] != text[end])
        {
            isPalindrome = false;
            break;
        }

        begin++;
        end--;
    }

    printf("%d\n", isPalindrome);

    return 0;
}

//해설  sprint 함수로 num1을 문자열로 반환하여 text에 저장 

// 연습문제 4-gram 만들기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char text[30];
    int length;
    int n = 4;

    scanf("%s", text);

    length = strlen(text);
    if (length < n)
    {
        printf("wrong\n");
    }
    else
    {
        for (int i = 0; i < length-(n-1); i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", text[i + j]);

            printf("\n");
        }
    }

    return 0;
}
// 해설 N-gram의 N이 변수 n으로 선언되어 있고 4가 들어있으므로 n을 활용하여 조건식을 작성

//심사문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char text1[30];
    char text2;

    scanf("%[^\n]s",&text2);

    sprintf(text1,"%s",text2);

    int length;
    bool isPalindrome = true;

    length = strlen(text1);

    for (int i = 0; i < length/2; i++)
    {
        if(text1[i] != text1[length -1 -i])
        {
            isPalindrome = false;
            break;
        }
    }

    printf("%d\n",isPalindrome);

    return 0;
}