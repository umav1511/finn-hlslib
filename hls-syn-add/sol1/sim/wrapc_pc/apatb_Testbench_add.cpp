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


// wrapc file define: "in1_V_V"
#define AUTOTB_TVIN_in1_V_V  "../tv/cdatafile/c.Testbench_add.autotvin_in1_V_V.dat"
#define WRAPC_STREAM_SIZE_IN_in1_V_V  "../tv/stream_size/stream_size_in_in1_V_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_in1_V_V  "../tv/stream_size/stream_ingress_status_in1_V_V.dat"
// wrapc file define: "in2_V_V"
#define AUTOTB_TVIN_in2_V_V  "../tv/cdatafile/c.Testbench_add.autotvin_in2_V_V.dat"
#define WRAPC_STREAM_SIZE_IN_in2_V_V  "../tv/stream_size/stream_size_in_in2_V_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_in2_V_V  "../tv/stream_size/stream_ingress_status_in2_V_V.dat"
// wrapc file define: "out_V_V"
#define AUTOTB_TVOUT_out_V_V  "../tv/cdatafile/c.Testbench_add.autotvout_out_V_V.dat"
#define AUTOTB_TVIN_out_V_V  "../tv/cdatafile/c.Testbench_add.autotvin_out_V_V.dat"
#define WRAPC_STREAM_SIZE_OUT_out_V_V  "../tv/stream_size/stream_size_out_out_V_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_out_V_V  "../tv/stream_size/stream_egress_status_out_V_V.dat"
// wrapc file define: "numReps"
#define AUTOTB_TVIN_numReps  "../tv/cdatafile/c.Testbench_add.autotvin_numReps.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "out_V_V"
#define AUTOTB_TVOUT_PC_out_V_V  "../tv/rtldatafile/rtl.Testbench_add.autotvout_out_V_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			in1_V_V_depth = 0;
			in2_V_V_depth = 0;
			out_V_V_depth = 0;
			numReps_depth = 0;
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
			total_list << "{in1_V_V " << in1_V_V_depth << "}\n";
			total_list << "{in2_V_V " << in2_V_V_depth << "}\n";
			total_list << "{out_V_V " << out_V_V_depth << "}\n";
			total_list << "{numReps " << numReps_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int in1_V_V_depth;
		int in2_V_V_depth;
		int out_V_V_depth;
		int numReps_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void Testbench_add (
hls::stream<ap_uint<128> > (&in1),
hls::stream<ap_uint<128> > (&in2),
hls::stream<ap_uint<128> > (&out),
const unsigned int numReps);

