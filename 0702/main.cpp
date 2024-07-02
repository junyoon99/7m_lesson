#include <stack>
#include <queue>
#include <iostream>

#include <set>	//std::set, std::multiset
#include <unordered_set>
#include <map>

//push O(1) pop O(1) 
void StackEX() 
{
	// 선언
	std::stack<int> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 크기
	std::cout << s.size() << std::endl;

	// 삭제
	s.pop();

	// 가장 위에 있는 원소(LAST)
	std::cout << s.top() << std::endl;

	//초기화식 불가능
	//std::stack<int> s2{1,2,3,4,5}

	//순회
	//범위기반 불가능
	//for(auto e : s){}
	//이터레이터, 인덱스 없음
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
	//heap자료구조
	std::priority_queue<int> pq;
	pq.push(5);
	pq.push(3);
	pq.push(4);
	pq.push(2);

	std::priority_queue<int> temp = pq;
	//항상 높은값이 top에 있음
	while (!temp.empty()) 
	{
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}

void SetEX()
{
	//unique한 값
	// 자동정렬
	
	// 선언
	std::set<int> s{ 1,2,3,4,5 };
	// 삽입
	s.insert(6);
	// 삭제
	s.erase(3);
	// 크기
	std::cout << s.size() << std::endl;
	//순회
	for (auto e : s) 
	{
		std::cout << e << " ";
	}
	//검색
	//이터레이터 반환이라 end가 아니면 찾았다라는 뜻
	std::cout << (s.find(4) != s.end()) << std::endl;
}

void MapEX() 
{
	//(키 - 밸류)
	std::map<int, std::string> m {
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"}
	};

	//삽입
	m.insert({5,"five"});
	m[6] = "six";

	//크기
	std::cout << m.size() << std::endl;

	//값 접근
	std::cout << m.at(2) << std::endl;
	std::cout << m[2] << std::endl;

	// {key, value}
	// std::pair<T1, T2>
	//std::map의 원소 타입은 std::pair타입

	//검색
	std::map<int, std::string>::iterator result = m.find(1);
	if (result != m.end()) 
	{
		//*result = std::pair<int, string>
		//                   .first .second
		std::cout << "find : " << (*result).second << std::endl;
	}

	//순회
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
	//키값은 수정 불가하지만 밸류값은 수정 가능
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