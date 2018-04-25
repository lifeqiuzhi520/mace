// Copyright 2018 Xiaomi, Inc.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mace/ops/folded_batch_norm.h"

namespace mace {
namespace ops {

void Register_FoldedBatchNorm(OperatorRegistry *op_registry) {
  REGISTER_OPERATOR(op_registry, OpKeyBuilder("FoldedBatchNorm")
                                     .Device(DeviceType::CPU)
                                     .TypeConstraint<float>("T")
                                     .Build(),
                    FoldedBatchNormOp<DeviceType::CPU, float>);

#ifdef MACE_ENABLE_OPENCL
  REGISTER_OPERATOR(op_registry, OpKeyBuilder("FoldedBatchNorm")
                                     .Device(DeviceType::OPENCL)
                                     .TypeConstraint<float>("T")
                                     .Build(),
                    FoldedBatchNormOp<DeviceType::OPENCL, float>);

  REGISTER_OPERATOR(op_registry, OpKeyBuilder("FoldedBatchNorm")
                                     .Device(DeviceType::OPENCL)
                                     .TypeConstraint<half>("T")
                                     .Build(),
                    FoldedBatchNormOp<DeviceType::OPENCL, half>);
#endif  // MACE_ENABLE_OPENCL

  REGISTER_OPERATOR(op_registry, OpKeyBuilder("FoldedBatchNorm")
                                     .Device(DeviceType::NEON)
                                     .TypeConstraint<float>("T")
                                     .Build(),
                    FoldedBatchNormOp<DeviceType::NEON, float>);
}

}  // namespace ops
}  // namespace mace
