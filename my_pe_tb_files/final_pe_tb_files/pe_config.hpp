/*#define MH 64
#define MW 27
#define SIMD 3
#define PE 8
#define INPUT_STREAM_WIDTH 
#define WEIGHT_STREAM_WIDTH 4
#define OUTPUT_STREAM_WIDTH 4
//#define TW ap_uint<2>
//#define TSrcI Slice<ap_uint<2>>
//#define TDstI Slice<ap_uint<16>>
//#define TWeightsI Slice<ap_uint<2>>
#define REPS 50
#define W_BITS 2
#define INPUT_BITS 2*/

#ifndef PE_CONFIG_H
#define PE_CONFIG_H

#define MH 64
#define MW 16
#define SIMD 2
#define PE 8


#define OUTPUT_STREAM_WIDTH 8


#define TDstI Slice<ap_int<OUTPUT_STREAM_WIDTH>>
#define TWeightI Identity
#define REPS 5
#define W_BITS 2
#define INPUT_BITS 2
#define TSrcI Slice<ap_int<INPUT_BITS>>
#define INPUT_STREAM_WIDTH INPUT_BITS*SIMD
#define TW ap_int<W_BITS>
#define WEIGHT_STREAM_WIDTH W_BITS*SIMD
#define INPUT_STREAM_TYPE ap_uint<INPUT_STREAM_WIDTH>
#define OUTPUT_STREAM_TYPE ap_uint<OUTPUT_STREAM_WIDTH>
#define WEIGHT_STREAM_TYPE ap_uint<SIMD * TW::width>

#endif
