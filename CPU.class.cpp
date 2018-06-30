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
	this->_brand = "Processor: " + std::string(brand);

	int coreNum;
	sysctlbyname("hw.ncpu", &coreNum, &size, NULL, 0);
	std::stringstream ss;
	ss << coreNum;
	this->_cores = "Number of cores: " + ss.str();

	double avg[3];
    getloadavg(avg, 3);
	std::stringstream ss1;
	ss1 << avg[0] << ", " << avg[1] << ", " << avg[2];
	this->_loadAVG = "Load Avg: " + ss1.str();

	for (int i = 0; i < 4; i++) {
		this->_oldUsageOfCore[i] = this->_calcUsage(i);
	}
	usleep(500000);
	for (int i = 0; i < 4; i++) {
		this->_usage[i] = this->_calcUsage(i);
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

std::string CPU::getCores(void) const {
	return this->_cores;
}

std::string CPU::getLoadAVG(void) const {
	return this->_loadAVG;
}

std::string CPU::getUsage(void) const {
	std::stringstream ss;

	for (int i = 0; i < 4; i++) {
		unsigned long long int used =
			std::accumulate(this->_usage[i].begin(), this->_usage[i].end() - 1, 0)
			- std::accumulate(this->_oldUsageOfCore[i].begin(), this->_oldUsageOfCore[i].end() - 1, 0);
		unsigned long long int total =
			std::accumulate(this->_usage[i].begin(), this->_usage[i].end(), 0)
			- std::accumulate(this->_oldUsageOfCore[i].begin(), this->_oldUsageOfCore[i].end(), 0);

		float result = static_cast<float>(used) / static_cast<float>(total) * 100.0f;
		ss << std::fixed << std::setprecision(1) << result << "% ";
	}


	return ss.str();
}
