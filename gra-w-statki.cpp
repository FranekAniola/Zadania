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

auto settingUpShips(char *argv[], int argvNum, std::string ship, int& rowInt, int& x, std::vector<char>& row, std::vector<int>& collumn, char shipField, int iValue, char v, char h,std::vector<std::vector<char>>& vec) -> void{ 
	
	if(argv[argvNum] && ship[2] == h) {
		IsInputValid(rowInt,x,ship,row,collumn);
		std::cout<<std::endl;
		
		for(int i = 0; i < iValue;++i) {
			vec[rowInt][x+i] = shipField;
		}
		
	} else if(argv[argvNum] && ship[2] == v) {
		IsInputValid(rowInt,x,ship,row,collumn);
		std::cout<<std::endl;
		
		for(int i = 0; i < iValue;++i) {
			vec[rowInt+i][x] = shipField;
		}
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
	char shipField = 'x';
	
	

	std::string firstShip = std::string(argv[1]);
	std::string secondShip = std::string(argv[2]);
	std::string thirdShip = std::string(argv[3]);
	std::string frtShip = std::string(argv[4]);
	std::string fivthShip = std::string(argv[5]);
	std::string sixthShip = std::string(argv[6]);
	std::string seventhShip = std::string(argv[7]);
	std::string eightShip = std::string(argv[8]);
	std::string ninethShip = std::string(argv[9]);
	std::string tenthShip = std::string(argv[10]);

	settingUpShips(argv,1,firstShip, rowInt, x, row, collumn, shipField, 4, v,h,vec);
	settingUpShips(argv,2,secondShip, rowInt, x, row, collumn, shipField, 3, v,h,vec);
	settingUpShips(argv,3,thirdShip, rowInt, x, row, collumn, shipField, 3, v,h,vec);
	settingUpShips(argv,4,frtShip, rowInt, x, row, collumn, shipField, 2, v,h,vec);
	settingUpShips(argv,5,fivthShip, rowInt, x, row, collumn, shipField, 2, v,h,vec);
	settingUpShips(argv,6,sixthShip, rowInt, x, row, collumn, shipField, 2, v,h,vec);
	settingUpShips(argv,7,seventhShip, rowInt, x, row, collumn, shipField, 1, v,h,vec);
	settingUpShips(argv,8,eightShip, rowInt, x, row, collumn, shipField, 1, v,h,vec);
	settingUpShips(argv,9,ninethShip, rowInt, x, row, collumn, shipField, 1, v,h,vec);
	settingUpShips(argv,10,tenthShip, rowInt, x, row, collumn, shipField, 1, v,h,vec);

	PrintBoard(row, collumn, vec);
	
	return 0;
}
