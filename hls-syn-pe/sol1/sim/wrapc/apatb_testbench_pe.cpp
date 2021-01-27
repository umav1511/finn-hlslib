// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "in_V_V"
#define AUTOTB_TVIN_in_V_V  "../tv/cdatafile/c.testbench_pe.autotvin_in_V_V.dat"
#define WRAPC_STREAM_SIZE_IN_in_V_V  "../tv/stream_size/stream_size_in_in_V_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_in_V_V  "../tv/stream_size/stream_ingress_status_in_V_V.dat"
// wrapc file define: "out_V_V"
#define AUTOTB_TVOUT_out_V_V  "../tv/cdatafile/c.testbench_pe.autotvout_out_V_V.dat"
#define AUTOTB_TVIN_out_V_V  "../tv/cdatafile/c.testbench_pe.autotvin_out_V_V.dat"
#define WRAPC_STREAM_SIZE_OUT_out_V_V  "../tv/stream_size/stream_size_out_out_V_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_out_V_V  "../tv/stream_size/stream_egress_status_out_V_V.dat"
// wrapc file define: "weights_V_V"
#define AUTOTB_TVIN_weights_V_V  "../tv/cdatafile/c.testbench_pe.autotvin_weights_V_V.dat"
#define WRAPC_STREAM_SIZE_IN_weights_V_V  "../tv/stream_size/stream_size_in_weights_V_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weights_V_V  "../tv/stream_size/stream_ingress_status_weights_V_V.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "out_V_V"
#define AUTOTB_TVOUT_PC_out_V_V  "../tv/rtldatafile/rtl.testbench_pe.autotvout_out_V_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			in_V_V_depth = 0;
			out_V_V_depth = 0;
			weights_V_V_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{in_V_V " << in_V_V_depth << "}\n";
			total_list << "{out_V_V " << out_V_V_depth << "}\n";
			total_list << "{weights_V_V " << weights_V_V_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int in_V_V_depth;
		int out_V_V_depth;
		int weights_V_V_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void testbench_pe (
hls::stream<ap_uint<4> > (&in),
hls::stream<ap_uint<8> > (&out),
hls::stream<ap_uint<4> > (&weights),
int reps);

