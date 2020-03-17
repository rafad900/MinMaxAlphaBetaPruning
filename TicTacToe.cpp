#include "TicTacToe.hpp"

TicTacToe::TicTacToe(std::vector< std::vector<char> > board, short X, short O) {

	_board = board;
	_numOfX = X;
	_numOfO = O;
}

int TicTacToe::Eval(std::vector< std::vector<char> > board) {
	
	
	return 0;
}



bool TicTacToe::max_node(std::vector< std::vector<char> > current_board) {
	if (_numOfX > _numOfO) return false;
	else return true;
}

std::vector< std::vector< std::vector<char> > > TicTacToe::successor (std::vector< std::vector<char> > board, bool X_turn) {
	std::vector< std::vector< std::vector<char> > > children;
	for (int x = 0; x < board.size(); x++) {
		for (int y = 0; y < board[x].size(); y++) {
			if (board[x][y] == '\0') {
				std::vector< std::vector<char> > child = board;
				if (X_turn) child[x][y] = 'X';
				else		child[x][y] = 'O';
			}
		}
	}
	return children;
}

bool TicTacToe::leaf(std::vector< std::vector<char> > board) {
	for (int x = 0; x < board.size(); x++) 
		for (int y = 0; y < board[x].size(); y++) 
			if (board[x][y] == '\0') 
				return false;
	return true;
}
			

int TicTacToe::max(int y, int z) {
	if (y > z) return y;
	else return z;
}

int TicTacToe::min(int y, int z) {
	if (y < z) return y;
	else return z;
}

int TicTacToe::minMaxAB(std::vector< std::vector<char> > board, int depth, int A, int B) {
	if (depth == 0 || leaf(board)) return Eval(board);
	int res;
	if (max_node(board)) {
		res = A;
		std::vector< std::vector< std::vector<char> > > successors = successor(board, true);
		for (std::vector< std::vector<char> > c: successors) {
			int val = minMaxAB(c, depth-1, res, B);
			int maxVal = max(res, A);
			if (res >= B)
				return res;
		}
	} else {
		res = B;
		std::vector< std::vector< std::vector<char> > > successors = successor(board, true);
		for (std::vector< std::vector<char> > c: successors) {
			int val = minMaxAB(board, depth-1, A, res);
			int res = min(res, val);
			if (res >= A) 
				return res;
		}
	}
	return res;

}
