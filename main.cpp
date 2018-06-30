#include "UserHost.class.hpp"
#include "DateTime.class.hpp"

int main(void)
{
	DateTime testDateTime;

	testDateTime.update();
	std::cout << testDateTime.getDate() << std::endl;
	std::cout << testDateTime.getTime() << std::endl;
	UserHost lala;
	std::string userName = lala.getUserName();
	std::string hostName = lala.getHostName();
	std::cout << userName << std::endl;
	std::cout << hostName << std::endl;
	return 0;
}
