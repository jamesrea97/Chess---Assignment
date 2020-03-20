#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Piece;
class Rook: virtual public Piece {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the rook with colour, name and pointer to board
 inline Rook(int colour_r, ChessBoard* p_b) : Piece(colour_r, "Rook"), ptr_board(p_b){};
 
  /* DECLARATION OF DESTRUCTOR */
  virtual ~Rook() override {};

 protected:
  /* DECLARATION OF virtual "isValid" */
  //checks if permissible (both move and jumping conditions)
  virtual bool isValid(int pos_in[], int pos_out[]) override;

 private:
  int abs_x;
  int abs_y;
  int unit_pos[2];
  ChessBoard* ptr_board;

  /* DECLARATION OF "checkMove" */
  //checks whehter the move obeys piece move restrictions
  virtual bool checkMove();
    
  /* DECLARATION OF "isJump" */
  //checks whether the move jumps over a piece on current boar
  bool checkJump(int pos_in[]) ;


};

#endif
