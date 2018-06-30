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

	private:
		std::string _brand;
		std::string _cores;
};

#endif
