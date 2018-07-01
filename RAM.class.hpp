#ifndef RAM_H
#define RAM_H
#include "IMonitorModule.hpp"

class RAM: public IMonitorModule {
	public:
		RAM(void);
		RAM(const RAM& copy);
		~RAM(void);
		RAM& operator=(const RAM&);

		void update(void);

		unsigned long long getTotalMem(void) const;
		unsigned long long getUsedMem(void) const;
		unsigned long long getFreeMem(void) const;

	private:
		unsigned long long _totalMem;
		unsigned long long _usedMem;
		unsigned long long _freeMem;

		void _calcTotalMem(void);
		void _calcUsedMem(void);
		void _calcFreeMem(void);
};

#endif
