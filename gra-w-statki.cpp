#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/*
auto ships(std::vector row, std::vector collumn, int argc, char* argv[]){

	std::string firstShip = atoi(argv[1]);
	
	for(int i = 0; i < 10;++i){
		
		if(firstShip[0] == atoi(row) && firstShip[1] == atoi(collumn)){
			
		}
	}

}
*/



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
		std::cout<< "   " << collumn[i];
	}
	
	std::cout<<std::endl;
	
	for(int i = 0; i < vec.size();++i){
	std::cout<<row[i];
		for(int j = 0;j < vec[i].size();++j){
			
		std::cout<<'|' << vec[i][j] << "| ";
		}
		
	std:: cout << std::endl;
	
	}
	
	std::string firstShip;
	
	firstShip = std::string(argv[1]);
	
	
	
	for(int i = 0; i < 10;++i){
		
		if(firstShip[0] == row[i] && firstShip[1] == char(collumn[i])){
			
			std::cout<<"jest!";		
		}
	}
	/*
	std::cout<< "\n" <<argv[1] << "\n" ;		
	std::cout<<firstShip[1] << "\n";
	*/
	
	return 0;
}
