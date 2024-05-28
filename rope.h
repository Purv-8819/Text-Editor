#pragma once

using namespace std;

struct Node
{
   Node *left;
   Node *right;
   Node *parent;
   char *str;
   int lCount;
   int height;
};

class Rope
{
private:
   int Max_Len = 4;
   Node *root;
   Node *curr;
   int capacity;
   int size;

   void rebalance();
   void addNode();

public:
   Rope();
   Rope(string s);
   ~Rope();
   void insert(string s);
   void insert(int i, string s);
   char index(int i);
   void concat(Rope *S, bool before);
   pair<Rope *, Rope *> split(int i);
   void del(int i, int j);
   string getString();
   string getString(int i);
   string getString(int i, int j);
};
