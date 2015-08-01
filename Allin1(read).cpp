#include <cstdlib>
#include <stdio.h>
#include <coni.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <coni.h>
#include <string>
#include <curl/curl.h>
void curlurl();
using namespace std;

char link[79],a[22];
string data;
fstream fs_bal;
ifstream file;

int main(int argc,char *argv[])
{
    cout<<(argv[1])<<endl;
    cout<<"\n";
	int y;
    strlen(argv[1]);
    for(int l=0;l<strlen(argv[1]);l++)
    a[l]=argv[1][l];
    cout<<a;
    Sleep(1000);
	curlurl();
	for(y=0;y<22;y++)
    {
       a[y]=NULL;
    }

   file.close();
   return 0;
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
   //callback must have this declaration
   //buf is a pointer to the data that curl has for us
   //size*nmemb is the size of the buffer
   for (int c = 0; c<size*nmemb; c++)
   {
      data.push_back(buf[c]);
   }
   return size*nmemb; //tell curl how many bytes we handled
}

void curlurl()
{
	char b[205];int j;
   for(j=0;j<205;j++)
   b[j]=NULL;
   for(j=0;j<79;j++)
   link[j]=NULL;
   data.clear();


   textcolor(15);

   CURL* curl; //our curl object
   curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
   curl = curl_easy_init();

   curl_easy_setopt(curl, CURLOPT_URL, a);
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
   curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
   curl_easy_perform(curl);

   copy(data.begin(),data.end(),&b[0]);

	/*textcolor(11);
	cout<<"here";
	textcolor(15);*/

   for(j=25;j<103;j++)
	{
     /*textcolor(14);
	  cout<<link[j-25]<<j<<endl;
	  textcolor(15);*/
  	  link[j-25]=b[j];
   }

   curl_easy_cleanup(curl);
	/*textcolor(13);
	cout<<"here";
	textcolor(15);*/

   curl_global_cleanup();

   /*textcolor(10);
	cout<<"here";
	textcolor(15);*/

	{
   	link[31]='g';
   	link[32]='e';
   	link[33]='t';
   	link[34]='B';
   	link[35]='a';
   	link[36]='l';
   	link[37]='a';
   	link[38]='n';
   	link[39]='c';
   	link[40]='e';
   }

   /*textcolor(12);
	cout<<"here\n\n\n\n\n"<<link<<endl<<endl;
	textcolor(15);*/


   if(strlen(b)>30)
   {
      fs_bal.open("Balance.txt",ios::out  | ios::app);
	   fs_bal<<link<<endl;
	   fs_bal.close();
	   cout<<data.size()<<" "<<strlen(b);
   }

   else
   {
  	  cout<<"curl is failed to connect\n";
  	  cout<<endl<<data.size()<<" "<<strlen(b)<<endl;
   }
   Sleep(2000);
}