void AESL_WRAP_Testbench_add (
hls::stream<ap_uint<128> > (&in1),
hls::stream<ap_uint<128> > (&in2),
hls::stream<ap_uint<128> > (&out),
const unsigned int numReps)
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

		// pop stream input: "in1"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in1_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in1_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in1_V_V, AESL_token); // pop_size
			int aesl_tmp_10 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_10; i++)
			{
				in1.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in1_V_V, AESL_token); // [[/transaction]]
		}

		// pop stream input: "in2"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in2_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in2_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in2_V_V, AESL_token); // pop_size
			int aesl_tmp_13 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_13; i++)
			{
				in2.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in2_V_V, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "out"
		std::vector<ap_uint<128> > aesl_tmp_15;
		int aesl_tmp_16;
		int aesl_tmp_17 = 0;

		// read output stream size: "out"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // pop_size
			aesl_tmp_16 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[/transaction]]
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

			std::vector<sc_bv<128> > out_V_V_pc_buffer;
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
			if (i != aesl_tmp_16)
			{
				aesl_tmp_16 = i;
			}

			if (aesl_tmp_16 > 0 && aesl_tmp_15.size() < aesl_tmp_16)
			{
				int aesl_tmp_15_size = aesl_tmp_15.size();

				for (int tmp_aesl_tmp_15 = 0; tmp_aesl_tmp_15 < aesl_tmp_16 - aesl_tmp_15_size; tmp_aesl_tmp_15++)
				{
					ap_uint<128> tmp;
					aesl_tmp_15.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: out_V_V
				{
					// bitslice(127, 0)
					// {
						// celement: out.V.V(127, 0)
						// {
							sc_lv<128>* out_V_V_lv0_0_0_1 = new sc_lv<128>[aesl_tmp_16 - aesl_tmp_17];
						// }
					// }

					// bitslice(127, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(127, 0)
						{
							// carray: (aesl_tmp_17) => (aesl_tmp_16 - 1) @ (1)
							for (int i_0 = aesl_tmp_17; i_0 <= aesl_tmp_16 - 1; i_0 += 1)
							{
								if (&(aesl_tmp_15[0]) != NULL) // check the null address if the c port is array or others
								{
									out_V_V_lv0_0_0_1[hls_map_index].range(127, 0) = sc_bv<128>(out_V_V_pc_buffer[hls_map_index].range(127, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(127, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(127, 0)
						{
							// carray: (aesl_tmp_17) => (aesl_tmp_16 - 1) @ (1)
							for (int i_0 = aesl_tmp_17; i_0 <= aesl_tmp_16 - 1; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : aesl_tmp_15[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : aesl_tmp_15[0]
								// output_left_conversion : aesl_tmp_15[i_0]
								// output_type_conversion : (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(aesl_tmp_15[0]) != NULL) // check the null address if the c port is array or others
								{
									aesl_tmp_15[i_0] = (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
									hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_16; i++)
		{
			out.write(aesl_tmp_15[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "in1_V_V"
		char* tvin_in1_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in1_V_V);
		char* wrapc_stream_size_in_in1_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_in1_V_V);
		char* wrapc_stream_ingress_status_in1_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_in1_V_V);

		// "in2_V_V"
		char* tvin_in2_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in2_V_V);
		char* wrapc_stream_size_in_in2_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_in2_V_V);
		char* wrapc_stream_ingress_status_in2_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_in2_V_V);

		// "out_V_V"
		char* tvin_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_V_V);
		char* tvout_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_out_V_V);
		char* wrapc_stream_size_out_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_out_V_V);
		char* wrapc_stream_egress_status_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_out_V_V);

		// "numReps"
		char* tvin_numReps = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_numReps);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "in1"
		std::vector<ap_uint<128> > aesl_tmp_9;
		int aesl_tmp_10 = 0;
		while (!in1.empty())
		{
			aesl_tmp_9.push_back(in1.read());
			aesl_tmp_10++;
		}

		// dump stream tvin: "in2"
		std::vector<ap_uint<128> > aesl_tmp_12;
		int aesl_tmp_13 = 0;
		while (!in2.empty())
		{
			aesl_tmp_12.push_back(in2.read());
			aesl_tmp_13++;
		}

		// dump stream tvin: "out"
		std::vector<ap_uint<128> > aesl_tmp_15;
		int aesl_tmp_16 = 0;
		while (!out.empty())
		{
			aesl_tmp_15.push_back(out.read());
			aesl_tmp_16++;
		}

		// [[transaction]]
		sprintf(tvin_numReps, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_numReps, tvin_numReps);

		sc_bv<32> numReps_tvin_wrapc_buffer;

		// RTL Name: numReps
		{
			// bitslice(31, 0)
			{
				// celement: numReps(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : numReps
						// sub_1st_elem          : 
						// ori_name_1st_elem     : numReps
						// regulate_c_name       : numReps
						// input_type_conversion : numReps
						if (&(numReps) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> numReps_tmp_mem;
							numReps_tmp_mem = numReps;
							numReps_tvin_wrapc_buffer.range(31, 0) = numReps_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_numReps, "%s\n", (numReps_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_numReps, tvin_numReps);
		}

		tcl_file.set_num(1, &tcl_file.numReps_depth);
		sprintf(tvin_numReps, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_numReps, tvin_numReps);

		// push back input stream: "in1"
		for (int i = 0; i < aesl_tmp_10; i++)
		{
			in1.write(aesl_tmp_9[i]);
		}

		// push back input stream: "in2"
		for (int i = 0; i < aesl_tmp_13; i++)
		{
			in2.write(aesl_tmp_12[i]);
		}

		// push back input stream: "out"
		for (int i = 0; i < aesl_tmp_16; i++)
		{
			out.write(aesl_tmp_15[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		Testbench_add(in1, in2, out, numReps);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "in1"
		int aesl_tmp_11 = in1.size();

		// record input size to tv3: "in2"
		int aesl_tmp_14 = in2.size();

		// pop output stream: "out"
		int aesl_tmp_17 = aesl_tmp_16;
		aesl_tmp_16 = 0;
     aesl_tmp_15.clear();
		while (!out.empty())
		{
			aesl_tmp_15.push_back(out.read());
			aesl_tmp_16++;
		}

		// [[transaction]]
		sprintf(tvin_in1_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in1_V_V, tvin_in1_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, tvin_in1_V_V);

		sc_bv<128>* in1_V_V_tvin_wrapc_buffer = new sc_bv<128>[aesl_tmp_10 - aesl_tmp_11];

		// RTL Name: in1_V_V
		{
			// bitslice(127, 0)
			{
				int hls_map_index = 0;
				// celement: in1.V.V(127, 0)
				{
					// carray: (0) => (aesl_tmp_10 - aesl_tmp_11 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_10 - aesl_tmp_11 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_9[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_9[0]
						// regulate_c_name       : in1_V_V
						// input_type_conversion : (aesl_tmp_9[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_9[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<128> in1_V_V_tmp_mem;
							in1_V_V_tmp_mem = (aesl_tmp_9[i_0]).to_string(2).c_str();
							in1_V_V_tvin_wrapc_buffer[hls_map_index].range(127, 0) = in1_V_V_tmp_mem.range(127, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_10 - aesl_tmp_11; i++)
		{
			sprintf(tvin_in1_V_V, "%s\n", (in1_V_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in1_V_V, tvin_in1_V_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_10 > aesl_tmp_11)
     {
		sc_int<32> stream_ingress_size_in1_V_V = aesl_tmp_10;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, stream_ingress_size_in1_V_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, "\n");

		for (int i = 0; i < aesl_tmp_10 - aesl_tmp_11; i++)
		{
			stream_ingress_size_in1_V_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, stream_ingress_size_in1_V_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_in1_V_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, stream_ingress_size_in1_V_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_10 - aesl_tmp_11, &tcl_file.in1_V_V_depth);
		sprintf(tvin_in1_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in1_V_V, tvin_in1_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in1_V_V, tvin_in1_V_V);

		// release memory allocation
		delete [] in1_V_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_in1_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in1_V_V, wrapc_stream_size_in_in1_V_V);
		sprintf(wrapc_stream_size_in_in1_V_V, "%d\n", aesl_tmp_10 - aesl_tmp_11);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in1_V_V, wrapc_stream_size_in_in1_V_V);
		sprintf(wrapc_stream_size_in_in1_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in1_V_V, wrapc_stream_size_in_in1_V_V);

		// [[transaction]]
		sprintf(tvin_in2_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in2_V_V, tvin_in2_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, tvin_in2_V_V);

		sc_bv<128>* in2_V_V_tvin_wrapc_buffer = new sc_bv<128>[aesl_tmp_13 - aesl_tmp_14];

		// RTL Name: in2_V_V
		{
			// bitslice(127, 0)
			{
				int hls_map_index = 0;
				// celement: in2.V.V(127, 0)
				{
					// carray: (0) => (aesl_tmp_13 - aesl_tmp_14 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_13 - aesl_tmp_14 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_12[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_12[0]
						// regulate_c_name       : in2_V_V
						// input_type_conversion : (aesl_tmp_12[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_12[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<128> in2_V_V_tmp_mem;
							in2_V_V_tmp_mem = (aesl_tmp_12[i_0]).to_string(2).c_str();
							in2_V_V_tvin_wrapc_buffer[hls_map_index].range(127, 0) = in2_V_V_tmp_mem.range(127, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_13 - aesl_tmp_14; i++)
		{
			sprintf(tvin_in2_V_V, "%s\n", (in2_V_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in2_V_V, tvin_in2_V_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_13 > aesl_tmp_14)
     {
		sc_int<32> stream_ingress_size_in2_V_V = aesl_tmp_13;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, stream_ingress_size_in2_V_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, "\n");

		for (int i = 0; i < aesl_tmp_13 - aesl_tmp_14; i++)
		{
			stream_ingress_size_in2_V_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, stream_ingress_size_in2_V_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_in2_V_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, stream_ingress_size_in2_V_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_13 - aesl_tmp_14, &tcl_file.in2_V_V_depth);
		sprintf(tvin_in2_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in2_V_V, tvin_in2_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in2_V_V, tvin_in2_V_V);

		// release memory allocation
		delete [] in2_V_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_in2_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in2_V_V, wrapc_stream_size_in_in2_V_V);
		sprintf(wrapc_stream_size_in_in2_V_V, "%d\n", aesl_tmp_13 - aesl_tmp_14);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in2_V_V, wrapc_stream_size_in_in2_V_V);
		sprintf(wrapc_stream_size_in_in2_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in2_V_V, wrapc_stream_size_in_in2_V_V);

		// [[transaction]]
		sprintf(tvout_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		sc_bv<128>* out_V_V_tvout_wrapc_buffer = new sc_bv<128>[aesl_tmp_16 - aesl_tmp_17];

		// RTL Name: out_V_V
		{
			// bitslice(127, 0)
			{
				int hls_map_index = 0;
				// celement: out.V.V(127, 0)
				{
					// carray: (aesl_tmp_17) => (aesl_tmp_16 - 1) @ (1)
					for (int i_0 = aesl_tmp_17; i_0 <= aesl_tmp_16 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_15[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_15[0]
						// regulate_c_name       : out_V_V
						// input_type_conversion : (aesl_tmp_15[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_15[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<128> out_V_V_tmp_mem;
							out_V_V_tmp_mem = (aesl_tmp_15[i_0]).to_string(2).c_str();
							out_V_V_tvout_wrapc_buffer[hls_map_index].range(127, 0) = out_V_V_tmp_mem.range(127, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_16 - aesl_tmp_17; i++)
		{
			sprintf(tvout_out_V_V, "%s\n", (out_V_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);
		}

		tcl_file.set_num(aesl_tmp_16 - aesl_tmp_17, &tcl_file.out_V_V_depth);
		sprintf(tvout_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		// release memory allocation
		delete [] out_V_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "%d\n", aesl_tmp_16 - aesl_tmp_17);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_16; i++)
		{
			out.write(aesl_tmp_15[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "in1_V_V"
		delete [] tvin_in1_V_V;
		delete [] wrapc_stream_size_in_in1_V_V;
		// release memory allocation: "in2_V_V"
		delete [] tvin_in2_V_V;
		delete [] wrapc_stream_size_in_in2_V_V;
		// release memory allocation: "out_V_V"
		delete [] tvout_out_V_V;
		delete [] tvin_out_V_V;
		delete [] wrapc_stream_size_out_out_V_V;
		// release memory allocation: "numReps"
		delete [] tvin_numReps;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

