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
        std::string getUserName();
        std::string getHostName();
    private:
        std::string UserName;
        std::string HostName;
};

#endif