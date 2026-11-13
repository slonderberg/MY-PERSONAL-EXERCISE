#include <iostream>
#include <string>
#include <windows.h>
#include <unistd.h>
#include <ctime>
using namespace std;

// per fare spazio
void space(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\n";
    }
}
// per fare bordo
void bordo()
{
    cout << "!==================================!" << endl;
}

// fa scrivere tre puntini
void threePoints()
{
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << endl;
}
// scrive un errore
void errore()
{
    space(3);
    bordo();
    cout << "SCELTA NON SUPPORTATA!!! RIPROVA" << endl;
    bordo();
    space(3);
    sleep(1);
}
void push_backListsChoisePlayer(int *&playerChoiseListRow, int *&playerChoiseListCol, int &sizePlayer, const int valueRow, const int valueCol)
{
    int *ChangeSizeChoiseListRow = new int[sizePlayer + 1];
    int *ChangeSizeChoiseListCol = new int[sizePlayer + 1];
    for (int i = 0; i < sizePlayer; i++)
    {
        ChangeSizeChoiseListRow[i] = playerChoiseListRow[i];
        ChangeSizeChoiseListCol[i] = playerChoiseListCol[i];
    }
    ChangeSizeChoiseListRow[sizePlayer] = valueRow;
    ChangeSizeChoiseListCol[sizePlayer] = valueCol;
    sizePlayer++;

    delete[] playerChoiseListRow;
    delete[] playerChoiseListCol;

    playerChoiseListRow = ChangeSizeChoiseListRow;
    playerChoiseListCol = ChangeSizeChoiseListCol;
}
void push_backListsChoiseBot(int *&botChoiseListRow, int *&botChoiseListCol, int &sizeBot, const int valueRow, const int valueCol)
{
    int *ChangeSizeChoiseListRow = new int[sizeBot + 1];
    int *ChangeSizeChoiseListCol = new int[sizeBot + 1];
    for (int i = 0; i < sizeBot; i++)
    {
        ChangeSizeChoiseListRow[i] = botChoiseListRow[i];
        ChangeSizeChoiseListCol[i] = botChoiseListCol[i];
    }
    ChangeSizeChoiseListRow[sizeBot] = valueRow;
    ChangeSizeChoiseListCol[sizeBot] = valueCol;
    sizeBot++;

    delete[] botChoiseListRow;
    delete[] botChoiseListCol;

    botChoiseListRow = ChangeSizeChoiseListRow;
    botChoiseListCol = ChangeSizeChoiseListCol;
}

// per impostare/cambiare il nome
void name(string &nickname)
{
    bool exitFooName = false;
    while (!exitFooName)
    {
        int choiseFooName;
        cout << "IMPOSTA IL NOME:\t";
        cin >> nickname;
        cout << "IL TUO NICKNAME:\t" << nickname << endl
             << "VUOI RIFARLO?" << endl
             << "1. SI" << endl
             << "2. NO" << endl
             << "RISPOSTA:\t";
        cin >> choiseFooName;
        switch (choiseFooName)
        {
        case 1:
            space(1);
            break;
        case 2:
            exitFooName = true;
            break;

        default:
            errore();
            break;
        }
    }
}

void ShowHeartPlayer(int QuantityOfHearts)
{
    string hearts = "<3";
    for (int i = 0; i < QuantityOfHearts; i++)
    {
        cout << hearts << " ";
    }
    cout << endl;
}
void ShowHeartBot(int QuantityOfHeartsBot)
{
    string hearts = "<3";
    for (int i = 0; i < QuantityOfHeartsBot; i++)
    {
        cout << hearts << " ";
    }
    cout << endl;
}

