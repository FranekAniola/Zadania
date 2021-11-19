#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"


auto main() ->int
{
	auto st = Student{"Franciszek", "Aniola", "s25532",1,4};
	std::cout<<st.to_string()<<std::endl;
	
	return 0;
}
