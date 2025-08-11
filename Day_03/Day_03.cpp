// Day_03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// chapter 3 : 값 탐색, 최솟값, 최댓값 찾기
// 값 탐색
//  주어진 값이 트리에 존재하는지 확인(bool search(int key))
//  찾으면 "있음", 없으면 "없음" 출력
// 
// 최솟값 & 최댓값 찾기
//  최솟값 : 왼쪽 끝 노드
//  최댓값 : 오른쪽 끝 노드
// 
// 개념 정리
//  BST에서는 왼쪽 자식 < 부모 < 오른쪽 자식
//  따라서 최소값은 왼쪽으로 쭉 내려가면 되고,
//  최대값은 오른쪽으로 쭉 내려가면 됨.
//  
//  탐색 시간 복잡도 : 평균 O(log n) (트리가 균형 잡혀있을 때)

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int value) : data(value), left(nullptr), right(nullptr)
	{
	}
};

class BST
{
private:
	Node* root;

	Node* insert(Node* node, int value)
	{
		if (!node)
			return new Node(value);

		if (value < node->data)
			node->left = insert(node->left, value);
		else if (value > node->data)
			node->right = insert(node->right, value);

		return node;
	}

	bool search(Node* node, int key)
	{
		if (!node)
			return false;

		if (node->data == key)
			return true;

		if (key < node->data)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	Node* FindMin(Node* node)
	{
		while (node && node->left)
			node = node->left;

		return node;
	}

	Node* FindMax(Node* node)
	{
		while (node && node->right)
			node = node->right;

		return node;
	}

public:
	BST() : root(nullptr)
	{

	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	void searchValue(int key)
	{
		if (search(root, key))
			cout << key << " 는(은) 트리에 있습니다.\n";
		else
			cout << key << " 는(은) 트리에 없습니다.\n";
	}

	void printMinMax()
	{
		Node* MinNode = FindMin(root);
		Node* MaxNode = FindMax(root);

		if (MinNode && MaxNode)
		{
			cout << "최솟값: " << MinNode->data << "\n";
			cout << "최댓값: " << MaxNode->data << "\n";
		}
		else
		{
			cout << "트리가 비어있습니다.\n";
		}
	}
};

int main()
{
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(60);
	tree.insert(80);

	tree.searchValue(60);
	tree.searchValue(25);

	tree.printMinMax();

	return 0;
}