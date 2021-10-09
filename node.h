#ifndef NODE_H
#define NODE_H
#include <stack>


class Node
{
public:
    Node();
    Node (char data, Node* left=nullptr, Node* right=nullptr);

    char getData();
    void print();
    Node * find(char data);
    void insert(char data);
    void oppg1();
    void oppg2();
    int oppg3();
    int oppg4(Node* root);
    int findMax(int a, int b);

private:
    char m_data ;
    Node* m_left;
    Node* m_right;
};

#endif // NODE_H
