#pragma once

using namespace std;

class Rope
{
private:
   Rope *parent;
   Rope *left;
   Rope *right;
   char *str;
   int lCount;

public:
   Rope();
   ~Rope();
   int test();
   void insert(int i, string s);
   char index(int i);
   void concat(Rope *S, bool before);
   pair<Rope *, Rope *> split(int i);
   void del(int i, int j);
   string getString();
   string getString(int i);
   string getString(int i, int j);
};
