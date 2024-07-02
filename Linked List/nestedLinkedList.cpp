#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Matkul{
    char name[56];
    Matkul *next, *prev;
};

struct Jurusan{
    char name[56];
    Jurusan *prev, *next;
    Matkul *mhead, *mtail;
};

Matkul* createMatkul(char name[]){
    Matkul* newMatkul = (Matkul*)malloc(sizeof(Matkul));
    strcpy(newMatkul->name, name);
    newMatkul->next = newMatkul->prev = NULL;

    return newMatkul;
}

Jurusan* createJurusan(char name[]){
    Jurusan* newJurusan = (Jurusan*)malloc(sizeof(Jurusan));
    strcpy(newJurusan->name, name);
    newJurusan->next = newJurusan->prev = NULL;
	newJurusan->mhead = newJurusan->mtail = NULL;
	
    return newJurusan;
}

void pushMatakuliah(Jurusan* jtemp, char matkulName[]){
    if(!jtemp) return;

    //push data
    Matkul* newMatkul = createMatkul(matkulName);
    if(!jtemp->mhead){
        jtemp->mhead = jtemp->mtail = newMatkul;
        return;
    } else {
        newMatkul->prev = jtemp->mtail;
        jtemp->mtail->next = newMatkul;
        jtemp->mtail = newMatkul;
        return;
    }
}

void pushJurusan(Jurusan** jhead, Jurusan** jtail, char jurusanName[]){
    Jurusan* jcurr = createJurusan(jurusanName);
    if(!(*jhead)){
        (*jhead) = (*jtail) = jcurr;
        return;
    } else {
        jcurr->prev = (*jtail);
        (*jtail)->next = jcurr;
        (*jtail) = jcurr;
        return;
    }
}

Jurusan* searchJurusan(Jurusan* jhead, char jurusanName[]){
    if(!jhead) return NULL;

    Jurusan* jcurr = jhead;
    while(jcurr){
        if(strcmp(jcurr->name, jurusanName) == 0){
            return jcurr;
        }
        jcurr = jcurr->next;
    }
    return NULL;
}

void pushMatkulByJurusan(Jurusan** jhead, char jurusanName[], char matkulName[]){
    if(!*jhead) {
        printf("There are no jurusan avaiable!\n");
        return;
    }

    Jurusan* temp = searchJurusan(*jhead, jurusanName);
    if(!temp){
        printf("Jurusan not found!\n");
        return;
    }

    pushMatakuliah(temp, matkulName);
    return;
}

void printAllData(Jurusan* jhead){
    if(!jhead){
        printf("There are no data!\n");
        return;
    }

    Jurusan* curr = jhead;
    while(curr){
        printf("Jurusan: %s\n", curr->name);
        Matkul* currMatkul = curr->mhead;
        if(!currMatkul){
            printf("Jurusan ini tidak ada matkulnya!\n");
        }
		int i = 1;
        while(currMatkul){
            printf("%d. %s\n",i, currMatkul->name);
            i++;
            currMatkul = currMatkul->next;
        }
        puts("\n");
        curr = curr->next;
    }
}

int main(){

    Jurusan *jhead, *jtail;
    jhead = jtail = NULL;

    pushJurusan(&jhead, &jtail, "Data Science");
    pushJurusan(&jhead, &jtail, "Computer Science");
    pushJurusan(&jhead, &jtail, "Information System");

	pushMatkulByJurusan(&jhead, "Data Science", "Database");
	pushMatkulByJurusan(&jhead, "Data Science", "Intro to Machine Learning");
	
	pushMatkulByJurusan(&jhead, "Computer Science", "HCI");
	pushMatkulByJurusan(&jhead, "Computer Science", "Data Structure");
	
	pushMatkulByJurusan(&jhead, "Information System", "Java");
	pushMatkulByJurusan(&jhead, "Information System", "Database");

    printAllData(jhead);

    return 0;
}
