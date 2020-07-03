#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

//char matrix[3][3] = { '1', '2', '3',
//                      '4', '5', '6',
//                      '7', '8', '9' };

void matrix_init ( char matrix[][3] ){
    int i, j;
    char c = '1';
    for ( int i = 0; i < 3; i++ ){
        for ( int j = 0; j < 3; j++ ){
            matrix[i][j] = c;
            c++;
        }
    }
}

bool symbol_insertion ( char matrix[][3], int i, int j, char c ) {
    if ( matrix[i][j] == 'X' || matrix[i][j] == '0' ){
        return false;

    }else{
        matrix[i][j] = c;
        return true;
    }
}


int main()
{

    return 0;
}


//X  0  X
//0  0  X
//X  X  0
//
//1  2  3
//4  5  6
//7  8  9

