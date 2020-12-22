
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define DIM_MAX 100

using namespace std;

struct recStudente{
	string nome;
	string cognome;
	int numero_matricola;
	int eta;
	int voto;
};

void classifica(recStudente stud[], int n);
recStudente scambio (recStudente &x, recStudente &y);

void classifica(recStudente stud[], int n){
	int i=0, j=0;
	fstream fileRisultati_ordinati;
	
	fileRisultati_ordinati.open("Risultati_ordinati.txt",ios::out);

	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
			if (stud[i].voto > stud[j].voto){
				/*
					recStudente z;
					z = stud[i];
					stud[i] = stud[j];
					stud[j] = z;
				*/
				scambio (stud[i],stud[j]);
			}
		}
	}
		
	fileRisultati_ordinati<<"CLASSIFICA: "<<endl;

	for (int i=n-1; i>=0;i--){
		fileRisultati_ordinati<<stud[i].nome<<"\t";
		fileRisultati_ordinati<<stud[i].cognome<<"\t";
		fileRisultati_ordinati<<stud[i].numero_matricola<<"\t";
		fileRisultati_ordinati<<stud[i].eta<<"\t";
		fileRisultati_ordinati<<stud[i].voto;
		fileRisultati_ordinati<<endl;
	}
	
	fileRisultati_ordinati.close();
}

recStudente scambio (recStudente &x, recStudente &y){
	recStudente z;
	z = x;
	x = y;
	y = z;
}


int main(void){
	int numeroStudenti=0, conta=0, i=0;
	recStudente studente[DIM_MAX];
	fstream fileRisultati;
	
	fileRisultati.open("eeee.txt",ios::in);

	while (!fileRisultati.eof()){
		fileRisultati >> studente[i].nome;
		fileRisultati >> studente[i].cognome;
		fileRisultati >> studente[i].numero_matricola;
		fileRisultati >> studente[i].eta;
		fileRisultati >> studente[i].voto;		
		i++;
		conta++;
	}
	
	fileRisultati.close();
	
	classifica(studente, conta);

	system("PAUSE");
}
