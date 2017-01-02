# A rule that builds a C/C++ native executable from a single .cpp file
# its corresponding header, and a C/C++ library dependency.
cxx_binary(
  name = 'echo',
  srcs = [
  'echo.cc',
  ],
  headers = [
#'echo.h',
  ],
#  deps = [
#  ':util',
#  ],
  )

# To build without stripping:
# buck build :echo

# To build with stripping debug symbols only:
# buck build :echo#strip-debug
