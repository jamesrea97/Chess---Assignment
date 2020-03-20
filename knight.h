#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Piece;
class Knight : public Piece {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the knight with colour, name and pointer to board
  inline Knight (int colour_r, ChessBoard* p_b) : Piece(colour_r, "Knight"), ptr_board(p_b){};

  /* DECLARATION OF DESTRUCTOR */
  virtual ~Knight() override {};

 protected:
  /* DECLARATION OF virtual "isValid" */
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
