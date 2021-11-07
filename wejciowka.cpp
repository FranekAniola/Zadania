#include <iostream>
auto main() ->int
{
int a;
std::cin>>a;
	
	for(int i=1; i<=a ;++i)
	{
		
		for(int j=1; j<=i ;++j)
		{
		std::cout<<"#";
		
		}
		
		for(int j=a-1; j>=i ;--j)
		{
		std::cout<<"-";
		
		}
		
				
	std::cout<<"\n";
	}
	
	
	for(int i=a; i>=1 ;--i)
	{
		
		for(int j=1; j<=i ;++j)
		{
		std::cout<<"#";
		
		}
		
		for(int k=a; k>i ;--k)
		{
		std::cout<<"-";
		
		}
	std::cout<<"\n";
	}
	
	
	
	return 0;
}
