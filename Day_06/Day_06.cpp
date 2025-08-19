// Day_06.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 6 : 이진 트리가 BST(Binary Search Tree)인지 확인
// 지금까지는 우리가 직접 삽입하면서 BST의 성질을 유지했는데,
// 현실에서는 “이미 만들어진 트리”가 진짜 BST인지 검증해야 할 때가 많습니다.
// 
// 1. Day 6 목표
//    a. 트리가 BST인지 검사하는 함수 구현
//      - BST 성질 : 왼쪽 서브트리 < 루트 < 오른쪽 서브트리
//      - 모든 노드에서 이 조건이 만족해야 함
//    b. 중위 순회를 활용한 검증 방법 배우기
// 2. 개념
//    a. 방법 1: 중위 순회(Inorder Traversal) 활용
//     - BST를 중위 순회하면 항상 정렬된 오름차순 배열이 나와야 함
//     - 오름차순이 깨지면 BST 아님
//   b. 방법 2: 범위 제한(Recursive Range Check)
//     - 각 노드가 가질 수 있는 값의 허용 범위(min, max) 를 전달하면서 검사
//     - 예 : 루트(50)의 왼쪽은(-∞, 50), 오른쪽은(50, ∞)
// 3. 정리
//   a. Day 6 핵심: “트리가 진짜 BST인지 확인할 수 있어야 한다”
//   b. 쓰임새 :
//     - 파일 / 네트워크에서 불러온 트리 구조 검증
//     - AI / 게임 / DB 엔진에서 데이터 구조 무결성 체크
//     - AVL / Red - Black 같은 고급 트리 설계에서 사전 검증

#include <iostream>
#include <climits>
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

class TreeChecker
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

    bool isBSTUtil(Node* node, long minVal, long maxVal)
    {
        if (!node)
            return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return isBSTUtil(node->left, minVal, node->data) && isBSTUtil(node->right, node->data, maxVal);
    }

public:
    TreeChecker() : root(nullptr)
    {

    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    bool isBST()
    {
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }

    void makeInvalidTree()
    {
        if (root && root->data)
        {
            root->left->right = new Node(1000);
        }
    }
};

int main()
{
    TreeChecker tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << (tree.isBST() ? "BST 맞음\n" : "BST 아님\n");
    tree.makeInvalidTree();
    cout << (tree.isBST() ? "BST 맞음\n" : "BST 아님\n");
}
