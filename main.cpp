#include <iostream>
#include "Rope.h"

using namespace std;

int main()
{
   Rope *r = new Rope("Hello");
   r->append(" World");
   cout << r->toString() << endl;

   vector<int> test = r->buildFibList(14);
   for (int i : test)
   {
      cout << i << "||";
   }

   return 0;
}