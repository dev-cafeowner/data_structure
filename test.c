#include <stdio.h>
#include <stdlib.h> // exit() 함수를 사용하기 위해 포함

#define MAX_SIZE 100 // 스택의 최대 크기를 100으로 정의

// 스택에 저장될 데이터의 자료형을 'element'라는 별칭으로 정의
// 나중에 데이터 타입을 바꿀 때 이 줄만 수정하면 됨 (유지보수성)
typedef int element; 

element stack[MAX_SIZE]; // 데이터를 저장할 1차원 배열
int top = -1;            // 스택의 최상단 위치를 가리키는 변수 (-1은 비어있음을 의미)

// 스택이 비어있는지 확인하는 함수
int is_empty()
{
    // top이 -1이면 1(true), 아니면 0(false)을 반환
    return (top == -1);
}

// 스택이 가득 찼는지 확인하는 함수
int is_full()
{
    // top이 배열의 마지막 인덱스(MAX_SIZE-1)와 같으면 1(true) 반환
    return (top == MAX_SIZE - 1);
}

// 스택에 데이터를 추가하는 함수
void push(element item)
{
    if (is_full()) // 가득 찼을 때 데이터를 넣으려 하면 에러 발생 (Stack Overflow)
    {
        fprintf(stderr, "스택 포화 에러\n");
    }
    else {
        // top을 먼저 1 증가시킨 후, 그 위치에 데이터를 저장
        stack[++top] = item;
    }
}

// 스택에서 데이터를 꺼내고 반환하는 함수
element pop()
{
    if (is_empty()) // 비어있는데 데이터를 꺼내려 하면 프로그램 강제 종료 (Stack Underflow)
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1); // 비상 정지: 비정상 종료(1) 상태 코드를 OS에 전달
    }
    else {
        // 현재 top 위치의 값을 반환한 후, top을 1 감소시킴 (논리적 삭제)
        return stack[top--];
    }
}

// 스택의 맨 위 데이터를 삭제하지 않고 확인만 하는 함수
element peek()
{
    if (is_empty()) 
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        // top 위치의 값을 읽어오기만 함 (top 변수 값은 변하지 않음)
        return stack[top];
    }
}

int main()
{
    // 데이터 삽입 (LIFO: 10 -> 20 -> 30 순서)
    push(10);
    push(20);
    push(30);

    // 데이터 추출 (LIFO: 마지막에 넣은 30부터 출력됨)
    printf("%d\n", pop()); // 30 출력
    printf("%d\n", pop()); // 20 출력
    printf("%d\n", pop()); // 10 출력
    
    return 0;
}