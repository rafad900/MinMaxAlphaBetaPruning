#ifndef TICTACTOE
#define TICTACTOE
#include <vector> 

class TicTacToe{
public:
    TicTacToe(std::vector< std::vector<char> > board, short X , short O);
    int Eval (std::vector< std::vector<char> > board);
    /*double minMax(std::vector< std::vector<char> > board);*/

    bool max_node(std::vector< std::vector<char> > board);
    bool leaf(std::vector< std::vector<char> > current_board);
    std::vector< std::vector< std::vector<char> > > successor(std::vector< std::vector<char> > board, bool X_turn);
	int minMaxAB(std::vector< std::vector<char> > board, int depth, int A, int B );
	int max(int y, int z);
	int min(int y, int z);
	void reset();

private:
	int positions [24][4][2];
    std::vector< std::vector<char> > _board;
    short _numOfX;
    short _numOfO;
};

#endif
