#ifndef USER_HOST_H
#define USER_HOST_H
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class UserHost : public IMonitorModule
{
    public:
        UserHost();
        ~UserHost();
        UserHost(const UserHost &other);
        UserHost &operator = (const UserHost &other);
          std::string getTime();
         std::string getDate();
        std::string getUserName();
         std::string getHostName();
        std::string getOSname();
         std::string getProcessorName();
         std::string getMemoryDescription();
         std::string getGraphics();
    private:
        std::string UserName;
        std::string HostName;
};

#endif