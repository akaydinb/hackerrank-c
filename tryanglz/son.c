void sort_by_area(triangle* tr, int n) {
    int *areas, t, swapped;
    double p;
    triangle temp;

    areas = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)  {
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        areas[i] = sqrt(p * (p-tr[i].a) * (p-tr[i].b) * (p-tr[i].c));
    }

    for(int i = 0; i < n; i++)  {
        swapped = 0;
        for(int j = i + 1; j < n; j++)  {
            if(areas[i] >= areas[j])     {
                temp = tr[i]; tr[i] = tr[j]; tr[j] = temp;
                t = areas[i]; areas[i] = areas[j]; areas[j] = t;
                swapped = 1;
            }
        }
        if(swapped == 0)    break;
    }

    //free(areas);
}

