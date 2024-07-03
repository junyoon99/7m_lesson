#include <iostream>
#include <stack>
#include <queue>
//그래프
// 노드와 노드가 연결된 구조

//트리
// 오직 하나의 Root를 가짐
// 두 노드를 연결하는 경로는 오직 하나

// Binary Tree
// 각 노드가 최대 두 개의 자식을 가지는 트리
// Full Binary Tree
// 모든 노드가 2개의 자식
// Perfct Binary Tree
// 모든 노드가 2개의 자식을 가지고 있으며 모든 리프 노드가 같은 레벨에 있는 트리
 

// Complete Binary Tree
// 마지막 레벨을 제외하고 모든 레벨이 완전히 채워져 있으며, 마지막 레벨의 모든 노드는 가장 왼쪽부터 채워져 있는 트리(Binary Search Tree)
//

struct Node 
{
	int mData;

	Node* mpLeft;
	Node* mpRight;
	
	Node(int data, Node* pLeft = nullptr, Node* pRight = nullptr) 
	{
		mData = data;
		mpLeft = pLeft;
		mpRight = pRight;
	}
};

class BinaryTree 
{
private:
	Node* mpRoot;
public:
	BinaryTree() { mpRoot = CreateNode(0); }

	Node* GetRoot() { return mpRoot; }

	Node* CreateNode(int data) 
	{
		return new Node(data);
	}

	Node* insertLeft(Node* parent, int data) 
	{
		parent->mpLeft = CreateNode(data);
		return parent->mpLeft;
	}
	Node* insertRight(Node* parent, int data)
	{
		parent->mpRight = CreateNode(data);
		return parent->mpRight;
	}
	//
	// Graph, Tree의 순회
	// Breadth First Search(BFS) 너비 우선 탐색
	// - 가로로 읽으면 됩니다. 같은 레벨우선으로 탐색
	// -Queue
	// Depth First Search(DFS) 깊이 우선 탐색
	// - 세로로 읽으면 됩니다. 힌 노드의 자식을 끝까지 탐색
	// -Stack (Recursive)
	//
	void Visit(Node* pNode)
	{
		std::cout << pNode->mData << " ";
	}

	//n 노드의 개수
	// Time Complexity : O(n)
	// Space Complexity : O(n)
	void BreadthFirst()
	{
		std::queue<Node*> q;
		q.push(mpRoot);

		while (!q.empty()) 
		{
			auto node = q.front();
			Visit(node);
			q.pop();

			if (node->mpLeft) 
			{
				q.push(node->mpLeft);
			}
			if (node->mpRight)
			{
				q.push(node->mpRight);
			}
		}
	}
	
	void DepthFirst() 
	{
		std::stack<Node*> s;
		s.push(mpRoot);
		while (!s.empty()) 
		{
			auto node = s.top();
			Visit(node);
			s.pop();

			if (node->mpRight)
			{
				s.push(node->mpRight);
			}

			if (node->mpLeft)
			{
				s.push(node->mpLeft);
			}
		}
	}

	void DepthFirstR(Node* pNode) 
	{
		//base case
		if (pNode == nullptr) 
		{
			return;
		}
		//recursive case
		Visit(pNode);
		DepthFirstR(pNode->mpLeft);
		DepthFirstR(pNode->mpRight);
	}
};

//Quad Tree, Oc Tree
//게임 이미지 처리에 사용하는 트리

int main() 
{
	BinaryTree tree;
	auto p = tree.GetRoot();
	p->mData = 1;
	tree.insertLeft(p, 2);
	tree.insertRight(p, 3);

	tree.insertLeft(p->mpLeft, 4);
	tree.insertRight(p->mpLeft, 5);

	tree.insertLeft(p->mpRight, 6);
	tree.insertRight(p->mpRight, 7);

	tree.BreadthFirst();
	std::cout << std::endl;
	tree.DepthFirst();
	std::cout << std::endl;
	tree.DepthFirstR(tree.GetRoot());
	std::cout << std::endl;
}