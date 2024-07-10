#pragma once

#include <iostream>
#include <array>
#include <vector>
#include "memo.h"
//Tabulation
// 재귀를 할 수 있다
// 1. n+1개의 배열을 만듦
// 2. Base case
// 3. 앞에서부터 뒤로 채워나감
// 
// 일반적인 접근
// 1. n+1개의 배열을 만듦
// 2. 배열에 기본값을 채움
// 3. 가장작은 단위의 문제를 채움
// 4. 현재 값을 영향을 주는 다른 셀로 퍼뜨립니다
//

//피보나치
int64_t Fibonacci_Tab(const int n) 
{
	//std::vector<int> table(n + 1);
	////base case
	//table[0] = 0;
	//table[1] = 1;
	////tabulation
	//for (int i{ 2 }; i < n + 1; ++i) 
	//{
	//	table[i] = table[i - 2] + table[i - 1];
	//}
	//return table[n];

	std::vector<int> table(n + 1, 0);
	table[1] = 1;
	for (int i = 0; i < n + 1; ++i) 
	{
		if (i + 1 < n + 1) 
		{
			table[i + 1] += table[i];
		}
		if (i + 2 < n + 1) 
		{
			table[i + 2] += table[i];
		}
	}
	return table[n];
}

//길찾기
//Time Complexity : O(m*n)
//Space Complexity : O(m*n)
int64_t Findwaus_tab(const int m, const int n) 
{
	//std::vector<std::vector<int>> table(m+1, std::vector<int>(n+1,0));
	//table[1][1] = 1;
	//for (int row = 1; row < m + 1; ++row) 
	//{
	//	for (int col = 1; col < n + 1; col++) 
	//	{
	//		if (row == 1 && col == 1) continue;
	//		table[row][col] = table[row - 1][col] + table[row][col - 1];
	//	}
	//}
	//return table[m][n];

	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));
	table[1][1] = 1;
	for (int row{}; row < m + 1; ++row) 
	{
		for (int col{}; col < n + 1; ++col) 
		{
			if (row + 1 < m + 1) 
			{
				table[row + 1][col] += table[row][col];
			}
			if (col + 1 < n + 1) 
			{
				table[row][col + 1] += table[row][col];
			}
		}
	}
	return table[m][n];
}

bool CanAccum_tab(const int sum, const std::vector<int>& numbers) 
{
	std::vector<bool> table(sum + 1, false);
	table[0] = true;
	for (int i{}; i < sum + 1; ++i) 
	{
		if (table[i]) 
		{
			for (auto e : numbers) 
			{
				if (i + e < sum+1) 
				{
					table[i + e] = true;
				}
			}
		}
	}
	return table[sum];
}

// Time Complexity : O(m*m*n) = O(m^2 * n)
// Space Complexity : O(m*m) = O(m^2)
std::shared_ptr<std::vector<int>> HowAccum_tab(const int sum, const std::vector<int>& numbers) 
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);
	table[0] = std::make_shared<std::vector<int>>(0);
	for (int i{}; i < sum + 1; i++) 
	{
		if (table[i] != nullptr) 
		{
			for (auto e : numbers) 
			{
				if (i + e < sum + 1) 
				{
					table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}
	}
	return table[sum];
}

//Time Complexity : O(m^2*n)
//Space Complexity : O(m^2)
std::shared_ptr<std::vector<int>> OptimizeAccum_tab(const int sum, const std::vector<int>& numbers) 
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);

	table[0] = std::make_shared<std::vector<int>>(0);
	for (int i{}; i < sum + 1; ++i)
	{
		if (table[i]) 
		{
			for (auto e : numbers) 
			{
				if (i + e < sum + 1)
				{
					if (table[i + e] == nullptr || table[i + e]->size() - 1 > table[i]->size()) 
					{
						table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}
	return table[sum];
}

std::shared_ptr<std::vector<int>> PossibleWaysToClimb(int n)
{
	std::vector<std::shared_ptr<std::vector<int>>> table(n + 1, nullptr);
	table[0] = std::make_shared<std::vector<int>>(1);
	for (int i{}; i < n + 1; i++) 
	{
		
	}
}

void Tabulation() 
{
	std::cout << Fibonacci_Tab(5) << std::endl;
	std::cout << Fibonacci_Tab(40) << std::endl;

	std::cout << Findwaus_tab(30, 30) << std::endl;

	std::cout << CanAccum_tab(8, { 2,3,5 }) << std::endl;

	Print(HowAccum_tab(8, { 2,3,5 }));
	Print(OptimizeAccum_tab(8, { 2,3,5 }));
}