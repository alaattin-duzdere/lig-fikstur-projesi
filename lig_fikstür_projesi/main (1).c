#include <stdio.h>

void generateFixtures(char takimlistesi[19][256]){
  char baslangıclistesi[19][256];
  strcpy(baslangıclistesi,takimlistesi);
  char temp[256];
  char newtakimlistesi[18][256];
  char bayTakim[256];
  strcpy(bayTakim, takimlistesi[0]);
  for(int hafta=0;hafta<19;hafta++){
    // Bay gecen takimi yazdir
    printf("\n\nBay geçen takım  ====>  %s\n", bayTakim);

    if(hafta ==0){
      //Yalnizca ilk hafta icin bir takim listesi olusturuyoruz
      for(int i=0;i<18;i++){
        strcpy(newtakimlistesi[i],takimlistesi[i+1]);
      }
    }
    else{
      //Yeni takim listesi olusturuyoruz
      int j = 0; // yeni dizi için indeks
      for(int i=0;i<19;i++){
        if(i!=18){ // Bay gecen takımı atla
          strcpy(newtakimlistesi[j],takimlistesi[i]);
          j++; // Yeni dizinin indeksini artır
        }
      }
    }
    printf("-------------Hafta %d------------\n",hafta+1);
    
    //Eşleştirmeleri yap
    for(int i=0;i<9;i++){
      printf("%s - %s \n",newtakimlistesi[i],newtakimlistesi[17-i]);
    }
    
    //İlk eleman sabit tut ve diger elemanlari kaydir
    strcpy(temp, takimlistesi[1]);
    for(int i = 1; i < 19; i++) {
      strcpy(takimlistesi[i],takimlistesi[i+1]);
    }
    strcpy(takimlistesi[18], temp);
    
    //Bay gecen takim degisir
    strcpy(bayTakim, takimlistesi[18]);
    
  }

  memset(temp, 0, sizeof(temp));
  memset(bayTakim, 0, sizeof(bayTakim));
  strcpy(takimlistesi,baslangıclistesi);
  strcpy(bayTakim, takimlistesi[0]);
  for(int hafta=19;hafta<38;hafta++){
    // Bay gecen takimi yazdir
    printf("\n\nBay geçen takım  ====>  %s\n", bayTakim);

    if(hafta ==19){
      //Yalnizca ilk hafta icin bir takim listesi olusturuyoruz
      for(int i=0;i<18;i++){
        strcpy(newtakimlistesi[i],takimlistesi[i+1]);
      }
    }
    else{
      //Yeni takim listesi olusturuyoruz
      int j = 0; // yeni dizi için indeks
      for(int i=0;i<19;i++){
        if(i!=18){ // Bay gecen takımı atla
          strcpy(newtakimlistesi[j],takimlistesi[i]);
          j++; // Yeni dizinin indeksini artır
        }
      }
    }
    
    printf("-------------Hafta %d------------\n",hafta+1);

    //Eşleştirmeleri yap
    for(int i=0;i<9;i++){
      printf("%s - %s \n",newtakimlistesi[17-i],newtakimlistesi[i]);
    }

    //İlk eleman sabit tut ve diger elemanlari kaydir
    strcpy(temp, takimlistesi[1]);
    for(int i = 1; i < 19; i++) {
      strcpy(takimlistesi[i],takimlistesi[i+1]);
    }
    strcpy(takimlistesi[18], temp);

    //Bay gecen takim degisir
    strcpy(bayTakim, takimlistesi[18]);
  }
    
};

int main() {
  FILE *file;

  // Open File
  file = fopen("takimlar.txt", "r");
  if (file == NULL) {
    printf("Dosya Açılamadı.");
    return 1;
  }

  // Takimlari saydirma
  char currentLine[100];
  int takimsayisi = 0;
  while (fgets(currentLine, 100, file)) {
    takimsayisi++;
  }
  printf("Takim sayisi : %d\n\n", takimsayisi);

  // Takim sayisi kontrolu
  if (takimsayisi == 0) {
    printf("!Takim bulunamadi \n\n");
    return 1;
  } else if (takimsayisi < 19 && takimsayisi != 0) {
    printf("!Takim sayisi 19'dan kucuk \n\n");
    return 1;
  } else if (takimsayisi>19){
    printf("! Takim sayisi 19'dan buyuk \n\n");
    return 1;
  }

  //Dosyanin basina don
  rewind(file);

  // Takim listesi olusturma
  char takimlistesi[takimsayisi][256];
  char line[256];
  int count = 0;
  while (fgets(line, sizeof(line), file)) { // Satır satır oku
    line[strcspn(line, "\n")] ='\0';        // Satır sonundaki newline karakterini kaldırır
    strcpy(takimlistesi[count],line);       // Okunan satırı takimlistesi dizisine kopyalar
    count++;
  }

  // Takim listesini yazdirma
  for (int i = 0; i <= 18; i++) {
    printf("%s\n", takimlistesi[i]);
  }
  printf("\n\n");

  // Dosyayi kapatma
  fclose(file);

  // Fikstur olusturma
  generateFixtures(takimlistesi);
  
  
  
    
    
}  