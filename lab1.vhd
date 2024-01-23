library ieee;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;


entity lab1 is 
        port (
            clk       : in  std_logic;             -- clk
            leds   : out std_logic_vector(7 downto 0);                    -- export
            bs : in  std_logic_vector(7 downto 0); -- export
            reset : in  std_logic);
end entity;

architecture arch of lab1 is 


    component lab1_qsys is
        port (
            clk_clk       : in  std_logic;             -- clk
            leds_export   : out std_logic_vector(9 downto 0);                    -- export
            bp_sw_export  : in  std_logic_vector(11 downto 0); -- export
            reset_reset_n : in  std_logic);
    end component lab1_qsys;

	 begin
	 
    u0 : component lab1_qsys
        port map (
            clk_clk       => clk,       --   clk.clk
            leds_export   => leds,   --  leds.export
            bp_sw_export  => bs,  -- bp_sw.export
            reset_reset_n => reset);
		  
end architecture; 