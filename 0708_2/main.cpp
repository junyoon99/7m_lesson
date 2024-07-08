#include<iostream>
#include<map>

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
	memo[n] = Fibonacci_memo(n - 1,memo) + Fibonacci_memo(n - 2,memo);
	return memo[n];
}

// m x n 크기의 사각형이 주어졌을 때, 좌상단에서 출발하여 우하단으로 이동하는 모든 경우의 수를 구하세요.
//단, 오른쪽이나 아래쪽으로만 이동 할 수 있습니다.

//Time Complexity : O(2 ^ (m+n))
//Space Complexity : O( m + n )
int64_t FindWays(int m, int n)
{
	//base case
	if ((m == 0) || (n == 0)) return 0;
	if ((m == 1) || (n == 1)) return 1;

	// recursive case
	return FindWays(m - 1, n) + FindWays(m, n - 1);
}

int main() 
{
	for (int i{}; i < 50; i++) 
	{
		std::map<int, int64_t> m;
		std::cout << Fibonacci_memo(i,m) << " ";
	}
	std::cout << std::endl;


	std::cout << FindWays(30, 30) << std::endl;
}