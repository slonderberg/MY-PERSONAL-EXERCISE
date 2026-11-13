#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

void space()
{
    cout << "\n\n\n";
}

void bordo()
{
    cout << "!==================================!" << endl;
}
void threePoints()
{
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
}

void errore()
{
    space();
    bordo();
    cout << "SCELTA NON SUPPORTATA!!! RIPROVA" << endl;
    bordo();
    space();
    sleep(1);
}
/* class Modifiche
{
    int quantitaTamburo;
}; */

void giocoProcesso()
{
    srand(time(NULL));
    // nome giocatore
    string giocatore1, giocatore2;
    //quantita dei carichi
    
    int quantitaTamburo = 8;
    // la camera del tamburo iniziale
    int cameraInizialePistola = rand() % quantitaTamburo + 1;
    // la camera con poittile
    int cameraPoittilePistola = rand() % quantitaTamburo + 1;
    // contatori
    int contatoreSecondaScelta1 = 0, contatoreTerzaScelta1 = 0, contatoreTerzaScelta2 = 0, contatoreSecondaScelta2 = 0;
    // le scelte

    // vittoria
    bool vittoriaGiocatore1 = false, vittoriaGiocatore2 = false;
    // perdita
    bool perditaGiocatore1 = false, perditaGiocatore2 = false;

    space();
    cout << "PREPARAZIONE AL GIOCO";
    threePoints();
    space();
    cout << "IMPOSTA I NOMI DEI GIOCATORI" << endl
         << "PRIMO GIOCATORE: ";
    cin >> giocatore1;
    cout << "SECONDO GIOCATORE: ";
    cin >> giocatore2;
    int i = 0;
    while (vittoriaGiocatore1 == false && vittoriaGiocatore2 == false)
    {
        i++;
        for (bool passoRound = false; passoRound == false;)
        {
            space();
            cout << "<================ROUND N." << i << "================>" << endl;
            
            space();
            sleep(1);

            // per passare al altro round
            int sceltaGiocatore;
            //dipendente dal i verra scelto giocatore
            if (i % 2 == 0)
            {
                cout << "GIOCATORE " << giocatore2 << " FA LA SCELTA" << endl;
                cout << "1. SPARARE IN SE " << endl;

                if (contatoreSecondaScelta2 == 0)
                {
                    cout << "2. SPARARE NEL TUO AVERSARIO" << endl;
                }
                if (contatoreTerzaScelta2 == 0)
                {

                    cout << "3. GIRARE IL TAMBURO" << endl;
                }
            }
            else
            {
                cout << "GIOCATORE " << giocatore1 << " FA LA SCELTA" << endl;
                cout << "1. SPARARE IN SE " << endl;

                if (contatoreSecondaScelta1 == 0)
                {
                    cout << "2. SPARARE NEL TUO AVERSARIO" << endl;
                }
                if (contatoreTerzaScelta1 == 0)
                {

                    cout << "3. GIRARE IL TAMBURO" << endl;
                }
            }

            cout << "SCELTA: ";
            cin >> sceltaGiocatore;
            switch (sceltaGiocatore)
            {
                //sparare in se
            case 1:
                if (i % 2 == 0)
                {
                    for (int j = 3; j > 0; j--)
                    {
                        cout << j << endl;
                        sleep(1);
                    }
                    // questo qua serve per far ripartire tambure se il valore è uguale a 8
                    if (cameraInizialePistola == quantitaTamburo)
                    {
                        //si cambia da 8 a 0 perche poi si aumentera per 1 e diventa 1 e fa una sorta del giro
                        cameraInizialePistola = 0;
                    }
                    // lo sparo
                    cameraInizialePistola++;

                    if (cameraInizialePistola == cameraPoittilePistola)
                    {
                        cout << "SPARO!!! SEI MORTO" << endl;
                        perditaGiocatore2 = true;
                    }
                    else
                    {
                        cout << "SALVATO" << endl;
                    }
                    passoRound = true;
                }
                else
                {
                    for (int j = 3; j > 0; j--)
                    {
                        cout << j << endl;
                        sleep(1);
                    }

                    if (cameraInizialePistola == quantitaTamburo)
                    {
                        cameraInizialePistola = 0;
                    }
                    cameraInizialePistola++;
                    if (cameraInizialePistola == cameraPoittilePistola)
                    {
                        cout << "SPARO!!! SEI MORTO" << endl;
                        perditaGiocatore1 = true;
                    }
                    else
                    {
                        cout << "SALVATO" << endl;
                    }
                    passoRound = true;
                }

                break;
                //sparare nel tuo aversario
            case 2:
                if (i % 2 == 0)
                {
                    if (contatoreSecondaScelta2 == 0)
                    {
                        for (int j = 3; j > 0; j--)
                        {
                            cout << j << endl;
                            sleep(1);
                        }
                        if (cameraInizialePistola == quantitaTamburo)
                        {
                            cameraInizialePistola = 0;
                        }
                        cameraInizialePistola++;
                        if (cameraInizialePistola == cameraPoittilePistola)
                        {
                            cout << "SPARO!!! IL TUO AVVERSARIO MORTO" << endl
                                 << "HAI VINTO" << giocatore2 << "!!!" << endl;
                            vittoriaGiocatore2 = true;
                        }
                        else
                        {
                            cout << "SALVATO.  IL TUO AVERSARIO E VIVO" << endl;
                        }
                        contatoreSecondaScelta2++;
                        passoRound = true;
                    }
                    else
                    {
                        errore();
                    }
                }
                else
                {
                    if (contatoreSecondaScelta1 == 0)
                    {
                        for (int j = 3; j > 0; j--)
                        {
                            cout << j << endl;
                            sleep(1);
                        }
                        if (cameraInizialePistola == quantitaTamburo)
                        {
                            cameraInizialePistola = 0;
                        }
                        cameraInizialePistola++;
                        if (cameraInizialePistola == cameraPoittilePistola)
                        {
                            cout << "SPARO!!! IL TUO AVVERSARIO MORTO" << endl
                                 << "HAI VINTO " << giocatore1 << "!!!" << endl;
                            vittoriaGiocatore1 = true;
                        }
                        else
                        {
                            cout << "SALVATO.  IL TUO AVERSARIO E VIVO" << endl;
                        }
                        contatoreSecondaScelta1++;
                        passoRound = true;
                    }
                    else
                    {
                        errore();
                    }
                }

                break;
                //giro tamburo
            case 3:
                if (i % 2 == 0)
                {
                    if (contatoreTerzaScelta2 == 0)
                    {
                        cameraInizialePistola = rand() % quantitaTamburo + 1;
                        cout << "GIRO IL TAMBUROOO";
                        threePoints();

                        contatoreTerzaScelta2++;
                        passoRound = true;
                    }
                    else
                    {
                        errore();
                    }
                }
                else
                {
                    if (contatoreTerzaScelta1 == 0)
                    {
                        cameraInizialePistola = rand() % quantitaTamburo + 1;
                        cout << "GIRO IL TAMBUROOO";
                        threePoints();

                        contatoreTerzaScelta1++;
                        passoRound = true;
                    }
                    else
                    {
                        errore();
                    }
                }

                break;
            default:
                errore();
                break;
            }
        }
        if (perditaGiocatore1 == true)
        {
            cout << "HA VINTO " << giocatore2 << endl;
            vittoriaGiocatore2 = true;
        }
        else if (perditaGiocatore2 == true)
        {
            cout << "HA VINTO " << giocatore1 << endl;
            vittoriaGiocatore1 = true;
        }
    }
    cout << "RITORNO AL MENU";
    threePoints();
    space();
}

