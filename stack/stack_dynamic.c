#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 스택을 구성하는 데이터와 상태를 하나의 구조체로 묶음
typedef struct {
    element* data; // 스택의 데이터를 저장할 배열
    int top;       // 현재 최상단 데이터의 인덱스
    int capacity;  // 현재 스택의 최대 용량 
} StackType;

// 스택 초기화 함수
void init(StackType *s)
{
    // 포인터를 사용하여 원본 스택 구조체의 값을 직접 수정.
    s->top = -1;
    // 초기에는 1로 시작
    s->capacity = 1;
    s->data = (element*) malloc(s->capacity * sizeof(element));
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
    return (s->top == s->capacity - 1);
}

// 데이터 삽입 함수
void push(StackType *s, element item)
{
    // 스택이 포화 상태인지 확인.
    if (is_full(s)) 
    {
        // 메모리 용량 확대.
        s->capacity *= 2;
        
        // 메모리 용량 재할당
        element* tmp = (element*)realloc(s->data, s->capacity * sizeof(element));
    
        if (s->data == NULL)
        {
            fprintf(stderr, "메모리 할당 에러: 더 이상 확장할 수 없습니다.");
            exit(1);
        }

        s->data = tmp;
    }

    // top의 위치를 변경하고, 데이터 삽입
    s->data[++(s->top)] = item;
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

// 데이터 확인 함수
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

    free(s.data);
    return 0;
}