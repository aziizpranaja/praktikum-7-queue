#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int maxim=50;
string data[50];
int penunjuk=-1;


bool isEmpty()
{
	if(penunjuk == -1)
	return true;
	else
	return false;
}

bool isFull()
{
	if(penunjuk == maxim-1)
	return true;
	else
	return false;
}

void enqueue()
{
	if (isFull())
	{
		cout<<"antrian sudah penuh!";
		getch();
	}
	else
	{
		penunjuk++;
		cout<<"plat nomer yang akan dimasukkan ke antrian : ";
		cin>>data[penunjuk];
		cin.ignore();
	}
}

void dequeue()
{
	if (isEmpty())
	{
		cout<<"antrian kosong!";
		getch();
	}
	else
	{
		cout<<"plat nomer mobil yang akan dikeluarkan adalah : "<<data[0];
		penunjuk--;
		for(int x=0; x<=penunjuk; x++)
		{
			data[x]=data[x+1];
		}
		getch();
	}
}

void clear()
{
	penunjuk=-1;
	cout<<"antrian sudah dikosongkan";
	getch();
}

void view()
{
	if(!isEmpty())
	{
		for(int a=penunjuk; a>=0; a--)
		{
			cout<<"data antrian mobil pada tumpukan ke-"<<a<<": "<<data[a]<<endl;
		}
	}
	else
	{
		cout<<"Antrian kosong";
	}
}



int main()
{
	int jawab;
	
	do
	{
	system("cls");
	cout<<endl;
	cout<<"Antrian mobil saat ini"<<endl<<endl;
	 view();
	cout<<endl<<endl<<endl<<endl;
	cout<<"1.Antrian parkir mobil"<<endl;
	cout<<"2.Keluarkan mobil"<<endl;
	cout<<"3.Clear"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"masukkan pilihan anda : ";
	cin>>jawab;
	
	
	switch(jawab)
	{
		case 1:
			int limit;
			cout<<"masukkan jumlah kendaraan : ";
			cin>>limit;
			
			for(int a=1; a<=limit; a++)
			{
				enqueue();
			}
			break;
		case 2:
			dequeue();
			break;
		case 3:
			clear();
			break;	
		getch();
	}
}
	while (jawab !=4);
}
