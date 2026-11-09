#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	struct procinfo info;
	int pid;

	if (argc != 2) {
		printf("Usage: procinfo <pid>\n");
		exit(1);
	}

	pid = atoi(argv[1]);

	if (procinfo(pid, &info) < 0) {
		printf("procinfo: process not found\n");
		exit(1);
	}

	printf("Process information:\n");
	printf("Name: %s\n", info.name);
	printf("PID: %d\n", info.pid);
	printf("PPID: %d\n", info.ppid);
	printf("State: %d bytes\n", (int)info.sz);

	exit(0);
}