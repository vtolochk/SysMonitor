#ifndef OS_INFO_H
#define OS_INFO_H
#include "IMonitorModule.hpp"

class OSInfo: public IMonitorModule {
	public:
		OSInfo(void);
		OSInfo(const OSInfo& copy);
		~OSInfo(void);
		OSInfo& operator=(const OSInfo&);

		void update(void);

		std::string getOSName(void) const;
		std::string getKernelVersion(void) const;

	private:
		std::string _osName;
		std::string _kernelVersion;
};

#endif
