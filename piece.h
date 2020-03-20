#ifndef PIECE_H
#define PIECE_H
#include <string>

class ChessBoard;
class Piece {
 public:
    
 /* DECLARATION OF CONSTRUCTOR */
 //constructs the piece
 inline Piece(int colour_p, std::string n) : colour(colour_p), name(n){ };

  /* DECLARATION OF DESTRUCTOR */
  virtual ~Piece(){}

  /* need to be public for the helper function to access */
  int colour;
  std::string name;

 protected:

  
  /* DECLARATION OF "isValid" */
  //purely virtual function
  virtual bool isValid(int pos_in[], int pos_out[]) = 0;

  /* class Board needs access to isValid and colour/name for printing out */
  friend class ChessBoard;



};

#endif
