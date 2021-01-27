open_project hls-syn-pe
add_files pe_top.cpp -cflags "-std=c++0x -I$::env(FINN_HLS_ROOT) -I$::env(FINN_HLS_ROOT)/tb" 
add_files -tb pe_tb.cpp -cflags "-std=c++0x -I$::env(FINN_HLS_ROOT) -I$::env(FINN_HLS_ROOT)/tb" 
set_top testbench_pe
open_solution sol1
set_part {xczu3eg-sbva484-1-i}
create_clock -period 5 -name default
csim_design
csynth_design
cosim_design
exit
