#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////

// ���ӽ����̽�

/*
1 �ݺ������� ����ϴ� Ÿ ������ using�� ����
	(����::����� ������ �θ��� ������ �������� ������)
2 ���ӽ����̽�=�μ�(���������� �и���)
*/
////////////////////////////////////////////////

namespace usage {

#pragma region �����Ҵ�
////////////////////////////////////////////////

// �����Ҵ�

/*
1 c++���� malloc, free ��� ����(ũ�Ⱑ �ڵ�����̹Ƿ�)
2 �ݵ�� new�� delete�� ��Ʈ��
*/

////////////////////////////////////////////////
void makeNew() {
	cout << "[�����Ҵ� ����]" << endl;
	int* ptr1 = new int(3);
	int* ptr2 = new int[3] {0, 1, 2};

	delete ptr1;
	delete[]ptr2; //��ü �迭�� �̷��� ����
	//���� �迭�̸� �ȿ� �ִ� �迭����� �������
}


#pragma endregion

#pragma region ����ü Ŭ����
	////////////////////////////////////////////////

	// c++ ����ü�� Ŭ����

	/*
	1 ����ü�� ������� �⺻������ public, Ŭ������ private
	2 �Լ��� ��������
	3 ����ü�� ���翬��� ���� �״�� ����
	4 �Լ��� �����ε��� ����
	5 c++���� ����ü�� Ŭ������ ����� ���� ū ���̾���
	6 �� ���� �ٸ��� ���Խ� ������ �������ش�(�ּҸ� �ѱ� ��츦 �����ϰ�)
	7 �ظ��ϸ� Ŭ�������
	*/
	////////////////////////////////////////////////
	struct stu
	{
	private:
		int id;
		string name;
	public:
		stu() {}//������
		~stu() {
			cout << "����ü �Ҹ�" << endl;
		}// �Ҹ���
		void show() {
			cout << id << name;
		}
		void set(int id, string name) {
			this->id = id;//this�� �Ἥ �ڽ��� ����ü(Ŭ����)�ּҸ� ��ȯ
			this->name = name;
		}
	};

	//���� ���� ����� ������ Ŭ������ ����
	class cla {
	private:
		int id;
		string name;
	public:
		cla() {
			id = 0;
			name = "�͸�";
			cout << "����";
		} //������

		cla(int id, string name) {
			this->id = id;
			this->name = name;
		}//�����ε�

		cla(const cla& c) {
			this->id = c.id;
			this->name = c.name;
			cout << "�������" << endl;
		}//���������: ���ο� �ּҸ� ���°� ���� ��� ��� �����ϱ� ���� ���
		~cla() {
			cout << "�ν��Ͻ� �Ҹ�" << endl;
		}//�Ҹ���: ��ü �����ÿ� ȣ��
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
		cout << "[����ü ����]" << endl;
		stu s;
		s.set(1, "�ȳ�");
		s.show();
		stu s2 = s;//�� ��ü�� �翬 �ٸ���ü
		s2.show();
		s.set(1, "�߰�");
		s2.show();

		cout << "[Ŭ���� ����]" << endl;
		cla c(1, "�ȳ�");
		c.show();
		cla c2 = c;//�� ��ü�� �ٸ���ü���
		c2.show();
		c.set(10);//���� �ٲ㵵 c2���� ������ ����.
		c2.show();
	}

#pragma endregion

#pragma region Ŭ�������
////////////////////////////////////////////////

// Ŭ������ ���

/*
1 ��� ���� Ŭ������ ���� ���
2 �θ��� �����ڸ� ��������� ���� ������ �θ��� �����ڰ� ����ȣ���
3 ��������� ���� ȣ�� �ȵ�
4 �������̵�(�������� �̿���, �θ� �ڷ����� ��������, �ڳ��� ����� ����ϴ¹�)
	�����, �θ�� �ڳ� �Լ��� virtual void �̸�(){} ������� �ۼ�
5 ���������Լ�(�߻�)����: virtual void �̸�() = 0;
6 ���� �����ü�� ���ǳ�(�θ��Լ��� ��������� �θ��Ƿ�)���� ��������
*/
////////////////////////////////////////////////

