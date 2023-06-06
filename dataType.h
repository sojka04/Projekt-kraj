#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct igrac {         //2   
							   //3  
							   //10
	int redniBrojIgraca;

	int brDresa;

	char ime[20];       //1
	 
	char prezime[20];

	float broj_utakmica;

	float prosjek_minuta;

	float prosjek_poena;

	float prosjek_asistencija;

	float prosjek_skokova;

	float prosjek_ukradenih;

	float prosjek_blokada;

	float postotak_iz_polja;

	float postotak_trice;

	float postotak_bacanja;


}IGRAC;

#endif