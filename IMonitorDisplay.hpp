#ifndef I_MONITOR_DISPLAY_H
#define I_MONITOR_DISPLAY_H
#include <iostream>
#include <unistd.h>
#include <sys/sysctl.h>
#include <time.h>
#include <sstream>
#include <mach/mach_host.h>
#include <mach/processor_info.h>
#include <vector>
#include <numeric>
#include <iomanip>

class IMonitorDisplay
{
    public:
        virtual void displayInfo(void) = 0;
};

#endif