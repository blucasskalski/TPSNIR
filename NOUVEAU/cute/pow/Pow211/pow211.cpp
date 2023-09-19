#include "pow211.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <QTime>
#include <random>
#include <QRandomGenerator>
using namespace std;

Pow211::Pow211(QObject *parent)
    : QObject{parent}
{
    memset(m_board, 0, BOARDSIZE * BOARDSIZE * sizeof(quint16));
    m_higherTile = 0;
    m_score = 0;
    setBoard();
    addRandomTile() ;
    addRandomTile() ;
   // for ( int i = 0 ; i < BOARDSIZE ; ++i ) slideLine(i) ;
}

void Pow211::print() const
{
    cout << endl ;
    for ( int y = 0 ; y < BOARDSIZE ; ++y ) {
        for ( int x = 0 ; x < BOARDSIZE ; ++x ) {
            cout << setw(5) << m_board[x][y] ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void Pow211::setBoard()
{
    quint16 board[] = {
        0, 2, 4, 8,
        16, 32, 64, 128,
        256, 512, 1024, 2048,
        0, 0, 0, 0
    } ;
    for ( int i = 0 ; i < BOARDSIZE * BOARDSIZE ; ++i ) {
        m_board[ i % BOARDSIZE ][ i / BOARDSIZE ] = 0 ;//board[i] ;
    }
}

bool Pow211::slideTile(int line, int x )
{
    if ( m_board[x+1][line] == 0 ) {
        m_board[x+1][line] = m_board[x][line] ;
        m_board[x][line] = 0 ;
        return ( m_board[x+1][line] != 0 ) ;
    }
    return false ;
}

bool Pow211::slideLine(int line )
{
    bool modified = false ;
    for ( int x = BOARDSIZE - 2 ; x >= 0 ; x-- ) {
        for ( int xr = x ; xr < BOARDSIZE - 1 ; xr++ )
            modified |= slideTile(line, xr ) ;
    }
    int x = BOARDSIZE - 2 ;
    while ( x >= 0 ) {
        if ( ( m_board[x][line] )
             &&( m_board[x][line] == m_board[x+1][line] ) ) {
            m_board[x][line] = 0 ;
            m_board[x+1][line] *= 2 ;
            m_score += m_board[x+1][line];
            if(m_higherTile>m_board[x+1][line] ) m_higherTile = m_board[x+1][line];
            x-- ;
            modified = true ;
        }
        x-- ;
    }
    for ( int x = BOARDSIZE - 2 ; x >= 0 ; x-- ) {
        for ( int xr = x ; xr < BOARDSIZE - 1 ; xr++ )
            slideTile(line, xr ) ;
    }
    return modified ;
}

void Pow211::rotate()
{
    int n = BOARDSIZE ;
    for ( int x = 0 ; x < n / 2 ; ++x ) {
        for ( int y = x ; y < n - x - 1 ; ++y ) {
            quint16 tmp = m_board[x][y] ;
            m_board[x][y] = m_board[y][n-x-1] ;
            m_board[y][n-x-1] = m_board[y][n-x-1] ;
            m_board[n-x-1][n-y-1]=m_board[n-y-1][x];
            m_board[n-y-1][x] = tmp ;
        }
    }
}

bool Pow211::slideUp()
{
    bool modified = false ;
    rotate() ;
    for ( int i = 0 ; i < BOARDSIZE ; ++i ) modified |= slideLine(i) ;
    rotate() ;
    rotate() ;
    rotate() ;
    return modified ;
}


bool Pow211::slideDown(){
    bool modified = false ;
    rotate() ;
    for ( int i = 0 ; i < BOARDSIZE ; ++i ) modified |= slideLine(i) ;
    rotate() ;
    rotate() ;
    rotate() ;
    return modified ;
}

bool Pow211::slideLeft() {
    bool modified = false ;
    rotate() ;
    for ( int i = 0 ; i < BOARDSIZE ; ++i ) modified |= slideLine(i) ;
    rotate() ;
    rotate() ;
    rotate() ;
    return modified ;
}

bool Pow211::slideRight() {
    bool modified = false ;
    rotate() ;
    for ( int i = 0 ; i < BOARDSIZE ; ++i ) modified |= slideLine(i) ;
    rotate() ;
    rotate() ;
    rotate() ;
    return modified ;
}

int Pow211::findFreeCells()
{
    m_freeCount = 0 ;
    for ( int i = 0 ; i < BOARDSIZE * BOARDSIZE ; ++i ) {
        m_freeIndex[i] = 0 ;
        if ( m_board[ i % BOARDSIZE ][ i / BOARDSIZE ] == 0 ) {
            m_freeIndex[i] =i;
            m_freeCount ++;

        }
    }
    return m_freeCount;
}

void Pow211::addRandomTile()
{
    if ( !findFreeCells() ) return ;
    quint32 value = QRandomGenerator::global()->generate() ;
    int index = m_freeIndex[ value % m_freeCount ] ;
    value = QRandomGenerator::global()->generate() ;
    m_board[ index % BOARDSIZE ][ index / BOARDSIZE ] = ( (value % 10 ) / 8 + 1 ) * 2 ;
}

int Pow211::findPairInLine(int line )
{
    int num = 0 ;
    for ( int x = 0 ; x < BOARDSIZE - 1 ; ++x ) {
        if ( m_board[x][line] == m_board[x + 1][line] ) num++ ;
    }
    return num ;
}

int Pow211::findPair()
{
        int num = 0 ;
        for ( int i = 0 ; i < BOARDSIZE ; i++ ) num += findPairInLine(i) ;
        for(int i= 0; i <BOARDSIZE; i++){
            for(int j=0; j < BOARDSIZE; j++){

                if(m_board[i][j] == m_board[i][j + 1]) num++;
            }

        }

        return num ;
}


bool Pow211::win()
{
    if(m_higherTile == 2048) return 1;
    else return 0;
}

bool Pow211::gameOver()
{
    if(!findPair()) return 1;
    else return 0;

}

quint16 Pow211::tile(int index) const{

    return m_board[index % BOARDSIZE][index / BOARDSIZE];
}

quint32 Pow211::score() const{

}
