#include <stdio.h>
#include <stdlib.h>

#define FNAMELEN 255
#define MAX_STRLEN 30


struct RecordElenco {
	char nome [MAX_STRLEN+1];
	char cognome [MAX_STRLEN+1];
	unsigned int eta;
	char classe[MAX_STRLEN+1];
};

typedef struct RecordElenco elenco;


int main(int argc, char** argv) {
    elenco s;
    int i;
    FILE *puntaFile;
    char nomeFile[FNAMELEN];
    
    //Richiesta nome del file da aprire in lettura
    printf("Inserisci il nome del file che vuoi aprire in lettura: ");
    scanf("%s",nomeFile);
    
    //Apertura del file
    puntaFile = fopen(nomeFile,"r");
    if(puntaFile == NULL) {
        fprintf(stderr,"Errore nell'apertura del file %s.",nomeFile);
    }
    
    fscanf(puntaFile, "%[^;];%[^;];%[^;];%[^\n]\n", s.nome, s.cognome, s.eta, s.classe);
    
    i = 1;
    while(!feof(puntaFile)) {
        fscanf(puntaFile, "%[^;];%[^;];%d;%[^\n]\n", s.nome, s.cognome, &(s.eta), s.classe);
        fprintf(stdout,"\nStudente %d\nNome: %s\nCognome: %s\nEta':%d\nClasse: %s\n",i,s.nome,s.cognome,s.eta,s.classe);
        i++;
    }
    fclose(puntaFile);
    return (EXIT_SUCCESS);
}
