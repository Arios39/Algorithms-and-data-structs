#ifndef InsertLookup_h
#define InsertLookup_h

bool find(long* list, long size, long value){
    for (long i = 0; i < size; i++) {
        if (list[i] == value){
            return true;
        }
    }
    
    return false;
}

bool find(long* list, long n, int val){
    long lower = 0;
    long upper = n;
    
    while (lower < upper){
        long mid = lower + (upper - lower)/2;
        if(list[mid] == val){
            return true;
        }
        else if (list[mid] < val){
            lower = mid + 1;
        }
        else{
            upper = mid;
        }
    }
    
    return false;
}


void insertion_sort(long list[], long size){
   long n = size;
   for (long i = 1; i < n; i++) {
       long j = i;
       while (j > 0 && list[j-1] > list[j]){
          long temp = list[j];
           list[j] = list[j-1];
          list[j-1] = temp;
           j = j - 1;
       }
   }

}



void insert(long* list, long size, long value){
   //list[size-1] = value;
  // insertion_sort(list, size);
    long j = size - 1;
    while(j>= 0 && list [j]> value){
        list [j] = list [j-1];
        j=j-1;
        
    }
    list[j+1]= value;
}

#endif
