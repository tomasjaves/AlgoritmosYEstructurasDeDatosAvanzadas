#include "../include/CellACE110.h"

/**
 * @brief Constructor de la clase CellACE110.
 * 
 * @param pos 
 * @param state 
 */
CellACE110::CellACE110(const Position& pos, const State& state) : CellACE(pos, state) {}

/**
 * @brief Método que devuelve el estado siguiente de la célula.
 * 
 * @param lattice 
 * @return State 
 */
State CellACE110::nextState(const Lattice& lattice) {
  int result;
  // Obtenemos el estado de las células adyacentes y la propia.
  int cell_c_pos = lattice.getCell(this->getPos()).getState();
  int cell_r_pos = lattice.getCell(this->getPos() + 1).getState();
  int cell_l_pos = lattice.getCell(this->getPos() - 1).getState();
  // Calculamos el estado siguiente de la célula con la fórmula dada.
  result = (cell_c_pos + cell_r_pos + cell_c_pos * cell_r_pos + cell_l_pos * cell_c_pos * cell_r_pos) % 2;
  next_state_ = (State)result;
  return (State)result;
}