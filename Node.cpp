#include "Node.h"
#include <vector>
#include <memory>

/// @brief Construct internal Node from two given nodes
/// @param l Left Child of the internal node
/// @param r Rigjt Child of the internal node
Node::Node(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
{

   this->left = std::move(l);
   this->right = std::move(r);

   this->weight = this->left->getLength();
}

/// @brief Construct leaft Node containing given string
/// @param s the string to be held in the node
Node::Node(const string &s)
{
   this->left = nullptr;
   this->right = nullptr;
   this->frag = s;
   this->weight = s.length();
}

/// @brief Copy Constructor
/// @param n Node to be copied
Node::Node(const Node &n)
{
   this->frag = n.frag;
   this->weight = n.weight;

   Node *lTemp = n.left.get();
   Node *rTemp = n.right.get();
   if (lTemp == nullptr)
   {
      this->left = nullptr;
   }
   else
   {
      this->left = make_unique<Node>(*lTemp);
   }

   if (rTemp == nullptr)
   {
      this->right = nullptr;
   }
   else
   {
      this->right = make_unique<Node>(*rTemp);
   }
}

/// @brief Checks whether the node is a leaf node
/// @return if node is leaf
bool Node::isLeaf() const
{
   return this->left == nullptr && this->right == nullptr;
}

/// @brief gets the length of the string from root plus all nodes till right most child
/// @return the lenght of the string represented by the node's children
int Node::getLength() const
{
   if (this->isLeaf())
   {
      return this->weight;
   }
   // If right is null, return 0, else recursively call for right node
   int temp = this->right == nullptr ? 0 : this->right->getLength();
   return this->weight + temp;
}

/// @brief Gets the character at index i
/// @param i index to get char at
/// @return char at index i
char Node::getCharByIndex(int i) const
{
   // If already leaf node get from given index
   if (this->isLeaf())
   {
      if (i >= this->frag.size())
      {
         throw invalid_argument("");
         return {};
      }
      else
         return this->frag[i];
   }
   else // Traver to particular node
   {
      if (i < this->weight)
      {
         return this->left->getCharByIndex(i);
      }
      else
      {
         return this->right->getCharByIndex(i - this->weight);
      }
   }
}

/// @brief Gets a substring from the nodes
/// @param start Starting index to make substring
/// @param len lenght of the substring to get
/// @return the substring from start of length len
string Node::getSubstring(int start, int len) const
{
   string result = "";
   int here = start;
   for (int i = 0; i < len; i++)
   {
      result.push_back(this->getCharByIndex(here));
      here++;
   }

   return result;
}

/// @brief Gets the string the tree holds
/// @return Returns the string the tree depics
string Node::treeToString() const
{
   // Base case
   if (this->isLeaf())
   {
      return this->frag;
   }

   // In Order Traversal
   string left = (this->left == nullptr) ? "" : this->left->treeToString();
   string right = (this->right == nullptr) ? "" : this->right->treeToString();

   // Return the left and right combined
   return left.append(right);
}

/// @brief Splits the rope at the given index
/// @param n the "root" node
/// @param i the index to split at
/// @return a pair of 2 ropes
using uniq = std::unique_ptr<Node>;

pair<uniq, uniq> splitAt(unique_ptr<Node> n, int i)
{

   if (n->isLeaf())
   {
      return pair<uniq, uniq>{
          make_unique<Node>(n->frag.substr(0, i)),
          make_unique<Node>(n->frag.substr(i, n->weight - i))};
   }

   uniq oldRight = std::move(n->right);
   // Split happens in left half
   if (i < n->weight)
   {
      // Get rid of the right branch
      n->right = nullptr;
      n->weight = i;

      // Split the left at index
      std::pair<uniq, uniq> splitLeft = splitAt(std::move(n->left), i);
      // The first half is the left child of node
      n->left = std::move(splitLeft.first);
      // The second half combined with old right is the right half of split
      return pair<uniq, uniq>{
          std::move(n),
          make_unique<Node>(std::move(splitLeft.second), std::move(oldRight))};
   }
   else if (n->weight < i) // Split occurs in right half
   {
      // Split the right half accordingly
      pair<uniq, uniq> splitRight = splitAt(std::move(oldRight), i - n->weight);

      // Right child is the front half of the split
      n->right = std::move(splitRight.first);

      // Return the node, and the second half of the split
      return pair<uniq, uniq>{
          std::move(n),
          std::move(splitRight.second)};
   }
   else // Split right down middle
   {
      return pair<uniq, uniq>{
          std::move(n->left),
          std::move(n->right)};
   }
}

/// @brief Gets the maximum depth of the rope
/// @return the max depth
int Node::getDepth() const
{
   int depth = 0;
   // Base case
   if (this->isLeaf())
   {
      return depth;
   }

   int left = (this->left == nullptr) ? 1 : this->left->getDepth() + 1;
   int right = (this->right == nullptr) ? 1 : this->right->getDepth() + 1;

   depth = (left > right) ? left : right;
   return depth;
}

/// @brief Gets all the leaves of the tree
/// @param v the vecetor to store the leaves in
void Node::getLeaves(vector<Node *> &v)
{
   // If current node is leaf, add itself to list
   if (this->isLeaf())
   {
      v.push_back(this);
   }

   Node *left = this->left.get();
   Node *right = this->right.get();

   // If left child exists get the leaves from there
   if (left != nullptr)
   {
      left->getLeaves(v);
   }

   // If right child exists get the leaves from there
   if (right != nullptr)
   {
      right->getLeaves(v);
   }
}
