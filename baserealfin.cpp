#include <stdio.h>      //ㅐPRINTF, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>    // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>   // time 함수를 사용하기 위해서 헤더 추가

int main(void)      //프로그램을 실행하는 main 함수
{                   //메인함수의 시작
    int ball[3]; // 3개의 난수 저장 배열
    srand(time(NULL)); // 난수 초기화
    // 중복 없는 3자리 난수 생성
    do {
        ball[0] = rand() % 10; //랜덤값 설정
        ball[1] = rand() % 10; //랜덤값 설정
        ball[2] = rand() % 10; //랜덤값 설정
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]); //서로 다른 값이 배정되도록 반복

    

    int input[3]; //input에 입력하는값 설정
    int strike_count = 0 ; //strike count 0으로설정
    int ball_count = 0 ; //ball count 0으로설정
    int out_count = 0; //out count 0으로 설정
    int try_count = 0; //trycount 0으로 설정 

    clock_t start, end; //시간 시작과종료 설정
    start = clock(); // 게임 시작 시간 기록

    while (1) {   //반복문시작
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): "); //입력한 숫자 출력
        scanf("%d %d %d", &input[0], &input[1], &input[2]); //입력한 숫자 분석

        strike_count = 0; //strikecount 0으로 초기화
        ball_count = 0;  //ballcount 0으로 초기화

        // strike, ball 판정
        for (int i = 0; i < 3; i++) { //int i를 0으로 설정하고 3보다 작게 차례차례 증가
            if (input[i] == ball[i]) { //input i가 ball i와 같다면 strike count증가
                strike_count++; //strike 증가
            } else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3]) { //input i가 다른위치의 값과 같으면 ball count증가
                ball_count++;  //ball증가
            } //if else 종료
        }  //for종료

        out_count = 3 - (strike_count + ball_count); //strike와 ball을 합친숫자로 out카운트 3에서 뺌
        
        try_count++; //시도횟수 증가

        if (strike_count == 3) {  //strike가 3일때
            end = clock(); // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC; //측정시간 초로 변환
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count); //홈런 및 횟수 출력
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec); //걸린 시간 출력
            break;  //멈춤
        } else { //다른경우
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count); //stike ball out 의 count출력
        } //if else문 종료
    } //반복 종료
    return 0; //종료
}  //메인문 종료
