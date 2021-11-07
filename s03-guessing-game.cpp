#include <iostream>
#include <string>
#include <random>
auto main() ->int
{

std::random_device rd;
std::uniform_int_distribution <int> d100 (1, 100);

int guess;

int random = static_cast<int>(d100(rd));

do{

std::cin>>guess;

if(guess > random){
	std::cout<< "number too big!"<< std::endl;
}else if(guess < random){
	std::cout<< "number too small!"<< std::endl;
}else if(guess == random){
	std::cout<< "Right answer!"<< std::endl;
}

}while(guess != random);

return 0;
}
