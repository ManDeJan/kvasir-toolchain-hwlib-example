#include "hwlib-arduino-due.hpp"

int main(void) {

    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto led = hwlib::target::pin_out(1, 27);
    for(;;){
       led.set( 1 );
       hwlib::wait_ms( 500 );
       led.set( 0 );
       hwlib::wait_ms( 500 );
    }
}
