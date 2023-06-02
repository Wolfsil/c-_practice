#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////

// 네임스페이스

/*
1 반복적으로 사용하는 타 네임은 using을 쓰자
	(네임::사용할 것으로 부를순 있지만 여러번은 귀찮다)
2 네임스페이스=부서(동명이인을 분리함)
*/
////////////////////////////////////////////////

namespace usage {

#pragma region 동적할당
////////////////////////////////////////////////

// 동적할당

/*
1 c++에서 malloc, free 대신 쓴다(크기가 자동계산이므로)
2 반드시 new와 delete는 세트로
*/

////////////////////////////////////////////////
void makeNew() {
	cout << "[동적할당 사용법]" << endl;
	int* ptr1 = new int(3);
	int* ptr2 = new int[3] {0, 1, 2};

	delete ptr1;
	delete[]ptr2; //객체 배열은 이렇게 해제
	//이중 배열이면 안에 있는 배열들부터 해제요망
}


#pragma endregion

#pragma region 구조체 클래스
	////////////////////////////////////////////////

	// c++ 구조체와 클래스

	/*
	1 구조체는 접근제어가 기본적으로 public, 클래스는 private
	2 함수도 설정가능
	3 구조체는 복사연산시 값을 그대로 복제
	4 함수의 오버로딩도 가능
	5 c++에서 구조체와 클래스는 몇몇기능 빼고 큰 차이없다
	6 딴 언어와 다르게 대입시 값까지 복사해준다(주소를 넘길 경우를 제외하고)
	7 왠만하면 클래스사용
	*/
	////////////////////////////////////////////////
	struct stu
	{
	private:
		int id;
		string name;
	public:
		stu() {}//생성자
		~stu() {
			cout << "구조체 소멸" << endl;
		}// 소멸자
		void show() {
			cout << id << name;
		}
		void set(int id, string name) {
			this->id = id;//this를 써서 자신의 구조체(클래스)주소를 반환
			this->name = name;
		}
	};

	//위와 같은 기능을 하지만 클래스로 구현
	class cla {
	private:
		int id;
		string name;
	public:
		cla() {
			id = 0;
			name = "익명";
			cout << "생성";
		} //생성자

		cla(int id, string name) {
			this->id = id;
			this->name = name;
		}//오버로딩

		cla(const cla& c) {
			this->id = c.id;
			this->name = c.name;
			cout << "복사생성" << endl;
		}//복사생성자: 내부에 주소를 쓰는게 있을 경우 깊게 복사하기 위해 사용
		~cla() {
			cout << "인스턴스 소멸" << endl;
		}//소멸자: 객체 해제시에 호출
		void show() {
			cout << id << name;
		}
		void set(int id, string name) {
			this->id = id;
			this->name = name;
		}
		void set(int id) {
			this->id = id;
		}
	};


	void useStrCla() {
		cout << "[구조체 사용법]" << endl;
		stu s;
		s.set(1, "안녕");
		s.show();
		stu s2 = s;//두 객체는 당연 다른객체
		s2.show();
		s.set(1, "잘가");
		s2.show();

		cout << "[클래스 사용법]" << endl;
		cla c(1, "안녕");
		c.show();
		cla c2 = c;//두 객체는 다른객체취급
		c2.show();
		c.set(10);//값을 바꿔도 c2에는 영향이 없다.
		c2.show();
	}

#pragma endregion

#pragma region 클래스상속
////////////////////////////////////////////////

// 클래스의 상속

/*
1 상속 받은 클래스의 모든걸 계승
2 부모의 생성자를 명시적으로 쓰지 않으면 부모의 생성자가 먼저호출됨
3 명시적으로 쓰면 호출 안됨
4 오버라이딩(다형성을 이용해, 부모 자료형의 변수에서, 자녀의 기능을 사용하는법)
	사용방법, 부모와 자녀 함수를 virtual void 이름(){} 방식으로 작성
5 순수가상함수(추상)사용법: virtual void 이름() = 0;
6 다중 상속자체는 허용되나(부모함수를 명시적으로 부르므로)굳이 하지말자
*/
////////////////////////////////////////////////

