#include <iostream>
#include "ChessBoard.h"
#include "helper.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "move.h"

using namespace std;


/* DEFINITION OF CONSTRUCTOR */
ChessBoard::ChessBoard() {
  
  /* setting up the board */
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      cb[i][j] = nullptr;      
    }
  }

  /* setting up the colour */
  current_turn_colour = WHITE;
  
  /* setting up White */
  cb[0][7] = new Rook(WHITE, this);
  cb[1][7] = new Knight(WHITE, this);
  cb[2][7] = new Bishop(WHITE, this);
  cb[3][7] = new Queen(WHITE, this);
  cb[4][7] = new King(WHITE, this);
  cb[5][7] = new Bishop(WHITE, this);
  cb[6][7] = new Knight(WHITE, this);
  cb[7][7] = new Rook(WHITE, this);
  for (int i = 0; i < NUMBER_FILE; i++) {
    cb[i][6] = new Pawn(WHITE, this);
  }

  /* setting up Black */
  cb[0][0] = new Rook(BLACK, this);
  cb[1][0] = new Knight(BLACK, this);
  cb[2][0] = new Bishop(BLACK, this);
  cb[3][0] = new Queen(BLACK, this);
  cb[4][0] = new King(BLACK, this);
  cb[5][0] = new Bishop(BLACK, this);
  cb[6][0] = new Knight(BLACK, this);
  cb[7][0] = new Rook(BLACK, this);
  for (int i = 0; i < NUMBER_FILE; i++) {
    cb[i][1] = new Pawn(BLACK, this);
  }
}

/* DEFINITION OF DECONSTRUCTOR */
ChessBoard::~ChessBoard() {
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      if (cb[i][j]) {
	delete cb[i][j];
        cb[i][j] = nullptr;
      }
    }
  }
}

/* *** USER FUNCTIONS *** */

/* DEFINITION OF "endGame" */
void ChessBoard::endGame() {
  this->~ChessBoard();
  cout << "End of the game";
}

/* DEFINITION OF "resetBoard" */
void ChessBoard:: resetBoard() {

  /* setting up the board */
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      if (cb[i][j] != nullptr) {
	delete cb[i][j];
      }
      cb[i][j] = nullptr;      
    }
  }

  /* setting up White */
  cb[0][7] = new Rook(WHITE, this);
  cb[1][7] = new Knight(WHITE, this);
  cb[2][7] = new Bishop(WHITE, this);
  cb[3][7] = new Queen(WHITE, this);
  cb[4][7] = new King(WHITE, this);
  cb[5][7] = new Bishop(WHITE, this);
  cb[6][7] = new Knight(WHITE, this);
  cb[7][7] = new Rook(WHITE, this);
  for (int i = 0; i < NUMBER_FILE; i++) {
    cb[i][6] = new Pawn(WHITE, this);
  }

  /* setting up Black */
  cb[0][0] = new Rook(BLACK, this);
  cb[1][0] = new Knight(BLACK, this);
  cb[2][0] = new Bishop(BLACK, this);
  cb[3][0] = new Queen(BLACK, this);
  cb[4][0] = new King(BLACK, this);
  cb[5][0] = new Bishop(BLACK, this);
  cb[6][0] = new Knight(BLACK, this);
  cb[7][0] = new Rook(BLACK, this);
  for (int i = 0; i < NUMBER_FILE; i++) {
    cb[i][1] = new Pawn(BLACK, this);
  }

  /* setting up the colour */
  current_turn_colour = WHITE;

  /* introduction message */
  cout << "A new chess game is started!";
}

/* DEFINITION OF "submitMove" */
void ChessBoard::submitMove(const char* in_ch, const char* out_ch) {
  
  /* variables used to test move and cout */
  int pos_in[NUMBER_DIMENSIONS];
  int pos_out[NUMBER_DIMENSIONS];
  Piece* ptr_out;
  Piece* ptr_in;

  /* format specific checks */
  if (!formatSpecificChecks(in_ch, out_ch)) {
    return;
  }

  /* assignment of variables and instantiation of move */
  stringConverter(in_ch, pos_in);
  stringConverter(out_ch, pos_out);
  ptr_in = cb[pos_in[0]][pos_in[1]];
  ptr_out = cb[pos_out[0]][pos_out[1]];
  Move m(this);

  /* board specific checks */
  if (!boardSpecificChecks(pos_in)) {
    return;
  }
  
  /* piece specific check */
  if(!cb[pos_in[0]][pos_in[1]]->isValid(pos_in, pos_out)) {
    moveInvalidPrint(cb[pos_in[0]][pos_in[1]], pos_out);
    return;
  }
  
  /* move specific check */
  if (!m.move(pos_in, pos_out, current_turn_colour)) {
    moveInvalidPrint(cb[pos_in[0]][pos_in[1]], pos_out);
    return;
  }

  /* passes all tests -> move piece */
  if (cb[pos_out[0]][pos_out[1]] != nullptr) {
    removePiece(pos_out);
  }
  m.forwardMove(pos_in, pos_out);
  if (isEmptyCheck(pos_out)) {
    removePiece(pos_out);
  }
  moveValidPrint(ptr_in, ptr_out, pos_in, pos_out);


  /* changing the colour for the next turn */
  changeColour();

  /* Check specific checks */
  if (!checkCheck(current_turn_colour)) {
    if (current_turn_colour == WHITE) {
      cout << "White ";
    }
    else {
      cout << "Black ";
    }
    cout << "is in check";

    /* checking current player is not in checkmate */
    if (checkMate(current_turn_colour)) {
      cout << "mate\n";
      return;
    }
    else
      cout << "\n";
  }

  /* stale specific checks */
  if (staleCheck(current_turn_colour)) {
    if (current_turn_colour == WHITE) {
      cout << "White ";
    }
    else {
      cout << "Black ";
    }
    cout << "is in stalemate\n";
    return;
  }

}


