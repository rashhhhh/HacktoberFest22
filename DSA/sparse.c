#include<stdio.h>
#include<stdlib.h>

int checkEle(int **arr,int row,int col){
    float e,t;
    int i,j,cz = 0,cn = 0;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            if(arr[i][j] == 0) cz += 1;
            else cn += 1;
        }
    }
    e = (float)cz/(cz+cn);
    t = (float)2/3;
    if(e >= t) return 1;
    else return 0;
}

int create(int **arr,int row,int col){
    int i,j,cn = 0;
    for(i = 0;i<row;i++){
        arr[i] = (int *)malloc(col*sizeof(int));
        printf("Enter elements of row %d:\n",i+1);
        for(j = 0;j<col;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] != 0) cn += 1;
        }
    }
    return(cn);
}

void createSparse(int **sm,int **arr,int srow,int row,int col){
    int i,j,k = 1;
    for(i = 0;i<srow;i++) sm[i] = (int *)malloc(3*sizeof(int));
    sm[0][0] = row;
    sm[0][1] = col;
    sm[0][2] = srow-1;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            if(arr[i][j] != 0){
                sm[k][0] = i+1;
                sm[k][1] = j+1;
                sm[k][2] = arr[i][j];
                k += 1;
            }
        }
    }
    return;
}

int count(int **s1,int **s2,int row1,int row2){
    int c,i,j,checkS;
    c = row2-1;
    for(i = 1;i<row1;i++){
        checkS = 0;
        for(j = 1;j<row2;j++){
            if(s2[j][0] == s1[i][0] && s2[j][1] == s1[i][1]) checkS = 1;
        }
        if(checkS != 1) c += 1;
    }
    return(c+1);
}

void copy(int **s1,int **s3,int row1,int row3){
    int i;
    for(i = 0;i<row3;i++) s3[i] = (int *)malloc(3*sizeof(int));
    for(i = 1;i<row1;i++){
        s3[i][0] = s1[i][0];
        s3[i][1] = s1[i][1];
        s3[i][2] = s1[i][2];
    }
    return;
}

void add(int **s2,int **s3,int row2,int row3,int row1,int row,int col){
    int i,j,lr,c;
    lr = row1;
    s3[0][0] = row;
    s3[0][1] = col;
    s3[0][2] = row3-1;
    for(i = 1;i<row2;i++){
        c = 0;
        for(j = 1;j<row3;j++){
            if(s2[i][0] == s3[j][0] && s2[i][1] == s3[j][1]){
                s3[j][2] += s2[i][2];
                c = 1;
            }
        }
        if(c == 0){
            s3[lr][0] = s2[i][0];
            s3[lr][1] = s2[i][1];
            s3[lr][2] = s2[i][2];
            lr += 1;
        }
    }
    return;
}

void print(int **sm,int srow){
    int i,j;
    for(i = 0;i<srow;i++){
        for(j = 0;j<3;j++){
            printf("%d ",sm[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(){
    int **arr1, **arr2, **sm1, **sm2, **sm3,row,col,srow1,srow2,srow3,cn1,cn2,check1,check2;
    //entering the row & column of the two matrices
    printf("Enter row:");
    scanf("%d",&row);
    printf("Enter col:");
    scanf("%d",&col);
    //creation of first matrix
    printf("Enter the first matrix\n");
    arr1 = (int **)malloc(row*sizeof(int *));
    cn1 = create(arr1,row,col);
    //creation of second matrix
    printf("Enter the second matrix\n");
    arr2 = (int **)malloc(row*sizeof(int *));
    cn2 = create(arr2,row,col);
    // checking for elegibility
    check1 = checkEle(arr1,row,col);
    check2 = checkEle(arr2,row,col);
    if(check1 && check2 == 1){
        //creating the sparse of first matrix
        srow1 = cn1+1;
        sm1 = (int **)malloc(srow1*sizeof(int *));
        createSparse(sm1,arr1,srow1,row,col);
        printf("The first sparse matrix is:\n");
        print(sm1,srow1);
        //creating the sparse of second matrix
        srow2 = cn2+1;
        sm2 = (int **)malloc(srow2*sizeof(int *));
        createSparse(sm2,arr2,srow2,row,col);
        printf("The second sparse matrix is:\n");
        print(sm2,srow2);
        //counting the row no of third sprase matrix
        srow3 = count(sm1,sm2,srow1,srow2);
        //creating the third matrix
        sm3 = (int **)malloc(srow3*sizeof(int *));
        //copying the first sparse into third
        copy(sm1,sm3,srow1,srow3);
        //adding first two matrices
        add(sm2,sm3,srow2,srow3,srow1,row,col);
        //printing sparse matrix
        printf("The final sparse matrix is:\n");
        print(sm3,srow3);
    }
    else printf("These matrices are not suitable for creating sparse matrix!");
    //clearing the space
    free(arr1);
    free(arr2);
    free(sm1);
    free(sm2);
    free(sm3);
    return 0;
}