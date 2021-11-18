#include <iostream>

auto main(int argc, char* argv[]) ->int
{
	if(argc>2)
	{
	std::cout<<"You are supposed to give just one argument";
	return 1;
	}

	for(int i = atoi(argv[1]); i >= 0 ;--i)
	{
		std::cout<<i<<"\n";
	}

return 0;
} 


