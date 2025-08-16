// Day_05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 5 : 트리의 높이(Height) 계산 & 균형 여부 확인 (트리의 구조적인 특성)
// 1. 트리 높이(Height) 계산
//  - 노드가 없으면 0
//  - 있으면 1 + max(왼쪽 높이, 오른쪽 높이)
// 2. 균형 여부 확인
//  - 모든 노드에서 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이 ≤ 1
//  - 균형 → True / 불균형 → False
// 3. 트리 높이
//     50      (높이 = 3)
//    /  \
//  30    70
// /

#include <iostream>
#include <algorithm>

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

    int getHeight(Node* node)
    {
        if (!node)
            return 0;

        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    bool isBalanced(Node* node)
    {
        if (!node)
            return true;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalanced(node->left) && isBalanced(node->right);
    }

public:
    BST() : root(nullptr)
    {

    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void printHeight()
    {
        cout << "트리 높이: " << getHeight(root) << "\n";
    }

    void checkBalance()
    {
        if (isBalanced(root))
            cout << "트리는 균형 상태 입니다.\n";
        else
            cout << "트리는 불균형 상태 입니다.\n";
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

    tree.printHeight();
    tree.checkBalance();

    BST skewedTree;
    skewedTree.insert(10);
    skewedTree.insert(20);
    skewedTree.insert(30);
    skewedTree.insert(40);
    skewedTree.insert(50);

    skewedTree.printHeight();
    skewedTree.checkBalance();
}
