#include "TerminalMonitor.class.hpp"

TerminalMonitor::TerminalMonitor(DateTime &dateTime, UserHost &userHost, OSInfo &OSinfo, CPU &cpu, RAM &ram)
{
	this->_dateTime = dateTime;
	this->_userHost = userHost;
	this->_OSinfo = OSinfo;
	this->_cpu = cpu;
	this->_ram = ram;
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

void TerminalMonitor::_allUpdate()
{
	this->_cpu.update();
	this->_dateTime.update();
	this->_userHost.update();
	this->_OSinfo.update();
	this->_ram.update();
}

void TerminalMonitor::_timeModule()
{
	std::string temp;
	WINDOW *win = newwin(8, 20, 0, 0);
	box(win, 0, 0);
	mvwprintw(win, 1, 8, "Date");
	temp = this->_dateTime.getDate();
	mvwprintw(win, 2, 5, temp.c_str());
	mvwprintw(win, 4, 8, "Time");
	temp = this->_dateTime.getTime();
	mvwprintw(win, 5, 6, temp.c_str());
	wrefresh(win);
}

void TerminalMonitor::_userModule()
{
	std::string temp;
	WINDOW *win = newwin(8, 20, 8, 0);
	box(win, 0, 0);
	mvwprintw(win, 1, 6, "Username");
	temp = this->_userHost.getUserName();
	mvwprintw(win, 2, 6, temp.c_str());
	mvwprintw(win, 4, 6, "Hostname");
	temp = this->_userHost.getHostName();
	mvwprintw(win, 5, 3, temp.c_str());
	wrefresh(win);
}

void TerminalMonitor::_OSModule()
{
	std::string temp;
	WINDOW *win = newwin(8, 20, 16, 0);
	box(win, 0, 0);
	mvwprintw(win, 1, 6, "OS Name");
	temp = this->_OSinfo.getOSName();
	mvwprintw(win, 2, 6, temp.c_str());
	mvwprintw(win, 4, 3, "Kernel version");
	temp = this->_OSinfo.getKernelVersion();
	mvwprintw(win, 5, 6, temp.c_str());
	wrefresh(win);
}

void TerminalMonitor::_CPUModule()
{
	std::string temp;
	WINDOW *win = newwin(24, 60, 0, 20);
	box(win, 0, 0);
	mvwprintw(win, 2, 25, "Processor");
	temp = this->_cpu.getBrand();
	mvwprintw(win, 3, 11, temp.c_str());

	mvwprintw(win, 6, 24, "Average load");
	std::vector<double> avg = this->_cpu.getLoadAVG();
	std::stringstream output;
	std::copy(avg.begin(), avg.end(), std::ostream_iterator<double>(output, "  "));
	mvwprintw(win, 7, 18, output.str().c_str());

	std::vector<float> usage = this->_cpu.getUsage();
	
	int j = 11;
	for (size_t i = 0; i < 4; i++)
	{
		mvwprintw(win, j, 4, "core %i:", i);
		this->_printCpuBars(win, j, 12, usage[i]);
		mvwprintw(win, j, 50, "%.1f%%", usage[i]);
		j += 2;
	}

	wrefresh(win);
}

void TerminalMonitor::_printCpuBars(WINDOW* win, int y, int x, float usage) {
	mvwprintw(win, y, x, "[");
	int numOfBars = usage * 0.45;
	for (int i = 0; i < numOfBars; i++) {
		wattron(win, COLOR_PAIR(1));
		mvwprintw(win, y, x + 1 + i, "|");
		wattroff(win, COLOR_PAIR(1));
	}
	mvwprintw(win, y, x + 36, "]");
}

void TerminalMonitor::_RAMModule()
{
	WINDOW *win = newwin(12, 30, 0, 80);
	box(win, 0, 0);
	mvwprintw(win, 1, 8, "Total memory");
	mvwprintw(win, 2, 11, "%llu", this->_ram.getTotalMem());
	mvwprintw(win, 4, 8, "Used memory");
	mvwprintw(win, 5, 7, "%llu", this->_ram.getUsedMem());
	mvwprintw(win, 7, 8, "Free memory");
	mvwprintw(win, 8, 7, "%llu", this->_ram.getFreeMem());
	wrefresh(win);
}

void TerminalMonitor::_NetworkModule()
{
	std::string temp;
	WINDOW *win = newwin(12, 30, 12, 80);
	box(win, 0, 0);
	mvwprintw(win, 1, 11, "Networks");
	mvwprintw(win, 3, 10, "Packets in");
	temp = "kaka";
	mvwprintw(win, 5, 8, temp.c_str());
	mvwprintw(win, 7, 10, "Packets out");
	temp = "kaka";
	mvwprintw(win, 9, 8, temp.c_str());
	wrefresh(win);
}

void TerminalMonitor::_allAppear()
{
	this->_timeModule();
	this->_userModule();
	this->_OSModule();
	this->_CPUModule();
	this->_RAMModule();
	this->_NetworkModule();
}

void TerminalMonitor::displayInfo()
{
	initscr();
	noecho();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	curs_set(0);
	for(;;)
	{
		nodelay(stdscr, true);
		keypad(stdscr, true);
		this->_allUpdate();
		this->_allAppear();
		if (getch() == 'q')
		{	
			endwin();
			exit(0);
		}
	}
}
