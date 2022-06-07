#include <stdio.h>
#include <windows.h>
#include <strings.h>
#include <stdlib.h>
#include <iostream>

#define MAX 1000

using namespace std;

typedef struct nhan_vien{
	char ma_so[11];
	char ho_ten[31];
	int luong;
}nhan_vien;

void ghiFile(nhan_vien nv[], int n, char fileName[]);
int docFile(nhan_vien nv[], char fileName[]);
void nhap_thong_tin_nhan_vien(nhan_vien &nv);
void nhap_nhan_vien(nhan_vien nv[], int n);
void in_nhan_vien(nhan_vien *nv, int n);
void quickSort_T(nhan_vien *arr, int left, int right);

int main()
{
	int key, run = true;
    char fileName[] = "DS_NhanVien.txt";
    nhan_vien arrayNV[MAX];
    int soluongNV = 0;

	// nhap danh sach nhan vien tu file
    soluongNV = docFile(arrayNV, fileName);
        
    while(run) 
	{
    	printf("CHUONG TRINH QUAN LY NHAN VIEN C/C++\n");
    	printf("*************************MENU**************************\n");
    	printf("**  1. Them nhan vien.                               **\n");
    	printf("**  2. Sap xep nhan vien theo luong.                 **\n");
    	printf("**  3. Hien thi danh sach sinh vien.                 **\n");
    	printf("**  4. Ghi danh sach sinh vien vao file.             **\n");
    	printf("**  5. Lam sach cua so                               **\n");
    	printf("**  0. Thoat                                         **\n");
    	printf("*******************************************************\n");
    	printf("Nhap tuy chon: ");
    	scanf("%d", &key);
    	switch(key)
    	{
    		case 0:
    			run = false;
    			break;
    		case 1:
    			printf("**  1. Them nhan vien.  **\n");
    			nhap_nhan_vien(arrayNV, soluongNV);
    		   	printf("\nThem nhan vien thanh cong!");
    		   	soluongNV++;
    		   	break;
    		case 2:
    			printf("**  2. Sap xep nhan vien theo luong.  **\n");
    			quickSort_T(arrayNV, 0, soluongNV);
    			in_nhan_vien(arrayNV, soluongNV);
    			break;
    		case 3:
                if(soluongNV > 0){
                    cout << "**  3. Hien thi danh sach sinh vien.  **\n";
                    in_nhan_vien(arrayNV, soluongNV);
                }else{
                    cout << "\nSanh sach nhan vien trong!";
                }
                break;
            case 4:
                if(soluongNV > 0){
                    cout << "\n4. Ghi danh sach nhan vien vao file.";
                    ghiFile(arrayNV, soluongNV, fileName);
                }else{
                    cout << "\nSanh sach nhan vien trong!";
                }
                printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
                break;
            case 5:
            	system("cls");
            	break;
            default:
            	printf("\nKhong co chuc nang nay !! Nhap lai !!");
            	break;
    	}
	}
}


void ghiFile(nhan_vien nv[], int n, char fileName[])
{
	FILE *f;
	f = fopen(fileName, "w");
	int i;
	for(i = 0; i < n; i++)
		fprintf(f,"%11s%31s%10d\n", nv[i].ma_so, nv[i].ho_ten, nv[i].luong);
	fclose(f);
}

int docFile(nhan_vien nv[], char fileName[])
{
	FILE *f;
	int i = 0;
	f = fopen(fileName, "r");
	printf("Chuan bi doc file: %s\n", fileName);
	// doc thong tin sinh vien
	while(fscanf(f,"%11s", &nv[i].ma_so) != EOF && fgets(nv[i].ho_ten, 32, f) && fscanf(f,"%10d\n", &nv[i].luong) != EOF)
	{
		i++;
		printf("Doc ban ghi thu: %d\n", i);
	}
	printf("So luong nhan vien co san trong file la: %d\n", i);
	return i;
	fclose(f);
}

void nhap_thong_tin_nhan_vien(nhan_vien &nv)
{
	printf("\nNhap ma so nhan vien: "); fflush(stdin); gets(nv.ma_so);
	printf("\nNhap ho&ten nhan vien: ");fflush(stdin); gets(nv.ho_ten);
	printf("\nNhap luong nhan vien: "); fflush(stdin); scanf("%d", &nv.luong);
}

void nhap_nhan_vien(nhan_vien nv[], int n)
{
	printf("\nNhap nhan vien thu %d", n+1);
	nhap_thong_tin_nhan_vien(nv[n]);
}
	
void in_nhan_vien(nhan_vien *nv, int n)
{
	printf("\n+-----------+------------------------------------+-----------+\n");
	printf("|  Ma So    |        Ho & Ten                    |   Luong   |\n");
	printf("+-----------+------------------------------------+-----------+\n");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("|%11s|", nv[i].ma_so);	
		printf("%36s|", nv[i].ho_ten);	
		printf("%10d |", nv[i].luong);	
		printf("\n");
	}
	printf("+-----------+------------------------------------+-----------+\n");
	printf("\n");
}	

void quickSort_T(nhan_vien *arr, int left, int right) 
{
    int i, j ;
    nhan_vien x;
    if(left >= right) return;
    x = arr[(left+right)/2];
    i = left; j = right;
    while(i <= j) {
        while(arr[i].luong < x.luong) i++;
        while(arr[j].luong > x.luong) j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++;    j--;
            }
    }
    quickSort_T(arr, left, j);
    quickSort_T(arr, i, right);
}
