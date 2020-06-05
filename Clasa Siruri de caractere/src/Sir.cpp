#include "Sir.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>

unsigned long long numara,lungime;
char clone[100001],aux[100001],prieten[100001];
char *p,*q;

const char simboluri[]="`~!@#$%^&*()_-+={[}]:;'<,>.?/";
const char voc[]="aeiou";
const char vocale[]="AEIOUaeiou";

void micmic(char s[])
{
    unsigned long long l=strlen(s);
    for(unsigned int i=0;i<l;i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
}

void rev(char s[])
{
    unsigned long long l=strlen(s);
    for(unsigned int i=0;i<=(l-1)/2;i++)
        std::swap(s[i],s[l-i-1]);
}

Sir::Sir()
{
    //ctor
}

Sir::~Sir()
{
    //dtor
}

Sir::Sir(char litera)
{
    this->dimension=1;
    this->sir[0]=litera;
    this->sir[1]=NULL;
}

Sir::Sir(char cuv[])
{
    this->dimension=strlen(cuv);
    strcpy(this->sir,cuv);
}

Sir::Sir(Sir &Z)
{
    this->dimension=Z.dimension;
    strcpy(this->sir,Z.sir);
}

unsigned long long Sir::getDim()
{
    return this->dimension;
}

unsigned long long Sir::getNoCuv()
{
    numara=0;
    strcpy(clone,this->sir);
    p=strtok(clone," ");
    while(p)
    {
        bool ch=0;
        lungime=strlen(p);
        for(unsigned int i=0;i<lungime;i++)
            if(isalnum(p[i]))
                {
                    ch=1;
                    break;
                }
        if(ch==1)
            numara++;
        p=strtok(NULL," ");
    }
    return numara;
}

unsigned long long Sir::getNoVowel()
{
    numara=0;
    for(unsigned int i=0;i<this->dimension;i++)
        if(strchr("aeiouAEIOU",this->sir[i]))
            numara++;
    return numara;
}

unsigned long long Sir::getNoConsoane()
{
    numara=0;
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(this->sir[i]))
            if(!strchr("aeiouAEIOU",this->sir[i]))
                numara++;
    return numara;
}

unsigned long long Sir::getNoSymbols()
{
    numara=0;
    for(unsigned int i=0;i<this->dimension;i++)
        if(!isalnum(this->sir[i]) && this->sir[i]!=' ')
            numara++;
    return numara;
}

unsigned long long Sir::getAparitiiCh(char c)
{
    numara=0;
    p=strchr(this->sir,c);
    while(p)
    {
        numara++;
        p=strchr(p+1,c);
    }
    return numara;
}

unsigned long long Sir::getAparitiiCuv(char cuv[])
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(cuv);
    numara=0;
    lungime=strlen(cuv);
    p=strtok(clone," ");
    while(p)
    {
        if(!strcmp(p,cuv))
            numara++;
        p=strtok(NULL," ");
    }
    return numara;
}

unsigned long long Sir::getDigits()
{
    numara=0;
    for(unsigned int i=0;i<this->dimension;i++)
        if(isdigit(this->sir[i]))
            numara++;
    return numara;
}

void Sir::createCaesarKey()
{
    srand(time(NULL));
    this->CaesarKey=rand()%100+1;
}

unsigned long long Sir::getCaesarKey()
{
    return this->CaesarKey;
}

void Sir::doCompozitie(Sir &Z)
{
    //0=cuvinte, 1=vocale 2=consoane, 3=digits 4= simboluri 5 spatii
    this->compozitie[0]=Z.getNoCuv();
    this->compozitie[1]=Z.getNoVowel();
    this->compozitie[2]=Z.getNoConsoane();
    this->compozitie[3]=Z.getDigits();
    this->compozitie[4]=Z.getNoSymbols();
    this->compozitie[5]=Z.getAparitiiCh(' ');
}

void Sir::copyFrom(char c)
{
    this->sir[0]=c;
    this->sir[1]=NULL;
    this->dimension=1;
}

void Sir::copyFrom(char cuv[])
{
    this->dimension=strlen(cuv);
    strcpy(this->sir,cuv);
}

void Sir::copyFrom(Sir &Z)
{
    this->dimension=Z.dimension;
    strcpy(this->sir,Z.sir);
}

void Sir::copyTo(char cuv[])
{
    strcpy(cuv,this->sir);
}

Sir operator + (Sir &A,Sir &B)
{
    Sir C;
    strcpy(C.sir,A.sir);
    strcat(C.sir,B.sir);
    C.dimension=strlen(C.sir);
    return C;
}

void Sir::reverseSir()
{
    for(unsigned int i=0;i<=(this->dimension-1)/2;i++)
        std::swap(this->sir[i],this->sir[this->dimension-i-1]);
}

void Sir::readKB()
{
    std::cin.getline(this->sir,100000);
}

void Sir::readCaesarKey()
{
    std::cin>>this->CaesarKey;
}

void Sir::AfisareENL()
{
    std::cout<<this->sir<<'\n';
}

void Sir::AfisareESpace()
{
    std::cout<<this->sir<<' ';
}

void Sir::CaseLowerAll()
{
    for(unsigned int i=0;i<this->dimension;i++)
        if(this->sir[i]>='A' && this->sir[i]<='Z')
            this->sir[i]+=32;
}

void Sir::CaseLowerFirstCh()
{
    if(this->sir[0]>='A' && this->sir[0]<='Z')
        this->sir[0]+=32;
}

