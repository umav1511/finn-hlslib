-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2020.1
-- Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Testbench_add is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    in1_V_V_dout : IN STD_LOGIC_VECTOR (127 downto 0);
    in1_V_V_empty_n : IN STD_LOGIC;
    in1_V_V_read : OUT STD_LOGIC;
    in2_V_V_dout : IN STD_LOGIC_VECTOR (127 downto 0);
    in2_V_V_empty_n : IN STD_LOGIC;
    in2_V_V_read : OUT STD_LOGIC;
    out_V_V_din : OUT STD_LOGIC_VECTOR (127 downto 0);
    out_V_V_full_n : IN STD_LOGIC;
    out_V_V_write : OUT STD_LOGIC;
    numReps : IN STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of Testbench_add is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "Testbench_add,hls_ip_2020_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xczu3eg-sbva484-1-i,HLS_INPUT_CLOCK=5.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=3.912750,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=271,HLS_SYN_LUT=2013,HLS_VERSION=2020_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (2 downto 0) := "010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (2 downto 0) := "001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal image_fu_98_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal image_reg_112 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal grp_AddStreams_fu_83_ap_start : STD_LOGIC;
    signal grp_AddStreams_fu_83_ap_done : STD_LOGIC;
    signal grp_AddStreams_fu_83_ap_idle : STD_LOGIC;
    signal grp_AddStreams_fu_83_ap_ready : STD_LOGIC;
    signal grp_AddStreams_fu_83_in1_V_V_read : STD_LOGIC;
    signal grp_AddStreams_fu_83_in2_V_V_read : STD_LOGIC;
    signal grp_AddStreams_fu_83_out_V_V_din : STD_LOGIC_VECTOR (127 downto 0);
    signal grp_AddStreams_fu_83_out_V_V_write : STD_LOGIC;
    signal image_0_i_reg_72 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal grp_AddStreams_fu_83_ap_start_reg : STD_LOGIC := '0';
    signal icmp_ln718_fu_93_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (2 downto 0);

    component AddStreams IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        in1_V_V_dout : IN STD_LOGIC_VECTOR (127 downto 0);
        in1_V_V_empty_n : IN STD_LOGIC;
        in1_V_V_read : OUT STD_LOGIC;
        in2_V_V_dout : IN STD_LOGIC_VECTOR (127 downto 0);
        in2_V_V_empty_n : IN STD_LOGIC;
        in2_V_V_read : OUT STD_LOGIC;
        out_V_V_din : OUT STD_LOGIC_VECTOR (127 downto 0);
        out_V_V_full_n : IN STD_LOGIC;
        out_V_V_write : OUT STD_LOGIC );
    end component;



begin
    grp_AddStreams_fu_83 : component AddStreams
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_AddStreams_fu_83_ap_start,
        ap_done => grp_AddStreams_fu_83_ap_done,
        ap_idle => grp_AddStreams_fu_83_ap_idle,
        ap_ready => grp_AddStreams_fu_83_ap_ready,
        in1_V_V_dout => in1_V_V_dout,
        in1_V_V_empty_n => in1_V_V_empty_n,
        in1_V_V_read => grp_AddStreams_fu_83_in1_V_V_read,
        in2_V_V_dout => in2_V_V_dout,
        in2_V_V_empty_n => in2_V_V_empty_n,
        in2_V_V_read => grp_AddStreams_fu_83_in2_V_V_read,
        out_V_V_din => grp_AddStreams_fu_83_out_V_V_din,
        out_V_V_full_n => out_V_V_full_n,
        out_V_V_write => grp_AddStreams_fu_83_out_V_V_write);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    grp_AddStreams_fu_83_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_AddStreams_fu_83_ap_start_reg <= ap_const_logic_0;
            else
                if (((icmp_ln718_fu_93_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                    grp_AddStreams_fu_83_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_AddStreams_fu_83_ap_ready = ap_const_logic_1)) then 
                    grp_AddStreams_fu_83_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    image_0_i_reg_72_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((grp_AddStreams_fu_83_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                image_0_i_reg_72 <= image_reg_112;
            elsif (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                image_0_i_reg_72 <= ap_const_lv32_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                image_reg_112 <= image_fu_98_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, grp_AddStreams_fu_83_ap_done, ap_CS_fsm_state3, icmp_ln718_fu_93_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln718_fu_93_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((grp_AddStreams_fu_83_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when others =>  
                ap_NS_fsm <= "XXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);

    ap_done_assign_proc : process(ap_CS_fsm_state2, icmp_ln718_fu_93_p2)
    begin
        if (((icmp_ln718_fu_93_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln718_fu_93_p2)
    begin
        if (((icmp_ln718_fu_93_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    grp_AddStreams_fu_83_ap_start <= grp_AddStreams_fu_83_ap_start_reg;
    icmp_ln718_fu_93_p2 <= "1" when (image_0_i_reg_72 = numReps) else "0";
    image_fu_98_p2 <= std_logic_vector(unsigned(image_0_i_reg_72) + unsigned(ap_const_lv32_1));

    in1_V_V_read_assign_proc : process(grp_AddStreams_fu_83_in1_V_V_read, ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            in1_V_V_read <= grp_AddStreams_fu_83_in1_V_V_read;
        else 
            in1_V_V_read <= ap_const_logic_0;
        end if; 
    end process;


    in2_V_V_read_assign_proc : process(grp_AddStreams_fu_83_in2_V_V_read, ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            in2_V_V_read <= grp_AddStreams_fu_83_in2_V_V_read;
        else 
            in2_V_V_read <= ap_const_logic_0;
        end if; 
    end process;

    out_V_V_din <= grp_AddStreams_fu_83_out_V_V_din;

    out_V_V_write_assign_proc : process(grp_AddStreams_fu_83_out_V_V_write, ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            out_V_V_write <= grp_AddStreams_fu_83_out_V_V_write;
        else 
            out_V_V_write <= ap_const_logic_0;
        end if; 
    end process;

end behav;
