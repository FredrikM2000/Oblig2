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

    //std::cout << btre->getData();

    //btre->print();
    //btre->oppg1();
    //btre->oppg2();
    //std::cout << btre->oppg3();
    std::cout << btre->oppg4(btre);
}
