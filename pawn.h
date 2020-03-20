#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "string"

class Piece;
class Pawn : public Piece {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the pawn with colour, name and pointer to board
  inline Pawn (const char colour_r, ChessBoard* p_b) : Piece(colour_r, "Pawn"), ptr_board(p_b) {};

  /* DECLARATION OF DESTRUCTOR */
  virtual ~Pawn() override {};

 protected:
  /* DECLARATION OF virtual "isValid" */
  //checks if permissible (both move and jumping conditions
  virtual bool isValid(int pos_in[], int pos_out[]) override;


 private:
  int unit_pos[2];
  int diff_x;
  int diff_y;
  ChessBoard* ptr_board;

  /* DECLARATION OF "checkMove" */
  //checks whehter the move obeys basic pawn moves
  bool checkMove();
    
  /* DECLARATION OF "checkWhite" */
  //checks all special cases for white pawn
  bool checkWhite(int pos_in[], int pos_out[]);

 /* DECLARATION OF "checkBlack" */
  //checks all special cases for black pawn
  bool checkBlack(int pos_in[], int pos_out[]);

  /* DECLARATION OF "isJumpWhite" */
  //checks if pawn makes a jump when at the base of black
  bool isJumpWhite(int pos_in[]);

  /* DECLARATION OF "isJumpBlack" */
  //checks if pawn makes a jump when at the base of black
    bool isJumpBlack (int pos_in[]);
};

#endif

