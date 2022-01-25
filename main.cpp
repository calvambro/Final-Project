//melakukan include beberapa standart library yang akan diperlukan
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int structlen;// untuk mengetahui banyak nasabah pada sistem

// Membuat struct untuk menyimpan data nasabah
struct nasabah
{  
   char norek[30]; //untuk nomor rekening
   char nama[100]; //untuk nama nasabah
   char date[100]; // untuk tanggal pembuatan rekening
   long long saldo; //untuk saldo rekening
} nasabah[1000]; // declare struct secara global

void swap(struct nasabah a, struct nasabah b); //untuk menukar data dibuat ambro
void sortrek (struct nasabah list[]); //untuk melakukan sorting data pada array of struct dibuat ambro
int searchrek(struct nasabah list[], char x[], int low, int high);// untuk melakukan searching berdasarkan nomor rekening dibuat ambro

// Dibagi menjadi beberapa bagian sesuai dengan fitur
void account(); //function membuat akun baru dibuat ambro
void withdraw(); //function untuk tarik tunai dibuat wilson
void deposit(); //function untuk setor tunai dibuat wilson
void deposit_withdraw(); //function pilihan setor/tarik tunai dibuat wilson dan ambro
void tutupRek(); //function untuk menutup rekening dibuat ambro
void cekSaldo(); //function untuk mengecek saldo nasabah dibuat ambro
void transfer(); //function untuk transfer dana nasabah dibuat wilson

int main(){ // dibuat wilson
   //Deklarasi variable yang dibutuhkan
   int pilihan;
   
   // file processing untuk melakukan input data dari file txt dibuat ambro
   FILE *fp;
   fp = fopen("nasabah.txt", "r"); //membuka buffer area
   for(int i = 0; !feof(fp); i++){
     fscanf(fp, "%[^#]#%[^#]#%lld#%[^\n]\n", nasabah[i].norek, nasabah[i].nama, &nasabah[i].saldo, nasabah[i].date);
     structlen = i+1;
   }
   fclose(fp); //menutup buffer area

   printf("SELAMAT DATANG DI BANK\n");
   printf("======================\n");
   printf("   Welcome to Bank\n");

   // loop yang akan terus mengulang hingga program diminta keluar dibuat wilson
   while (true)
   {
      //meminta inputan untuk proses yang akan dilakukan
      printf("\nApa yang ingin anda lakukan ? \n");
      printf("1. Membuat rekening\n");
      printf("2. Setor dan Tarik Tunai\n");
      printf("3. Tutup Rekening\n");
      printf("4. Cek Saldo\n");
      printf("5. Transfer\n");
      printf("0. Exit\n\n");
      printf("Masukan sesuai dengan nomor : ");
      scanf("%d", &pilihan);

      while(pilihan < 0 || pilihan > 5){
        printf("Nomor yang anda masukan salah\n");
        printf("Silahkan masukan ulang pilihan yang diinginkan : ");
        scanf("%d", &pilihan);
      }

      // switch untuk melakukan proses yang dipilih dibuat ambro dan wilson
      switch (pilihan)
      {
      case 1: // 1 untuk membuat rekening
         account();
         break;
      case 2: // 2 untuk depo/wd
         deposit_withdraw();
         break;
      case 3: // 3 untuk menutup rekening
         tutupRek();
         break;
      case 4: // 4 untuk cek saldo rekening
         cekSaldo();
         break;
      case 5: // 5 untuk tranfer antar rekening
         transfer();
         break;
      case 0: // 0 untuk keluar program
        // melakukan print data nasabah ke file txt untuk digunakan ketika program dijalankan kembali
         fp = fopen("nasabah.txt", "w"); //membuka buffer area
         sortrek(nasabah); //data di sort
         for(int i = 0; i<structlen; i++){ // untuk menaruh data nasabah pada file txt
           fprintf(fp, "%s#%s#%lld#%s\n", nasabah[i].norek,nasabah[i].nama, nasabah[i].saldo, nasabah[i].date); //melakukan printing seluruh data
         }
         fclose(fp); //menutup buffer area

         exit(0); //exit untuk keluar dari program
         break;
      }
   }
   
   return 0;
} //end main

