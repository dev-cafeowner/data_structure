#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100        // 스택의 최대 크기를 100으로 정의

typedef int element;

// 스택을 구성하는 데이터와 상태를 하나의 구조체로 묶음
typedef struct {
    element data[MAX_SIZE]; // 스택의 데이터를 저장할 배열
    int top;                // 현재 최상단 데이터의 인덱스
} StackType;

// 스택 초기화 함수
void init(StackType *s)
{
    // 포인터를 사용하여 원본 스택 구조체의 값을 직접 수정.
    s->top = -1;
}

// 스택 공백 검출 함수
int is_empty(StackType *s)
{
    // C언어 관례상 통일성을 위해 포인터로 받습니다)
    return (s->top == -1);
}

// 스택 포화 검출 함수
int is_full(StackType *s)
{
    return (s->top == MAX_SIZE - 1);
}

// 데이터 삽입 함수
void push(StackType *s, element item)
{
    if (is_full(s)) 
    {
        fprintf(stderr, "스택 포화 에러\n");
    }
    else 
    {
        // 화살표(->) 연산자로 구조체 멤버에 접근.
        s->data[++(s->top)] = item;
    }
}

// 데이터 추출 함수
element pop(StackType *s)
{
    if (is_empty(s)) 
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else 
    {
        // 값을 반환한 뒤 top을 1 감소.
        return s->data[(s->top)--];
    }
}

element peek(StackType *s)
{
    if (is_empty(s)) 
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else 
    {
        // top을 감소시키지 않고 값만 반환.
        return s->data[s->top];
    }
}

int main()
{
    // 스택 구조체 변수 선언 (이 단계에서는 top에 쓰레기 값이 들어있음)
    StackType s; 

    // 스택 사용 전 반드시 초기화 함수를 호출해야 함.
    // 원본 데이터를 넘겨주기 위해 주소 연산자(&)를 사용.
    init(&s);

    // 함수를 호출할 때마다 '어떤 스택'에 작업할 것인지 주소를 넘겨줍니다.
    push(&s, 10);               // 10 삽입
    push(&s, 20);               // 20 삽입
    push(&s, 30);               // 30 삽입

    printf("%d\n", pop(&s));    // 30 추출
    printf("%d\n", pop(&s));    // 20 추출
    printf("%d\n", pop(&s));    // 10 추출

    return 0;
}