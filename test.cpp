#include<iostream>
using namespace std;
int x,i,maxn=-1,minn=100,maxi1=0,maxi2=0,a,maxmas1=0,maxmas2=0;
double sa,sum=0;
int mas[100];
int main()
{
setlocale(0,"");
for(i=0;i<100;i++)
mas[i]=0;
cout<<"Введите 10 чисел от 0 до 99"<<endl;
for(i=0;i<10;i++)
{
cin>>x;
mas[x]=mas[x]+1;
if(x>maxn)
maxn=x;
if(x<minn)
minn=x;
sum=sum+x;
}
a=maxn-minn;
sa=sum/10;
for(i=0;i<100;i++)
if(mas[i]>=maxi1)
{
maxi2=maxi1;
maxi1=mas[i];
maxmas2=maxmas1;
maxmas1=i;
}
cout<<"Среднее арифметическое :"<<sa<<endl;
cout<<"Размах :"<<a<<endl;
if((maxi1==maxi2)||(maxi1==1))
cout<<"Моды нет"<<endl;
else
cout<<"Мода :"<<maxmas1<<endl;
system("pause");
return 0;
}
