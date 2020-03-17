#include <iostream>
#include <vector>
#include <fstream>
#include "TicTacToe.hpp"

int main(int argc, char *argv[]) {
    std::vector< std::vector<char> > board (5, std::vector<char> (5,'\0')); 
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        perror("Error when attempting to open the input file.");
        exit(2);
    }

    char c;
    short row =1,column = 1;
    short num_X =0, num_O = 0;
    while ( !inputStream.eof()){
        while (inputStream.get(c) && isspace(c) && c != '\n')
            ;
        if (c == 'X' || c == 'x'){
            //std::cout<< "X at :: ("<<row<<" , "<< column<<")"<< std::endl;
            board[row][column] = 'X';
            column++;
            num_X++;
        }
        else if( c == 'O' || c == 'o'){
            //std::cout<< " O at :: ("<<row<<" , "<< column<<")"<< std::endl;
            board[row][column] = 'O';
            column++;
            num_O++;
        }
        else if (c == '\n'){
            column =1;
            row++;
        }
        else if (c =='-' || c =='_'){
            column++;
        }
        else{
            std::cout<<"Invalid character in input -->"<< c <<"<--"<<std::endl;
            exit(2);
        }

    }
    TicTacToe * game = new TicTacToe(board, num_X,num_O);

    return 0;
}
