#ifndef POW211_H
#define POW211_H
#define BOARDSIZE 4
#define MAXVALUEOFTILE 2048
#include <QObject>

class Pow211 : public QObject
{
    Q_OBJECT
public:
    explicit Pow211(QObject *parent = nullptr);
    Q_INVOKABLE quint16 tile(int index ) const ;  // lecture valeur de la tuile d’indice index
    quint32 score() const ; // lecture du score courant
    void print() const;
    bool win();
    void addRandomTile();

    bool gameOver();


private:

    quint16 m_board[BOARDSIZE][BOARDSIZE];
    quint32 m_score;
    int m_higherTile;
    int m_freeCount ;
    int m_freeIndex[ BOARDSIZE * BOARDSIZE ];

private:

    void setBoard();
    bool slideTile(int line, int x);
    bool slideLine(int line );
    void rotate();
    bool slideUp();
    bool slideDown();
    bool slideLeft();
    bool slideRight();
    int findFreeCells();
    int findPairInLine(int line );
    int findPair();

    signals:

};

#endif // POW211_H
