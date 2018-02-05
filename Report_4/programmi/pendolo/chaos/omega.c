#include <iostream>
#include <math.h>
#include <fstream>

#include "pendoli.h"
#include "problemicauchy.h"
using namespace std;

int main(){
        
	int N=20000;	// numero di punti
	double dt=0.005;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	
	
	t[0]=0;		//valore iniziale
    	Th[0]=0;
	w[0] =0;
     
 
Runge_Kutta_secondo(F12,t,Th,w,dt,N);


    	ofstream myfile("omega/omega_+",ios::trunc);
	for(int i=0;i<N;i++){myfile<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile.close();

//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile1("omega/omega_+_fasi",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();




	Runge_Kutta_secondo(F1,t,Th,w,dt,N);

	ofstream myfile3("omega/omega_0",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile3.close();
	
	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile4("omega/omega_0_fasi",ios::trunc);
	for(int i=0;i<N;i++){myfile4<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile4.close();



	Runge_Kutta_secondo(F11,t,Th,w,dt,N);

	ofstream myfile5("omega/omega_-",ios::trunc);
	for(int i=0;i<N;i++){myfile5<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile5.close();

	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile6("omega/omega_-_fasi",ios::trunc);
	for(int i=0;i<N;i++){myfile6<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile6.close();



return(0);
	}
