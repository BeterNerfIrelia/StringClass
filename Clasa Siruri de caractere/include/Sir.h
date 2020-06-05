#ifndef SIR_H
#define SIR_H


class Sir
{
    public:
        /** Default constructor */
        Sir();
        /** Default destructor */
        virtual ~Sir();
        //constructori

        Sir(char litera);
        Sir(char cuv[]);
        Sir(Sir &Z);


        //operatii

        unsigned long long getDim();                        //returneaza lungimea sirului
        unsigned long long getNoCuv();                      //returneaza numarul de cuvinte
        unsigned long long getNoVowel();                    //returneaza numarul de vocale;
        unsigned long long getNoConsoane();                 //returneaza numarul de consoane;
        unsigned long long getNoSymbols();                  //returneaza numarul de simboluri
        unsigned long long getAparitiiCh(char c);           //returneaza numarul de aparitii ale unui caracter
        unsigned long long getAparitiiCuv(char cuv[]);      //returneaza numarul de aparitii ale unui cuvant, cuvant separat
        unsigned long long getDigits();                     //returneaza numarul de cifre;
        void createCaesarKey();                             //generaza o cheie de criptare;
        unsigned long long getCaesarKey();                  //returneaza cheia de criptare;
        void doCompozitie(Sir &Z);                          //face compozitia sirului
        void copyFrom(char c);                              // obiect <- litera
        void copyFrom(char cuv[]);                          // obiect <- sir de caractere
        void copyFrom(Sir &Z);                              // obiect <- alt obiect
        void copyTo(char cuv[]);                            //copiaza sirul obiectului intr-un alt sir
        friend Sir operator + (Sir &A, Sir &B);             // functie friend de concatenare
        void reverseSir();                                  //strrev manual


        //citiri

        void readKB();                                      //citire de la tastatura
        void readCaesarKey();                               //citirea cheii de criptare


        //afisare

        void AfisareENL();                                  //afisare pe ecran cu endl la final
        void AfisareESpace();                               //afisare pe ecran cu spatiu

        //case changes

        //lower
        void CaseLowerAll();                                        //toate literele majuscule devin litere mici
        void CaseLowerFirstCh();                                    //primul caracter e transformat in caracter mic
        void CaseLowerFirstNCh(unsigned int n);                     //primele n caractere sunt facute mici
        void CaseLowerFirstSpecificCh(char litera);                 //primul caracter dat e micsorat, indiferent de marime
        void CaseLowerLastCh();                                     //ultimul caracter e micsorat
        void CaseLowerLastDatCh(char litera);                       //ultima aparitie a unui caracter e micsorat, indiferent de marime
        void CaseLowerLastNCh(unsigned int n);                      //ultimele n caractere
        void CaseLowerFirstNChDate(char C,unsigned int n);          // primele n aparitii ale unui ch dat sunt micsorate
        void CaseLowerLastNChDate(char C,unsigned int n);           //ultimele n aparitii ale unui ch dat sunt micsorate
        void CaseLowerConsoaneAll();                                //toate consoanele sunt micsorate
        void CaseLowerConsoaneFirstN(unsigned int n);               //primele N consoane
        void CaseLowerConsoaneFirst();                              //prima consoana micsorata
        void CaseLowerConsoaneLast();                               //ultima consoana micsorata
        void CaseLowerConsoaneLastN(unsigned int n);                //ultimele n consoane sunt micsorate
        void CaseLowerVocaleAll();                                  //toate vocalele micsorate
        void CaseLowerVocaleFirst();                                //prima vocala micsoarata
        void CaseLowerVocaleFirstN(unsigned int n);                 //micsorate primele n vocale
        void CaseLowerVocaleLast();                                 //ultima vocala micsoarata
        void CaseLowerVocaleLastN(unsigned int n);                  //ultimele n vocale micsorate
        void CaseLowerStringAll(char cine[]);                       //toate aparitiile unui string dat
        void CaseLowerStringFirst(char cine[]);                     //prima aparitie a unui string dat
        void CaseLowerStringFirstN(char cine[],unsigned int n);     // primele n aparitii ale unui string dat
        void CaseLowerStringLast(char cine[]);                      //ultima aparitie a unui string e micsorata
        void CaseLowerStringLastN(char cine[],unsigned int n);      //ultimele n aparitii a unui string sunt micsorate

