#include <iostream>
#include "node.h"
#include <stack>

Node::Node(){}

Node::Node(char data, Node* left, Node* right) : m_data{data}, m_left{left}, m_right{right}
{ }
char Node::getData() {return m_data;}

Node *Node::find(char data)
{
    // std::cout << m_data;
    if(m_data == data)
         return this;
    else if (data < m_data && m_left!= nullptr)
        return m_left->find(data) ;
    else if (m_right) // m_data <= data
         return m_right->find(data);
    // kun hvis noden ikke finnes, kommer vi hit
    return nullptr;
}

void Node::insert(char data)
{
    if(data < m_data) {
        if(m_left)
            m_left->insert(data);
        else
            m_left = new Node(data);
    }
    else if (data > m_data) {
        if (m_right)
            m_right->insert(data);
        else
            m_right = new Node(data);
    }
}

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
            std::cout << p->m_data; //INORDER
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

    return findMax(oppg4(root->m_left), oppg4(root->m_right)) + 1;
}

int Node::findMax(int a, int b){
    if (a >= b)
        return a;
    else
        return b;
}

void Node::print()
{
    if(m_left)
        m_left->print();
    std::cout << m_data;
    if(m_right)
        m_right->print();
}







