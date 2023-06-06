#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "header.h"

static int brojIgraca = 0;

int izbornik(const char* const ime)
{
	int odgovor = 0;

	static IGRAC* poljeIgraca = NULL;

	static IGRAC* pronadeniIgrac = NULL;

	if (poljeIgraca != NULL)
	{
		free(poljeIgraca);
		poljeIgraca = NULL;
	}

	poljeIgraca = (IGRAC*)ucitavanjeIgraca(ime);

	if (poljeIgraca == NULL)
	{
		exit(EXIT_FAILURE);
	}

	printf("\n\t\t**************************************************\n\n");                      //8
	printf("\t\tOdaberite jednu od opcija: \n\n");

	printf("\t\tOpcija 1: Kreiranje datoteke\n");
	printf("\t\tOpcija 2: Dodavanje igraca\n");
	printf("\t\tOpcija 3: Ispisi podatke o svim igracima\n");
	printf("\t\tOpcija 4: Pretrazi igraca po broju dresa\n");
	printf("\t\tOpcija 5: Pretrazi igraca po imenu\n");
	printf("\t\tOpcija 6: Pretrazi igraca po prezimenu\n");
	printf("\t\tOpcija 7: Izlaz iz programa\n\n");

	printf("\t\t**************************************************\n\n");

	scanf("%d", &odgovor);

	switch (odgovor)
	{
	case 1:
		system("cls");
		kreiranjeDatoteke(ime);
		break;

	case 2:
		system("cls");
		dodavanjeIgraca(ime);
		break;

	case 3:
		system("cls");

		ispisPodataka(poljeIgraca);

		break;

	case 4:
		system("cls");

		pronadeniIgrac = (IGRAC*)dresIgraca(poljeIgraca);

		if (pronadeniIgrac != NULL)
		{
			printf("Redni broj igraca: %d.\n", pronadeniIgrac->redniBrojIgraca);
			printf("Broj dresa: %d\n", pronadeniIgrac->brDresa);
			printf("Ime: %s\n", pronadeniIgrac->ime);
			printf("Prezime: %s\n", pronadeniIgrac->prezime);
			printf("Broj utakmica: %f\n", pronadeniIgrac->broj_utakmica);
			printf("Minutaza: %.1f\n", pronadeniIgrac->prosjek_minuta);
			printf("Poeni: %.1f\n", pronadeniIgrac->prosjek_poena);
			printf("Asistencije: %.1f\n", pronadeniIgrac->prosjek_asistencija);
			printf("Skokovi: %.1f\n", pronadeniIgrac->prosjek_skokova);
			printf("Ukradene lopte: %.1f\n", pronadeniIgrac->prosjek_ukradenih);
			printf("Blokade: %.1f\n", pronadeniIgrac->prosjek_blokada);
			printf("Postotak iz polja: %.1f\n", pronadeniIgrac->postotak_iz_polja);
			printf("Postotak trice: %.1f\n", pronadeniIgrac->postotak_trice);
			printf("Postotak bacanja: %.1f\n", pronadeniIgrac->postotak_bacanja);


		}
		else
		{
			printf("Ne postoji igrac s tim brojem dresa.\n");
		}

		break;

	case 5:
		system("cls");

		pronadeniIgrac = (IGRAC*)imeIgraca(poljeIgraca);

		if (pronadeniIgrac != NULL)
		{
			printf("Redni broj igraca: %d.\n", pronadeniIgrac->redniBrojIgraca);
			printf("Broj dresa: %d\n", pronadeniIgrac->brDresa);
			printf("Ime: %s\n", pronadeniIgrac->ime);
			printf("Prezime: %s\n", pronadeniIgrac->prezime);
			printf("Broj utakmica: %f\n", pronadeniIgrac->broj_utakmica);
			printf("Minutaza: %.1f\n", pronadeniIgrac->prosjek_minuta);
			printf("Poeni: %.1f\n", pronadeniIgrac->prosjek_poena);
			printf("Asistencije: %.1f\n", pronadeniIgrac->prosjek_asistencija);
			printf("Skokovi: %.1f\n", pronadeniIgrac->prosjek_skokova);
			printf("Ukradene lopte: %.1f\n", pronadeniIgrac->prosjek_ukradenih);
			printf("Blokade: %.1f\n", pronadeniIgrac->prosjek_blokada);
			printf("Postotak iz polja: %.1f\n", pronadeniIgrac->postotak_iz_polja);
			printf("Postotak trice: %.1f\n", pronadeniIgrac->postotak_trice);
			printf("Postotak bacanja: %.1f\n", pronadeniIgrac->postotak_bacanja);


		}
		else
		{
			printf("Ne postoji igrac s tim imenom.\n");
		}

		break;

	case 6:
		system("cls");

		pronadeniIgrac = (IGRAC*)prezimeIgraca(poljeIgraca);

		if (pronadeniIgrac != NULL)
		{
			printf("Redni broj igraca: %d.\n", pronadeniIgrac->redniBrojIgraca);
			printf("Broj dresa: %d\n", pronadeniIgrac->brDresa);
			printf("Ime: %s\n", pronadeniIgrac->ime);
			printf("Prezime: %s\n", pronadeniIgrac->prezime);
			printf("Broj utakmica: %f\n", pronadeniIgrac->broj_utakmica);
			printf("Minutaza: %.1f\n", pronadeniIgrac->prosjek_minuta);
			printf("Poeni: %.1f\n", pronadeniIgrac->prosjek_poena);
			printf("Asistencije: %.1f\n", pronadeniIgrac->prosjek_asistencija);
			printf("Skokovi: %.1f\n", pronadeniIgrac->prosjek_skokova);
			printf("Ukradene lopte: %.1f\n", pronadeniIgrac->prosjek_ukradenih);
			printf("Blokade: %.1f\n", pronadeniIgrac->prosjek_blokada);
			printf("Postotak iz polja: %.1f\n", pronadeniIgrac->postotak_iz_polja);
			printf("Postotak trice: %.1f\n", pronadeniIgrac->postotak_trice);
			printf("Postotak bacanja: %.1f\n", pronadeniIgrac->postotak_bacanja);



		}
		else
		{
			printf("Ne postoji igrac s tim prezimenom.\n");
		}

		break;

	case 7:
		system("cls");
		odgovor = izlazIzPrograma(poljeIgraca);
		break;

	default:
		odgovor = 0;
	}

	return odgovor;
}
