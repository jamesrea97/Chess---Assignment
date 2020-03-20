#include "pawn.h"
#include "ChessBoard.h"

using namespace std;

bool Pawn::isValid(int pos_in[], int pos_out[]) {

  /* calculating displacement of pawn */
  diff_x = pos_out[0] - pos_in[0];
  diff_y = pos_out[1] - pos_in[1];
  
  /* initial checks */
  if (!checkMove()) {
    return false;
  }

  /* checking take a piece from own team */
  if (!ptr_board->sameColourCheck(pos_in, pos_out)) {
    return false;
  }

  /* white case */
  if (colour == WHITE) {
    if (!checkWhite(pos_in, pos_out)) {
      return false;
    }
  }
    
  /* black case */
  if (colour == BLACK) {
    if (!checkBlack(pos_in, pos_out)) {
      return false;
    }
  }

  return true;
}
/* DEFINITION OF "checkMove */
bool Pawn::checkMove() {
  
  /* checking actually makes a move */
  if (abs(diff_x) == 0 && abs(diff_y) == 0) {
    return false;
  }
  /* checking legality of move */ 
  if (abs(diff_x) > 1) {
    return false; //moves more than 1 horizontal
  }
  if(abs(diff_y) > 2 || abs(diff_y) < 1) {
    return false; //more than 2 vertical or less than 1 is impossible
  }

  return true;
}

/* DEFINITION OF "isJumpBlack" */
bool Pawn::isJumpBlack (int pos_in[]) {
  int temp[NUMBER_DIMENSIONS];
  temp[0] = pos_in[0];
  temp[1] = pos_in[1] + 1;

  /* checking black jump */
  if(!ptr_board->isEmptyCheck(temp)){
    return false;
  }
  
 return true;
}

/* DEFINITION OF "isJumpWhite" */
bool Pawn::isJumpWhite (int pos_in[]) {
  int temp[NUMBER_DIMENSIONS];
  temp[0] = pos_in[0];
  temp[1] = pos_in[1] - 1;

  /* checking white jump */
  if(!ptr_board->isEmptyCheck(temp)){
    return false;
  }
  
    return true;
}
/* DEFINITION OF "checkWhite" */
bool Pawn::checkWhite(int pos_in[], int pos_out[]) {

  /* general white */
  if (diff_y > -1) {
    return false;  //needs to go upwards
  }

  /*piece in front of pawn */
  if (abs(diff_x) == 0) {
    if(!ptr_board->isEmptyCheck(pos_out)) {
      return false;
    }
  }
  /* not at base */
  if (pos_in[1] != 6) {
    if (diff_y != - 1) {
      return false; 
    }
  }
  
  /* taking piece case */
  if (abs(diff_x) == 1) {
    /* at base */
    if (diff_y == -2) {
      return false; 
    }
    /* must be non_empty */
    if (ptr_board->isEmptyCheck(pos_out)) {
       return false; 
     }
  }

  /* moving two and piece in front */
  if (pos_in[1] == 6) {
    if (diff_y == -2) {
      if (!isJumpWhite(pos_in)) {
	return false;
      }
    }
  }
  return true;
}  

/* DEFINITION OF "checkBlack" */
bool Pawn:: checkBlack (int pos_in[], int pos_out[]) {
  /* general black */
  if (diff_y < 1) {
    return false;  //needs to go upwards
  }

  /*piece in front of pawn */
  if (abs(diff_x) == 0) {
    if(!ptr_board->isEmptyCheck(pos_out)) {
      return false;
    }
  }
  /* not at base */
  if (pos_in[1] != 1) {
    if (diff_y != 1) {
      return false; 
    }
  }
  
  /* taking piece case */
  if (abs(diff_x) == 1) {
    /* at base */
    if (diff_y == 2) {
      return false; 
    }
    /* must be non_empty */
    if (ptr_board->isEmptyCheck(pos_out)) {
       return false; 
     }
  }

  /* moving two and piece in front */
  if (pos_in[1] == 1) {
    if (diff_y == 2) {
      if (!isJumpBlack(pos_in)) {
	return false;
      }
    }
  }
  return true;
}
