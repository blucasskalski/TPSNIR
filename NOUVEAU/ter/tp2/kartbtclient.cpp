#include "kartbtclient.h"



//version cliente classique
KartBtClient::KartBtClient(const QString& configFile ,QObject* parent )
    : QObject(parent)
{

    // cartographie Modbus
    //TO DO
    //m_map    = new QamModbusMap(   ) ;
    
    m_map->setVerbose( true ) ;
    connect( m_map, SIGNAL(info(QString,QString)), this, SLOT(info(QString,QString)) ) ;


    bool retour = m_map->loadMap( configFile );
    m_table = QamModbusMap::HoldingRegister ;
    
    // client TCP COMPLETER la creation du client
    //m_client = new QamTcpClient(  ) ;

    //Demande de connexion du client en TCP sur la machine hôte serveur et le port 502 (a priori...)
    //A completer pour creation socket
    //m_client->sockConnect(  ) ;
    
    //A completer pour l'affichage de l'hote , du port et de l'etat de la connexion
    cout<< "host distant :"   << "port " <<   endl;

    cout<< "etat connexion" ;
    // intercepteur de commandes clavier (Ne rien modifier ici !)

     m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this ) ;
     connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readConsole()) ) ;

   int thing = 0;

    while(retour == false)
    {
        qSleep(1000);
        if(thing >= 5) {
        cerr << "pb fichier csv non trouve" << endl;
        exit(-1) ;
        }
        thing++;

    }
}

/* Menu clavier a completer */
void KartBtClient::readConsole()
{

    QTextStream in(stdin) ;

    QString line = in.readLine() ;   
    QStringList parse = line.split( QRegExp("\\s+") ) ;

    // COMPLETER la creation du menu => appels des methodes privées a coder dans ce fichier
    //
    //MENU : saisie des choix et appels des methodes adaptées
    //
    
    if ( parse.at(0) == "q" ) {
        emit quit() ;
    }


}


void KartBtClient::info(const QString& src, const QString& msg )
{
    cout << qPrintable( src ) << ": " << qPrintable( msg ) << endl ;
}
#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void KartBtClient::qSleep(int ms)
{
    //QTEST_ASSERT(ms > 0);

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, nullptr);
#endif
}

// DONNEES MESUREES LECTURE SEULE

//TODO ELEVE
float KartBtClient::getCoupleSimu()
{
}
//TODO ELEVE
//vitesse simulateur (moteur  : tr/mn)
float KartBtClient::getVitSimu()
{
}
//Lecture Tension X4   //TODO ELEVE
float KartBtClient::gettens1()
{
}
float KartBtClient::gettens2()
{
  
}
float KartBtClient::gettens3()
{
  
}
float KartBtClient::gettens4()
{
    
}

//TODO ELEVE
//Lecture Courant X4
float KartBtClient::getcour1()
{
}
float KartBtClient::getcour2()
{
}
float KartBtClient::getcour3()
{
}
float KartBtClient::getcour4()
{
}
//Lecture Courant Decharge*/

/** fn  float  KartBtClient::getCourantBatt()
 * brief mesure courant de decharge batterie 1,2,3,4 : batteries en serie !

*/
//TODO ELEVE
float  KartBtClient::getCourantBatt()
{
}
//DONNEES en lecture / Eciture

//lit le mode local 0 ; distant : 1
int KartBtClient::getLocal_Distant()
{
    
}

//ecrit le mode local 0 ; distant : 1
void KartBtClient::setLocal_Distant(QString LocalDist)
{
    
}

///MASSE PILOTE
//TODO ELEVE
void KartBtClient::setMasse_Pilote(QString weight)
{

}
//TODO ELEVE
float  KartBtClient::getMasse_Pilote()
{

}

///CONSIGNE PENTE
//TODO ELEVE
//ecrit
void KartBtClient::setConsignePente(QString pente)
{

}
//lit
float KartBtClient::getConsignePente()
{
    
}

///CONTROLE MOTEUR
//TODO ELEVE
            //ENABLE
            //ecrit
void KartBtClient::setConsigneEnable(QString valide)
{
   
}
            //lit
int KartBtClient::getConsigneEnable()
{

}

//TODO ELEVE
            //RUN
            //ecrit
void KartBtClient::setConsigneRun(QString valide)
{
   
}
            //lit
int KartBtClient::getConsigneRun()
{
   
}

