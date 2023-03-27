#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include<wingdi.h>
#include<string.h>
#include <tchar.h>
#include "myconio.h"
#include <stdio.h>
#include <windows.h>
#include"structure.h"
#include"validation.h"
#include"saisie.h"
#define btn_ajou 4
#define btn_an 5
#define btn_ajt_t 99
#define btn_ajt_q 2
#define btn_ajt_p 3
#define btn_sup_pos 88
#define btn_sup_tel 11
#define btn_sup_ville 12
#define btn_sup_indicatif 13
#define btn_modif_tel 77
#define btn_modif_adresse 66
#define btn_aff_tel 123
#define btn_aff_nom 789
#define btn_aff_ind 555
#define btn_aff_ville 623
#define vprenom 33

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;
liste l;
int t_num,t_nom=0,t_prenom,reponse,tt,nn,posi;
char x[50][50];
char rep1[]="rep.txt";
char n_c[5];
FILE *fp=NULL;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");




int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Répertoire Télephonique"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);


    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

void affichage(HWND hwnd)
{
    FILE* file = fopen("affiche.txt", "r");
    char line[100000]="";
    char all[100000]="";

    while (fgets(line, sizeof(line), file))
        {
            //printf("%s", line);
            strcat(all,line);
            strcat(all,"\r\n");
        }
    SetWindowText(zone_aff,all);
    fclose(file);
}


void effacer_tout_fenetre( HWND hwnd)
{
            DestroyWindow(a);
             DestroyWindow(b);
             DestroyWindow(num);
             DestroyWindow(d);
             DestroyWindow(nom);
             DestroyWindow(f);
             DestroyWindow(prenom);
             DestroyWindow(z);
             DestroyWindow(jour);
             DestroyWindow(mois);
             DestroyWindow(annee);
             DestroyWindow(h);
             DestroyWindow(i);
             DestroyWindow(rue);
             DestroyWindow(k);
             DestroyWindow(ville);
             DestroyWindow(m);
              DestroyWindow(code_pos);
             DestroyWindow(o);
             DestroyWindow(mail);
             DestroyWindow(y);
             DestroyWindow(position);
             DestroyWindow(s);
             DestroyWindow(t);
             DestroyWindow(contact);
             DestroyWindow(num_contact);
             DestroyWindow(ajt_t);
             DestroyWindow(ajt_q);
             DestroyWindow(ajt_pos);
             DestroyWindow(sup_pos);
             DestroyWindow(sup_tel);
             DestroyWindow(sup_ville);
             DestroyWindow(sup_ind);
             DestroyWindow(ind);
             DestroyWindow(st_adresse);
             DestroyWindow(st_nouvelle_num);
             DestroyWindow(modif_adresse);
             DestroyWindow(modif_tel);
             DestroyWindow(new_num);
             DestroyWindow(aff_rang);
             DestroyWindow(aff_num);
             DestroyWindow(aff_nom);
             DestroyWindow(aff_ind);
             DestroyWindow(aff_ville);
             DestroyWindow(aff_prenom);
             DestroyWindow(aff_date);
             DestroyWindow(aff_rue);
             DestroyWindow(aff_ville);
             DestroyWindow(aff_code_pos);
             DestroyWindow(aff_mail);
             DestroyWindow(zone_aff);
             DestroyWindow(jj);
             DestroyWindow(mm);
             DestroyWindow(aaaa);

}


void zone_affichage(HWND hwnd)
{
    zone_aff=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD |  ES_MULTILINE | WS_VSCROLL | WS_HSCROLL | ES_AUTOHSCROLL | WS_BORDER  ,10,30,1200,650,hwnd,NULL,NULL,NULL);
    SendMessage(zone_aff,EM_SETREADONLY,TRUE ,NULL);
}