        //upper
        void CaseUpAll();                                           //toate literele sunt marite
        void CaseUpFirstCh();                                       //primul caracter e marit
        void CaseUpFirstNCh(unsigned int n);                        // primele n caractere sunt marite
        void CaseUpFirstSpecificCh(char C);                         //prima aparitie a unui caracter
        void CaseUpLastCh();                                        //ultimul ch e micsorat
        void CaseUpLastDatCh(char C);                               //ultima aparitie a unui caracter dat;
        void CaseUpLastNCh(unsigned int n);                         //ultimele n caractere sunt marite;
        void CaseUpFirstNChDate(char C,unsigned int n);             // primele n aparitii ale unui ch sunt marite;
        void CaseUpLastNChDate(char C, unsigned int n);             //ultimele n aparitii ale unui ch sunt marite;
        void CaseUpConsoaneAll();                                   //toate consoanele sunt marite
        void CaseUpConsoaneFirst();                                 //prima consoana e marita;
        void CaseUpConsoaneLast();                                  //ultima consoana e marita;
        void CaseUpconsoaneFirstN(unsigned int n);                  //primele n consoane sunt marite;
        void CaseUpConsoaneLastN(unsigned int n);                   //ultimele n consoane sunt marite;
        void CaseUpVocaleAll();                                     // toate vocalele sunt marite;
        void CaseUpVocaleFirst();                                   //prima vocala e marita
        void CaseUpVocaleLast();                                    //ultima vocaal e marita
        void CaseUpVocaleFirstN(unsigned int n);                    //primele n vocale sunt marite
        void CaseUpVocaleLastN(unsigned int n);                     //ultimele n vocale sunt marite;
        void CaseUpStringAll(char cine[]);                          //toate aparitiile ale unui string dat sunt marite
        void CaseUpStringFirst(char cine[]);                        //prima aparitie a unui string dat e marita
        void CaseUpStringLast(char cine[]);                         //ultima aparitie a unui string dat e marita;
        void CaseUpStringFirstN(char cine[],unsigned int n);        //primele n aparitii ale unui string dat sunt marite
        void CaseUpStringLastN(char cine[],unsigned int n);         //ultimele n aparitii ale unui string dat sunt marite

        //Adaugare
        void AddToBeginning(Sir &A);                                                //adauge pe A la inceputul sirului nostru;
        void AddToEnding(Sir &A);                                                   //adauga pe A la sfarsitul sirului nostru;
        void AddChToPozDat(char C,unsigned int unde);                               //adauga caracterul dat pe o anumita pozitie in sir
        void AddChDupaVocaleAll(char C);                                            //adauga un caracter dat dupa toate vocalele
        void AddChDupaVocaleN(char C, unsigned int n);                              //adauga un caracter dat dupa primele n vocale;
        void AddChBeforeVocaleAll(char C);                                          //adauga un caracter inaitnea tuturor vocalelor
        void AddChBeforeVocaleN(char C, unsigned int n);                            //adauga un caracter dupa primele n vocale
        void AddChDupaConsoaneAll(char C);                                          //adauga un caracter dupa toate consoanele;
        void AddChDupaConsoaneN(char C,unsigned int n);                             //adauca un caracter dat dupa primele n consoane.
        void AddChBeforeConsoaneAll(char C);                                        //adauga un caracter inaitea tuturor consoanelor;
        void AddChBeforeConsoaneN(char C, unsigned int n);                          //adauga un caracter inaintea primelor n consoane;
        void AddChDupaChAll(char pun, char dupa);                                   //adauga un caracter dupa toate aparitiile ale unui alt caracter;
        void AddChDupaChFirstN(char pun,char dupa,unsigned int n);                  //adauga un caracter dupa primele n aparitii ale unui alt caracter
        void AddChBeforeChAll(char pun,char dupa);                                  //adauga un caracter inaintea tuturor aparitiilor ale unui alt caracter;
        void AddChBeforeChN(char pun,char dupa,unsigned int n);                     // adauga un caracter inaintea primelor n aparitii ale unui caracter;
        void AddChBeforeStringN(char pun,char dupa[],unsigned int n);               //adauga un caracter inaintea primelor n aparitii ale unui sir de caractere;
        void AddChBeforeStringAll(char pun,char dupa[]);                            //adauga un caracter inaintea tuturor aparitiilor unui sir de caractere;
        void AddChDupaStringN(char pun,char dupa[],unsigned int n);                 //adauga un caracter dupa primele n aparitii ale unui string;
        void AddChDupaStringAll(char pun,char dupa[]);                              //adauga un caracter dupa taote aparitiile unui string;
        void AddChDupaPasN(char C, unsigned int pas);                               //adauga un caracter in sir la fiecare pas;
        void AddChBeforePas(char C, unsigned int pas);                              //adauga un caracter in sir la fiecare pas;
        void AddStringToPozDat(char cine[],unsigned int unde);                      //adauga un string pe pozitia data;
        void AddStringDupaChN(char pun[],char C, unsigned int n);                   //adauga un string dupa primele n aparitii ale unui ch;
        void AddStringDupaChAll(char pun[],char C);                                 //adauga un string dupa toate aparitiile unui ch;
        void AddStringBeforeChAll(char pun[],char C);                               //adauga un string inaintea tuturor aparitiilor unui ch;
        void AddStringBeforeChN(char pun[],char C,unsigned int n);                  //adaug un string inaintea priemlor n aparitii ale unui ch;
        void AddStringAfterPas(char cine[],unsigned int pas);                       //adaug un string la fiecare pas, dupa caracterul de pe locul respectiv;
        void AddStringBeforePas(char cine[],unsigned int pas);                      //adaug un string la fiecare pas, inaintea caracterului de pe locul respectiv;
        void AddStringDupaStringAll(char pun[],char in[]);                          //adaug un string dupa fiecare aparitie a unui string;
        void AddStringDupaStringN(char pun[],char in[],unsigned int n);             //adaug string dupa primele n aparitii ale unui string;
        void AddStringBeforeStringAll(char pun[],char in[]);                        //adaug un sting inaintea fiecarei aparitii a unui string;
        void AddStringBeforeStringN(char pun[],char in[],unsigned int n);           //adaug un string inaintea primelor n aparitii ale unui string;

