#include <stdio.h>
#include <math.h>

// Nama    : Muhammad Wildan Asyrof
// NIM     : 13219067
// Modul   : 2
// Program : Kalkulator
// Spec    : Sesuai Permintaan Tugas Modul 2 Divisi Programming Sekuro 2021

// **Fungsi Inisiasi** //
// Fungsi untuk Mem-Validasi Input pilihan
void validasi_pilihan(int pilihan,int *keluar){
    while(pilihan!=1 && pilihan!=2 && pilihan!=3){
        printf("\nInput pilihan tidak valid, pilihan yang tersedia:\n1.) Kalkulator Normal (Ketik '1')\n2.) Kalkulator Integral (Ketik '2')\n");
        printf("Masukkan pilihan (ketik '3' untuk keluar): ");
        scanf("%d",&pilihan);
    }
    if(pilihan==3){
        *keluar=0;
        printf("\nKalkulator ter-close, sampai jumpa~");
    }
}

// **Fungsi Kalkulator Normal** //
// Fungsi Perhitungan
float proses(float a,float b,char c);
// Fungsi Untuk Mem-Validasi Input operator
void validasi(char operator,float b){
    // Terus meminta input yang valid
    while((operator!='c') && (operator!='r') && (operator!='+') && (operator!='-') && (operator!='*') && (operator!='/') && (operator!='/') && (operator!='^')){
            printf("\nInput operator tidak valid, operator yang tersedia:\n1.) Penjumlahan('+')\n2.) Pengurangan('-')\n3.) Perkalian('*')\n4.) Pembagian('/')\n5.) Pemangkatan('^')\n");
            printf("Masukkan operator (ketik 'r' untuk reset atau 'c' untuk keluar): ");
            scanf(" %c",&operator);
    }
}
// Fungsi Untuk Membagi Aksi Per-Kasus 
void kasus(char operator,float *a,float *b,int *keluar){
    // Kasus Normal
    if(operator!='r' && operator!='c'){
        printf("Masukkan input2: ");
        scanf("%f",b);
    }
    // Kasus Reset
    else if(operator=='r'){
        *a=0;
        *b=0;
        printf("\nKalkulator ter-reset\n");
    }
    // Kasus Close Program
    else{
        *keluar=0;
        printf("\nKalkulator ter-close, sampai jumpa~");
    }
}

// **Fungsi Kalkulator Integral** //
// Fungsi f(x)
float f(float a,float b,float c,float x);
// Fungsi Penghitungan Integral dengan Riemann Metode Trapesium
float riemann(float a,float b,float c,float batas_bawah,float batas_atas,int n);
// Validasi Input Variabel ulang_integral
void validasi_ulang_integral(char ulang_integral,int *keluar){
    while(ulang_integral!='Y' && ulang_integral!='N'){
        printf("\nInput tidak valid, masukkan 'Y' (menghitung ulang integral) atau 'N' (Keluar)\n");
        printf("Apakah anda ingin menghitung integral fungsi yang lain?(Y/N): ");
        scanf("% c",&ulang_integral);
    }
    if(ulang_integral=='N'){
        *keluar=0;
        printf("\nKalkulator ter-close, sampai jumpa~");
    }
}

