#include <iostream>
#include <vector>
#include <array>	//std::array
#include <algorithm>	//std::sort
#include <string>
#include <forward_list>
#include <list>
#include <deque>

void ArrayEX() 
{
	// std::array
	// �Ϲ� ���� �迭 - ������Ÿ�ӿ� ũ�Ⱑ ����
	// Sequence
	// Random Acces
	
	// ����
	std::array<int, 5>arr{ 5, 2, 4, 1, 3 };

	// ��ȸ(Traverse)
	for (const auto& e : arr) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// ũ��
	std::cout << arr.size() << std::endl;

	// ����
	std::sort(arr.begin(), arr.end());

	// �ε���
	std::cout << arr[0] << " : " << *arr.begin() << " : " << arr.front() << std::endl;
	std::cout << arr[4] << " : " << *(arr.end()-1) << " : " << arr.back() << std::endl; //end�� �迭 �ʸӼ� ����Ű�� ������ �۵�����
}

void VectorEX() 
{
	// std::vector
	// ���� �迭
	// Sequence
	// Random Access

	// ����
	std::vector<int> vec{ 5, 2, 1, 3, 4 };

	// ũ��
	std::cout << vec.size() << std::endl;

	// ����
	std::sort(vec.begin(), vec.end());

	// ��ȸ
	for (const auto& e : vec) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// �ε���
	std::cout << vec[0] << " : " << *vec.begin() << " : " << vec.front() << std::endl;
	std::cout << vec[4] << " : " << *(vec.end()-1) << " : " << vec.back() << std::endl;
	// ���� �迭�̹Ƿ� ������ ������ ����
	vec.resize(10, -1);

	// �ڿ��� �߰�, ������ ����
	vec.push_back(6);
	vec.push_back(10);

	vec.pop_back();
	std::cout << vec.capacity() << std::endl;

	for (const auto& e : vec)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void StringEX() 
{
	//std::string
	// ���������� std::vector<char>�� ����
	// ���ڿ��� Ưȭ�� ��� �߰�

	// ����
	std::string str = "hello";
	std::string str2 = { 'h', 'e', 'l', 'l', 'o', '\0' };

	// ũ��
	std::cout << str.size() << std::endl;

	// ����
	std::sort(str.begin(), str.end());
	std::cout << str << std::endl;

	//��ȸ
	for (const auto e : str) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	str.push_back('!');
	str.push_back('?');

	str.pop_back();
	std::cout << str << std::endl;

	// �ε���
	std::cout << str[0] << " : " << *str.begin() << " : " << str.front() << std::endl;
	std::cout << str[5] << " : " << *(str.end()-1) << " : " << str.back() << std::endl;

	std::cout << str.substr(0, 3) << std::endl;
};

void ForwardListEX() 
{
	//std::forward_list
	// Single Linked List
	// Sequential
	// randomAccess X

	// ����
	std::forward_list<int> list{ 5,3,1,2,4 };

	// ũ��
	// size()�� ����
	int count{};
	auto itr = list.begin();
	while (itr != list.end()) { count++; itr++; }
	std::cout << count << std::endl;

	// ����
	//std::sort(list.begin(), list.end());
	list.sort();

	// ��ȸ
	for (auto e : list) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//�ε���
	std::cout << *list.begin() << " : " << list.front() << std::endl;
	// �ܹ����̶� ���ͷ����� - ������ �Ұ��� & back X
	//std::cout << *(list.end() - 1) << " : " << list.back(); �ȵ�

	//��ũ�� ����Ʈ�� ���� - �߰��� �߰��� ����
	list.insert_after(std::find(list.begin(), list.end(), 4), 0);

	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void ListEX() 
{
	//std::list
	//double linked list
	//Random Access X

	// ����
	std::list<int> list{ 5,4,1,3,2 };

	// ũ��
	std::cout << list.size() << std::endl;

	// ����
	list.sort();

	//��ȸ
	for (const auto& e : list) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//�ε���
	std::cout << *list.begin() << " : " << list.front() << std::endl;
	std::cout << " : " << list.back() << std::endl;

	// list Ư
	list.push_back(10);
	list.push_front(0);
	list.insert(std::find(list.begin(), list.end(), 4), 0);

	list.pop_back();
	list.pop_front();

	for (const auto& e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void DequeEX() 
{
	//Double Ended Queue
	//std::vector�� ����

	// ����
	std::deque<int> c = { 5,4,1,3,2 };

	// ũ��
	std::cout << c.size() << std::endl;

	// ����
	std::sort(c.begin(), c.end());

	// ��ȸ
	for (const auto& e : c) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// �ε���
	std::cout << c[0] << " : " << *c.begin() << " : " << c.front() << std::endl;
	std::cout << c[4] << " : " << *(c.end()-1) << " : " << c.back() << std::endl;

	c.push_back(10);
	c.push_front(0);
	for (const auto& e : c)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main() 
{
	//Sequence Container
	ArrayEX();
	VectorEX();
	StringEX();
	ForwardListEX();
	ListEX();
	DequeEX();
}