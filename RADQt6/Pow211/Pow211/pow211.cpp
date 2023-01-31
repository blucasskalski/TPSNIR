#include "pow211.h"

Pow211::Pow211(QObject *parent) : QObject(parent) {
  m_score = 0;
  m_higherTile = 0;
  memset(m_board, 0, sizeof(m_board));
}
