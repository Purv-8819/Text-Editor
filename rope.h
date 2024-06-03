#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "Node.h"

using namespace std;

class Rope
{
private:
   unique_ptr<Node> root;

   /// For balancing use
   int fib(int n);

public:
   vector<int> buildFibList(int len);
   // Constructors

   // Default constructor - produces a rope representing the empty string
   Rope();
   // Construct a rope from the given string
   Rope(const string &str);
   // Copy constructor
   Rope(const Rope &r);

   // Accessors

   // Get the string stored in the rope
   string toString() const;
   // Get the length of the stored string
   int length() const;
   // Get the character at the given position in the represented string
   char at(int index) const;
   // Return the substring of length (len) beginning at the specified index
   string substring(int start, int len) const;
   // Determine if rope is balanced
   bool isBalanced() const;
   // Balance the rope
   void balance();

   // Mutator

   // Insert the given string/rope into the rope, beginning at the specified index (i)
   void insert(int i, const string &str);
   void insert(int i, const Rope &r);
   // Concatenate the existing string/rope with the argument
   void append(const string &s);
   void append(const Rope &r);
   // Delete the substring of (len) characters beginning at index (start)
   void rdelete(int start, int len);
};
