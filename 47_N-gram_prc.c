/*
ȸ��(palindrome)�� ������ �Ųٷ� �о ����� ���� �Ͱ� ���� �ܾ�� ������ ���մϴ�. ���� ��� "level", "SOS", "rotator", "nurses run"�� ���� �ܾ�� ������ ������.

�׷� ���ڿ��� ȸ������ �Ǻ��Ϸ��� ��� �ؾ� �ұ��? ���� ȸ���� �� ���캸�� ù ��° ���ڿ� ������ ���ڰ� �����ϴ�. �׸��� �������� �� ���ھ� ������ �� ���ڰ� ���� ������ ȸ���Դϴ�.
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

    printf("�ܾ �Է��ϼ���"); 
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
// ȸ���� 1 ȸ���� �ƴҰ�� 0

/*
N-gram ����� ���ڿ����� N���� ���ӵ� ��Ҹ� �����ϴ� ����Դϴ�. ���� "Hello"��� ���ڿ��� ����(����) ���� 2-gram���� �����ϸ� ������ ���� �˴ϴ�.
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

// �ܾ� ���� N-gram 
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
char *ptr = strtok(text, " ");   // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ

while (ptr != NULL)            // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
{
    tokens[count] = ptr;       // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
    count++;                   // �ε��� ����

    ptr = strtok(NULL, " ");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
}
*/

//�������� ���� ȸ�� �Ǻ��ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    long long num1;
    char text[30];

    printf("������ �Է��ϼ���: ");
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

//�ؼ�  sprint �Լ��� num1�� ���ڿ��� ��ȯ�Ͽ� text�� ���� 

// �������� 4-gram �����

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
// �ؼ� N-gram�� N�� ���� n���� ����Ǿ� �ְ� 4�� ��������Ƿ� n�� Ȱ���Ͽ� ���ǽ��� �ۼ�

//�ɻ繮��
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