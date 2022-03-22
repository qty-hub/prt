#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;
int pilihan, jmlData;

struct buah{
	char namaBuah[20];
	int hargaBuah;
} dataBuah[5], dataBuahTemp[5], temp;

/* ================================================== Input data ================================================== */
void inputData(){
	do{
		printf("============================\n");
		printf("|| Menu jumlah input data ||\n");
		printf("============================\n");
		printf("Input jumlah data (tidak lebih dari 5): "); scanf("%d", &jmlData);
		system("cls");
	}while(jmlData>5);
	printf("=====================\n");
	printf("|| Input data buah ||\n");
	printf("=====================\n");
	for(i=0; i<jmlData; i++){
		printf("Nama buah ke-%d : ", i+1); scanf("%s", &dataBuah[i].namaBuah);
		printf("Harga buah ke-%d: ", i+1); scanf("%d", &dataBuah[i].hargaBuah);
		dataBuahTemp[i]=dataBuah[i];
		printf("\n");
	}
	printf("Data berhasil dimasukkan!\n");
	printf("\n");
	printf("Press any key to continue . . . ");
}

/* ================================================== Display input ================================================== */
void sortByInput(){
	system("cls");
	printf("===================================\n");
	printf("| Nama                | Harga     |\n");
	printf("===================================\n");
	for(i=0; i<jmlData; i++){
		printf("| %-20s| %-10d|\n", dataBuahTemp[i].namaBuah, dataBuahTemp[i].hargaBuah);
	}
	printf("===================================\n");
	printf("\n");
	printf("Press any key to continue . . . ");
}

void sortByName(){
	do{
		system("cls");
		printf("==============================\n");
		printf("|| Urutkan berdasarkan nama ||\n");
		printf("==============================\n");
		printf("1. Ascending  | A -> Z\n");
		printf("2. Descending | Z -> A\n");
		printf("3. Kembali\n");
		printf("Pilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			// Ascending
			case 1:
				system("cls");
				for(i=0; i<jmlData; i++){
					for(j=i+1; j<jmlData; j++){
						if(strcmp(dataBuah[i].namaBuah, dataBuah[j].namaBuah)>0){
							temp=dataBuah[i];
							dataBuah[i]=dataBuah[j];
							dataBuah[j]=temp;
						}
					}
				}
				printf("===================================\n");
				printf("| Nama                | Harga     |\n");
				printf("===================================\n");
				for(i=0; i<jmlData; i++){
					printf("| %-20s| %-10d|\n", dataBuah[i].namaBuah, dataBuah[i].hargaBuah);
				}
				printf("===================================\n");
				printf("\n");
				printf("Press any key to continue . . . ");
				getch(); break;
			// Descending
			case 2:
				system("cls");
				for(i=0; i<jmlData; i++){
					for(j=i+1; j<jmlData; j++){
						if(strcmp(dataBuah[i].namaBuah, dataBuah[j].namaBuah)<0){
							temp=dataBuah[i];
							dataBuah[i]=dataBuah[j];
							dataBuah[j]=temp;
						}
					}
				}
				printf("===================================\n");
				printf("| Nama                | Harga     |\n");
				printf("===================================\n");
				for(i=0; i<jmlData; i++){
					printf("| %-20s| %-10d|\n", dataBuah[i].namaBuah, dataBuah[i].hargaBuah);
				}
				printf("===================================\n");
				printf("\n");
				printf("Press any key to continue . . . ");
				getch(); break;
			case 3: outputData();
		}
	}while(pilihan!=3);
}

void sortByPrice(){
	do{
		system("cls");
		printf("===============================\n");
		printf("|| Urutkan berdasarkan harga ||\n");
		printf("===============================\n");
		printf("1. Ascending  | Murah -> Mahal\n");
		printf("2. Descending | Mahal -> Murah\n");
		printf("3. Kembali\n");
		printf("Pilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			// Ascending
			case 1:
				system("cls");
				for(i=0; i<jmlData; ++i){
					for (j=i+1; j<jmlData; ++j){
						if(dataBuah[i].hargaBuah>dataBuah[j].hargaBuah){
							temp=dataBuah[i];
							dataBuah[i]=dataBuah[j];
							dataBuah[j]=temp;
						}
					}
				}
				printf("===================================\n");
				printf("| Nama                | Harga     |\n");
				printf("===================================\n");
				for(i=0; i<jmlData; i++){
					printf("| %-20s| %-10d|\n", dataBuah[i].namaBuah, dataBuah[i].hargaBuah);
				}
				printf("===================================\n");
				printf("\n");
				printf("Press any key to continue . . . ");
				getch(); break;
			// Descending
			case 2:
				system("cls");
				for(i=0; i<jmlData; ++i){
					for (j=i+1; j<jmlData; ++j){
						if(dataBuah[i].hargaBuah<dataBuah[j].hargaBuah){
							temp=dataBuah[i];
							dataBuah[i]=dataBuah[j];
							dataBuah[j]=temp;
						}
					}
				}
				printf("===================================\n");
				printf("| Nama                | Harga     |\n");
				printf("===================================\n");
				for(i=0; i<jmlData; i++){
					printf("| %-20s| %-10d|\n", dataBuah[i].namaBuah, dataBuah[i].hargaBuah);
				}
				printf("===================================\n");
				printf("\n");
				printf("Press any key to continue . . . ");
				getch(); break;
			case 3: outputData();
		}
	}while(pilihan!=3);
}

