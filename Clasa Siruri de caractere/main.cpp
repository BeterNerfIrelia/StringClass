#include <iostream>
#include <Sir.h>
#include <cstring>
#include <windows.h>
#include <conio.h>

#define DBLUE 1
#define DGREEN 2
#define LBLUE 3
#define DRED 4
#define DPURPLE 5
#define DYELLOW 6
#define DWHITE 7
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define LIGHTERBLUE 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

using namespace std;

char defaultSir[]="Acesta este sirul de caractere, default, pentru testarea functiilor programului!";

Sir A,B;
Sir D;
Sir copieOriginal;

char litera,lin,lout;
char out[100001];
char in[100001];

unsigned long long optiune,n;

unsigned long long iscriptat=0;

unsigned long long Ok,Ok2;


HANDLE colour=GetStdHandle(STD_OUTPUT_HANDLE);

void clearScreen()
{
    system("cls");
}

void textRevenire()
{
    SetConsoleTextAttribute(colour,DWHITE);
    cout<<"\n\nPentru a reveni in meniul anterior, apasati tasta";
    SetConsoleTextAttribute(colour,LIGHTERBLUE);
    cout<<" =\n\n";
    SetConsoleTextAttribute(colour,DWHITE);
    cout<<"Pentru a reveni in meniul principal, apsati tasta:";
    SetConsoleTextAttribute(colour,LIGHTERBLUE);
    cout<<" 0\n\n\n";
}


