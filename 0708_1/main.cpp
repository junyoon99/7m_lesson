#include <iostream>
#include <queue>

int main() 
{
	//내부구조는 살짝 다르지만 기능은 Heap과 비슷하게 작동
	std::priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	pq.push(4);
	pq.push(3);
	pq.push(5);

	std::cout << pq.top() << std::endl;
	pq.pop();

	std::cout << pq.top() << std::endl;
	pq.pop();

	std::cout << pq.top() << std::endl;
	pq.pop();

	std::cout << pq.top() << std::endl;
	pq.pop();

	std::cout << pq.top() << std::endl;
	pq.pop();

	std::vector<int> v{ 1,2,3,4,5 };
	std::make_heap(v.begin(), v.end());

	for (const auto& e : v) 
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::cout << v.front() << std::endl;
	std::pop_heap(v.begin(), v.end());
	v.pop_back();

	std::cout << v.front() << std::endl;
	std::pop_heap(v.begin(), v.end());
	v.pop_back();

	std::cout << v.front() << std::endl;
	std::pop_heap(v.begin(), v.end());
	v.pop_back();

	std::cout << v.front() << std::endl;
	std::pop_heap(v.begin(), v.end());
	v.pop_back();

	std::cout << v.front() << std::endl;
	std::pop_heap(v.begin(), v.end());
	v.pop_back();
}