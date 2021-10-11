#include <iostream>
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{
    Node* h = new Node ('d');
    Node* v = new Node ('a');
    v = new Node ('b', v, h);
    // peker h er ledig
    Node* btre = new Node ('g');
    h = new Node ('p');
    btre = new Node ('i', btre, h);
    btre = new Node ('f', v, btre);


    Node* test = new Node ('q');
    Node* test2 = new Node('w');

    btre = new Node ('s', btre, test);
    //std::cout << btre->getData();
    std::cout << btre->height(btre);

    //btre->print();
    //btre->oppg1();
    //btre->oppg2();
    //std::cout << btre->oppg3();

    if (btre->isBalanced(btre))
            cout << "Tree is balanced";
        else
            cout << "Tree is not balanced";
        return 0;
}
