#include "Network.class.hpp"

Network::Network(void) {
	this->update();
}

Network::Network(const Network& copy) {
	*this = copy;
}

Network::~Network(void) {
	return;
}

Network& Network::operator=(const Network&) {
	return *this;
}

void Network::update(void) {
	this->_network.clear();
	this->_parseNetworkFromTop();
}

void Network::_parseNetworkFromTop(void) {
	FILE* pipe1;
	FILE* pipe2;
	char buff[64];
	std::string tmp;

	pipe1 = popen("top -l 1 | grep Network | sed 's/\\.//g' | cut -d' ' -f 3", "r");
	fgets(buff, 64, pipe1);
	tmp = std::string(buff);
	tmp.erase(tmp.end() - 1, tmp.end());
	this->_network.push_back(tmp);

	pipe2 = popen("top -l 1 | grep Network | sed 's/\\.//g' | cut -d' ' -f 5", "r");
	fgets(buff, 64, pipe2);
	tmp = std::string(buff);
	tmp.erase(tmp.end() - 1, tmp.end());
	this->_network.push_back(tmp);
	pclose(pipe1);
	pclose(pipe2);
}

/* Getters */

std::vector<std::string> Network::getNetwork(void) const {
	return this->_network;
}
