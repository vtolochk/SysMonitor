#ifndef CPU_H
#define CPU_H
#include "IMonitorModule.hpp"

class CPU: public IMonitorModule {
	public:
		CPU(void);
		CPU(const CPU& copy);
		~CPU(void);
		CPU& operator=(const CPU&);

		void update(void);

		std::string getBrand(void) const;
		std::string getCores(void) const;
		std::string getLoadAVG(void) const;
		std::string getUsage(void) const;

	private:
		std::string _brand;
		std::string _cores;
		std::string _loadAVG;
		std::vector<unsigned long long int> _usage[4];
		std::vector<unsigned long long int> _oldUsageOfCore[4];

		std::vector<unsigned long long int> _calcUsage(int core);
};

#endif
