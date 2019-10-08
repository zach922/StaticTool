#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>


int* getPIDs()
{
	static int pids[20];

	DIR* dp;
	dp = opendir("/proc");

	if (dp != NULL)
 	{
	int count = 0;

	struct dirent *ep;
 		while (ep = readdir (dp))
 		{
			int pid;
 			pid = strtol(ep->d_name, NULL, 10);
 			if( ( ep->d_type == DT_DIR ) && ( pid > 0) )
 			{
 				pids[count] = pid;//(ep->d_name);
				count++;
 			}
 		}
 		closedir(dp);
 	}
 	else
 		perror ("Couldn't open the directory");

	return pids;
}

int main(void)
{
	unsigned int* pids = getPIDs();

	for(unsigned int i = 0; i < 20; i++)
	{
		if (pids[i] != 0) printf("%u\n", pids[i]);
	}
}
