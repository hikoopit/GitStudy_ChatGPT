// Day_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// chapter 1 : BST (이진 탐색 트리 구현 예제)


#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int nVal) : data(nVal), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
	void Insert(int val)
    {
        root = InsertNode(root, val);
    }
    bool Search(int val)
    {
        return SearchNode(root, val);
    }
    void Delete(int val)
    {
        root = DeleteNode(root, val);
    }
    void InOrder()
    {
        cout << "중위 순회: ";
        InOderTraversal(root);
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
    bool SearchNode(TreeNode* node, int val)
    {
        if (!node)
            return false;

        if (val == node->data)
            return true;

        if (val < node->data)
            return SearchNode(node->left, val);
        else
            return SearchNode(node->right, val);
    }
    TreeNode* DeleteNode(TreeNode* node, int val)
    {
        if (!node)
            return nullptr;

        if (val < node->data)
            node->left = DeleteNode(node->left, val);
        else if (val > node->data)
            node->right = DeleteNode(node->right, val);
        else
        {
            if (!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            else if (!node->left)
            {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                TreeNode* minNode = FindMin(node->right);
                node->data = minNode->data;
                node->right = DeleteNode(node->right, minNode->data);
            }
        }

        return node;
    }
    TreeNode* FindMin(TreeNode* node)
    {
        while (node && node->left)
            node = node->left;

        return node;
    }
    void InOderTraversal(TreeNode* node)
    {
        if (!node)
            return;

        InOderTraversal(node->left);
        cout << node->data << " ";
        InOderTraversal(node->right);
    }
};

void ShowMenu()
{
    cout << "\n[메뉴]\n";
    cout << "1. 삽입\n";
    cout << "2. 탐색\n";
    cout << "3. 삭제\n";
    cout << "4. 중위 순회 출력\n";
    cout << "5. 종료\n";
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
        case 1: // 삽입
            cout << "삽입할 값: ";
            cin >> value;
            bst.Insert(value);
            break;
        case 2: // 검색
            cout << "탐색할 값: ";
            cin >> value;   
            if (bst.Search(value))
                cout << "=> 찾았습니다.\n";
            else
                cout << "=> 없습니다.\n";
            break;
        case 3: // 삭제
            cout << "삭제할 값: ";
            cin >> value;
            bst.Delete(value);
            cout << "삭제 완료\n";
            break;
        case 4: // 중위 순회 (존재하는 값 크기 순서대로 정렬)
            bst.InOrder();
            break;
        case 5:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        default:
            cout << "잘못된 입력입니다.\n";
        }
    }

    return 0;
}