	class inheritiedCla : public cla {
	public:
		string gender="����";// ����Ʈ��
		inheritiedCla(int id, string name,string gender) :cla(id,name),gender(gender) {
				
		}//������
		inheritiedCla() {
			//cla();//X �̷������� ȣ���ϸ� ������ �ι�ȣ��ǹǷ� ��ó�� �Ұ�
			//�ƹ��͵� �Ƚᵵ �θ� ����Ʈ�� �����ǳ� �ظ��ϸ� ����
		}//������ 
		void show() {
			cla::show();//Ŭ�� �Ƚᵵ ��;��� �θ� ã�ư���
					//�θ� ��������� ǥ���Ұ�(�����ڿ� �ٸ��� ����Ʈ ���� ����)

			cout << gender << endl;
		}
	};

	void useinheritiedCla() {
		cout << "[��� ����]" << endl;
		inheritiedCla * c = new inheritiedCla();
		c->show();
		delete c;
	}
#pragma endregion

#pragma region ���۷���
////////////////////////////////////////////////

// ���۷���

/*
1 ��Ī��(�׳� ������)
2 �ƽ��׸���ũ���� ����ϱ� ������(�״�� �ָ��)
3 ������ü�� ���� �ּҸ� ����Ű�� ��
(�ƽ��׸���ũ������ ������ ����Ű�� ���� �ּ���. ���� �ٸ�)
*/
////////////////////////////////////////////////
	void reffTest(int& ref1, int& ref2) { //������ &�� ���̸� ������ �ƴ� ������
		int temp = ref1;
		ref1 = ref2;
		ref2 = temp;
	}

	void useReff() {
		cout << "[���۷��� ����]" << endl;
		int num = 0, num2 = 1;
		int& numRef = num;
		cout << numRef << endl;
		reffTest(num, num2);
		cout << num << " " << num2 << endl;
	}
#pragma endregion

#pragma region ���ø�
	////////////////////////////////////////////////

	// ���ø�

	/*
	1 �ڷ����� �������� �ʾ����� �����ϰ� ���

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
		swap<int>(num1, num2); //�� ������� �ʿ� ������ ������ΰ� ���ڴ�
		cout << num1 << " " << num2;
	}

	////////////////////////////////////////////////
#pragma endregion

#pragma region ����
////////////////////////////////////////////////

//����ó��

/*
1 ���װ� �߻��� �� �ִ� �ڵ忡 ������ġ�� �޾��ش�
*/
////////////////////////////////////////////////

	void useException() {
		int a, b;
		cout << "�� ���� ������ �Է��ϼ���: ";
		cin >> a >> b;

		try
		{
			string e = "�����߻�";
			e.append(to_string(b));
			if (b == 0) throw e;
			cout << a << "�� " << b << "�� ���� ���� " << a / b << "�Դϴ�." << endl;
		}
		catch (string & excep)//������ ������ �ڷ����� �ڷ����� ��ġ�ؾ���
		{
			cout << "���� �߻�, ������ ���� " << excep << "�� �� �� �����ϴ�." << endl;
		}
	}

////////////////////////////////////////////////
#pragma endregion


#pragma region �׿� ����� ����
////////////////////////////////////////////////
// �׿��� ����� ����

/*
1 ���� ���ϴ� �Ҹ���. ���� 1(0 �̿��� ��)��, ������ 0���� ���ǵ�. 1����Ʈ
	(��κ��� �ǿ��� ����)
2 #define �Լ���(x) ((x)*(x)*(x)) ���� ��ũ�� ���� ����
3 2���� �� inline int �Լ���(x){return x*x*x;} �� ���� ����
4 �ζ����� �ҽ��ڵ尡 ���ſ� ���Ƿ� ª�� ����ƴϸ� ���� ����
5 Ŭ���� ���ο� �� friend class ����� Ŭ������; 
	������ �ؼ� Ư�� Ŭ������ ������Ӽ����� ���� �����ϰ� ����� ����
6 ������ �����ε�: ��ȯ�� operator(������)(�Է��� ����)
7 �� Cla& operator=(Cla& ref)
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
