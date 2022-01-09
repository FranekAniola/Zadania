#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


auto IsInputValid(int& rowInt, int& x,std::string ship, std::vector<char>& row, std::vector<int>& collumn) -> bool {
	char* secondCharacter = &ship[1];

	bool isEqualK = isdigit(ship[1]);
	
	bool isEqualR = (ship[0] >= 'A') && (ship[0] <= 'J');
	
	if(isEqualK && isEqualR) {
		std::cout<<"\n Correct parameters";
		x = atoi(secondCharacter);
	} else {
		std::cout<<"Wrong parameters";
	}
	
	for(int i = 0; i <10; ++i) {
		if(ship[0] == row[i]) {
			rowInt = i;
			break;
		}
	}
	
	return isEqualK && isEqualR;
}



auto PrintBoard(std::vector<char>& row, std::vector<int>& collumn, std::vector<std::vector<char>>& vec) -> void {
	
	for(int i = 0;i < collumn.size();++i) {
		std::cout<< " " << collumn[i] << "  "; 
	}
	
	std::cout<<std::endl;
	
	for(int i = 0; i < vec.size();++i) {
		for(int j = 0;j < vec[i].size();++j) {
			std::cout<<'|' << vec[i][j] << "| ";
		}
		std::cout<<row[i];
		std:: cout << std::endl;
	}
}

auto main(int argc, char *argv[]) -> int {
	
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
      
    auto row = std::vector<char> {'A','B','C','D','E','F','G','H','I','J'};
    auto collumn = std::vector<int>{0,1,2,3,4,5,6,7,8,9};
    auto rowToNumbers = std::vector<int>{};
    
  
    
    PrintBoard(row, collumn, vec);
	
	int x;
	int rowInt;
	char v = 'v';
	char h = 'h';
	
	std::string firstShip;
	std::string secondShip;
	
	firstShip = std::string(argv[1]);
	secondShip = std::string(argv[2]);
	
	


	char ShipField = 'x';
	
	if(argv[1] && firstShip[2] == h) {
		IsInputValid(rowInt,x,firstShip,row,collumn);
		std::cout<<std::endl;
		
		for(int i = 0; i < 4;++i) {
			vec[rowInt][x+i] = ShipField;
		}
		
	} else if(argv[1] && firstShip[2] == v) {
		IsInputValid(rowInt,x,firstShip,row,collumn);
		std::cout<<std::endl;
		
		for(int i = 0; i < 4;++i) {
			vec[rowInt+i][x] = ShipField;
		}
	
	}
	
	IsInputValid(rowInt,x,secondShip,row,collumn);
	std::cout<<std::endl;
	
	vec[rowInt][x] = ShipField;
	
	PrintBoard(row, collumn, vec);
	
	return 0;
}
