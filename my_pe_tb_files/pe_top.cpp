#include <hls_stream.h>
using namespace hls;
#include "ap_int.h"
#include "bnn-library.h"


#include "pe_config.h"
#define MH 64
#define MW 16
#define SIMD 3
#define PE 8


#define OUTPUT_STREAM_WIDTH 8


#define TDstI Slice<ap_uint<OUTPUT_STREAM_WIDTH>>
#define TWeightI Identity
#define REPS 50
#define W_BITS 2
#define INPUT_BITS 8
#define TSrcI Slice<ap_uint<INPUT_BITS>>
#define INPUT_STREAM_WIDTH INPUT_BITS*SIMD
#define TW ap_uint<W_BITS>
#define WEIGHT_STREAM_WIDTH W_BITS*SIMD
void testbench_pe( stream<ap_uint<INPUT_STREAM_WIDTH>> &in, stream<ap_uint<OUTPUT_STREAM_WIDTH>> &out, stream<ap_uint<SIMD * TW::width>> & weights, int reps)
{
Matrix_Vector_PE_Batch<MW, MH, SIMD, PE, TSrcI, TDstI, TWeightI, TW>(in, out, weights, reps, ap_resource_lut());
}
