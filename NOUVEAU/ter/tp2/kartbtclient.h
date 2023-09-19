#ifndef KARTBTCLIENT_H
#define KARTBTCLIENT_H

#include <QObject>
#include <qamtcpclient.h>
#include <qammodbusmap.h>


#include <QSocketNotifier>
#include <QTimer>
#include <iostream>
using namespace std ;


class KartBtClient:public QObject
{

    Q_OBJECT
    public :
      //init classe metier avec nom de fichier csv en arg

    explicit  KartBtClient(const QString& configFile, QObject *parent = nullptr);

    //accesseurs

       float get_cons_pente( ) { return cons_pente ; }
       float get_masse_pilote() { return masse_pilote; }

       //recupere tension batterie numero 1,4
       float get_tension(int n){ return tension[n];}

       //recupere courant charge batterie numero 1,4
       float get_courant(int n){ return courant[n];}

       //recupere le mode courant
       int get_mode() { return mode_local_distant; }

       //recupere la vitesse arbre roue tr/mn
       float get_vitesse_simu() { return vitesse_simu; }
       //mets consigne de pente
       void set_cons_pente(float pente) { cons_pente = pente; }

       //mets une masse
       void set_masse_pilote(float m) { masse_pilote = m ; }

       //mets un mode
       void set_mode(int mode) { mode_local_distant = mode ;}

       //Enable
       void setEnable(int en) { enable = en;}
       int getEnable(){ return enable;}

       //Run
       void setRun(int en) { enable = en;}
       int getRun(){ return enable;}

   public  slots:
    void info(const QString& src, const QString& msg ) ;
    void readConsole();


   signals:
     void quit() ;   // signal à émettre pour terminer l'application...

   private:
       void qSleep(int ms);
       QamModbusMap*				m_map ;
       QamModbusMap::PrimaryTable	m_table ;

       QamTcpClient*		m_client ;
       QSocketNotifier*    m_notifier ;

       //données du kart
       float  couple_simu, cons_pente, vitesse_simu, masse_pilote;
       float  tension[4], courant[4], courant_total_decharge;

       int mode_local_distant;// 0 : Local ; 1 : Distant
       int enable; //Enable : 0 non valide; 1 valide
       int run; //Run : 0 non valide; 1 valide
       /*******************************************
        * moteur OPERATIONNEL SSI E = 1 et Run = 1
        * *****************************************/

       //réception données de MESURES   Read ONLY

       float getVitSimu();    //tr/mn-1

       float getCoupleSimu();

       float getCourantBatt(); // courant de decharge totale (batteries en series ! donc peu importe le numero de batterie
                                        //utile pour simulateur

       /* lecture des tensions des 4 batteries */
       float gettens1();
       float gettens2();
       float gettens3();
       float gettens4();

       /* lecture des 4 courants de charge des 4 batteries */
       float getcour1();
       float getcour2();
       float getcour3();
       float getcour4();

       //envoi / lecture donnees de CONSIGNE   R/W
       void setMasse_Pilote(QString weight);
       float getMasse_Pilote();

       void setConsignePente(QString pente);
       float getConsignePente();

       void setLocal_Distant(QString local_dist);
       int getLocal_Distant();

       // envoi / lecture Consigne commande broche Enable
       void setConsigneEnable(QString valide);
       int getConsigneEnable();


       // envoi / lecture Consigne commande broche Run
       void setConsigneRun(QString valide);
       int getConsigneRun();
};
#endif // KARTBTCLIENT_H