void Sir::CaseLowerFirstNCh(unsigned int n)
{
    for(unsigned int i=0;i<n;i++)
        if(this->sir[i]>='A' && this->sir[i]<='Z')
            this->sir[i]+=32;
}

void Sir::CaseLowerFirstSpecificCh(char litera)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(litera>='A' && litera<='Z')
        litera+=32;
    p=strchr(clone,litera);
    numara=p-clone;
    if(this->sir[numara]<'a')
        this->sir[numara]+=32;
}

void Sir::CaseLowerLastCh()
{
    this->sir[this->dimension-1]=this->sir[this->dimension-1]<'a' ? this->sir[this->dimension-1]+=32 : this->sir[this->dimension-1];
}

void Sir::CaseLowerLastDatCh(char litera)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(litera<'a' && isalpha(litera))
        litera+=32;
    p=strrchr(clone,litera);
    numara=p-clone;
    if(this->sir[numara]<'a')
        this->sir[numara]+=32;
}

void Sir::CaseLowerLastNCh(unsigned int n)
{
    if(this->dimension<n)
        micmic(this->sir);
    else
    {
        for(unsigned int i=1;i<=n;i++)
            if(isalpha(this->sir[this->dimension-i]))
                this->sir[this->dimension-i]= this->sir[this->dimension-i]<'a' ? this->sir[this->dimension-i]+=32 : this->sir[this->dimension-i];
    }
}

void Sir::CaseLowerFirstNChDate(char C,unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(C<'a' && isalpha(C))
        C+=32;
    p=strchr(clone,C);
    while(n>0 && p!=NULL)
    {
        numara=p-clone;
        if(this->sir[numara]<'a')
            this->sir[numara]+=32;
        p=strchr(p+1,C);
        n--;
    }
}

void Sir::CaseLowerLastNChDate(char C,unsigned int n)
{
    if(C<'a' && isalpha(C))
        C+=32;
    rev(this->sir);
    strcpy(clone,this->sir);
    micmic(clone);
    p=strchr(clone,C);
    while(n>0 && p!=NULL)
    {
        numara=p-clone;
        if(this->sir[numara]<'a')
            this->sir[numara]+=32;
        p=strchr(p+1,C);
        n--;
    }
    rev(this->sir);
}

void Sir::CaseLowerConsoaneAll()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
                if(this->sir[i]<'a')
                    this->sir[i]+=32;
}

void Sir::CaseLowerConsoaneFirstN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
            {
                if(this->sir[i]<97)
                    this->sir[i]+=32;
                n--;
            }
}

void Sir::CaseLowerConsoaneFirst()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
            {
                if(this->sir[i]<97)
                    this->sir[i]+=32;
                break;
            }
}

void Sir::CaseLowerConsoaneLast()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>0;i--)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        break;
    }
}

void Sir::CaseLowerConsoaneLastN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;n>0 && i>0;i--)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        n--;
    }
}

void Sir::CaseLowerVocaleAll()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
}

void Sir::CaseLowerVocaleFirst()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        break;
    }
}

void Sir::CaseLowerVocaleFirstN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        n--;
    }
}

void Sir::CaseLowerVocaleLast()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>0;i--)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        break;
    }
}

void Sir::CaseLowerVocaleLastN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1 && n>0;i>0;i--)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]<97)
            this->sir[i]+=32;
        n--;
    }
}

void Sir::CaseLowerStringAll(char cine[])
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(cine);
    p=strstr(clone,cine);
    lungime=strlen(cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
        p=strstr(p+lungime,cine);
    }
}

void Sir::CaseLowerStringFirst(char cine[])
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(cine);
    p=strstr(clone,cine);
    lungime=strlen(cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
        break;
    }
}

void Sir::CaseLowerStringFirstN(char cine[],unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(cine);
    p=strstr(clone,cine);
    lungime=strlen(cine);
    while(p && n>0)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
        n--;
        p=strstr(p+lungime,cine);
    }
}

void Sir::CaseLowerStringLast(char cine[])
{
    rev(this->sir);
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(cine);
    rev(cine);
    lungime=strlen(cine);
    p=strstr(clone,cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
        break;
    }
    rev(this->sir);
}

void Sir::CaseLowerStringLastN(char cine[],unsigned int n)
{
    rev(this->sir);
    strcpy(clone,this->sir);
    micmic(clone);
    rev(cine);
    micmic(cine);
    lungime=strlen(cine);
    p=strstr(clone,cine);
    while(p && n>0)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]<97)
                    this->sir[i]+=32;
        n--;
        p=strstr(p+lungime,cine);
    }
    rev(this->sir);
}

void Sir::CaseUpAll()
{
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(this->sir[i]))
            if(this->sir[i]>=97)
                this->sir[i]-=32;
}

void Sir::CaseUpFirstCh()
{
    if(isalpha(this->sir[0]))
        if(this->sir[0]>96)
            this->sir[0]-=32;
}

void Sir::CaseUpFirstNCh(unsigned int n)
{
    for(unsigned int i=0;i<n;i++)
    {
        if(isalpha(this->sir[i]))
            if(this->sir[i]>96 && isalpha((this->sir[i])))
                this->sir[i]-=32;
    }
}

void Sir::CaseUpFirstSpecificCh(char C)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(C<97 && isalpha(C))
        C+=32;
    p=strchr(clone,C);
    numara=p-clone;
    if(this->sir[numara]>='a')
        this->sir[numara]-=32;
}

