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

// m x n ũ���� �簢���� �־����� ��, �»�ܿ��� ����Ͽ� ���ϴ����� �̵��ϴ� ��� ����� ���� ���ϼ���.
//��, �������̳� �Ʒ������θ� �̵� �� �� �ֽ��ϴ�.

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