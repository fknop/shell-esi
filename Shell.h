#define BUFFER_SIZE 100
#define ARR_SIZE 10
#define TRUE 1

void shellPrompt();
int parsecmd(char * cmd, char ** args, int * bg, int * out);
int execcmd(char ** args, int * bg, int * out, int i);
void split(char * tab[], char * cmd, char * splitter);
