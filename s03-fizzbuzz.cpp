#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
auto main(int argc, char* argv[]) -> int
{

for(int i = 1; i <= argc;++i){
std::cout<< argv[i]<< " ";

if(atoi(argv[i])%3==0 && atoi(argv[i])%5!=0)
{
        std::cout<<"Fizz"<< "\n";
}
else if(atoi(argv[i])%5==0 && atoi(argv[i])%3!=0){
        std::cout<<"Buzz"<< "\n";
}
else if(atoi(argv[i])%3==0 && atoi(argv[i])%5==0){
std::cout<<"FizzBuzz"<< "\n";
}

}



return 0;
}

