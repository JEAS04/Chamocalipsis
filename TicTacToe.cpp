#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void TicTacToe::playGame() {
    std::cout << "Bienvenido al juego de Tic Tac Toe!" << std::endl;
    displayBoard(); // Mostrar el tablero vacío al principio
    char currentPlayer = 'X';
    while (true) {
        playerMove(currentPlayer);
        if (checkWin(currentPlayer)) {
            std::cout << "Jugador " << currentPlayer << " gana!" << std::endl;
            break;
        } else if (checkDraw()) {
            std::cout << "Empate!" << std::endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void TicTacToe::playerMove(char symbol) {
    int row, col;
    while (true) {
        std::cout << "Jugador " << symbol << ", ingrese la fila y columna en el siguiente formato (F C): ";
        std::cin >> row >> col;
        row--; col--; // Convertir a índices de array
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Error: ingrese un número entre 1 y 3." << std::endl;
        } else if (board[row][col] != '-') {
            std::cout << "Casilla ocupada, intente de nuevo." << std::endl;
        } else {
            board[row][col] = symbol;
            break;
        }
    }
    displayBoard();
}

void TicTacToe::displayBoard() {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::checkWin(char symbol) {
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }
    // Verificar diagonales
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }
    return false;
}

bool TicTacToe::checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}