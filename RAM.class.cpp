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
	unsigned long totalMem;
	size_t size = sizeof(totalMem);
	sysctlbyname("hw.memsize", &totalMem, &size, NULL, 0);
	std::stringstream ss;
	ss << totalMem / 1024 / 1024;
	this->_totalMem = ss.str();
	ss.str("");
	ss.clear();

	unsigned long freeMem;
	size_t sizeFreeMem = sizeof(freeMem);
	sysctlbyname("vm.page_free_count", &freeMem, &sizeFreeMem, NULL, 0);
	ss << ((totalMem / 1048576) - (freeMem * 4096 / 1048576));
	this->_usedMem = ss.str();
	ss.str("");
	ss.clear();

	ss << freeMem * 4096 / 1048576;
	this->_freeMem = ss.str();
}

/* Getters */

std::string RAM::getTotalMem(void) const {
	return this->_totalMem;
}

std::string RAM::getUsedMem(void) const {
	return this->_usedMem;
}

std::string RAM::getFreeMem(void) const {
	return this->_freeMem;
}
