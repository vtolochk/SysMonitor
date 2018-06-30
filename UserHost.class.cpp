#include "UserHost.class.hpp"

UserHost::UserHost()
{
	this->update();
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
	return this->_UserName;
}

std::string UserHost::getHostName()
{
	return this->_HostName;
}

void UserHost::update(void) 
{
	char hostname[_POSIX_HOST_NAME_MAX];
	gethostname(hostname, _POSIX_HOST_NAME_MAX );
	this->_UserName = "Username: " + std::string(getlogin());
	this->_HostName = "Hostname: " + std::string(hostname);
}
