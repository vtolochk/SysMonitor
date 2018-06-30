#ifndef I_MONITOR_MODULE_H
#define I_MONITOR_MODULE_H
#include <iostream>
#include <unistd.h>

class IMonitorModule
{
    public:
        virtual std::string getTime() = 0;
        virtual std::string getDate() = 0;
        virtual std::string getUserName() = 0;
        virtual std::string getHostName() = 0;
        virtual std::string getOSname() = 0;
        virtual std::string getProcessorName() = 0;
        virtual std::string getMemoryDescription() = 0;
        virtual std::string getGraphics() = 0;
};

#endif