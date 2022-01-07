#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


auto IsInputValid(std::string ship, std::vector<char>& row, std::vector<int>& collumn) -> bool{
	bool isEqualK = isdigit(ship[1]);
	bool isEqualR = (ship[0] >= 'A') && (ship[0] <= 'J');
		
	if(isEqualK && isEqualR) {
		std::cout<<"Correct parameters";
	} else {
		std::cout<<"Wrong parameters";
	}

	return isEqualK && isEqualR;
}


auto main(int argc, char *argv[]) ->int
{
	
	
	std::vector<std::vector<char>> vec =
    {
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //1
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //2
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //3
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //4
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //5
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //6
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //7
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //8
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //9
        {'.', '.', '.','.', '.', '.','.', '.', '.','.'}, //10
    };
    
    
    
    auto row = std::vector<char>{'A','B','C','D','E','F','G','H','I','J'};
    auto collumn = std::vector<int>{0,1,2,3,4,5,6,7,8,9};
    
    for(int i = 0;i < collumn.size();++i){
		std::cout<< " " << collumn[i] << "  "; 
	}
	
	std::cout<<std::endl;
	
	for(int i = 0; i < vec.size();++i){
		
		for(int j = 0;j < vec[i].size();++j){
			
		std::cout<<'|' << vec[i][j] << "| ";
		}
		std::cout<<row[i];
		std:: cout << std::endl;
		
	}
	
	std::string firstShip;
	
	firstShip = std::string(argv[1]);
	
	IsInputValid(firstShip,row,collumn);
	
	std::cout<< "\n" <<argv[1] << "\n" ;		
	//std::cout<<firstShip[0] << "\n";
	//std::cout<<firstShip[1] << "\n";
	
	
	return 0;
}
