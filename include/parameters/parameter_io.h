/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Matt Olan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INCLUDE_PARAMETERS_PARAMETER_IO_H_
#define INCLUDE_PARAMETERS_PARAMETER_IO_H_

#include <parameters/internal_constants.h>
#include <cstdint>

class parameter_io
{
public:
    static uint64_t extract_data_length(uint64_t commonFecOTI);
    static uint16_t extract_symbol_size(uint64_t commonFecOTI);
    static uint8_t extract_num_source_blocks(uint32_t schemeSpecFecOTI);
    static uint16_t extract_interleaver_length(uint32_t schemeSpecFecOTI);
    static uint8_t extract_symbol_alignment(uint32_t schemeSpecFecOTI);
    static uint8_t extract_source_block_number(uint32_t fecPayloadID);
    static uint32_t extract_encoding_symbol_id(uint32_t fecPayloadID);
    static uint64_t build_common_fec_oti(uint64_t dataLen, uint16_t symbolSize);
    static uint64_t canonicalize_common_fec_oti(uint64_t commonFecOTI);
    static uint32_t build_scheme_spec_fec_oti(uint8_t numSrcBs, uint16_t interLen,
            uint8_t sAlign);
    static uint32_t build_fec_payload_id(uint8_t sbn, uint32_t esi);

private:
    static int data_length_shift();
    static int num_source_blocks_shift();
    static int interleaver_length_shift();
    static int source_block_number_shift();
};

#endif  // INCLUDE_PARAMETERS_PARAMETER_IO_H_
