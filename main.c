#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FILE *pU;
FILE *red;
FILE *green;
FILE *blue;

struct Kullanici
{
    char name[50];
    char password[50];
}user,user2;
typedef struct
{
    int salon;
    int matine;
    int film;
}ticket;
typedef struct
{
    int Red[5][50];
    int Green[5][50];
    int Blue[5][50];
}Salonlar;
typedef enum
{
    RED=1,
    GREEN,
    BLUE
}saloons;
typedef enum
{
    Ogr=20,
    Tam=30
}fiyat;

Salonlar s1;
ticket ticket1;
Salonlar *psalon;

void KullaniciGiris()
{
    printf("\tSisteme girebilmek icin kaydolunuz\n");
    printf("Username:");
    scanf("%s",&user.name);
    printf("Password:");
    scanf("%s",&user.password);
    sleep(1);
    printf("Kaydiniz basarili bir sekilde yapildi.");
    sleep(1);
    system("cls");

    pU = fopen("Sifre.txt","w+");
    if(pU == NULL){
        printf("Sifre.txt acilmadi!\n");
        exit(1);
    }
    fprintf(pU,"%s\n%s",user.name,user.password);
    fclose(pU);
}
void KullaniciGiris2()
{
    int a=0;
    char c1[50];
    char c2[50];
    printf("\tLutfen kayitli bilgileriniz ile giris yapiniz\n");

        pU = fopen("Sifre.txt","r");
    if(pU == NULL){
        printf("Sifre.txt acilmadi!\n");
        exit(1);
    }
    fscanf(pU,"%s\n%s",&c1,&c2);
    printf("Username:");
    scanf("%s",&user2.name);
    printf("Password:");
    scanf("%s",&user2.password);
    for (int i=0;i<strlen(user2.name);i++){
        if (c1[i]!=user2.name[i])
            a++;
    for (int i=0;i<strlen(user2.password);i++){
        if(c2[i]!=user2.password[i])
            a++;
    }
    }
    if (a==0){
        printf("\nDogru Kullanici\n\n");
        }
    else{
        printf("\nYanlis Kullanici\n\n");
        exit(1);
    }
    sleep(1);
    system("cls");
    fclose(pU);
}
void Anamenu()
{
    int x;
    while (1){
    printf("1)Rezervasyon\n2)Ucret Bilgisi\n3)Izlenme Bilgisi\n4)Cikis\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        salonsecim();
        break;
    case 2:
        ucret();
        break;
    case 3:
        izlenmered();
        izlenmegreen();
        izlenmeblue();
        break;
    case 4:
        cikis();
        break;
    default:
        printf("Hatali Giris\n");
        exit(1);
    }
    }
}
void ucret()
{
    int x;
    printf("\n\tOdeme icin lutfen kriter seciniz\n");
    printf("1-Ogrenci\n2-Tam\n");
    scanf("%d",&x);

    FILE *ucret;
    ucret = fopen("Ucret.txt","w");
    if(ucret==NULL)
    {
        printf("Ucret.txt acilamadi!");
        exit(1);
    }
    switch(x)
    {
    case 1:
        printf("Ucretiniz=20TL\n");
        fprintf(ucret,"%d",Ogr);
        break;
    case 2:
        printf("Ucretiniz=30TL\n");
        fprintf(ucret,"%d",Tam);
        break;
    default:
        printf("Yanlis secim\n");
        exit(1);
    }
}
void KoltukRed()
{
    red = fopen("Koltuk.red.txt","w");
    if(red==NULL){
        printf("Koltuk.red.txt acilamadi!");
        exit(1);
    }
    for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(red,"%d",s1.Red[i-1][j-1]);
            s1.Red[i-1][j-1]=0;
        }
    }
    fclose(red);
}
void KoltukGreen()
{
    green = fopen("Koltuk.green.txt","w");
    if(green==NULL){
        printf("Koltuk.green.txt acilamadi!");
        exit(1);
    }
    for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(green,"%d",s1.Green[i-1][j-1]);
            s1.Green[i-1][j-1]=0;
        }
    }
    psalon = &s1;
    fclose(green);
}
void KoltukBlue()
{
    blue = fopen("Koltuk.blue.txt","w+");
    if(blue==NULL){
        printf("Koltuk.blue.txt acilamadi!");
        exit(1);
    }
    for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(blue,"%d",s1.Blue[i-1][j-1]);
            s1.Blue[i-1][j-1]=0;
        }
    }
    psalon = &s1;
    fclose(blue);
}

