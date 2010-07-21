#include <termios.h>
#include <unistd.h>

int stdin_serial_set_raw_main() {
    struct termios termios_p;
    cfmakeraw(&termios_p);
    tcsetattr(0, 0, &termios_p);
    return 0;
}

#ifndef QTOPIA
int main(int argc, char **argv) {
  return stdin_serial_set_raw_main();
}
#endif  