	class inheritiedCla : public cla {
	public:
		string gender="남자";// 디폴트값
		inheritiedCla(int id, string name,string gender) :cla(id,name),gender(gender) {
				
		}//생성자
		inheritiedCla() {
			//cla();//X 이런식으로 호출하면 생성자 두번호출되므로 위처럼 할것
			//아무것도 안써도 부모 디폴트가 생성되나 왠만하면 쓸것
		}//생성자 
		void show() {
			cla::show();//클라를 안써도 재귀없이 부모를 찾아가나
					//부모를 명시적으로 표현할것(생성자와 다르게 디폴트 콜이 없음)

			cout << gender << endl;
		}
	};

	void useinheritiedCla() {
		cout << "[상속 사용법]" << endl;
		inheritiedCla * c = new inheritiedCla();
		c->show();
		delete c;
	}
#pragma endregion

#pragma region 레퍼런스
////////////////////////////////////////////////

// 레퍼런스

/*
1 별칭임(그냥 같은것)
2 아스테리스크보다 사용하기 편한편(그대로 주면됨)
3 변수자체가 같은 주소를 가르키게 됨
(아스테리스크변수는 변수가 가리키는 곳이 주소임. 완전 다름)
*/
////////////////////////////////////////////////
	void reffTest(int& ref1, int& ref2) { //변수에 &를 붙이면 복제가 아닌 가져옴
		int temp = ref1;
		ref1 = ref2;
		ref2 = temp;
	}

	void useReff() {
		cout << "[레퍼런스 사용법]" << endl;
		int num = 0, num2 = 1;
		int& numRef = num;
		cout << numRef << endl;
		reffTest(num, num2);
		cout << num << " " << num2 << endl;
	}
#pragma endregion

#pragma region 템플릿
	////////////////////////////////////////////////

	// 템플릿

	/*
	1 자료형이 정해지지 않았을떄 유용하게 사용

	*/
	////////////////////////////////////////////////

	template<typename T>
	void swap(T& num1, T& num2)
	{
		T temp = num1;
		num1 = num2;
		num2 = temp;
	}

	void useTemp() {
		int num1 = 0, num2 = 1;
		swap<int>(num1, num2); //꼭 명시적일 필욘 없으나 명시적인게 예쁘다
		cout << num1 << " " << num2;
	}

	////////////////////////////////////////////////
#pragma endregion

#pragma region 예외
////////////////////////////////////////////////

//예외처리

/*
1 버그가 발생할 수 있는 코드에 안전장치를 달아준다
*/
////////////////////////////////////////////////

	void useException() {
		int a, b;
		cout << "두 개의 정수를 입력하세요: ";
		cin >> a >> b;

		try
		{
			string e = "오류발생";
			e.append(to_string(b));
			if (b == 0) throw e;
			cout << a << "를 " << b << "로 나눈 몫은 " << a / b << "입니다." << endl;
		}
		catch (string & excep)//오류를 던지는 자료형과 자료형이 일치해야함
		{
			cout << "예외 발생, 나누는 수는 " << excep << "가 될 수 없습니다." << endl;
		}
	}

////////////////////////////////////////////////
#pragma endregion


#pragma region 그외 잡다한 내용
////////////////////////////////////////////////
// 그외의 잡다한 내용

/*
1 논리를 뜻하는 불리언. 참은 1(0 이외의 수)로, 거짓은 0으로 정의됨. 1바이트
	(대부분의 실용어는 같음)
2 #define 함수명(x) ((x)*(x)*(x)) 으로 매크로 정의 가능
3 2번을 더 inline int 함수명(x){return x*x*x;} 로 정의 가능
4 인라인은 소스코드가 무거워 지므로 짧은 내용아니면 쓰지 말것
5 클래스 내부에 에 friend class 허락할 클래스명; 
	선언을 해서 특정 클래스가 비공개속성에도 접근 가능하게 만들수 있음
6 연산자 오버로딩: 반환형 operator(연산자)(입력형 변수)
7 예 Cla& operator=(Cla& ref)
*/
////////////////////////////////////////////////
#pragma endregion
}

int main() {
	//usage::makeNew();
	//usage::useStrCla();
	//usage::useReff();
	//usage::useinheritiedCla();
	//usage::useTemp();
	usage::useException();
	return 0;
}
