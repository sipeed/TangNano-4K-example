module top (
    input  wire       rst_n,
    input  wire       clk,
    output wire       hdmi_clk_p,
    output wire       hdmi_clk_n,
    output wire [2:0] hdmi_data_p,
    output wire [2:0] hdmi_data_n
);

// f_CLKOUT = f_CLKIN * FBDIV / IDIV, 3.125~600MHz
// f_VCO = f_CLKOUT * ODIV, 400~1200MHz
// f_PFD = f_CLKIN / IDIV = f_CLKOUT / FBDIV, 3~400MHz

localparam PLL_IDIV  =  2 - 1; // 0~63
localparam PLL_FBDIV = 57 - 1; // 0~63
localparam PLL_ODIV  =      2; // 2, 4, 8, 16, 32, 48, 64, 80, 96, 112, 128

// 720p
//localparam DVI_H_BPORCH = 12'd220;
//localparam DVI_H_ACTIVE = 12'd1280;
//localparam DVI_H_FPORCH = 12'd110;
//localparam DVI_H_SYNC   = 12'd40;
//localparam DVI_H_POLAR  = 1'b1;
//localparam DVI_V_BPORCH = 12'd20;
//localparam DVI_V_ACTIVE = 12'd720;
//localparam DVI_V_FPORCH = 12'd5;
//localparam DVI_V_SYNC   = 12'd5;
//localparam DVI_V_POLAR  = 1'b1;

// 1080p
//localparam DVI_H_BPORCH = 12'd148;
//localparam DVI_H_ACTIVE = 12'd1920;
//localparam DVI_H_FPORCH = 12'd88;
//localparam DVI_H_SYNC   = 12'd44;
//localparam DVI_H_POLAR  = 1'b1;
//localparam DVI_V_BPORCH = 12'd36;
//localparam DVI_V_ACTIVE = 12'd1080;
//localparam DVI_V_FPORCH = 12'd4;
//localparam DVI_V_SYNC   = 12'd5;
//localparam DVI_V_POLAR  = 1'b1;

// 1440p
localparam DVI_H_BPORCH = 12'd40;
localparam DVI_H_ACTIVE = 12'd2560;
localparam DVI_H_FPORCH = 12'd8;
localparam DVI_H_SYNC   = 12'd32;
localparam DVI_H_POLAR  = 1'b1;
localparam DVI_V_BPORCH = 12'd6;
localparam DVI_V_ACTIVE = 12'd1440;
localparam DVI_V_FPORCH = 12'd13;
localparam DVI_V_SYNC   = 12'd8;
localparam DVI_V_POLAR  = 1'b0;
//localparam DVI_H_BPORCH = 12'd80;
//localparam DVI_H_ACTIVE = 12'd2560;
//localparam DVI_H_FPORCH = 12'd48;
//localparam DVI_H_SYNC   = 12'd32;
//localparam DVI_H_POLAR  = 1'b1;
//localparam DVI_V_BPORCH = 12'd33;
//localparam DVI_V_ACTIVE = 12'd1440;
//localparam DVI_V_FPORCH = 12'd3;
//localparam DVI_V_SYNC   = 12'd5;
//localparam DVI_V_POLAR  = 1'b0;

wire rst;
wire clk_serial;
wire clk_pixel;
wire pll_locked;

reg       rgb_vs;
reg       rgb_hs;
reg       rgb_de;
reg [7:0] rgb_r;
reg [7:0] rgb_g;
reg [7:0] rgb_b;

assign rst = ~rst_n;

