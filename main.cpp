#include "UserHost.class.hpp"
#include "DateTime.class.hpp"
#include "OSInfo.class.hpp"
#include "CPU.class.hpp"


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


	OSInfo testOSInfo;

	std::cout << testOSInfo.getOSName() << std::endl;
	std::cout << testOSInfo.getKernelVersion() << std::endl;


	CPU testCPU;


	std::cout << testCPU.getBrand() << std::endl;
	std::cout << testCPU.getCores() << std::endl;

	double avg[3];
	getloadavg(avg, 3);
	std::cout << avg[0] << std::endl;
	std::cout << avg[1] << std::endl;
	std::cout << avg[2] << std::endl;

	return 0;
}
