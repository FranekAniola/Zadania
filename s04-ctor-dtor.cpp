#include <iostream>
#include <string>



struct Student{
	private: 
	std::string name;
	std::string surname;
	
	public:	
	Student(std::string n, std::string s){
		name = n;
		surname = s;
	}
	~Student(){
		std::cout<<"DESTRUCTION!"<<std::endl;
		std::cout<<name<<std::endl;
		std::cout<<surname<<std::endl;
	}
};


auto main() -> int
{
	auto student = Student{"Franek", "aniola"};
	
	return 0;
}
