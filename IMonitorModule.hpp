#ifndef I_MONITOR_MODULE_H
#define I_MONITOR_MODULE_H
#include <iostream>
#include <unistd.h>

class IMonitorModule
{
	public: 
		virtual void update() = 0;
		
};

#endif