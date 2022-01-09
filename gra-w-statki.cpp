#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


auto IsInputValid(int& collumnInt, int& x,std::string ship,
 std::vector<char>& collumn, std::vector<int>& row) -> bool {
	char* secondCharacter = &ship[1];

	bool isEqualK = isdigit(ship[1]);
	
	bool isEqualR = (ship[0] >= 'A') && (ship[0] <= 'J');
	
	if(isEqualK && isEqualR) {
		std::cout<<" Correct parameter";
		x = atoi(secondCharacter);
	} else {
		std::cout<<"Wrong parameter";
	}
	
	for(int i = 0; i < collumn.size(); ++i) {
		if(ship[0] == collumn[i]) {
			collumnInt = i;
			break;
		}
	}
	
	return isEqualK && isEqualR;
}


auto PrintBoard(std::vector<char>& collumn, std::vector<int>& row,
 std::vector<std::vector<char>>& vec) -> void {
	
	for(int i = 0;i < row.size();++i) {
		std::cout<< "  " << collumn[i] << " "; 
	}
	
	std::cout<<std::endl;
	
	for(int i = 0; i < vec.size();++i) {
		std::cout<<row[i];
		for(int j = 0;j < vec[i].size();++j) {
			std::cout<<'|' << vec[i][j] << "| ";
		}
		
		std:: cout << std::endl;
	}
}

auto settingUpShips(char *argv[], int argvNum, std::string ship, 
int& collumnInt, int& x, std::vector<char>& collumn, std::vector<int>& row, 
char shipField, int iValue, char v, char h,
std::vector<std::vector<char>>& vec) -> void {
	 
	int var = 0;
	int var2 = 0;
	bool isPicked;
	bool isPicked2;
	if(iValue <= 1){
	
		if(argv[argvNum]) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
		
			for(int i = 0; i < iValue;++i) {
				if(vec[x][collumnInt+i] == shipField){
					std::cout<<"you ve alredy picked that place \n";
					exit(1);
				}else{
					vec[x][collumnInt+i] = shipField;
				}			
			}
		
		}

	} else {
	
		if(argv[argvNum] && ship[2] == h) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
			
			for(int j = 0; j < 4; ++j) {
				var++;
				if(iValue == 1 + var && collumnInt == 10 - var) {
					std::cout<<"Unforunetly there is no more space left \n";
					exit(1);	
				}
			}
			
			for(int i = 0; i < 4;++i) {
				
				isPicked = vec[x][collumnInt+i] == shipField;
				
				if(isPicked == true){
					std::cout<<"you ve alredy picked that place \n";
					exit(1);
				}else{
					break;
				}
			}
			
			if(isPicked == false){
				for(int j = 0; j < iValue;++j) {
					vec[x][collumnInt+j] = shipField;
				}
			}
		
		} else if(argv[argvNum] && ship[2] == v) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
			
			for(int i = 0; i < 4; ++i){
				var2++;
				if(iValue == 1 + var2 &&  x == row[10-var2] ) {
				
					std::cout<<"Unforunetly there is no more space left \n";
					exit(1);
				}
			}
			
			for(int i = 0; i < iValue;++i) {
				
				isPicked = vec[x+i][collumnInt] == shipField;
				
				if(isPicked2 == true){
					std::cout<<"you ve alredy picked that place \n";
					
					exit(1);
				}else{
					break;
				}
			}
			
			if(isPicked2 == false) {
				
				for(int i = 0; i < iValue;++i) {
				
					vec[x+i][collumnInt] = shipField;
				}
			}
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
      
    auto collumn = std::vector<char> {'A','B','C','D','E','F','G','H','I','J'};
    auto row = std::vector<int>{0,1,2,3,4,5,6,7,8,9};
    
    
    PrintBoard(collumn, row, vec);
	
	int x;
	int collumnInt;
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

	settingUpShips(argv,1,firstShip, collumnInt, x, collumn, row, shipField, 4, v,h,vec);
	settingUpShips(argv,2,secondShip, collumnInt, x, collumn, row, shipField, 3, v,h,vec);
	settingUpShips(argv,3,thirdShip, collumnInt, x, collumn, row, shipField, 3, v,h,vec);
	settingUpShips(argv,4,frtShip, collumnInt, x, collumn, row, shipField, 2, v,h,vec);
	settingUpShips(argv,5,fivthShip, collumnInt, x, collumn, row, shipField, 2, v,h,vec);
	settingUpShips(argv,6,sixthShip, collumnInt, x, collumn, row, shipField, 2, v,h,vec);
	settingUpShips(argv,7,seventhShip, collumnInt, x, collumn, row, shipField, 1, v,h,vec);
	settingUpShips(argv,8,eightShip, collumnInt, x, collumn, row, shipField, 1, v,h,vec);
	settingUpShips(argv,9,ninethShip, collumnInt, x, collumn, row, shipField, 1, v,h,vec);
	settingUpShips(argv,10,tenthShip, collumnInt, x, collumn, row, shipField, 1, v,h,vec);

	PrintBoard(collumn, row, vec);
	
	return 0;
}
