#include "OSInfo.class.hpp"

OSInfo::OSInfo(void) {
	this->update();
}

OSInfo::OSInfo(const OSInfo& copy) {
	*this = copy;
}

OSInfo::~OSInfo(void) {
	return;
}

OSInfo& OSInfo::operator=(const OSInfo&) {
	return *this;
}

void OSInfo::update(void) {
#ifdef __unix
	this->_osName = "OS Name: Unix";
#elif __unix__
	this->_osName = "OS Name: Unix";
#elif __APPLE__ || __MACH__
	this->_osName = "OS Name: Mac OSX";
#elif __linux__
	this->_osName = "OS Name: Linux";
#else
	this->_osName = "OS Name: Other";
#endif

	char str[256];
	size_t size = sizeof(str);
	sysctlbyname("kern.osrelease", str, &size, NULL, 0);
	this->_kernelVersion = "Kernel Version: " + std::string(str);
}

std::string OSInfo::getOSName(void) const {
	return this->_osName;
}

std::string OSInfo::getKernelVersion(void) const {
	return this->_kernelVersion;
}
