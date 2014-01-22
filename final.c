#include <stdio.h> 
#include <string.h>
#include <process.h>

//deklarasi fungsi
 void encrypt();
 void decrypt();
 

//
int menu;
int main(int argc, char *argv[])
{

     printf("PROGRAM SEDERHANA VIGENERE CIPHER\n");
     printf("=================================\n");
     printf("1. Encrypt\n");
     printf("2. Decrypt \n");
     printf("---------------------------------\n");
     printf("Masukkan pilihan anda : "); scanf("%d",&menu);
     printf("\n-------------------------------\n");
     switch(menu)
       {
              case 1 : encrypt();break;
              case 2 : decrypt();break;
              
       }
    
} 

void encrypt()
{
int i;
int katakunci;
int katasandi;
printf("Masukkan panjang huruf kunci / KEY : ");
scanf("%d",&katakunci);
printf("Masukkan panjang huruf yang ingin di enkripsi: ");
scanf("%d",&katasandi);

char sandi[katasandi];
char kunci[katakunci];

printf("\n Masukkan kata kunci / Key : ");
for(i=-1;i<katakunci;i++)
scanf("%c",&kunci[i]);

printf("\n Masukkan Kata yang ingin di enkripsi: ");
for(i=-1;i<katasandi;i++)
scanf("%c",&sandi[i]);

int x[3][katasandi];

for(i=0;i<katasandi;i++)
{
if(65<=sandi[i] && sandi[i]<=91)
x[0][i]=sandi[i]%65;
else
x[0][i]=sandi[i]%97;
}

int count=0;
while(count<katasandi)
{
for(i=0;i<katakunci;i++)
{
if(65<=kunci[i] && kunci[i]<=91)
x[1][count+i]=kunci[i]%65;
else
x[1][count+i]=kunci[i]%97;
}
count=count+katakunci;
}

printf("\n\nHasil Enkripsi adalah: ");
char cipher[katakunci];
for(i=0;i<katasandi;i++)
{
x[2][i]=(x[0][i]+x[1][i])%26;
cipher[i]=(char)(x[2][i]+65);
printf("%c ",cipher[i]);
}

}

void decrypt()
{
  unsigned int i,j;
     char input[257],key[33];
     int value;
     printf("Masukkan kata yang ingin di dekripsi: \n"); fflush(stdin);
     gets(input);
     printf("Masukkan Kata Kunci / Key: \n");
     gets(key);
     printf("Hasil Dekripsi anda : ");
     for(i=0,j=0;i<strlen(input);i++,j++)
     {
          if(j>=strlen(key))
          {
               j=0;
          }
          value = (toupper(input[i])-64)-(toupper(key[j])-64);
          if( value < 0)
          {
               value = 26 + value;
          }
		            
          printf("%c",65 + (value % 26));
     }

}


