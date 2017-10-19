#ifndef FindMin_h
#define FindMin_h


// Declare and define the findMin function here
int findMin(int N[], int x, int y){
    
    int v = N[x];
    int j = x;
    
    for ( int i = x; i < y ; i++){
        if (N[i] < v){
            v = N[i];
            j = i;
        }
    }
    return j;
    
}
// Do not write any code below this line
#endif
