#ifndef CHESSBOARD_H
#define CHESSBOARD_H

/* global constants for board */
const int NUMBER_RANK = 8;
const int NUMBER_FILE = 8;
const int NUMBER_DIMENSIONS = 2;
enum colour {WHITE, BLACK};

class Piece;

class ChessBoard {
 public:
  
  /* DECLARATION OF CONSTRUCTOR */
  //sets up initial pos for pieces. Note: empty squares are set to NULL
  ChessBoard();

  /* DECLARATION OF DESTRUCTOR */
  ~ChessBoard();
  
  /* DECLARATION OF "resetBoard" */
  //deletes all pieces on board and resets board to initial state
  void resetBoard();
  
  /* DECLARATION OF "submitMove" */
  //checks if valid move -> moves piece or returns checkmate/stalemate and destroys board
  void submitMove(const char* in_ch, const char* out_ch);

  /* DECLARATION OF "endGame" */
  //destroys board
  void endGame();
  
 protected:

  Piece * cb[NUMBER_RANK][NUMBER_FILE];
  int current_turn_colour;

  /*** FORMAT SPECIFIC CHECKS ***/
  /* DECLARATION OF "formatSpecificChecks" */
  //returns false if bad format of user input; true otherwise
  bool formatSpecificChecks(const char* in_ch, const char* out_ch);

  /*** BOARD SPECIFIC CHECKS ***/
  /* DECLARATION OF boardSpecificChecks */
  //returns false if wrong colour for source/empty source; true otherwise
  bool boardSpecificChecks(int pos_in[]);
  /* DECLARATION OF "colourCheck" */
  //checks if player is selecting own colour when submitting move
  bool colourCheck(int pos_in[]);

  /*** FUNCTIONS USED BY FRIEND CLASSES ***/
  
  /* DECLARATION OF "isEmptyCheck" */
  //checks square is non-empty
  bool isEmptyCheck(int pos_in[]);
  /* DECLARATION OF "sameColourCheck" */
  //checks input/output pos is not same colour
  bool sameColourCheck(int pos_in[], int pos_out[]);


  /*** CHECK SPECIFIC CHECKS ***/
  /* DECLARATION OF "checkCheck" */
  //checks if the king of that colour is in check
  bool checkCheck(int king_colour);
  /*DECLARATION OF "checkMate" */
  //checks if current color is in check mate
  bool checkMate(int cur_col);
  
  /*** STALE CHECKS ***/
  /* DECLARATION OF "staleCheck" */
  //checks whether current player is in stale mate
  bool staleCheck(int cur_col);

  /* DECLARATION OF "MovePiece" */
  //temporaly moves the pieces
  void movePiece(int pos_in[], int pos_out[]);

  /*** BOARD LOGISTIC FUNCTIONS ***/
  /* DECLARATION OF "removePieces" */
  //removes a piece from the board (considerig memory)
  void removePiece(int pos[]);
  /* DECLARATION OF "changeColour" */
  //changes colour of current turn for next turn
  void changeColour();
  /* DEFINITION OF "findCurrColKing" */
  //finds current position of the king for current colour
  void findKing(int pos_k[], int curr_colour);


  /* move needs to see entire board to check if a move causes check */
  friend class Move;

  /* pieces need to access functions and cb from Board class for jump and same colour checks */
  friend class Rook;
  friend class Bishop;
  friend class Queen;
  friend class King;
  friend class Knight;
  friend class Pawn;
};
  
#endif
