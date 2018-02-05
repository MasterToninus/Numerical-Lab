#include <iostream>
#include <math.h>
#include <fstream>

#include "pendoli.h"
#include "problemicauchy.h"
using namespace std;


int main(){
        
	int N=10000;	// numero di punti
	double dt=0.005;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	t[0]=0;		//valore iniziale
    	Th[0]=(M_PI)*0.25 + 0.1;
	w[0] =0;
     
 
Runge_Kutta_secondo(F,t,Th,w,dt,N);
	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile1("spaziofasi",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();

	
	t[0]=0;		//valore iniziale
    	Th[0]=(M_PI)*0.25 + 0.15;
	w[0] =0;
Runge_Kutta_secondo(F,t,Th,w,dt,N);
	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
	ofstream myfile2("spaziofasi+",ios::trunc);
	for(int i=0;i<N;i++){myfile2<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile2.close();	



	t[0]=0;		//valore iniziale	
    	Th[0]=(M_PI)*0.25 + 0.05 ;
	w[0] =0;
Runge_Kutta_secondo(F,t,Th,w,dt,N);
	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
}
	ofstream myfile3("spaziofasi-",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile3.close();


	


 



return(0);
	}
