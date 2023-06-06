#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

int main(void)                //4 
							  //6    
{
	int odgovor = 1;

	char* datoteka = "igraci.txt";

	while (odgovor) {
		odgovor = izbornik(datoteka);
	}

	printf("Kraj programa");

	return 0;
}