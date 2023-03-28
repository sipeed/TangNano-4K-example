module blink#(
    parameter clk_frequency = 27_000_000 ,
    parameter io_num        = 1
)(
    input                   clk , // Clock in
    input                   rst_n,
    input  [1:0]            key,
    output [io_num-1:0]     led_o
);

parameter count_ms = clk_frequency / 1000 ;

parameter count_20ms = count_ms * 20 -1 ;
parameter count_500ms = count_ms * 500 -1 ;

reg [($clog2(count_20ms)-1)+10:0] count_20ms_reg;
reg [$clog2(count_500ms)-1:0] count_500ms_reg;

reg [io_num-1:0] led = ~{io_num{'d0}};

// key flag

reg key_input = 1'd1;

always @(posedge clk) begin
    key_input <= (~key[0])|(~key[1])  ;
end

reg key_flag;

always @(posedge clk or negedge rst_n) begin
    if (!rst_n)
        count_20ms_reg <= 'd0;
    else if(key_input)
        count_20ms_reg <= count_20ms_reg + 'd1 ;
    else if(count_20ms_reg >= count_20ms) begin
            key_flag = ~key_flag;
            count_20ms_reg <= 'd0;;
    end
    else
        count_20ms_reg <= 'd0;;
end

// Save led state

reg [io_num-1:0] led_o_state;

always @(posedge clk or negedge rst_n) begin
     if(!rst_n) begin
        led_o_state <= 'd0 ;
     end
    else begin
        led_o_state <= led_o;
    end
end

// LED Toggle

always @(posedge clk or negedge rst_n) begin
     if(!rst_n) begin
        led <= ~('d0);
        count_500ms_reg <= 'd0 ;
     end
    else if(count_500ms_reg < count_500ms)
        count_500ms_reg <= count_500ms_reg+'d1;
    else begin
        count_500ms_reg <= 'd0 ;
        led = ~led ;
    end
end

// led output choice

assign led_o[io_num-1:0] = key_flag ? led_o_state[io_num-1:0] : led[io_num-1:0] ;

endmodule