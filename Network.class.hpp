#ifndef NETWORK_H
#define NETWORK_H
#include "IMonitorModule.hpp"

class Network: public IMonitorModule {
	public:
		Network(void);
		Network(const Network& copy);
		~Network(void);
		Network& operator=(const Network&);

		void update(void);

		std::vector<std::string> getNetwork(void) const;

	private:
		std::vector<std::string> _network;

		void _parseNetworkFromTop(void);
};

#endif
