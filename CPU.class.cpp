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
}

/* Getters */

std::string CPU::getBrand(void) const {
	return this->_brand;
}

std::string CPU::getCores(void) const {
	return this->_cores;
}
