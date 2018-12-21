#ifndef CMPRSR_CONFIG_H

#define SOME_POINTLESS_FLAG

namespace cmprsr {
   void assert(bool const test,
               char const * const testString,
               char const * const file,
               char const * const function,
               int const line);
}

#define ASSERT(x) cmprsr::assert(x,#x,__FILE__,__FUNCTION__,__LINE__)

#endif