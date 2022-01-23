#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

auto IsInputValid(int& collumnInt, int& x,std::string ship,
 std::vector<char>& collumn, std::vector<int>& row) -> bool {
	char* secondCharacter = &ship[1];
	
	//sprawdzanie czy drugi znak stringa jest cyfrą od 0 do 9
	bool isEqualK = isdigit(ship[1]);
	
	bool isEqualR = (ship[0] >= 'A') && (ship[0] <= 'J');
	
	if(isEqualK && isEqualR) {
	//przypisanie do x drugiego znaku stringa który ma być użyty jako oznaczenie wiersza
		x = atoi(secondCharacter);
	} else {
		std::cout<< "Wrong parameter";
		exit(1);
	}
		//integerowa reprezentacja kolumny 
	for(int i = 0; i < collumn.size(); ++i) {
		if(ship[0] == collumn[i]) {
			collumnInt = i;
			break;
		}
	}
	
	return isEqualK && isEqualR;
}

//Print tablicy dwu wymiarowej
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


//ustawianie statków, sprawdzenie czy statki na siebie nie nachodzą oraz sprawdzenie czy dookoła statku jest przynajmniej jedno wolne miejsce 

auto settingUpShips(char *argv[], int argvNum, std::string ship, 
int& collumnInt, int& x, std::vector<char> collumn, std::vector<int> row, 
char shipField, int iValue, char v, char h,
std::vector<std::vector<char>>& vec) -> void {
	 
	
	bool isNoSpace;
	bool isNoSpace2;
	bool isNoSpace3;
	bool isNoSpace4;
	bool isNoSpace5;
	bool isNoSpace6;
	bool isNoSpace7;
	bool isNoSpace8;
	
	bool isOcupated;
	
	//iValue <=1 odnosi się do jednomasztowych statków
	
	if(iValue <= 1) {
		if(argv[argvNum]) {
			IsInputValid(collumnInt,x,ship,collumn,row);
			std::cout<<std::endl;
		
			for(int i = 0; i < iValue;++i) {
					//sprwadzenie prawej strony  
					if(collumnInt < 9) {
						isNoSpace = vec[x][collumnInt+1] != shipField;
					} else {
					isNoSpace = true;
					}
					//sprwadzenie dolnej prawej strony
					if(collumnInt < 9 && x < 9) {
						isNoSpace7 = vec[x+1][collumnInt+1] != shipField;
					} else {
						isNoSpace7 = true;
					}
					//sprwadzenie górnej prawej strony 
					if(collumnInt < 9 && x > 0) {
						isNoSpace6 = vec[x-1][collumnInt+1] != shipField;
					} else {
						isNoSpace6 = true;
					}
					//sprwadzenie dolnej lewej strony
					if(collumnInt > 0 && x < 9) {
						isNoSpace8 = vec[x+1][collumnInt-1] != shipField;
					} else {
						isNoSpace8 = true;
					}
					//sprwadzenie górnej lewej strony
					if(collumnInt > 0 && x > 0) {
						isNoSpace5 = vec[x-1][collumnInt-1] != shipField;
					} else {
						isNoSpace5 = true;
					}
					//sprwadzenie lewej strony 
					if(collumnInt > 0) {
						isNoSpace2 = vec[x][collumnInt-1] != shipField;
					} else {
						isNoSpace2 = true;
					}
					//sprwadzenie górnej strony
					if(x < 9) {
						isNoSpace3 = vec[x+1][collumnInt] != shipField;
					} else { 
						isNoSpace3 = true;
					}
					//sprwadzenie dolnej strony
					if(x > 0) {
						isNoSpace4 = vec[x-1][collumnInt] != shipField;
					} else {
						isNoSpace4 = true;
					}
					
					
					if(isNoSpace && isNoSpace2 && isNoSpace3 && isNoSpace4 && isNoSpace5 && isNoSpace6 && isNoSpace7 && isNoSpace8) {
						if(vec[x][collumnInt+i] == shipField) {
							std::cout<< "This field is occupated by other ship\n";
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
				
				if(iValue == 4 - j && collumnInt <= 9 && collumnInt >= (7 + j)) {
					std::cout<< "The ship is outside of the board\n";
					exit(1);	
				}
				
			}
			
			for(int j = 0; j < iValue; ++j) {
			
				if(vec[x][collumnInt+j] == shipField) {
					std::cout<< "This field is alredy occupated by other ship\n";
					exit(1);
				} else {
					//sprawdza dół
					if(x < 9) {	
						isNoSpace = vec[x+1][collumnInt+j] != shipField;
					} else {
						isNoSpace = true;
					}
					
					//sprwadza górę
					if(x > 0) {	
						isNoSpace2 = vec[x-1][collumnInt+j] != shipField;
					} else {
						isNoSpace2 = true;
					}
					
					//sprawdza lewe pole
					if(j == 0 && collumnInt > 0) {	
						isNoSpace3 = vec[x][collumnInt-1] != shipField;
					} else {
							isNoSpace3 = true;
					}
					
					// sprawdza prawe pole
					if(j == iValue - 1 && collumnInt < 9 && collumnInt < 10 - iValue ) {
						//debugowanie
						if (collumnInt + iValue >= 10) {
                            std::cout << "ERROR: Out of vector scope" << std::endl;
                        }
							
						isNoSpace4 = vec[x][collumnInt + iValue] != shipField;
					} else {
						isNoSpace4 = true;
					}
					 
					//sprawdza lewą górę
					if(j == 0 && x > 0 && collumnInt > 0) {
						isNoSpace5 = vec[x - 1][collumnInt - 1] != shipField;
					} else {
						isNoSpace5 = true;
					}
					
					// sprawdza lewy dół
					if(j == 0 && x < 9 && collumnInt > 0) {
						isNoSpace6 = vec[x + 1][collumnInt - 1] != shipField;
					} else {
						isNoSpace6 = true;
					}
					
					//sprawdza prawą górę
					if(j == iValue - 1 && x > 0 && collumnInt < 9 && collumnInt < 10 - iValue) {
						isNoSpace7 = vec[x - 1][collumnInt + iValue] != shipField;
					} else {
						isNoSpace7 = true;
					}
					
					//sprawdza prawy dół
					if(j == iValue - 1 && x < 9 && collumnInt < 9 && collumnInt < 10 - iValue ) {
						
						isNoSpace8 = vec[x + 1][collumnInt + iValue] != shipField;
					} else {
						isNoSpace8 = true;
					}
					
					
					if(isNoSpace && isNoSpace2 &&
					 isNoSpace3 && isNoSpace4 && 
					 isNoSpace5 && isNoSpace6 &&
					 isNoSpace7 && isNoSpace8) {
					
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
				
				if(iValue == 4 - i &&  x <= 9 && x >= 7 + i ) {
				
					std::cout<< "The ship is outside of the board\n";
					exit(1);
				}
				
			}
			
			
			for(int i = 0; i < iValue;++i) {
				if(vec[x+i][collumnInt] == shipField)
				{
					std::cout<< "This field is alredy occupated by other ship\n";
					exit(1);
				}
				//Sprawdza pole po lewej stronie
				if(collumnInt > 0) {	
					isNoSpace = vec[x + i][collumnInt-1] != shipField;
				} else {
					isNoSpace = true;
				}
				
				//sprawdza pole po prawej stronie
				if(collumnInt < 9) {	
					isNoSpace2 = vec[x + i][collumnInt+1] != shipField;
				} else {
					isNoSpace2 = true;
				}
				
				//sprawdza początkowy górne pole 
				if(i == 0 && x > 0) {	
					isNoSpace3 = vec[x - 1][collumnInt] != shipField;
				} else {
					isNoSpace3 = true;
				}
				
				//sprawdza dolne pole 
				if(i == iValue - 1 && x < 9 && x < 10 - iValue) {	
					isNoSpace4 = vec[x + iValue][collumnInt] != shipField;
				} else {
					isNoSpace4 = true;
				}
				
				//sprawdza górne lewe pole 			
				if(i == 0 && x > 0 && collumnInt > 0) {
					isNoSpace5 = vec[x - 1][collumnInt - 1] != shipField;
				} else {
						isNoSpace5 = true;
				}
				
				//sprawdza dolne lewe pole
				if(i == iValue - 1 && x < 9 && collumnInt > 0 && x < 10 - iValue) {
					isNoSpace6 = vec[x + iValue][collumnInt - 1] != shipField;
						if (x + iValue >= 10) {
                          std::cout << "ERROR: Out of vector scope" << std::endl;
                        }
				} else {
						isNoSpace6 = true;
				}
				
				// srpawdza górne prawe pole
				if(i == 0  && x > 0 && collumnInt < 9) {
					isNoSpace7 = vec[x - 1][collumnInt + 1] != shipField;
				} else {
					isNoSpace7 = true;
				}
				
				//sprawdza dolne prawe pole
				if(i == iValue - 1 && x < 9 && collumnInt < 9 && x < 10 - iValue) {
					isNoSpace8 = vec[x + iValue][collumnInt + 1] != shipField;
				} else {
					isNoSpace8 = true;
				}
				
				
				if(isNoSpace && isNoSpace2 && 
				isNoSpace3 && isNoSpace4 && 
				isNoSpace5 && isNoSpace6 && 
				isNoSpace7 && isNoSpace8) {
					
					vec[x+i][collumnInt] = shipField;
				} else {
					std::cout<< "There has to be at least on space between ships \n";
					exit(1);
				}	
			}
		}
	}
}


auto isShipDestroyed(std::vector<int>& vecOfHits, std::vector<std::string> ships, 
std::vector<char> collumn, std::vector<std::vector<char>>& vec, char shipField) -> void {
	
	int var; 
	int digit;
	int collumnInt;
	bool zatopiony = false;
	
	for(int k = 0; k < 10; ++k) {
		
		if(k == 0) {
			var = 4;
		} else if(k == 1 || k == 2) { 
			var = 3;
		} else if (k == 3|| k == 4 || k == 5) {
			var = 2;
		}
			
		if(ships[k][2] == 'v') {
			for(int i = 0; i < collumn.size(); ++i) {
				if(ships[k][0] == collumn[i]) {
					collumnInt = i;
					break;
				}
			}
			char* secondCharacter3 = &ships[k][1];
			digit = atoi(secondCharacter3);
			
			for(int j = 0; j < var; ++j) {
				if(vec[digit+j][collumnInt] == 'T') {
					vecOfHits[k]++;
				}
			}
			
		} else if(ships[k][2] == 'h') {
			
			for(int i = 0; i < collumn.size(); ++i) {
				if(ships[k][0] == collumn[i]) {
					collumnInt = i;
					break;
				}
			}
			
			char* secondCharacter3 = &ships[k][1];
			digit = atoi(secondCharacter3);
			
			for(int j = 0; j < var;++j) {
				if(vec[digit][collumnInt+j] == 'T') {
					vecOfHits[k]++;
				}
			}
			
		} else if(k == 6 || k == 7 || k == 8 || k == 9 ) {
			
			for(int i = 0; i < collumn.size(); ++i) {
				if(ships[k][0] == collumn[i]) {
					collumnInt = i;
					break;
				}
			}
			
			char* secondCharacter = &ships[k][1];
			digit = atoi(secondCharacter);
			
			
			if(vec[digit][collumnInt] == 'T') {
				vecOfHits[k]++;
			}
			
		}
	}
}

auto userInput(std::vector<int> vecOfHits, std::vector<std::string> ships,
 std::string shot, int& letter, int& digit, std::vector<char> collumn,
 std::vector<std::vector<char>>& vec, char shipField) -> void {	
		
		std::string score = "";
		
		for(int i = 0; i < 2;++i) {
			
			std::cout<<"Pass three fields that you want to uncover,"
			" each parameter must be separated with space: ";
			std::getline(std::cin,shot);
			
			for(int k = 0; k<8;k+=3) {
				for(int j = 0; j < collumn.size(); ++j) {
					if(shot[k] == collumn[j]) {
						letter = j;
						break;
					}
				}
				char* secondCharacter2 = &shot[k+1];
				digit = atoi(secondCharacter2);
			
				if(vec[digit][letter]  == shipField ) {
					score += "T";
					vec[digit][letter]  = 'T';
				} else if(vec[digit][letter]  == '.') {
					score += "P";
					vec[digit][letter] = 'P';
				} else if(vec[digit][letter] == 'T' || vec[digit][letter]  == 'P') {
					score += "D";
				} 
				
			}
			
			isShipDestroyed(vecOfHits, ships, collumn, vec, shipField);
			int lValue;
			
			for(int l = 0; l < 10;++l) {
				if(l == 0) {
					lValue = 4;
				} else if(l == 1 || l == 2) {
					lValue = 3;
				} else if(l == 3 || l == 4 || l == 5) {
					lValue = 2;
				} else if(l == 6 || l == 7 || l == 8 || l == 9) {
					lValue = 1;
				} 
				
				if(vecOfHits[l] == lValue) {
					score += "Z";
				}
			}
			
			isShipDestroyed(vecOfHits, ships, collumn, vec, shipField);
				
			std::cout<<score<<std::endl;
	}
	
 }

auto main(int argc, char *argv[]) -> int {
	
	std::vector<std::vector<char>> vec =
    {
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //1
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //2
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //3
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //4
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //5
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //6
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //7
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //8
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //9
        {'.', '.', '.','.', '.', '.', '.', '.', '.','.'}, //10
    };
      
    auto collumn = std::vector<char> {'A','B','C','D','E','F','G','H','I','J'};
    auto row = std::vector<int>{0,1,2,3,4,5,6,7,8,9};
	
	int x;
	int collumnInt;
	char v = 'v';
	char h = 'h';
	char shipField = 'x';
	//User input variebles
	std::string shot;
	int digit;
	int letter;
	auto ships = std::vector<std::string>{};
	auto vecOfHits = std::vector<int>{0,0,0,0,0,0,0,0,0,0};
	
	//zamiana char argv na stringa 
	
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
	
	ships.push_back(firstShip);
	ships.push_back(secondShip);
	ships.push_back(thirdShip);
	ships.push_back(frtShip);
	ships.push_back(fivthShip);
	ships.push_back(sixthShip);
	ships.push_back(seventhShip);
	ships.push_back(eightShip);
	ships.push_back(ninethShip);
	ships.push_back(tenthShip);

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
	
		userInput(vecOfHits, ships,shot,letter,digit,collumn,vec,shipField);

		PrintBoard(collumn, row, vec);
	return 0;
}
