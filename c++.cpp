#include <iostream>
using namespace std;
bool isSafe(int** arr, int x, int y, int n){
    //check coln any queen is present or not
    for(int row=0;row<x;row++){
        //If queen is present it shows 1 
        if(arr[row][y]==1){
            return false;
        }
        
    }
    //check for left daigonal
    int row=x;
    int col=y;
    while(row>=0  && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    } 
    //check for right daigonal
    row=x;
    col=y;
    while(row>=0  && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}
//recursive backtracking
bool nQueen(int** arr, int x, int n){
    if(x>=n){
        return true;
    }
    //checkimg queen is safe in that position or not 
    for(int col=0;col<n;col++){
    //check is safe
        if(isSafe(arr,x,col,n)){
            //if true then place 1
            arr[x][col]=1; // place a queen
            
            if(nQueen(arr,x+1,n)){
                return true; //move to next row if successful
            }
            //if not giving true and use backtracking
            arr[x][col]=0; //backtracking step (remove the queen if not placing)
        }
    }
    //not able to place queen in any col
    return false; //no coln is safe (backtrack)
    
}

int main() {
    int n;
    cin>>n;
    //making 2d array
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    //if  no soln is possible 
    return 0;
}