
#define AP_INT_MAX_W 784

#include "bnn-library.h"

// includes for network parameters
#include "weights.hpp"
#include "activations.hpp"
#include "slidingwindow.h"
#include "mvau.hpp"

// defines for network parameters
#define MW1 784
 #define MH1 4

             #define SIMD1 49
 #define PE1 1
 #define WMEM1 64

             #define TMEM1 0
 #define numReps 1
#define WP1 1


void StreamingFCLayer_Batch_0(
                    hls::stream<ap_uint<98>> &in0,
                    hls::stream<ap_uint<49>> &weights,
                    hls::stream<ap_uint<16>> &out
                    )
{
#pragma HLS INTERFACE axis port=in0
#pragma HLS INTERFACE axis port=out
#pragma HLS stream depth=2 variable=in0
#pragma HLS stream depth=2 variable=out
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=weights
#pragma HLS stream depth=8 variable=weights
Matrix_Vector_PE_Batch<MW1, MH1, SIMD1, PE1, Slice<ap_int<2>>, Slice<ap_int<16>>, Recast<Binary> >
               (in0, out, weights, numReps, ap_resource_lut());
}
