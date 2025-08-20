// Day_07.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 6 : 트리 통계 기능
// 지금까지는 “트리가 맞는지, 균형인지, 탐색이 잘 되는지”를 다뤘는데, 이제는 트리 내부의 통계적인 정보를 구해봅니다.
// 
// 1. Day 7 목표
//   a. 전체 노드 개수 세기
//   b. 리프 노드 개수(자식이 없는 노드) 세기
//   c. 내부 노드 개수(자식이 있는 노드) 세기
// 2. 개념
//   a. 노드(Node) 개수
//     - count(node) = 1 + count(left) + count(right)
//   b. 리프 노드(Leaf)
//     - 왼쪽도 없고, 오른쪽도 없으면 → leafCount += 1
//   c. 내부 노드(Internal)
//     - 루트 포함해서 자식이 하나 이상 있는 노드
//     - internalCount = totalCount - leafCount 로도 계산 가능
// 3. 쓰임새
//   a. 데이터 구조 분석 : 트리의 크기, 복잡도 파악
//   b. 메모리 최적화 : 리프가 많으면 포인터 낭비가 적음, 내부 노드가 많으면 구조가 깊음
//   c. 알고리즘 기초 : 향후 트리 기반 알고리즘(압축, 탐색 최적화, 경로 탐색)에서 통계 정보 활용

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

    int countNodes(Node* node)
    {
        if (!node)
            return 0;

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node* node)
    {
        if (!node)
            return 0;

        if (!node->left && !node->right)
            return 1;

        return countLeaves(node->left) + countLeaves(node->right);
    }

public:
    BST() : root(nullptr)
    {

    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void printStats()
    {
        int total = countNodes(root);
        int leaves = countLeaves(root);
        int internal = total - leaves;

        cout << "전체 노드 수: " << total << "\n";
        cout << "리프 노드 수: " << leaves << "\n";
        cout << "내부 노드 수: " << internal << "\n";
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

    tree.printStats();
}

