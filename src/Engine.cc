#include <cerrno>
#include <string>
#include <fstream>

#include "global.h"
#include "Engine.h"

using namespace cmprsr;

Engine::Engine() {
   /* blank */
}

std::string Engine::read(std::string const& filename) {
   std::ifstream in(filename, std::ios::in | std::ios::binary);
   if (in) {
     std::string contents;
     in.seekg(0, std::ios::end);
     contents.resize(in.tellg());
     in.seekg(0, std::ios::beg);
     in.read(&contents[0], contents.size());
     in.close();
     return contents;
  } else {
     throw errno;
  }
}