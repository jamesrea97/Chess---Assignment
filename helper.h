#ifndef HELPER_H
#define HELPER_H

class ChessBoard;
class Piece;

/* HELPERS FOR FORMAT CHECKS */

/* DECLARATION OF "stringFormatCheck" - used in Board::isValid */
//checks correct format string and in range
bool stringFormatCheck(const char* input);

/* DECLARATION OF "stringConveter" */
//converts the rightly formated string to 2D array format
void stringConverter(const char* input, int pos[]);


/* HELPERS FOR PRINT OUT CHECKS */

/* DECLARATION OF "rankConverter" */
//converts the rank from int to char
char rankConverter(int r);

/* DECLARATION OF "fileConverter" */
//converts file from int to char
char fileConverter(int r);

/* DECLARATION OF "moveInvalidPrint" */
//prints out when cannot make move
void moveInvalidPrint(Piece* ptr_in, int pos_out[]);

/* DECLARATION OF "moveValidPrint" */
//prints out when move is made
void moveValidPrint(Piece* ptr_in, Piece* ptr_out, int pos_in[], int pos_out[]);


/* HELPERS FOR UNIT DIRECTIONAL VECTOR */

/* DECLARATION OF "unitVector" */
//calculates unit directions for rook and bishop
int unitDirectionCalc(int in, int out);


#endif
