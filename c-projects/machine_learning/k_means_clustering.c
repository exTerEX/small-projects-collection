#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <string.h>

typedef struct observation
{
    double x, y;
    int group;
} observation;

typedef struct cluster
{
    double x, y;
    size_t c;
} cluster;

int calculate_nearest(observation *o, cluster clusters[], int k)
{
    double min_d = DBL_MAX;
    double dist = 0;
    int index = -1;

    for (int i = 0; i < k; i++)
    {
        dist = (clusters[i].x - o->x) * (clusters[i].x - o->x) + (clusters[i].y - o->y) * (clusters[i].y - o->y);
        if (dist < min_d)
        {
            min_d = dist;
            index = i;
        }
    }
    return index;
}

void calculate_centroid(observation observations[], size_t size, cluster *centroid)
{
    centroid->x = 0;
    centroid->y = 0;
    centroid->c = size;

    for (size_t i = 0; i < size; i++)
    {
        centroid->x += observations[i].x;
        centroid->y += observations[i].y;
        observations[i].group = 0;
    }
    centroid->x /= centroid->c;
    centroid->y /= centroid->c;
}

cluster *k_means(observation observations[], size_t size, int k)
{
    cluster *clusters = NULL;
    if (k <= 1)
    {
        clusters = (cluster *)malloc(sizeof(cluster));
        memset(clusters, 0, sizeof(cluster));
        calculate_centroid(observations, size, clusters);
    }
    else if (k < size)
    {
        clusters = malloc(sizeof(clusters) * k);
        memset(clusters, 0, k * sizeof(cluster));
        for (size_t j = 0; j < size; j++)
        {
            observations[j].group = rand() % k;
        }
        size_t changed = 0;
        size_t min_accepted_error = size / 10000;
        int t = 0;
        do
        {
            for (int i = 0; i < k; i++)
            {
                clusters[i].x = 0;
                clusters[i].y = 0;
                clusters[i].c = 0;
            }
            for (size_t j = 0; j < size; j++)
            {
                t = observations[j].group;
                clusters[t].x += observations[j].x;
                clusters[t].y += observations[j].y;
                clusters[t].c++;
            }
            for (int i = 0; i < k; i++)
            {
                clusters[i].x /= clusters[i].c;
                clusters[i].y /= clusters[i].c;
            }
            changed = 0;
            for (size_t j = 0; j < size; j++)
            {
                t = calculate_nearest(observations + j, clusters, k);
                if (t != observations[j].group)
                {
                    changed++;
                    observations[j].group = t;
                }
            }
        } while (changed > min_accepted_error);
    }
    return clusters;
}
