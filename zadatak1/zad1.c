#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct student {
	char ime[50];
	char prezime[50];
	float bodovi;
};

int main()
{
	char ImeDat[50], c;
	int br = 0, i;
	float max = 50;
	struct student* osoba;

	printf("Unesi ime datoteke: \n");
	scanf(" %s", ImeDat);

	FILE* datoteka = fopen(ImeDat, "r");

	if (datoteka == NULL)
		printf("Greska pri otvaranju datoteke!");

	for (c = getc(datoteka); c != EOF; c = getc(datoteka))
	{
		if (c == '\n')
			br++;
	}
	rewind(datoteka);

	osoba = (struct student*)malloc(br * sizeof(struct student));

	printf("Ime \t Prezime   Apsolutni bodovi   Relativni bodovi \n");

	for (i = 0; i < br; i++)
	{
		float rel;
		fscanf(datoteka, "%s %s %f", osoba[i].ime, osoba[i].prezime, &osoba[i].bodovi);
		rel = osoba[i].bodovi*max / 100;
		printf("%s \t %s %f %f \n", osoba[i].ime, osoba[i].prezime, osoba[i].bodovi, rel);
	}

	fclose(datoteka);

	return 0;
}