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
		std::vector<int> getCores(void) const;
		std::vector<double> getLoadAVG(void) const;
		std::vector<float> getUsage(void);

	private:
		std::string _brand;
		std::vector<int> _cores;
		std::vector<double> _loadAVG;
		std::vector<unsigned long long int> _currenUsageOfCore[4];
		std::vector<unsigned long long int> _oldUsageOfCore[4];
		std::vector<float> _usage;

		std::vector<unsigned long long int> _calcUsage(int core);
};

#endif
