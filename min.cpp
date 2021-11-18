#include <iostream>

auto main() -> int
{
	int tab[3];
	int min;
	
	
	std::cout<<"Podaj elementy tablicy \n";
	
	for(int i = 0; i<3; ++i)
	{
		
		std::cin>>tab[i];
		
	}
	
	min = tab[0];
	
	for(int j = 0; j<3; ++j)
	{
		if(min>tab[j])
		{
			min = tab[j];
		}
		
	}
	std::cout<<"Najmniejszy element to: " << min <<"\n";
return 0;
}
