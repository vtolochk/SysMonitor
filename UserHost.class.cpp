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
    /* std::cout << getlogin_r() << std::endl; */
    return NULL;
}

std::string UserHost::getHostName()
{
    std::cout << "la" << std::endl;
    return NULL;
}

void UserHost::update(void) {
	std::cout << "hello" << std::endl;
}
