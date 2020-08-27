#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle    {
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
    int swapped;
    double p, t, *areas;
    triangle temp;

    areas = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        // heron's formula
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        areas[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }

    // bubble sort by areas
    for (int i = 0; i < n; i++) {
        swapped = 0;
        for (int j = i + 1; j < n; j++) {
            if (areas[i] > areas[j]) {
                temp = tr[i]; tr[i] = tr[j]; tr[j] = temp;
                t = areas[i]; areas[i] = areas[j]; areas[j] = t;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }

//    for(int i = 0; i < n; i++)
//        printf("%d , %d , %d = %f\n", tr[i].a, tr[i].b, tr[i].c, areas[i]);

    free(areas);
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
