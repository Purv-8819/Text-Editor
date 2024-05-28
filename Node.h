#pragma once

#include <string>

using namespace std;

class Node
{
private:
   unique_ptr<Node> left;
   unique_ptr<Node> right;
   string frag;
   int weight;

   bool isLeaf() const;

public:
   // Constructor

   // Construct internal node from 2 other nodes
   Node(unique_ptr<Node> l, unique_ptr<Node> r);
   // Construct leaf node with string
   Node(string &s);
   // Copy Constructor
   Node(Node &);

   // Accessors
   int getLength() const;
   char getCharByIndex(int i) const;
   // Get the substring of (len) chars beginning at index (start)
   string getSubstring(int start, int len) const;
   // Get string contained in current node and its children
   string treeToString() const;

   // Helper
   // Used in balancing
   int getDepth() const;
   void getLeaves(std::vector<Node *> &v);
};
