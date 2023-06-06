#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"

static int brojIgraca = 0;   //5 

void kreiranjeDatoteke(const char* const ime)      //7 
												   //16
{
	FILE* fileIgraci = fopen(ime, "wb");
	if (fileIgraci == NULL)
	{
		perror("Kreiranje datoteke igraci.bin");
		exit(EXIT_FAILURE);
	}

	fwrite(&brojIgraca, sizeof(int), 1, fileIgraci);

	printf("Kreirana je datoteka igraci.bin\n\n");

	fclose(fileIgraci);
}

void dodavanjeIgraca(const char* const ime)
{
	FILE* fileIgraci = fopen(ime, "rb+");

	if (fileIgraci == NULL)
	{
		perror("Dodavanje igraca u igraci.bin");

		exit(EXIT_FAILURE);
	}

	fread(&brojIgraca, sizeof(int), 1, fileIgraci);

	printf("Broj igraca: %d\n\n", brojIgraca);

	IGRAC temp = { 0 };
	temp.redniBrojIgraca = brojIgraca;

	printf("Unesite broj dresa igraca: ");
	scanf("%d", &temp.brDresa);
	getchar();

	printf("Unesite ime igraca: ");
	scanf("%19[^\n]", &temp.ime);
	getchar();

	printf("Unesite prezime igraca: ");
	scanf("%19[^\n]", &temp.prezime);
	getchar();

	printf("Unesite broj utakmica igraca: ");
	scanf("%f", &temp.broj_utakmica);
	getchar();

	printf("Unesite prosjek minuta igraca: ");
	scanf("%f", &temp.prosjek_minuta);
	getchar();

	printf("Unesite prosjek poena igraca: ");
	scanf("%f", &temp.prosjek_poena);
	getchar();

	printf("Unesite prosjek asistencija igraca: ");
	scanf("%f", &temp.prosjek_asistencija);
	getchar();

	printf("Unesite prosjek skokova igraca: ");
	scanf("%f", &temp.prosjek_skokova);
	getchar();

	printf("Unesite prosjek ukradenih lopti igraca: ");
	scanf("%f", &temp.prosjek_ukradenih);
	getchar();

	printf("Unesite prosjek blokada igraca: ");
	scanf("%f", &temp.prosjek_blokada);
	getchar();

	printf("Unesite postotak iz polja igraca: ");
	scanf("%f", &temp.postotak_iz_polja);
	getchar();

	printf("Unesite postotak trice igraca: ");
	scanf("%f", &temp.postotak_trice);
	getchar();

	printf("Unesite postotak bacanja igraca: ");
	scanf("%f", &temp.postotak_bacanja);
	getchar();


	fseek(fileIgraci, sizeof(IGRAC) * brojIgraca, SEEK_CUR);
	fwrite(&temp, sizeof(IGRAC), 1, fileIgraci);
	printf("\nNovi igrac dodan.\n\n");

	rewind(fileIgraci);
	brojIgraca++;

	fwrite(&brojIgraca, sizeof(int), 1, fileIgraci);

	fclose(fileIgraci);
}

void* ucitavanjeIgraca(const char* const ime)
{
FILE* fileIgraci = fopen(ime, "rb");

	if (fileIgraci == NULL)
	{
		perror("Ucitavanje igraca iz igraci.bin");     //19
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojIgraca, sizeof(int), 1, fileIgraci);
	printf("Broj igraca u bazi podataka: %d\n\n", brojIgraca);

	IGRAC* poljeIgraca = (IGRAC*)calloc(brojIgraca, sizeof(IGRAC));          //13

	if (poljeIgraca == NULL)
	{
		perror("Zauzimanje memorije za igrace");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeIgraca, sizeof(IGRAC), brojIgraca, fileIgraci);

	//printf("Svi igraci su uspjesno ucitani.\n\n");

	return poljeIgraca;
}

void ispisPodataka(const IGRAC* const polje) {

	if (polje == NULL)
	{
		printf("Polje igraca prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojIgraca; i++)
	{
		printf("Broj igraca: %d.\n\tBroj dresa: %d\n\tIme: %s\n\tPrezime: %s\n\tBroj utakmica: %0.f\n\tProsjecna minutaza: %.1f min\n\tPoeni: %.1f pts\n\tAsistencije: %.1f\n\tSkokovi: %.1f\n\tUkradene lopte: %.1f\n\tBlokade: %.1f\n\tPostotak iz polja: %.1f\n\tPostotak trice: %.1f\n\tPostotak bacanja: %.1f\n\n",
			i + 1,
			(polje + i)->brDresa,
			(polje + i)->ime,
			(polje + i)->prezime,
			(polje + i)->broj_utakmica,
			(polje + i)->prosjek_minuta,
			(polje + i)->prosjek_poena,
			(polje + i)->prosjek_asistencija, 
			(polje + i)->prosjek_skokova,
			(polje + i)->prosjek_ukradenih, 
			(polje + i)->prosjek_blokada,
			(polje + i)->postotak_iz_polja, 
			(polje + i)->postotak_trice,
		    (polje + i)->postotak_bacanja);

	}
}

void* dresIgraca(IGRAC* const polje)
{
	if (polje == NULL)
	{
		printf("Polje igraca je prazno\n");
		return;
	}

	int i;

	int trazeniDres;

	printf("Unesite broj dresa igraca kojeg trazite: \n\n");
	scanf("%d", &trazeniDres);

	for (i = 0; i < brojIgraca; i++) {

		if (trazeniDres == (polje + i)->brDresa) {
			printf("Igrac pronaden.\n\n");

			return (polje + i);
		}
	}

	return NULL;
}

void* imeIgraca(IGRAC* const polje)
{
	if (polje == NULL)
	{
		printf("Polje igraca je prazno.\n");
		return;
	}

	int i;

	char trazenoIme[20];

	printf("Unesite ime igraca kojeg trazite: \n\n");
	scanf("%s", &trazenoIme);

	for (i = 0; i < brojIgraca; i++) {

		if (strcmp((polje + i)->ime, trazenoIme) == 0) {
			
				printf("Igrac pronaden.\n\n");

			return (polje + i);
		}
	}

	return NULL;
}

void* prezimeIgraca(IGRAC* const polje)
{

	if (polje == NULL)
	{
		printf("Polje igraca je prazno\n");
		return;
	}

	int i;

	char trazenoPrezime[20];

	printf("Unesite prezime igraca kojeg trazite: \n\n");
	scanf("%s", &trazenoPrezime);

	for (i = 0; i < brojIgraca; i++) {

		if (strcmp((polje + i)->prezime, trazenoPrezime) == 0) {
			printf("igrac pronaden.\n\n");

			return (polje + i);
		}
	}

	return NULL;
}

int izlazIzPrograma(IGRAC* polje) {

	free(polje);                      //14  
									  //15

	return 0;
}