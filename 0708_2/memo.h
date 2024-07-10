#pragma once

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>

// Time Complexity : O(2^n)
// Space Complexity : O(n)
int Fibonacci(int n)
{
	//base case
	if (n <= 2)
	{
		return 1;
	}

	// recursive case
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Time Complexity : O(n)
// Space Complexity : O(n)
int64_t Fibonacci_memo(int n, std::map<int, int64_t>& memo)
{
	//memo
	if (memo.count(n) == 1)
	{
		return memo[n];
	}

	//base case
	if (n <= 2)
	{
		return 1;
	}

	// recursive case
	memo[n] = Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2, memo);
	return memo[n];
}

// m x n 크기의 사각형이 주어졌을 때, 좌상단에서 출발하여 우하단으로 이동하는 모든 경우의 수를 구하세요.
//단, 오른쪽이나 아래쪽으로만 이동 할 수 있습니다.

//Time Complexity : O(2 ^ (m * n))
//Space Complexity : O( m + n )
int64_t FindWays(int m, int n)
{
	//base case
	if ((m < 0) || (n < 0)) return 0;
	if ((m == 1) || (n == 1)) return 1;

	// recursive case
	return FindWays(m - 1, n) + FindWays(m, n - 1);
}

int64_t FindWays_memo(int m, int n, std::map<std::string, int64_t>& memo)
{
	const std::string key = std::to_string(m) + "," + std::to_string(n);
	if (memo.count(key) == 1)
	{
		return memo[key];
	}

	const std::string rkey = std::to_string(n) + "," + std::to_string(m);
	if (memo.count(rkey) == 1)
	{
		return memo[rkey];
	}

	//base case
	if ((m < 1) || (n < 1)) return 0;

	if ((m == 1) || (n == 1)) return 1;

	// recursive case
	memo[key] = FindWays_memo(m - 1, n, memo) + FindWays_memo(m, n - 1, memo);
	return memo[key];
}

// 정수의 배열 numbers에서 숫자들을 조합하여 sum을 만들어 낼 수 있는지 확인하는
// bool CanAccumulation(sum, numbers)를 만들어 보세요.
// 단, 동일한 원소를 여러번 사용해도 됩니다.
// ex) 8 {2,3,5} true	8{5,6} false

// m : sum, n : numbers의 크기
//time Complexity : O(너비^높이) = O(n^m)
//space Complexity : O(m)
bool CanAccumulation(int sum, const std::vector<int>& numbers)
{
	//base case
	if (sum < 0) return false;
	if (sum == 0) return true;

	//recursive case
	for (const auto& e : numbers)
	{
		if (!(e == 0))
		{
			if (CanAccumulation(sum - e, numbers)) return true;
		}
	}
	return false;
}

bool CanAccumulation_memo(int sum, const std::vector<int>& numbers, std::map<int64_t, bool>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	//base case
	if (sum < 0) return false;
	if (sum == 0) return true;

	//recursive case
	for (const auto& e : numbers)
	{
		if (!(e == 0))
		{
			if (CanAccumulation_memo(sum - e, numbers, memo))
			{
				memo[sum] = true;
				return memo[sum];
			}
		}
	}
	memo[sum] = false;
	return memo[sum];
}


//Time Complexity : O(n^m) -> O(n*m)
//Space Comlexity : o(m^2) -> O(m^2) 출력을 무시한다면 O(m)
using accum_memo = std::map<int, std::shared_ptr<std::vector<int>>>;
std::shared_ptr<std::vector<int>> HowAccumulate(int sum, const std::vector<int>& numbers, accum_memo& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}
	//base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	//recursive case
	for (const auto& e : numbers)
	{
		auto ret = HowAccumulate(sum - e, numbers, memo);
		if (ret != nullptr)
		{
			ret->push_back(e);
			memo[sum] = ret;
			return memo[sum];
		}
	}
	return nullptr;
}

std::shared_ptr<std::vector<int>> OptimizeAccumulation(int sum, const std::vector<int>& numbers, accum_memo& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}
	//base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}
	//recursive case
	std::shared_ptr<std::vector<int>> best = nullptr;
	for (auto e : numbers)
	{
		auto ret = OptimizeAccumulation(sum - e, numbers, memo);
		if (ret != nullptr)
		{
			std::shared_ptr<std::vector<int>> temp = std::make_shared<std::vector<int>>();
			temp->resize(ret->size());
			std::copy(ret->begin(), ret->end(), temp->begin());
			temp->push_back(e);
			//ret->push_back(e);
			if ((best == nullptr) || (temp->size() < best->size()))
			{
				best = temp;
			}
		}
	}

	memo[sum] = best;
	return memo[sum];
}


void Print(std::shared_ptr<std::vector<int>> result)
{
	std::cout << "{ ";
	if (result)
	{
		for (auto e : *result)
		{
			std::cout << e << " ";
		}
	}
	else
	{
		std::cout << "nullptr ";
	}
	std::cout << "}" << std::endl;
}

void Memoization()
{
	for (int i{}; i < 50; i++)
	{
		std::map<int, int64_t> m;
		std::cout << Fibonacci_memo(i, m) << " ";
	}
	std::cout << std::endl;

	std::map<std::string, int64_t> m2;
	std::cout << FindWays_memo(30, 30, m2) << std::endl;

	std::map<int64_t, bool> memo;
	std::cout << CanAccumulation_memo(99, { 1,2,3 }, memo);
	std::cout << std::endl;
	memo.clear();

	accum_memo m;
	std::vector<int> n{ 1,3,4,5 };
	std::make_heap(n.begin(), n.end());
	Print(HowAccumulate(7, n, m));
	m.clear();
	Print(HowAccumulate(8, { 5,6 }, m));
	m.clear();
	Print(OptimizeAccumulation(8, n, m));
	m.clear();
	Print(OptimizeAccumulation(7, { 1,4,3,5 }, m));
	m.clear();


}