PLLVR #(
    .FCLKIN    (27),
    .IDIV_SEL  (PLL_IDIV),
    .FBDIV_SEL (PLL_FBDIV),
    .ODIV_SEL  (PLL_ODIV),
    .DEVICE    ("GW1NSR-4C")
) pll (
    .CLKIN    (clk),
    .CLKFB    (1'b0),
    .RESET    (rst),
    .RESET_P  (1'b0),
    .FBDSEL   (6'b0),
    .IDSEL    (6'b0),
    .ODSEL    (6'b0),
    .DUTYDA   (4'b0),
    .PSDA     (4'b0),
    .FDLY     (4'b0),
    .VREN     (1'b1),
    .CLKOUT   (clk_serial),
    .LOCK     (pll_locked),
    .CLKOUTP  (),
    .CLKOUTD  (),
    .CLKOUTD3 ()
);

CLKDIV #(
    .DIV_MODE (5)
) clk_pixel_gen (
    .HCLKIN (clk_serial),
    .RESETN (rst_n),
    .CALIB  (1'b0),
    .CLKOUT (clk_pixel)
);

DVI_TX_Top dvi_tx (
    .I_rst_n       (rst_n),       // input I_rst_n
    .I_serial_clk  (clk_serial),  // input I_serial_clk
    .I_rgb_clk     (clk_pixel),   // input I_rgb_clk
    .I_rgb_vs      (rgb_vs),      // input I_rgb_vs
    .I_rgb_hs      (rgb_hs),      // input I_rgb_hs
    .I_rgb_de      (rgb_de),      // input I_rgb_de
    .I_rgb_r       (rgb_r),       // input [7:0] I_rgb_r
    .I_rgb_g       (rgb_g),       // input [7:0] I_rgb_g
    .I_rgb_b       (rgb_b),       // input [7:0] I_rgb_b
    .O_tmds_clk_p  (hdmi_clk_p),  // output O_tmds_clk_p
    .O_tmds_clk_n  (hdmi_clk_n),  // output O_tmds_clk_n
    .O_tmds_data_p (hdmi_data_p), // output [2:0] O_tmds_data_p
    .O_tmds_data_n (hdmi_data_n)  // output [2:0] O_tmds_data_n
);

// Video Timing Generator

reg [11:0] cnt_h;
reg [11:0] cnt_h_next;
reg [11:0] cnt_v;
reg [11:0] cnt_v_next;

always @(negedge rst_n or posedge clk_pixel)
    if (!rst_n) begin
        cnt_h <= 12'd0;
        cnt_v <= 12'd0;
    end else if (!pll_locked) begin
        cnt_h <= 12'd0;
        cnt_v <= 12'd0;
    end else begin
        cnt_h <= cnt_h_next;
        cnt_v <= cnt_v_next;
    end

always @(*) begin
    if (cnt_h == DVI_H_BPORCH + DVI_H_ACTIVE + DVI_H_FPORCH + DVI_H_SYNC - 1'd1) begin
        cnt_h_next = 12'd0;
        if (cnt_v == DVI_V_BPORCH + DVI_V_ACTIVE + DVI_V_FPORCH + DVI_V_SYNC - 1'd1) begin
            cnt_v_next = 12'd0;
        end else begin
            cnt_v_next = cnt_v + 1'd1;
        end
    end else begin
        cnt_h_next = cnt_h + 1'd1;
        cnt_v_next = cnt_v;
    end
end

always @(*) begin
    if (cnt_h < DVI_H_BPORCH + DVI_H_ACTIVE + DVI_H_FPORCH) begin
        rgb_hs = ~DVI_H_POLAR;
    end else begin
        rgb_hs = DVI_H_POLAR;
    end

    if (cnt_v < DVI_V_BPORCH + DVI_V_ACTIVE + DVI_V_FPORCH) begin
        rgb_vs = ~DVI_V_POLAR;
    end else begin
        rgb_vs = DVI_V_POLAR;
    end

    if (cnt_h < DVI_H_BPORCH || cnt_h >= DVI_H_BPORCH + DVI_H_ACTIVE) begin
        rgb_de = 1'b0;
    end else if (cnt_v < DVI_V_BPORCH || cnt_v >= DVI_V_BPORCH + DVI_V_ACTIVE) begin
        rgb_de = 1'b0;
    end else begin
        rgb_de = 1'b1;
    end
end

// Video Pattern Generator

reg [23:0] cnt_white;
reg [23:0] cnt_white_next;

always @(negedge rst_n or posedge clk_pixel)
    if (!rst_n) begin
        cnt_white <= 24'd0;
    end else if (cnt_h == 12'd0 && cnt_v == 12'd0) begin
        cnt_white <= cnt_white_next;
    end

always @(*)
    if (cnt_white == DVI_H_ACTIVE * DVI_V_ACTIVE - 1'd1) begin
        cnt_white_next = 24'd0;
    end else begin
        cnt_white_next = cnt_white + 1'd1;
    end

reg [23:0] cnt_de;
reg [23:0] cnt_de_next;

always @(negedge rst_n or posedge clk_pixel)
    if (!rst_n) begin
        cnt_de <= 1'd0;
    end else begin
        cnt_de <= cnt_de_next;
    end

always @(*)
    if (rgb_vs == DVI_V_POLAR) begin
        cnt_de_next = 24'd0;
    end else if (rgb_de) begin
        cnt_de_next = cnt_de + 1'd1;
    end else begin
        cnt_de_next = cnt_de;
    end

wire [23:0] rgb_next;

always @(negedge rst_n or posedge clk_pixel)
    if (!rst_n) begin
        {rgb_r, rgb_g, rgb_b} <= 24'h000000;
    end else begin
        {rgb_r, rgb_g, rgb_b} <= rgb_next;
    end

assign rgb_next = cnt_de < cnt_white ? 24'hFFFFFF : 24'h000000;

endmodule
