#include<iostream>
#include<string>
#include<string.h>
#include<strings.h>
#include<fstream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{

bool time_to_end=false;

ifstream infile("C:\\Users\\Bhanu\\Desktop\\a32.s");
string temp="";
string s1="";
string line;
while (getline(infile, line))
{
    s1=line;

    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]=='a' && s1[i+1]=='n'&& s1[i+2]=='d'&& s1[i+3]=='l')
        {
            break;
        }
        if(s1[i]=='%' && s1[i+1]=='e'&& s1[i+2]=='s'&& s1[i+3]=='p')
        {
            temp=temp+"%rsp";
            i=i+4;

        }
        if(s1[i]=='%' && s1[i+1]=='e'&& s1[i+2]=='b'&& s1[i+3]=='p')
        {
            temp=temp+"%rbp";
            i=i+4;

        }
        if(s1[i]=='s' && s1[i+1]=='u'&& s1[i+2]=='b'&& s1[i+3]=='l')
        {
            temp=temp+"subq";
            i=i+4;

        }
        if(s1[i]=='p' && s1[i+1]=='u'&& s1[i+2]=='s'&& s1[i+3]=='h'&& s1[i+4]=='l')
        {
            temp = temp + "pushq";
            i=i+5;
        }
        if(s1[i]=='$' && s1[i+1]=='3' && s1[i+1]=='2')
        {
            temp=temp+" $16";
            i=i+2;
        }
        if(s1[i]=='2' && s1[i+1]=='0' && s1[i+1]=='(')
        {
            temp=temp+"-12(";
            i=i+2;
        }
        if(s1[i]=='2' && s1[i+1]=='4' && s1[i+1]=='(')
        {
            temp=temp+"-8(";
            i=i+2;
        }
        if(s1[i]=='2' && s1[i+1]=='8' && s1[i+1]=='(')
        {
            temp=temp+"-4(";
            i=i+2;
        }
        if(s1[i]==' ' && s1[i+1]=='5')
        {
            temp=temp+" 6";
            i=i+2;
        }
        if(s1[i]==' ' && s1[i+1]=='8')
        {
            temp=temp+" 16";
            i=i+2;
        }
        if(s1[i]=='-' && s1[i+1]=='8')
        {
            temp=temp+"-16";
            i=i+2;
        }
        if(s1[i]=='_' && s1[i+1]=='c' && s1[i+2]=='f' && s1[i+3]=='a' && s1[i+4]==' ' && s1[i+5]=='4' && s1[i+6]==',' && s1[i+7]==' ' && s1[i+8]=='4')
        {
            temp=temp+"_cfa 7, 8";
            i=i+9;
        }
        if(s1[i]=='.' && s1[i+1]=='n' && s1[i+2]=='o' && s1[i+3]=='t' && s1[i+4]=='e' && s1[i+5]=='.' && s1[i+6]=='G' && s1[i+7]=='N' && s1[i+8]=='U' && s1[i+8]=='-' && s1[i+8]=='s' && s1[i+8]=='t' && s1[i+8]=='a' && s1[i+8]=='c' && s1[i+8]=='k')
        {
            temp=temp+".note.GNU-stack";
            time_to_end=true;

            i=i+9;
        }


        if(i>=s1.size())
            break;
        else
            temp=temp+s1[i];
    }
temp=temp+"\n";
if(time_to_end)
    break;
}
infile.close();
cout<<endl<<temp<<endl;
ofstream out("C:\\Users\\Bhanu\\Desktop\\a32_to_64.s");
out << temp;
out.close();

return 0;
}
