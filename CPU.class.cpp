#include "CPU.class.hpp"


CPU::CPU(void) {
	this->update();
}

CPU::CPU(const CPU& copy) {
	*this = copy;
}

CPU::~CPU(void) {
	return;
}

CPU& CPU::operator=(const CPU&) {
	return *this;
}

void CPU::update(void) {
	char brand[128];
	size_t size = sizeof(brand);

	sysctlbyname("machdep.cpu.brand_string", &brand, &size, NULL, 0);
	this->_brand = std::string(brand);

	this->_cores.clear();
	int coreNum;
	sysctlbyname("hw.ncpu", &coreNum, &size, NULL, 0);
	this->_cores.push_back(coreNum);

	this->_loadAVG.clear();
	double avg[3];
    getloadavg(avg, 3);
	this->_loadAVG.push_back(avg[0]);
	this->_loadAVG.push_back(avg[1]);
	this->_loadAVG.push_back(avg[2]);

	for (int i = 0; i < 4; i++) {
		this->_oldUsageOfCore[i] = this->_calcUsage(i);
	}
	sleep(1);
	for (int i = 0; i < 4; i++) {
		this->_currenUsageOfCore[i] = this->_calcUsage(i);
	}
}

std::vector<unsigned long long int> CPU::_calcUsage(int core) {
	unsigned int cpuCount;
	processor_cpu_load_info_t cpuLoad;
	mach_msg_type_number_t cpuMsgCount;

	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &cpuCount,
			(processor_info_array_t *) &cpuLoad, &cpuMsgCount);

	unsigned long long int userTime = cpuLoad[core].cpu_ticks[CPU_STATE_USER];
	unsigned long long int niceTime = cpuLoad[core].cpu_ticks[CPU_STATE_NICE];
	unsigned long long int systemTime = cpuLoad[core].cpu_ticks[CPU_STATE_SYSTEM];
	unsigned long long int idleTime = cpuLoad[core].cpu_ticks[CPU_STATE_IDLE];

	std::vector<unsigned long long int> cpuTicks;
	cpuTicks.push_back(userTime);
	cpuTicks.push_back(niceTime);
	cpuTicks.push_back(systemTime);
	cpuTicks.push_back(idleTime);
	return cpuTicks;
}

/* Getters */

std::string CPU::getBrand(void) const {
	return this->_brand;
}

std::vector<int> CPU::getCores(void) const {
	return this->_cores;
}

std::vector<double> CPU::getLoadAVG(void) const {
	return this->_loadAVG;
}

std::vector<float> CPU::getUsage(void) {
	this->_usage.clear();
	for (int i = 0; i < 4; i++) {
		unsigned long long int used =
			std::accumulate(this->_currenUsageOfCore[i].begin(), this->_currenUsageOfCore[i].end() - 1, 0)
			- std::accumulate(this->_oldUsageOfCore[i].begin(), this->_oldUsageOfCore[i].end() - 1, 0);
		unsigned long long int total =
			std::accumulate(this->_currenUsageOfCore[i].begin(), this->_currenUsageOfCore[i].end(), 0)
			- std::accumulate(this->_oldUsageOfCore[i].begin(), this->_oldUsageOfCore[i].end(), 0);

		float result = static_cast<float>(used) / static_cast<float>(total) * 100.0f;
		this->_usage.push_back(result);
	}

	return this->_usage;
}
