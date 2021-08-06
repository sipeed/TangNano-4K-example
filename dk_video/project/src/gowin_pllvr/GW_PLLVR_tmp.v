//Copyright (C)2014-2020 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.6.01Beta
//Part Number: GW1NSR-LV4CQN48PC7/I6
//Created Time: Mon Aug 17 16:09:45 2020

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

    GW_PLLVR your_instance_name(
        .clkout(clkout_o), //output clkout
        .lock(lock_o), //output lock
        .clkin(clkin_i) //input clkin
    );

//--------Copy end-------------------
