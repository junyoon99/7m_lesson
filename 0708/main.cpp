#include <iostream>
#include <vector>

class Heap 
{
private:
	std::vector<int> mHeap;

public:
	void Insert(int value) 
	{
		mHeap.push_back(value);
		int i = static_cast<int>(mHeap.size()) - 1;
		int parent = (i - 1) / 2;
		while ((i != 0)&&(value > mHeap[parent])) 
		{
			mHeap[i] = mHeap[parent];
			mHeap[parent] = value;

			i = parent;
			parent = (i - 1) / 2;
		}
	}

	void Print() 
	{
		for (const auto& e : mHeap) 
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	void pop() 
	{
		if (mHeap.size() == 0) 
		{
			return;
		}

		mHeap[0] = mHeap.back();
		mHeap.pop_back();

		int i{};
		while (i < mHeap.size()) 
		{
			int child = (i * 2) + 1;

			if (child >= mHeap.size()) 
			{
				break;
			}

			if ((child + 1 < mHeap.size()) && (mHeap[child] < mHeap[child + 1])) 
			{
				child++;
			}

			if (mHeap[i] >= mHeap[child]) 
			{
				break;
			}

			std::swap(mHeap[i], mHeap[child]);
			i = child;
		}
	}

	int GetRoot() 
	{
		return mHeap.front();
	}
};

int main() 
{
	Heap h;
	h.Insert(1);
	h.Insert(2);
	h.Insert(3);
	h.Insert(4);
	h.Insert(5);
	h.Print();

	h.pop();
	h.Print();
}