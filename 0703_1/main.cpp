#include <iostream>
#include <stack>
#include <queue>
//�׷���
// ���� ��尡 ����� ����

//Ʈ��
// ���� �ϳ��� Root�� ����
// �� ��带 �����ϴ� ��δ� ���� �ϳ�

// Binary Tree
// �� ��尡 �ִ� �� ���� �ڽ��� ������ Ʈ��
// Full Binary Tree
// ��� ��尡 2���� �ڽ�
// Perfct Binary Tree
// ��� ��尡 2���� �ڽ��� ������ ������ ��� ���� ��尡 ���� ������ �ִ� Ʈ��
 

// Complete Binary Tree
// ������ ������ �����ϰ� ��� ������ ������ ä���� ������, ������ ������ ��� ���� ���� ���ʺ��� ä���� �ִ� Ʈ��(Binary Search Tree)
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
	// Graph, Tree�� ��ȸ
	// Breadth First Search(BFS) �ʺ� �켱 Ž��
	// - ���η� ������ �˴ϴ�. ���� �����켱���� Ž��
	// -Queue
	// Depth First Search(DFS) ���� �켱 Ž��
	// - ���η� ������ �˴ϴ�. �� ����� �ڽ��� ������ Ž��
	// -Stack (Recursive)
	//
	void Visit(Node* pNode)
	{
		std::cout << pNode->mData << " ";
	}

	//n ����� ����
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
//���� �̹��� ó���� ����ϴ� Ʈ��

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