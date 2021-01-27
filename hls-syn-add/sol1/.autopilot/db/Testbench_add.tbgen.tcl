set moduleName Testbench_add
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {Testbench_add}
set C_modelType { void 0 }
set C_modelArgList {
	{ in1_V_V int 128 regular {fifo 0 volatile }  }
	{ in2_V_V int 128 regular {fifo 0 volatile }  }
	{ out_V_V int 128 regular {fifo 1 volatile }  }
	{ numReps int 32 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "in1_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "READONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "in1.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "in2_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "READONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "in2.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "out_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "out.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "numReps", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "numReps","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 16
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ in1_V_V_dout sc_in sc_lv 128 signal 0 } 
	{ in1_V_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ in1_V_V_read sc_out sc_logic 1 signal 0 } 
	{ in2_V_V_dout sc_in sc_lv 128 signal 1 } 
	{ in2_V_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ in2_V_V_read sc_out sc_logic 1 signal 1 } 
	{ out_V_V_din sc_out sc_lv 128 signal 2 } 
	{ out_V_V_full_n sc_in sc_logic 1 signal 2 } 
	{ out_V_V_write sc_out sc_logic 1 signal 2 } 
	{ numReps sc_in sc_lv 32 signal 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "in1_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "in1_V_V", "role": "dout" }} , 
 	{ "name": "in1_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "empty_n" }} , 
 	{ "name": "in1_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "read" }} , 
 	{ "name": "in2_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "in2_V_V", "role": "dout" }} , 
 	{ "name": "in2_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "empty_n" }} , 
 	{ "name": "in2_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "read" }} , 
 	{ "name": "out_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "out_V_V", "role": "din" }} , 
 	{ "name": "out_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_V_V", "role": "full_n" }} , 
 	{ "name": "out_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_V_V", "role": "write" }} , 
 	{ "name": "numReps", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "numReps", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "Testbench_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddStreams_fu_83"}],
		"Port" : [
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "in1_V_V"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "in2_V_V"}]},
			{"Name" : "out_V_V", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "out_V_V"}]},
			{"Name" : "numReps", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AddStreams_fu_83", "Parent" : "0",
		"CDFG" : "AddStreams",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "7", "EstimateLatencyMax" : "7",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in1_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in2_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "out_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_V_V_blk_n", "Type" : "RtlSignal"}]}]}]}


set ArgLastReadFirstWriteLatency {
	Testbench_add {
		in1_V_V {Type I LastRead 2 FirstWrite -1}
		in2_V_V {Type I LastRead 2 FirstWrite -1}
		out_V_V {Type O LastRead -1 FirstWrite 3}
		numReps {Type I LastRead 0 FirstWrite -1}}
	AddStreams {
		in1_V_V {Type I LastRead 2 FirstWrite -1}
		in2_V_V {Type I LastRead 2 FirstWrite -1}
		out_V_V {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	in1_V_V { ap_fifo {  { in1_V_V_dout fifo_data 0 128 }  { in1_V_V_empty_n fifo_status 0 1 }  { in1_V_V_read fifo_update 1 1 } } }
	in2_V_V { ap_fifo {  { in2_V_V_dout fifo_data 0 128 }  { in2_V_V_empty_n fifo_status 0 1 }  { in2_V_V_read fifo_update 1 1 } } }
	out_V_V { ap_fifo {  { out_V_V_din fifo_data 1 128 }  { out_V_V_full_n fifo_status 0 1 }  { out_V_V_write fifo_update 1 1 } } }
	numReps { ap_none {  { numReps in_data 0 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
	in1_V_V { fifo_read 1 no_conditional }
	in2_V_V { fifo_read 1 no_conditional }
	out_V_V { fifo_write 1 no_conditional }
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
set moduleName Testbench_add
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {Testbench_add}
set C_modelType { void 0 }
set C_modelArgList {
	{ in1_V_V int 128 regular {fifo 0 volatile }  }
	{ in2_V_V int 128 regular {fifo 0 volatile }  }
	{ out_V_V int 128 regular {fifo 1 volatile }  }
	{ numReps int 32 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "in1_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "READONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "in1.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "in2_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "READONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "in2.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "out_V_V", "interface" : "fifo", "bitwidth" : 128, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":127,"cElement": [{"cName": "out.V.V","cData": "uint128","bit_use": { "low": 0,"up": 127},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "numReps", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "numReps","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 16
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ in1_V_V_dout sc_in sc_lv 128 signal 0 } 
	{ in1_V_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ in1_V_V_read sc_out sc_logic 1 signal 0 } 
	{ in2_V_V_dout sc_in sc_lv 128 signal 1 } 
	{ in2_V_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ in2_V_V_read sc_out sc_logic 1 signal 1 } 
	{ out_V_V_din sc_out sc_lv 128 signal 2 } 
	{ out_V_V_full_n sc_in sc_logic 1 signal 2 } 
	{ out_V_V_write sc_out sc_logic 1 signal 2 } 
	{ numReps sc_in sc_lv 32 signal 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "in1_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "in1_V_V", "role": "dout" }} , 
 	{ "name": "in1_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "empty_n" }} , 
 	{ "name": "in1_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "read" }} , 
 	{ "name": "in2_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "in2_V_V", "role": "dout" }} , 
 	{ "name": "in2_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "empty_n" }} , 
 	{ "name": "in2_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "read" }} , 
 	{ "name": "out_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":128, "type": "signal", "bundle":{"name": "out_V_V", "role": "din" }} , 
 	{ "name": "out_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_V_V", "role": "full_n" }} , 
 	{ "name": "out_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_V_V", "role": "write" }} , 
 	{ "name": "numReps", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "numReps", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "Testbench_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddStreams_fu_83"}],
		"Port" : [
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "in1_V_V"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "in2_V_V"}]},
			{"Name" : "out_V_V", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_AddStreams_fu_83", "Port" : "out_V_V"}]},
			{"Name" : "numReps", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AddStreams_fu_83", "Parent" : "0",
		"CDFG" : "AddStreams",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "7", "EstimateLatencyMax" : "7",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in1_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "in2_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "out_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_V_V_blk_n", "Type" : "RtlSignal"}]}]}]}


set ArgLastReadFirstWriteLatency {
	Testbench_add {
		in1_V_V {Type I LastRead 2 FirstWrite -1}
		in2_V_V {Type I LastRead 2 FirstWrite -1}
		out_V_V {Type O LastRead -1 FirstWrite 3}
		numReps {Type I LastRead 0 FirstWrite -1}}
	AddStreams {
		in1_V_V {Type I LastRead 2 FirstWrite -1}
		in2_V_V {Type I LastRead 2 FirstWrite -1}
		out_V_V {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	in1_V_V { ap_fifo {  { in1_V_V_dout fifo_data 0 128 }  { in1_V_V_empty_n fifo_status 0 1 }  { in1_V_V_read fifo_update 1 1 } } }
	in2_V_V { ap_fifo {  { in2_V_V_dout fifo_data 0 128 }  { in2_V_V_empty_n fifo_status 0 1 }  { in2_V_V_read fifo_update 1 1 } } }
	out_V_V { ap_fifo {  { out_V_V_din fifo_data 1 128 }  { out_V_V_full_n fifo_status 0 1 }  { out_V_V_write fifo_update 1 1 } } }
	numReps { ap_none {  { numReps in_data 0 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
	in1_V_V { fifo_read 1 no_conditional }
	in2_V_V { fifo_read 1 no_conditional }
	out_V_V { fifo_write 1 no_conditional }
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
