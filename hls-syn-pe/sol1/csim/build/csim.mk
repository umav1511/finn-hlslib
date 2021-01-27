# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../pe_tb.cpp ../../../../pe_top.cpp

override TARGET := csim.exe

AUTOPILOT_ROOT := /home/uma/Desktop/Xilinx/Vivado/2020.1
AUTOPILOT_MACH := lnx64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
IFLAG += -fPIC
ifndef AP_GCC_PATH
  AP_GCC_PATH := /home/uma/Desktop/Xilinx/Vivado/2020.1/tps/lnx64/gcc-6.2.0/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_TOOL}/clang-3.9/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -I "/usr/include/x86_64-linux-gnu"
IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E2__
IFLAG += -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/tb -std=c++0x -Wno-unknown-pragmas 
IFLAG += -g
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += 
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



$(ObjDir)/pe_tb.o: ../../../../pe_tb.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../pe_tb.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/tb -std=c++0x -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/pe_tb.d

$(ObjDir)/pe_top.o: ../../../../pe_top.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../pe_top.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/tb -std=c++0x  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/pe_top.d
