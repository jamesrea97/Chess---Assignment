#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Piece;
class Bishop : virtual public Piece {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the bishop with colour, name and pointer to board
  inline Bishop (int colour_r, ChessBoard* p_b) : Piece(colour_r, "Bishop"), ptr_board(p_b){};

   /* DECLARATION OF DESTRUCTOR */
  virtual ~Bishop() override {};


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
