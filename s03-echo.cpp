#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> create_vector(int const argc, char* argv[])
{
    std::vector <std::string> vector_to_create;

    for (int i = 0; i < argc; i++) {
        vector_to_create.push_back(std::string(argv[i]));
    }
	
    vector_to_create.erase(vector_to_create.begin());

    return vector_to_create;
}

auto main(int argc, char* argv[]) -> int
{
    auto main_vector = create_vector(argc, argv);
    auto print_vector = std::vector<std::string>{};

    auto new_line = std::string{"\n"};
    auto separator = std::string{" "};
    auto reverse_order = true;



    for (auto i = 0; i < main_vector.size(); ++i) {
        auto const& each = main_vector.at(i);
        
        if (each == "-l") {
			
            separator = "\n";
        } else if (each == "-n") {
			
            new_line = "";
        } else if (each == "-r") {
			
            std::reverse(main_vector.begin(), main_vector.end());
        } else {
            std::copy(main_vector.begin() + i, main_vector.end(), std::back_inserter(print_vector));
            break;
        }
    }

    if (reverse_order){
        for (auto const& each : print_vector) {
            std::cout << each << separator;
        }
    }


    std::cout << new_line;  
 

   
    return 0;
}