void salonsecim()
{

    printf("\tSinema Salonunuzu seciniz:\n");
    printf("1-Red\n2-Green\n3-Blue\n");
    scanf("%d",&ticket1.salon);
    switch(ticket1.salon){
    case RED:
        printf("\tRed Salonunun Matineleri\n");
        matinesecim();
        filmsecim();
        koltuksecimred();
        break;
    case GREEN:
        printf("\tGreen Salonunun Matineleri\n");
        matinesecim();
        filmsecim();
        koltuksecimgreen();
        break;
    case BLUE:
        printf("\tBlue Salonunun Matineleri\n");
        matinesecim();
        filmsecim();
        koltuksecimblue();
        break;
    default:
        printf("Boyle bir salonumuz bulunmamaktadir.");

    }
}
void matinesecim()
{

    printf("1\n2\n3\n4\n5\n");
    printf("\tBir matine seciniz\n");
    scanf("%d",&ticket1.matine);
    printf("\n");
    if(ticket1.matine>5 || ticket1.matine<0){
        printf("Böyle bir matinemiz bulunmamaktadir.\n");
        exit(1);
    }
}
void filmsecim()
{

    printf("\tIzlemek istediginiz filmi seciniz\n");
    printf("1-A filmi\n2-B filmi\n3-C filmi\n");
    scanf("%d",&ticket1.film);
    if(ticket1.film>3 || ticket1.film<0){
        printf("Boyle bir filmimiz bulunmamaktadir.\n");
        exit(1);
    }
}
void koltuksecimred()
{
    int k;
    psalon = &s1;
    printf("Bir Koltuk seciniz:\n");
    scanf("%d",&k);

    red = fopen("Koltuk.red.txt","w+");
    if(red==NULL){
        printf("Koltuk.red.txt acilamadi!");
        exit(1);
    }
        if(psalon->Red[ticket1.matine-1][k]==0){
           psalon->Red[ticket1.matine-1][k]=1;
        }
        for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(red,"%d",s1.Red[i-1][j-1]);
        }
    }
}
void koltuksecimblue()
{
    int k;
    psalon = &s1;
    printf("Bir Koltuk seciniz:\n");
    scanf("%d",&k);

    blue = fopen("Koltuk.blue.txt","w+");
    if(blue==NULL){
        printf("Koltuk.blue.txt acilamadi!");
        exit(1);
    }
        if(psalon->Blue[ticket1.matine-1][k]==0){
           psalon->Blue[ticket1.matine-1][k]=1;
        }
        for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(blue,"%d",s1.Blue[i-1][j-1]);
        }
    }
}
void koltuksecimgreen()
{
    int k;
    psalon = &s1;
    printf("Bir Koltuk seciniz:\n");
    scanf("%d",&k);

    green = fopen("Koltuk.green.txt","w+");
    if(green==NULL){
        printf("Koltuk.green.txt acilamadi!");
        exit(1);
    }
        if(psalon->Green[ticket1.matine-1][k]==0){
           psalon->Green[ticket1.matine-1][k]=1;
        }
        for(int i=1;i<6;i++){
        for(int j=1;j<51;j++){
            fprintf(green,"%d",s1.Green[i-1][j-1]);
        }
    }
}
void izlenmered()
{
    int i,x=0;
    psalon = &s1;
    for(i=1; i<6; i++){
        for(int j=1; j<51; j++){
            if(psalon->Red[i-1][j-1]==1)
            x++;
        }
        printf("Red salonu %d. Matine %d izleyiciye sahip.\n",i,x);
        x=0;
    }
}
void izlenmegreen()
{
    int i,x=0;
    psalon = &s1;
    for(i=1; i<6; i++){
        for(int j=1; j<51; j++){
            if(psalon->Green[i-1][j-1]==1)
            x++;
        }
        printf("Green salonu %d. Matine %d izleyiciye sahip.\n",i,x);
        x=0;
    }
}
void izlenmeblue()
{
    int i,x=0;
    psalon = &s1;
    for(i=1; i<6; i++){
        for(int j=1; j<51; j++){
            if(psalon->Blue[i-1][j-1]==1)
            x++;
        }
        printf("Blue salonu %d. Matine %d izleyiciye sahip.\n",i,x);
        x=0;
    }
}
void cikis()
{
    exit(1);
}
int main()
{
    KullaniciGiris();
    KullaniciGiris2();
    KoltukRed();
    KoltukGreen();
    KoltukBlue();
    Anamenu();
    return 0;
}






