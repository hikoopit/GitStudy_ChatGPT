// Day_04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 4 : BST 노드 삭제(Delete) 구현
//  1. 값 삭제 기능 구현(deleteValue)
//  2. 삭제 시 3가지 경우 처리
//    Case 1 : 삭제할 노드가 리프(leaf) → 그냥 제거
//    Case 2 : 삭제할 노드가 자식 1개 → 자식 노드로 대체
//    Case 3 : 삭제할 노드가 자식 2개 → 오른쪽 서브트리에서 최소값 노드 찾아서 대체
// 
//  3. 50 삭제 시 → 오른쪽 서브트리(70,60)에서 최소값 60을 찾아서 50 자리에 넣고, 60은 원래 위치에서 삭제.
//    50
//   /  \
// 30    70
//      /
//    60


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
        while (node && node->left)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int key)
    {
        if (!node)
            return nullptr;

        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            if (!node->left)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inOrder(Node* node)
    {
        if (!node)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

public:
    BST() : root(nullptr)
    {

    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void deleteValue(int key)
    {
        root = deleteNode(root, key);
    }

    void printInOrder()
    {
        inOrder(root);
        cout << "\n";
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

    cout << "초기 트리(InOrder): ";
    tree.printInOrder();

    cout << "50 삭제\n";
    tree.deleteValue(50);
    tree.printInOrder();

    cout << "30 삭제\n";
    tree.deleteValue(30);
    tree.printInOrder();

    cout << "80 삭제\n";
    tree.deleteValue(80);
    tree.printInOrder();

    return 0;
}