        //eliminari
        void RemoveRedundantSpaces();                               // elimina spatiile redundante
        void RemoveChAll(char C);                                   //elimina toate aparitiile unui caracter;
        void RemoveChFirst(char C);                                 //elimina prima aparitie a unui ch;
        void RemoveChFirstN(char C,unsigned int n);                 //elimina primele N aparitii ale unui caracter;
        void RemoveChLast(char C);                                  //elimina ultima aparitie a unui caracter;
        void RemoveChLastN(char C, unsigned int n);                 //ultimele n aparitii ale unui caracter sunt eliminate
        void RemoveStringAll(char cine[]);                          //elimina toate apariile unui string;
        void RemoveStringFirst(char cine[]);                        //elimina prima aparitie a unui string;
        void RemoveStringFirstN(char cine[],unsigned int n);        //primele n aparitii sunt eliminate;
        void RemoveStringLast(char cine[]);                         //ultima aparitie a unui string e eliminata;
        void RemoveStringLastN(char cine[],unsigned int n);         //ultimele n aparitii sunt eliminate;
        void RemoveVocaleAll();                                     //elimina toate vocalele;
        void RemoveVocaleFirstN(unsigned int n);                    //elimina primele n vocale;
        void RemoveVocaleLastN(unsigned int n);                     //elimina ultimele n vocale;
        void RemoveConsoaneAll();                                   //elimina toate consoanele;
        void RemoveConsoaneFirstN(unsigned int n);                  //elimina primele consoane;
        void RemoveConsoaneLastN(unsigned int n);                   //elimina ultimele n consoane;
        void RemoveSymbols();                                       //elimina toate simbolurile;
        void RemoveFirstCh();                                       //elimina primul caracter;
        void RemoveFirstChN(unsigned int n);                        //elimina primele n caractere;
        void RemoveLastCh();                                        //elimina ultimul caracter
        void RemoveLastChN(unsigned int n);                         //elimina ultimele n caractere;

        //inlocuiri
        void ReplaceChToChAll(char in,char out);                                        //inlocuiest un caracter cu altul -toate aparitiile-
        void ReplaceChToChFirstN(char in,char out, unsigned int n);                     //inlocuieste un caracter cu altul - primele n aparitii-
        void ReplaceChToChLastN(char in,char out,unsigned int n);                       //inlocuieste un caracter cu altul - ultimele n aparitii-
        void ReplaceChToStringAll(char in[],char out);                                  //inlocuieste un caracter cu un string - toate aparitiile-
        void ReplaceChToStringFirstN(char in[],char out,unsigned int n);                //inlocuieste un caracter cu un string - primele n aparitii -;
        void ReplaceChToStringLastN(char in[],char out,unsigned int n);                 //inlocuieste un caracter cu un string - ultimele n aparitii -;
        void ReplaceStringToChAll(char in,char out[]);                                  //inlocuiest un string cu un caracter - toate aparitiile-;
        void ReplaceStringToChFirstN(char in, char out[], unsigned int n);              //inlocueste un string cu un caracter - primele n aparitii-;
        void ReplaceStringToChLastN(char in,char out[],unsigned int n);                 //inclouieste un string cu un caracter - ultimele n aparitii-;
        void ReplaceStringToStringAll(char in[],char out[]);                            //inlocuieste un string cu un string - toate aparitiile-;
        void ReplaceStringToStringFirstN(char in[],char out[], unsigned int n);         //inlocuieste un string cu un string - primele n aparitii-;
        void ReplaceStringToStringLastN(char in[],char out[],unsigned int n);           //inlocuieste un string un cun string -ultmele n aparitii-;
        void Censor(char cine[]);                                                       //inlocuieste "cine" cu un sir de * de aceeasi lungime;

        //criptare
        void CaesarEncrypt(); //criptare cu cheia CaesarKey;
        void CaesarDecrypt(); //decripteaza cu cheia CaesarKey;

        unsigned long long compozitie[6]; //0=cuvinte, 1=vocale 2=consoane, 3=digits 4= simboluri 5 spatii


    protected:

    private:
        char sir[100001];
        unsigned long long dimension=0;
        unsigned long long CaesarKey=0;

};

#endif // SIR_H