void swap(struct nasabah *a, struct nasabah *b){
  struct nasabah temp;
  //melakukan swap berdasarkan isi struct
  strcpy(temp.norek, a->norek);
  strcpy(a->norek, b->norek);
  strcpy(b->norek, temp.norek);

  strcpy(temp.nama, a->nama);
  strcpy(a->nama, b->nama);
  strcpy(b->nama, temp.nama);

  strcpy(temp.date, a->date);
  strcpy(a->date, b->date);
  strcpy(b->date, temp.date);

  temp.saldo = a->saldo;
  a->saldo = b->saldo;
  b->saldo = temp.saldo;
}

//function sort menggunakan bubble sort
void sortrek(struct nasabah list[1000]){
  for(int i = 0; i<structlen-1; i++){
    for(int j = 0; j<structlen-1-i; j++){
      if(strcmp(list[j].norek, list[j+1].norek) > 0){
        swap(&list[j], &list[j+1]);
      }
    }
  }
}

//function searching menggunakan binary search
int searchrek(struct nasabah list[], char x[30], int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (strcmp(list[mid].norek,x) == 0)
      return mid;

    if (strcmp(list[mid].norek, x) < 0)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

// function untuk membuat rekening baru
void account(){
   //deklarasi variable yang diperlukan
   char nama[100], contacts[100], creationDate[100];
   long long initialSaving;

  time_t now = time(NULL); // untuk mendapatkan tanggal saat rekening dibuat secara otomatis
  struct tm *t = localtime(&now);


  strftime(nasabah[structlen].date, sizeof(nasabah[structlen].date)-1, "%d %m %Y %H:%M", t);
  // printf("Current Date: %s", text);

   //time untuk mendapatkan waktu pembuatan secara otomatis
  //  time_t t;
  //  time(&t);
   getchar();

   //meminta nama pembuat rekening
   printf("Masukan nama rekening anda: ");
   scanf("%[^\n]", nasabah[structlen].nama);
   getchar();
   // input nomor telepon pembuat rekening
   printf("Masukan nomer telepon anda: ");
   scanf("%s", nasabah[structlen].norek);
   getchar();
   // meminta jumlah setoran awal nasabah
   printf("Masukan setoran awal anda (minimal 100.000): ");
   scanf("%lld", &nasabah[structlen].saldo);

  // looping untuk meminta ulang setoran awal jika setoran awal tidak mencapai minimal
   while(nasabah[structlen].saldo < 100000){
      printf("Minimal setoran awal adalah 100.000\n");
      printf("Masukan ulang setoran awal anda: ");
      scanf("%lld", &nasabah[structlen].saldo);
   }
   // mendapatkan tanggal secara otomatis
   char tanggal[100];
  //  strcpy(nasabah[structlen].date, ctime(&t));

   // konfirmasi data nasabah
   printf("\nMohon periksa kembali data anda\n");
   printf("Nama: %s\n", nasabah[structlen].nama);
   printf("Nomer Rekening: %s\n", nasabah[structlen].norek);
   printf("Tanggal rekening dibuat: %s\n", nasabah[structlen].date);
   printf("Saldo anda sekarang: %lld\n", nasabah[structlen].saldo);
   structlen++;

   sortrek(nasabah); //setelah menambahkan data nasabah maka data nasabah kembali di sort sesuai nomor rekening
} //end account

void withdraw(){
  // variable declaration
  long long setoran;
  char rekening[100];
  // number input
  printf("Masukan nomor rekening anda : ");
  scanf("%s", rekening);

  sortrek(nasabah);
  int indexcari = searchrek(nasabah, rekening, 0, structlen);

  while(indexcari == -1){
    printf("Nomor rekening yang anda masukan salah\n");
    printf("Silahkan masukan ulang nomor rekening anda : ");
    scanf("%s", rekening);
    indexcari = searchrek(nasabah, rekening, 0, structlen);
  }

  // amount of money to withdraw
  printf("Masukan jumlah uang yang ingin ditarik (maximal 5.000.000) : ");
  scanf("%lld", &setoran);
  //looping for withdraw value
  while (setoran > 5000000 || setoran > nasabah[indexcari].saldo)
  {
    // input ulang jika nominal yang dimasukan lebih besar dari ketentuan atau saldo tidak mencukupi
    if(setoran > 5000000) // jika lebih dari maksimal tarik tunai
    {
      printf("Anda melebihi nilai maximum untuk melakukan withdraw\n");
      printf("Silahkan masukan ulang nominal yang ingin ditarik : ");
      scanf("%lld", &setoran);
    } else if(setoran < 5000000 && setoran > nasabah[indexcari].saldo) // jika saldo tidak mencukupi
    {
      printf("Saldo anda tidak mencukupi\n");
      printf("Silahkan masukan ulang nominal yang ingin ditarik : ");
      scanf("%lld", &setoran);
    }
  }

  nasabah[indexcari].saldo -= setoran; // mengurangi saldo nasabah

  // diisi konfirmasi withdraw
   printf("Uang anda berhasil ditarik\n");

} // end withdraw

void deposit(){
   // deklarasi variable yang diperlukan
   long long setoran;
   char rekening[100];
   // input nomor rekening
   printf("Masukan nomor rekening anda : ");
   scanf("%s", rekening); 

   sortrek(nasabah);
   //nanti diisi mencari nomor rekening
   int indexcari = searchrek(nasabah, rekening, 0, structlen);

   while(indexcari == -1){ // ketika nomor rekeing tidak ditemukan
    printf("Nomor rekening yang anda masukan salah\n");
    printf("Silahkan masukan ulang nomor rekening anda : ");
    scanf("%s", rekening);
    indexcari = searchrek(nasabah, rekening, 0, structlen);
   }

   //input jumlah uang yang ingin disetor
   printf("Masukan jumlah uang yang ingin disetor (minimal 100.000) : ");
   scanf("%lld", &setoran);
   
   // looping untuk meminta ulang jumlah setoran bila tidak mencapai minimum
   while (setoran < 100000)
   {
      printf("Anda tidak mencapai nilai minimum untuk melakukan deposit\n");
      printf("Silahkan masukan ulang nominal yang ingin disetor : ");
      scanf("%lld", &setoran);
   }
   nasabah[indexcari].saldo += setoran; // menambahkan saldo nasabah
   
   // diisi konfirmasi deposit
   printf("Uang anda berhasil disetor!\n");
   

} // end deposit

void deposit_withdraw(){
   int jenis;
   // melakukan input jenis transaksi yang ingin dilakukan
   printf("Jenis transaksi apa yang ingin dilakukan?\n");
   printf("1. Setor Tunai (Deposit)\n");
   printf("2. Tarik Tunai (Withdraw)\n");
   printf("Masukan sesuai dengan nomor : ");
   scanf("%d", &jenis);

  // while jika angka yang dimasukan salah
   while(jenis < 1 || jenis > 2){
      printf("Angka yang anda masukan salah\n");
      printf("Silahkan masukan angka yang benar : ");
      scanf("%d", &jenis);
   }

  // memanggil function sesuai jenis transaksi
   if (jenis == 1){
      deposit(); //melempar ke function deposit
   } else if(jenis == 2){
      withdraw(); // melempar ke function withdraw
   } 
} // end deposit withdraw

// function untuk cek saldo nasabah
void cekSaldo(){
  //declare variable 
  char rekening[30];
  printf("Masukan Nomor Rekening anda : ");
  //scan nomer rekening
  scanf("%s", rekening);
  
  //sorting data pada variable nasabah
  sortrek(nasabah);
  int indexcari = searchrek(nasabah, rekening, 0, structlen); //mencari rekening nasabah

  //while loop jika rekening tidak ditemukan
  while(indexcari == -1){
    printf("Nomor rekening yang anda masukan salah\n");
    printf("Silahkan masukan ulang nomor rekening anda : ");
    scanf("%s", rekening);
    indexcari = searchrek(nasabah, rekening, 0, structlen);
  }

  //melakukan print terhadap saldo nasabah
  printf("\nSaldo anda sekarang : %lld\n", nasabah[indexcari].saldo);
}

void tutupRek(){
  //declare variable
  char rekening[30];
  int pilihan;

  printf("Silahkan masukan nomor rekening yang ingin ditutup : ");
  //scan nomer rekening
  scanf("%s", rekening);

  //memanggil function searching berdasarkan nomor rekening
  int indexcari = searchrek(nasabah, rekening, 0, structlen);

  //while loop jika rekening tidak ditemukan
  while(indexcari == -1){
    printf("Nomor rekening yang anda masukan salah\n");
    printf("Silahkan masukan ulang nomor rekening anda : ");
    scanf("%s", rekening);
    indexcari = searchrek(nasabah, rekening, 0, structlen);
  }
  
  //menukar array menjadi array terakhir
  swap(&nasabah[structlen-1], &nasabah[indexcari]);
  //panjang array of struct dikurangi
  structlen--;
  //melakukan clear dari data nasabah
  nasabah[structlen].norek[0] = '\0';
  nasabah[structlen].nama[0] = '\0';
  nasabah[structlen].date[0] = '\0';
  nasabah[structlen].saldo = 0;

  //konfirmasi rekening yang ditutup
  printf("Rekening %s telah ditutup\n", rekening);
} // end tutuprek

void transfer(){
  //declare variable
  char rekasal[30], rektujuan[30];
  long long nominal;
  //scan nomor rekening awal
  printf("Masukan nomor rekening anda: ");
  scanf("%s", rekasal);
  //mencari nomor rekening
  int indexasal = searchrek(nasabah, rekasal, 0, structlen);
  //loop jika rekening tidak ada
  while(indexasal == -1){
    printf("nomor rekening yang anda masukan tidak valid\n");
    printf("Silahkan masukan kembali nomor rekening anda : ");
    scanf("%s", rekasal);
    indexasal = searchrek(nasabah, rekasal, 0, structlen);
  }  
  //scan nomor rekening tujuan
  printf("Masukan nomor rekening tujuan: ");
  scanf("%s", rektujuan);
  //mencari nomor rekening
  int indextujuan = searchrek(nasabah, rektujuan, 0, structlen);

  //loop jika rekening tidak ada
  while(indextujuan == -1){
    printf("Nomor rekening yand anda masukan tidak valid\n");
    printf("Silahkan masukan kembali nomor rekening anda : ");
    scanf("%s", rektujuan);
    indextujuan = searchrek(nasabah, rektujuan, 0, structlen);
  }
  //input nominal transfer
  printf("Masukan nominal transfer yang diinginkan : ");
  scanf("%lld", &nominal);

  // looping jika saldo tidak mencukupi
  while(nominal > nasabah[indexasal].saldo){
    printf("Saldo anda tidak mencukupi!\n");
    printf("Silahkan masukan ulang nominal transfer : ");
    scanf("%lld", &nominal);
  }

  // mengubah jumlah saldo nasabah sesuai dengan nominal transfer
  nasabah[indexasal].saldo -= nominal;
  nasabah[indextujuan].saldo += nominal;

  printf("Transfer sukses\n");
}//end of transfer



/*BANK MANAGEMENT SYSTEM

1. Create Account v
	name
	contacts
	creation date
	initial saving
2. Deposit v
	min 100k
3. Withdraw v
	max 5mil
4. close an accountv v
5. main menu v
6, Cek Saldo v
*/