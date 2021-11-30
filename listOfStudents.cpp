#include <iostream>
#include <string>
#include <sstream>
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
    }	
	void view(){
		std::cout<<"\n name: " << name <<" surname: " << surname << 
		" index: " << index << " semester: " << semester<< std::endl;
		}
    
};
 std::string name(std::string n){
		std::cout<<"\npass a name: \n";
		std::cin>>n;
		return n;
	}
    
    std::string surname(std::string sn){
		std::cout<<"pass a surname: \n";
		std::cin>>sn;
		return sn;
	}
	
    std::string index(std::string i){
		std::cout<<"pass an index: \n";
		std::cin>>i;
		return i;
	}
	
	int semester(int sm){
	std::cout<<"Pass the current semester: \n";
	std::cin>>sm;
	return sm;	
	}
	
    void pushing(Student student){
		/*
		std::vector<Student>vectorStudent;
		vectorStudent.push_back(student);
		int vSize = vectorStudent.size();
		std::cout<<"List of size is: "<<vSize<<"\n";
		*/
	}
	
	void studentList(std::vector<Student*> vectorStudent){
	int k=0;
		for(Student* student : vectorStudent){					
		std::cout << k << " ";
		student->view();
		k++;
		}
	}
	
auto main() -> int
{
	std::vector<Student*>vectorStudent;
	std::string n, sn, i;
	int sm, choice, vSize, del;
	

	do{
	
	std::cout<<"1. Adding a new student \n";
	std::cout<<"2. View a full array of students\n";
	std::cout<<"3. Deleteing a student\n";
	std::cout<<"4. End process\n"; 
	std::cout<<"Pass what action you want to perform: ";
		
		std::cin>>choice;
		
		switch(choice){
		case 1:
		vectorStudent.push_back(new Student {name(n),surname(sn), index(i), semester(sm)});
		
		vSize = vectorStudent.size();
		std::cout<<"Size of list of Students is: "<<vSize<<"\n";
		break;
		case 2:
			studentList(vectorStudent);
		break;
		case 3:
		std::cout<<"Provide, which student would you like to delete:  ";
		std::cin>>del;
		vectorStudent.erase(vectorStudent.begin() + (del -1));
		std::cout<<"Student nr: "<<del<<"has been deleted\n";
		break;
		}
		
	}while(choice != 4);
		return 0;

}