void outputData(){
	do{
		system("cls");
		printf("=========================\n");
		printf("|| Tampilkan data buah ||\n");
		printf("=========================\n");
		printf("1. Urut sesuai input\n");
		printf("2. Urutkan berdasarkan nama\n");
		printf("3. Urutkan berdasarkan harga\n");
		printf("4. Kembali\n");
		printf("Pilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			case 1: sortByInput(); getch(); break;
			case 2: sortByName();
			case 3: sortByPrice();
			case 4: main();
		}
	}while(pilihan!=4);
}

/* ================================================== Search data ================================================== */
void searchByName(){
	char fruitName[20];
	system("cls");
	printf("==============================\n");
	printf("|| Mencari data buah - Nama ||\n");
	printf("==============================\n");
	printf("Nama buah: "); scanf("%s", &fruitName);
	for(i=0; i<jmlData; i++){
		if(strcmp(fruitName, dataBuahTemp[i].namaBuah)==0){
			system("cls");
			printf("==============================\n");
			printf("|| Mencari data buah - Nama ||\n");
			printf("==============================\n");
			printf("Buah ditemukan!\n");
			printf("Nama buah : %s\n", dataBuahTemp[i].namaBuah);
			printf("Harga buah: %d\n", dataBuahTemp[i].hargaBuah);
			printf("\n");
			printf("Press any key to continue . . . ");
			getch(); searchData();
		}
	}
	system("cls");
	printf("==============================\n");
	printf("|| Mencari data buah - Nama ||\n");
	printf("==============================\n");
	printf("Buah tidak ditemukan!\n");
	printf("\n");
	printf("Press any key to continue . . . ");
	getch(); searchData();
}

void searchByPrice(){
	int fruitPrice;
	system("cls");
	printf("===============================\n");
	printf("|| Mencari data buah - Harga ||\n");
	printf("===============================\n");
	printf("Harga: "); scanf("%d", &fruitPrice);
	for(i=0; i<jmlData; i++){
		if(dataBuahTemp[i].hargaBuah==fruitPrice){
			system("cls");
			printf("===============================\n");
			printf("|| Mencari data buah - Harga ||\n");
			printf("===============================\n");
			printf("Buah ditemukan!\n");
			printf("Nama buah : %s\n", dataBuahTemp[i].namaBuah);
			printf("Harga buah: %d\n", dataBuahTemp[i].hargaBuah);
			printf("\n");
			printf("Press any key to continue . . . ");
			getch(); searchData();
		}
	}
	system("cls");
	printf("===============================\n");
	printf("|| Mencari data buah - Harga ||\n");
	printf("===============================\n");
	printf("Buah tidak ditemukan!\n");
	printf("\n");
	printf("Press any key to continue . . . ");
}

void searchData(){
	do{
		system("cls");
		printf("=======================\n");
		printf("|| Mencari data buah ||\n");
		printf("=======================\n");
		printf("1. Mencari berdasarkan nama\n");
		printf("2. Mencari berdasarkan harga\n");
		printf("3. Kembali\n");
		printf("Pilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			case 1: searchByName();
			case 2: searchByPrice(); getch(); break;
			case 3: main();
		}
	}while(pilihan!=3);
}

/* ================================================== Main ================================================== */
int main(){
	do{
		system("cls");
		printf("==================\n");
		printf("|| Menu pilihan ||\n");
		printf("==================\n");
		printf("1. Masukkan data buah\n");
		printf("2. Tampilkan data buah\n");
		printf("3. Mencari data buah\n");
		printf("4. Exit\n");
		printf("Pilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			case 1: system("cls"); inputData(); getch(); break;
			case 2: outputData(); break;
			case 3: searchData(); break;
			case 4: system("cls"); printf("Exit!"); exit(EXIT_SUCCESS);
		}
	}while(pilihan!=4);
}