void AESL_WRAP_testbench_pe (
hls::stream<ap_uint<4> > (&in),
hls::stream<ap_uint<8> > (&out),
hls::stream<ap_uint<4> > (&weights),
int reps)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// pop stream input: "in"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // pop_size
			int aesl_tmp_10 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_10; i++)
			{
				in.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "out"
		std::vector<ap_uint<8> > aesl_tmp_12;
		int aesl_tmp_13;
		int aesl_tmp_14 = 0;

		// read output stream size: "out"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // pop_size
			aesl_tmp_13 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[/transaction]]
		}

		// pop stream input: "weights"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_weights_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_weights_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_weights_V_V, AESL_token); // pop_size
			int aesl_tmp_16 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_16; i++)
			{
				weights.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_weights_V_V, AESL_token); // [[/transaction]]
		}

		// output port post check: "out_V_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // data

			std::vector<sc_bv<8> > out_V_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'out_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'out_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					out_V_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_out_V_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_13)
			{
				aesl_tmp_13 = i;
			}

			if (aesl_tmp_13 > 0 && aesl_tmp_12.size() < aesl_tmp_13)
			{
				int aesl_tmp_12_size = aesl_tmp_12.size();

				for (int tmp_aesl_tmp_12 = 0; tmp_aesl_tmp_12 < aesl_tmp_13 - aesl_tmp_12_size; tmp_aesl_tmp_12++)
				{
					ap_uint<8> tmp;
					aesl_tmp_12.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: out_V_V
				{
					// bitslice(7, 0)
					// {
						// celement: out.V.V(7, 0)
						// {
							sc_lv<8>* out_V_V_lv0_0_0_1 = new sc_lv<8>[aesl_tmp_13 - aesl_tmp_14];
						// }
					// }

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(7, 0)
						{
							// carray: (aesl_tmp_14) => (aesl_tmp_13 - 1) @ (1)
							for (int i_0 = aesl_tmp_14; i_0 <= aesl_tmp_13 - 1; i_0 += 1)
							{
								if (&(aesl_tmp_12[0]) != NULL) // check the null address if the c port is array or others
								{
									out_V_V_lv0_0_0_1[hls_map_index].range(7, 0) = sc_bv<8>(out_V_V_pc_buffer[hls_map_index].range(7, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(7, 0)
						{
							// carray: (aesl_tmp_14) => (aesl_tmp_13 - 1) @ (1)
							for (int i_0 = aesl_tmp_14; i_0 <= aesl_tmp_13 - 1; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : aesl_tmp_12[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : aesl_tmp_12[0]
								// output_left_conversion : aesl_tmp_12[i_0]
								// output_type_conversion : (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(aesl_tmp_12[0]) != NULL) // check the null address if the c port is array or others
								{
									aesl_tmp_12[i_0] = (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
									hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_13; i++)
		{
			out.write(aesl_tmp_12[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "in_V_V"
		char* tvin_in_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in_V_V);
		char* wrapc_stream_size_in_in_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_in_V_V);
		char* wrapc_stream_ingress_status_in_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_in_V_V);

		// "out_V_V"
		char* tvin_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_V_V);
		char* tvout_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_out_V_V);
		char* wrapc_stream_size_out_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_out_V_V);
		char* wrapc_stream_egress_status_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_out_V_V);

		// "weights_V_V"
		char* tvin_weights_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_weights_V_V);
		char* wrapc_stream_size_in_weights_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weights_V_V);
		char* wrapc_stream_ingress_status_weights_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weights_V_V);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "in"
		std::vector<ap_uint<4> > aesl_tmp_9;
		int aesl_tmp_10 = 0;
		while (!in.empty())
		{
			aesl_tmp_9.push_back(in.read());
			aesl_tmp_10++;
		}

		// dump stream tvin: "out"
		std::vector<ap_uint<8> > aesl_tmp_12;
		int aesl_tmp_13 = 0;
		while (!out.empty())
		{
			aesl_tmp_12.push_back(out.read());
			aesl_tmp_13++;
		}

		// dump stream tvin: "weights"
		std::vector<ap_uint<4> > aesl_tmp_15;
		int aesl_tmp_16 = 0;
		while (!weights.empty())
		{
			aesl_tmp_15.push_back(weights.read());
			aesl_tmp_16++;
		}

		// push back input stream: "in"
		for (int i = 0; i < aesl_tmp_10; i++)
		{
			in.write(aesl_tmp_9[i]);
		}

		// push back input stream: "out"
		for (int i = 0; i < aesl_tmp_13; i++)
		{
			out.write(aesl_tmp_12[i]);
		}

		// push back input stream: "weights"
		for (int i = 0; i < aesl_tmp_16; i++)
		{
			weights.write(aesl_tmp_15[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		testbench_pe(in, out, weights, reps);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "in"
		int aesl_tmp_11 = in.size();

		// pop output stream: "out"
		int aesl_tmp_14 = aesl_tmp_13;
		aesl_tmp_13 = 0;
     aesl_tmp_12.clear();
		while (!out.empty())
		{
			aesl_tmp_12.push_back(out.read());
			aesl_tmp_13++;
		}

		// record input size to tv3: "weights"
		int aesl_tmp_17 = weights.size();

		// [[transaction]]
		sprintf(tvin_in_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, tvin_in_V_V);

		sc_bv<4>* in_V_V_tvin_wrapc_buffer = new sc_bv<4>[aesl_tmp_10 - aesl_tmp_11];

		// RTL Name: in_V_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: in.V.V(3, 0)
				{
					// carray: (0) => (aesl_tmp_10 - aesl_tmp_11 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_10 - aesl_tmp_11 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_9[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_9[0]
						// regulate_c_name       : in_V_V
						// input_type_conversion : (aesl_tmp_9[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_9[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<4> in_V_V_tmp_mem;
							in_V_V_tmp_mem = (aesl_tmp_9[i_0]).to_string(2).c_str();
							in_V_V_tvin_wrapc_buffer[hls_map_index].range(3, 0) = in_V_V_tmp_mem.range(3, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_10 - aesl_tmp_11; i++)
		{
			sprintf(tvin_in_V_V, "%s\n", (in_V_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_10 > aesl_tmp_11)
     {
		sc_int<32> stream_ingress_size_in_V_V = aesl_tmp_10;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, stream_ingress_size_in_V_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, "\n");

		for (int i = 0; i < aesl_tmp_10 - aesl_tmp_11; i++)
		{
			stream_ingress_size_in_V_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, stream_ingress_size_in_V_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_in_V_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, stream_ingress_size_in_V_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_10 - aesl_tmp_11, &tcl_file.in_V_V_depth);
		sprintf(tvin_in_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, tvin_in_V_V);

		// release memory allocation
		delete [] in_V_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_in_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);
		sprintf(wrapc_stream_size_in_in_V_V, "%d\n", aesl_tmp_10 - aesl_tmp_11);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);
		sprintf(wrapc_stream_size_in_in_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);

		// [[transaction]]
		sprintf(tvout_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		sc_bv<8>* out_V_V_tvout_wrapc_buffer = new sc_bv<8>[aesl_tmp_13 - aesl_tmp_14];

		// RTL Name: out_V_V
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: out.V.V(7, 0)
				{
					// carray: (aesl_tmp_14) => (aesl_tmp_13 - 1) @ (1)
					for (int i_0 = aesl_tmp_14; i_0 <= aesl_tmp_13 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_12[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_12[0]
						// regulate_c_name       : out_V_V
						// input_type_conversion : (aesl_tmp_12[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_12[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> out_V_V_tmp_mem;
							out_V_V_tmp_mem = (aesl_tmp_12[i_0]).to_string(2).c_str();
							out_V_V_tvout_wrapc_buffer[hls_map_index].range(7, 0) = out_V_V_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_13 - aesl_tmp_14; i++)
		{
			sprintf(tvout_out_V_V, "%s\n", (out_V_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);
		}

		tcl_file.set_num(aesl_tmp_13 - aesl_tmp_14, &tcl_file.out_V_V_depth);
		sprintf(tvout_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		// release memory allocation
		delete [] out_V_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "%d\n", aesl_tmp_13 - aesl_tmp_14);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);

		// [[transaction]]
		sprintf(tvin_weights_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_weights_V_V, tvin_weights_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, tvin_weights_V_V);

		sc_bv<4>* weights_V_V_tvin_wrapc_buffer = new sc_bv<4>[aesl_tmp_16 - aesl_tmp_17];

		// RTL Name: weights_V_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: weights.V.V(3, 0)
				{
					// carray: (0) => (aesl_tmp_16 - aesl_tmp_17 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_16 - aesl_tmp_17 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_15[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_15[0]
						// regulate_c_name       : weights_V_V
						// input_type_conversion : (aesl_tmp_15[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_15[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<4> weights_V_V_tmp_mem;
							weights_V_V_tmp_mem = (aesl_tmp_15[i_0]).to_string(2).c_str();
							weights_V_V_tvin_wrapc_buffer[hls_map_index].range(3, 0) = weights_V_V_tmp_mem.range(3, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_16 - aesl_tmp_17; i++)
		{
			sprintf(tvin_weights_V_V, "%s\n", (weights_V_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_weights_V_V, tvin_weights_V_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_16 > aesl_tmp_17)
     {
		sc_int<32> stream_ingress_size_weights_V_V = aesl_tmp_16;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, stream_ingress_size_weights_V_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, "\n");

		for (int i = 0; i < aesl_tmp_16 - aesl_tmp_17; i++)
		{
			stream_ingress_size_weights_V_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, stream_ingress_size_weights_V_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_weights_V_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, stream_ingress_size_weights_V_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_16 - aesl_tmp_17, &tcl_file.weights_V_V_depth);
		sprintf(tvin_weights_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_weights_V_V, tvin_weights_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weights_V_V, tvin_weights_V_V);

		// release memory allocation
		delete [] weights_V_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_weights_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_weights_V_V, wrapc_stream_size_in_weights_V_V);
		sprintf(wrapc_stream_size_in_weights_V_V, "%d\n", aesl_tmp_16 - aesl_tmp_17);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_weights_V_V, wrapc_stream_size_in_weights_V_V);
		sprintf(wrapc_stream_size_in_weights_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_weights_V_V, wrapc_stream_size_in_weights_V_V);

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_13; i++)
		{
			out.write(aesl_tmp_12[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "in_V_V"
		delete [] tvin_in_V_V;
		delete [] wrapc_stream_size_in_in_V_V;
		// release memory allocation: "out_V_V"
		delete [] tvout_out_V_V;
		delete [] tvin_out_V_V;
		delete [] wrapc_stream_size_out_out_V_V;
		// release memory allocation: "weights_V_V"
		delete [] tvin_weights_V_V;
		delete [] wrapc_stream_size_in_weights_V_V;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

