# To Do List berbasis Terminal (ada musik nya c0y)
kamu malas? kamu pengen mempersulit hidup dengan aplikasi todolist keren berbasis terminal? cobalah apk saya! (masih dalam perkembangan)

# Mengelola Database
Pada saat program diinisialisasi, program akan mengecek apakah file database nya ada atau tidak, jika tidak ada maka program akan membuat file database baru. setelah itu, program akan membaca isi dari file tersebut dan memasukannya ke dalam array.

# Menu Utama
Pengguna akan disuguhkan oleh _Ascii Art_ pada bagian utama yang juga berisi menu pilihan untuk menjalankan fitur fitur yang tersedia. Dengan diiringi musik, pengguna di minta memasukkan pilihannya menggunakan angka. pilihan yang bisa dipilih pengguna terdiri dari:
```
  [1] JADWAL SAYA     
                      
  [2] TAMBAHKAN JADWAL
                      
  [3] CARI            
                      
  [0] KELUAR          
```
# Menampilkan jadwal 
Program akan membaca file database. Jika isi dari file terdeteksi oleh program, maka program akan memsukannya ke dalam _Array of Record_. lalu, isi dari _Array of Record_ di sortir berdasarkan tanggal terdekat dari awal tahun menggunakan _Quick Sort_. Jadwal yang sudah di deteksi dan di sortir akan muncul di terminal.

# Menambahkan Jadwal
Program akan meminta pengguna untuk memasukkan input. Input pengguna lalu di simpan pada _Array of Record_. setelah itu, database di _Overwrite_, diganti dengan _Array of Record_ yang sudah di update sehabis user selesai memasukkan input. 

# Mencari Jadwal Berdasarkan Hari
Program meminta pengguna untuk memilih hari untuk menampilkan jadwal yang ada pada hari tersebut. Program akan mengecek tanggal dari setiap jadwal yang tersimpan pada _Array of Record_. jika hari nya sesuai dengan pilihan pengguna, maka program akan menampilkan jadwal dari hari tersebut beserta keterangannya.

# Update jadwal
Saat pengguna sedang melihat jadwal yang sudah disimpan, pengguna bisa mengubah jadwal tertentu. pengguna diberi pilihan untuk menghapus, mengubah jadwal, hingga menandai bahwa jadwal tersebut sudah selesai.

# Menghapus Jadwal
Pengguna akan diminta untuk memilih salah satu jadwal yang akan dihapus. jadwal yang dipilih akan dipindahkan ke indeks terakhir dari _Array of Record_. setelah itu ukuran dari _Array of Record_ akan dikurangi sehingga data tidak lagi bisa dibaca atau dicetak. perubahan ini lalu di Overwrite dan file database nya di baca ulang untuk mencegah bug. jika pilihan tidak valid maka kembali ke menu utama. 

# Ubah Jadwal
Pengguna akan diminta untuk memilih salah satu jadwal yang ingin di ubah. lalu fungsi menambahkan jadwal dijalankan dengan indeks yang berdasarkan pada pilihan pengguna sehingga jadwal lain tidak berubah. Lalu, database di overwrite berdasarkan perubahan ini dan dibaca kembali untuk mencegah bug.

# Menandai Jadwal Telah Selesai
Pengguna akan diminta untuk memilih salah satu jadwal yang ingin di tandai sudah selesai. salah satu bagian dari _Array of Record_ yaitu ```keterangan``` akan dirubah _Value_ nya dari belum selesai menjadi selesai. Lalu, database di overwrite berdasarkan perubahan ini dan dibaca kembali untuk mencegah bug.

# Keluar
Program berhenti
