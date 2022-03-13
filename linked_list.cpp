#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int absen;
    const char *NIM;
    const char *nama;

    node *prev, *next;
}*head, *tail, *curr;

node *createNode(int absen, const char *nama, const char *nim){
    node *temp = (node*)malloc(sizeof(node));
    temp->nama = nama;
    temp->absen = absen;
    temp->NIM = nim;

    temp->next = temp->prev = NULL;
    return temp;
}

void pushHead(int absen, const char *nama, const char *nim){
    node *newNode = createNode(absen, nama, nim);
    if(!head){
        head = tail = newNode;
    }else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void popHead(){
    if(head == tail){
        head = tail = NULL;
    }else{
        node *temp = head;
        head = head->next;
        temp->next = head->prev = NULL;
        free(temp);
    }
}

void pushTail(int absen, const char *nama, const char *nim){
    if(head == NULL){
        head = tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

void popTail(){
    if(head == tail){
        head= tail = NULL;
    }else{
        node *temp = tail;
        tail = tail->prev;
        tail->next = temp->prev = NULL;
        free(temp);
    }
}

void popSearch(const char *nama){
    if(strcmp(head->nama, nama)==0){
        popHead();
    }else if(strcmp(tail->nama, nama)==0){
        popTail();
    }else{
        node *temp = head->next;
        while(temp){
            if(strcmp(temp->nama, nama)==0){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                temp->next = temp->prev = NULL;
                free(temp);
                return;
            }
            temp = temp->next;
        }
        printf("Data not found!\n");
    }
}

void print(){
    node *temp = head; //klo mau dari tail ke head tinggal diganti jadi tail aja
    char name[50] = "Nama";
    char no[20] = "Nim";
    printf("List Data Mahasiswa : \n");
    printf("=========================================\n");
    printf("Absen\t|%-10s\t|%-15s| \n",no, name);
    printf("=========================================\n");
    while(temp){
        printf("%d\t|%-10s\t|%-15s|\n", temp->absen, temp->NIM, temp->nama);
        printf("-----------------------------------------\n");
        temp = temp->next; //nah klo ini jadi prev
    }
    printf("=========================================\n");
    printf("\n");
}

void print2(){
    node *temp = head; //klo mau dari tail ke head tinggal diganti jadi tail aja
    char name[50] = "Nama";
    char no[20] = "Nim";
    printf("List Data Mahasiswa Baru : \n");
    printf("=========================================\n");
    printf("Absen\t|%-10s\t|%-15s| \n",no, name);
    printf("=========================================\n");
    while(temp){
        printf("%d\t|%-10s\t|%-15s|\n", temp->absen, temp->NIM, temp->nama);
        printf("-----------------------------------------\n");
        temp = temp->next; //nah klo ini jadi prev
    }
    printf("=========================================\n");
    printf("\n");
}

int main(){
    pushHead(4, "Tono Sutmaja", "2548472934");
    pushHead(3, "Toni Sutmaja", "2712312313");
    pushHead(2, "Asep", "2623772332");
    pushHead(1, "Ijal", "224234234324");
    print();


    int jumlah;
    char search[50];
    char choose;
    printf("Banyak data yang ingin dihapus : ");
    scanf("%d", &jumlah);
    getchar();
    do{
        for(int i=0;i<jumlah;i++){
            printf("Nama Mahasiswa yang ingin dihapus : ");
            scanf("%[^\n]", search);
            getchar();
            popSearch(search);
        }
        printf("\n");
        print2();
        printf("Apakah ingin menghapus data lagi? (Y|N)");
        scanf("%c", choose);
    }while(choose == 'Y');
    // for(int i=0;i<jumlah;i++){
    //     printf("Nama Mahasiswa yang ingin dihapus : ");
    //     scanf("%[^\n]", search);
    //     getchar();
    //     popSearch(search);
    // }
    // printf("\n");
    // print2();



    return 0;
}