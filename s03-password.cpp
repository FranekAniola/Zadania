#include <iostream>
#include <string>

auto main() -> int
{
std::string password = "student";
auto line = std::string{};

do
{
std::getline(std::cin, line);

if(line == password){
std::cout<<"correct"<<std::endl;
}else{
std::cout<<"incorrect"<<std::endl;
}

}while(line != password);

return 0;

}
