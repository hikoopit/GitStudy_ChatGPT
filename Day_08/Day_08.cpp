// Day_08.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 8 : 최소값/최대값 찾기
// 1. Day 8 목표
//   a. 최소값(Minimum) 찾기 → 가장 왼쪽 끝 노드
//   b.최대값(Maximum) 찾기 → 가장 오른쪽 끝 노드
// 2. 개념
//   a. BST 성질 :
//     - 왼쪽 자식은 항상 더 작음
//     - 오른쪽 자식은 항상 더 큼
//   b. 따라서 :
//     - 최소값 → root->left->left->... 끝까지 가면 됨
//     - 최대값 → root->right->right->... 끝까지 가면 됨
//   c. 시간 복잡도 : O(h) (h = 트리 높이)
//     - 평균 : O(log n)
//     - 최악(편향 트리) : O(n)

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

    Node* findMin(Node* node)
    {
        if (!node)
            return nullptr;

        while (node->left)
        {
            node = node->left;
        }

        return node;
    }

    Node* findMax(Node* node)
    {
        if (!node)
            return nullptr;

        while (node->right)
        {
            node = node->right;
        }

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

    void printManMax()
    {
        Node* minNode = findMin(root);
        Node* maxNode = findMax(root);

        if (minNode)
            cout << "최소값: " << minNode->data << "\n";
        else
            cout << "트리가 비어있음\n";

        if (maxNode)
            cout << "최대값: " << maxNode->data << "\n";
        else
            cout << "트리가 비어있음\n";
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

    tree.printManMax();

    return 0;
}
