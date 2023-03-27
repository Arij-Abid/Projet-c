#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct
{
    char j[20];
    char m[20];
    char a[20];
}date;

typedef struct
{
    char rue[20];
    char ville[20];
    char codep[5];
}adr;

typedef struct
{
    char numtel[10];
    char nom[21];
    char prenom[21];
    date dn;
    adr adresse;
    char email[30];
}repertoire;

struct cellule1
{
    repertoire info;
    struct cellule1* suiv;
};
typedef struct cellule1* liste;


#endif // STRUCTURE_H_INCLUDED
