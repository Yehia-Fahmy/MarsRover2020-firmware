#include "mbed.h"

AnalogIn potVoltageIn(PA_0);
PwmOut servoPwmOut(PA_1);

int main(int argc, char const *argv[]) {
  servoPwmOut.period_ms(20);
  while (1) {
    float potVoltage = potVoltageIn.read();
    servoPwmOut.pulsewidth.ms(1 + potVoltage / 3.3)
  }
  return 0;
}
