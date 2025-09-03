// Day_09.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 9 : 트리의 높이 계산
//            50
//      30            70
//   20     40     X     80
//         X  35
// 📌 Day 9 목표
// 1. 트리의 높이(Height) 구하기
// 루트에서 가장 깊은 리프까지의 경로 길이
// 2. 트리의 깊이(Depth) 이해하기
// 특정 노드가 루트에서 얼마나 떨어져 있는가
// 
// 🧠 개념 정리
// 1. 높이(Height)
// 트리 전체에서 가장 긴 경로의 길이
// 재귀적으로 정의 :
// height(node) = 1 + max(height(left), height(right))
// 빈 트리의 높이 = 0
// 2. 깊이(Depth)
// 개별 노드 기준, 루트까지 몇 단계 떨어져 있는지
// 구현은 BFS / DFS로 가능(오늘은 전체 트리 높이만 다룸)
// 
// 📌 쓰임새
// 1. 성능 분석
// BST는 이상적으로 O(log n) 탐색 → 높이가 크면 O(n)으로 퇴화
// 따라서 높이 계산은 균형 여부 점검에 쓰임
// 2. 균형 트리 설계
// AVL, Red - Black Tree 같은 균형 트리 구현에서 높이는 핵심 지표
// 3. 네트워크 / 경로 탐색
// 트리 높이는 “최악의 경우 몇 단계 이동하는지”를 의미
// 네트워크 라우팅, 파일시스템 탐색에 응용

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

    int getHeight(Node* node)
    {
        if (!node)
            return 0; // 빈 트리 높이

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
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
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(35); // 일부러 깊게 넣기
    tree.insert(80);

    tree.printHeight();

    return 0;
}
