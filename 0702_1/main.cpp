#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	std::vector<int> v{ 3,1,4,1,5,9,2,6,5,3 };
	auto itr = std::min_element(v.begin(), v.end());
	std::cout << *itr << std::endl;
}