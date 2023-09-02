#include <bits/stdc++.h>
#include <unistd.h>
#define co(a) cout<<a<<endl
#define ci(a) cin>>a
#define M 1000000000
#define ll long long
using namespace std;

float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

vector<float> Method1(){
    vector<float> res;
    for(int i=0;i<10;i++){
        res.emplace_back((mpu6050[i]+bno55[i])/2);
    }   
        return res;
}

vector<float> Method2(){
    vector<float> res;
    for(int i=0;i<10;i++){
        res.emplace_back((mpu6050[i]*0.79+bno55[i]*0.92)/(0.92+0.79));
    }   
        return res;
}


int main(){

vector<float>  m1,m2;

m1=Method1();
cout<<"Output of First Method = {";
for(auto it:m1){
    cout<<it;
    if(it!=m1[9])
        cout<<", ";
}
cout<<"}"<<endl;


m2=Method2();
cout<<"Output of Second Method = {";
for(auto it:m2){
    cout<<it;
    if(it!=m2[9])
        cout<<", ";
}
cout<<"}"<<endl;

}