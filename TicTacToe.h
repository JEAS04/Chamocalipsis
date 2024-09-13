#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void playGame();

private:
    char board[3][3];
    void playerMove(char symbol);
    void displayBoard();
    bool checkWin(char symbol);
    bool checkDraw();
};

#endif // TICTACTOE_H