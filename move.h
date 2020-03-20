#ifndef MOVE_H
#define MOVE_H

class Piece;
class ChessBoard;

class Move {
 public:
  /* DECLARATION OF CONSTRUCTOR */
  //constructs the rook with colour, name and pointer to board
 Move(ChessBoard* p_b) : ptr_board(p_b){};

 protected:
  Piece* ptr_in;
  Piece* ptr_out;
  ChessBoard* ptr_board;

  /* DECLARATION OF "move" */
  //moves piece (and back if it is illegal
  //PRE: source and destination and current king colour
  //POST: returns true if the move can be done correctly; false otherwise
  bool move(int pos_in[], int pos_out[], int king_colour);

  /* DECLARATION OF "forwardMove" */
  //moves piece forward
  //PRE: source and destination
  //POST: moves piece
  void forwardMove(int pos_in[], int pos_out[]);

  
  /* DECLARATION OF "backwardMove" */
  //moves piece backwards (in case illegal)
  //PRE: pointers to initial pos_in/ initial pos_out pieces, and source and destination
  //POST: moves piece back to original state
  void backwardMove(int pos_in[], int pos_out[]);
  
  
  friend class ChessBoard;
  friend class King;
};

#endif