int main()
{

    int scelta;
    do
    {
        cout << " <========REVOLVER========>" << endl
             << "1. GIOCA" << endl
             << "2. COME SI GIOCA" << endl
             << "3. MODALITA' PERSONALE" << endl
             << "0. EXIT" << endl
             << "TUA SCELTA: ";

        cin >> scelta;

        switch (scelta)
        {
            // PER ACCEDERE GIOCO
        case 1:

            giocoProcesso();
            break;
            // GUIDA GIOCO
        case 2:
            int sceltaSwitch;
            space();
            cout << "<====================GUIDA GIOCO====================>" << endl
                 << "E' IL GIOCO DI RANDOM PER DUE PERSONE ETRAMBI DI VOI " << endl
                 << "HANNO LA STESSA PISTOLA CON UNO SOLO POIETTILE REALE " << endl
                 << "IN UNA CARICA SCONOSCIUTA DEL TAMBURO DI REVOLVER " << endl
                 << "E ALTRI 7 VUOTI. GIOCO SI TERMINA DOPO CHE UNO DI VOI " << endl
                 << "MUORE. AL INIZIO DEL OGNI ROUND AI QUATRO SCELTE." << endl
                 << endl;
            cout << "<=======================PRIMA=======================>" << endl
                 << "SPARARE IN SE STESSO. DOPO IL SPARO, IL TRAMBURO  " << endl
                 << "DELLA TUA PISTOLA SI GIRA UNA VOLTA IN AVANTI. " << endl
                 << endl;
            cout << "<======================SECONDO======================>" << endl
                 << "SPARARE NEL TUO AVERSARIO. DOPO IL SPARO, IL " << endl
                 << "TRAMBURO DELLA TUA PISTOLA SI GIRA UNA VOLTA IN AVANTI. " << endl
                 << "OGNUNO PUO UTILIZARLO SOLO UNA VOLTA!!! " << endl
                 << endl;
            cout << "<=======================TERZO=======================>" << endl
                 << "GIRARE IL TAMPURO DELLA PISTOLA PROPRIA IN MANO. DOPO " << endl
                 << "IL GIRO, IL POIETTILE NON CAMBIA LA PROPRIA CAMERA " << endl
                 << "MA LA CAMERA CORISPONDENTE DEL GIOCATORE SI (POTERBBE " << endl
                 << "USCIRE SUBITO IL POITTILE). OGNUNO PUO UTILIZARLO SOLO " << endl
                 << "UNA VOLTA!!!" << endl;
            space();
            sleep(3);
            do
            {
                cout << "1. INIZIARE GIOCO" << endl
                     << "0. MENU PRINCIPALE" << endl
                     << "TUA SCELTA: ";
                cin >> sceltaSwitch;
                if (sceltaSwitch == 1)
                {
                    giocoProcesso();
                }
                if (sceltaSwitch != 1 && sceltaSwitch != 0)
                {
                    errore();
                }
            } while (sceltaSwitch != 1 && sceltaSwitch != 0);
            sleep(1);
            break;
        case 3:
            cout << "TRA POCO..." << endl;
            break;
            // USCITA
        case 0:
            do
            {
                cout << "SICURO CHE VUOI USCIRE DAL GIOCO???" << endl
                     << "0. SI" << endl
                     << "1. NO" << endl
                     << "TUA SCELTA: ";

                cin >> scelta;
                if (scelta != 1 && scelta != 0)
                {
                    errore();
                }
                sleep(1);
            } while (scelta != 1 && scelta != 0);

            break;
        default:
            errore();
            break;
        }
    } while (scelta != 0);
    system("pause");
    return 0;
}
