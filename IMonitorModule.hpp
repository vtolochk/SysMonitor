#ifndef IMONITOR_MODULE_H
#define IMONITOR_MODULE_H

class IMonitorModule
{
    public:
        virtual std::string getCurrentTime() = 0;
        virtual std::string getUserName() = 0;
        virtual std::string getHostName() = 0; 
};

#endif