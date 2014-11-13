#include "ctfserver.h"

void challenge(void *);

int main()
{
    if (!ctfserver(challenge)) return 1;
    return 0;
}

void challenge(void *pSock){
    sock rsock = *((sock *)pSock);
    char rBuf[BUFSIZE];
    char *out;
    if (!rprintf(rsock, "Hey, it works!\nWhat do you say? ")) return;
    if (!rgets(rsock, rBuf)) return;
    out = strtok(rBuf, "\n");
    if (!out) return;
    if (strstr("Yes!", out))
        send_flag(rsock, "HERE IS YOUR FLAG: ");
    else
        if (!rprintf(rsock, "No, \"%s\" is not the answer we were looking for\n", out)) return;
    close(rsock);
}
