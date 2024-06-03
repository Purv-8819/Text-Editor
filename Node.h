#pragma once

#include <memory>
#include <string>

using namespace std;

class Node
{
private:
   unique_ptr<Node> left;
   unique_ptr<Node> right;
   string frag;
   int weight;

public:
   // Constructor

   // Construct internal node from 2 other nodes
   Node(unique_ptr<Node> l, unique_ptr<Node> r);
   // Construct leaf node with string
   Node(const string &s);
   // Copy Constructor
   Node(const Node &n);

   // Accessors
   int getLength() const;
   char getCharByIndex(int i) const;
   // Get the substring of (len) chars beginning at index (start)
   string getSubstring(int start, int len) const;
   // Get string contained in current node and its children
   string treeToString() const;

   using uniq = unique_ptr<Node>;
   // Mutator
   friend pair<uniq, uniq> splitAt(uniq n, int i);

   // Helper
   // Used in balancing
   bool isLeaf() const;
   int getDepth() const;
   void getLeaves(vector<Node *> &v);
};
