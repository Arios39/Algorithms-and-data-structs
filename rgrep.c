#include <stdio.h>
#define MAXSIZE 4096
/**
 * You can use this recommended helper function
 * Returns true if partial_line y
 matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
    int i =0;


  //checks if text file and pattern input are  acceptable
  if(partial_line[i] == '\0' && pattern[i] != '\0') return 0;
    if(partial_line[1] == '\0' && pattern[i] != '\0') return 0;
    // /0 or NULL if the text file isn't empty ->
    while(partial_line[i] != '\0'){
      //while the pattern isn't empty->
      
        if(pattern[i] != '\0'){
	  //Starts to check user pattern
           // if pattern begins with wildcard \+
            //error is given if \\ function isnt defined first (tested on 3/18 ----10:55pm)
            //---------------------------------------------------------------------------------------------
            if(pattern[i] == '\\' ){
                //  printf(pattern);
                if(pattern[1] == '.' || pattern[1] == '+' || pattern[1] == '?'){
                    int n =0,count =0;
                    // function for \?
                    while(pattern[1] == '?'&& partial_line[n] != '\0'){
                        if(partial_line[n] == '?')
                            count ++;
                        n++;
                        if(count < 1)
                            return 0;
                    }
                    //moded here on ------------3/14 at 7:27pm----------------------------------------------------->>>>>>>>>>>>>>>>
                    if(pattern[n] == '?')
                        return matches_leading(partial_line, pattern +1);
                    return matches_leading(partial_line+1,pattern+2);
                }
                return matches_leading(partial_line, pattern+1);
            }
//---------------------------------------------------------------------------------------------
            
             if(pattern[i] == '?'){
                //generates random or other char
                return matches_leading(partial_line, pattern -1);
            }


            else if(pattern[1] == '?'){ //has affect on char. before it so need to check ahead
                
                if(pattern[i] == '.'  && pattern[-1] != '\\'){
                    if(matches_leading(partial_line, pattern+2))
                        return 1;
                    else if(matches_leading(partial_line+1, pattern+2))
                        return 1;
                    else
                        return 0;
                }

                
                else if(partial_line[i] == pattern[2]){
                    if(matches_leading(partial_line, pattern+2))
                        return 1;
                }
                
                else if(pattern[i] == partial_line[i])
                    return matches_leading(partial_line+1, pattern+2);
                
                else if(pattern[i] == pattern[i+2]){
                    pattern = pattern +2;
                    return matches_leading(partial_line, pattern);
                }
                else if(pattern[i] != partial_line[i])
                    return i;
                
            }
            
//---------------------------------------------------------------------------------------------

            
//---------------------------------------------------------------------------------------------
            else if(pattern[1]=='+'){
                int i=0;
                int j=0;
                if(pattern[i] == '\\' && pattern[-1] != '\\'){
                    while(partial_line[i] == '\\'){
                        partial_line++;
                        if(partial_line[i] == '\0')
                            return 0;
                    }
                    return matches_leading(partial_line,pattern+1);
                }
                if(pattern[i] == '.'){
                 //   printf(pattern);
                    if(pattern[2]=='\0')
                        return 1;
                    while(partial_line[j] != pattern[2]){
                        j++;
                        if(partial_line[j] == '\0')
                            return 0;
                    }
                    
                    return matches_leading(partial_line+j,pattern+2);
                    
                }
                while(partial_line[i] == pattern[i]){
                    i++;
                }
                if(i > 0){
                    pattern = pattern +2;
                    return matches_leading(partial_line+i, pattern);
                }
                else
                    return 0;
            }
//---------------------------------------------------------------------------------------------

            
            else if(pattern[0] == '.'){
                if(pattern[-1] == '\\')
                    return 0;
                return matches_leading(partial_line+1, pattern+1);
            }
//---------------------------------------------------------------------------------------------

            else if(partial_line[0] == pattern [0])
                return matches_leading(partial_line+1, pattern+1);
            else
                return 0;
        }
        return 1;
    }
    return 0;
}

/**
 * You may assume that all strings are properly null terminated
 * and will not overrun the buffer set by MAXSIZE
 *
 * Implementation of the rgrep matcher function
 */

int rgrep_matches(char *line, char *pattern) {
  
    int m=0;
    
    
    while(line[m] != '\0'){
        if(matches_leading(line+m, pattern))
            return 1;
        m++;
    }
    
    
    
    if(pattern[0] == '\0')
        return 1;
    return 0;
}



int main(int argc, char **argv) {
    if (argc != 2) {
        //fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }
    
    /* we're not going to worry about long lines */
    char buf[MAXSIZE];
    
    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }
    
    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }
    
    return 0;
}
