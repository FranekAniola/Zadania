#include <iostream>
#include <string>
#include <sstream>

struct Student{
	private: 
	std::string name;
	std::string surname;
	std::string index;
	int semester;
	float avarage;
	
	public:	
	Student(std::string n, std::string sn, std::string i, int sm, float ag)
	{
		name = n;
		surname = sn;
		index = i;
		semester = sm;
		avarage = ag;
		
	}	


	auto const to_string() -> std::string
    {
    auto result = std::ostringstream{};
	result << name << " " <<surname << " ("<<index<<") semester: " << semester << " avarage grade: "<< avarage;
	
	return result.str();    
    }
};

auto main() ->int
{
	auto st = Student{"Franciszek", "Aniola", "s25532",1,4};
	std::cout<<st.to_string()<<std::endl;
	
	return 0;
}
