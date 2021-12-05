#include <iostream>
#include <string>



struct Var{
	public:
	void show(){
		std::cout<< this <<std::endl;
	}

};


auto main() -> int
{
	auto var = Var();
	var.show();
	std::cout << &var <<std::endl;
	return 0;
}
