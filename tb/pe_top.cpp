#include <hls_stream.h>
using namespace hls;
#include "ap_int.h"
#include "bnn-library.h"


#include "pe_config.h"

void testbench_pe( stream<ap_uint<INPUT_STREAM_WIDTH>> &in, stream<ap_uint<OUTPUT_STREAM_WIDTH>> &out, stream<ap_uint<WEIGHT_STREAM_WIDTH>> & weights, reps)
{
Matrix_Vector_PE_Batch<MW, MH, SIMD, PE, TSrcI, TDstI, TWeightI, TW>(in, out, weights, reps, ap_resource_lut());
}
