#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct nasabah
{  
   long long norek;
   char nama[100];
   char date[100];
   long long saldo;
};


void account();
void withdraw();
void deposit();
void deposit_withdraw();

int main(){
   int pilihan;
   struct nasabah nasabah[1000];

   FILE *fp;
   fp = fopen("nasabah.txt", "w+");
   fclose(fp);

   printf("SELAMAT DATANG DI BANK\n");
   printf("======================\n");
   printf("   Welcome to Bank\n\n");

   while (true)
   {
      printf("Apa yang ingin anda lakukan ? \n");
      printf("1. Membuat rekening\n");
      printf("2. Setor dan Tarik Tunai\n");
      printf("3. Tutup Rekening\n");
      printf("4. Cek Saldo\n");
      printf("0. Exit\n\n");
      printf("Masukan sesuai dengan nomor : ");
      scanf("%d", &pilihan);

      switch (pilihan)
      {
      case 1:
         account();
         break;
      case 2:
         deposit_withdraw();
         break;
      case 0:
         exit(0);
         break;
      default:
         break;
      }
   }
   
   return 0;
}

void account(){
   char nama[100], contacts[100], creationDate[100];
   long long initialSaving;
   time_t t;
   time(&t);
   getchar();

   printf("Masukan nama rekening anda: ");
   scanf("%[^\n]", nama);
   getchar();
   printf("Masukan nomer telepon anda: ");
   scanf("%s", contacts);
   getchar();
   printf("Masukan setoran awal anda: ");
   scanf("%lld", &initialSaving);

   while(initialSaving < 100000){
      printf("Minimal setoran awal adalah 100.000\n");
      printf("Masukan ulang setoran awal anda: ");
      scanf("%lld", &initialSaving);
   }
   char tanggal[100];
   strcpy(tanggal, ctime(&t));

   printf("Mohon periksa kembali data anda\n");
   printf("Nama: %s\n", nama);
   printf("Nomer Rekening: %s\n", contacts);
   printf("Tanggal rekening dibuat: %s", tanggal);
   printf("Saldo anda sekarang: %lld\n", initialSaving);
   
}

void withdraw(){

}

void deposit(){
   long long setoran;
   printf("Masukan nomor rekening anda : ");
   char rekening[100];
   scanf("%s", rekening); 

   //nanti diisi mencari nomor rekening

   printf("Masukan jumlah uang yang ingin disetor (minimal 100.000) : ");
   scanf("%lld", &setoran);

   while (setoran < 100000)
   {
      printf("Anda tidak mencapai nilai minimum untuk melakukan deposit\n");
      printf("Silahkan masukan ulang nominal yang ingin disetor : ");
      scanf("%lld", &setoran);
   }

   printf("");
   

}

void deposit_withdraw(){
   int jenis;
   printf("Jenis transaksi apa yang ingin dilakukan?\n");
   printf("1. Setor Tunai (Deposit)\n");
   printf("2. Tarik Tunai (Withdraw)\n");
   printf("Masukan sesuai dengan nomor : ");
   scanf("%d", &jenis);

   while(jenis < 1 || jenis > 2){
      printf("Angka yang anda masukan salah\n");
      printf("Silahkan masukan angka yang benar : ");
      scanf("%d", &jenis);
   }

   if (jenis == 1){
      deposit();
   } else if(jenis == 2){
      withdraw();
   } 
}


/*BANK MANAGEMENT SYSTEM

1. Create Account
	name
	contacts
	creation date
	initial saving
2. Deposit
	min 100k
3. Withdraw
	max 5mil
4. close an account
5. main menu*/

