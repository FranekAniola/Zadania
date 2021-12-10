#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdint>
#include "Time.h"


auto main() ->int
{
	auto t = Time{4,2,5};
	
	auto t2 = Time{4,2,2};
	Time result = t + t2;
	Time result2 = t - t2;
	bool result3 = t==t2;
	bool result4 = t!=t2;
	bool result5 = t<t2;
	bool result6 = t>t2;
	
		
	t.next_hour();
	t2.next_hour();
	
	std::cout<<t.to_string()<<std::endl;
	
	std::cout<<t.string2(t.tod())<<std::endl;
	
	std::cout<<t.countSeconds(t)<<" seconds have passed since midnight :>"<<std::endl;
	std::cout<<t.countMinutes(t)<<" minutes have passed since midnight :>"<<std::endl;
	
	std::cout<<t.timeToMidnight().to_string()<<" time left to midnight :>"<<std::endl;
	
	std::cout<<result.to_string()<<std::endl;
	
	std::cout<<result2.to_string()<<std::endl;
		
	std::cout<<"Check if first time: "<< t.to_string() << " equels to second time: "<< t2.to_string()<< " Answer:" <<result3<<std::endl;
	
	std::cout<<"Check if first time: "<< t.to_string() << " is not equel to second time: "<< t2.to_string()<< " Answer: " <<result4<<std::endl;
	
	std::cout<<"Check if first time: "<< t.to_string() << " is lesser than second time: "<< t2.to_string()<< " Answer: " <<result5<<std::endl;
	
	std::cout<<"Check if first time: "<< t.to_string() << " is gratter than second time: "<< t2.to_string()<< " Answer: " <<result6<<std::endl;


	return 0;
	
}