void Sir::CaseUpLastCh()
{
    if(isalpha(this->sir[this->dimension-1]))
        if(this->sir[this->dimension-1]>96 && isalpha(this->sir[this->dimension-1]))
            this->sir[this->dimension-1]-=32;
}

void Sir::CaseUpLastDatCh(char C)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(C<97 && isalpha(C))
        C+=32;
    p=strchr(clone,C);
    numara=p-clone;
    if(this->sir[numara]>96)
        this->sir[numara]-=32;
}

void Sir::CaseUpLastNCh(unsigned int n)
{
    for(unsigned int i=this->dimension-1;i>=0 && n>0;i--)
    {
        n--;
        if(isalpha(this->sir[i]))
            if(this->sir[i]>96 && isalpha(this->sir[i]))
                this->sir[i]-=32;
    }
}

void Sir::CaseUpFirstNChDate(char C,unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(C<97 && isalpha(C))
        C+=32;
    p=strchr(clone,C);
    while(p && n>0)
    {
        n--;
        numara=p-clone;
        if(this->sir[numara]>96 && isalpha(this->sir[numara]))
            this->sir[numara]-=32;
        p=strchr(p+1,C);
    }
}

void Sir::CaseUpLastNChDate(char C,unsigned int n)
{
    rev(this->sir);
    strcpy(clone,this->sir);
    micmic(clone);
    if(C<97 && isalpha(C))
        C+=32;
    p=strchr(clone,C);
    while(p && n>0)
    {
        n--;
        numara=p-clone;
        if(this->sir[numara]>96 && isalpha(this->sir[numara]))
            this->sir[numara]-=32;
        p=strchr(p+1,C);
    }
    rev(this->sir);
}

void Sir::CaseUpConsoaneAll()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
}

void Sir::CaseUpConsoaneFirst()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        if(this->sir[i]>96)
            this->sir[i]-=32;
        break;
    }
}

void Sir::CaseUpConsoaneLast()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>=0;i--)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        if(this->sir[i]>96)
            this->sir[i]-=32;
        break;
    }
}

void Sir::CaseUpconsoaneFirstN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        n--;
        if(this->sir[i]>96)
            this->sir[i]-=32;
    }
}

void Sir::CaseUpConsoaneLastN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>=0 && n>0;i--)
        if(isalpha(clone[i]))
            if(!strchr(voc,clone[i]))
    {
        n--;
        if(this->sir[i]>96)
            this->sir[i]-=32;
    }
}

void Sir::CaseUpVocaleAll()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
}

void Sir::CaseUpVocaleFirst()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]>96)
            this->sir[i]-=32;
        break;
    }
}

void Sir::CaseUpVocaleLast()
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>=0;i--)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        if(this->sir[i]>96)
            this->sir[i]-=32;
        break;
    }
}

void Sir::CaseUpVocaleFirstN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        n--;
        if(this->sir[i]>96)
            this->sir[i]-=32;
    }
}

void Sir::CaseUpVocaleLastN(unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    for(unsigned int i=this->dimension-1;i>=0 && n>0;i--)
        if(isalpha(clone[i]))
            if(strchr(voc,clone[i]))
    {
        n--;
        if(this->sir[i]>96)
            this->sir[i]-=32;
    }
}

void Sir::CaseUpStringAll(char cine[])
{
    micmic(cine);
    lungime=strlen(cine);

    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
        p=strstr(p+lungime,cine);
    }
}

void Sir::CaseUpStringFirst(char cine[])
{
    micmic(cine);
    lungime=strlen(cine);

    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
        break;
    }
}

void Sir::CaseUpStringLast(char cine[])
{
    rev(cine);
    rev(this->sir);
    micmic(cine);
    lungime=strlen(cine);

    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p)
    {
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
        break;
    }
    rev(this->sir);
}

void Sir::CaseUpStringFirstN(char cine[],unsigned int n)
{
    lungime=strlen(cine);
    micmic(cine);

    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p && n>0)
    {
        n--;
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
        p=strstr(p+lungime,cine);
    }
}

void Sir::CaseUpStringLastN(char cine[],unsigned int n)
{
    rev(cine);
    rev(this->sir);
    lungime=strlen(cine);
    micmic(cine);

    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p && n>0)
    {
        n--;
        numara=p-clone;
        for(unsigned int i=numara;i<numara+lungime;i++)
            if(isalpha(clone[i]))
                if(this->sir[i]>96)
                    this->sir[i]-=32;
        p=strstr(p+lungime,cine);
    }
    rev(this->sir);
}

void Sir::AddToBeginning(Sir &A)
{
    strcpy(aux,A.sir);
    strcat(aux,this->sir);
    strcpy(this->sir,aux);
    this->dimension+=A.dimension;
}

void Sir::AddToEnding(Sir &A)
{
    strcat(this->sir,A.sir);
    this->dimension+=A.dimension;
}

void Sir::AddChToPozDat(char C,unsigned int unde)
{
    strcpy(clone,this->sir+unde);
    this->sir[unde]=C;
    strcpy(this->sir+unde+1,clone);
    this->dimension++;
}

void Sir::AddChDupaVocaleAll(char C)
{
    for(unsigned int i=0;i<this->dimension;)
        if(strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        strcpy(clone,this->sir+i+1);
        this->sir[i+1]=C;
        strcpy(this->sir+i+2,clone);
        i+=2;
    }
    else
        i++;
}

void Sir::AddChDupaVocaleN(char C,unsigned int n)
{
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        strcpy(clone,this->sir+i+1);
        this->sir[i+1]=C;
        strcpy(this->sir+i+2,clone);
        n--;
        i++;
    }
}

