#include "RAM.class.hpp"

RAM::RAM(void) {

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
