#include "UserHost.class.hpp"
#include "DateTime.class.hpp"
#include "OSInfo.class.hpp"
#include "CPU.class.hpp"
#include "RAM.class.hpp"
#include "TerminalMonitor.class.hpp"

int main(void)
{
	DateTime dateTime;
	UserHost userHost;
	OSInfo OSinfo;
	CPU cpu;
	
	TerminalMonitor terminal(dateTime, userHost, OSinfo, cpu);
	terminal.displayInfo();
	return 0;
}
