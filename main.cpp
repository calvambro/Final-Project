#include <stdio.h>
#include <time.h>
#include <string.h>

struct nasabah
{  
   long long norek;
   char nama[100];
   char date[100];
   long long saldo;
};


void account(){
   char name[100], contacts[100], creationDate[100];
   long long initialSaving;
   time_t t;
   time(&t);

   printf("Masukan nama rekening anda: ");
   scanf("%s", name);
   getchar();
   printf("Masukan nomer telopon anda: ");
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
   printf("Nama: %s\n", name);
   printf("Nomer Rekening: %s\n", contacts);
   printf("Tanggal rekening dibuat: %s", tanggal);
   printf("Saldo anda sekarang: %lld", initialSaving);
   
}

void withdraw(){

}

void deposit(){
   long long setoran;
   printf("Masukan nomor rekening anda : ");
   char rekening[100];
   scanf("%s", rekening); 

   //nanti diisi mencari nomor rekening

   printf("Masukan jumlah uang yang ingin disetor : ");
   scanf("%lld", &setoran);


}

void deposit_withdraw(){
   int jenis;
   printf("Jenis transaksi apa yang ingin dilakukan?\n");
   printf("1. Menyetor Uang (Deposit)\n");
   printf("2. Menarik Uang (Withdraw)");
   printf("Masukan sesuai dengan nomor : ");
   scanf("%d", &jenis);

   if (jenis == 1)
   {
      deposit();
   } else if(jenis == 2){
      withdraw();
   } else{
      printf("Angka yang anda masukan salah \n");
      printf("Silahkan masukan angka yang benar : ");
      scanf("%d", &jenis);
      if (jenis == 1)
      {
         deposit();
      } else if(jenis == 2){
         withdraw();
      } else{
         printf("Angka yang anda masukan salah \n");
         printf("Silahkan masukan angka yang benar : ");
         scanf("%d", &jenis);
      }
   }
   
}



int main(){
   int pilihan;

   printf("SELAMAT DATANG DI BANK\n\n");
   printf("======================");
   printf("   Welcome to Bank");

   printf("Apa yang ingin anda lakukan ? \n");
   printf("1. Membuat rekening\n");
   printf("2. Deposit + Withdraw\n");
   printf("3. Tutup Rekening\n");
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
   
   default:
      break;
   }
   
   return 0;
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

