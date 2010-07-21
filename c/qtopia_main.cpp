#include <stdio.h>
#include "help.h"
#include "stdin-serial-set-raw.c"
#include "gta02-agps-dump.c"
#include "gta02-agps-load.c"
#include "gta02-set-power.c"

int command(const char *cmd, int *argc, char **argv) {
    int i, j;
    
    if (*argc < 2 || strcmp(argv[1], cmd) == 0) {
        return 0;
    }
    
    /* delete command name */
    *argc--;
    for (i = 1; i < *argc; i++) {
        argv[i] = argv[i + 1];
    }
    return 1;
}

int main(int argc, char **argv) {

  if (command("gta02-agps-dump", &argc, argv)) {
      return gta02_agps_dump_main(argc, argv);
  }
  if(command("gta02-agps-load", &argc, argv)) {
      return gta_02_agps_load_main(argc, argv);
  }
  if(command("gta02-set-power", &argc, argv)) {
      return gta02_set_power_main(argc, argv);
  }
  if(command("stdin-serial-set-raw", &argc, argv)) {
       return stdin_serial_set_raw_main();
  }
  
  printf("GTA02 GPS qtopia applet. Calls one of following programs:\n"
         "\n"
         "    gta02-agps-dump\n"
         "    gta02-agps-load\n"
         "    gta02-set-power\n"
         "    stdin-serial-set-raw (does not work, use stty -F /dev/ttySAC1 raw instead)\n"
         "\n"
         "Usage: gta02-gps [program] [args]\n"
         "Information for using individual programs follows\n\n");

   help();
   return 2;
}
