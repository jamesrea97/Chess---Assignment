#include "move.h"
#include "ChessBoard.h"

using namespace std;


/* DEFINITION OF "move" */
bool Move::move(int pos_in[], int pos_out[], int king_colour) {

  /* setting up the pointers fr backward move */
  ptr_in = ptr_board->cb[pos_in[0]][pos_in[1]];
  ptr_out = ptr_board->cb[pos_out[0]][pos_out[1]];
  
  /* moving forward */
  forwardMove(pos_in, pos_out);

  /* checking this does not cause current colour to be in check */
  if (!ptr_board->checkCheck(king_colour)) {
    /* move back as illegal */
    backwardMove(pos_in, pos_out);
    return false;
  }
  
  backwardMove(pos_in, pos_out);
  return true;
}
/* DEFINITION OF "forwardMove" */
void Move::forwardMove(int pos_in[], int pos_out[]) {
  /* move forward*/
  ptr_board->cb[pos_out[0]][pos_out[1]] = ptr_board->cb[pos_in[0]][pos_in[1]];
  ptr_board->cb[pos_in[0]][pos_in[1]] = nullptr;
}

/* DEFINITION OF "backwardMove" */
void Move::backwardMove(int pos_in[], int pos_out[]) {
    /* move forward*/
  ptr_board->cb[pos_out[0]][pos_out[1]] = ptr_out;
  ptr_board->cb[pos_in[0]][pos_in[1]] = ptr_in;
}
