#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

short int measurementInterval = 10; // Measurement interval in seconds.
char measurementPoints = 0;         // Times for recording bandwidth.

// Finds if information is available about interface
char findInterfaceInfo(char *path, char *interface)
{
    if (strstr(interface, "upload"))
    {
        strcat(path, "/statistics/tx_bytes");
    }
    else if (strstr(interface, "download"))
    {
        strcat(path, "/statistics/rx_bytes");
    }
    else
    {
        printf("Error: Enter a valid input; \'upload\' or \'download\'?\n");
        return -1;
    }

    struct stat linkAttributes;

    if ((lstat(path, &linkAttributes)) != 0)
    {
        if (errno == ENOENT)
        {
            fprintf(stderr, "Error_lstat: No information about interface.\n");
            return (-1);
        }
        else
        {
            perror("Error_lstat: ");
            return (-1);
        }
    }

    if (!S_ISREG(linkAttributes.st_mode))
    {
        fprintf(stderr, "Error_S_ISREG: Information could not be interpreted.\n");
        return (-1);
    }

    if (!((linkAttributes.st_mode & S_IRUSR) && (linkAttributes.st_mode & S_IRGRP) && (linkAttributes.st_mode & S_IROTH)))
    {
        printf("Warning: You may not have the permission to access to this information.\n");
        return (-1);
    }

    return 0;
}

// Finds if network interface exist
char findInterface(char *path, char *interface)
{
    strcpy(path, "/sys/class/net/");
    strcat(path, interface);
    struct stat linkAttributes;

    if ((lstat(path, &linkAttributes)) != 0)
    {
        if (errno == ENOENT)
        {
            fprintf(stderr, "Error_lstat: No such network interface.\n");
            return (-1);
        }
        else
        {
            perror("Error_lstat: ");
            return (-1);
        }
    }

    return 0;
}

// Interface information for current online session.
void session(char *path)
{
    FILE *file = NULL;
    if ((file = fopen(path, "r")) == NULL)
    {
        perror("Error_fopen");
        exit(-1);
    }

    char buffer[128];

    if (fgets(buffer, 127, file) == NULL)
    {
        perror("Error_fgets");
        exit(-1);
    }

    buffer[511] = '\0';

    printf("%s", buffer);

    if (fclose(file) != 0)
    {
        perror("Error_fclose");
        exit(-1);
    }
}

// Find BPS interval, max, min, and total network load
char process_information()
{
    FILE *resFile = fopen("data.txt", "r");

    if (resFile == NULL)
    {
        printf("Error_fopen\n");
        exit(1);
    }

    FILE *calFile = fopen("pdata.txt", "w");

    if (resFile == NULL)
    {
        printf("Error_fopen\n");
        exit(1);
    }

    char buffer[12] = {0};
    int i = 0;
    int t1_data = 0, t2_data = 0;
    int Total = 0, min = 0, max = 0;
    int usage = 0;
    printf("Processing the data...\n");

    for (i = 0; i < measurementPoints; i++)
    {
        if (fgets(buffer, 12, resFile) == NULL)
        {
            perror("Error_fgets");
            return (-1);
        }

        t2_data = atoi(buffer);

        if (i == 0)
        {
            t1_data = t2_data;
            Total = t2_data;
        }

        usage = t2_data - t1_data;

        if (i == 1)
        {
            min = usage;
        }

        if (usage > max)
        {
            max = usage;
        }
        else if (usage <= min)
        {
            min = usage;
        }

        fprintf(calFile, "%d\n", usage);
        printf("%d\tB\t", usage);
        t1_data = t2_data;
        printf("Interval %d (%d sec)\n", i, measurementInterval);
        bzero(buffer, 12);
    }

    Total = t2_data - Total;
    printf("Total usage: %d B\n", Total);
    printf("Minimum usage: %d B\n", min);
    printf("Maximum usage: %d B\n", max);

    if (fclose(resFile) != 0)
    {
        perror("Error_fclose");
        return (-1);
    }

    if (fclose(calFile) != 0)
    {
        perror("Error_fclose");
        return (-1);
    }

    return 0;
}

char getInformation(char *path)
{
    FILE *file = NULL;

    if ((file = fopen(path, "r")) == NULL)
    {
        perror("Error_fopen");
        return (-1);
    }

    FILE *resFile = fopen("data.txt", "w");

    if (resFile == NULL)
    {
        printf("Error_fopen\n");
        exit(1);
    }

    char buffer[12];
    int i;
    time_t result = time(NULL);
    struct tm *ti;

    ti = localtime(&result);
    printf("Starting time: %s", asctime(ti));

    for (i = 0; i < measurementPoints; i++)
    {
        if ((file = fopen(path, "r")) == NULL)
        {
            perror("Error_fopen");
            return (-1);
        }

        if (fgets(buffer, 11, file) == NULL)
        {
            perror("Error_fgets");
            return (-1);
        }

        fprintf(resFile, "%s", buffer);
        printf(".");
        fflush(stdout);
        bzero(buffer, 12);
        sleep(measurementInterval);
    }

    result = time(NULL);
    ti = localtime(&result);
    printf("\nFinishing time: %s", asctime(ti));

    if (fclose(file) != 0)
    {
        perror("Error_fclose");
        return (-1);
    }

    if (fclose(resFile) != 0)
    {
        perror("Error_fclose");
        return (-1);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char path[128];

    if (argc < 2)
    {
        printf("Error: Please specify which network interface to monitor\n");
        return -1;
    }

    if (findInterface(path, argv[1]) == -1)
    {
        return -1;
    }

    if (argc < 3)
    {
        printf("Error: Please specify \'upload\' or \'download\'\n");
        return -1;
    }

    if (findInterfaceInfo(path, argv[2]) == -1)
    {
        return -1;
    }

    if (argc < 4)
    {
        session(path);
        return 0;
    }

    if (strlen(argv[3]) > 2)
    {
        printf("Choose timeperiod less then 24 hours!\n");
        return -1;
    }

    int measurement_period = 0;

    if (strlen(argv[3]) == 1)
    {
        measurement_period = *argv[3] - '0';
    }
    else
    {
        measurement_period = atoi(argv[3]);
    }

    measurementPoints = 20;

    printf("Monitoring Interface \'%s\' for \'%s' Performance\n", argv[1], argv[2]);
    printf("Sampling every %d seconds for %s hours.\n", measurementInterval, argv[3]);

    if (getInformation(path))
    {
        return -1;
    }

    if (process_information())
    {
        return -1;
    }

    return 0;
}
