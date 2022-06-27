/* 열거형은 상수에 이름을 붙여서 코드를 이해하기 쉽게해줌 
다음과 같이 ValueA , ValueB 라는 정수형 상수를 선언한다면 
개수가 많아지면 일일이 선언하기 귀찮아집니다.
열거형을 이용하면 편히 정의할 수 있습니다.

enum 열거형이름 {
    값1 = 초깃값,
    값2,
    값3
}

열거형으로 요일을 정의 */
#include <stdio.h>

enum DayOfWeek
{
    sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{
    enum DayOfWeek week;

    week = Tuesday;  // 2

    printf("%d\n",week);

    return 0;
}

//열거형의 값은 처음에만 할당해주면 그 아래 오는 값들은 1씩 증가하면서 자동할당 됩니다.
//아무값도 할당 안하면 0부터 시작

/* 열거형 이름과 규칙은 아니지만 열거형 이름이나 값을 정의할 때 대문자만 사용하는 경우가 많습니다. 
특히 단어와 단어 사이에는 _을 주로 사용합니다. 리눅스 커널의 hdmi.h 헤더 파일에 정의된 열거형인데 열거형 이름은 모두 소문자지만
열거형 값이 모두 대문자입니다.

enum hdmi_content_type{
    HDMI_CONTENT_TYPE_GRAPHICS,
    HDMI_CONTENT_TYPE_PHOTO,
    HDMI_CONTENT_TYPE_CIEMA,
    HDMI_CONTENT_TYPE_GAME,
};

다음은 Window 커널의 winddk.h 헤더 파일에 정의된 열거형입니다. 여기서는 열거형 이름이 모두 대문자이고 열거형 값은 단어의 첫글자만 대문자로 되어있습니다.

typedef enum _POOL_TYPE {
    NonPagedPool,
    PagedPool, ...
}

모든 열거형 값에 정수 할당하기
enum Value {
    ValueA = 1;
    ValueB = 3;
    ValueC = 7;
};

typedef와 익명 열거형 
typedef enum 열거형 이름 {
    값1 = 초깃값,
    값2,
    값3
};
*/
// 열거형은 switch 분기문을 사용할 때 유용합니다.
switch (열거형 변수)
{
case 열거형 값:
    실행할 코드;
    break;

default:
    break;
}

#include <stdio.h>

enum Luxskill{
    LightBinding = 1,
    prismaticBarrier,
    LucentSingularity,
    FinalSpark
};

int main()
{
    enum LuxSkill skill;
    skill = LightBinding;

    switch (skill)
    {
    case LightBinding:
        printf("LightBinding\n");
        break;
    case PrismaticBarrier:
        printf("PrismaticBarrier\n");
        break;
    default:
        break;
    }

    return 0;
}

// 열거형 for에 활용하기

#include <stdio.h>

typedef enum _DayOfWeek{
    sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    DayOfWeekCount
}DayOfWeek;

int main()
{
    for (DayOfWeek i = sunday; i < DayOfWeekCount; i++)
        printf("%d\n",i);

    return 0;
}

