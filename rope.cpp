#include "Rope.h"

using namespace std;

Rope::Rope()
{
   this->root = make_unique<Node>("");
}

Rope::Rope(const string &s)
{
   this->root = make_unique<Node>(s);
}

Rope::Rope(const Rope &r)
{
   // Make a copy of the root node
   Node copy = Node(*r.root);

   // Make the root node the unique pointer to that copy
   this->root = make_unique<Node>(copy);
}

/// @brief Converts the rope to a string
/// @return Gets the string represented by the rope
string Rope::toString() const
{
   return this->root->treeToString();
}

/// @brief Gets the length of the string represented by the rope
/// @return lenght of string
int Rope::length() const
{
   return this->root->getLength();
}

/// @brief Gets the character at a specified index
/// @param i index to get the char at
/// @return characters at index i
char Rope::at(int i) const
{
   return this->root->getCharByIndex(i);
}

/// @brief Gets a substring from the nodes
/// @param start Starting index to make substring
/// @param len lenght of the substring to get
/// @return the substring from start of length len
string Rope::substring(int start, int len) const
{
   return this->root->getSubstring(start, len);
}

/// @brief Insert the given string at the specified index
/// @param i index for string to be inserted
/// @param str string to insert
void Rope::insert(int i, const string &str)
{
   this->insert(i, Rope(str));
}

/// @brief Insert the given rope at the specified index
/// @param i index for string to be inserted
/// @param r rope to insert
void Rope::insert(int i, const Rope &r)
{
   using uniq = unique_ptr<Node>;

   Rope tmp = Rope(r);
   // Split rope by where insertion needs to be made
   pair<uniq, uniq> origSplit = splitAt(std::move(this->root), i);
   // Concat the first half to inssertion
   uniq middleConcat = make_unique<Node>(std::move(origSplit.first), std::move(tmp.root));

   // Concat the end
   this->root = make_unique<Node>(std::move(middleConcat), std::move(origSplit.second));
}

/// @brief Append the given string at the end
/// @param str string to append
void Rope::append(const string &str)
{
   Rope r = Rope(str);
   this->append(r);
}

/// @brief Append the given rope at the end
/// @param r rope to append
void Rope::append(const Rope &r)
{
   Rope temp = Rope(r);
   this->root = make_unique<Node>(std::move(this->root), std::move(temp.root));
}

// Determine if rope is balanced
//
// A rope is balanced if and only if its length is greater than or equal to
//   fib(d+2) where d refers to the depth of the rope and fib(n) represents
//   the nth fibonacci number i.e. in the set {1,1,2,3,5,8,etc...}
bool Rope::isBalanced(void) const
{
   return false;
}

/// @brief Gets the nth Fibonacci number
/// @param n the number to get
/// @return Fibonacci number at nth spot
int Rope::fib(int n)
{
   if (n == 0)
   {
      return 0;
   }
   int a = 0;
   int b = 1;
   int sum;
   for (int i = 2; i < n; i++)
   {
      sum = a + b;
      a = b;
      b = sum;
   }

   return b;
}

vector<int> Rope::buildFibList(int len)
{
   int a = 0, b = 1, sum;
   vector<int> result;
   while (a <= len)
   {
      if (a > 0)
      {
         result.push_back(b);
      }

      sum = a + b;
      a = b;
      b = sum;
   }
   return result;
}