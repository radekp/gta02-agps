#ifndef _HELP_H
#define _HELP_H

#include <string.h>
#include <unistd.h>

void help() {
    char *help =

"gta02-apgs-dump, gta02-agps-load, gta02-set-power, stdin-serial-set-raw\n"
"\n"
"INFORMATION\n"
"===========\n"
"\n"
"These programs can set up the UBX GPS chip to obtain\n"
"faster fix after powering on (TTFF). To do this it\n"
"needs AGPS information.\n"
"\n"
"The AGPS information can be grabbed from GPS chip\n"
"when it has fix (reports valid position). Do:\n"
"\n"
"    gta02-agps-dump agpsdata < /dev/ttySAC1 > /dev/ttySAC1\n"
"\n"
"This will save AGPS data read from chip into the\n"
"file \"agpsdata\".\n"
"\n"
"This data can be loaded into the GPS after it is\n"
"stopped and started again. This should improve TTFF.\n"
"\n"
"To load data from agpsdata file issue:\n"
"\n"
"    gta02-agps-load agpsdata < /dev/ttySAC1 > /dev/ttySAC1\n"
"\n"
"Passing -h or --help argument gives you this message.\n"
"\n"
"Passing -v or --verbose argument prints some debug\n"
"information while operating.\n"
"\n"
"Before using this programs (especially gta02-agps-dump)\n"
"you need to properly set the serial port. You can\n"
"do this by:\n"
"\n"
"    stty -F /dev/ttySAC1 raw\n"
"\n"
"In case you do not have stty program, you can use\n"
"the one supplied in the package:\n"
"\n"
"    stdin-serial-set-raw < /dev/ttySAC1\n"
"\n"
"In order to get even faster fixes you can enable\n"
"FixNow(R) technology. When you intend to disable\n"
"the GPS, you can put it to a kind of stand-by mode\n"
"instead. Waking up (instead of doing power on) gives\n"
"you TTFF of 10 seconds range.\n"
"\n"
"Instead of disabling GPS, do:\n"
"\n"
"    gta02-set-power fixnow > /dev/ttySAC1\n"
"\n"
"Instead of enabling it again, do:\n"
"\n"
"    gta02-set-power max > /dev/ttySAC1\n"
"\n"
"You need to have GPS powered on to do this kind\n"
"of things. Note this will drain some current, but\n"
"it should be minimal (comparing to GPS fully powered\n"
"on).\n"
"\n"
    
    ;

    write(2, help, strlen(help));
}

#endif // _HELP_H