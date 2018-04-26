#include "knightstour.h"
#include <iostream>

void test_next_move()
{
    int b1[8][8] =
        {
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, -1, 15, -1, 15, 15},
            {15, 15, 99, 15, 15, 15, -1, 15},
            {15, 15, 15, 15, -1, 15, 15, 15},
            {15, 15, -1, 15, 15, 15, -1, 15},
            {15, 15, 15, -1, 15, -1, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15}};

    std::cout << next_move(2, 2, b1).first << " should be 3  " << next_move(2, 2, b1).second << " should be 4" << std::endl;

    int b2[8][8] =
        {
            {15, 15, -1, 15, 15, 15, -1, 15},
            {-1, 15, 15, 15, -1, 15, 15, 15},
            {15, 15, 99, 15, 15, 15, 15, 15},
            {15, -1, 15, 15, -1, 15, 15, 15},
            {15, 15, -1, 15, 15, 15, -1, 15},
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15}};

    for (int i = 0; i < 100; ++i)
    {
        std::pair<int, int> temp = next_move(2, 2, b2);
        std::cout << temp.first << " should be 3  " << temp.second << " should be 4" << std::endl;
    }

    int b3[8][8] =
        {
            {15, 15, -1, 15, 15, 15, -1, 15},
            {-1, 15, 15, 15, -1, 15, 15, 15},
            {15, 15, 99, 15, 15, 15, 15, 15},
            {-1, -1, 15, 15, -1, 15, 15, 15},
            {15, 15, -1, 15, 15, 15, -1, 15},
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15},
            {15, 15, 15, 15, 15, 15, 15, 15}};

        std::pair<int, int> temp = next_move(2, 2, b3);
        std::cout << temp.first << " should be 0  " << temp.second << " should be 3" << std::endl;
}

int main()
{

    srand(time(NULL));
    test_next_move();
    //int board[NUM_ROWS][NUM_COLS];
    //initialize_board(board);
}