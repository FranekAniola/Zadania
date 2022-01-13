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
	//std::cout<<" Correct parameter";
		x = atoi(secondCharacter);
	} else {
		std::cout<< "Wrong parameter";
		exit(1);
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
int& collumnInt, int& x, std::vector<char> collumn, std::vector<int> row, 
char shipField, int iValue, char v, char h,
std::vector<std::vector<char>>& vec) -> void {
	 
	int var = 0;
	int var2 = 0;
	int var3 = 0;
	
	bool isNoSpace;
	bool isNoSpace2;
	bool isNoSpace3;
	bool isNoSpace4;
	bool isNoSpace5;
	bool isNoSpace6;
	bool isNoSpace7;
	bool isNoSpace8;
	
	bool isOcupated;
	
	
	if(iValue <= 1) {
		if(argv[argvNum]) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
		
			for(int i = 0; i < iValue;++i) {
					
					if(collumnInt != 9) {
						isNoSpace = vec[x][collumnInt+1] != shipField;
					} else {
					isNoSpace = true;
					}
					
					if(collumnInt != 9 && x != 9) {
						isNoSpace7 = vec[x+1][collumnInt+1] != shipField;
					} else {
						isNoSpace7 = true;
					}
					
					if(collumnInt != 9 && x != 0) {
						isNoSpace6 = vec[x-1][collumnInt+1] != shipField;
					} else {
						isNoSpace6 = true;
					}
					
					if(collumnInt != 0 && x != 9) {
						isNoSpace8 = vec[x+1][collumnInt-1] != shipField;
					} else {
						isNoSpace8 = true;
					}
					
					if(collumnInt != 0 && x != 0) {
						isNoSpace5 = vec[x-1][collumnInt-1] != shipField;
					} else {
						isNoSpace5 = true;
					}
					
					if(collumnInt != 0) {
						isNoSpace2 = vec[x][collumnInt-1] != shipField;
					} else {
						isNoSpace2 = true;
					}
					
					if(x != 9) {
						isNoSpace3 = vec[x+1][collumnInt] != shipField;
					} else { 
						isNoSpace3 = true;
					}
					
					if(x != 0) {
						isNoSpace4 = vec[x-1][collumnInt] != shipField;
					} else {
						isNoSpace4 = true;
					}
					
					
					if(isNoSpace && isNoSpace2 && isNoSpace3 && isNoSpace4 && isNoSpace5 && isNoSpace6 && isNoSpace7 && isNoSpace8) {
						if(vec[x][collumnInt+i] == shipField) {
							std::cout<< "This place is occupated by other ship\n";
							exit(1);	
						} else {
							vec[x][collumnInt+i] = shipField;
						}
					} else {
						std::cout<< "There has to be at least on space between ships \n";
						exit(1);
					}			
			}
		}
		
	} else {
		
		//HORIZONTALLY
		
		if(argv[argvNum] && ship[2] == h) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
			
			for(int j = 0; j < 4; ++j) {
				
				if(iValue == 4 - var && collumnInt <= 9 && collumnInt >= (7 + j)) {
					std::cout<< "The ship is outside of the board\n";
					exit(1);	
				}
				var++;
			}
			
			for(int j = 0; j < iValue; ++j) {
			
				if(vec[x][collumnInt+j] == shipField) {
					std::cout<< "This place is alredy occupated by other ship\n";
					exit(1);
				} else {
					
					if(x != 9) {	
						isNoSpace = vec[x+1][collumnInt+j] != shipField;
					} else {
						isNoSpace = true;
					}
					
					
					if(x != 0) {	
						isNoSpace2 = vec[x-1][collumnInt+j] != shipField;
					} else {
						isNoSpace2 = true;
					}
					
					
					if(j == 0 && collumnInt != 0) {	
						isNoSpace3 = vec[x][collumnInt-1] != shipField;
					} else {
							isNoSpace3 = true;
					}
					
					
					if(j == iValue - 1 && collumnInt != 9) {	
						isNoSpace4 = vec[x][collumnInt + iValue] != shipField;
					} else {
						isNoSpace4 = true;
					}
					
					
					if(j == 0 && x != 0 && collumnInt != 0) {
						isNoSpace5 = vec[x - 1][collumnInt - 1] != shipField;
					} else {
						isNoSpace5 = true;
					}
					
					if(j == 0 && x != 9 && collumnInt != 0) {
						isNoSpace6 = vec[x + 1][collumnInt - 1] != shipField;
					} else {
						isNoSpace6 = true;
					}
					
					if(j == iValue - 1 && x != 0 && collumnInt != 9) {
						isNoSpace7 = vec[x - 1][collumnInt + iValue] != shipField;
					} else {
						isNoSpace7 = true;
					}
					
					if(j == iValue - 1 && x != 9 && collumnInt != 9) {
						isNoSpace8 = vec[x + 1][collumnInt + iValue] != shipField;
					} else {
						isNoSpace8 = true;
					}
					
					
					if(isNoSpace && isNoSpace2 && isNoSpace3 && isNoSpace4 && isNoSpace5 && isNoSpace6 && isNoSpace7 && isNoSpace8) {
					
						vec[x][collumnInt+j] = shipField;
						
					} else {
						std::cout<< "There has to be at least on space between ships \n";
						exit(1);
					}
				
			}	
		}
				
			//VERTICALLY
			
		} else if(argv[argvNum] && ship[2] == v) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
			
			for(int i = 0; i < 4; ++i) {
				
				if(iValue == 4 - var2 &&  x <= 9 && x >= 7 + i ) {
				
					std::cout<< "The ship is outside of the board\n";
					exit(1);
				}
				var2++;
			}
			

			for(int i = 0; i < iValue;++i) {
				if(vec[x+i][collumnInt] == shipField)
				{
					std::cout<< "This place is alredy occupated by other ship\n";
					exit(1);
				}
				
				if(collumnInt != 0) {	
					isNoSpace = vec[x + i][collumnInt-1] != shipField;
				} else {
					isNoSpace = true;
				}
				
				
					
				if(collumnInt != 9) {	
					isNoSpace2 = vec[x + i][collumnInt+1] != shipField;
				} else {
					isNoSpace2 = true;
				}
				
				//working
				if(i == 0 && x != 0) {	
					isNoSpace3 = vec[x - 1][collumnInt] != shipField;
				} else {
					isNoSpace3 = true;
				}
				
				//working
				if(i == iValue - 1 && x != 9) {	
					isNoSpace4 = vec[x + iValue][collumnInt] != shipField;
				} else {
					isNoSpace4 = true;
				}
				
				//working					
				if(i == 0 && x != 0 && collumnInt != 0) {
					isNoSpace5 = vec[x - 1][collumnInt - 1] != shipField;
				} else {
						isNoSpace5 = true;
				}
				
				//working
				if(i == iValue - 1 && x != 9 && collumnInt != 0) {
					isNoSpace6 = vec[x + iValue][collumnInt - 1] != shipField;
				} else {
						isNoSpace6 = true;
				}
				//working
				if(i == 0  && x != 0 && collumnInt != 9) {
						isNoSpace7 = vec[x - 1][collumnInt + 1] != shipField;
				} else {
						isNoSpace7 = true;
				}
				
				//working
				if(i == iValue - 1 && x != 9 && collumnInt != 9) {
					isNoSpace8 = vec[x + iValue][collumnInt + 1] != shipField;
				} else {
					isNoSpace8 = true;
				}
				
				
				if(isNoSpace && isNoSpace2 && isNoSpace3 && isNoSpace4 && isNoSpace5 && isNoSpace6 && isNoSpace7 && isNoSpace8) {
						vec[x+i][collumnInt] = shipField;
				} else {
					std::cout<< "There has to be at least on space between ships \n";
					exit(1);
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
