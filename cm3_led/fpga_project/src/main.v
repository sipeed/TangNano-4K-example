module moduleName (
	clkin_i,
	gpio_io,
	uart0_rxd_i,
	uart0_txd_o,
	reset_n_i
);
	input clkin_i;
	input reset_n_i;
	input uart0_rxd_i;
	output uart0_txd_o;
	inout[15:0] gpio_io;

	wire clkout_o;
	// wire sys_clk_i = clkout_o;
	Gowin_EMPU_Top Gowin_EMPU_Top_instance(
		.sys_clk(clkout_o), //input sys_clk
		.gpio(gpio_io), //inout [15:0] gpio
		.uart0_rxd(uart0_rxd_i), //input uart0_rxd
		.uart0_txd(uart0_txd_o), //output uart0_txd
		.reset_n(reset_n_i) //input reset_n
	);


	Gowin_PLLVR Gowin_PLLVR_instance(
        .clkout(clkout_o), //output clkout
        .clkin(clkin_i) //input clkin
    );
endmodule
	