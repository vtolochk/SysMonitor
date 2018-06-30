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

		std::string getTotalMem(void) const;
		std::string getUsedMem(void) const;
		std::string getFreeMem(void) const;

	private:
		std::string _totalMem;
		std::string _usedMem;
		std::string _freeMem;
};

#endif
