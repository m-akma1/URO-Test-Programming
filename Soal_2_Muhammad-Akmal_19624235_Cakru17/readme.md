# The Battle of Robots

## Overview

The Battle of Robots adalah sebuah game combat strategy di mana setiap pemain memilih tim  yang terdiri dari 4 robot untuk bertanding melawan pemain lain atau komputer. Game ini berbasis terminal langsung dengan antarmuka cukup interaktif.

## Fitur Utama

* Berbagai Mode Game: User bisa memilih dua jenis mode: Player vs Player (PvP) atau Play Against Computer.
* 10 Robot Unik: Tersedia 10 jenis robot dinamai dari aksara Yunani dengan variasi power dan health stats.
* Pertarungan Antar-Robot: Setiap game terdiri dari pertarungan, di mana robot terdepan dari setiap tim berduel hingga salah satu atau keduanya mati.
* Pemilihan Acak (untuk Komputer): Ketika bermain melawan Komputer, tim yang dipilih diambil secara acak sehingga membuat hasil yang bervariasi.

## Cara Bermain
Sebelum bermain, program akan menanyakan mode game yang akan dipilih. 

### PvP Mode
* Pemain pertama menuliskan nama lalu memilih 4 robot berbeda dari 10 robot yang disediakan.
* Pemilihan robot dilakukan dengan memasukkan indeks pilihan (angka) ke terminal.
* Setelah program menunjukkan tim pemain pertama, pemain kedua menginisiasi nama dan tim dengan cara serupa.
* Pertarungan berjalan otomatis, kedua pemain hanya perlu melihat keterangan hasil pertarungan di terminal.

### Computer Mode

* Pemain menuliskan nama lalu memilih anggota tim serupa seperti mode PvP
* Setelah tim pemain ditunjukkan program, program akan menginisiasi akun komputer dan tim robotnya yang dipilih secara otomatis dan random. 
* Pertarungan langsung akan berjalan hingga salah satu atau kedua pemain tidak memiliki robot tersisa.

### Gameplay

* Ketika pertarungan dimulai, tiap robot terdepan tim akan berduel dan menyerang bersamaan. 
* Besar serangan dan sisa nyawa tiap robot akan dioutputkan oleh program.
* Ketika salah satu atau kedua robot kehabisan nyawa, pertarungan selesai dan robot yang mati akan dikeluarkan dari tim. 
* Pertarungan baru dimulai seterusnya hingga salah satu atau kedua pemain tidak memiliki robot tersisa.

### Penentuan Pemenang
* Pemenang game adalah pemain yang masih memiliki robot di akhir game. 
* Jika kedua tim kehabisan robot, maka pertarungan dinyatakan seri. 


## Persyaratan Sistem
Agar dapat memainkan game ini, dibutuhkan sistem berupa PC/Laptop dengan ketentuan:

* Compiler C++ seperti g++, clang++, atau sejenisnya
* IDE Terminal yang mendukung kompilasi C++ seperti PowerShell, Bash, atau sejenisnya

## Tentang Developer

Game ini dibuat dalam rangka memenuhi Rangkian URO Test Programming Calon Kru 17 Unit Robotika ITB. 

* Nama: Muhammad Akmal
* NIM: 19624235
* Email: muhammad.akmal.3806@gmail.com
* Sekolah Teknik Elektro dan Informatika - Komputasi
