
#include <stdio.h>
#include <stdlib.h>

void A_Matrix(int**, int);
void print(int**, int);

int main(){

    int ver;
    printf("Enter number of vertices: ");
    scanf("%d", &ver);

    //Allocate memory for adjacency matrix

    int** a = (int**)malloc(ver * sizeof(int*));

    for(int i = 0; i < ver; i++){
        a[i] = (int*)malloc(ver * sizeof(int));

        for(int j = 0; j < ver; j++){
            a[i][j] = 0;
        }
    }
    A_Matrix(a, ver);
    print(a, ver);

    return 0;
}

void A_Matrix(int** a, int ver){

    int i,j,ans;
    do{
        printf("\nEnter edge (from to): ");
        scanf("%d %d", &i, &j);

        if(i >= 0 && i < ver && j >= 0 && j < ver){
            a[i][j] = 1;
            a[j][i] = 1;
        }
        else{
            printf("\nInvalid edge!");
        }
        printf("\nAdd more edges? (1 for Yes/ 0 for No): ");
        scanf("%d", &ans);

    }while(ans != 0);
}

void print(int **a, int ver){

    int totalDeg = 0;

    printf("\nAdjacency Matrix: \n");
    for(int i = 0; i < ver; i++){
        int deg = 0;

        for(int j = 0; j < ver; j++){
            printf("%d ", a[i][j]);

            if(a[i][j] == 1)
            deg++;
        }
        totalDeg += deg;
        printf(" Vertex %d Degree = %d\n", i ,deg);
    }
    printf("\nTotal Degree (All vertices) = %d\n", totalDeg);
}