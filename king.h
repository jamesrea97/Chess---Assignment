#ifndef KING_H
#define KING_H
#include "piece.h"

class Piece;
class King : public Piece {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the king with colour, name and pointer to board
  inline King (int colour_r, ChessBoard* p_b) : Piece(colour_r, "King"), ptr_board(p_b){};

  /* DECLARATION OF DESTRUCTOR */
  virtual ~King() override {};


 protected:
  /* DECLARATION OF virtual "isValid" */
  //checks if permissible (both move and jumping conditions)
  virtual bool isValid(int pos_in[], int pos_out[]) override;
  
 private:
  int abs_x;
  int abs_y;
  ChessBoard* ptr_board;
  
  /* DECLARATION OF "checkMove" */
  //checks whehter the move obeys piece move restrictions
  bool checkMove();
  
};

#endif
