
// =================================================================================================
// This file is part of the CLBlast project. The project is licensed under Apache Version 2.0. This
// project loosely follows the Google C++ styleguide and uses a tab-size of two spaces and a max-
// width of 100 characters per line.
//
// Author(s):
//   Cedric Nugteren <www.cedricnugteren.nl>
//
// =================================================================================================

#include "test/correctness/testblas.hpp"
#include "test/routines/level2/xhpmv.hpp"

// Shortcuts to the clblast namespace
using float2 = clblast::float2;
using double2 = clblast::double2;

// Main function (not within the clblast namespace)
int main(int argc, char *argv[]) {
  auto errors = size_t{0};
  errors += clblast::RunTests<clblast::TestXhpmv<float2>, float2, float2>(argc, argv, false, "CHPMV");
  errors += clblast::RunTests<clblast::TestXhpmv<double2>, double2, double2>(argc, argv, true, "ZHPMV");
  if (errors > 0) { return 1; } else { return 0; }
}

// =================================================================================================