void Sir::AddChBeforeVocaleAll(char C)
{
    for(unsigned int i=0;i<this->dimension;i++)
        if(strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        strcpy(clone,this->sir+i);
        this->sir[i]=C;
        strcpy(this->sir+i+1,clone);
        i++;
    }
}

void Sir::AddChBeforeVocaleN(char C,unsigned int n)
{
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        n--;
        strcpy(clone,this->sir);
        this->sir[i]=C;
        strcpy(this->sir+i+1,clone);
        i++;
    }
}

void Sir::AddChDupaConsoaneAll(char C)
{
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(this->sir[i]))
            if(!strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        strcpy(clone,this->sir+i+1);
        this->sir[i+1]=C;
        strcpy(this->sir+i+2,clone);
        i++;
    }
}

void Sir::AddChDupaConsoaneN(char C,unsigned int n)
{
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(this->sir[i]))
            if(!strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        n--;
        strcpy(clone,this->sir+i+1);
        this->sir[i+1]=C;
        strcpy(this->sir+i+2,clone);
        i++;
    }
}

void Sir::AddChBeforeConsoaneAll(char C)
{
    for(unsigned int i=0;i<this->dimension;i++)
        if(isalpha(this->sir[i]))
            if(!strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        strcpy(clone,this->sir+i);
        this->sir[i]=C;
        strcpy(this->sir+i+1,clone);
        i++;
    }
}

void Sir::AddChBeforeConsoaneN(char C,unsigned int n)
{
    for(unsigned int i=0;i<this->dimension && n>0;i++)
        if(isalpha(this->sir[i]))
            if(!strchr(vocale,this->sir[i]))
    {
        this->dimension++;
        n--;
        strcpy(clone,this->sir+i);
        this->sir[i]=C;
        strcpy(this->sir+i+1,clone);
        i++;
    }
}

void Sir::AddChDupaChAll(char pun,char dupa)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(dupa<96 && isalpha(dupa))
        dupa+=32;
    p=strchr(clone,dupa);
    while(p)
    {
        this->dimension++;
        numara=p-clone;
        strcpy(aux,clone+numara+1);
        clone[numara+1]=pun;
        strcpy(clone+numara+2,aux);

        strcpy(aux,this->sir+numara+1);
        this->sir[numara+1]=pun;
        strcpy(this->sir+numara+2,aux);
        p=strchr(p+2,dupa);
    }
}

void Sir::AddChDupaChFirstN(char pun,char dupa,unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(dupa<96 && isalpha(dupa))
        dupa+=32;
    p=strchr(clone,dupa);
    while(p && n>0)
    {
        numara=p-clone;
        this->dimension++;
        strcpy(aux,clone+numara+1);
        clone[numara+1]=pun;
        strcpy(clone+numara+2,aux);

        strcpy(aux,this->sir+numara+1);
        this->sir[numara+1]=pun;
        strcpy(this->sir+numara+2,aux);
        n--;
        p=strchr(p+2,dupa);
    }
}

void Sir::AddChBeforeChAll(char pun,char dupa)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(dupa<96 && isalpha(dupa))
        dupa+=32;
    p=strchr(clone,dupa);
    while(p)
    {
        numara=p-clone;
        this->dimension++;
        strcpy(aux,clone+numara);
        clone[numara]=pun;
        strcpy(clone+numara+1,aux);

        strcpy(aux,this->sir+numara);
        this->sir[numara]=pun;
        strcpy(this->sir+numara+1,aux);
        p=strchr(p+2,dupa);
    }
}

void Sir::AddChBeforeChN(char pun,char dupa,unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    if(dupa<96 && isalpha(dupa))
        dupa+=32;
    p=strchr(clone,dupa);
    while(p && n>0)
    {
        n--;
        this->dimension++;
        numara=p-clone;
        strcpy(aux,clone+numara);
        clone[numara]=pun;
        strcpy(clone+numara+1,aux);

        strcpy(aux,this->sir+numara);
        this->sir[numara]=pun;
        strcpy(this->sir+numara+1,aux);
        p=strchr(p+2,dupa);
    }
}

void Sir::AddChBeforeStringN(char pun,char dupa[],unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(dupa);
    lungime=strlen(dupa);
    p=strstr(clone,dupa);
    while(p && n>0)
    {
        n--;
        numara=p-clone;
        strcpy(aux,this->sir+numara);
        this->sir[numara]=pun;
        strcpy(this->sir+numara+1,aux);
        this->dimension++;

        strcpy(aux,p);
        p[0]=pun;
        strcpy(p+1,aux);

        p=strstr(p+1+lungime,dupa);
    }
}

void Sir::AddChBeforeStringAll(char pun,char dupa[])
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(dupa);
    lungime=strlen(dupa);
    p=strstr(clone,dupa);
    while(p)
    {
        numara=p-clone;
        strcpy(aux,this->sir+numara);
        this->sir[numara]=pun;
        strcpy(this->sir+numara+1,aux);
        this->dimension++;

        strcpy(aux,p);
        p[0]=pun;
        strcpy(p+1,aux);

        p=strstr(p+1+lungime,dupa);
    }
}

void Sir::AddChDupaStringAll(char pun,char dupa[])
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(dupa);
    lungime=strlen(dupa);
    p=strstr(clone,dupa);
    while(p)
    {
        numara=p-clone;
        strcpy(aux,this->sir+numara+lungime);
        this->sir[numara+lungime]=pun;
        strcpy(this->sir+numara+lungime+1,aux);
        this->dimension++;

        strcpy(aux,p+lungime);
        p[lungime]=pun;
        strcpy(p+lungime+1,aux);

        p=strstr(p+lungime+1,dupa);
    }
}