// funzione principale per il gioco
void Game(int row, int col, int QuantityOfBombs, int QuantityOfHearts, int QuantityOfHeartsBot, string name)
{

    int cordinateBombsRow[QuantityOfBombs];
    int cordinateBombsCol[QuantityOfBombs];

    cout << "IL TUO CAMPO DELLE PATATINE INIZIALE" << endl;
    char CheapsOfPlayer1[row][col];
    char CheapsOfBot[row][col];

    char cheaps = 'O';
    char spaceG = ' ';

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            CheapsOfPlayer1[i][j] = cheaps;
            CheapsOfBot[i][j] = cheaps;
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (i == 0)
        {
            cout << "N";
            for (int r = 1; r <= row; r++)
            {
                cout << " " << r;
            }
            cout << endl;
        }
        for (int j = 0; j < col; j++)
        {
            if (j == 0)
            {
                cout << i + 1 << " ";
                cout << CheapsOfPlayer1[i][j] << " ";
            }
            else
            {
                cout << CheapsOfPlayer1[i][j] << " ";
            }
        }
        cout << endl;
    }
    sleep(1);
    cout << "I TUOI CUORI: ";
    ShowHeartPlayer(QuantityOfHearts);
    sleep(1);
    cout << "I CUORI DI PATATA BOSS: ";
    ShowHeartBot(QuantityOfHeartsBot);
    sleep(1);
    space(3);

    cout << "INSERISCI LE CORDINATE DELLE TUE " << QuantityOfBombs << " PATATINE SPICY";
    bool exitBombs = false;
    while (!exitBombs)
    {
        int choiseBombs;
        for (int i = 0; i < QuantityOfBombs;)
        {
            cout << "PATATINA PICANTE N " << i + 1 << endl;
            do
            {
                cout << "LA RIGA: ";
                cin >> cordinateBombsRow[i];
                if (cordinateBombsRow[i] <= 0 || cordinateBombsRow[i] > row)
                {
                    errore();
                }
            } while (cordinateBombsRow[i] <= 0 || cordinateBombsRow[i] > row);
            do
            {
                cout << "LA COLONNA: ";
                cin >> cordinateBombsCol[i];
                if (cordinateBombsCol[i] <= 0 || cordinateBombsCol[i] > col)
                {
                    errore();
                }
            } while (cordinateBombsCol[i] <= 0 || cordinateBombsCol[i] > col);

            bool sameCordinate = false;
            for (int j = 0; j < i; j++)
            {
                if (cordinateBombsRow[i] == cordinateBombsRow[j] && cordinateBombsCol[i] == cordinateBombsCol[j])
                {
                    cout << "QUESTA PATATINA E' STATA GIA MINATA, RIINSERISCI LA COORDINATA" << endl;
                    sameCordinate = true;
                }
            }
            if (!sameCordinate)
            {
                i++;
            }
        }
        char bombs = '*';

        for (int i = 0; i < QuantityOfBombs; i++)
        {
            for (int r = 0; r < row; r++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (cordinateBombsRow[i] == r + 1 && cordinateBombsCol[i] == j + 1)
                    {
                        CheapsOfPlayer1[r][j] = bombs;
                    }
                    else if (CheapsOfPlayer1[r][j] == cheaps || CheapsOfPlayer1[r][j] == bombs)
                    {
                        continue;
                    }
                    else
                    {

                        CheapsOfPlayer1[r][j] = cheaps;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            if (i == 0)
            {
                cout << "N";
                for (int r = 1; r <= row; r++)
                {
                    cout << " " << r;
                }
                cout << endl;
            }
            for (int j = 0; j < col; j++)
            {
                if (j == 0)
                {
                    cout << i + 1 << " ";
                    cout << CheapsOfPlayer1[i][j] << " ";
                }
                else
                {
                    cout << CheapsOfPlayer1[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << "VUOI RIINSERIRE LE BOMBE?" << endl
             << "1. SI" << endl
             << "2. NO" << endl
             << "RISPOSTA: ";
        cin >> choiseBombs;
        switch (choiseBombs)
        {
        case 1:
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    CheapsOfPlayer1[i][j] = cheaps;
                }
            }

            break;

        case 2:
            exitBombs = true;
            break;

        default:
            errore();
            break;
        }
    }

    // patatina della fortuna
    int Golden_Cheap_Player_Row;
    int Golden_Cheap_Player_Col;

    if (QuantityOfBombs > 3)
    {
        bool empty_space = false;
        while (!empty_space)
        {
            Golden_Cheap_Player_Col = rand() % col + 1;
            Golden_Cheap_Player_Row = rand() % row + 1;
            empty_space = true;
            for (int i = 0; i < QuantityOfBombs && empty_space; i++)
            {
                if (cordinateBombsRow[i] == Golden_Cheap_Player_Row && cordinateBombsCol[i] == Golden_Cheap_Player_Col)
                {
                    empty_space = false;
                }
            }
        }
    }

    cout << "CARICAMENTO DEL CAMPO DI TUO AVERSARIO";
    threePoints();
    cout << endl;
    int cordinateBombsBotRow[QuantityOfBombs];
    int cordinateBombsBotCol[QuantityOfBombs];
    for (int i = 0; i < QuantityOfBombs;)
    {

        cordinateBombsBotRow[i] = rand() % row + 1;
        cordinateBombsBotCol[i] = rand() % col + 1;
        bool sameCordinate = false;
        for (int j = 0; j < i; j++)
        {
            if (cordinateBombsBotRow[i] == cordinateBombsBotRow[j] && cordinateBombsBotCol[i] == cordinateBombsBotCol[j])
            {
                sameCordinate = true;
            }
        }
        if (!sameCordinate)
        {
            i++;
        }
    }

    // patatina della fortuna
    int Golden_Cheap_Bot_Row;
    int Golden_Cheap_Bot_Col;
    if (QuantityOfBombs > 3)
    {
        bool empty_space = false;
        while (!empty_space)
        {
            Golden_Cheap_Bot_Col = rand() % col + 1;
            Golden_Cheap_Bot_Row = rand() % row + 1;
            empty_space = true;
            for (int i = 0; i < QuantityOfBombs && empty_space; i++)
            {
                if (cordinateBombsBotRow[i] == Golden_Cheap_Bot_Row && cordinateBombsBotCol[i] == Golden_Cheap_Bot_Col)
                {
                    empty_space = false;
                }
            }
        }
    }

    int startFirst = rand() % 2 + 1;
    int sizePlayer = 1;
    int sizeBot = 1;
    int *playerChoiseListRow = new int[sizePlayer];
    int *playerChoiseListCol = new int[sizePlayer];
    int *botChoiseListRow = new int[sizePlayer];
    int *botChoiseListCol = new int[sizePlayer];
    int WennNumberRound = 0;
    int NumberRound = 1;

    if (startFirst == 1)
    {
        cout << "GIOCATORE " << name << " INIZIA IL PRIMO" << endl;
    }
    else
    {
        cout << "PATATA BOSS INIZIA IL PRIMO" << endl;
    }
    // processo dei round
    while (QuantityOfHearts != 0 && QuantityOfHeartsBot != 0)
    {
        if (WennNumberRound % 2 == 0)
        {

            cout << "Round n." << NumberRound << endl;
            NumberRound++;
        }
        WennNumberRound++;
        if (startFirst == 1)
        {
            cout << "IL CAMPO DEL TUO AVERSARIO:" << endl;
            for (int i = 0; i < row; i++)
            {
                if (i == 0)
                {
                    cout << "N";
                    for (int r = 1; r <= row; r++)
                    {
                        cout << " " << r;
                    }
                    cout << endl;
                }
                for (int j = 0; j < col; j++)
                {
                    if (j == 0)
                    {
                        cout << i + 1 << " ";
                        cout << CheapsOfBot[i][j] << " ";
                    }
                    else
                    {
                        cout << CheapsOfBot[i][j] << " ";
                    }
                }
                cout << endl;
            }
            int takeCheapsRow;
            int takeCheapsCol;
            cout << "TOCCA TE " << name << endl;
            bool repiteTakenCheaps = true;
            while (repiteTakenCheaps)
            {
                repiteTakenCheaps = false;
                do
                {
                    cout << "LA RIGA: ";

                    cin >> takeCheapsRow;
                    if (takeCheapsRow < 0 || takeCheapsRow > row)
                    {
                        errore();
                    }

                } while (takeCheapsRow < 0 || takeCheapsRow > row);
                do
                {
                    cout << "LA COLONNA: ";
                    cin >> takeCheapsCol;
                    if (takeCheapsCol < 0 || takeCheapsCol > col)
                    {
                        errore();
                    }

                } while (takeCheapsCol < 0 || takeCheapsCol > col);

                for (int i = 1; i < sizePlayer; i++)
                {
                    if (playerChoiseListRow[i - 1] == takeCheapsRow && playerChoiseListCol[i - 1] == takeCheapsCol)
                    {
                        errore();
                        repiteTakenCheaps = true;
                    }
                }
            }
            push_backListsChoisePlayer(playerChoiseListRow, playerChoiseListCol, sizePlayer, takeCheapsRow, takeCheapsCol);
            bool exitForTakeCheaps = false;
            for (int i = 0; i < QuantityOfBombs && !exitForTakeCheaps; i++)
            {
                if (cordinateBombsBotRow[i] == takeCheapsRow && cordinateBombsBotCol[i] == takeCheapsCol)
                {
                    cout << "HAI SCELT0 LA PATATINA SPICYYY" << endl;
                    QuantityOfHearts--;
                    space(1);
                    sleep(1);
                    cout << "I TUOI CUORI: ";
                    exitForTakeCheaps = true;
                }
                else if (Golden_Cheap_Bot_Row == takeCheapsRow && Golden_Cheap_Bot_Col == takeCheapsCol)
                {
                    cout << "HAI PESCATO LA PATATINA GOLD" << endl;
                    QuantityOfHearts++;
                    space(1);
                    sleep(1);
                    cout << "I TUOI CUORI: ";
                    exitForTakeCheaps = true;
                }
            }
            if (!exitForTakeCheaps)
            {
                cout << "HAI SCELT0 LA PATATINA NORMALE. SALVATO" << endl;
                sleep(1);
                space(1);
                cout << "I TUOI CUORI: ";
            }
            ShowHeartPlayer(QuantityOfHearts);
            CheapsOfBot[takeCheapsRow - 1][takeCheapsCol - 1] = spaceG;
        }
        else
        {

            int takeCheapsRow;
            int takeCheapsCol;
            cout << "PATATA BOSS STA SCEGLENDO";
            threePoints();
            space(1);
            bool repiteTakenCheaps = true;
            while (repiteTakenCheaps)
            {
                repiteTakenCheaps = false;
                takeCheapsRow = rand() % row + 1;
                takeCheapsCol = rand() % col + 1;

                for (int i = 1; i < sizeBot; i++)
                {
                    if (botChoiseListRow[i - 1] == takeCheapsRow && botChoiseListCol[i - 1] == takeCheapsCol)
                    {

                        repiteTakenCheaps = true;
                    }
                }
            }
            push_backListsChoiseBot(botChoiseListRow, botChoiseListCol, sizeBot, takeCheapsRow, takeCheapsCol);
            bool exitForTakeCheaps = false;
            for (int i = 0; i < QuantityOfBombs && !exitForTakeCheaps; i++)
            {
                if (cordinateBombsRow[i] == takeCheapsRow && cordinateBombsCol[i] == takeCheapsCol)
                {
                    cout << "PATATA BOSS HA SCELTO LA PATATINA SPICYYY" << endl;
                    QuantityOfHeartsBot--;
                    sleep(1);
                    space(1);
                    cout << "I CUORI DI PATATA BOSS: ";

                    exitForTakeCheaps = true;
                }
                else if (Golden_Cheap_Player_Row == takeCheapsRow && Golden_Cheap_Player_Col == takeCheapsCol)
                {
                    cout << "PATATA BOSS HA PESCATO LA PATATINA GOLD" << endl;
                    QuantityOfHeartsBot++;
                    space(1);
                    sleep(1);
                    cout << "I CUORI DI PATATA BOSS: ";

                    exitForTakeCheaps = true;
                }
            }
            if (!exitForTakeCheaps)
            {
                cout << "PATATA BOSS HA SCELT0 LA PATATINA NORMALE. SALVATO" << endl;
                sleep(1);
                space(1);
                cout << "I CUORI DI PATATA BOSS: ";
            }
            ShowHeartBot(QuantityOfHeartsBot);
            CheapsOfPlayer1[takeCheapsRow - 1][takeCheapsCol - 1] = spaceG;
        }
        if (startFirst == true)
        {
            startFirst = false;
        }
        else
        {
            startFirst = true;
        }
        if (QuantityOfHearts == 0)
        {
            cout << "HA VINTO PATATA BOSS, BUONA FORTUNA PROSSIMA VOLTA";
            threePoints();
        }
        else if (QuantityOfHeartsBot == 0)
        {
            cout << "COMPLIMENTI " << name << " HAI VINTO, TI ASPETTIAMO ANCORA";
            threePoints();
        }
        sleep(1);
    }

    delete[] playerChoiseListCol;
    delete[] playerChoiseListRow;
}
// main come menu con impostazioni e le regole
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    bool exitGame = false;
    string player = "empty";
    while (!exitGame)
    {

        int choisePrincipal;
        cout << "MENU" << endl
             << "1. Inizia giocare" << endl
             << "2. Come si gioca" << endl
             << "3. Imposta il nome" << endl
             << "0. Quitta" << endl
             << "Risposta: ";
        cin >> choisePrincipal;
        space(1);
        switch (choisePrincipal)
        {
        case 1:
        {

            bool exitCase1 = false;
            if (player == "empty")
            {
                bool exitIfWhileCase1 = false;
                while (!exitIfWhileCase1)
                {
                    int choiseIfCase1;
                    cout << "NON HAI IMPOSTATO IL TUO NICKNAME, SICURO CHE VUOI PROSEGUIRE?" << endl
                         << "NICKNAME CORRENTE:\t" << player << endl
                         << "1. PROSSEGUIRE" << endl
                         << "2. IMPOSTARE IL NOME" << endl
                         << "RISPOSTA: ";
                    cin >> choiseIfCase1;
                    space(1);
                    switch (choiseIfCase1)
                    {
                    case 1:
                        exitIfWhileCase1 = true;
                        break;

                    case 2:
                        name(player);
                        exitIfWhileCase1 = true;
                        break;

                    default:
                        errore();
                        break;
                    }
                }
            }

            while (!exitCase1)
            {
                int choiseCase1;
                cout << "IMPOSTA LA MODALITA DEL GIOCO" << endl
                     << "1. FACILE" << endl
                     << "2. COMPLICATO" << endl
                     << "3. DIFFICILE" << endl
                     << "4. IMPOSIBILE" << endl
                     << "RISPOSTA: ";
                cin >> choiseCase1;
                space(3);
                sleep(1);
                switch (choiseCase1)
                {
                case 1:
                    Game(3, 3, 3, 3, 3, player);
                    exitCase1 = true;
                    break;
                case 2:
                    Game(6, 6, 11, 3, 3, player);
                    exitCase1 = true;
                    break;
                case 3:
                    Game(9, 9, 23, 3, 3, player);
                    exitCase1 = true;
                    break;
                case 4:
                    Game(9, 9, 25, 1, 5, player);
                    exitCase1 = true;
                    break;
                default:
                    errore();
                    break;
                }
            }
        }
        break;
        case 2:
            cout << "===========================REGOLE DEL GIOCO==========================" << endl
                 << "SUL TAVOLO CI SONO LE PATATINE DIVISI IN DUE PARTI UGUALI CON LA  " << endl
                 << "QUANTITA PURE UGUALE. AL INIZIO DEL GIOCO DEVI SCEGLERE LE PATATINE " << endl
                 << "QUALI VUOI MINARE CON LA SALSA EXTRA HOT DALLA PARTE DEL TUO AVERSARIO. " << endl
                 << "PERDE CHI SPRECCA PRIMA I TUTTI SUOI CUORI";
            cout << endl;
            cout << "=========================I SIMBOLI DEL GIOCO=========================" << endl
                 << "O ----> LA PATATINA" << endl
                 << "* ----> LA PATATINA MINATA" << endl
                 << "<3 ----> CUORI" << endl
                 << endl
                 << "BUONA FORTUNA" << endl;
            sleep(1);
            break;
        case 3:
            name(player);
            break;
        case 0:
            exitGame = true;
            break;
        default:
            errore();
            break;
        }
    }

    system("pause");
    return 0;
}