/* *** FUNCTIONS THAT PIECES USE IN THEIR CLASS TOO *** */

/* DEFINITION OF "isEmptyCheck" */
bool ChessBoard::isEmptyCheck(int pos_in[]) {
  if (cb[pos_in[0]][pos_in[1]] == nullptr) {
    return true;
  }
  return false;
}

/* DEFINITION OF "sameColourCheck" */
bool ChessBoard::sameColourCheck(int pos_in[], int pos_out[]) {  
  if (!isEmptyCheck(pos_in) && !isEmptyCheck(pos_out)) {
    if (cb[pos_in[0]][pos_in[1]]->colour == cb[pos_out[0]][pos_out[1]]->colour) {
      return false;
    }
  }
  return true;
}


/* *** FORMAT SPECIFIC CHECKS FUNCTION *** */

/* DEFINTION OF "formatSpecificChecks" */
bool ChessBoard::formatSpecificChecks(const char* in_ch, const char* out_ch) {
  if(!stringFormatCheck(in_ch)) {
    return false;
  }
  if(!stringFormatCheck(out_ch)) {
    return false;
  }
  return true;
}


/* **** BOARD SPECIFIC CHECKS FUNCTIONS *** */

/* DEFINTION OF "boardSpecificChecks" */
bool ChessBoard::boardSpecificChecks(int pos_in[]) {
  /* checking non-empty in_pos */
  if(isEmptyCheck(pos_in)) {
    cout << "There is no piece at position ";
    cout << rankConverter(pos_in[0]) << fileConverter(pos_in[1]) << "!\n";
    return false;
  }
  /* checking right colour for pos_in */
  if (!colourCheck(pos_in)) {
    return false;
  }
  return true;
}

/* DEFINITION OF "colourCheck" */
bool ChessBoard::colourCheck(int pos_in[]) {
  
  if(cb[pos_in[0]][pos_in[1]]->colour!= current_turn_colour) {
    cout << "It's not ";
    if (current_turn_colour == BLACK) {
      cout << "White's ";
    }
    if (current_turn_colour == WHITE) {
      cout << "Black's ";
    }
    cout << "turn to play!\n";
    return false;
  }
  return true;
}


/* *** MOVE SPECIFIC CHECKS FUNCTIONS */


/* *** CHECK SPECIFIC FUNCTIONS *** */

/* DEFINITION OF "checkCheck" */
bool ChessBoard::checkCheck(int king_colour) {
  int pos_k[NUMBER_DIMENSIONS];
  findKing(pos_k, king_colour);
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      int temp[NUMBER_DIMENSIONS];
       if (cb[i][j] != nullptr
	   && cb[i][j]->colour == (king_colour + 1) % 2) {
	 temp[0] = i;
	 temp[1] = j;
	 if (cb[i][j]->isValid(temp, pos_k)) {
	   return false;
	 }
       }
    }
  }
  return true;
}

/* DEFINITION OF "checkMate" */
bool ChessBoard::checkMate(int cur_col) {
  int temp1[NUMBER_DIMENSIONS];
  int temp2[NUMBER_DIMENSIONS];
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      if (cb[i][j] != nullptr
	  && cb[i][j]->colour == cur_col) {
	temp1[0] = i;
	temp1[1] = j;
	for (int r = 0; r < NUMBER_RANK; r++) {
	  for (int f = 0; f < NUMBER_FILE; f++) {
	    temp2[0] = r;
	    temp2[1] = f;
	    Move m(this);
	    if (cb[i][j]->isValid(temp1, temp2)) {
	      if (m.move(temp1, temp2, cur_col)) {
		if (sameColourCheck(temp1, temp2)) {
		  return false;
		}
	      }
	    }
	  }
	}
      }
    }
  }
  return true;  
}

/* *** STALEMATE SPECIFIC FUNCTIONS *** */

/* DEFINITION OF "staleCheck" */
bool ChessBoard:: staleCheck(int cur_col) {
  int temp1[NUMBER_DIMENSIONS];
  int temp2[NUMBER_DIMENSIONS];
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      if (cb[i][j] != nullptr
	  && cb[i][j]->colour == cur_col) {
	temp1[0] = i;
	temp1[1] = j;
	for (int r = 0; r < NUMBER_RANK; r++) {
	  for (int f = 0; f < NUMBER_FILE; f++) {
	    temp2[0] = r;
	    temp2[1] = f;
	    if (cb[i][j]->isValid(temp1, temp2)) {
	      Move m(this);
	      if (m.move(temp1, temp2, cur_col)) {
		return false;
	      }
	    }
	  }
	}
      }
    }
  }
  return true;
}


/* FUNCTIONS FOR BOARD LOGISTICS */

/* DEFINITION OF "changeColour" */
void ChessBoard::changeColour() {
  if (current_turn_colour == WHITE) {
    current_turn_colour = BLACK;
  }
  else {
    current_turn_colour = WHITE;
  }
}

/* DEFINITION OF "findCurrColKing" */
void ChessBoard::findKing(int pos_k[], int king_colour) {
  for (int i = 0; i < NUMBER_RANK; i++) {
    for (int j = 0; j < NUMBER_FILE; j++) {
      if (cb[i][j] != nullptr
	  && cb[i][j]->colour == king_colour
	  && cb[i][j]->name == "King") {
	pos_k[0] = i;
	pos_k[1] = j;
      }
    }
  }
}

/* DEFINITION OF "removePiece" */
void ChessBoard:: removePiece(int pos[]) {
  delete cb[pos[0]][pos[1]];
  cb[pos[0]][pos[1]] = nullptr;
}
