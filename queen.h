#ifndef QUEEN_H
#define QUEEN_H
#include "rook.h"
#include "bishop.h"

class Rook;
class Bishop;

class Queen : virtual public Rook, virtual public Bishop {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the queen with colour, name and pointer to board
  inline Queen (int colour_r, ChessBoard* p_b) : Piece(colour_r, "Queen"),
    Rook(colour_r, p_b), Bishop(colour_r, p_b) {};
  
  /* DECLARATION OF DESTRUCTOR */
  virtual ~Queen() override {};

 protected:
  ChessBoard* ptr_board;

  /* DECLARATION OF virtual "isValid" */
  //checks if permissible (both move and jumping conditions
  virtual bool isValid(int pos_in[], int pos_out[]) override;		  
  
};

#endif
