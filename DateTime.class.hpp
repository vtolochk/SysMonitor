#ifndef DATE_TIME_H
#define DATE_TIME_H
#include "IMonitorModule.hpp"

class DateTime: public IMonitorModule {
	public:
		DateTime(void);
		DateTime(const DateTime& copy);
		~DateTime(void);
		DateTime& operator=(const DateTime&);

		void update(void);

		std::string getDate(void) const;
		std::string getTime(void) const;

	private:
		std::string _date;
		std::string _time;

		const std::string _getCurrentDate();
		const std::string _getCurrentTime();
};

#endif
