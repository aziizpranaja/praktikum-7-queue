#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 8

using namespace std;

typedef struct
{
	int data[MAX];
	int head;
	int tail;
}antri;

antri antrian;

void Create()
{
	antrian.head=antrian.tail=-1;
}

int isEmpty()
{
	if(antrian.tail==-1)
	return 1;
	else 
	return 0;
}

int isFull()
{
	if(antrian.tail==MAX-1)
	return 1;
	else
	return 0;
}

void Enantri(int data)
{
	int no=1;
	if(isEmpty()==1)
	{
		antrian.head=antrian.tail=0;
		antrian.data[antrian.tail]=data;
		
		cout<<data<<"masuk antrian ke-"<<no;
	}
	else 
	{
		if(isFull()==0)
		{
			antrian.tail++;
			antrian.data[antrian.tail]=data;
			if(antrian.tail==0)
			no=no+1;
			else
			no+=antrian.tail;
			
			cout<<data<<"masuk antrian ke-"<<no;
		}
		else
		{
			cout<<"data full\n";
		}
	}
}

int Deantri()
{
	int i;
	int e =antrian.data[antrian.head];
	for (i=antrian.head; i<=antrian.tail-1; i++)
	{
		antrian.data[i] = antrian.data[i+1];
	}
	antrian.tail--;
	return e;
}

void clear()
{
	antrian.head=antrian.tail=-1;
	cout<<"data clear";
}

void tampil()
{
	if(isEmpty()==0)
	{
		for (int i=antrian.head; i<=antrian.tail; i++)
		{
			cout<<antrian.data[i];
		}
	}
	else
	{
		cout<<"data kosong";
	}
}

void operasidata(int pill)
{
	int jum=0;
	int b = antrian.tail+1;
	float avg;
	
	if(isEmpty()==0)
	{
		for(int i=antrian.head; i<=antrian.tail; i++)
		{
			jum=jum+antrian.data[i];
		}
		avg=jum/b;
		
		switch (pill)
		{
			case 1:
				cout<<"jumlah datanya : "<<jum;
				break;
			case 2:
				cout<<"rata rata datanya : "<<avg;
				break;
			case 3:
				cout<<"banyak datanya : "<<antrian.tail+1;
				break;
			default :
				break;
		}
	}
	else 
	{
		cout<<"data kosong"<<endl;
	}
}

int main()
{
	int pil;
	int data;
	
	Create();
	
	do
	{
		system("CLS");
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Tampil"<<endl;
		cout<<"4.Bersihkan"<<endl;
		cout<<"5.Banyaknya data"<<endl;
		cout<<"6.Jumlah data"<<endl;
		cout<<"7.Rata-rata data"<<endl;
		cout<<"8.Exit"<<endl;
		cout<<"Masukkan pilihan : ";
		cin>>pil;
		
		switch (pil)
		{
			case 1:
				if(isFull()==0)
				{
					cout<<"data : ";
					cin>>data;
				}
				Enantri(data);
				break;
			case 2:
				cout<<"elemen yang keluar : "<<Deantri();
				break;
			case 3:
				tampil();
				break;
			case 4:
				clear();
				break;
			case 5:
				operasidata(3);
				break;
			case 6:
				operasidata(1);
				break;
			case 7:
				operasidata(2);
				break;
			case 8:
				return(0);
				break;
			default :
				cout<<"silahkan masukkan nomer yang tersedia";
				break;
		}
		getch();
	}
	while(pil!=8);
}
