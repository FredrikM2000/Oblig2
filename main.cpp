#include <iostream>
#include "node.h"

using namespace std;

int main()
{
    //Lager treet
    Node* h = new Node ('d');
    Node* v = new Node ('a');
    v = new Node ('b', v, h);

    Node* btre = new Node ('g');
    h = new Node ('p');
    btre = new Node ('i', btre, h);
    btre = new Node ('f', v, btre);

    //btre->oppg1();
    //btre->oppg2();
    //std::cout << btre->oppg3();
    //std::cout << btre->oppg4(btre);

//    if (btre->oppg5(btre))
//            cout << "Tree is balanced";
//        else
//            cout << "Tree is not balanced";

//    Node* q = new Node ('q');
//    btre = new Node ('s', btre, q);

//    if (btre->oppg5(btre))
//            cout << "Tree is balanced";
//        else
//            cout << "Tree is not balanced";

        return 0;
}
