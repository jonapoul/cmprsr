#include "global.h"
#include "Engine.h"

int main() {

   char var = 'a';
   cmprsr::printBinary(sizeof(var), &var);
   cmprsr::Engine engine;
   std::string str = engine.read("README.md");
   PRINT(str);
   return 0;
}
