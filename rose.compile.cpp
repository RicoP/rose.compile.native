#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ROSE_FORMAT_IMPL
#include <rose/printf.h>
#include <roseio.h>

#define IMPL_SERIALIZER
#include "options.h"
#include <components/padevents.h>
#include <components/workspace.h>
#include <components/components_ser.h>
#include "rose.compile.serializer.h"

void error(const char *msg) {
  rose::printf({msg});
  std::exit(1);
}

int main(int argc, char **argv) {
  for (int i = 1; i != argc; ++i) {
    if (std::strcmp(argv[i], "-O") == 0) {
      if (i + 1 == argc) {
        error("-I requires an argument");
      }
      auto options = rose::io::json::read<CompileOptions>(
          rose::io::Folder::Working, argv[i + 1]);

      for (auto path : options.includePaths) {
        rose::println({path.string});
      }
      rose::println({argv[i + 1]});
      ++i;
    }
  }
  return 0;
}