#ifndef _ENTITIES_H
#define _ENTITIES_H
#endif

typedef struct {
    int day;
    int mounth;
    int year;
}date;

typedef struct {
    char name[31];
    char registration[13];
    char gender;
    char cpf[15];
    date birthDate;

}people;

typedef struct {
    char name[21];
    char code[11];
    char semester[7];
    people professor;
}class; 