// Fungsi Utama
void main(){
    // Deklarasi dan Inisialisasi Variabel Global (Lokal Fungsi main())
    float a,b,c,batas_bawah,batas_atas;
    int keluar=1,pilihan,n;
    char operator,ulang_integral;

    // Intro dan Pemilihan Jenis Kalkulator
    printf("Selamat datang di kalkulator Wildan~\n");
    printf("Apakah anda ingin menggunakan kalkulator normal atau kalkulator integral?\n");
    printf("1.) Kalkulator Normal (Ketik '1')\n2.) Kalkulator Integral (Ketik '2')\n");
    printf("Masukkan pilihan (ketik '3' untuk keluar): ");
    scanf("%d",&pilihan);
    validasi_pilihan(pilihan,&keluar);
    if(pilihan==1){
        printf("\nKalkulator Normal Aktif!");
    }
    else if(pilihan==2){
        printf("\nKalkulator Integral Aktif!");
    }

    // Program Utama
    while(keluar==1)
    {
        // Program Kalkulator Normal
        if(pilihan==1){
            // Input Awal (Asumsi Input Angka Selalu Benar)
            printf("\n\nMasukkan input1: ");
            scanf("%f",&a);
            printf("Masukkan operator (ketik 'r' untuk reset) atau 'c' untuk keluar): ");
            scanf(" %c",&operator);
            // Validasi Awal
            validasi(operator,b);
            kasus(operator,&a,&b,&keluar);
            // Operasi Berlanjut (Apabila User Menghendaki Berlanjut)
            while(operator!='r' && operator!='c'){
                a = proses(a,b,operator);
                printf("\nHasilnya adalah %f",a);
                printf("\n\nMasukkan operator lanjutan (ketik 'r' untuk reset) atau 'c' untuk keluar): ");
                scanf(" %c",&operator);
                // Validasi Lanjutan
                validasi(operator,b);
                kasus(operator,&a,&b,&keluar);
            }
        }

        //Program Kalkulator Integral
        else{
            // Intro dan Input Fungsi (Asumsi Input Angka Selalu Benar)
            printf("\n\nKalkulator Pengintegralan akan menggunakan pendekatan Riemann Metoda Trapesium");
            printf("\nFormat fungsi yang akan di-integralkan adalah sebagai berikut: \n");
            printf("f(x) = ax^2 + bx + c\nMasukkan a: ");
            scanf("%f",&a);
            printf("Masukkan b: ");
            scanf("%f",&b);
            printf("Masukkan c: ");
            scanf("%f",&c);
            // Input Batas-Batas dan Partisi Pengintegralan
            printf("\nMasukkan batas-batas dan partisi pengintegralan!");
            printf("\nMasukkan batas bawah: ");
            scanf("%f",&batas_bawah);
            printf("Masukkan batas atas: ");
            scanf("%f",&batas_atas);
            printf("Masukkan partisi pengintegralan: ");
            scanf("%d",&n);
            // Output Penghitungan Integral 
            printf("\nHasil pengintegralan-nya adalah = %f",riemann(a,b,c,batas_bawah,batas_atas,n));
            // Input Validasi Pengulangan Penggunaan Kalkulator Integral
            printf("\n\nApakah anda ingin menghitung integral fungsi yang lain?(Y/N): ");
            scanf(" %c",&ulang_integral);
            validasi_ulang_integral(ulang_integral,&keluar);
        }
    }
}

// Implementasi Fungsi proses
float proses(float a,float b,char c){
    if(c=='+'){
        return a+b;
    }
    else if(c=='-'){
        return a-b;
    }
    else if(c=='*'){
        return a*b;
    }
    else if(c=='/'){
        return a/b;
    }
    else if(c=='^'){
        return pow(a,b);
    }
}

// Implementasi Fungsi f
float f(float a,float b,float c,float x){
    return((a*pow(x,2)) + b*x + c);
}

// Implementasi Fungsi riemann
float riemann(float a,float b,float c,float batas_bawah,float batas_atas,int n){
    // Deklarasi dan Inisialisai Variabel Lokal
    float temp_batas_bawah=batas_bawah,temp_batas_atas=0,total=0,panjang_partisi;

    // Mencari Panjang Partisi dan Inisialisasi Variabel temp_batas_atas
    panjang_partisi = ((batas_atas - batas_bawah)/n);
    temp_batas_atas = (temp_batas_bawah + panjang_partisi);
    // Proses Penghitungan Partisi Riemann dengan Metoda Trapesium
    for(int i = 0;i<n;i++){
        total = (total + (((f(a,b,c,temp_batas_bawah)+f(a,b,c,temp_batas_atas))/2)*panjang_partisi));
        temp_batas_bawah = (temp_batas_bawah + panjang_partisi);
        temp_batas_atas = (temp_batas_atas + panjang_partisi);
    }
    return(total);
}
