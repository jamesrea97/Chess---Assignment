#include "rook.h"
#include "ChessBoard.h"
#include "helper.h"

using namespace std;

/* DEFINITION OF "isValid" */
bool Rook::isValid(int pos_in[], int pos_out[]) {

  /* calculating displacement of rook */
  abs_x = abs(pos_out[0] - pos_in[0]);
  abs_y = abs(pos_out[1] - pos_in[1]);
  unit_pos[0] = unitDirectionCalc(pos_in[0], pos_out[0]);
  unit_pos[1] = unitDirectionCalc(pos_in[1], pos_out[1]);

  /* checking move */
  if (!checkMove()) {
    return false;
  }

  /* checking take a piece from own team */
  if (!ptr_board->sameColourCheck(pos_in, pos_out)) {
    return false;
  }

  /* checking jump */
  if (!checkJump(pos_in)) {
    return false;
  }

  return true;
}

/* DEFINITION OF "checkMove" */
bool Rook::checkMove() {
  
  /* check actually makes a move */
  if (abs_x == 0 && abs_y == 0) {
    return false;
  }
  /* check legality of move */
  if (abs_x != 0 && abs_y != 0) {
    return false;
  }
  
  return true;
}

/* DEFINITION OF "checkJump" */
bool Rook::checkJump (int pos_in[]) { 

  /*case postion vector is horizontal */
  if (abs_x != 0) { 
    for (int i = 1; i < abs_x; i++) {
      int temp[2];
      temp[0] = pos_in[0] + unit_pos[0] * i;
      temp[1] = pos_in[1];
      if (!ptr_board->isEmptyCheck(temp)) {
  	return false;
      }
    }
  }

  /* case position vector is vertical */
  if (abs_y != 0) {
    for (int i = 1; i < abs_y; i++) {
      int temp[2];
      temp[0] = pos_in[0];
      temp[1] = pos_in[1] + unit_pos[1] * i;
      if (!ptr_board->isEmptyCheck(temp)) {
  	return false;
      }
    }
  }
  return true;
  
}

