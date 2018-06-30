#include "TerminalMonitor.class.hpp"

TerminalMonitor::TerminalMonitor(DateTime &dateTime, UserHost &userHost, OSInfo &OSinfo, CPU &cpu)
{
	this->_dateTime = dateTime;
	this->_userHost = userHost;
	this->_OSinfo = OSinfo;
	this->_cpu = cpu;
}

TerminalMonitor::~TerminalMonitor()
{

}

TerminalMonitor::TerminalMonitor(const TerminalMonitor &other)
{
	static_cast<void>(other);
}

TerminalMonitor &TerminalMonitor::operator = (const TerminalMonitor &other)
{
	static_cast<void>(other);
	return *this;
}

void TerminalMonitor::displayInfo()
{
	initscr();
	noecho();
	curs_set(0);
	this->_userHost.update();
	this->_OSinfo.update();
	for(;;)
	{
		nodelay(stdscr, true);
		erase();
		this->_cpu.update();
		this->_dateTime.update();
		keypad(stdscr, true);

		std::string str = this->_dateTime.getTime();
		std::string str2 = this->_userHost.getUserName();
		std::vector<double> str4 = this->_cpu.getLoadAVG();
		mvprintw(10, 50, str2.c_str());
		mvprintw(0, 50, str.c_str());

		std::vector<float> str3 = this->_cpu.getUsage();
		int res = getch();
		if (res == 'q')
		{	
			nodelay(stdscr, false);
			endwin();
			exit(0);
		}
	}
}
