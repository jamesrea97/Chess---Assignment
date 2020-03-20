#include <iostream>
#include <string.h>
#include "helper.h"
#include "ChessBoard.h"
#include "piece.h"

using namespace std;

/* INITIAL TESTS HELPER FUNCTIONS */

/* DEFINITION OF "stringFormatCheck" */
bool stringFormatCheck(const char* input) {
  if (strlen(input) > 2) {
    cout << "Incorrect format.\n";
    return false;
  }

  if (input[0] < 65 || input[0] > 72) {
    cout << "File must be between A and H.\n";
    return false;
  }
  if (input[1] < 49 || input[1] > 56) {
    cout << "Rank must be between 1 and 8.\n";
    return false;
  }
  return true;
}
/* DEFINITION OF "stringConverter" */
void stringConverter(const char* input, int pos[]) {
  pos[0] = static_cast<int>(input[0]) - 65;
  pos[1] = 7 - (static_cast<int>(input[1]) - 49);
}

/* OUTPUT HELPER FUNCTIONS */

/* DEFINITION OF "rankConverter" */
char rankConverter(int r) {
  char out = r + 65;
  return out;
}
/* DEFINITION OF "fileConverter" */
char fileConverter(int r) {
  char out = (8 - r) + 48;
  return out; 
}
/* DEFINITION OF "moveInvalidPrint" */
void moveInvalidPrint(Piece* ptr_in, int pos_out[]) {
  if (ptr_in->colour == WHITE) {
    cout << "White";
  }
  if (ptr_in->colour == BLACK) {
    cout << "Black";
  }
  cout << "'s " << ptr_in->name << " cannot move to ";
  cout << rankConverter(pos_out[0]) << fileConverter(pos_out[1]) << "!\n"; 
}
/* DEFINITION OF "moveValidPrint" */
void moveValidPrint(Piece* ptr_in, Piece* ptr_out, int pos_in[], int pos_out[]) {
  if (ptr_in->colour == WHITE) {
    cout << "White ";
  }
  if (ptr_in->colour == BLACK) {
    cout << "Black ";
  }
  cout << ptr_in->name;
  cout << " moves from ";
  cout << rankConverter(pos_in[0]) << fileConverter(pos_in[1]) << " to ";
  cout << rankConverter(pos_out[0]) << fileConverter(pos_out[1]);
  if (ptr_out != nullptr) {
    cout << " taking ";
    if (ptr_out->colour == WHITE) {
      cout << "White";
    }
    if (ptr_out->colour == BLACK) {
      cout << "Black";
    }
    cout << "'s " << ptr_out->name;
    
  }
  
  cout <<"\n";
}

/* CALCULATION HELPER FUNCTIONS */

/* DEFINITION OF "unitDirectionCalc" */
int unitDirectionCalc(int in, int out) {
  if ((out - in) == 0) {
    return 0;
  }
  return (out - in) / abs(out - in);
}

