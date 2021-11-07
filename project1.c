#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int processors, num_prcss, num_instr;
int swtchs, unc_swtchs, vol_swtchs;

typedef struct prcss{
	
	int prcssId;
	int exec_time;

}prcss;

void print(prcss* a){
	printf("<ID = %d, Burst = %d>\n", a->prcssId, a->exec_time);
}

void errExit(int errNum){

	fprintf(stderr, "Error: %s\n", strerror(errNum));
	exit(errNum);
}

void fromFile(FILE* inpt, prcss* a){
	int _temp;
	fscanf(inpt, "%d %d %d", &(a->prcssId), &(a->exec_time), &_temp);
}

void scan(FILE* _file, prcss* array, int size){
	
	int pid, burst, priority;
	swtchs = 0;

	while (fscanf(_file, "%d %d %d", &pid, &burst, &priority) > 0){	

		++swtchs;
	}

}


int main(int argc, char** argv){
	
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		errExit(errno);
	
	FILE* inputFile = fdopen(fd, "r");
	if (inputFile == NULL)
		errExit(errno);

	fscanf(inputFile, "%d %d %d", &processors, &num_prcss, &num_instr);

	prcss* prcss_stats = malloc(num_instr*sizeof(prcss));
	for (int i = 0; i < num_instr; i++) fromFile(inputFile, &(prcss_stats[i]));

	return 0;
}
