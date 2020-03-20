#include "queen.h"
#include "rook.h"
#include "bishop.h"

using namespace std;

/* DEFINITION OF "isValid" */
bool Queen::isValid(int pos_in[], int pos_out[]) {
  if (Rook::isValid(pos_in, pos_out) || Bishop::isValid(pos_in, pos_out)) {
    return true;
  }
  return false;
}
