#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char** argv, char** env)
{
    struct sockaddr_in localaddr, from;
    char buffer[1024];
    unsigned int fromlen;
    localaddr.sin_family = PF_INET;
    localaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    localaddr.sin_port = htons(9999);

    int desc = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    while (1)
    {
        if (bind(desc, (struct sockaddr*)&localaddr, sizeof(localaddr)) == SO_ERROR)
        {
            perror("erreur bind()");
        }
        fromlen = sizeof(from);

        int retour = recvfrom(desc, buffer, sizeof(buffer), 0, (struct sockaddr*)&from, &fromlen);

        if (retour == -1)
        {
            perror("erreur recvfrom()");
            return -1;
        }
        printf("message reçu côté client :%s\n", buffer);

        time_t timestamp = time(NULL);
        struct tm* loctime = localtime(&timestamp);

        strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", loctime);

        printf("%d.%d.%d.%d\n", (from.sin_addr.s_addr & 0xFF), (from.sin_addr.s_addr & 0xFF00) >> 8, (from.sin_addr.s_addr & 0xFF0000) >> 16, (from.sin_addr.s_addr & 0xFF000000) >> 24);

        retour = sendto(desc, buffer, strlen(buffer), 0, (struct sockaddr*)&from, sizeof(from));

        if (retour == -1){
            perror("erreur sendto()");
            return -1;
        }
    }
    close(desc);

    return (0);
}