void Sir::AddChDupaStringN(char pun,char dupa[],unsigned int n)
{
    strcpy(clone,this->sir);
    micmic(clone);
    micmic(dupa);
    lungime=strlen(dupa);
    p=strstr(clone,dupa);
    while(p && n>0)
    {
        numara=p-clone;
        n--;
        strcpy(aux,this->sir+numara+lungime);
        this->sir[numara+lungime]=pun;
        strcpy(this->sir+numara+lungime+1,aux);
        this->dimension++;

        strcpy(aux,p+lungime);
        p[lungime]=pun;
        strcpy(p+lungime+1,aux);

        p=strstr(p+lungime+1,dupa);
    }
}

void Sir::AddChDupaPasN(char C,unsigned int pas)
{
    for(unsigned int i=pas-1;i<this->dimension;i+=pas+1)
    {
        strcpy(clone,this->sir+i+1);
        this->sir[i+1]=C;
        strcpy(this->sir+i+2,clone);
        this->dimension++;
    }
}
 void Sir::AddChBeforePas(char C,unsigned int pas)
 {
     for(unsigned int i=pas-1;i<this->dimension;i+=pas+1)
    {
        strcpy(clone,this->sir+i);
        this->sir[i]=C;
        strcpy(this->sir+i+1,clone);
        this->dimension++;
    }
 }

 void Sir::AddStringToPozDat(char cine[],unsigned int unde)
 {
     lungime=strlen(cine);
     strcpy(clone,this->sir+unde);
     strcpy(this->sir+unde,cine);
     strcpy(this->sir+unde+lungime,clone);
     this->dimension+=lungime;
 }

 void Sir::AddStringDupaChN(char pun[],char C,unsigned int n)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     lungime=strlen(pun);
     p=strchr(clone,C);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(aux,this->sir+numara+1);
         strcpy(this->sir+numara+1,pun);
         strcpy(this->sir+numara+lungime+1,aux);

         strcpy(aux,p+1);
         strcpy(p+1,pun);
         strcpy(p+1+lungime,aux);
         this->dimension+=lungime;
         p=strchr(p+lungime+1,C);
     }
 }

 void Sir::AddStringDupaChAll(char pun[],char C)
 {
      strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     lungime=strlen(pun);
     p=strchr(clone,C);
     while(p)
     {
         numara=p-clone;
         strcpy(aux,this->sir+numara+1);
         strcpy(this->sir+numara+1,pun);
         strcpy(this->sir+numara+lungime+1,aux);

         strcpy(aux,p+1);
         strcpy(p+1,pun);
         strcpy(p+1+lungime,aux);
         this->dimension+=lungime;
         p=strchr(p+lungime+1,C);
     }
 }

 void Sir::AddStringBeforeChAll(char pun[],char C)
 {
    strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     lungime=strlen(pun);
     p=strchr(clone,C);
     while(p)
     {
         this->dimension+=lungime;
         numara=p-clone;

         strcpy(aux,this->sir+numara);
         strcpy(this->sir+numara,pun);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p);
         strcpy(p,pun);
         strcpy(p+lungime,aux);

         p=strchr(p+lungime+1,C);
     }
 }

 void Sir::AddStringBeforeChN(char pun[],char C,unsigned int n)
 {
    strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     lungime=strlen(pun);
     p=strchr(clone,C);
     while(p && n>0)
     {
         n--;
         this->dimension+=lungime;
         numara=p-clone;

         strcpy(aux,this->sir+numara);
         strcpy(this->sir+numara,pun);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p);
         strcpy(p,pun);
         strcpy(p+lungime,aux);

         p=strchr(p+lungime+1,C);
     }
 }

 void Sir::AddStringAfterPas(char cine[],unsigned int pas)
 {
     lungime=strlen(cine);
     for(unsigned int i=pas-1;i<this->dimension;i+=lungime+pas)
     {
         strcpy(clone,this->sir+i+1);
         strcpy(this->sir+i+1,cine);
         strcpy(this->sir+i+1+lungime,clone);
         this->dimension+=lungime;
     }
 }

 void Sir::AddStringBeforePas(char cine[],unsigned int pas)
 {
     lungime=strlen(cine);
     for(unsigned int i=pas-1;i<this->dimension;i+=pas+lungime)
     {
         strcpy(clone,this->sir+i);
         strcpy(this->sir+i,cine);
         strcpy(this->sir+i+lungime,clone);
         this->dimension+=lungime;
     }
 }

 void Sir::AddStringDupaStringAll(char pun[],char in[])
 {
     strcpy(clone,this->sir);
     micmic(clone);

     strcpy(aux,in);
     micmic(in);

     lungime=strlen(pun);
     int lin=strlen(in);

     p=strstr(clone,in);
     while(p)
     {
         numara=p-clone;
         this->dimension+=lungime;

         strcpy(prieten,this->sir+numara+lin);
         strcpy(this->sir+numara+lin,pun);
         strcpy(this->sir+numara+lin+lungime,prieten);

         strcpy(prieten,p+lin);
         strcpy(p+lin,pun);
         strcpy(p+lin+lungime,prieten);

         p=strstr(p+lin+lungime,in);
     }
 }

 void Sir::AddStringDupaStringN(char pun[],char in[],unsigned int n)
 {
     strcpy(clone,this->sir);
     micmic(clone);

     micmic(in);

     lungime=strlen(pun);
     int lin=strlen(in);

     p=strstr(clone,in);
     while(p && n>0)
     {
         numara=p-clone;
         this->dimension+=lungime;
         n--;

         strcpy(prieten,this->sir+numara+lin);
         strcpy(this->sir+numara+lin,pun);
         strcpy(this->sir+numara+lin+lungime,prieten);

         strcpy(prieten,p+lin);
         strcpy(p+lin,pun);
         strcpy(p+lin+lungime,prieten);

         p=strstr(p+lin+lungime,in);
     }
 }

 void Sir::AddStringBeforeStringAll(char pun[],char in[])
 {
     strcpy(clone,this->sir);
     micmic(clone);

     micmic(in);

     lungime=strlen(pun);
     int lin=strlen(in);
     p=strstr(clone,in);

     while(p)
     {
         numara=p-clone;
         this->dimension+=lungime;

         strcpy(aux,this->sir+numara);
         strcpy(this->sir+numara,pun);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p);
         strcpy(p,pun);
         strcpy(p+lungime,aux);

         p=strstr(p+lungime+lin,in);
     }
 }

 void Sir::AddStringBeforeStringN(char pun[],char in[], unsigned int n)
 {
    strcpy(clone,this->sir);
     micmic(clone);

     micmic(in);

     lungime=strlen(pun);
     int lin=strlen(in);
     p=strstr(clone,in);

     while(p && n>0)
     {
         numara=p-clone;
         n--;
         this->dimension+=lungime;

         strcpy(aux,this->sir+numara);
         strcpy(this->sir+numara,pun);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p);
         strcpy(p,pun);
         strcpy(p+lungime,aux);

         p=strstr(p+lungime+lin,in);
     }
 }


 void Sir::RemoveRedundantSpaces()
 {
     p=strchr(this->sir,' ');
     while(p)
     {
         while(p[1]==' ')
            strcpy(p,p+1);
         p=strchr(p+1,' ');
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::RemoveChAll(char C)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     p=strchr(clone,C);
     while(p)
     {
         numara=p-clone;
         strcpy(p,p+1);
         strcpy(this->sir+numara,this->sir+numara+1);
         p=strchr(p+1,C);
         this->dimension--;
     }
 }

 void Sir::RemoveChFirst(char C)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     p=strchr(clone,C);
     numara=p-clone;
     strcpy(this->sir+numara,this->sir+numara+1);
     this->dimension--;
 }

 void Sir::RemoveChFirstN(char C,unsigned int n)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     p=strchr(clone,C);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(p,p+1);
         strcpy(this->sir+numara,this->sir+numara+1);
         p=strchr(p+1,C);
         this->dimension--;
     }
 }

 void Sir::RemoveChLast(char C)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     p=strrchr(clone,C);
     numara=p-clone;
     strcpy(this->sir+numara,this->sir+numara+1);
     this->dimension--;
 }

 void Sir::RemoveChLastN(char C,unsigned int n)
 {
     strcpy(clone,this->sir);
     micmic(clone);
     if(C<96 && isalpha(C))
        C+=32;
     p=strrchr(clone,C);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(this->sir+numara,this->sir+numara+1);
         this->dimension--;
         strcpy(p,p+1);
         p=strrchr(clone,C);
     }
 }

 void Sir::RemoveStringAll(char cine[])
 {
     micmic(cine);
     lungime=strlen(cine);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,cine);
     while(p)
     {
         numara=p-clone;
         strcpy(this->sir+numara,this->sir+numara+lungime);
         strcpy(p,p+lungime);
         this->dimension-=lungime;
         p=strstr(p,cine);
     }
 }

 void Sir::RemoveStringFirst(char cine[])
 {
     micmic(cine);
     lungime=strlen(cine);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,cine);
     numara=p-clone;
     strcpy(this->sir+numara,this->sir+numara+lungime);
     this->dimension-=lungime;
 }

 void Sir::RemoveStringFirstN(char cine[],unsigned int n)
 {
     micmic(cine);
     lungime=strlen(cine);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,cine);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(this->sir+numara,this->sir+numara+lungime);
         strcpy(p,p+lungime);
         this->dimension-=lungime;
         p=strstr(p,cine);
     }
 }

 void Sir::RemoveStringLast(char cine[])
 {
     micmic(cine);
     lungime=strlen(cine);
     rev(cine);
     rev(this->sir);
     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,cine);
     numara=p-clone;
     strcpy(this->sir+numara,this->sir+numara+lungime);
     this->dimension-=lungime;
     rev(this->sir);
 }

 void Sir::RemoveStringLastN(char cine[],unsigned int n)
 {
     rev(this->sir);
     rev(cine);
     micmic(cine);
     lungime=strlen(cine);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,cine);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(this->sir+numara,this->sir+numara+lungime);
         strcpy(p,p+lungime);
         this->dimension-=lungime;
         p=strstr(p,cine);
     }
     rev(this->sir);
 }

 void Sir::RemoveVocaleAll()
 {
     for(unsigned int i=0;i<this->dimension;)
        if(strchr(vocale,this->sir[i]))
     {
         strcpy(this->sir+i,this->sir+i+1);
         this->dimension--;
     }
     else
        i++;
 }

 void Sir::RemoveVocaleFirstN(unsigned int n)
 {
     for(unsigned int i=0;i<this->dimension && n>0;)
        if(strchr(vocale,this->sir[i]))
     {
         strcpy(this->sir+i,this->sir+i+1);
         this->dimension--;
         n--;
     }
     else
        i++;
 }

 void Sir::RemoveVocaleLastN(unsigned int n)
 {
     rev(this->sir);
     for(unsigned int i=0;i<this->dimension && n>0;)
        if(strchr(vocale,this->sir[i]))
     {
         n--;
         strcpy(this->sir+i,this->sir+i+1);
         this->dimension--;
     }
     else
        i++;
     rev(this->sir);
 }

 void Sir::RemoveConsoaneAll()
 {
     for(unsigned int i=0;i<this->dimension;)
        if(isalpha(this->sir[i]))
     {
         if(!strchr(vocale,this->sir[i]))
         {
             strcpy(this->sir+i,this->sir+i+1);
             this->dimension--;
         }
         else
            i++;
     }
     else
        i++;
 }

 void Sir::RemoveConsoaneFirstN(unsigned int n)
 {
     for(unsigned int i=0;i<this->dimension && n>0;)
        if(isalpha(this->sir[i]))
     {
         if(!strchr(vocale,this->sir[i]))
         {
             strcpy(this->sir+i,this->sir+i+1);
             this->dimension--;
             n--;
         }
         else
            i++;
     }
     else
        i++;
 }

 void Sir::RemoveConsoaneLastN(unsigned int n)
 {
     rev(this->sir);
      for(unsigned int i=0;i<this->dimension && n>0;)
        if(isalpha(this->sir[i]))
     {
         if(!strchr(vocale,this->sir[i]))
         {
             strcpy(this->sir+i,this->sir+i+1);
             this->dimension--;
             n--;
         }
         else
            i++;
     }
     else
        i++;
    rev(this->sir);
 }

 void Sir::RemoveSymbols()
 {
     for(unsigned int i=0;i<this->dimension;)
        if(strchr(simboluri,this->sir[i]))
     {
         this->dimension--;
         strcpy(this->sir+i,this->sir+1+i);
     }
     else
        i++;
     p=strchr(this->sir,'"');
     while(p)
     {
         strcpy(p,p+1);
         this->dimension--;
         p=strchr(p,'"');
     }
 }

 void Sir::RemoveFirstCh()
 {
     strcpy(this->sir,this->sir+1);
     this->dimension--;
 }

 void Sir::RemoveFirstChN(unsigned int n)
 {
     strcpy(this->sir,this->sir+n);
     this->dimension-=n;
 }

 void Sir::RemoveLastCh()
 {
     strcpy(this->sir+this->dimension-1,this->sir+this->dimension);
     this->dimension--;
 }

 void Sir::RemoveLastChN(unsigned int n)
 {
     strcpy(this->sir+this->dimension-n,this->sir+this->dimension);
     this->dimension-=n;
 }

 void Sir::ReplaceChToChAll(char in,char out)
 {
     if(out<96 && isalpha(out))
        out+=32;
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p)
     {
         numara=p-clone;
         this->sir[numara]=in;
         p=strchr(p+1,out);
     }
 }

 void Sir::ReplaceChToChFirstN(char in,char out,unsigned int n)
 {
      if(out<96 && isalpha(out))
        out+=32;
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         this->sir[numara]=in;
         p=strchr(p+1,out);
     }
 }

 void Sir::ReplaceChToChLastN(char in,char out,unsigned int n)
 {
     rev(this->sir);
       if(out<96 && isalpha(out))
        out+=32;
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p && n>0)
     {
         n--;
         numara=p-clone;
         this->sir[numara]=in;
         p=strchr(p+1,out);
     }
     rev(this->sir);
 }

 void Sir::ReplaceChToStringAll(char in[],char out)
 {
     if(out<96 && isalpha(out))
        out+=32;
     lungime=strlen(in);
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p)
     {
         numara=p-clone;
         strcpy(aux,this->sir+numara+1);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p+1);
         strcpy(p,in);
         strcpy(p+lungime,aux);

         p=strchr(p+lungime,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceChToStringFirstN(char in[],char out,unsigned int n)
 {
     if(out<96 && isalpha(out))
        out+=32;
     lungime=strlen(in);
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p && n>0)
     {
         numara=p-clone;
         n--;
         strcpy(aux,this->sir+numara+1);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p+1);
         strcpy(p,in);
         strcpy(p+lungime,aux);

         p=strchr(p+lungime,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceChToStringLastN(char in[],char out,unsigned int n)
 {
     rev(this->sir);
     rev(in);
      if(out<96 && isalpha(out))
        out+=32;
     lungime=strlen(in);
     strcpy(clone,this->sir);
     micmic(clone);
     p=strchr(clone,out);
     while(p && n>0)
     {
         numara=p-clone;
         n--;
         strcpy(aux,this->sir+numara+1);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lungime,aux);

         strcpy(aux,p+1);
         strcpy(p,in);
         strcpy(p+lungime,aux);

         p=strchr(p+lungime,out);
     }
     this->dimension=strlen(this->sir);
     rev(this->sir);
 }

 void Sir::ReplaceStringToChAll(char in,char out[])
 {
     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);
     while(p)
     {
         numara=p-clone;

         this->sir[numara]=in;
         strcpy(this->sir+numara+1,this->sir+numara+lungime);

         p[0]=in;
         strcpy(p+1,p+lungime);

         p=strstr(p+1,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceStringToChFirstN(char in,char out[],unsigned int n)
 {
     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);
     while(p && n>0)
     {
         numara=p-clone;
         n--;

         this->sir[numara]=in;
         strcpy(this->sir+numara+1,this->sir+numara+lungime);

         p[0]=in;
         strcpy(p+1,p+lungime);

         p=strstr(p+1,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceStringToChLastN(char in,char out[],unsigned int n)
 {
     rev(this->sir);
     rev(out);
     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);
     while(p && n>0)
     {
         numara=p-clone;
         n--;

         this->sir[numara]=in;
         strcpy(this->sir+numara+1,this->sir+numara+lungime);

         p[0]=in;
         strcpy(p+1,p+lungime);

         p=strstr(p+1,out);
     }
     this->dimension=strlen(this->sir);
     rev(this->sir);
 }

 void Sir::ReplaceStringToStringAll(char in[],char out[])
 {
     unsigned int lin=strlen(in);

     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);

     while(p)
     {
         numara=p-clone;
         strcpy(aux,this->sir+numara+lungime);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lin,aux);

         strcpy(aux,p+lungime);
         strcpy(p,in);
         strcpy(p+lin,aux);

         p=strstr(p+lin,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceStringToStringFirstN(char in[],char out[],unsigned int n)
 {
     unsigned int lin=strlen(in);

     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);

     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(aux,this->sir+numara+lungime);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lin,aux);

         strcpy(aux,p+lungime);
         strcpy(p,in);
         strcpy(p+lin,aux);

         p=strstr(p+lin,out);
     }
     this->dimension=strlen(this->sir);
 }

 void Sir::ReplaceStringToStringLastN(char in[],char out[], unsigned int n)
 {
     rev(this->sir);
     rev(in);
     rev(out);
     unsigned int lin=strlen(in);

     micmic(out);
     lungime=strlen(out);

     strcpy(clone,this->sir);
     micmic(clone);

     p=strstr(clone,out);

     while(p && n>0)
     {
         n--;
         numara=p-clone;
         strcpy(aux,this->sir+numara+lungime);
         strcpy(this->sir+numara,in);
         strcpy(this->sir+numara+lin,aux);

         strcpy(aux,p+lungime);
         strcpy(p,in);
         strcpy(p+lin,aux);

         p=strstr(p+lin,out);
     }
     this->dimension=strlen(this->sir);
     rev(this->sir);
 }

 void Sir::Censor(char cine[])
 {
     strcpy(aux,cine);
     lungime=strlen(cine);
     for(unsigned int i=0;i<lungime;i++)
        aux[i]='*';

    micmic(cine);
    strcpy(clone,this->sir);
    micmic(clone);

    p=strstr(clone,cine);
    while(p)
    {
        numara=p-clone;
        strcpy(prieten,this->sir+numara+lungime);
        strcpy(this->sir+numara,aux);
        strcpy(this->sir+numara+lungime,prieten);

        strcpy(prieten,p+lungime);
        strcpy(p,aux);
        strcpy(p+lungime,prieten);

        p=strstr(p+lungime,cine);
    }
 }

 void Sir::CaesarEncrypt()
 {
     for(unsigned int i=0;i<this->dimension;i++)
        if(this->sir[i]>=32 && this->sir[i]<=47)
            this->sir[i]=(this->sir[i]+this->CaesarKey%16-32)%16+32;
     else
        if(this->sir[i]>=48 && this->sir[i]<=57)
            this->sir[i]=(this->sir[i]+this->CaesarKey%10-48)%10+48;
     else
        if(this->sir[i]>=58 && this->sir[i]<=64)
            this->sir[i]=(this->sir[i]+this->CaesarKey%7-58)%7+58;
     else
        if(this->sir[i]>=65 && this->sir[i]<=90)
            this->sir[i]=(this->sir[i]+this->CaesarKey%26-65)%26+65;
     else
        if(this->sir[i]>=91 && this->sir[i]<=96)
            this->sir[i]=(this->sir[i]+this->CaesarKey%6-91)%6+91;
     else
        if(this->sir[i]>=97 && this->sir[i]<=122)
            this->sir[i]=(this->sir[i]+this->CaesarKey%26-97)%26+97;
     else
        if(this->sir[i]>=123 && this->sir[i]<=126)
            this->sir[i]=(this->sir[i]+this->CaesarKey%4-123)%4+123;
 }

 void Sir::CaesarDecrypt()
 {
    for(int i=0;i<this->dimension;i++)
        if(this->sir[i]=32 && this->sir[i]<=47)
            this->sir[i]=(this->sir[i]+16-this->CaesarKey%16-32)%16+32;
    else
        if(this->sir[i]>=48 && this->sir[i]<=57)
            this->sir[i]=(this->sir[i]+10-this->CaesarKey%10-48)%10+48;
    else
        if(this->sir[i]>=58 && this->sir[i]<=64)
            this->sir[i]=(this->sir[i]+7-this->CaesarKey%7-58)%7+58;
    else
        if(this->sir[i]>=65 && this->sir[i]<=90)
            this->sir[i]=(this->sir[i]+26-this->CaesarKey%26-65)%26+65;
    else
        if(this->sir[i]>=91 && this->sir[i]<=96)
            this->sir[i]=(this->sir[i]+6-this->CaesarKey%6-91)%6+91;
    else
        if(this->sir[i]>=97 && this->sir[i]<=122)
            this->sir[i]=(this->sir[i]+26-this->CaesarKey%26-97)%26+97;
    else
        if(this->sir[i]>=123 && this->sir[i]<=126)
            this->sir[i]=(this->sir[i]+4-this->CaesarKey%4-123)%4+123;
 }
