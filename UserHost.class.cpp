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
	return getlogin();
}

std::string UserHost::getHostName()
{
	char HostName[_POSIX_HOST_NAME_MAX];
	gethostname(HostName, _POSIX_HOST_NAME_MAX );
	this->_HostName.assign(HostName, _POSIX_HOST_NAME_MAX );
	return this->_HostName;
}

void UserHost::update(void) {
	std::cout << "hello" << std::endl;
}
