#include<iostream>
#include<conio.h>
#include<cstring>
#include<ctype.h>
using namespace std;
class String
{
 private:
  char* str;
 public:
  String(char* s)
   {
    int L=strlen(s);
    str=new char[L+1];
    strcpy(str,s);
   }
 //~String()
   //{
    //delete[]str;
   //}
  void display()
   {
    cout<<str<<endl;
   }
  void upit();

};
void String::upit()
   {
    int l=strlen(str);
    int j;
    for(j=0;j<l;j++)
    {
     switch(*(str+j))
     {
      case 'a':*(str+j)='A';break;
      case 'b':*(str+j)='B';break;
      case 'c':*(str+j)='C';break;
      case 'd':*(str+j)='D';break;
      case 'e':*(str+j)='E';break;
      case 'f':*(str+j)='F';break;
      case 'g':*(str+j)='G';break;
      case 'h':*(str+j)='H';break;
      case 'i':*(str+j)='I';break;
      case 'j':*(str+j)='J';break;
      case 'k':*(str+j)='K';break;
      case 'l':*(str+j)='L';break;
      case 'm':*(str+j)='M';break;
      case 'n':*(str+j)='N';break;
      case 'o':*(str+j)='O';break;
      case 'p':*(str+j)='P';break;
      case 'q':*(str+j)='Q';break;
      case 'r':*(str+j)='R';break;
      case 's':*(str+j)='S';break;
      case 't':*(str+j)='T';break;
      case 'u':*(str+j)='U';break;
      case 'v':*(str+j)='V';break;
      case 'w':*(str+j)='W';break;
      case 'x':*(str+j)='X';break;
      case 'y':*(str+j)='Y';break;
      case 'z':*(str+j)='Z';break;
     }
    }
    *(str+j)='\0';
   }
int main()
{
 char* st="vyshe!!! silnee!!! bystree!!!";
 String s1=st;
 s1.display();
 s1.upit();
 s1.display();
         getch();
        return 0;
}
//---------------------------------------------------------------------------
 