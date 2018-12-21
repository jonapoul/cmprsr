#ifndef CMPRSR_ENGINE_H
#define CMPRSR_ENGINE_H

#include <string>

namespace cmprsr {

   class Engine {
   public:
      Engine();

      std::string read(std::string const& filename);

   private:
      int x;
   };

} // namespace cmprsr

#endif