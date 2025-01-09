
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char * args[])
{

    if(argc < 2){
        printf("ERROR, TOO LITTLE ARGUMENTS TO MAKE A LOG!!");
        return 1;
    }

    char prefix[] = "logs\\";

    time_t epochTime = time(NULL);
    struct tm timeS;
    localtime_s(&timeS, &epochTime);

    char timeString[32];
    sprintf(timeString, "%d-%d-%d-%d-%d-%d", 
        timeS.tm_year+1900, 
        timeS.tm_mon+1, 
        timeS.tm_mday, 
        timeS.tm_hour, 
        timeS.tm_min, 
        timeS.tm_sec);

    char filepath[64];
    // char cwd[64];
    // getcwd(cwd, 64);
    sprintf(filepath, "%s%s.txt", prefix, timeString);
    if(mkdir("logs")){
        if(errno != EEXIST){
            printf("Something happened!!");
            return 2;
        }
    }
    
    FILE *file = fopen(filepath, "w");
    for(int i = 1; i < argc; i++){
        fprintf(file, "%s ", args[i]);
    }

    fclose(file);

    printf("Successfully saved to %s\n Have a great day ^_^ \n", filepath);


    return 0;
}