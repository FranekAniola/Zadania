#include <iostream>
#include <string>
#include <sstring>
#include <vector>
#include <algorithm>


struct Student{
	private: 
	std::string name;
	std::string surname;
	std::string index;
	int semester;
	
	public:	
	Student(std::string n, std::string sn, std::string i, int sm)
	{
		name = n;
		surname = sn;
		index = i;
		semester = sm;
		avarage = ag;
    }
    
};

	std::string imie()
	{
		std::cout<<"Give the name: \n"
		std::cin>>name;
		return 0;
	}
	
	std::string surname()
	{
		std::cout<<"Give the surname: \n"
		std::cin>>surname;
		return 0;
	}
	
	std::string index()
	{
		std::cout<<"Give the index: \n"
		std::cin>>index;
		return 0;
	}
	
	std::string avarage()
	{
		std::cout<<"Give the avarage: \n"
		std::cin>>avarage;
		return 0;
	}



auto main() -> int
{
	int choice;
	
	std::cout<<"1. Dodaj studenta \n";
	std::cout<<"2. usun studenta \n";
	std::cout<<"3. wyswietl studenta \n";
	std::cout<<"4. Zakoncz program \n";
	std::cout<<"Podaj jaka akcje wykonac \n";
	
	std::vector <Student*> vectorStudent;
	vectorStudent.erase(vectorStudent.begin());
	
	switch(choice):
	case 1:
	vectorStudent.push_back(Student);
	default:
	break;s
}
