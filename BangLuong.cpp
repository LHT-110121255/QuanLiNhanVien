#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200

typedef struct{
	int maso;
	char* hoten;
	int luong;	
}NhanVien;

int ms[N] = {1,2,3,4,5};
char* ht[N] = {"Nguyen Van An", "Le Thi Thuy Lieu", "Tran Minh Dao", "Ly Thu Thao", "Dang Minh Nguyen"};
int lg[N]= {300,250,1200,400,700};

/* Khoi tao mot Nhan Vien moi */
NhanVien khoiTao(int ms, char* ht, int l)
{
	NhanVien nvx; // <--rong
	
	nvx.maso = ms;
	nvx.hoten = ht;
	nvx.luong = l;
	
	return nvx; // <-- co du lieu
	
}
/* In NhanVien ra man hinh*/
void InNhanVien(NhanVien nv)
{
	printf("|%4d |",nv.maso); 
	printf("%25s |",nv.hoten);
	printf("%8d   |",nv.luong);
	printf("\n");
}

/* In bang luong */
void InBangLuong(NhanVien nvs[], int n)
{
	
	printf("+-----+--------------------------+-----------+\n");
	printf("|Ma so|            Ho ten        |    Luong  |\n");
	printf("+-----+--------------------------+-----------+\n");
	
	for (int i =0; i<n; i++)
	{
		InNhanVien(nvs[i]);
	}
	printf("+-----+--------------------------+-----------+\n");	
	
}

/* Sap xep bang luong tang dan */
void SapXepTheoLuong(NhanVien nvs[], int n)
{
	for (int i = 0; i<n; i++)
		for (int j = i; j<n; j++)
		{
			if (nvs[i].luong > nvs[j].luong)
			{
				//Hoan vi
				NhanVien tam = nvs[i];
				nvs[i]= nvs[j];
				nvs[j]=tam;
			}
		}	
}

int kiemTraDuongDan(char* filePath)
{
	FILE *myFile;
	myFile = fopen(filePath,"a");
	
	if (myFile==NULL)
	{
		printf("Error open file %s\n", filePath);
		return 0;
	}
	fclose(myFile);
	return 1;
}

void XuatBangLuongRaFile(NhanVien nvs[], char* filePath, int n)
{
	if(kiemTraDuongDan(filePath))
	{
		FILE* outFile =fopen(filePath, "w");
		
		for (int i=0 ; i<n; i++)
		{
			fwrite(&nvs[i], sizeof(NhanVien), 1, outFile);
			
		}
		if(fwrite != 0)
			printf("Xuat bang luong thanh cong vao file: %s\n", filePath);
		else
			printf("Loi ghi file !\n");
			
		fclose(outFile);
	}	
}

/* 
Doc mot bang luong n NhanVien tu filePath
Luu vao mang nvs
Return: so luong NhanVien doc duoc
*/
int DocBangLuongTuFile(NhanVien nvs[], char* filePath)
{
	FILE *inFile;	
	int i=0;
	if (kiemTraDuongDan(filePath))
	{
		inFile = fopen(filePath, "r");
		NhanVien nvInput;
		
		printf("Begin read\n");
		while(fread(&nvInput, sizeof(NhanVien), 1, inFile))
		{
			nvs[i]= nvInput;
			i++;			
		}

		// close file
		fclose (inFile);
	}
	return i;
}

int main()
{
	NhanVien myNVs[N];
	
	/*for (int i=0; i<N; i++)
	{
		myNVs[i]= khoiTao(ms[i], ht[i], lg[i]);				
		
	}*/

	int sl = DocBangLuongTuFile(myNVs, "D:\\annb\\bangluong.txt");

	
	printf("Bang luong chua sap xep \n");	
	InBangLuong(myNVs, sl);
	
	SapXepTheoLuong(myNVs, sl) ;
	
	printf("\n ======================\n Bang luong da sap xep \n");	
	InBangLuong(myNVs, sl);
	
	XuatBangLuongRaFile(myNVs, "D:\\annb\\bangluongSX.txt", sl);	
	
	
	
	return 0;
}