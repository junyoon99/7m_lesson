#include <stack>
#include <queue>
#include <iostream>

#include <set>	//std::set, std::multiset
#include <unordered_set>
#include <map>

//push O(1) pop O(1) 
void StackEX() 
{
	// ����
	std::stack<int> s;

	// ����
	s.push(1);
	s.push(2);
	s.push(3);

	// ũ��
	std::cout << s.size() << std::endl;

	// ����
	s.pop();

	// ���� ���� �ִ� ����(LAST)
	std::cout << s.top() << std::endl;

	//�ʱ�ȭ�� �Ұ���
	//std::stack<int> s2{1,2,3,4,5}

	//��ȸ
	//������� �Ұ���
	//for(auto e : s){}
	//���ͷ�����, �ε��� ����
	std::stack<int> temp = s;
	while (!s.empty()) 
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	s = temp;
}

//push O(1) pop O(1)
void queueEX() 
{
	std::queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	q.pop();

	std::cout << q.size() << std::endl;

	while (!q.empty()) 
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

//push O(logn) pop O(logn)
void priorityQueueEX() 
{
	//heap�ڷᱸ��
	std::priority_queue<int> pq;
	pq.push(5);
	pq.push(3);
	pq.push(4);
	pq.push(2);

	std::priority_queue<int> temp = pq;
	//�׻� �������� top�� ����
	while (!temp.empty()) 
	{
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}

void SetEX()
{
	//unique�� ��
	// �ڵ�����
	
	// ����
	std::set<int> s{ 1,2,3,4,5 };
	// ����
	s.insert(6);
	// ����
	s.erase(3);
	// ũ��
	std::cout << s.size() << std::endl;
	//��ȸ
	for (auto e : s) 
	{
		std::cout << e << " ";
	}
	//�˻�
	//���ͷ����� ��ȯ�̶� end�� �ƴϸ� ã�Ҵٶ�� ��
	std::cout << (s.find(4) != s.end()) << std::endl;
}

void MapEX() 
{
	//(Ű - ���)
	std::map<int, std::string> m {
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"}
	};

	//����
	m.insert({5,"five"});
	m[6] = "six";

	//ũ��
	std::cout << m.size() << std::endl;

	//�� ����
	std::cout << m.at(2) << std::endl;
	std::cout << m[2] << std::endl;

	// {key, value}
	// std::pair<T1, T2>
	//std::map�� ���� Ÿ���� std::pairŸ��

	//�˻�
	std::map<int, std::string>::iterator result = m.find(1);
	if (result != m.end()) 
	{
		//*result = std::pair<int, string>
		//                   .first .second
		std::cout << "find : " << (*result).second << std::endl;
	}

	//��ȸ
	for (std::pair<int, std::string> e : m) 
	{
		std::cout << e.first << " : " << e.second << std::endl;
	}

	std::map<std::string, int> items
	{
		{"sword", 10},
		{"hammer", 100},
		{"shield", 50},
		{"armor", 50}
	};

	std::cout << items["sword"] << std::endl;
	items["knife"] = 30;
	//Ű���� ���� �Ұ������� ������� ���� ����
	items["knife"] = 50;


	std::multiset<int> ms;
	std::unordered_set<int> us;
	std::unordered_multiset<int> ums;

	ms.insert(1);
	ms.insert(2);
	ms.insert(2);

	us.insert(1);
	us.insert(2);
	us.insert(3);

	ums.insert(1);
	ums.insert(2);
	ums.insert(2);
}

int main() 
{
	// Adoptor Container
	StackEX();
	queueEX();
	priorityQueueEX();

	// Associative Container
	SetEX();
	MapEX();
}