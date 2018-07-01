#include "UserHost.class.hpp"
#include "DateTime.class.hpp"
#include "OSInfo.class.hpp"
#include "CPU.class.hpp"
#include "RAM.class.hpp"
#include "TerminalMonitor.class.hpp"
#include "Network.class.hpp"


#include <sys/mount.h>
int main(void)
{
	DateTime dateTime;
	UserHost userHost;
	OSInfo OSinfo;
	CPU cpu;
	RAM ram;
	Network network;
	
	TerminalMonitor terminal(dateTime, userHost, OSinfo, cpu, ram, network);
	terminal.displayInfo();
	

	return 0;
}
