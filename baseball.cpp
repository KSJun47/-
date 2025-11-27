#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) //프로그램을 실행하는 main 함수
{              // main함수 시작
    int ball[3]; //3개의 난수 저장값 부여
    srand(time(NULL));  //난수 초기화

    do {                            //반복
         ball[0] = rand() % 9 + 1;  //ball[0]에 랜덤값 부여
         ball[1] = rand() % 9 + 1;  //ball[1]에 랜덤값 부여
         ball[2] = rand() % 9 + 1;  //ball[2]에 랜덤값 부여
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]); //ball에 같은 값이 나오지않을때까지 랜덤값 부여

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); //ball의 랜덤값 출력

    //3개의 숫자를 입력
    while(1) {
    int input[3];
    printf("Enter the first number: "); //""안에 문구 출력
    scanf("%d", &input[0]); //본인이 입력한 값을 읽음

    printf("Enter the second number: "); //""안에 문구 출력
    scanf("%d", &input[1]); //본인이 입력한 값을 읽음

    printf("Enter the third number: "); // ""안에 문구 출력
    scanf("%d", &input[2]); //본인이 입력한 값을 읽음

    printf("input : %d %d %d\n", input[0], input[1], input[2]); //본인이 입력한 값을 출력 

   
    int strike = 0; //strike에 대한 값 지정
    int ballcount = 0; //ballcount에 대한 값 지정
    int outcount = 3;  //outcount에 대한 값 지정

    if( ball[0] == input[0] ) //입력한 값이 랜덤한값에 가깝거나 맞거나 다르면 ballcount, strike, outcount의 값을 조정
    { //if문 시작
        strike = strike + 1 ; //입력값이 같을시 strike에 1을 더함 
        outcount = outcount - 1 ;  //같을시 outcount 1 차감
    } //if문 끝

    if( ball[1] == input[1] )
    { //if문 시작
        strike = strike + 1 ;  //입력값이 같을시 strike에 1을 더함
        outcount = outcount - 1 ; //같을시 outcount 1 차감
    } //if문 끝
    if( ball[2] == input[2] )
    { //if문 시작
        strike = strike + 1 ;  //입력값이 같을시 strike에 1을 더함
        outcount = outcount - 1 ; //같을시 outcount 1 차감
    } //if문 끝
     if( ball [0] == input [1] ) 
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
    if( ball [0] == input [2] ) 
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
     if( ball [1] == input [0] ) 
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
     if( ball [1] == input [2] ) 
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
     if( ball [2] == input [0] ) 
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
     if( ball [2] == input [1] ) //ball[2] 와 input[1]이 같다면
     { //if문 시작
        ballcount = ballcount + 1 ; //입력값이 값과 같을시 ballcount 1추가
        outcount = outcount - 1 ; //같을시 outcount 1 차감
     } //if문 끝
    
     if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] ) // 값이 전부 맞다면 home run 출력
    { //if문 시작
	    printf("Home Run~\n"); //home run 출력
       return 0;
      } //if문 끝

    
    else // 아니라면 각각의 값을 출력
    {
        printf("%d Strike, %d Ball, %d Out\n", strike, ballcount, outcount) ; //strike값과 ball, out 값을 출력
    }  
    
   }
   return 0;
   } //main문 종료
