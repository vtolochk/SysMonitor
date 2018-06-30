#include "UserHost.class.hpp"

int main(void)
{
    UserHost lala;
    std::string userName = lala.getUserName();
    std::string hostName = lala.getHostName();
    std::cout << userName << std::endl;
    std::cout << hostName << std::endl;
    return 0;
}