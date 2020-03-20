OBJ = ChessMain.o ChessBoard.o piece.o rook.o knight.o bishop.o queen.o king.o pawn.o helper.o move.o
EXE = chess
CXX = g++
CXXFLAGS = -Wall -g -Wextra

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm -f $(OBJ) $(EXE)
