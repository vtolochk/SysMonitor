#include "DateTime.class.hpp"

DateTime::DateTime(void) {

}

DateTime::DateTime(const DateTime& copy) {
	*this = copy;
}

DateTime::~DateTime(void) {
	return;
}

DateTime& DateTime::operator=(const DateTime&) {
	return *this;
}

void DateTime::update(void) {
	this->_date = this->_getCurrentDate();
	this->_time = this->_getCurrentTime();
}

const std::string DateTime::_getCurrentDate(void) {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return std::string(buf);
}

const std::string DateTime::_getCurrentTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);

	return std::string(buf);
}

/* Getters */

std::string DateTime::getDate(void) const {
	return this->_date;
}

std::string DateTime::getTime(void) const {
	return this->_time;
}
