#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;

void Divide(char mtr [20][20], char text[50],int l,int &m)
{
    int k=0;
    for(int i=0; i<strlen(text); i++){
        if(text[i]!=' '){
            mtr[l][k]=text[i];
            k++;
            m=k;
        }
    }
}

void readF(char str [50], char mtr1 [20][20],int &n1, int &m1, char mtr2 [20][20], int &n2, int &m2)
{
    fstream f;
    f.open(str,ios::in);
    char text[50];
    bool flag=true;
    int l=0;
    while(!f.eof()){
        f.getline(text,50);
        if (strlen(text)==0){
            flag=false;
            f.getline(text,50);
            l=0;
        }
        if(flag==false){
            Divide(mtr2,text,l,m2);
            l++;
            n2=l;

        }else{
            Divide(mtr1,text,l,m1);
            l++;
            n1=l;
        }
    }
    f.close();
}

void SotrM(char mtr[20][20], int n, int m)
{
    bool flag=true;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(mtr[i][j]>='a' && mtr[i][j]<='z'){
                flag=true;
            }else{
                flag=false;
                break;
            }
        }
        if (flag==true){
            for (int i1=0; i1<m-1; i1++){
                for (int k=0; k<m-1; k++){
                    if (mtr[i][k]>mtr[i][k+1]){
                        swap(mtr[i][k], mtr[i][k+1]);
                    }
                }
            }
        }else{
            flag=true;
        }
    }
}

void Print(char mtr1[20][20], int n1, int m1, char mtr2[20][20], int n2, int m2){
    fstream f;
    f.open("g.txt",ios::app);
    f << endl;
    for (int i=0; i<n1; i++){
        for(int j=0;j<m1-1; j++){
            f << mtr1[i][j] << " ";
        }
        f << mtr1[i][m1-1]<< endl;
    }
    f << endl;
    for (int i=0; i<n2; i++){
        for(int j=0;j<m2; j++){
            f << mtr2[i][j] << " ";
        }
        f << endl;

    }
    f.close();
}
int main()
{
    system("CHCP 1251");
    // //1
    // int arr[10];
    // for (int i=0; i<10; i++){
    //     cin >> arr[i];
    // }
    // int ident;
    // if(arr[0]<0){
    //     ident=-1;
    // }else{
    //     ident=1;
    // }
    // int counter=0;
    // for (int i=1; i<10; i++){
    //     switch (ident)
    //     {
    //     case 1:{
    //         if(arr[i]<0){
    //             ident=-1;
    //         }else{
    //             counter++;
    //         }
    //     }
    //         break;
    //     case -1:{
    //         if(arr[i]>0){
    //             ident=1;
    //         }else{
    //             counter++;
    //         }
    //     }
    //         break;
    //     }
    // }
    // try{
    //     if (counter!=0){
    //     cout << "NO";
    //     }else{
    //         throw (counter);
    //     }
    // } catch(int num){
    //     cout << "YES";
    // }

    // //2
    // fstream f;
    // fstream f2;
    // char str[100];
    // f.open("g.txt", ios::in);
    // f2.open("g.txt",ios::app);
    // while(!f.eof()){
    //     f.getline(str,100);
    //     char mas [100][100];
    //     int l = 0;
    //     int counter=0;
    //     char* token1 = NULL;
    //     token1 = strtok(str, "*");
    //     while (token1 != NULL) {
    //         if (strcmp(token1,"testing")!=0){
    //             strcpy(mas[l],token1);
    //             l++;
    //         }else{
    //             if(counter%2==0){
    //                 strcpy(mas[l],token1);
    //                 l++;
    //             }
    //         }
    //         token1 = strtok(NULL, "*");
    //         counter++;
    //     }
    //     f2 << endl;
    //     for (int i=0; i<l; i++){
    //         f2 << mas[i] << "*";
    //     }
    // }
/////   // f.close();
    // f2.close();

    //3
    char str[50];
    char mtr1[20][20];
    char mtr2[20][20];
    strcpy(str,"g.txt");
    int n1,m1,n2,m2;
    readF(str,mtr1,n1,m1,mtr2,n2,m2);
    SotrM(mtr1,n1,m1);
    SotrM(mtr2,n2,m2);
    Print(mt r1,n1,m1,mtr2,n2,m2);
    cout << "Helllo" << endl;

}	q
