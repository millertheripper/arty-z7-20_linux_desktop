-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2020.1
-- Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity hls_sobel_axi_stream_top_xFSobel3x3_1_1_0_0_s is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    p_read2 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read5 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read6 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read7 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read8 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read9 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read10 : IN STD_LOGIC_VECTOR (7 downto 0);
    p_read11 : IN STD_LOGIC_VECTOR (7 downto 0);
    ap_return_0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    ap_return_1 : OUT STD_LOGIC_VECTOR (7 downto 0);
    ap_ce : IN STD_LOGIC );
end;


architecture behav of hls_sobel_axi_stream_top_xFSobel3x3_1_1_0_0_s is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_boolean_0 : BOOLEAN := false;

attribute shreg_extract : string;
    signal grp_xFGradientX3x3_0_0_s_fu_72_ap_return : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_xFGradientX3x3_0_0_s_fu_72_ap_ce : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0_ignore_call8 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1_ignore_call8 : BOOLEAN;
    signal ap_block_pp0_stage0_11001_ignoreCallOp11 : BOOLEAN;
    signal grp_xFGradientY3x3_0_0_s_fu_88_ap_return : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_xFGradientY3x3_0_0_s_fu_88_ap_ce : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0_ignore_call9 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1_ignore_call9 : BOOLEAN;
    signal ap_block_pp0_stage0_11001_ignoreCallOp12 : BOOLEAN;
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal ap_ce_reg : STD_LOGIC;
    signal ap_return_0_int_reg : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_return_1_int_reg : STD_LOGIC_VECTOR (7 downto 0);

    component hls_sobel_axi_stream_top_xFGradientX3x3_0_0_s IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        t0 : IN STD_LOGIC_VECTOR (7 downto 0);
        t2 : IN STD_LOGIC_VECTOR (7 downto 0);
        m0 : IN STD_LOGIC_VECTOR (7 downto 0);
        m2 : IN STD_LOGIC_VECTOR (7 downto 0);
        b0 : IN STD_LOGIC_VECTOR (7 downto 0);
        b2 : IN STD_LOGIC_VECTOR (7 downto 0);
        ap_return : OUT STD_LOGIC_VECTOR (7 downto 0);
        ap_ce : IN STD_LOGIC );
    end component;


    component hls_sobel_axi_stream_top_xFGradientY3x3_0_0_s IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        t0 : IN STD_LOGIC_VECTOR (7 downto 0);
        t1 : IN STD_LOGIC_VECTOR (7 downto 0);
        t2 : IN STD_LOGIC_VECTOR (7 downto 0);
        b0 : IN STD_LOGIC_VECTOR (7 downto 0);
        b1 : IN STD_LOGIC_VECTOR (7 downto 0);
        b2 : IN STD_LOGIC_VECTOR (7 downto 0);
        ap_return : OUT STD_LOGIC_VECTOR (7 downto 0);
        ap_ce : IN STD_LOGIC );
    end component;



begin
    grp_xFGradientX3x3_0_0_s_fu_72 : component hls_sobel_axi_stream_top_xFGradientX3x3_0_0_s
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        t0 => p_read2,
        t2 => p_read6,
        m0 => p_read7,
        m2 => p_read8,
        b0 => p_read9,
        b2 => p_read11,
        ap_return => grp_xFGradientX3x3_0_0_s_fu_72_ap_return,
        ap_ce => grp_xFGradientX3x3_0_0_s_fu_72_ap_ce);

    grp_xFGradientY3x3_0_0_s_fu_88 : component hls_sobel_axi_stream_top_xFGradientY3x3_0_0_s
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        t0 => p_read2,
        t1 => p_read5,
        t2 => p_read6,
        b0 => p_read9,
        b1 => p_read10,
        b2 => p_read11,
        ap_return => grp_xFGradientY3x3_0_0_s_fu_88_ap_return,
        ap_ce => grp_xFGradientY3x3_0_0_s_fu_88_ap_ce);





    ap_ce_reg_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            ap_ce_reg <= ap_ce;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_ce_reg)) then
                ap_return_0_int_reg <= grp_xFGradientX3x3_0_0_s_fu_72_ap_return;
                ap_return_1_int_reg <= grp_xFGradientY3x3_0_0_s_fu_88_ap_return;
            end if;
        end if;
    end process;
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001_ignoreCallOp11 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001_ignoreCallOp12 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0_ignore_call8 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0_ignore_call9 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1_ignore_call8 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1_ignore_call9 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_return_0_assign_proc : process(grp_xFGradientX3x3_0_0_s_fu_72_ap_return, ap_ce_reg, ap_return_0_int_reg)
    begin
        if ((ap_const_logic_0 = ap_ce_reg)) then 
            ap_return_0 <= ap_return_0_int_reg;
        elsif ((ap_const_logic_1 = ap_ce_reg)) then 
            ap_return_0 <= grp_xFGradientX3x3_0_0_s_fu_72_ap_return;
        end if; 
    end process;


    ap_return_1_assign_proc : process(grp_xFGradientY3x3_0_0_s_fu_88_ap_return, ap_ce_reg, ap_return_1_int_reg)
    begin
        if ((ap_const_logic_0 = ap_ce_reg)) then 
            ap_return_1 <= ap_return_1_int_reg;
        elsif ((ap_const_logic_1 = ap_ce_reg)) then 
            ap_return_1 <= grp_xFGradientY3x3_0_0_s_fu_88_ap_return;
        end if; 
    end process;


    grp_xFGradientX3x3_0_0_s_fu_72_ap_ce_assign_proc : process(ap_block_pp0_stage0_11001_ignoreCallOp11)
    begin
        if (((ap_const_logic_1 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001_ignoreCallOp11))) then 
            grp_xFGradientX3x3_0_0_s_fu_72_ap_ce <= ap_const_logic_1;
        else 
            grp_xFGradientX3x3_0_0_s_fu_72_ap_ce <= ap_const_logic_0;
        end if; 
    end process;


    grp_xFGradientY3x3_0_0_s_fu_88_ap_ce_assign_proc : process(ap_block_pp0_stage0_11001_ignoreCallOp12)
    begin
        if (((ap_const_logic_1 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001_ignoreCallOp12))) then 
            grp_xFGradientY3x3_0_0_s_fu_88_ap_ce <= ap_const_logic_1;
        else 
            grp_xFGradientY3x3_0_0_s_fu_88_ap_ce <= ap_const_logic_0;
        end if; 
    end process;

end behav;
