#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<std::string> create_vector(int const argc, char* argv[])
{
    std::vector <std::string> vector_to_create;

    for (int i = 0; i < argc; i++) {
        vector_to_create.push_back(std::string(argv[i]));
    }
    return vector_to_create;
}


int choice;
float one, two, res1, res2;
int exponent, base, power=1;
int main(int argc, char*argv[])


{
auto main_vector = create_vector(argc, argv);
int num1;
int num2;
std::cout<<"select the action number, which you want ot execute.\n";
std::cout<<"1. add (+) \n";
std::cout<<"2. rest of the division (%) \n";
std::cout<<"3. Dividing intigers (//) \n";
std::cout<<"4. multiplying  (*) \n";
std::cout<<"5. Dividing (/) \n";
std::cout<<"6. powering  (**) \n";
std::cout<<"7. Square root (sqrt) \n";
std::cout<<"Choice: ";
std::cin>>choice;

    num1 = std::stoi(argv[1]);
   
    num2 = std::stoi(argv[2]);

    for (int i = 1; i < argc-1; i = i + 1)
    {

        switch (choice)
        {
            case 1:
                std::cout<< (num1+num2)<<"\n";
                break;
            case 2:
                std::cout<< (num1%num2)<<"\n";
                break;
            case 3:
				std::cout<< (num1/num2)<<"\n";
                break;
            case 4:
                std::cout<< (num1*num2)<<"\n";
                break;
            case 5:
				one=num1;
				two=num2;
				std::cout<<(one/two)<<"\n";
				break;
			case 6:
				exponent=num2;
				base=num1;
				for(int i=0; i<exponent; i++)
				{
				power*=base;
				}
				std::cout<<power<<"\n";
				break;
			case 7:
				one=num1;
				two=num2;
				res1=sqrt(one);
				res2=sqrt(two);
				std::cout<<"power of first number: "<<res1<<"\n"<<"Power of second number: " <<res2<<"\n";

            default:
                break;
        }
    }
    return 0;
}
		
		
		
	
	

