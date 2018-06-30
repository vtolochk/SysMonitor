#ifndef I_MONITOR_MODULE_H
#define I_MONITOR_MODULE_H
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
#include <ncurses.h>


class IMonitorModule
{
	public:
		virtual void update() = 0;
		
};

#endif
