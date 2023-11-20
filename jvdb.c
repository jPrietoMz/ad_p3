#include <stdio.h>
#include <string.h>

void updateRecord(const char *filename, const char *oldData, const char *newData) {
    FILE *oldFile = fopen(filename, "r");
    FILE *newFile = fopen("temp.txt", "w");

    if (oldFile == NULL || newFile == NULL) {
        printf("Error opening files for update.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), oldFile) != NULL) {
        if (strstr(line, oldData) == NULL) {
            fputs(line, newFile);
        } else {
            fputs(newData, newFile);
            fputs("\n", newFile);
        }
    }

    fclose(oldFile);
    fclose(newFile);

    remove(filename);
    rename("temp.txt", filename);

    printf("Record updated successfully.\n");
}

void deleteRecord(const char *filename, const char *data) {
    FILE *oldFile = fopen(filename, "r");
    FILE *newFile = fopen("temp.txt", "w");

    if (oldFile == NULL || newFile == NULL) {
        printf("Error opening files for delete.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), oldFile) != NULL) {
        if (strstr(line, data) == NULL) {
            fputs(line, newFile);
        }
    }

    fclose(oldFile);
    fclose(newFile);

    remove(filename);
    rename("temp.txt", filename);

    printf("Record deleted successfully.\n");
}

int main(int argc, char *argv[]){
    FILE *archivo;
    char *operacion=argv[1];
    char *basededatos=argv[2];
    char *nombrearchivo=argv[3];
    char ruta[100];
    strcpy(ruta,basededatos);
    strcat(ruta,"-");
    strcat(ruta,nombrearchivo);
    strcat(ruta,".txt");
    
    
    if(strcmp(operacion,"select") == 0){
        archivo = fopen(ruta,"r");
        printf("te doy datos:\n");
        char linea[1024];
        printf(ruta);
        while(fgets(linea,sizeof(linea),archivo) != NULL){
            printf("linea: %s",linea);
        }  
    }else if(strcmp(operacion,"insert") == 0){
        archivo = fopen(ruta,"a");
        char *texto = argv[4];
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
    }else if (strcmp(operacion, "update") == 0) {
        char *oldData = argv[4];
        char *newData = argv[5];
        updateRecord(ruta, oldData, newData);
    }else if (strcmp(operacion, "delete") == 0) {
        char *dataToDelete = argv[4];
        deleteRecord(ruta, dataToDelete);
    }else {
        printf("operación no válida");
    }
    
    return 0;
}