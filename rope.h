#pragma once

using namespace std;

class Rope
{
private:
   Rope* parent;
   Rope* left;
   Rope* right;
   char* str;
   int lCount;
public:
   Rope(/* args */);
   ~Rope();
};

