#include "RAM.class.hpp"

RAM::RAM(void) {
	this->update();
}

RAM::RAM(const RAM& copy) {
	*this = copy;
}

RAM::~RAM(void) {
	return;
}

RAM& RAM::operator=(const RAM&) {
	return *this;
}

void RAM::update(void) {
	this->_calcTotalMem();
	this->_calcFreeMem();
	this->_calcUsedMem();
}

void RAM::_calcTotalMem(void) {
	unsigned long long totalMem;
	size_t size = sizeof(totalMem);
	sysctlbyname("hw.memsize", &totalMem, &size, NULL, 0);
	this->_totalMem = totalMem / 1024 / 1024;
}

void RAM::_calcUsedMem(void) {
	this->_usedMem = this->_totalMem - this->_freeMem;
}

void RAM::_calcFreeMem(void) {
	int freeMem;
	size_t sizeFreeMem = sizeof(freeMem);
	sysctlbyname("vm.page_free_count", &freeMem, &sizeFreeMem, NULL, 0);
	this->_freeMem = freeMem * 4096 / 1024 / 1024;
}

/* Getters */

unsigned long long RAM::getTotalMem(void) const {
	return this->_totalMem;
}

unsigned long long RAM::getUsedMem(void) const {
	return this->_usedMem;
}

unsigned long long RAM::getFreeMem(void) const {
	return this->_freeMem;
}
