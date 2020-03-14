#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

char isValidIP(const char *TIP)
{
    struct sockaddr_in BIP;
    int result = inet_pton(AF_INET, TIP, &(BIP.sin_addr));
    return result == 1;
}

void locateSpecificIP(const char *TIP)
{
    if (isValidIP(TIP) != 1)
    {
        printf("Not a valid IP address.\n");
    }
    else
    {
        char url[50] = {0};
        strcpy(url, "curl ipinfo.io/");
        strcat(url, TIP);

        char url2[50] = {0};
        strcpy(url2, url);
        strcat(url, "/city");

        int result = system(url);

        if (result == -1 || result == 127)
        {
            printf("Error: Location could not be found.\n");
            exit(EXIT_FAILURE);
        }

        strcat(url2, "/country");
        result = system(url2);

        if (result == -1 || result == 127)
        {
            printf("Error: Location could not be found.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void locatePersonalIP()
{
    printf("IP address is:\n");
    int result = system("curl ipinfo.io/ip");

    if (result == -1 || result == 127)
    {
        printf("Error: IP could not be found.\n");
        exit(EXIT_FAILURE);
    }

    printf("from city:\n");
    result = system("curl ipinfo.io/city");

    if (result == -1 || result == 127)
    {
        printf("Error: Location could not be found.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        locatePersonalIP();
    }
    else
    {
        printf("Locating %s...\n", argv[1]);
        locateSpecificIP(argv[1]);
    }

    return 0;
}
