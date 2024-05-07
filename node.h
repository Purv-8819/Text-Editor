#pragma once
#include <string>

using namespace std;

class Node
{
private:
   int data;
   Node* left;
   Node* right;
public:
   Node(/* args */);
   ~Node();
};

Node::Node(/* args */)
{
}

Node::~Node()
{
}


class Leaf: private Node
{
private:
   string data;

public:
   Leaf(/* args */);
   ~Leaf();
};

Leaf::Leaf(/* args */)
{
}

Leaf::~Leaf()
{
}
