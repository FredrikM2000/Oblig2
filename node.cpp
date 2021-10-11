#include <iostream>
#include "node.h"
#include <stack>

Node::Node(){}

Node::Node(char data, Node* left, Node* right) : m_data{data}, m_left{left}, m_right{right}
{ }

void Node::oppg1()
{
    std::stack<Node*> stakk{};
    Node* p = this;
    do {
        //left subtree
        while (p != nullptr) {
            stakk.push(p);
            p = p->m_left;
        }
        //right subtree
        if (!stakk.empty()) {
            p = stakk.top();
            std::cout << p->m_data;
            stakk.pop();
            p = p->m_right;

        }
        //std::cout << p->m_data;
    } while (!stakk.empty() || p != nullptr);
}

void Node::oppg2()
{
    std::stack<Node*> stakk1{};
    std::stack<Node*> stakk2{};

    Node* p = this;

    stakk1.push(p);

    while(!stakk1.empty()) {
        p = stakk1.top();
        stakk1.pop();
        stakk2.push(p);

        if(p->m_left)
            stakk1.push(p->m_left);
        if(p->m_right)
            stakk1.push(p->m_right);

    }

    while(!stakk2.empty()){
        p = stakk2.top();
        stakk2.pop();
        std::cout << p->m_data;
    }

}

int Node::oppg3()
{
    std::stack<Node*> stakk{};
    Node* p = this;

    int teller = 0;

    do {
        //left subtree
        while (p != nullptr) {
            stakk.push(p);
            p = p->m_left;
        }
        //right subtree
        if (!stakk.empty()) {
            p = stakk.top();
            teller++;
            stakk.pop();
            p = p->m_right;

        }
        //std::cout << p->m_data;
    } while (!stakk.empty() || p != nullptr);
    return teller;
}



int Node::oppg4(Node* root)
{
    if(root == nullptr)
        return 0;

    int a = oppg4(root->m_left);
    int b = oppg4(root->m_right);

    if (a >= b)
        return a + 1;
    else
        return b + 1;
}

bool Node::oppg5(Node* node)
{
    int lh;
    int rh;

    if (node == nullptr)
        return 1;

    lh = oppg4(node->m_left);
    rh = oppg4(node->m_right);

    if (abs(lh-rh)<= 1 && oppg5(node->m_left) && oppg5(node->m_right))
        return 1;
    return 0;
}

