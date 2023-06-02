////////////////////////////////////////////////

//0 선언하는 방법들

/*
1 라이브러리 인클루드 방법(파일째로 복붙)
2 < >는 내장 라이브러리, "" 내가 가져온 라이브러리
3. 정의: 헤더, 구현화: .cpp
4. 네임스페이스를 이용해 같은 이름의 기능이라도 분리가능
*/
////////////////////////////////////////////////

#pragma once // 이 파일을 딴곳에서 인클루드시 한번만 인클루드 됨
#include <stdio.h> //둘다 입출력이지만, 난 printf를 선호
#include <iostream>
#define NAME "name" //name이란 name을 정의. 일종의 상수화
using namespace std;


////////////////////////////////////////////////

//1 기초적인 입출력과 범위

/*
1 입출력 방법
2 함수 생성방법(순차적이므로 사용하기전에 선언 해줘야 함) 
3 지역변수와 전역변수(동명의 변수가 여러개 생성되면 가까운 스코프를 사용
4 static 정적변수 키워드를 사용하면, 블록이 끝나도 프로그램이 끝날때까지 값유지
5 cout cin은 c++용(iostream 라이브러리)
*/
////////////////////////////////////////////////

int glovalVar = 0;// 전역변수. 전 지역에서 유효
void io(int param=0) { //디폴트값 생성가능
	printf("[입출력 사용법]\n");
	int regionalVar =param;// 지역변수로 {}안에서만 유효
	printf("지역변수 : %d \n", regionalVar); //%d 정수, %f 소숫점 포함, %c 글자, %s 글자조합
	//cout << "지역변수 : " << regionalVar << endl; //이런 방식의 출력도 가능
	
	scanf_s("%d", &regionalVar);
	printf("지역변수 : %d", regionalVar);

}

////////////////////////////////////////////////

//2 논리

/*
1 제어와 반복 사용법
2 && || ! 같은 논리연산을 이용해 조건을 중첩가능
3 c++의 스위치는 정수형만 됨
4 continue, break로 반복문의 실행조절 가능
5. goto는 사용금지
*/
////////////////////////////////////////////////

void logic() {
	printf("[조건문 사용법]\n");

	int num = 10;
	cin >> num; //cout, cin 과 printf와 scanf를 같이 사용하는건 삼가할것
	if (num > 20) {
		//num이 20보다 클때
		printf("num은 20보다 큽니다");
	}
	else if (num == 20)
	{
		//같을때
		printf("num은 20입니다");
	}
	else {
		//작을때 실행
		printf("num은 20보다 작습니다");
	}
	cout << endl;

	switch (num) {
	case 0:
		printf("입력값은 0입니다");
		break;//호출 안하면 아래도 실행해버림
	case 20:
		printf("입력값은 20입니다");
		break;
	default:
		printf("입력값은 어찌돼도 좋습니다.");
		break;
	}

	cout << endl;

	printf("[반복문 사용법]\n");
	while (num < 30) { //먼저체크
		cout << num << endl;
		num++;
	}
	
	do {
		cout << num << endl;
		num++;
	} while (num < 30); //나중체크

	for (int i = num; i < 30; i++) {
		cout << num << endl;
		num++;
	}
}


////////////////////////////////////////////////

//3 배열

/*
1 초기화 해주지 않으면 쓰레기값(전역에선 자동으로 0으로 초기화)
*/
////////////////////////////////////////////////

void arrFunc(int paramArr[][3], int length) {
	printf("[배열 사용법]\n");
	char arr[10] = {};//초기화 없이는 쓰레기값이 가득
	for (int i = 0; i < 10; i++) {
		printf("%c", arr[i]);
	}
	scanf_s("%s", arr,10);//입력은 널문자를 상정하고 쓸것
	printf("%s\n", arr);

	cin >> arr;//입력은 널문자를 상정하고 쓸것
	cout << arr<<endl;
	
	printf("[문자열 사용법]\n");
	string s;
	cin >> s;//스트링은 널문자를 자동처리해줌. scanf를 쓰지말것(length등이 작동 x)
	
	cout << s <<" 길이: "<< s.length()<<endl;

	printf("[다차원 배열 사용법]\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << paramArr[i][j];
		}
	}

}


////////////////////////////////////////////////

//4 주소

/*
1 배열은 그 자체로 주소형(클래스도 마찬가지, 스트럭트는 X)

2 동적할당은 c방식(malloc,free), c++방식(new, delete)로 나뉨
*/
////////////////////////////////////////////////

void reff() {
	printf("[배열 사용법]\n");
	int a = 0;
	int* ap = &a;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int * arrp= arr;
	cout << *ap << arrp[1]<<"==" << *(arrp + 1) << endl;

	printf("[동적할당 사용법]\n");
	int* buffer=NULL;
	buffer = (int*)malloc(16);
	if (buffer == NULL) exit(1);
	buffer[3] = 3;
	cout << buffer[3];
	free(buffer); //이런식으로 버퍼를 사용하고 없앤다

}


////////////////////////////////////////////////

//5 구조체와 공용체와 열거형

/*
1 열거형은 주소를 공유한다(가장 큰 자료형을 기준으로 사이즈 결정)\
2 enum 원소의 정수값은 직전 값의 +1씩 증가(최초 값이 없으면 0에서 시작)
3 순수 c에선 typedef로 별칭설정해야 struct를 생략가능
*/
////////////////////////////////////////////////
struct stu {
	int id;
	string name;
};//새로운 데이터타입(값) 정의
typedef stu st; //새로운 이름 부여

union uni {
	char a[4];
	char b[2];
	char c;
};

enum enu {
	a=1,
	b,
	c,
	d
};//보통 안쓰긴 한다

#include <string>

void makeStuUni() {
	printf("[그외 자료형 사용법]\n");
	stu s = { 10,"name" };
	s.id = 1;//값변경 방법
	cout << s.id << endl;
	uni u;
	char ca[4] = {'0','2','3','\0'};
	strcpy_s(u.a,4,ca);
	cout << u.c;

	enu alpha = enu(0);
	if (alpha == a) {
		cout << "a임";
	}
	else {
		cout << "아님";
	}
	

}



int main() {
	//io();//1
	//logic();//2
	//int arr[][3] = {{0,1,2} ,{3,4,5} ,{6,7,8}}; //3
	//arrFunc(arr,3); //3
	//reff(); //4
	//makeStuUni(); //5
	return 0;
}

