// Day_02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 2 : 트리 순회 기능 확장
//             전위(pre - order), 후위(post - order), 레벨 순서(level - order) 순회 추가
//             재귀 vs 반복(스택 / 큐) 구현 비교


#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
	void Insert(int val)
	{
		root = InsertNode(root, val);
	}

	void InOrder()
	{
		cout << "중위 순회: ";
		InOrderTraversal(root);
		cout << endl;
	}

	void PreOrder()
	{
		cout << "전위 순회: ";
		PreOrderTraversal(root);
		cout << endl;
	}

	void PostOrder()
	{
		cout << "후위 순회: ";
		PostOrderTraversal(root);
		cout << endl;
	}

	void LevelOrder()
	{
		cout << "레벨 순회: ";
		LevelOrderTraversal(root);
		cout << endl;
	}

private:
	TreeNode* root = nullptr;

	TreeNode* InsertNode(TreeNode* node, int val)
	{
		if (!node)
			return new TreeNode(val);

		if (val < node->data)
			node->left = InsertNode(node->left, val);
		else if (val > node->data)
			node->right = InsertNode(node->right, val);

		return node;
	}

	void InOrderTraversal(TreeNode* node)
	{
		if (!node)
			return;

		InOrderTraversal(node->left);
		cout << node->data << " ";
		InOrderTraversal(node->right);
	}

	void PreOrderTraversal(TreeNode* node)
	{
		if (!node)
			return;

		cout << node->data << " ";
		PreOrderTraversal(node->left);
		PreOrderTraversal(node->right);
	}

	void PostOrderTraversal(TreeNode* node)
	{
		if (!node)
			return;

		PostOrderTraversal(node->left);
		PostOrderTraversal(node->right);
		cout << node->data << " ";
	}

	void LevelOrderTraversal(TreeNode* node)
	{
		if (!node)
			return;

		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty())
		{
			TreeNode* curr = q.front();
			q.pop();

			cout << curr->data << " ";
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}
	}
};

void ShowMenu()
{
	cout << "\n[메뉴]\n";
	cout << "1. 삽입\n";
	cout << "2. 중위 순회\n";
	cout << "3. 전위 순회\n";
	cout << "4. 후위 순회\n";
	cout << "5. 레벨 순회\n";
	cout << "6. 종료\n";
	cout << ">> ";
}

int main()
{
	BinarySearchTree bst;
	int choice, value;

	while (true)
	{
		ShowMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "삽입할 값: ";
			cin >> value;
			bst.Insert(value);
			break;
		case 2:
			bst.InOrder();
			break;
		case 3:
			bst.PreOrder();
			break;
		case 4:
			bst.PostOrder();
			break;
		case 5:
			bst.LevelOrder();
			break;
		case 6:
			cout << "프로그램을 종료합니다.\n";
			return 0;
		default:
			cout << "잘못된 입력입니다.\n";
		}
	}
}