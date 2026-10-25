#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int nots[10];
    double toplam=0;
    int  yukseknot , dusuknot;
    for(int i=0;i<10;i++){
        cout<<i+1<<".Notu giriniz lutfen:";
        cin>>nots[i];
        while (nots[i]<0 || nots[i]>100){
        cout<<"Gecersiz not! Lütfen tekrar deneyiniz."<<endl;
        cout<<i+1<<".Notu giriniz lutfen:";
        cin>>nots[i];
        }              
    }
     yukseknot=nots[0];
     dusuknot=nots[0];
     for(int i=0;i<10;i++){
        toplam = toplam + nots[i];
        if(nots[i]>yukseknot){
            yukseknot=nots[i];
        }
        if(nots[i]<dusuknot){
            dusuknot=nots[i];
        }
        
     }
     double ortalama=toplam/10;
     cout<<"\n Girdiginiz notlar:";
     for(int i=0;i<10;i++){
        cout<<nots[i]<<" ";
     }
    cout<<"\n Sinifin not ortalamasi:"<<ortalama;
    cout<<"\n En yuksek not:"<<yukseknot;
    cout<<"\n En dusuk not:"<<dusuknot;

    cout<<"\n Ortalamanin uzerindeki notlar:";
    for(int i=0;i<10;i++){
    if(nots[i]>ortalama){
        cout<<nots[i]<<" ";
    }
    }
    cout << "\n Harf notlari:" << endl;
    for(int i=0;i<10;i++){
        string harfnotu;
        if (nots[i]>=90){
            harfnotu="AA";
        }
        else if (nots[i]>=80){
            harfnotu="BA";
        }
         else if (nots[i]>=70){
            harfnotu="BB";
        }
         else if (nots[i]>=60){
            harfnotu="CB";
        }
         else if (nots[i]>=50){
            harfnotu="CC";
        }
        else{
            harfnotu="FF";
        }    
        cout<<nots[i]<<" ---> "<<harfnotu<<endl;  
    }
    //Notları küçükten büyüğe sıralayıp ekrana yazdırdım.
     int sira[10];
        for(int i=0;i<10;i++){
            sira[i]=nots[i];
        }

     sort(sira,sira+10);
        
    cout<<"\n Kucukten buyuge siralanmis notlar:";
    for(int i=0;i<10;i++){
    cout<<sira[i]<<" ";
    }
   return 0;
}