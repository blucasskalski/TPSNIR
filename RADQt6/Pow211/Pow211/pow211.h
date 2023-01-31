#ifndef POW211_H
#define POW211_H
const int BOARDSIZE = 4;
const int MAXVALUEOFTILE = 2048;

#include <QObject>

class Pow211 : public QObject {
  Q_OBJECT
public:
  explicit Pow211(QObject *parent = nullptr);
  quint16 tile(int index) const;
  quint32 score() const;

private:
  quint16 m_board[BOARDSIZE][BOARDSIZE];
  quint32 m_score;
  quint16 m_higherTile;
signals:
};

#endif // POW211_H
