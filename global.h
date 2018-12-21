#ifndef CMPRSR_CONFIG_H
#define CMPRSR_CONFIG_H

#include <cstddef>
#include <iostream>

#define SOME_POINTLESS_FLAG

typedef unsigned char      uchar;
typedef unsigned int       uint;
typedef unsigned long long ull;

namespace cmprsr {
   inline void assert(bool const test,
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

   template <typename T>
   void printBinary(size_t const size,
                    T const& variable) {
      uchar const * const b = (uchar *)&variable;
      uchar byte;
      size_t i, j;

      for (i = size-1; i != 0; i--) {
         for (j = 7; j != 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
         }
         printf("\n");
      }
   }

} // namespace cmprsr

#define ASSERT(x) cmprsr::assert(x, #x, __FILE__, __FUNCTION__, __LINE__)
#define PRINT(x) std::cout << #x << " = '" << x << "'\n";

#endif