/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/kernels/cwise_ops_common.h"

namespace tensorflow {
REGISTER5(BinaryOp, CPU, "Pow", functor::pow, float, Eigen::half, double,
          complex64, complex128);
REGISTER2(BinaryOp, CPU, "Pow", functor::safe_pow, int32, int64);

//#if GOOGLE_CUDA
REGISTER(BinaryOp, GPU, "Pow", functor::pow, float);
//#endif
#ifdef TENSORFLOW_USE_SYCL
REGISTER2(BinaryOp, SYCL, "Pow", functor::pow, float, double);
#endif  // TENSORFLOW_USE_SYCL
}  // namespace tensorflow
