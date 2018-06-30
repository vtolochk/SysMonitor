#include "UserHost.class.hpp"

UserHost::UserHost()
{

}

UserHost::~UserHost()
{

}

UserHost::UserHost(const UserHost &other)
{
    (void)other;
}

UserHost &UserHost::operator = (const UserHost &other)
{
    (void)other;
    return *this;
}

std::string UserHost::getUserName()
{
    std::cout << getlogin_r() << std::endl;
    return NULL;
}

std::string UserHost::getHostName()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getTime()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getDate()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getOSname()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getProcessorName()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getMemoryDescription()
{
    std::cout << "la" << std::endl;
    return NULL;
}

std::string UserHost::getGraphics()
{
    std::cout << "la" << std::endl;
    return NULL;
}