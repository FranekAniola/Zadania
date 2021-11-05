#include <iostream>

auto main(int argc, char* argv[]) -> int
{
		for(int i = atoi(argv[1]); i>=0;--i)
		{
			std::cout<< i <<" bottles of beer on the wall,"<< i << "bottles of beer.\n"
			"Take one down, pass it around, " << i << " bottles of beer on the wall...\n";
			if(i==0)
			{
				std::cout<<"No more bottles of beer on the wall, no more bottles of beer.\n"
			"Go to the store and buy some more," << atoi(argv[1]) <<"bottles of beer on the wall...\n";
			}
		}
}

