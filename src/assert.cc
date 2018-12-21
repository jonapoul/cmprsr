#include <iostream>

#include "config.h"

void cmprsr::assert(bool const test,
                    char const * const testString,
                    char const * const file,
                    char const * const function,
                    int const line) {
   if (!test) {
      printf("========== ASSERT FAILED ==========\n");
      printf("Test     = '%s'\n", testString);
      printf("File     = '%s'\n", file);
      printf("Function = '%s'\n", function);
      printf("Line     = '%d'\n", line);
      printf("===================================\n");
   }
}
