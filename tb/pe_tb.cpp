#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <hls_stream.h>
#include <cstdlib>
#define AP_INT_MAX_W 16384
#include "ap_int.h"
#include "weights.hpp"
#include "bnn-library.h"

#include "pe_config.h"

#include "activations.hpp"
#include "interpret.hpp"
#include <math.h>
#include <stdlib.h>

using namespace hls;
using namespace std;


void testbench_pe( stream<ap_uint<INPUT_STREAM_WIDTH>> &in, stream<ap_uint<OUTPUT_STREAM_WIDTH>> &out, stream<ap_uint<WEIGHT_STREAM_WIDTH>> & weights, int reps);

void sw_mult_mm(ap_uint<INPUT_STREAM_WIDTH> inp_value, ap_uint<WEIGHT_STREAM_WIDTH> wgt_value, ap_uint<OUTPUT_STREAM_WIDTH>   & out) {
    /*    static int state = 0;
        static ap_uint<OUTPUT_STREAM_WIDTH> total = 0;
             ap_uint<INPUT_STREAM_WIDTH> sub_inp;
             ap_uint<OUTPUT_STREAM_WIDTH> sub_tot;
             ap_uint<TW::width> sub_wgt
        for(int i = 0; i < SIMD; i++) {
             sub_inp = inp_value((i + 1)*INPUT_BITS-1, i*INPUT_BITS);
             sub_wgt = wgt_value((i + 1)*W_BITS-1, i*W_BITS);
             sub_tot += sub_inp * sub_wgt;
        }
        total += sub_tot;
        state++;
        if (state == ((MW/SIMD) - 1))){
             out = total;
             total= 0;
             state = 0;

       }*/
}

int main()
{

	stream<ap_uint<INPUT_STREAM_WIDTH> > input_stream1("input_stream1");
        stream<ap_uint<WEIGHT_STREAM_WIDTH>>  weight_stream("weight_stream");
	stream<ap_uint<OUTPUT_STREAM_WIDTH> > output_stream("output_stream");
        unsigned const int max_input_val = (int) pow(2, INPUT_STREAM_WIDTH);
        unsigned const int max_weight_val = (int)pow(2, (SIMD * TW::WIDTH)); 
	static ap_uint<OUTPUT_STREAM_WIDTH> expected[REPS];

	unsigned int count_out = 0;
	unsigned int count_in = 0;

	for (unsigned int counter = 0; counter < REPS; counter++) {
          for(unsigned int rep = 0; rep < (MW/SIMD); rep++){
                unsigned int inp = rand() % max_input_val;
                unsigned int weight = rand() % max_weight_val;
		ap_uint<INPUT_STREAM_WIDTH> inp_value = (ap_uint<INPUT_STREAM_WIDTH>) (inp);
		ap_uint<WEIGHT_STREAM_WIDTH> wgt_value = (ap_uint<WEIGHT_STREAM_WIDTH>) (weight);
		sw_mult_mm(inp_value, wgt_value, expected[counter]);
		input_stream1.write(inp_value);
		weight_stream.write(wgt_value);		
	  }
        }

	testbench_pe(input_stream1, output_stream, weight_stream, REPS);

	for (unsigned int counter = 0; counter < REPS; counter++)
	{
		ap_uint<OUTPUT_STREAM_WIDTH> value = output_stream.read();
		if(value!= expected[counter])
		{
			cout << "ERROR with counter " << counter << std::hex << " expected " << expected[counter] << " value " << value << std::dec <<  endl;
			return(1);
		}
	}

}

