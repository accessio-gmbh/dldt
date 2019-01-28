/*
// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once

#include "convolution_kernel_imad_3x3.h"

namespace kernel_selector {

    // TODO Currently the best 1x1 IMAD convolution kernel is not completely done.
    // Temporary solution to implement 1x1 using 3x3 IMAD convolution kernel with a
    // little modifications.
    class ConvolutionKernel_imad_1x1 : public ConvolutionKernel_imad_3x3
    {
    public:
        using Parent = ConvolutionKernel_imad_3x3;
        ConvolutionKernel_imad_1x1() {}
        virtual ~ConvolutionKernel_imad_1x1() {}

        virtual KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;
        virtual ParamsKey GetSupportedKey() const override;
        KernelsData GetCommonKernelsData(const Params& params, const optional_params& options, const std::string exeMode = DEFAULT, int autoTuneIndex = -1) const;

    protected:
        virtual bool Validate(const Params& params, const optional_params& options) const override;
        JitConstants GetJitConstants(const convolution_params& params, const DispatchData& kd) const override;
        DispatchData SetDefault(const convolution_params& params, int autoTuneIndex = -1) const override;

        std::vector<WeightsLayout> GetSupportedWeightLayouts(const convolution_params&) const override
        {
            return{
                WeightsLayout::os_is_yx_osv16_isv4
            };
        }
    };
}
