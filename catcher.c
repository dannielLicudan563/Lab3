#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

volatile int termFlag = 0;

void handler(int mysignal)
{

    switch(mysignal)
    {
        case 1:
        printf("\nSIGHUP caught at %ld\n", time(NULL));
        signal(SIGHUP, handler);
        termFlag = 0;
        break;

        case 2:
        printf("\nSIGINT caught at %ld\n", time(NULL));
        signal(SIGINT, handler);
        termFlag = 0;
        break;

        case 3:
        printf("\nSIGQUIT caught at %ld\n", time(NULL));
        signal(SIGQUIT, handler);
        termFlag = 0;
        break;

        case 4:
        printf("\nSIGILL caught at %ld\n", time(NULL));
        signal(SIGILL, handler);
        termFlag = 0;
        break;

        case 5:
        printf("\nSIGTRAP caught at %ld\n", time(NULL));
        signal(SIGTRAP, handler);
        termFlag = 0;
        break;

        case 6:
        printf("\nSIGABRT caught at %ld\n", time(NULL));
        signal(SIGABRT, handler);
        printf("\nSIGIOT caught at %ld\n", time(NULL));
        signal(SIGIOT, handler);
        termFlag = 0;
        break;

        case 7:
        printf("\nSIGBUS caught at %ld\n", time(NULL));
        signal(SIGBUS, handler);
        termFlag = 0;
        break;

        case 8:
        printf("\nSIGFPE caught at %ld\n", time(NULL));
        signal(SIGFPE, handler);
        termFlag = 0;
        break;

        case 10:
        printf("\nSIGUSR1 caught at %ld\n", time(NULL));
        signal(SIGUSR1, handler);
        termFlag = 0;
        break;

        case 11:
        printf("\nSIGSEGV caught at %ld\n", time(NULL));
        signal(SIGSEGV, handler);
        termFlag = 0;
        break;

        case 12:
        printf("\nSIGUSR2 caught at %ld\n", time(NULL));
        signal(SIGUSR2, handler);
        termFlag = 0;
        break;

        case 13:
        printf("\nSIGPIPE caught at %ld\n", time(NULL));
        signal(SIGPIPE, handler);
        termFlag = 0;
        break;

        case 14:
        printf("\nSIGALRM caught at %ld\n", time(NULL));
        signal(SIGALRM, handler);
        termFlag = 0;
        break;

        case 15:
        printf("\nSIGTERM caught at %ld\n", time(NULL));
        signal(SIGTERM, handler);
        termFlag++;
        break;

        case 16:
        printf("\nSIGSTKFLT caught at %ld\n", time(NULL));
        signal(SIGSTKFLT, handler);
        termFlag = 0;
        break;

        case 17:
        printf("\nSIGCHLD caught at %ld\n", time(NULL));
        signal(SIGCHLD, handler);
        termFlag = 0;
        break;

        case 18:
        printf("\nSIGCONT caught at %ld\n", time(NULL));
        signal(SIGCONT, handler);
        termFlag = 0;
        break;

        case 20:
        printf("\nSIGTSTP caught at %ld\n", time(NULL));
        signal(SIGTSTP, handler);
        termFlag = 0;
        break;

        case 21:
        printf("\nSIGTTIN caught at %ld\n", time(NULL));
        signal(SIGTTIN, handler);
        termFlag = 0;
        break;

        case 22:
        printf("\nSIGTTOU caught at %ld\n", time(NULL));
        signal(SIGTTOU, handler);
        termFlag = 0;
        break;

        case 23:
        printf("\nSIGURG caught at %ld\n", time(NULL));
        signal(SIGURG, handler);
        termFlag = 0;
        break;

        case 24:
        printf("\nSIGXCPU caught at %ld\n", time(NULL));
        signal(SIGXCPU, handler);
        termFlag = 0;
        break;

        case 25:
        printf("\nSIGXFSZ caught at %ld\n", time(NULL));
        signal(SIGXFSZ, handler);
        termFlag = 0;
        break;

        case 26:
        printf("\nSIGVTALRM caught at %ld\n", time(NULL));
        signal(SIGVTALRM, handler);
        termFlag = 0;
        break;

        case 27:
        printf("\nSIGPROF caught at %ld\n", time(NULL));
        signal(SIGPROF, handler);
        termFlag = 0;
        break;

        case 28:
        printf("\nSIGWINCH caught at %ld\n", time(NULL));
        signal(SIGWINCH, handler);
        termFlag = 0;
        break;
    }


}

int main(int argc, char* argv[])
{
    int sigCount;

    fprintf(stderr,"%d\n", getpid());

    while(1)
    {
        signal(SIGHUP, handler);
        signal(SIGINT, handler);
        signal(SIGQUIT, handler);
        signal(SIGILL, handler);
        signal(SIGTRAP, handler);
        signal(SIGABRT, handler);
        signal(SIGIOT, handler);
        signal(SIGBUS, handler);
        signal(SIGFPE, handler);
        signal(SIGUSR1, handler);
        signal(SIGSEGV, handler);
        signal(SIGUSR2, handler);
        signal(SIGPIPE, handler);
        signal(SIGALRM, handler);
        signal(SIGTERM, handler);
        signal(SIGSTKFLT, handler);
        signal(SIGCHLD, handler);
        signal(SIGCONT, handler);
        signal(SIGTSTP, handler);
        signal(SIGTTIN, handler);
        signal(SIGTTOU, handler);
        signal(SIGURG, handler);
        signal(SIGXCPU, handler);
        signal(SIGXFSZ, handler);
        signal(SIGVTALRM, handler);
        signal(SIGPROF, handler);
        signal(SIGWINCH, handler);

        if(pause() == -1)
        {
            sigCount++;

            if(termFlag == 3)
            {
                fprintf(stderr,"Total Signal Count: %d\n", sigCount);
                exit(0);
            }
        }

    }

    return 0;
}
