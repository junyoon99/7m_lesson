#include <iostream>
#include <vector>
#include <algorithm>
class MyClass
{
public:
	MyClass() { std::cout << "�⺻" << std::endl; }
	//���� ������
	MyClass(const MyClass& from) { std::cout << "����" << std::endl; }

	//���� ���� ������
	MyClass& operator = (const MyClass& from)
	{
		std::cout << "���� ���� ������" << std::endl; return*this;
	}

	//�̵� ������
	MyClass(MyClass&& from)
	{
		std::cout << "�̵�" << std::endl;
	}

	//�̵� ���� ������
	MyClass& operator = (MyClass&& from)
	{
		std::cout << "�̵� ���� ������" << std::endl; return *this;
	}
};

//������ ���� &&
void Funtion(int&& a) 
{
	std::cout << a << std::endl;
}

//enum�� �����̱� ������ enum class�� ���°� ����
enum class Color
{
	White = 0,
	Black = 1
};

//����Ʈ ������
//std::unique_ptr	���ҽ� : ������ = 1 : 1
//std::shared_ptr	���ҽ� : ������ = 1 : n
//std::weak_ptr		�������� ����

class MyClass2 
{
public:
	int val;
	MyClass2() { std::cout << "creat" << std::endl; }
	~MyClass2() { std::cout << "delete" << std::endl; }
};

int main() 
{
	//���ٽ�
	//�Ű������� 2�� �޴� �Լ�
	[](int a, int b) -> int
	{
		return 0;
	};

	//���ϰ��� ��õǾ� �ִ� ��� ��ȯ�� ���� ����
	auto f = []() -> int { return 0; };
	auto g = []() { return 0; };

	//capture [] [=] [&]
	//���� ��� ������ ���� �Ǵ� ���� ����

	MyClass c1;
	MyClass c2(c1);
	MyClass c3(std::move(c1));

	int x = 10;
	Funtion(30);
	Funtion(x + 10);
	Funtion(std::move(x));
	std::cout << x << std::endl;

	Color c5;
	c5 = Color::White;

	//����Ʈ ������
	std::unique_ptr<MyClass2> p(std::make_unique<MyClass2>());
	p->val = 1;
	//p�� .������ ����ũ �������� ����� ���
	//->�� ���� p�� ����Ű�� Ŭ������ ���
	MyClass2* pp = p.get();
	p.release();
	p.reset();
}