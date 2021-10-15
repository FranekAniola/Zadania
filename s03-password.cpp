#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
std::string provided_password;
if(argc <= 1){

std::cout<<"error"<< "\n";
return 1;
}

std::string password = std::string(argv[1]);

do
{
	std::cout << "password: " <<"\n";
	std::cin>>provided_password;
	
}while(password != provided_password);
std::cout<<"correct password\n";
return 0;

}
