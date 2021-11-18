#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

auto main(int argc, char* argv[]) -> int
{

for(int i = 1;i <= atoi(argv[1]);++i)
{
std::cout<<i<<"  ";


if(i%3==0 && i%5!=0)
{
        std::cout<<"Fizz"<< "\n";
}
else if(i%5==0 && i%3!=0){
	
        std::cout<<"Buzz"<< "\n";
}
else if(i%3==0 && i%5==0){
	
std::cout<<"FizzBuzz"<< "\n";

}else{
	std::cout<<"\n";
	}



}


return 0;
}

