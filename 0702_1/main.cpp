#include <iostream>
#include <vector>
#include <algorithm>
class MyClass
{
public:
	MyClass() { std::cout << "기본" << std::endl; }
	//복사 생성자
	MyClass(const MyClass& from) { std::cout << "복사" << std::endl; }

	//복사 대입 연산자
	MyClass& operator = (const MyClass& from)
	{
		std::cout << "복사 대입 연산자" << std::endl; return*this;
	}

	//이동 생성자
	MyClass(MyClass&& from)
	{
		std::cout << "이동" << std::endl;
	}

	//이동 대입 연산자
	MyClass& operator = (MyClass&& from)
	{
		std::cout << "이동 대입 연산자" << std::endl; return *this;
	}
};

//우측값 참조 &&
void Funtion(int&& a) 
{
	std::cout << a << std::endl;
}

//enum은 전역이기 때문에 enum class를 쓰는게 낫다
enum class Color
{
	White = 0,
	Black = 1
};

//스마트 포인터
//std::unique_ptr	리소스 : 포인터 = 1 : 1
//std::shared_ptr	리소스 : 포인터 = 1 : n
//std::weak_ptr		소유하지 않음

class MyClass2 
{
public:
	int val;
	MyClass2() { std::cout << "creat" << std::endl; }
	~MyClass2() { std::cout << "delete" << std::endl; }
};

int main() 
{
	//람다식
	//매개변수를 2개 받는 함수
	[](int a, int b) -> int
	{
		return 0;
	};

	//리턴값이 명시되어 있는 경우 반환값 생략 가능
	auto f = []() -> int { return 0; };
	auto g = []() { return 0; };

	//capture [] [=] [&]
	//같은 블록 변수에 복사 또는 참조 가능

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

	//스마트 포인터
	std::unique_ptr<MyClass2> p(std::make_unique<MyClass2>());
	p->val = 1;
	//p에 .찍으면 유니크 포인터의 기능을 사용
	//->을 쓰면 p가 가르키는 클래스를 사용
	MyClass2* pp = p.get();
	p.release();
	p.reset();
}