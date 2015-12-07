#include <iostream>

using namespace std;

int main (){
//int i;
//float temp[31]={0.0};
int a[10]={3,4,5,10,2,8,1,12,6,52};
//char score[5]={'H','E','L','L','O'};
int i;int tot;
for (i=0,tot=0;i<10;i++){
if (a[i]%2==0){
tot+=a[i];}
}
cout << tot << endl;
}
//cout << score[i] << endl;