int main()
{
    SetConsoleTextAttribute(colour,RED);
    cout<<"\nBine ati venit! Acesta este un proiect despre siruri de caractere.\n\n\n";
    cout<<"Apasati orice tasta pentru a continua...";
    getch();

    CreareSir:
        clearScreen();

        SetConsoleTextAttribute(colour,GREEN);
        cout<<"Doriti sa introduceti dumneavoastra un sir de caractere sau sa il utilizati pe cel pentru testare, al programului?\n\n";

        MeniuCreareSir:

            SetConsoleTextAttribute(colour,YELLOW);
            cout<<"    Va rugam sa introduceti cifra corespunzatoare optiunii dorite:\n";
            SetConsoleTextAttribute(colour,RED);
            cout<<"1. ";
            SetConsoleTextAttribute(colour,LIGHTERBLUE);
            cout<<"Sirul de testare va fi cel utilizat\n";
            SetConsoleTextAttribute(colour,RED);
            cout<<"2. ";
            SetConsoleTextAttribute(colour,LIGHTERBLUE);
            cout<<"Un sir va fi introdus de la tastatura\n";
            SetConsoleTextAttribute(colour,RED);
            cout<<"3. ";
            SetConsoleTextAttribute(colour,LIGHTERBLUE);
            cout<<"Se afiseaza sirul de testare\n\n\n\n";
            SetConsoleTextAttribute(colour,DWHITE);
            cout<<"Puteti parasi programul in acest moment prin apasarea tastei ";
            SetConsoleTextAttribute(colour,PURPLE);
            cout<<"0";
            SetConsoleTextAttribute(colour,WHITE);

            optiune=getch();
            switch(optiune)
            {
            case 49:
                {
                    clearScreen();
                    A.copyFrom(defaultSir);
                    break;
                }
            case 50:
                {
                    clearScreen();
                    A.readKB();
                    break;
                }
            case 51:
                {
                    clearScreen();
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<defaultSir<<"\n\n";
                    goto MeniuCreareSir;
                    break;
                }
            case 48:
                {
                    clearScreen();
                    cout<<"\n\n\n\n";
                    return 0;
                }
            default:
                {
                    clearScreen();
                    cout<<"\n\nComanda invalida. Va rugam sa introduceti o comanda valida. Apasati orice tasta pentru a reveni in meniu.";
                    getch();
                    clearScreen();
                    goto MeniuCreareSir;
                    break;
                }
            }

    copieOriginal.copyFrom(A);

    MeniuPrincipal:
        clearScreen();
        SetConsoleTextAttribute(colour,GREEN);
        cout<<"\nVa rugam sa introduceti cifra corespunzatoare optiunii dorite\n\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"1. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Operatii pe sir\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"2. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Modificari asupra sirului\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"3. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Inserari\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"4. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Eliminari\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"5. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Revenirea la meniul de creare\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"6. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Parasirea programului\n";
        SetConsoleTextAttribute(colour,YELLOW);
        cout<<"7. ";
        SetConsoleTextAttribute(colour,PURPLE);
        cout<<"Inlocuirea sirului de testare\n\n\n";

        SetConsoleTextAttribute(colour,DRED);
        cout<<"Pentru a obtine informatii despre categoriile de mai sus, apasati tasta ";
        SetConsoleTextAttribute(colour,WHITE);
        cout<<"- (minus)\n\n";
        SetConsoleTextAttribute(colour,DRED);
        cout<<"Pentru a reveni in meniul principal, puteti sa apasati oricand pe tasta ";
        SetConsoleTextAttribute(colour,LIGHTERBLUE);
        cout<<"0\n\n\n\n\n";
        SetConsoleTextAttribute(colour,WHITE);

        optiune=getch();
        switch(optiune)
        {
        case 49:
            {
                //operatii pe sir;
                meniuOp:
                    clearScreen();
                    SetConsoleTextAttribute(colour,GREEN);
                    cout<<" Doriti sa:\n\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"1. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Obtineti informatii despre sir\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"2. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Intrati in meniul de criptare\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"3. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Inversati sirul\n\n";
                    textRevenire();
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        goto MeniuPrincipal;
                        break;
                    case 61:
                        goto MeniuPrincipal;
                        break;
                    case 49:
                        {
                            meniuOpInfo:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa obtineti:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de cuvinte din sir\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de vocale din sir\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de consoane din sir\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"4. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de simboluri din sir\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"5. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de cifre din sir\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"6. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Numarul de aparitii a unui sir de caractere sau al unui caracter\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"7. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Compozitia sirului dumneavoastra\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuOp;
                                    break;
                                case 49:
                                    {
                                        //1. numarul de cuvinte;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<" Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta este numarul de cuvinte din sir: ";
                                        SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                        cout<<A.getNoCuv()<<"\n\n";
                                        iesireOpInfo:
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuOpInfo;
                                                break;
                                            default:
                                                {
                                                    invalidOpInfoCuv:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuOpInfo;
                                                            break;
                                                        default:
                                                            goto invalidOpInfoCuv;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;

                                    }
                                case 50:
                                    {
                                        //2. numarul de vocale
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<" Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta este numarul de vocale din sir: ";
                                        SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                        cout<<A.getNoVowel()<<"\n\n";
                                        goto iesireOpInfo;
                                        break;
                                    }
                                case 51:
                                    {
                                        //3. numarul de consoane
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<" Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta este numarul de consoane din sir: ";
                                        SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                        cout<<A.getNoConsoane()<<"\n\n";
                                        goto iesireOpInfo;
                                        break;
                                    }
                                case 52:
                                    {
                                        //4. numarul de simboluri
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<" Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta este numarul de simboluri din sir: ";
                                        SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                        cout<<A.getNoSymbols()<<"\n\n";
                                        goto iesireOpInfo;
                                        break;
                                    }
                                case 53:
                                    {
                                        //5. numarul de cifre
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<" Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta este numarul de cifre din sir: ";
                                        SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                        cout<<A.getDigits()<<"\n\n";
                                        goto iesireOpInfo;
                                        break;
                                    }
                                case 54:
                                    {
                                        //6. aparitii
                                        meniuOpInfoAp:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa obtineti numarul de aparitii:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Al unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Al unui sir de caractere\n\n";
                                            textRevenire;
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuOpInfo;
                                                break;
                                            case 49:
                                                {
                                                    //nr ap ch
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti caracterul al carui numar de aparitii doriti sa il aflati: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>lin;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Acesta este sirul dumneavoastra:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Si acesta este numarul de aparitii ale caracterului cautat: ";
                                                    SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                                    cout<<A.getAparitiiCh(lin)<<"\n\n";
                                                    iesireOpInfoAp:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuOpInfoAp;
                                                            break;
                                                        default:
                                                            {
                                                                invalidOpInfoAp2:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuOpInfoAp;
                                                                        break;
                                                                    default:
                                                                        goto invalidOpInfoAp2;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //nr ap str
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti sirul de caractere caracterul al carui numar de aparitii doriti sa il aflati: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin.getline(in,100000);
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Acesta este sirul dumneavoastra:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Si acesta este numarul de aparitii ale sirului de caractere cautat: ";
                                                    SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                                    cout<<A.getAparitiiCuv(in)<<"\n\n";
                                                    goto iesireOpInfoAp;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidOpInfoAp:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuOpInfoAp;
                                                            break;
                                                        default:
                                                            goto invalidOpInfoAp;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 55:
                                    {
                                        //7. compozitia;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"Acesta este sirul dumneavoastra:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Si acesta contine:\n\n";
                                        A.doCompozitie(A);
                                        SetConsoleTextAttribute(colour,DWHITE);
                                        cout<<" - "<<A.compozitie[0]<<" de cuvinte\n";
                                        cout<<" - "<<A.compozitie[1]<<" de vocale\n";
                                        cout<<" - "<<A.compozitie[2]<<" de conaone\n";
                                        cout<<" - "<<A.compozitie[3]<<" de cifre\n";
                                        cout<<" - "<<A.compozitie[4]<<" de simboluri\n";
                                        cout<<" - "<<A.compozitie[5]<<" de spatii\n\n";
                                        goto iesireOpInfo;
                                        break;
                                    }
                                default:
                                    {
                                        invalidOpInfo:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuOpInfo;
                                                break;
                                            default:
                                                goto invalidOpInfo;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 50:
                        {
                            meniuOpCrypt:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<"Doriti sa:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Criptati sirul\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Decriptati sirul\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuOp;
                                    break;
                                case 49:
                                    {
                                        //criptare
                                        meniuOpCryptKey:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<"Cheia dumneavoastra doriti sa fie:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Generata de program\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Introdusa de dumneavoastra\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuOpCrypt;
                                                break;
                                            case 49:
                                                {
                                                    //cheie generata;
                                                    clearScreen();
                                                    iscriptat=1;
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Cheia generata este: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    A.createCaesarKey();
                                                    cout<<A.getCaesarKey()<<"\n";
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra inainte de operatia de criptare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa operatia de criptare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaesarEncrypt();
                                                    A.AfisareENL();
                                                    iesireCriptare:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuOpCryptKey;
                                                            break;
                                                        default:
                                                            {
                                                                invalidIesireCriptare:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuOpCryptKey;
                                                                        break;
                                                                    default:
                                                                        goto invalidIesireCriptare;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //cheie introdusa;
                                                    clearScreen();
                                                    iscriptat=1;
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti cheia de criptare: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    A.readCaesarKey();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de operatia de criptare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa operatia de criptare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaesarEncrypt();
                                                    A.AfisareENL();
                                                    goto iesireCriptare;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidOpCryptKey:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuOpCryptKey;
                                                            break;
                                                        default:
                                                            goto invalidOpCryptKey;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        //decriptare
                                        meniuDecrypt:
                                            clearScreen();
                                            switch(iscriptat)
                                            {
                                            case 48:
                                                {
                                                    invalidCheie:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Sirul dumneavoastra nu a fost criptat de program inainte, astfel cheia pentru decriptare nu este cunoscuta.\n";
                                                        cout<<"Va rugam sa criptati sirul, folosind programul, inainte de a accesa aceasta optiune\n\n";
                                                        getch();
                                                        goto meniuOpCrypt;
                                                        break;
                                                }
                                            case 49:
                                                {
                                                    //a fost criptat
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Avesta este sirul dumneavoastra:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Acesta este sirul dumneavoastra dupa operatia de decriptare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaesarDecrypt();
                                                    A.AfisareENL();
                                                    textRevenire();
                                                    optiune=getch();
                                                    switch(optiune)
                                                    {
                                                    case 48:
                                                        goto MeniuPrincipal;
                                                        break;
                                                    case 61:
                                                        goto meniuOpCrypt;
                                                        break;
                                                    default:
                                                        goto invalidOpCryptKey;
                                                        break;
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidOpCrypt:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuOpCrypt;
                                                break;
                                            default:
                                                goto invalidOpCrypt;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 51:
                        {
                            clearScreen();
                            SetConsoleTextAttribute(colour,GRAY);
                            cout<<" Sirul dumneavoastra inainte de operatie:\n";
                            SetConsoleTextAttribute(colour,RED);
                            A.AfisareENL();
                            SetConsoleTextAttribute(colour,GRAY);
                            cout<<"\n\n Sirul dumneavoastra dupa operatie:\n";
                            SetConsoleTextAttribute(colour,RED);
                            A.reverseSir();
                            A.AfisareENL();
                            textRevenire();
                            optiune=getch();
                            switch(optiune)
                            {
                            case 48:
                                goto MeniuPrincipal;
                                break;
                            case 61:
                                goto meniuOp;
                                break;
                            default:
                                {
                                    invalidOpRev:
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,RED);
                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                        textRevenire();
                                        optiune=getch();
                                        switch(optiune)
                                        {
                                        case 48:
                                            goto MeniuPrincipal;
                                            break;
                                        case 61:
                                            goto meniuOp;
                                            break;
                                        default:
                                            goto invalidOpRev;
                                            break;
                                        }
                                        break;
                                }
                            }
                            break;
                        }
                    default:
                        {
                            invalidOp:
                                clearScreen();
                                SetConsoleTextAttribute(colour,RED);
                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuOp;
                                    break;
                                default:
                                    goto invalidOp;
                                    break;
                                }
                                break;
                        }
                    }
                    break;
            }
        case 50:
            {
                //modificari -> up,lower,replace;
                meniuMod:
                    clearScreen();
                    SetConsoleTextAttribute(colour,GREEN);
                    cout<<" Ce actiune doriti sa efectuati asupra sirului dumneavoastra?\n\n\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"1. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Micsorati caractere\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"2. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Mariti caractere\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"3. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Micsorati siruri de caractere\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"4. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Mariti siruri de  caractere\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"5. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Inlocuiti caractere\n\n";
                    textRevenire();
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        goto MeniuPrincipal;
                        break;
                    case 61:
                        goto MeniuPrincipal;
                        break;
                    case 49:
                        {
                            //micsorare ch;
                            meniuModChLower:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa micsorati:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un numar specific de aparitii\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Vocale\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Consoane\n\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuMod;
                                    break;
                                case 49:
                                    {
                                        // micsorare numar specific aparitii
                                        /* 1. prima aparitie
                                        2. primele N aparitii
                                        3. ultima apritie
                                        4. ultimele n aparitii
                                        5. toate aparitiile
                                        */
                                        meniuModChLowerN:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa micsorati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate caracterele din sir\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChLower;
                                                break;
                                            case 49:
                                                {
                                                    meniuModChLowerN1st:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"Doriti sa micsorati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primul caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Un caracter specific\n\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLowerN;
                                                            break;
                                                        case 49:
                                                            {
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseLowerFirstCh();
                                                                A.AfisareENL();
                                                                OutModChLN:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerN1st;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChLN1;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                            case 50:
                                                                {
                                                                       clearScreen();
                                                                       SetConsoleTextAttribute(colour,DYELLOW);
                                                                       cout<<"Va rugam sa introduceti caracterul pe care il doriti modificat: ";
                                                                       SetConsoleTextAttribute(colour,PURPLE);
                                                                       cin>>litera;
                                                                       SetConsoleTextAttribute(colour,GRAY);
                                                                       cout<<"\n\nSirul dumneavoastra inainte de modificari:\n";
                                                                       SetConsoleTextAttribute(colour,RED);
                                                                       A.AfisareENL();
                                                                       SetConsoleTextAttribute(colour,GRAY);
                                                                       cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                                       A.CaseLowerFirstSpecificCh(litera);
                                                                       A.AfisareENL();
                                                                       goto OutModChLN;
                                                                       break;
                                                                }

                                                        default:
                                                            {
                                                                invalidModChLN1:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,WHITE);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerN1st;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChLN1;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuModChLowerN2nd:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"Doriti sa micsorati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N caractere ale sirului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLower;
                                                            break;
                                                        case 49:
                                                            {
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti numarul de caractere pe care doriti sa le micsorati: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\nSirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseLowerFirstNCh(n);
                                                                A.AfisareENL();
                                                                outModChLN2:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerN2nd;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            cout<<"Comanda invalida. va rugam sa introduceti o comanda valida.\n";
                                                                            goto outModChLN2;
                                                                            break;
                                                                        }
                                                                    }
                                                                break;
                                                            }
                                                                    case 50:
                                                                        {
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"Va rugam sa introduceti caracterul pe care doriti sa il micsorati: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>litera;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\nVa rugam sa introduceti de aparitii micsorate: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\nSirul dumneavaostra inainte de modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\nSirul dumneavaostra dupa modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.CaseLowerFirstNChDate(litera,n);
                                                                            A.AfisareENL();
                                                                            goto outModChLN2;
                                                                            break;

                                                                        }
                                                        default:
                                                            {
                                                                invalidModChLN2:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,WHITE);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerN2nd;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChLN2;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;

                                                }
                                            case 51:
                                            {
                                                   menuModChLLast:
                                                       clearScreen();
                                                       SetConsoleTextAttribute(colour,GREEN);
                                                       cout<<"Doriti sa micsorati:\n";
                                                       SetConsoleTextAttribute(colour,YELLOW);
                                                       cout<<"1. ";
                                                       SetConsoleTextAttribute(colour,DWHITE);
                                                       cout<<"Ultimul caracter\n";
                                                       SetConsoleTextAttribute(colour,YELLOW);
                                                       cout<<"2. ";
                                                       SetConsoleTextAttribute(colour,DWHITE);
                                                       cout<<"Ultima aparitie a unui caracter specific\n\n";
                                                       textRevenire();
                                                       optiune=getch();
                                                       switch(optiune)
                                                       {
                                                       case 48:
                                                        goto MeniuPrincipal;
                                                        break;
                                                       case 61:
                                                        goto meniuModChLower;
                                                        break;
                                                       case 49:
                                                        {
                                                            clearScreen();
                                                            SetConsoleTextAttribute(colour,GRAY);
                                                            cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                            SetConsoleTextAttribute(colour,RED);
                                                            A.AfisareENL();
                                                            SetConsoleTextAttribute(colour,GRAY);
                                                            cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                            SetConsoleTextAttribute(colour,RED);
                                                            A.CaseLowerLastCh();
                                                            A.AfisareENL();
                                                            goto IesireDinModChLLast;
                                                            break;
                                                        }
                                                       case 50:
                                                        {
                                                            clearScreen();
                                                            SetConsoleTextAttribute(colour,GREEN);
                                                            cout<<"Va rugam sa introduceti caracterul a carui ultima aparitie va fi micsorata: ";
                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                            cin>>litera;
                                                            SetConsoleTextAttribute(colour,GRAY);
                                                            cout<<"\n\nSirul dumneavoastra inainte de modificari:\n";
                                                            SetConsoleTextAttribute(colour,RED);
                                                            A.AfisareENL();
                                                            SetConsoleTextAttribute(colour,GRAY);
                                                            cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                            SetConsoleTextAttribute(colour,RED);
                                                            A.CaseLowerLastDatCh(litera);
                                                            A.AfisareENL();
                                                            goto IesireDinModChLLast;
                                                            break;
                                                        }
                                                       default:
                                                        {
                                                            invalidModChLLast:
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,RED);
                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                IesireDinModChLLast:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto menuModChLLast;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChLLast;
                                                                        break;
                                                                    }
                                                                    break;
                                                        }
                                                       }
                                                       break;
                                            }
                                                                    case 52:
                                                                        {
                                                                            meniuModChLowerLN:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                                cout<<"Doriti sa micsorati:\n";
                                                                                SetConsoleTextAttribute(colour,YELLOW);
                                                                                cout<<"1. ";
                                                                                SetConsoleTextAttribute(colour,DWHITE);
                                                                                cout<<"Ultimele N caractere\n";
                                                                                SetConsoleTextAttribute(colour,YELLOW);
                                                                                cout<<"2. ";
                                                                                SetConsoleTextAttribute(colour,DWHITE);
                                                                                cout<<"Ultimele N aparitii ale unui caracter\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuModChLower;
                                                                                    break;
                                                                                case 49:
                                                                                    {
                                                                                        clearScreen();
                                                                                        SetConsoleTextAttribute(colour,GREEN);
                                                                                        cout<<"Va rugam sa introduceti numare de caractere care urmeaza sa fie micsorate: ";
                                                                                        SetConsoleTextAttribute(colour,PURPLE);
                                                                                        cin>>n;
                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                        cout<<"\n\nSirul dumneavoastra inainte de modificari: \n";
                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                        A.AfisareENL();
                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                                                        A.CaseLowerLastNCh(n);
                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                        A.AfisareENL();
                                                                                        goto outDinModChLowerLN;
                                                                                        break;
                                                                                    }
                                                                                case 50:
                                                                                    {
                                                                                        clearScreen();
                                                                                        SetConsoleTextAttribute(colour,GREEN);
                                                                                        cout<<"Va rugam sa introduceti caracterul care urmeaza sa fie micsorat: ";
                                                                                        SetConsoleTextAttribute(colour,PURPLE);
                                                                                        cin>>litera;
                                                                                        SetConsoleTextAttribute(colour,GREEN);
                                                                                        cout<<"\n\nVa rugam sa introduceti numare de caractere care urmeaza sa fie micsorate: ";
                                                                                        SetConsoleTextAttribute(colour,PURPLE);
                                                                                        cin>>n;
                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                        cout<<"\n\nSirul dumneavoastra inainte de modificari: \n";
                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                        A.AfisareENL();
                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                                                        A.CaseLowerLastNCh(n);
                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                        A.AfisareENL();
                                                                                        goto outDinModChLowerLN;
                                                                                        break;
                                                                                    }
                                                                                default:
                                                                                    {
                                                                                        invalidModChLowerLN:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. va rugam sa introduceti o comanda valida.\n\n";
                                                                                            outDinModChLowerLN:
                                                                                                textRevenire();
                                                                                                optiune=getch();
                                                                                                switch(optiune)
                                                                                                {
                                                                                                case 48:
                                                                                                    goto MeniuPrincipal;
                                                                                                    break;
                                                                                                case 61:
                                                                                                    goto meniuModChLower;
                                                                                                    break;
                                                                                                default:
                                                                                                    goto invalidModChLowerLN;
                                                                                                    break;
                                                                                                }
                                                                                                break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                                                case 53:
                                                                                                    {
                                                                                                        clearScreen();
                                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                                        cout<<"Sirul dumneavoastra inainte de modificari: \n";
                                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                                        A.AfisareENL();
                                                                                                        SetConsoleTextAttribute(colour,GRAY);
                                                                                                        cout<<"\n\nSirul dumneavoastra dupa modificari: \n";
                                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                                        A.CaseLowerAll();
                                                                                                        A.AfisareENL();
                                                                                                        OutofHere:
                                                                                                            textRevenire();
                                                                                                            optiune=getch();
                                                                                                            switch(optiune)
                                                                                                            {
                                                                                                            case 48:
                                                                                                                goto MeniuPrincipal;
                                                                                                                break;
                                                                                                            case 61:
                                                                                                                goto meniuModChLower;
                                                                                                                break;
                                                                                                            default:
                                                                                                                {
                                                                                                                    outofhere2:
                                                                                                                        clearScreen();
                                                                                                                        SetConsoleTextAttribute(colour,RED);
                                                                                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                                                        goto OutofHere;
                                                                                                                        break;

                                                                                                                }
                                                                                                            }
                                                                                                    }
                                            default:
                                                {
                                                    invalidChLN:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLowerN;
                                                            break;
                                                        default:
                                                            goto invalidChLN;
                                                            break;
                                                        }
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        //vocale
                                        meniuModChLowerVoc:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<"Doriti sa micsorati:\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima vocala\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima vocala\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate vocalele\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuMod;
                                                break;
                                            case 49:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerVocaleFirst();
                                                    A.AfisareENL();
                                                    IesireVocaleLow:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLower;
                                                            break;
                                                        default:
                                                            {
                                                                invalidOutVocaleL:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comandva invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerVoc;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            goto invalidOutVocaleL;
                                                                            break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                    break;
                                                }
                                            case 50:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti numarul de vocale care urmeaza sa fie micsorate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerVocaleFirstN(n);
                                                    A.AfisareENL();
                                                    goto IesireVocaleLow;
                                                    break;
                                                }
                                            case 51:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerVocaleLast();
                                                    A.AfisareENL();
                                                    goto IesireVocaleLow;
                                                    break;
                                                }
                                            case 52:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti numarul de vocale care urmeaza sa fie micsorate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerVocaleLastN(n);
                                                    A.AfisareENL();
                                                    goto IesireVocaleLow;
                                                    break;
                                                }
                                            case 53:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerVocaleAll();
                                                    A.AfisareENL();
                                                    goto IesireVocaleLow;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidModChLowerVoc:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLowerVoc;
                                                            break;
                                                        default:
                                                            goto invalidModChLowerVoc;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        //consoane
                                        meniuModChLowerCon:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<"Doriti sa micsorati:\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima consoana\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima consoana\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate consoanele\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChLower;
                                                break;
                                            case 49:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerConsoaneFirst();
                                                    A.AfisareENL();
                                                    IesireConsoaneLow:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChLowerCon;
                                                            break;
                                                        default:
                                                            {
                                                                invalidOutCon:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda invalida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChLowerCon;
                                                                        break;
                                                                    default:
                                                                        goto invalidOutCon;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti numarul de consoane care urmeaza sa fie micsorate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerConsoaneFirstN(n);
                                                    A.AfisareENL();
                                                    goto IesireConsoaneLow;
                                                    break;
                                                }
                                            case 51:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerConsoaneLast();
                                                    goto IesireConsoaneLow;
                                                    break;
                                                }
                                            case 52:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"Va rugam sa introduceti numarul de consoane care urmeaza sa fie micsorate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerConsoaneLastN(n);
                                                    A.AfisareENL();
                                                    goto IesireConsoaneLow;
                                                    break;
                                                }
                                            case 53:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseLowerConsoaneAll();
                                                    A.AfisareENL();
                                                    goto IesireConsoaneLow;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidModChLowerCon:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        IesireDinModChLowerCon:
                                                            textRevenire();
                                                            optiune=getch();
                                                            switch(optiune)
                                                            {
                                                            case 48:
                                                                goto MeniuPrincipal;
                                                                break;
                                                            case 61:
                                                                goto meniuModChLowerCon;
                                                                break;
                                                            default:
                                                                goto invalidModChLowerCon;
                                                                break;
                                                            }
                                                            break;
                                                }
                                            }
                                            break;
                                    }

                                default:
                                    {
                                        invalidModLowCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,WHITE);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChLower;
                                                break;
                                            default:
                                                {
                                                    clearScreen();
                                                    goto invalidModLowCh;
                                                    break;
                                                }
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 50:
                        {
                            //marire ch
                            meniuModChUp:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa mariti:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un numar specific de aparitii\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Vocale\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Consoane\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuMod;
                                    break;
                                case 49:
                                    {
                                        //nr aparitii;
                                        meniuModChUpAp:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa mariti:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate caracterele\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChUp;
                                                break;
                                            case 49:
                                                {
                                                    meniuModChUpAp1:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa mariti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primul caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Prima aparitie a unui caracter specific\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseUpFirstCh();
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //1st dat ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"Va rugam sa introduceti caracterul care urmeaza sa fie marit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>litera;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseUpFirstSpecificCh(litera);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModChUpAp1:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpAp1;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpAp1;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuModChUpAp2:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa mariti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale unui caracter\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st N
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti cate caractere doriti sa fie marite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                A.CaseUpFirstNCh(n);
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //1st n ch date
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti cate caractere doriti sa fie marite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                cin.get();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul care urmeaza sa fie marit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>litera;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                A.CaseUpFirstNChDate(litera,n);
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModChUpAp2:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpAp2;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpAp2;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 51:
                                                {
                                                    meniuModChUpAp3:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa mariti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimul caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultima aparitie a unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //last ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseUpLastCh();
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last ch dat
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"Va rugam sa introduceti caracterul care urmeaza sa fie marit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>litera;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.CaseUpLastDatCh(litera);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModChUpAp3:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpAp3;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpAp3;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 52:
                                                {
                                                    meniuModChUpAp4:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa mariti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N apariti ale unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //last n ch
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti cate caractere doriti sa fie marite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                A.CaseUpLastNCh(n);
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last n ch date
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti cate caractere doriti sa fie marite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                cin.get();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul care urmeaza sa fie marit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>litera;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                A.CaseUpLastNChDate(litera,n);
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                goto IesireModChUpAp;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModChUpAp4:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpAp4;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpAp4;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 53:
                                                {
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpAll();
                                                    A.AfisareENL();
                                                    IesireModChUpAp:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        default:
                                                            {
                                                                invalidIesireModChUpAp:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpAp;
                                                                        break;
                                                                    default:
                                                                        goto invalidIesireModChUpAp;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidModChUpAp:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpAp;
                                                            break;
                                                        default:
                                                            goto invalidModChUpAp;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        //vocale
                                        meniuModChUpVoc:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa mariti:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima vocala\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima vocala\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate vocalele\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChUp;
                                                break;
                                            case 49:
                                                {
                                                    //1st voc;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpVocaleFirst();
                                                    A.AfisareENL();
                                                    goto IesireDinModChUpVoc;
                                                    break;
                                                }
                                            case 50:
                                                {
                                                    //1st n voc;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de vocale care urmeaza sa fie marite: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpVocaleFirstN(n);
                                                    A.AfisareENL();
                                                    IesireDinModChUpVoc:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpVoc;
                                                            break;
                                                        default:
                                                            {
                                                                invalidModChUpVoc2:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpVoc;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpVoc2;
                                                                        break;
                                                                    }
                                                            }
                                                        }
                                                    break;
                                                }
                                            case 51:
                                                {
                                                    //last voc;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpVocaleLast();
                                                    A.AfisareENL();
                                                    goto IesireDinModChUpVoc;
                                                    break;
                                                }
                                            case 52:
                                                {
                                                    //last N voc;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de vocale care urmeaza sa fie marite: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpVocaleLastN(n);
                                                    A.AfisareENL();
                                                    goto IesireDinModChUpVoc;
                                                    break;
                                                }
                                            case 53:
                                                {
                                                    //all voc
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpVocaleAll();
                                                    A.AfisareENL();
                                                    goto IesireDinModChUpVoc;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidModChUpVoc:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpVoc;
                                                            break;
                                                        default:
                                                            goto invalidModChUpVoc;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        //consoane
                                        meniuModChUpCon:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa mariti:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima consoana\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima consoana\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate consoanele\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChUp;
                                                break;
                                            case 49:
                                                {
                                                    //prima consoana;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpConsoaneFirst();
                                                    A.AfisareENL();
                                                    IesireModChUpVoc:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpCon;
                                                            break;
                                                        default:
                                                            {
                                                                invalidModChUpApCon:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModChUpCon;
                                                                        break;
                                                                    default:
                                                                        goto invalidModChUpApCon;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                                                    case 50:
                                                                        {
                                                                            //primele n consoane;
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti numarul de consoane care urmeaza sa fie marite: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoatra dupa modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.CaseUpconsoaneFirstN(n);
                                                                            A.AfisareENL();
                                                                            goto IesireModChUpVoc;
                                                                            break;
                                                                        }
                                                                    case 51:
                                                                        {
                                                                            //ultima consoana
                                                                            clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpConsoaneLast();
                                                    A.AfisareENL();
                                                    goto IesireModChUpVoc;
                                                    break;
                                                                        }
                                                                    case 52:
                                                                        {
                                                                            //ultimele n consoane
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti numarul de consoane care urmeaza sa fie marite: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoatra dupa modificari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.CaseUpConsoaneLastN(-n);
                                                                            A.AfisareENL();
                                                                            goto IesireModChUpVoc;
                                                                            break;
                                                                        }
                                                                    case 53:
                                                                        {
                                                                            //toate consoanele;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.CaseUpConsoaneAll();
                                                    A.AfisareENL();
                                                    goto IesireModChUpVoc;
                                                    break;
                                                                        }
                                            default:
                                                {
                                                    invalidModChUpCon:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModChUpCon;
                                                            break;
                                                        default:
                                                            goto invalidModChUpCon;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidModChUp:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModChUp;
                                                break;
                                            default:
                                                goto invalidModChUp;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 51:
                        {
                            //micsorare siruri
                            meniuModStringLower:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa micsorati:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Prima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Primele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"4. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultimele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"5. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Toate aparitiile ale unui sir de caractere\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuMod;
                                    break;
                                case 49:
                                    {
                                        //1st string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie micsorat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseLowerStringFirst(in);
                                        A.AfisareENL();
                                        IesireDinModStringLower:
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModStringLower;
                                                break;
                                            default:
                                                {
                                                    invalidModChStringLower2:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModStringLower;
                                                            break;
                                                        default:
                                                            goto invalidModChStringLower2;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                        break;
                                    }
                                case 50:
                                    {
                                        //1st n strings
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie micsorat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti numarul de aparitii ale sirului care urmeaza sa fie micsorate: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseLowerStringFirstN(in,n);
                                        A.AfisareENL();
                                        goto IesireDinModStringLower;
                                        break;
                                    }
                                case 51:
                                    {
                                        //last string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie micsorat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseLowerStringLast(in);
                                        A.AfisareENL();
                                        goto IesireDinModStringLower;
                                        break;
                                    }
                                case 52:
                                    {
                                        //last n strings
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie micsorat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti numarul de aparitii ale sirului care urmeaza sa fie micsorate: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseLowerStringLastN(in,n);
                                        A.AfisareENL();
                                        goto IesireDinModStringLower;
                                        break;
                                    }
                                case 53:
                                    {
                                        //all strings;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie micsorat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseLowerStringAll(in);
                                        A.AfisareENL();
                                        goto IesireDinModStringLower;
                                        break;
                                    }
                                default:
                                    {
                                        invalidModStringL:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModStringLower;
                                                break;
                                            default:
                                                goto invalidModStringL;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 52:
                        {
                            //marire siruri
                            meniuModStringUp:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa mariti:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Prima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Primele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"4. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultimele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"5. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Toate aparitiile ale unui sir de caractere\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuMod;
                                    break;
                                case 49:
                                    {
                                        //1st string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie marit:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseUpStringFirst(in);
                                        A.AfisareENL();
                                        iesireModStringUp:
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModStringUp;
                                                break;
                                            default:
                                                {
                                                    invalidModStringUp10:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModStringUp;
                                                            break;
                                                        default:
                                                            goto invalidModStringUp10;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                        break;
                                    }
                                case 50:
                                    {
                                        //1st n strings;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie marit:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"\n\n Va rugam sa introduceti numarul de aparitii ale sirului care vor fi marite: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseUpStringFirstN(in,n);
                                        A.AfisareENL();
                                        goto iesireModStringUp;
                                        break;
                                    }
                                case 51:
                                    {
                                        //last string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie marit:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseUpStringLast(in);
                                        A.AfisareENL();
                                        goto iesireModStringUp;
                                        break;
                                    }
                                case 52:
                                    {
                                        //last n strings
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie marit:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"\n\n Va rugam sa introduceti numarul de aparitii ale sirului care vor fi marite: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseUpStringLastN(in,n);
                                        A.AfisareENL();
                                        goto iesireModStringUp;
                                        break;
                                    }
                                case 53:
                                    {
                                        //all strings;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie marit:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\nSirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.CaseUpStringAll(in);
                                        A.AfisareENL();
                                        goto iesireModStringUp;
                                        break;
                                    }
                                default:
                                    {
                                        invalidModStringUp:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuModStringUp;
                                                break;
                                            default:
                                                goto invalidModStringUp;
                                                break;
                                            }
                                            break;
                                    }

                                }
                                break;
                        }
                    case 53:
                        {
                            //inlocuire;
                            meniuReplace:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Inlocuti un caracter\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Inlocuiti un sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Cenzurati un sir de caractere\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto MeniuPrincipal;
                                    break;
                                case 49:
                                    {
                                        meniuModReplaceCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa inlocuiti caracterul cu un:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Sir de caractere\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuReplace;
                                                break;
                                            case 49:
                                                {
                                                    //ChToCh
                                                    meniuModReplaceChtoCh:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"Doriti sa inlocuiti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale caracterului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N aparitii ale caracterului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Toate aparitiile caracterului\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st N;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti caracterul cu care doriti sa il inlocuiti pe cel anterior: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToChFirstN(lin,lout,n);
                                                                A.AfisareENL();
                                                                iesireModReplaceChToCh:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceChtoCh;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidModReplaceChtoCh10:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuModReplaceChtoCh;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidModReplaceChtoCh10;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last N;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti caracterul cu care doriti sa il inlocuiti pe cel anterior: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToChLastN(lin,lout,n);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceChToCh;
                                                                break;
                                                            }
                                                        case 51:
                                                            {
                                                                //all
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti caracterul cu care doriti sa il inlocuiti pe cel anterior: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToChAll(lin,lout);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceChToCh;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModReplaceChToCh:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceChtoCh;
                                                                        break;
                                                                    default:
                                                                        goto invalidModReplaceChToCh;
                                                                        break;
                                                                    }
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //ChToStr
                                                    meniuModReplaceChToString:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"Doriti sa inlocuiti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale caracterului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N aparitii ale caracterului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Toate aparitiile caracterului\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st n ch;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care va fi inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul de caractere care va inlocui caracterul anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari: \n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToStringFirstN(in,lout,n);
                                                                A.AfisareENL();
                                                                iesireModReplaceChToString10:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceChToString;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidModReplaceChToString:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuModReplaceChToString;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidModReplaceChToString;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last n ch;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care va fi inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul de caractere care va inlocui caracterul anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari: \n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToStringLastN(in,lout,n);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceChToString10;
                                                                break;
                                                            }
                                                        case 51:
                                                            {
                                                                //all
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care va fi inlocuit: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul de caractere care va inlocui caracterul anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari: \n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceChToStringAll(in,lout);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceChToString10;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModReplaceChToString11:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceChToString;
                                                                        break;
                                                                    default:
                                                                        goto invalidModReplaceChToString11;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidModReplaceChCh:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceCh;
                                                            break;
                                                        default:
                                                            goto invalidModReplaceChCh;
                                                            break;
                                                        }
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        meniuModReplaceString:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa inlocuiti sirul de caractere cu:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Sir de caractere\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuReplace;
                                                break;
                                            case 49:
                                                {
                                                    //StrToCh
                                                    meniuModReplaceStringToCh:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa inlocuiti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale sirului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N aparitii ale sirului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Toate aparitiile sirului\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceString;
                                                            break;
                                                        case 49:
                                                            {
                                                                //primele n;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere pe care doriti sa-l inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul care va inlocui sirul: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cout<<n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToChFirstN(lin,out,n);
                                                                A.AfisareENL();
                                                                iesireModReplaceStringToCh:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceStringToCh;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidModReplaceStringToCh10:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuModReplaceStringToCh;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidModReplaceStringToCh10;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //ultimele n
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere pe care doriti sa-l inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul care va inlocui sirul: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cout<<n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToChLastN(lin,out,n);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceStringToCh;
                                                                break;
                                                            }
                                                        case 51:
                                                            {
                                                                //all
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere pe care doriti sa-l inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul care va inlocui sirul: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToChAll(lin,out);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceStringToCh;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModReplaceStringToCh101:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceStringToCh;
                                                                        break;
                                                                    default:
                                                                        goto invalidModReplaceStringToCh101;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                }
                                            case 50:
                                                {
                                                    //StrToStr
                                                    meniuModReplaceStringToString:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa inlocuiti:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale sirului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N aparitii ale sirului\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Toate aparitiile sirului\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceString;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st n str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul pe care doriti sa il inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul care il va inlocui pe cel anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToStringFirstN(in,out,n);
                                                                A.AfisareENL();
                                                                iesireModReplaceStringToString10:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceStringToString;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidModReplaceStringToString100:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va Rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuModReplaceStringToString;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidModReplaceStringToString100;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;

                                                            }
                                                        case 50:
                                                            {
                                                                //last n str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul pe care doriti sa il inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul care il va inlocui pe cel anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de aparitii care vor fi inlocuite: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToStringLastN(in,out,n);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceStringToString10;
                                                                break;
                                                            }
                                                        case 51:
                                                            {
                                                                //all str;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul pe care doriti sa il inlocuiti:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul care il va inlocui pe cel anterior:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.ReplaceStringToStringAll(in,out);
                                                                A.AfisareENL();
                                                                goto iesireModReplaceStringToString10;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidModReplaceStringToString:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuModReplaceStringToString;
                                                                        break;
                                                                    default:
                                                                        goto invalidModReplaceStringToString;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidModReplaceString:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuModReplaceString;
                                                            break;
                                                        default:
                                                            goto invalidModReplaceString;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        //cenzura;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul care urmeaza sa fie cenzurat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa modificari:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.Censor(in);
                                        A.AfisareENL();
                                        textRevenire();
                                        optiune=getch();
                                        switch(optiune)
                                        {
                                        case 48:
                                            goto MeniuPrincipal;
                                            break;
                                        case 61:
                                            goto meniuReplace;
                                            break;
                                        default:
                                            goto invalidModReplace;
                                            break;
                                        }
                                        break;
                                    }
                                default:
                                    {
                                        invalidModReplace:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuReplace;
                                                break;
                                            default:
                                                goto invalidModReplace;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }

                    }
                    break;
            }
        case 51:
            {
                //inserari
                meniuAdd:
                    clearScreen();
                    SetConsoleTextAttribute(colour,GREEN);
                    cout<<" Doriti sa adaugati:\n\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"1. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Intr-o pozitie specifica\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"2. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Un caracter\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"3. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Un sir de caractere\n";
                    textRevenire();
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        goto MeniuPrincipal;
                        break;
                    case 61:
                        goto MeniuPrincipal;
                        break;
                    case 49:
                        {
                            //anumita poz
                            meniuAddPoz:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa adaugati:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"La inceputul sirului\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"La sfarsitul sirului\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Intr-o anumita pozitie\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuAdd;
                                    break;
                                case 49:
                                    {
                                        //inceput
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        B.readKB();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de adaugare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa adaugare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AddToBeginning(B);
                                        A.AfisareENL();
                                        iesireAddPozI:
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                           case 48:
                                            goto MeniuPrincipal;
                                            break;
                                           case 61:
                                            goto meniuAddPoz;
                                            break;
                                           default:
                                            {
                                                invalidAddPozI:
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,RED);
                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                    textRevenire();
                                                    optiune=getch();
                                                    switch(optiune)
                                                    {
                                                    case 48:
                                                        goto MeniuPrincipal;
                                                        break;
                                                    case 61:
                                                        goto meniuAddPoz;
                                                        break;
                                                    default:
                                                        goto invalidAddPozI;
                                                        break;
                                                    }
                                                    break;
                                            }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        //sfarsit
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        B.readKB();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de adaugare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa adaugare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AddToEnding(B);
                                        A.AfisareENL();
                                        goto iesireAddPozI;
                                        break;
                                    }
                                case 51:
                                    {
                                        //poz;
                                        meniuAddPozPoz:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Un caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Un sir de caractere\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddPoz;
                                                break;
                                            case 49:
                                                {
                                                    //add ch
                                                    Ok=0;
                                                    WrongDim:
                                                        clearScreen();
                                                        if(Ok || !Ok)
                                                        {
                                                            SetConsoleTextAttribute(colour,GREEN);
                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                            cin>>lin;
                                                        }
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"\n\n\n Va rugam sa introduceti pozitia pe care va fi introdus caracterul: ";
                                                        SetConsoleTextAttribute(colour,PURPLE);
                                                        cin>>n;
                                                        cin.get();
                                                        if(n>A.getDim() && n>=0)
                                                        {
                                                            clearScreen();
                                                            Ok=1-Ok;
                                                            SetConsoleTextAttribute(colour,RED);
                                                            cout<<"Valoare invalida. Va rugam sa introduceti o valoare pozitiva mai mica decat lungimea sirului.\n";
                                                            SetConsoleTextAttribute(colour,DWHITE);
                                                            cout<<"\nApasati orice tasta pentru a reveni.\n";
                                                            getch();
                                                            goto WrongDim;
                                                        }
                                                        SetConsoleTextAttribute(colour,GRAY);
                                                        cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                        SetConsoleTextAttribute(colour,RED);
                                                        A.AfisareENL();
                                                        SetConsoleTextAttribute(colour,GRAY);
                                                        cout<<"\n\n Sirul dumneavostra dupa adaugari:\n";
                                                        SetConsoleTextAttribute(colour,RED);
                                                        A.AddChToPozDat(lin,n);
                                                        A.AfisareENL();
                                                        iesireAddPoz:
                                                            textRevenire();
                                                            optiune=getch();
                                                            switch(optiune)
                                                            {
                                                            case 48:
                                                                goto MeniuPrincipal;
                                                                break;
                                                            case 61:
                                                                goto meniuAddPozPoz;
                                                                break;
                                                            default:
                                                                {
                                                                    invalidAddPozPozPozPoz:
                                                                        clearScreen();
                                                                        SetConsoleTextAttribute(colour,RED);
                                                                        cout<<"Comanda invaida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                        textRevenire();
                                                                        optiune=getch();
                                                                        switch(optiune)
                                                                        {
                                                                        case 48:
                                                                            goto MeniuPrincipal;
                                                                            break;
                                                                        case 61:
                                                                            goto meniuAddPozPoz;
                                                                            break;
                                                                        default:
                                                                            goto invalidAddPozPozPozPoz;
                                                                            break;
                                                                        }
                                                                        break;
                                                                }
                                                            }
                                                            break;
                                                }
                                            case 50:
                                                {
                                                    //add str
                                                    Ok2=0;
                                                    WrongDim2:
                                                        clearScreen();
                                                        if(Ok2)
                                                        {
                                                            SetConsoleTextAttribute(colour,GREEN);
                                                            cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                            cin.getline(in,100000);
                                                        }
                                                        else
                                                        {
                                                            SetConsoleTextAttribute(colour,GREEN);
                                                            cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                            cin.getline(in,100000);
                                                        }
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<"\n\n Va rugam sa introduceti pozitia pe care va fi introdus sirul de caractere: ";
                                                        SetConsoleTextAttribute(colour,PURPLE);
                                                        cin>>n;
                                                        cin.get();
                                                        if(n>A.getDim() && n>=0)
                                                        {
                                                            clearScreen();
                                                            Ok2=1-Ok2;
                                                            SetConsoleTextAttribute(colour,RED);
                                                            cout<<"Valoare invalida. Va rugam sa introduceti o valoare pozitiva mai mica decat lungimea sirului.\n\n";
                                                            SetConsoleTextAttribute(colour,DWHITE);
                                                            cout<<"Apasati orice tasta pentru a reveni.\n";
                                                            getch();
                                                            goto WrongDim2;
                                                        }
                                                        SetConsoleTextAttribute(colour,GRAY);
                                                        cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                        SetConsoleTextAttribute(colour,RED);
                                                        A.AfisareENL();
                                                        SetConsoleTextAttribute(colour,GRAY);
                                                        cout<<"\n\n Sirul dumneavostra dupa adaugari:\n";
                                                        SetConsoleTextAttribute(colour,RED);
                                                        A.AddStringToPozDat(in,n);
                                                        A.AfisareENL();
                                                        goto iesireAddPoz;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidAddPozPoz:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddPozPoz;
                                                            break;
                                                        default:
                                                            goto invalidAddPozPoz;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidAddPoz:
                                            clearScreen();
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddPoz;
                                                break;
                                            default:
                                                goto invalidAddPoz;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 50:
                        {
                            //ch
                            meniuAddCh:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa adaugati un caracter in functie de:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un caracter\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un anumit pas\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuAdd;
                                    break;
                                case 49:
                                    {
                                        meniuAddChCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati caracterul:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea unui anumit caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa un anumit caracter\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddCh;
                                                break;
                                            case 49:
                                                {
                                                    //inainte
                                                    meniuAddChChBefore:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati caracterul inaintea:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Unui caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Unei vocale\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Unei consoane\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                meniuAddChChBeforeCh:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul inaintea:\n\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"A primelor N aparitii ale unui caracter\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"A tuturor aparitiilor ale unui caracter\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChBefore;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //1st N
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti caracterul inaintea caruia se face adaugarea: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lout;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rumga sa introduceti numarul de adaugari ale caracterului: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugare:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugare:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeChN(lin,lout,n);
                                                                            A.AfisareENL();
                                                                            iesireChChBeforeChN:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeCh;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChBeforeChN:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChBeforeCh;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChBeforeChN;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //all
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti caracterul inaintea caruia se face adaugarea: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lout;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugare:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugare:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeChAll(lin,lout);
                                                                            A.AfisareENL();
                                                                            goto iesireChChBeforeChN;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChBeforeCh:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeCh;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChBeforeCh;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                meniuAddChChBeforeVoc:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul inaintea:\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1 .";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Primelor N vocale\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Tuturor vocalelor\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChBefore;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //1st n vowels
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeVocaleN(lin,n);
                                                                            A.AfisareENL();
                                                                            iesireAddChChBeforeVoc:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeVoc;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChBeforeVocVoc:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChBeforeVoc;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChBeforeVocVoc;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //all vowels
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeVocaleAll(lin);
                                                                            A.AfisareENL();
                                                                            goto iesireAddChChBeforeVoc;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChBeforeVoc:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeVoc;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChBeforeVoc;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 51:
                                                            {
                                                                meniuAddChChBeforeCon:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul inaintea:\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1 .";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Primelor N consoane\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Tuturor consoanelor\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChBefore;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //1st n cons;
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeConsoaneN(lin,n);
                                                                            A.AfisareENL();
                                                                            iesireAddChChBeforeCon:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeCon;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChBeforeConCon:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChBeforeCon;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChBeforeConCon;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //all cons;
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChBeforeConsoaneAll(lin);
                                                                            A.AfisareENL();
                                                                            goto iesireAddChChBeforeCon;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChBeforeCon:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChBeforeCon;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChBeforeCon;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddChChBefore:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChBefore;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddChChBefore;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                }
                                            case 50:
                                                {
                                                    //dupa ch
                                                    meniuAddChChDupa:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati caracterul dupa:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Un caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"O vocala\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"3. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"O consoana\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                meniuAddChChDupaCh:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul dupa:\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Primele N aparitii ale unui caracter\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Toate aparitiile unui caracter\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChDupa;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //dupa N ch;
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lout;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaChFirstN(lin,lout,n);
                                                                            A.AfisareENL();
                                                                            iesireAddChChDupaCh:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaCh;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChDupaChCh:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChDupaCh;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChDupaChCh;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //dupa all ch
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lout;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaChAll(lin,lout);
                                                                            A.AfisareENL();
                                                                            goto iesireAddChChDupaCh;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChDupaCh:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaCh;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChDupaCh;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                meniuAddChChDupaVoc:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul dupa:\n\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Primele N vocale\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Toate vocalele\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChDupa;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //1st n vowels
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaVocaleN(lin,n);
                                                                            A.AfisareENL();
                                                                            iesireAddChChDupaVoc:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaVoc;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChDupaVocVoc:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChDupaVoc;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChDupaVocVoc;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //all vowels
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaVocaleAll(lin);
                                                                            A.AfisareENL();
                                                                            goto iesireAddChChDupaVoc;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChDupaVoc:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaVoc;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChDupaVoc;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 51:
                                                            {
                                                                meniuAddChChDupaCon:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,GREEN);
                                                                    cout<<" Doriti sa adaugati caracterul dupa:\n\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"1. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Primele N consoane\n";
                                                                    SetConsoleTextAttribute(colour,YELLOW);
                                                                    cout<<"2. ";
                                                                    SetConsoleTextAttribute(colour,DWHITE);
                                                                    cout<<"Toate consoanele\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChDupa;
                                                                        break;
                                                                    case 49:
                                                                        {
                                                                            //1st n con;
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>n;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaConsoaneN(lin,n);
                                                                            A.AfisareENL();
                                                                            iesireAddChChDupaCon:
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaCon;
                                                                                    break;
                                                                                default:
                                                                                    {
                                                                                        invalidAddChChDupaConCon:
                                                                                            clearScreen();
                                                                                            SetConsoleTextAttribute(colour,RED);
                                                                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                            textRevenire();
                                                                                            optiune=getch();
                                                                                            switch(optiune)
                                                                                            {
                                                                                            case 48:
                                                                                                goto MeniuPrincipal;
                                                                                                break;
                                                                                            case 61:
                                                                                                goto meniuAddChChDupaCon;
                                                                                                break;
                                                                                            default:
                                                                                                goto invalidAddChChDupaConCon;
                                                                                                break;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                                break;
                                                                        }
                                                                    case 50:
                                                                        {
                                                                            //all con
                                                                            clearScreen();
                                                                            SetConsoleTextAttribute(colour,GREEN);
                                                                            cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                            SetConsoleTextAttribute(colour,PURPLE);
                                                                            cin>>lin;
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AfisareENL();
                                                                            SetConsoleTextAttribute(colour,GRAY);
                                                                            cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                            SetConsoleTextAttribute(colour,RED);
                                                                            A.AddChDupaConsoaneAll(lin);
                                                                            A.AfisareENL();
                                                                            goto iesireAddChChDupaCon;
                                                                            break;
                                                                        }
                                                                    default:
                                                                        {
                                                                            invalidAddChChDupaCon:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChChDupaCon;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChChDupaCon;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddChChDupa:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChChDupa;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddChChDupa;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidAddChCh:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChCh;
                                                            break;
                                                        default:
                                                            goto invalidAddChCh;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        meniuAddChStr:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati caracterul:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea unui sir de caractere\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa un sir de caractere\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddCh;
                                                break;
                                            case 49:
                                                {
                                                    meniuAddChStrBefore:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati caracterul inaintea:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primelor N aparitii ale unui sir de caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Tuturor aparitiilor unui sir de caractere\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChStr;
                                                            break;
                                                        case 49:
                                                            {
                                                                //before N str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere inaintea caruia se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddChBeforeStringN(lin,out,n);
                                                                A.AfisareENL();
                                                                iesireAddChStrBeforeStr:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChStrBefore;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddChStrBeforeStr:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChStrBefore;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChStrBeforeStr;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //before all str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere inaintea caruia se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddChBeforeStringAll(lin,out);
                                                                A.AfisareENL();
                                                                goto iesireAddChStrBeforeStr;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddChStrBefore:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChStrBefore;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddChStrBefore;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuAddChStrDupa:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati un caracter dupa:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale unui sir de caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Toate aparitiile unui sir de caractere\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChStr;
                                                            break;
                                                        case  49:
                                                            {
                                                                //dupa N str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere dupa care se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddChDupaStringN(lin,out,n);
                                                                A.AfisareENL();
                                                                iesireAddChStrDupaStr:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChStrDupa;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddChStrDupaStrStr:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddChStrDupa;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddChStrDupaStrStr;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //dupa all str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere dupa care se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddChDupaStringAll(lin,out);
                                                                A.AfisareENL();
                                                                goto iesireAddChStrDupaStr;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddChStrDupa:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChStrDupa;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddChStrDupa;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidAddChStr:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invaida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChStr;
                                                            break;
                                                        default:
                                                            goto invalidAddChStr;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        meniuAddChPas:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati un caracter la un anumit pas:\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea carcterlui de pe pozitia pasului\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa caracterul de pe pozitia pasului\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddCh;
                                                break;
                                            case 49:
                                                {
                                                    //inainte pas
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>lin;
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"\n\n\n Va rugam sa introduceti pasul adaugarii: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AddChBeforePas(lin,n);
                                                    A.AfisareENL();
                                                    iesireAddChPas:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChPas;
                                                            break;
                                                        default:
                                                            {
                                                                invalidAddChPasPas:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddChPas;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddChPasPas;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //dupa pas
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie adaugat: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>lin;
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"\n\n\n Va rugam sa introduceti pasul adaugarii: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AddChDupaPasN(lin,n);
                                                    A.AfisareENL();
                                                    goto iesireAddChPas;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidAddChPas:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddChPas;
                                                            break;
                                                        default:
                                                            goto invalidAddChPas;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidAddCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                            textRevenire();optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddCh;
                                                break;
                                            default:
                                                goto invalidAddCh;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 51:
                        {
                            //str
                            meniuAddStr:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa adaugati un sir de caractere in functie de:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un caracter\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un anumit pas\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuAdd;
                                    break;
                                case 49:
                                    {
                                        meniuAddStrCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati un sir de caractere:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa un caracter\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddStr;
                                                break;
                                            case 49:
                                                {
                                                    meniuAddStrChBefore:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati un sir de caractere:\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Inaintea primelor N aparitii ale unui caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Inaintea tuturor aparitiilor unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                //inainte n str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti caracterul inaintea caruia urmeaza sa se faca adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringBeforeChN(in,lout,n);
                                                                A.AfisareENL();
                                                                iesireAddStrChBefore:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrChBefore;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddStrChBeforeQ:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddStrChBefore;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddStrChBeforeQ;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //inainte toate str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"Va rugam sa introduceti caracterul inaintea caruia urmeaza sa se faca adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringBeforeChAll(in,lout);
                                                                A.AfisareENL();
                                                                goto iesireAddStrChBefore;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddStrChBefore:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrChBefore;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddStrChBefore;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuAddStrChDupa:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati un sir de caractere:\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Dupa primele N aparitii ale unui caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Dupa toate aparitiilor unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrCh;
                                                            break;
                                                        case 49:
                                                            {
                                                                //dupa n ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul dupa care se va face adaugarea: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringDupaChN(in,lout,n);
                                                                A.AfisareENL();
                                                                iesireAddStrChDupaDupa:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrChDupa;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddStrChDupaDupa:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddStrChDupa;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddStrChDupaDupa;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //dupa all ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti caracterul dupa care se va face adaugarea: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringDupaChAll(in,lout);
                                                                A.AfisareENL();
                                                                goto iesireAddStrChDupaDupa;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddStrChDupa:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrChDupa;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddStrChDupa;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidAddStrCh:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrCh;
                                                            break;
                                                        default:
                                                            goto invalidAddStrCh;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        meniuAddStrStr:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati un sir de caractere:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea unui sir de caractere\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa un sir de caractere\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddStr;
                                                break;
                                            case 49:
                                                {
                                                    meniuAddStrStrBefore:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati sirul de caractere:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Inaintea primelor N aparitii ale unui sir de caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Inaintea tuturor aparitiilor unui sir de caractere\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrStr;
                                                            break;
                                                        case 49:
                                                            {
                                                                //before N strings
                                                                clearScreen();
                                                                cout<<" Va rugam sa introduceti sirul de caractere pe care doriti sa-l adaugati:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere inaintea caruia se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringBeforeStringN(in,out,n);
                                                                A.AfisareENL();
                                                                iesireAddStrStrBefore:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrStrBefore;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddStrStrBeforeStr:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddStrStrBefore;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddStrStrBeforeStr;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //before all strings;
                                                                clearScreen();
                                                                cout<<" Va rugam sa introduceti sirul de caractere pe care doriti sa-l adaugati:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti sirul de caractere inaintea caruia se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringBeforeStringAll(in,out);
                                                                A.AfisareENL();
                                                                goto iesireAddStrStrBefore;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddStrStrBefore:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrStrBefore;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddStrStrBefore;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuAddStrStrDupa:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa adaugati sirul de caractere:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Dupa primele N aparitii ale unui sir de caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Dupa toate aparitiilor unui sir de caractere\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrStr;
                                                            break;
                                                        case 49:
                                                            {
                                                                //dupa n str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul de caractere dupa care se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti numarul de adaugari: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringDupaStringN(in,out,n);
                                                                A.AfisareENL();
                                                                IesireAddStrStrDupaStr:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrStrDupa;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidAddStrStrDupaStr:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuAddStrStrDupa;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidAddStrStrDupaStr;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //dupa toate str
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(in,100000);
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n Va rugam sa introduceti sirul de caractere dupa care se va face adaugarea:\n";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin.getline(out,100000);
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AddStringDupaStringAll(in,out);
                                                                A.AfisareENL();
                                                                goto IesireAddStrStrDupaStr;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidAddStrStrDupa:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrStrDupa;
                                                                        break;
                                                                    default:
                                                                        goto invalidAddStrStrDupa;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidAddStrStr:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrStr;
                                                            break;
                                                        default:
                                                            goto invalidAddStrStr;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        meniuAddStrPas:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa adaugati sirul de caractere:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Inaintea caracterului care se afla pozitia pasului\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Dupa caracterul care se afla pe pozitia pasului\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddStr;
                                                break;
                                            case 49:
                                                {
                                                    //inainte
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin.getline(in,100000);
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"\n\n Va rugam sa introduceti pasul de adaugare: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AddStringBeforePas(in,n);
                                                    A.AfisareENL();
                                                    IesireStrPas:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrPas;
                                                            break;
                                                        default:
                                                            {
                                                                invalidIesirePas:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuAddStrPas;
                                                                        break;
                                                                    default:
                                                                        goto invalidIesirePas;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //dupa
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie adaugat:\n";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin.getline(in,100000);
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<"\n\n Va rugam sa introduceti pasul de adaugare: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa adaugari:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AddStringAfterPas(in,n);
                                                    A.AfisareENL();
                                                    goto IesireStrPas;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidAddStrPas:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuAddStrPas;
                                                            break;
                                                        default:
                                                            goto invalidAddStrPas;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidAddStr:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuAddStr;
                                                break;
                                            default:
                                                goto invalidAddStr;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    default:
                        {
                            invalidAdd:
                                clearScreen();
                                SetConsoleTextAttribute(colour,RED);
                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuAdd;
                                    break;
                                default:
                                    goto invalidAdd;
                                    break;
                                }
                                break;
                        }
                    }
                    break;
            }
        case 52:
            {
                //Eliminari
                meniuRemove:
                    clearScreen();
                    SetConsoleTextAttribute(colour,GREEN);
                    cout<<" Doriti sa eliminati:\n\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"1. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Un caracter\n";
                    SetConsoleTextAttribute(colour,YELLOW);
                    cout<<"2. ";
                    SetConsoleTextAttribute(colour,DWHITE);
                    cout<<"Un sir de caractere\n";
                    textRevenire();
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        goto MeniuPrincipal;
                        break;
                    case 61:
                        goto MeniuPrincipal;
                        break;
                    case 49:
                        {
                            meniuRemoveCh:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa eliminati:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Un anumit numar de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Vocale\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Consoane\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"4. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Alte tipuri de caractere\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuRemove;
                                    break;
                                case 49:
                                    {
                                        meniuRemoveChAp:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa eliminati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Prima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultima aparitie a unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"4. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N aparitii ale unui caracter\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"5. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate aparitiile unui caracter\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveCh;
                                                break;
                                            case 49:
                                                {
                                                    meniuRemoveChApF:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa eliminati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primul caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Prima aparitie a unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //el 1st ch;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveFirstCh();
                                                                A.AfisareENL();
                                                                IesireRemoveChApF:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApF;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidRemoveChApF1:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuRemoveChApF;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidRemoveChApF1;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //el 1st ch app;
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul a carui prima aparitie va fi eliminat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lin;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveChFirst(lin);
                                                                A.AfisareENL();
                                                                goto IesireRemoveChApF;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidRemoveChApF:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApF;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChApF;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    meniuRemoveChApFN:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa eliminati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Primele N aparitii ale unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //1st n ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti numarul de caractere care vor fi eliminate: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveFirstChN(n);
                                                                A.AfisareENL();
                                                                IesireRemoveChApFN:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApFN;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidRemoveChApFN1:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuRemoveChApFN;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidRemoveChApFN1;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                break;
                                                            }
                                                        case 50:
                                                            {
                                                                //1st n ch app
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie eliminat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti numarul de caractere care urmeaza sa fie eliminate: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveChFirstN(lout,n);
                                                                A.AfisareENL();
                                                                goto IesireRemoveChApFN;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidRemoveChApFN:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApFN;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChApFN;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 51:
                                                {
                                                    meniuRemoveChApL:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa eliminati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimul caracter\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultima aparitie a unui caracter\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //last ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveLastCh();
                                                                A.AfisareENL();
                                                                iesireRemoveChApL:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApL;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidRemoveChApLL:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuRemoveChApL;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidRemoveChApLL;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last ch app
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie eliminat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveChLast(lout);
                                                                A.AfisareENL();
                                                                goto iesireRemoveChApL;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidRemoveChApL:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApL;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChApL;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 52:
                                                {
                                                    meniuRemoveChApLN:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,GREEN);
                                                        cout<<" Doriti sa eliminati:\n\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"1. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N caractere\n";
                                                        SetConsoleTextAttribute(colour,YELLOW);
                                                        cout<<"2. ";
                                                        SetConsoleTextAttribute(colour,DWHITE);
                                                        cout<<"Ultimele N aparitii ale unui caracter\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        case 49:
                                                            {
                                                                //last n ch
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti numarul de caractere care urmeaza sa fie eliminate: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveLastChN(n);
                                                                A.AfisareENL();
                                                                iesireRemoveChApLN:
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApLN;
                                                                        break;
                                                                    default:
                                                                        {
                                                                            invalidRemoveChApLNN:
                                                                                clearScreen();
                                                                                SetConsoleTextAttribute(colour,RED);
                                                                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                                textRevenire();
                                                                                optiune=getch();
                                                                                switch(optiune)
                                                                                {
                                                                                case 48:
                                                                                    goto MeniuPrincipal;
                                                                                    break;
                                                                                case 61:
                                                                                    goto meniuRemoveChApLN;
                                                                                    break;
                                                                                default:
                                                                                    goto invalidRemoveChApLNN;
                                                                                    break;
                                                                                }
                                                                                break;
                                                                        }
                                                                    }
                                                                    break;
                                                            }
                                                        case 50:
                                                            {
                                                                //last n ch app
                                                                clearScreen();
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie eliminat: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>lout;
                                                                SetConsoleTextAttribute(colour,GREEN);
                                                                cout<<"\n\n\n Va rugam sa introduceti numarul de caractere care urmeaza sa fie eliminate: ";
                                                                SetConsoleTextAttribute(colour,PURPLE);
                                                                cin>>n;
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.AfisareENL();
                                                                SetConsoleTextAttribute(colour,GRAY);
                                                                cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                                SetConsoleTextAttribute(colour,RED);
                                                                A.RemoveChLastN(lout,n);
                                                                A.AfisareENL();
                                                                goto iesireRemoveChApLN;
                                                                break;
                                                            }
                                                        default:
                                                            {
                                                                invalidRemoveChApLN:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChApLN;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChApLN;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 53:
                                                {
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti caracterul care urmeaza sa fie eliminat: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>lout;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveChAll(lout);
                                                    A.AfisareENL();
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        default:
                                                            {
                                                                invalidRemoveChApAll:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChAp;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChApAll;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidRemoveChApAp:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAp;
                                                            break;
                                                        default:
                                                            goto invalidRemoveChApAp;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        meniuRemoveChVoc:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa eliminati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N aparitii ale unui vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N aparitii ale unui vocale\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate vocalele\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveCh;
                                                break;
                                            case 49:
                                                {
                                                    //1st n voc
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de vocale care urmeaza sa fie eliminate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveVocaleFirstN(n);
                                                    A.AfisareENL();
                                                    goto iesireRemoveChVoc;
                                                    break;
                                                }
                                            case 50:
                                                {
                                                    //last n voc
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de vocale care urmeaza sa fie eliminate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveVocaleLastN(n);
                                                    A.AfisareENL();
                                                    goto iesireRemoveChVoc;
                                                    break;
                                                }
                                            case 51:
                                                {
                                                    //all voc;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveVocaleAll();
                                                    A.AfisareENL();
                                                    iesireRemoveChVoc:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChVoc;
                                                            break;
                                                        default:
                                                            {
                                                                invalidRemoveChVocV:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda valida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChVoc;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChVocV;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            default:
                                                {
                                                    invalidRemoveChVoc:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChVoc;
                                                            break;
                                                        default:
                                                            goto invalidRemoveChVoc;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 51:
                                    {
                                        meniuRemoveChCon:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa eliminati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Primele N aparitii ale unui consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Ultimele N aparitii ale unui consoane\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"3. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate consoanele\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveCh;
                                                break;
                                            case 49:
                                                {
                                                    //1st n con
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de consoane care urmeaza sa fie eliminate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveConsoaneFirstN(n);
                                                    A.AfisareENL();
                                                    iesireRemoveChCon:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChCon;
                                                            break;
                                                        default:
                                                            {
                                                                invalidRemoveChConCon:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda valida. Va rugam sa introduceti o comanda valida.\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChCon;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChConCon;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //last n con;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GREEN);
                                                    cout<<" Va rugam sa introduceti numarul de consoane care urmeaza sa fie eliminate: ";
                                                    SetConsoleTextAttribute(colour,PURPLE);
                                                    cin>>n;
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveConsoaneLastN(n);
                                                    A.AfisareENL();
                                                    goto iesireRemoveChCon;
                                                    break;
                                                }
                                            case 51:
                                                {
                                                    //all cons;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveConsoaneAll();
                                                    A.AfisareENL();
                                                    goto iesireRemoveChCon;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidRemoveChCon:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChCon;
                                                            break;
                                                        default:
                                                            goto invalidRemoveChCon;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 52:
                                    {
                                        meniuRemoveChAltele:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,GREEN);
                                            cout<<" Doriti sa eliminati:\n\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"1. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Spatiile redundante\n";
                                            SetConsoleTextAttribute(colour,YELLOW);
                                            cout<<"2. ";
                                            SetConsoleTextAttribute(colour,DWHITE);
                                            cout<<"Toate simbolurile\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveCh;
                                                break;
                                            case 49:
                                                {
                                                    //spatii redundante;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveRedundantSpaces();
                                                    A.AfisareENL();
                                                    IesireRemoveChAltele:
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAltele;
                                                            break;
                                                        default:
                                                            {
                                                                invalidRemoveChAlteleRS:
                                                                    clearScreen();
                                                                    SetConsoleTextAttribute(colour,RED);
                                                                    cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                                    textRevenire();
                                                                    optiune=getch();
                                                                    switch(optiune)
                                                                    {
                                                                    case 48:
                                                                        goto MeniuPrincipal;
                                                                        break;
                                                                    case 61:
                                                                        goto meniuRemoveChAltele;
                                                                        break;
                                                                    default:
                                                                        goto invalidRemoveChAlteleRS;
                                                                        break;
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        break;
                                                }
                                            case 50:
                                                {
                                                    //toate simbolurile;
                                                    clearScreen();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<" Sirul dumneavoastra inainte de eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.AfisareENL();
                                                    SetConsoleTextAttribute(colour,GRAY);
                                                    cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                                    SetConsoleTextAttribute(colour,RED);
                                                    A.RemoveSymbols();
                                                    A.AfisareENL();
                                                    goto IesireRemoveChAltele;
                                                    break;
                                                }
                                            default:
                                                {
                                                    invalidRemoveAltele:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda valida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveChAltele;
                                                            break;
                                                        default:
                                                            goto invalidRemoveAltele;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                default:
                                    {
                                        invalidRemoveCh:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveCh;
                                                break;
                                            default:
                                                goto invalidRemoveCh;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    case 50:
                        {
                            meniuRemoveString:
                                clearScreen();
                                SetConsoleTextAttribute(colour,GREEN);
                                cout<<" Doriti sa eliminati:\n\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"1. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Prima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"2. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Primele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"3. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultima aparitie a unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"4. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Ultimele N aparitii ale unui sir de caractere\n";
                                SetConsoleTextAttribute(colour,YELLOW);
                                cout<<"5. ";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Toate aparitiile ale unui sir de caractere\n\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuRemove;
                                    break;
                                case 49:
                                    {
                                        //1st string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie eliminat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.RemoveStringFirst(in);
                                        A.AfisareENL();
                                        iesireRemoveString:
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveString;
                                                break;
                                            default:
                                                {
                                                    invalidRemoveString1:
                                                        clearScreen();
                                                        SetConsoleTextAttribute(colour,RED);
                                                        cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                                        textRevenire();
                                                        optiune=getch();
                                                        switch(optiune)
                                                        {
                                                        case 48:
                                                            goto MeniuPrincipal;
                                                            break;
                                                        case 61:
                                                            goto meniuRemoveString;
                                                            break;
                                                        default:
                                                            goto invalidRemoveString1;
                                                            break;
                                                        }
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                case 50:
                                    {
                                        //1st n strings
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti numarul de aparitii care urmeaza sa fie eliminate: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        cin.get();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"\n\n\n Va rugam sa introduceti sirul de caractere care urmeaza sa fie eliminat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.RemoveStringFirstN(in,n);
                                        A.AfisareENL();
                                        goto iesireRemoveString;
                                        break;
                                    }
                                case 51:
                                    {
                                        //last string
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie eliminat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.RemoveStringLast(in);
                                        A.AfisareENL();
                                        goto iesireRemoveString;
                                        break;
                                    }
                                case 52:
                                    {
                                        //last n strings;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti numarul de aparitii care urmeaza sa fie eliminate: ";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin>>n;
                                        cin.get();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<"\n\n\n Va rugam sa introduceti sirul de caractere care urmeaza sa fie eliminat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.RemoveStringLastN(in,n);
                                        A.AfisareENL();
                                        goto iesireRemoveString;
                                        break;
                                    }
                                case 53:
                                    {
                                        //all strings;
                                        clearScreen();
                                        SetConsoleTextAttribute(colour,GREEN);
                                        cout<<" Va rugam sa introduceti sirul de caractere care urmeaza sa fie eliminat:\n";
                                        SetConsoleTextAttribute(colour,PURPLE);
                                        cin.getline(in,100000);
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra inainte de eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.AfisareENL();
                                        SetConsoleTextAttribute(colour,GRAY);
                                        cout<<"\n\n Sirul dumneavoastra dupa eliminare:\n";
                                        SetConsoleTextAttribute(colour,RED);
                                        A.RemoveStringAll(in);
                                        A.AfisareENL();
                                        goto iesireRemoveString;
                                        break;
                                    }
                                default:
                                    {
                                        invalidRemoveString:
                                            clearScreen();
                                            SetConsoleTextAttribute(colour,RED);
                                            cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida\n\n";
                                            textRevenire();
                                            optiune=getch();
                                            switch(optiune)
                                            {
                                            case 48:
                                                goto MeniuPrincipal;
                                                break;
                                            case 61:
                                                goto meniuRemoveString;
                                                break;
                                            default:
                                                goto invalidRemoveString;
                                                break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                    default:
                        {
                            invalidRemove:
                                clearScreen();
                                SetConsoleTextAttribute(colour,RED);
                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                textRevenire();
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                case 61:
                                    goto meniuRemove;
                                    break;
                                default:
                                    goto invalidRemove;
                                    break;
                                }
                                break;
                        }
                    }
            }
        case 53:
            {
                //revenire la meniu de creare
                clearScreen();
                goto MeniuCreareSir;
                break;
            }
        case 54:
            {
                //parasirea programului
                SetConsoleTextAttribute(colour,WHITE);
                clearScreen();
                return 0;
            }
        case 45:
            {
                //informatii;
                infoScreen:
                    clearScreen();
                    SetConsoleTextAttribute(colour,RED);
                    cout<<"Despre ce optiune doriti sa aflati mai multe?\n\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"1. ";
                    SetConsoleTextAttribute(colour,DRED);
                    cout<<"Operatii pe sir\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"2. ";
                    SetConsoleTextAttribute(colour,DRED);
                    cout<<"Modificari asupra sirului\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"3. ";
                    SetConsoleTextAttribute(colour,DRED);
                    cout<<"Inserari\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"4. ";
                    SetConsoleTextAttribute(colour,DRED);
                    cout<<"Eliminari\n\n\n";
                    SetConsoleTextAttribute(colour,GRAY);
                    cout<<"Puteti reveni la meniul principal apasand tasta: ";
                    SetConsoleTextAttribute(colour,PURPLE);
                    cout<<"0\n\n\n";
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        {
                            outInfo:
                                clearScreen();
                                goto MeniuPrincipal;
                                break;
                        }
                    case 49:
                        {
                            //info operatii pe sir
                            clearScreen();
                            SetConsoleTextAttribute(colour,GREEN);
                            cout<<"   Aceasta sectiune contine functii de:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            cout<<" - obtinere a informatiilor despre sir, precum dimensiunea sau compozitia sa\n";
                            cout<<" - copiere a altor siruri in sirul dumneavoastra\n";
                            cout<<" - concatenare\n";
                            cout<<" - inversare a sirului dumneavoastra\n";
                            cout<<" - criptare si de decriptare a sirului dumnavoastra\n\n\n";

                            iesireInfo:
                                SetConsoleTextAttribute(colour,WHITE);
                                cout<<"Pentru a reveni in meniul de informatii, apasati tasta: ";
                                SetConsoleTextAttribute(colour,PURPLE);
                                cout<<"=\n";
                                SetConsoleTextAttribute(colour,WHITE);
                                cout<<"Pentru a reveni in meniul principal, apasati tasta: ";
                                SetConsoleTextAttribute(colour,PURPLE);
                                cout<<"0\n\n";
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    {
                                        clearScreen();
                                        goto MeniuPrincipal;
                                        break;
                                    }
                                case 61:
                                    {
                                        clearScreen();
                                        goto infoScreen;
                                        break;
                                    }
                                default:
                                    {
                                        goto InvalidInfo;
                                        break;
                                    }
                                }
                            break;
                        }
                    case 50:
                        {
                            //info modificari pe sir
                            clearScreen();
                            SetConsoleTextAttribute(colour,GREEN);
                            cout<<"   Aceasta sectiune contine functii de:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            cout<<" - marire a unui caracter sau a unui sir de caractere din sirul dumneavoastra\n";
                            cout<<" - micsorare a unui caracter sau a unui sir de caractere din sirul dumneavoastra\n";
                            cout<<" - inlocuire a unui caracter sau a unui sir de caractere din sirul dumneavoastra cu un caracter sau cu un alt sir\n\n\n";
                            goto iesireInfo;
                            break;
                        }
                    case 51:
                        {
                            //info inserari
                            clearScreen();
                            SetConsoleTextAttribute(colour,GREEN);
                            cout<<"   Aceasta sectiune contine functii de:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            cout<<" - adaugare a unui caracter in sirul dumneavoastra in mai multe modalitati\n";
                            cout<<" - adaugare a unui sir de caractere in sirul dumneavoastra in mai multe modalitati\n\n\n";
                            goto iesireInfo;
                            break;
                        }
                    case 52:
                        {
                            //info eliminari
                            clearScreen();
                            SetConsoleTextAttribute(colour,GREEN);
                            cout<<"   Aceasta sectiune contine functii de:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            cout<<" - a unui caracter din sirul dumneavoastra\n";
                            cout<<" - a unui sir de caractere din sirul dumneavoastra\n\n\n";
                            goto iesireInfo;
                            break;
                        }
                    default:
                        {
                            InvalidInfo:
                                clearScreen();
                                SetConsoleTextAttribute(colour,WHITE);
                                cout<<"\nComanda invalida. Va rugam sa introduceti o comanda valida.\n";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"\nPentru a reveni in meniul anterior, apasati tasta: ";
                                SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                cout<<"=\n";
                                SetConsoleTextAttribute(colour,DWHITE);
                                cout<<"Pentru a reveni in meniul principal, apasati tasta: ";
                                SetConsoleTextAttribute(colour,LIGHTERBLUE);
                                cout<<"0\n\n";
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto outInfo;
                                    break;
                                case 61:
                                    goto infoScreen;
                                    break;
                                default:
                                    {
                                        clearScreen();
                                        goto InvalidInfo;
                                        break;
                                    }
                                }
                            break;
                        }
                    }
                    break;
            }
        case 55:
            {
                //schimbare sir de testare
                meniuSchSir:
                    clearScreen();
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<" Sirul de testare curent este:\n\n";
                    SetConsoleTextAttribute(colour,RED);
                    A.AfisareENL();
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"\n\nPentru a reveni la forma originala a sirului dumneavoastra, apasati tasta: ";
                    SetConsoleTextAttribute(colour,PURPLE);
                    cout<<"2\n\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"\n\nPentru a confirma cererea de inlocuire a sirului de testare, apasati tasta ";
                    SetConsoleTextAttribute(colour,PURPLE);
                    cout<<"1\n\n";
                    SetConsoleTextAttribute(colour,WHITE);
                    cout<<"Pentru revenirea la meniul principal, apasati tasta ";
                    SetConsoleTextAttribute(colour,PURPLE);
                    cout<<"0\n\n";
                    optiune=getch();
                    switch(optiune)
                    {
                    case 48:
                        goto MeniuPrincipal;
                        break;
                    case 49:
                        {
                            clearScreen();
                            SetConsoleTextAttribute(colour,WHITE);
                            cout<<" Sirul de testare curent este:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            A.AfisareENL();
                            SetConsoleTextAttribute(colour,WHITE);
                            cout<<"\nVa rugam sa introduceti noul sir de testare:\n\n";
                            SetConsoleTextAttribute(colour,RED);
                            A.readKB();
                            goto MeniuPrincipal;
                            break;
                        }
                    case 50:
                        {
                            A.copyFrom(copieOriginal);
                            goto MeniuPrincipal;
                            break;
                        }
                    default:
                        {
                            WrongSchSir:
                                clearScreen();
                                SetConsoleTextAttribute(colour,WHITE);
                                cout<<"Comanda invalida. Va rugam sa introduceti o comanda valida.\n\n";
                                cout<<"Pentru a reveni in meniul principal, apasati tasta ";
                                SetConsoleTextAttribute(colour,PURPLE);
                                cout<<"0\n\n";
                                SetConsoleTextAttribute(colour,RED);
                                optiune=getch();
                                switch(optiune)
                                {
                                case 48:
                                    goto MeniuPrincipal;
                                    break;
                                default:
                                    {
                                        goto WrongSchSir;
                                        break;
                                    }
                                }
                                break;
                        }
                    }
                    break;

            }
            default:
            {
                //comanda invalida
                SetConsoleTextAttribute(colour,WHITE);
                clearScreen();
                cout<<"\n Comanda invalida. Va rugam sa introduceti o comanda valida\n";
                cout<<" Apasati orice tasta pentru a reveni in meniul principal...";
                getch();
                goto MeniuPrincipal;
                break;
            }
        }
    return 0;
}