void interface_info(HWND hwnd){

    //int xreserve=200;
    //xcenter=x/2;
//    xtest=100;
    //ycenter=y/2;

    //a=CreateWindowEx(0,"button","reserve",WS_VISIBLE | WS_CHILD  | BS_CENTER,450,150,100,30,handle,(HMENU)NULL,NULL,NULL);
//    b=CreateWindowEx(0,"button","available rooms",WS_VISIBLE | WS_CHILD | BS_CENTER,700,300,250,25,handle,NULL,NULL,NULL);
    /*crée une text*/
    taille=taille_liste(l);
    itoa(taille+1,n_c,10);

                a=CreateWindow(TEXT("static"),TEXT("*******************************************Creation Contacts*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                /*crée une zone de text */
                contact=CreateWindow(TEXT("static"),TEXT("Contact N"),WS_VISIBLE| WS_CHILD| WS_BORDER,200,100,70,30,hwnd,NULL,NULL,NULL);
                num_contact=CreateWindow(TEXT("STATIC"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,270,100,40,30,hwnd,NULL,NULL,NULL);
                SetWindowText(num_contact,n_c);
                /*saisie numéro*/
                b=CreateWindow(TEXT("static"),TEXT("Numero====>"),WS_VISIBLE| WS_CHILD| WS_BORDER  ,450,140,100,30,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD |  ES_NUMBER | WS_BORDER ,580,140,70,30,hwnd,NULL,NULL,NULL);
                /*saisie nom*/
                d=CreateWindow(TEXT("static"),TEXT("Nom=======>"),WS_VISIBLE| WS_CHILD | WS_BORDER,450,180,100,30,hwnd,NULL,NULL,NULL);
                nom=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | WS_BORDER,580,180,100,30,hwnd,NULL,NULL,NULL);
                /*saisie prénom*/
                f=CreateWindow(TEXT("static"),TEXT("Prénom====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,220,100,30,hwnd,NULL,NULL,NULL);
                prenom=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,220,100,30,hwnd,NULL,NULL,NULL);
                /*date de naissance*/
                z=CreateWindow(TEXT("static"),TEXT("Date de Naissance====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,300,120,35,hwnd,NULL,NULL,NULL);
                jj=CreateWindow(TEXT("static"),TEXT("JJ"),WS_VISIBLE| WS_CHILD| WS_BORDER,580,270,18,25,hwnd,NULL,NULL,NULL);
                mm=CreateWindow(TEXT("static"),TEXT("MM"),WS_VISIBLE| WS_CHILD| WS_BORDER,610,270,25,25,hwnd,NULL,NULL,NULL);
                aaaa=CreateWindow(TEXT("static"),TEXT("AAAA"),WS_VISIBLE| WS_CHILD| WS_BORDER,640,270,35,25,hwnd,NULL,NULL,NULL);
                jour=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,300,20,30,hwnd,NULL,NULL,NULL);
                mois=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,610,300,20,30,hwnd,NULL,NULL,NULL);
                annee=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,640,300,38,30,hwnd,NULL,NULL,NULL);
               //  h=CreateWindow(TEXT("static"),TEXT("Les conrdonnes d'adresse"),WS_VISIBLE| WS_CHILD,480,300,180,30,hwnd,NULL,NULL,NULL);
                /*saisie rue*/
                i=CreateWindow(TEXT("static"),TEXT("Rue=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,350,100,30,hwnd,NULL,NULL,NULL);
                rue=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,650,350,100,30,hwnd,NULL,NULL,NULL);
                /*saisie ville*/
                k=CreateWindow(TEXT("static"),TEXT("Ville=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,400,100,30,hwnd,NULL,NULL,NULL);
                ville=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,650,400,100,30,hwnd,NULL,NULL,NULL);
                /*saisie code postale*/
                m=CreateWindow(TEXT("static"),TEXT("Code Postale=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,450,120,40,hwnd,NULL,NULL,NULL);
                code_pos=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,650,450,38,40,hwnd,NULL,NULL,NULL);
                /*saisie mail*/
                o=CreateWindow(TEXT("static"),TEXT("Adresse Mail=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,500,100,40,hwnd,NULL,NULL,NULL);
                mail=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,500,150,40,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Position====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,550,100,40,hwnd,NULL,NULL,NULL);
                position=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,550,200,40,hwnd,NULL,NULL,NULL);


                //gotoxy(25,10);
                /*creé un button ajouter*/
                s=CreateWindow(TEXT("BUTTON"),TEXT("Ajouter"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,600,600,80,50,hwnd,(HMENU) btn_ajou,NULL,NULL);



    //c=CreateWindowEx(0,"button","remove reservation",WS_VISIBLE | WS_CHILD | BS_CENTER,(windowsize.right-windowsize.left)/2-(xreserve/2),74,xreserve,25,handle,NULL,NULL,NULL);
    //d=CreateWindowEx(0,"button","display reservations",WS_VISIBLE | WS_CHILD | BS_CENTER,(windowsize.right-windowsize.left)/2-(xreserve/2),101,xreserve,25,handle,NULL,NULL,NULL);
    //e=CreateWindowEx(0,"button","search for a client",WS_VISIBLE | WS_CHILD | BS_CENTER,(windowsize.right-windowsize.left)/2-(xreserve/2),128,xreserve,25,handle,NULL,NULL,NULL);

    //name = CreateWindowEx(WS_EX_TRANSPARENT,"edit","...",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE,(windowsize.right-windowsize.left)/2-(xtest/2),156,xtest,50,handle,NULL,NULL,NULL);
    //f=CreateWindowEx(0,"button","test",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,(windowsize.right-windowsize.left)/2-(xtest/2),208,xtest,25,handle,(HMENU)NULL,NULL,NULL);
}





/********MAJ*****/




void interface_info_maj_pos(HWND hwnd)
{
    taille=taille_liste(l);
    itoa(taille+1,n_c,10);
    printf("%d",taille);

                a=CreateWindow(TEXT("static"),TEXT("*******************************************MAJ POSITION*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                /*crée une zone de text */
                contact=CreateWindow(TEXT("static"),TEXT("Contact N"),WS_VISIBLE| WS_CHILD| WS_BORDER,200,100,70,30,hwnd,NULL,NULL,NULL);
                num_contact=CreateWindow(TEXT("STATIC"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,270,100,40,30,hwnd,NULL,NULL,NULL);
                SetWindowText(num_contact,n_c);
                /*saisie numéro*/
                b=CreateWindow(TEXT("static"),TEXT("Numero====>"),WS_VISIBLE| WS_CHILD | WS_BORDER ,450,140,100,30,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD |  ES_NUMBER | WS_BORDER ,580,140,70,30,hwnd,NULL,NULL,NULL);
                /*saisie nom*/
                d=CreateWindow(TEXT("static"),TEXT("Nom=======>"),WS_VISIBLE| WS_CHILD | WS_BORDER ,450,180,100,30,hwnd,NULL,NULL,NULL);
                nom=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | WS_BORDER,580,180,100,30,hwnd,NULL,NULL,NULL);
                /*saisie prénom*/
                f=CreateWindow(TEXT("static"),TEXT("Prénom====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,220,100,30,hwnd,NULL,NULL,NULL);
                prenom=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,220,100,30,hwnd,NULL,NULL,NULL);
                /*date de naissance*/
                z=CreateWindow(TEXT("static"),TEXT("Date de Naissance====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,300,120,35,hwnd,NULL,NULL,NULL);
                jj=CreateWindow(TEXT("static"),TEXT("JJ"),WS_VISIBLE| WS_CHILD| WS_BORDER,580,270,18,25,hwnd,NULL,NULL,NULL);
                mm=CreateWindow(TEXT("static"),TEXT("MM"),WS_VISIBLE| WS_CHILD| WS_BORDER,610,270,25,25,hwnd,NULL,NULL,NULL);
                aaaa=CreateWindow(TEXT("static"),TEXT("AAAA"),WS_VISIBLE| WS_CHILD| WS_BORDER,640,270,35,25,hwnd,NULL,NULL,NULL);
                jour=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,300,20,30,hwnd,NULL,NULL,NULL);
                mois=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,610,300,20,30,hwnd,NULL,NULL,NULL);
                annee=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,640,300,38,30,hwnd,NULL,NULL,NULL);
                /*saise les cordonnes d'adresse*/
               //  h=CreateWindow(TEXT("static"),TEXT("Les conrdonnes d'adresse"),WS_VISIBLE| WS_CHILD,480,300,180,30,hwnd,NULL,NULL,NULL);
                /*saisie rue*/
                i=CreateWindow(TEXT("static"),TEXT("Rue=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,350,100,30,hwnd,NULL,NULL,NULL);
                rue=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,650,350,100,30,hwnd,NULL,NULL,NULL);
                /*saisie ville*/
                k=CreateWindow(TEXT("static"),TEXT("Ville=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,400,100,30,hwnd,NULL,NULL,NULL);
                ville=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,650,400,100,30,hwnd,NULL,NULL,NULL);
                /*saisie code postale*/
                m=CreateWindow(TEXT("static"),TEXT("Code Postale=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,520,450,120,40,hwnd,NULL,NULL,NULL);
                code_pos=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,650,450,38,40,hwnd,NULL,NULL,NULL);
                /*saisie mail*/
                o=CreateWindow(TEXT("static"),TEXT("Adresse Mail=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,500,100,40,hwnd,NULL,NULL,NULL);
                mail=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,500,150,40,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Ajouter en===>"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,600,100,30,hwnd,NULL,NULL,NULL);
                position=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,610,600,30,30,hwnd,NULL,NULL,NULL);


                //gotoxy(25,10);
                /*creé un button ajouter*/
                //s=CreateWindow(TEXT("BUTTON"),TEXT("Ajouter"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,500,600,80,50,hwnd,(HMENU) btn_ajou,NULL,NULL);


                //gotoxy(25,10);
                /*creé un button ajouter*/
                ajt_t=CreateWindow(TEXT("BUTTON"),TEXT("Tete"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,600,560,50,30,hwnd,(HMENU) btn_ajt_t,NULL,NULL);
                ajt_q=CreateWindow(TEXT("BUTTON"),TEXT("Queue"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,600,640,50,30,hwnd,(HMENU) btn_ajt_q,NULL,NULL);
                ajt_pos=CreateWindow(TEXT("BUTTON"),TEXT("Pos"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,650,600,50,30,hwnd,(HMENU) btn_ajt_p,NULL,NULL);

                /*creé un button annuler*/
                //t=CreateWindow(TEXT("BUTTON"),TEXT("Annuler"),WS_VISIBLE | WS_CHILD | WS_BORDER ,600,650,80,50,hwnd,(HMENU)btn_an,NULL,NULL);

}


void interface_supp_pos(HWND hwnd)
{

                a=CreateWindow(TEXT("static"),TEXT("*******************************************Supprimer d'un position*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("POsition=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,200,120,40,hwnd,NULL,NULL,NULL);
                position=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,200,200,40,hwnd,NULL,NULL,NULL);
                sup_pos=CreateWindow(TEXT("BUTTON"),TEXT("Supprimer"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_sup_pos,NULL,NULL);

}

void interface_supp_tel(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("*******************************************Supprimer d'un telephone*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Numéro=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,200,100,40,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,200,70,40,hwnd,NULL,NULL,NULL);
                sup_tel=CreateWindow(TEXT("BUTTON"),TEXT("Supprimer"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_sup_tel,NULL,NULL);

}

void interface_supp_ville(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("*******************************************Supprimer ville*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Ville=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,200,100,40,hwnd,NULL,NULL,NULL);
                ville=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER ,580,200,100,40,hwnd,NULL,NULL,NULL);
                sup_ville=CreateWindow(TEXT("BUTTON"),TEXT("Supprimer"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_sup_ville,NULL,NULL);

}
void interface_supp_ind(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("*******************************************Supprimer indicatif*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Indicatif=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,200,100,40,hwnd,NULL,NULL,NULL);
                ind=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,620,200,21,40,hwnd,NULL,NULL,NULL);
                sup_ind=CreateWindow(TEXT("BUTTON"),TEXT("Supprimer"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_sup_indicatif,NULL,NULL);

}

void interface_modification_tel(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("*******************************************Modification Telephone*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                /***ancient num****/
                b=CreateWindow(TEXT("static"),TEXT("Ancient Numéro=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,100,100,40,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,100,70,40,hwnd,NULL,NULL,NULL);
                /*** noveauo num***/
                st_nouvelle_num=CreateWindow(TEXT("static"),TEXT(" Nouvelle Numéro=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,150,100,40,hwnd,NULL,NULL,NULL);
                new_num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,150,70,40,hwnd,NULL,NULL,NULL);
                modif_tel=CreateWindow(TEXT("BUTTON"),TEXT("Modifier"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,200,80,50,hwnd,(HMENU) btn_modif_tel,NULL,NULL);

}

void interface_modification_adresse(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("*******************************************Modification Adresse*******************************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                b=CreateWindow(TEXT("static"),TEXT("Numéro=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,100,100,40,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,100,70,40,hwnd,NULL,NULL,NULL);
                st_adresse=CreateWindow(TEXT("static"),TEXT("*************Adresse*************"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,200,200,30,hwnd,NULL,NULL,NULL);
                i=CreateWindow(TEXT("static"),TEXT("Rue=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,250,100,30,hwnd,NULL,NULL,NULL);
                rue=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,250,200,30,hwnd,NULL,NULL,NULL);
                /*saisie ville*/
                k=CreateWindow(TEXT("static"),TEXT("Ville=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,300,100,30,hwnd,NULL,NULL,NULL);
                ville=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,580,300,200,30,hwnd,NULL,NULL,NULL);
                /*saisie code postale*/
                m=CreateWindow(TEXT("static"),TEXT("Code Postale=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,350,120,40,hwnd,NULL,NULL,NULL);
                code_pos=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,350,35,40,hwnd,NULL,NULL,NULL);

                modif_adresse=CreateWindow(TEXT("BUTTON"),TEXT("Modifier"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,450,80,50,hwnd,(HMENU) btn_modif_adresse,NULL,NULL);

}


void interface_aff_tel(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("************************************Afficher les information d'une Telephone********************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,700,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Numéro=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,450,200,100,40,hwnd,NULL,NULL,NULL);
                num=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | ES_NUMBER| WS_BORDER,580,200,70,40,hwnd,NULL,NULL,NULL);
                aff_num=CreateWindow(TEXT("BUTTON"),TEXT("Afficher"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_aff_tel,NULL,NULL);

}


void interface_aff_nom(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("************************************Afficher les information d'un nom********************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,650,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Nom=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,200,100,40,hwnd,NULL,NULL,NULL);
                nom=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | WS_BORDER,630,200,70,40,hwnd,NULL,NULL,NULL);
                aff_nom=CreateWindow(TEXT("BUTTON"),TEXT("Afficher"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_aff_nom,NULL,NULL);

}


void interface_aff_ind(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("************************************Afficher les information d'une indicatif********************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,750,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("indicatif=====>"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,200,100,40,hwnd,NULL,NULL,NULL);
                ind=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD | WS_BORDER,630,200,17,40,hwnd,NULL,NULL,NULL);
                aff_ind=CreateWindow(TEXT("BUTTON"),TEXT("Afficher"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_aff_ind,NULL,NULL);

}



void interface_aff_ville(HWND hwnd)
{
                a=CreateWindow(TEXT("static"),TEXT("************************************Afficher les information d'une ville********************************"),WS_VISIBLE| WS_CHILD| WS_BORDER,250,50,650,30,hwnd,NULL,NULL,NULL);
                y=CreateWindow(TEXT("static"),TEXT("Ville=======>"),WS_VISIBLE| WS_CHILD| WS_BORDER,500,200,100,40,hwnd,NULL,NULL,NULL);
                ville=CreateWindow(TEXT("Edit"),TEXT(""),WS_VISIBLE| WS_CHILD| WS_BORDER,630,200,70,40,hwnd,NULL,NULL,NULL);
                aff_ville=CreateWindow(TEXT("BUTTON"),TEXT("Afficher"),WS_VISIBLE | WS_CHILD | WS_BORDER  ,550,300,80,50,hwnd,(HMENU) btn_aff_ville,NULL,NULL);

}

void interface_bar_affichage(HWND hwnd)
{

        aff_rang=CreateWindow(TEXT("static"),TEXT("Rang"),WS_VISIBLE| WS_CHILD |ES_CENTER  | WS_BORDER,10,10,40,20,hwnd,NULL,NULL,NULL);
        aff_num=CreateWindow(TEXT("static"),TEXT("Numéro"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,80,10,60,20,hwnd,NULL,NULL,NULL);
        aff_nom=CreateWindow(TEXT("static"),TEXT("Nom"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,200,10,50,20,hwnd,NULL,NULL,NULL);
        aff_prenom=CreateWindow(TEXT("static"),TEXT("Prénom"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,320,10,50,20,hwnd,NULL,NULL,NULL);
        aff_date=CreateWindow(TEXT("static"),TEXT("Date de naisance"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,430,10,150,20,hwnd,NULL,NULL,NULL);
        aff_rue=CreateWindow(TEXT("static"),TEXT("Rue"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,600,10,40,20,hwnd,NULL,NULL,NULL);
        aff_ville=CreateWindow(TEXT("static"),TEXT("Ville"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,720,10,40,20,hwnd,NULL,NULL,NULL);
        aff_code_pos=CreateWindow(TEXT("static"),TEXT("Code postal"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,820,10,80,20,hwnd,NULL,NULL,NULL);
        aff_mail=CreateWindow(TEXT("static"),TEXT("E-Mail"),WS_VISIBLE| WS_CHILD |ES_CENTER | WS_BORDER,1000,10,50,20,hwnd,NULL,NULL,NULL);

}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp,img;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
        case 1:
            /*
    fp=fopen("rep.txt","r");

            if(v_rec==0 && fp!=NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur de creation", MB_OK | MB_ICONINFORMATION);
                break;
            }

            else
            if( fp!=NULL && v_rec==1)
            {
                MessageBox(hwnd,"les conctacts sont déja creés", "Erreur de creation", MB_OK | MB_ICONINFORMATION);
                break;
            }
            */


            //else
           // {
           fp=fopen("rep.txt","r");
           taille=taille_liste(l);


            if(taille==0 && fp!=NULL)
            {
                MessageBox(hwnd,"Il faut récuperer !!!", "Erreur de creation", MB_OK | MB_ICONERROR);
                break;

            }
            if(taille!=0 && fp!=NULL)
            {
                MessageBox(hwnd,"La creation se fait que un seul fois !!!", "Erreur de creation", MB_OK | MB_ICONINFORMATION);
                break;

            }
            else
            {
                img=LoadImage(NULL,"cr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

                effacer_tout_fenetre(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                 interface_info(hwnd);
                ShowWindow(hwnd,SW_NORMAL);

            }
            /*
            if(fp!=NULL )
            {

            }

            break;

*/




           // }
           break;

        case btn_ajou :


tt=taille_liste(l);
                l=saisie_creation_avec_position(l);
                nn=taille_liste(l);
                if (tt+1==nn)
                {if (MessageBox(hwnd,"Vous voulez ajouter nouvelle contact ?", "Demande d'ajouter", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                    {

                        effacer_tout_fenetre(hwnd);

                interface_info(hwnd);
                    }
                    else
                    {

                        effacer_tout_fenetre(hwnd);

                    }

                }

            break;
            /*
        case btn_an :



                        effacer_tout_fenetre(hwnd);
                        hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);



            break;
*/

            case btn_ajt_t :

            tt=taille_liste(l);
                l=ajouter_tete(l);
                nn=taille_liste(l);
                if (tt+1==nn)
                {
                    effacer_tout_fenetre(hwnd);
                    interface_info_maj_pos(hwnd);
                }
            break;


            case btn_ajt_q :


            tt=taille_liste(l);
                l=ajouter_queue(l);
                nn=taille_liste(l);
                if (tt+1==nn)
                {
                        effacer_tout_fenetre(hwnd);
                        interface_info_maj_pos(hwnd);
                }
            break;

            case btn_ajt_p :

                tt=taille_liste(l);
                l=ajouter_position(l);
                nn=taille_liste(l);
                if (tt+1==nn)
                {
                    effacer_tout_fenetre(hwnd);
                    interface_info_maj_pos(hwnd);
                }

            break;

            case btn_sup_pos :
            taille=taille_liste(l);
            GetWindowText(position,textsaved,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire

                      if(atoi(textsaved)>=taille || atoi(textsaved)==0  || strlen(textsaved)==0 || atoi(textsaved)==1 )
                      {
                          MessageBox(hwnd,"position erroné ou champ vide","Erreur position",MB_OK);
                      }
                      else
                      {
                          GetWindowText(position,textsaved,20);
                          pos=atoi(textsaved);
                          suppression_pos_tel(l,pos);
                          MessageBox(hwnd,"La mise à jour a été effectuer avec succées", "succès", MB_OK | MB_ICONQUESTION );
                          effacer_tout_fenetre(hwnd);
                          interface_supp_pos(hwnd);

                      }

                break;


            case btn_sup_tel :

                GetWindowText(num,textsaved,20);
             l=suppression_tel(l,textsaved);
             effacer_tout_fenetre(hwnd);
             interface_supp_tel(hwnd);



                break;

            case btn_sup_ville :

             GetWindowText(ville,textsaved,20);
             if((recherche_ville(l,textsaved))==NULL)
             {
                 MessageBox(hwnd,"Ville invalide", "Erreur suppression ville", MB_OK | MB_ICONQUESTION );
                 break;
             }
             else
             {


                do
             {
                 l=suppression_ville(l,textsaved);

             }
             while((recherche_ville(l,textsaved))!=NULL);
             MessageBox(hwnd,"suppression ville terminer", "Suppression ville", MB_OK | MB_ICONQUESTION );
             effacer_tout_fenetre(hwnd);
             interface_supp_ville(hwnd);
             }



                break;

            case btn_sup_indicatif :


             GetWindowText(ind,textsaved,20);
            l=suppression_indicatif(l,textsaved);
            MessageBox(hwnd,"Suppression indicatif termienr","Succeés suppression",MB_OK |MB_ICONINFORMATION);
            effacer_tout_fenetre(hwnd);
            interface_supp_ind(hwnd);

                break;

            case btn_modif_tel:

                GetWindowText(num,ancien_num,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                      if(strlen(ancien_num)!=8 || strlen(ancien_num)==0 || recherche_tel(l,ancien_num)==NULL)
                      {

                          MessageBox(hwnd,"le numéro est < à 8 ou  le numéro n'exsit pas ou le champ numéro est vide","Erreur Numéro",MB_OK);
                            break;
                      }
                      else
                      {
                          GetWindowText(new_num,nouveau_num,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                      if(strlen(nouveau_num)!=8 || strlen(nouveau_num)==0 || recherche_tel(l,nouveau_num))
                      {
                          MessageBox(hwnd,"le numéro est < à 8 ou  le numéro est exsit déja  ou le champ numéro est vide","Erreur Numéro",MB_OK);
                            break;
                      }
                      else
                      {
                          modification_tel_donne(l,ancien_num,nouveau_num);

                        MessageBox(hwnd,"Modification du numéro terminer","succeés",MB_OK|MB_ICONINFORMATION);
                        effacer_tout_fenetre(hwnd);
                        interface_modification_tel(hwnd);
                      }
                      }

                break;

            case btn_modif_adresse :

                GetWindowText(num,num_test_adress,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                      if(strlen(num_test_adress)!=8 || strlen(num_test_adress)==0 || recherche_tel(l,num_test_adress)==NULL)
                      {

                          MessageBox(hwnd,"le numéro est < à 8 ou  le numéro n'exsit pas ou le champ numéro est vide","Erreur Numéro",MB_OK);
                            break;
                      }
                      else
                      {
                                    GetWindowText(rue,nvadresse.rue,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                                    if(strlen(nvadresse.rue)==0)
                                        {
                                            MessageBox(hwnd,"Le champ rue est vide","Erreur rue",MB_OK);
                                            break;
                                        }
                                    else
                                        {

                                            GetWindowText(ville,nvadresse.ville,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                                            if(strlen(nvadresse.ville)==0)
                                                {
                                                    MessageBox(hwnd,"Le champ ville est vide","Erreur ville",MB_OK);
                                                    break;
                                                }

                                            else
                                                {
                                                        GetWindowText(code_pos,nvadresse.codep,20); // c: text fiel ; rep.numtel : placement d'enregistrement ; 20 : 20-1=19 le nombre des caractéres lire
                                                        if(strlen(nvadresse.codep)==0 || strlen(nvadresse.codep)!=4)
                                                            {
                                                                MessageBox(hwnd,"Le champ code postal est vide","Erreur code postal",MB_OK);
                                                                break;
                                                            }
                                                        else
                                                            {
                                                                modification_adresse_donnee(l,num_test_adress,nvadresse);
                                                                MessageBox(hwnd,"Modification terminer","succeés modification",MB_OK|MB_ICONINFORMATION);
                                                                effacer_tout_fenetre(hwnd);
                                                                interface_modification_adresse(hwnd);
                                                            }

                                                }
                                        }
                        }

                break;


            case btn_aff_tel :
                GetWindowText(num,textsaved,20);

                if(strlen(textsaved)!=8 || strlen(textsaved)==0 || recherche_tel(l,textsaved)==NULL)
                      {

                          MessageBox(hwnd,"le numéro est < à 8 ou  le numéro n'exsit pas ou le champ numéro est vide","Erreur Numéro",MB_OK);
                            break;
                      }
                      else
                      {
                            GetWindowText(num,textsaved,20);
                            enregistrer_tel(l,textsaved);
                            effacer_tout_fenetre(hwnd);
                          interface_bar_affichage(hwnd);
                            zone_affichage(hwnd);
                            affichage(hwnd);
                      }
                break;


        case btn_aff_nom :

            GetWindowText(nom,textsaved,20);

                if(strlen(textsaved)==0 || recherche_nom(l,textsaved)==NULL)
                      {

                          MessageBox(hwnd,"le nom n'exsit pas ou le champ nom est vide","Erreur Nom",MB_OK);
                            break;
                      }
                      else
                      {
                            GetWindowText(nom,textsaved,20);
                            enregistrer_nom(l,textsaved);
                            effacer_tout_fenetre(hwnd);
                          interface_bar_affichage(hwnd);
                            zone_affichage(hwnd);
                            affichage(hwnd);

                      }

                break;


        case btn_aff_ind :

            GetWindowText(ind,textsaved,20);

                if(strlen(textsaved)==0 || strlen(textsaved)!=2 ||recherche_indicatif(l,textsaved)==NULL)
                      {

                          MessageBox(hwnd,"le indicatif n'exsit pas ou le champ indicatif est vide","Erreur indicatif",MB_OK);
                            break;
                      }
                      else
                      {
                            GetWindowText(ind,textsaved,20);
                            enregistrer_indicatif(l,textsaved);
                            effacer_tout_fenetre(hwnd);
                          interface_bar_affichage(hwnd);
                            zone_affichage(hwnd);
                            affichage(hwnd);


                      }


            break;


        case btn_aff_ville :


        GetWindowText(ville,textsaved,20);

                if(strlen(textsaved)==0  ||recherche_ville(l,textsaved)==NULL)
                      {

                          MessageBox(hwnd,"le ville n'exsit pas ou le champ ville est vide","Erreur ville",MB_OK);
                            break;
                      }
                      else
                      {

                            GetWindowText(ville,aff_adr.ville,20);
                            enregistrer_ville(l,aff_adr.ville);
                            effacer_tout_fenetre(hwnd);
                          interface_bar_affichage(hwnd);
                            zone_affichage(hwnd);
                            affichage(hwnd);

                      }

            break;
/*
        case 211:

            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }

            else
            {
                effacer_tout_fenetre(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                interface_info_maj_tete(hwnd);
                 //hBmp=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }


        case 212:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {



                        effacer_tout_fenetre(hwnd);

             interface_info_maj_queue(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                //hBmp=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
            */
        case 213:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
else
            {
                        effacer_tout_fenetre(hwnd);

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                interface_info_maj_pos(hwnd);
                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 221:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {

                        effacer_tout_fenetre(hwnd);

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=supprimer_tete(l);
                MessageBox(hwnd,"La mise à jour a été effectuer avec succées", "succès", MB_OK | MB_ICONQUESTION );
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 222:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                effacer_tout_fenetre(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=supprimer_queue(l);
                MessageBox(hwnd,"La mise à jour a été effectuer avec succées", "succès", MB_OK | MB_ICONQUESTION );
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 223:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                        effacer_tout_fenetre(hwnd);

             interface_supp_pos(hwnd);

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 224:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                        effacer_tout_fenetre(hwnd);

             interface_supp_tel(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 225:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                        effacer_tout_fenetre(hwnd);

             interface_supp_ville(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 226:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                        effacer_tout_fenetre(hwnd);

             interface_supp_ind(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }

        case 227:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {


                        img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                        effacer_tout_fenetre(hwnd);
                        l=suppression_all(l);
                        MessageBox(hwnd,"suppression de tout les contacts est terminer","suppression Terminer",MB_OK| MB_ICONINFORMATION);

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 231:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                        effacer_tout_fenetre(hwnd);

             interface_modification_adresse(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 232:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                                img=LoadImage(NULL,"update-logo.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


                effacer_tout_fenetre(hwnd);
                interface_modification_tel(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 31:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur mise à jour", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

                effacer_tout_fenetre(hwnd);
              interface_bar_affichage(hwnd);
                zone_affichage(hwnd);
                enre_tt(l);
                affichage(hwnd);
   /* FILE* file = fopen("affiche.txt", "r");
    char line[256]="";
    char all[10000]="";

    while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
            strcat(all,line);
            strcat(all,"\r\n");
        }
    SetWindowText(zone_aff,all);
    fclose(file);*/

                system("color F9");
                //affiche2(l);
                ShowWindow(hwnd,SW_HIDE);
                ShowWindow(hwnd,SW_NORMAL);
                break;
            }
        case 32:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur recherche", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                effacer_tout_fenetre(hwnd);
                interface_aff_tel(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 33:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur recherche", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);
                effacer_tout_fenetre(hwnd);
                interface_aff_ind(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 34:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur recherche", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

                effacer_tout_fenetre(hwnd);
                interface_aff_nom(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 35:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur recherche", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

                effacer_tout_fenetre(hwnd);
                interface_aff_ville(hwnd);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 36:
            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur recherche", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {
                img=LoadImage(NULL,"rech.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);


               effacer_tout_fenetre(hwnd);

              interface_bar_affichage(hwnd);
                tri1(l);
                zone_affichage(hwnd);
                enre_tt(l);
                affichage(hwnd);
                system("color F9");
                //affiche2(l);
                ShowWindow(hwnd,SW_HIDE);
                ShowWindow(hwnd,SW_NORMAL);
                break;
            }

        case 41:


            if(l==NULL)
            {
                MessageBox(hwnd,"il faut recuperer", "Erreur d'enregistrement", MB_OK | MB_ICONERROR);
                break;
            }
            else
            {

                effacer_tout_fenetre(hwnd);
                enregistrement_repertoire(l);
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("    BONJOUR 19   \n");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

            }


        case 42:
                       fp=fopen("rep.txt","r");


            if(fp==NULL )
            {
                MessageBox(hwnd,"    le fichier est vide", "Remarque", MB_OK | MB_ICONINFORMATION);
                break;
            }
            else
                {
                    effacer_tout_fenetre(hwnd);
                    l=recuperation_repertoire();
                    MessageBox(hwnd,"      Récuperation terminer", "Succeés recupération", MB_OK | MB_ICONINFORMATION);
                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf("    BONJOUR 20   \n");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;
                }


            case 51:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "projet.pdf", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;


            case 52:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "rep.txt", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;

            case 531:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "Cours chaines de caractères.pdf", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;

            case 532:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "les pointeurs.pdf", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;

            case 533:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "Les structures Cours.pdf", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;

            case 534:



                    effacer_tout_fenetre(hwnd);
                    ShellExecute( NULL, "open", "cours LSC.pdf", NULL, NULL, SW_SHOWNORMAL );

                    system("color F9");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    break;





        case 10:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
        addmenus(hwnd);
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);



            break;


        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);
            DrawState(hdc,NULL,NULL,(long)img,0,0,0,0,0,DST_BITMAP);
            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    //HMENU htp=CreateMenu();
    HMENU up_date=CreateMenu();
    HMENU rech=CreateMenu();
    HMENU save=CreateMenu();
   // HMENU htp4=CreateMenu();
    HMENU plus=CreateMenu();
    HMENU help=CreateMenu();
    HMENU add=CreateMenu();
    HMENU del=CreateMenu();
    HMENU edit=CreateMenu();
    HMENU cours=CreateMenu();


    //HMENU hex3=CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
/*******************************************************/

    AppendMenu(hmenu,MF_STRING,1,"creation contact");
    //AppendMenu(hmenu,MF_STRING,2,"Mise a jour");

/***************************************************************/

    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)up_date,"Mise a jour");

      AppendMenu(up_date,MF_STRING,213,"Ajouter un téléphone");
        //AppendMenu(add,MF_STRING,211,"En tête"); /*Sous partie */
        //AppendMenu(add,MF_STRING,212,"En queue");
        //AppendMenu(add,MF_STRING,213,"A partir d'une position");

      AppendMenu(up_date,MF_POPUP,(UINT_PTR)del,"Supprimer un téléphone");
        AppendMenu(del,MF_STRING,221,"En tête"); /*Sous partie */
        AppendMenu(del,MF_STRING,222,"En queue");
        AppendMenu(del,MF_STRING,223,"A partir d'une position");
        AppendMenu(del,MF_STRING,224,"D'un téléphone");
        AppendMenu(del,MF_STRING,225,"D'une ville");
        AppendMenu(del,MF_STRING,226,"D'un indicatif ");
        AppendMenu(del,MF_STRING,227,"*********Tout*********");


      AppendMenu(up_date,MF_POPUP,(UINT_PTR)edit,"Modifier les données d'un téléphone");
        AppendMenu(edit,MF_STRING,231,"Adresse"); /*Sous partie */
        AppendMenu(edit,MF_STRING,232,"Téléphone");

/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)rech,"Recherche affichage et tri");

      AppendMenu(rech,MF_STRING,31,"Tout les contacts ");
      AppendMenu(rech,MF_STRING,32,"Recherche par numéro ");
      AppendMenu(rech,MF_STRING,33,"Recherche par indicatif ");
      AppendMenu(rech,MF_STRING,34,"Recherche par nom ");
      AppendMenu(rech,MF_STRING,35,"Recherche par ville ");
      AppendMenu(rech,MF_STRING,36,"Tri 1");

/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)save,"Enregistrement récuperation ");

      AppendMenu(save,MF_STRING,41,"Enregistrement ");
      AppendMenu(save,MF_STRING,42,"Récuperation ");

/***************************************************************/
  AppendMenu(hmenu,MF_POPUP,(UINT_PTR)plus,"Plus++");
    AppendMenu(plus,MF_STRING,51,"Ennoncé Du Projet");
    AppendMenu(plus,MF_STRING,52,"Ouvrir Ficher");
    AppendMenu(plus,MF_POPUP,(UINT_PTR)cours,"Cours");
    AppendMenu(cours,MF_STRING,531,"Chaine De Caractére");
        AppendMenu(cours,MF_STRING,532,"Les Pointeurs");
    AppendMenu(cours,MF_STRING,533,"Les Structures");
        AppendMenu(cours,MF_STRING,534,"Liste Chainé");





    //AppendMenu(plus,MF_STRING,53,"Cours");






/***************************************************************/
  AppendMenu(hmenu,MF_POPUP,(UINT_PTR)help,"Aide");


/******************************************************************/
    AppendMenu(hmenu,MF_STRING,10,"Quitter");
    SetMenu(hwnd,hmenu);
}

