#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char Destination[25];
    struct da *link;
    struct node *next;
} dest;

typedef struct da
{
    int date;
    struct na *link;
    struct da *next;
} dat;

typedef struct na
{
    char name[20];
    int Num_Tourists;
    struct na *next;
} nam;

int count_tourists(nam *pointer);
int count_dest(dest *pointer);
int count_dat(dat *pointer);
nam *exceed_premium(nam *pointer, int n, int total);

int main()
{
    dest *head = NULL;
    FILE *ptr = NULL;
    char string[34];
    int total_num;
    ptr = fopen("tour.txt", "r");
    fscanf(ptr, "%d", &total_num);
    while ((fscanf(ptr, "%s", string)) == 1)
    {
        if (strcmp(string, "C1") == 0)
        {
            dest *trp, *ptt;
            trp = (dest *)malloc(sizeof(dest));
            char str[15];
            fscanf(ptr, "%s", str);
            if (strcmp(str, "TS1") == 0)
                strcpy(trp->Destination, "Darjeeling");
            else if (strcmp(str, "TS2") == 0)
                strcpy(trp->Destination, "Leh");
            else
                strcpy(trp->Destination, "Ooty");

            trp->link = NULL;
            trp->next = NULL;

            if (head == NULL)
            {
                head = trp;
            }
            else
            {
                ptt = head;
                while (ptt->next != NULL)
                    ptt = ptt->next;
                ptt->next = trp;
            }
        }
        else if (strcmp(string, "C2") == 0)
        {
            int datee;
            dest *hd;
            dat *ptrs, *pt;
            int i;
            pt = (dat *)malloc(sizeof(dat));
            hd = head;
            for (i = 1; i < count_dest(head); i++)
            {
                hd = hd->next;
            }

            fscanf(ptr, "%d", &datee);

            pt->date = datee;
            pt->next = NULL;
            pt->link = NULL;

            ptrs = hd->link;
            if (ptrs == NULL)
            {
                ptrs = pt;
                hd->link = pt;
            }
            else
            {
                while (ptrs->next != NULL)
                    ptrs = ptrs->next;
                if (ptrs->date == pt->date)
                    ptrs->next = NULL;
                else
                    ptrs->next = pt;
            }
        }
        else if (strcmp(string, "C3") == 0)
        {

            dest *hdd;
            dat *fst;
            nam *p,*dptrr;
            int j, i;
            p = (nam *)malloc(sizeof(nam));
            dptrr = (nam *)malloc(sizeof(nam));
            char initial[15];
            int num;
            hdd = head;

            for (i = 1; i < count_dest(head); i++)
            {
                hdd = hdd->next;
            }

            fst = hdd->link;
            for (j = 1; j < count_dat(hdd->link); j++)
            {
                fst = fst->next;
            }

            fscanf(ptr, "%s", initial);
            fscanf(ptr, "%d", &num);

            strcpy(p->name, initial);
            p->Num_Tourists = num;
            p->next = NULL;

            dptrr = fst->link;

            if (dptrr == NULL)
            {
                if ((num + count_tourists(fst->link)) > total_num)
                    dptrr = NULL;
                else
                {
                    dptrr = p;
                    fst->link = p;
                }
            }
            else
            {
                while (dptrr->next != NULL)
                    dptrr = dptrr->next;
                if ((num + count_tourists(fst->link)) > total_num)
                    dptrr->next = NULL;
                else
                    dptrr->next = p;
            }
        }
        else if (strcmp(string, "C3A") == 0)
        {
            dat *fstt;
            dest *hddd;
            int i, j;
            hddd = head;

            for (j = 1; j < count_dest(head); j++)
            {
                hddd = hddd->next;
            }

            fstt = hddd->link;
            for (i = 1; i < count_dat(hddd->link); i++)
            {
                fstt = fstt->next;
            }

            nam *point;
            point = (nam *)malloc(sizeof(nam));

            char initials[15];
            int nums;
            fscanf(ptr, "%s", initials);
            fscanf(ptr, "%d", &nums);

            nam *ptrrr = fstt->link;
            ptrrr = exceed_premium(ptrrr, nums, total_num);

            strcpy(point->name, initials);
            point->Num_Tourists = nums;
            point->next = NULL;

            if (ptrrr == NULL)
            {
                ptrrr = point;
                fstt->link = point;
            }
            else
            {
                point->next = ptrrr;
                fstt->link = point;
            }
        }
        else if (strcmp(string, "C5") == 0)
        {
            nam *a,*b,*c,*on;
            dest *h;
            dat *fs;
            int j;
            char namee[15];

            h = head;

            for (j = 1; j < count_dest(head); j++)
            {
                h = h->next;
            }

            fs = h->link;
            for (j = 1; j < count_dat(h->link); j++)
            {
                fs = fs->next;
            }

            on = fs->link;

            fscanf(ptr, "%s", namee);
            if (strcmp(on->name, namee) == 0)
            {
                c = on;
                on = c->next;
                free(c);
                fs->link = on;
            }

            else
            {
                a = on;
                b = on->next;
                while (strcmp(b->name, namee) != 0)
                {
                    a = a->next;
                    b = b->next;
                }
                a->next = b->next;
                free(b);
            }
        }
        else if (strcmp(string, "C8") == 0)
        {
            char n[15];
            dest *ntr;
            dat *mtr;
            nam *atr;
            fscanf(ptr, "%s", n);
            if ((strcmp(n, "TS1")) == 0)
            {
                ntr = head;
                while (strcmp(ntr->Destination, "Darjeeling") != 0)
                    ntr = ntr->next;
                printf("TS1 : %s\n", ntr->Destination);
                mtr = ntr->link;
                while (mtr != NULL)
                {
                    atr = mtr->link;
                    if (count_tourists(atr) == 0)
                    {
                        mtr = mtr->next;
                        continue;
                    }

                    printf("May %d :", mtr->date);

                    if ((mtr->date + 7) > 31)
                    {
                        printf("No trip\n");
                        break;
                    }
                    printf("%d tourists: ", count_tourists(atr));
                    while (atr != NULL)
                    {
                        printf("%s ", atr->name);
                        atr = atr->next;
                    }
                    printf("\n");
                    mtr = mtr->next;
                }

                printf("-----------------------------\n");
            }
            else if ((strcmp(n, "TS2")) == 0)
            {
                atr = mtr->link;
                if (count_tourists(atr) == 0)
                {
                    mtr = mtr->next;
                    continue;
                }
                ntr = head;
                while (strcmp(ntr->Destination, "Leh") != 0)
                    ntr = ntr->next;
                printf("TS2 :%s \n", ntr->Destination);
                mtr = ntr->link;
                while (mtr != NULL)
                {
                    printf("May %d :", mtr->date);

                    if ((mtr->date + 7) > 31)
                    {
                        printf("No trip\n");
                        break;
                    }

                    atr = mtr->link;
                    printf("%d tourists: ", count_tourists(atr));
                    while (atr != NULL)
                    {
                        printf("%s ", atr->name);
                        atr = atr->next;
                    }
                    printf("\n");
                    mtr = mtr->next;
                }

                printf("-----------------------------\n");
            }
            else
            {
                ntr = head;
                while (strcmp(ntr->Destination, "Ooty") != 0)
                    ntr = ntr->next;
                printf("TS3 : %s\n", ntr->Destination);
                mtr = ntr->link;
                while (mtr != NULL)
                {
                    atr = mtr->link;
                    if (count_tourists(atr) == 0)
                    {
                        mtr = mtr->next;
                        continue;
                    }
                    printf("May %d :", mtr->date);

                    if ((mtr->date + 7) > 31)
                    {
                        printf("No trip\n");
                        break;
                    }

                    atr = mtr->link;
                    printf("%d tourists: ", count_tourists(atr));
                    while (atr != NULL)
                    {
                        printf("%s ", atr->name);
                        atr = atr->next;
                    }
                    printf("\n");
                    mtr = mtr->next;
                }

                printf("-----------------------------\n");
            }
        }
        else if (strcmp(string, "C9") == 0)
        {
            exit(0);
        }

        else
        {
            printf("Error while reading the Tour.txt File \n");
        }
    }

    return 0;
}
int count_tourists(nam *pointerr)
{
    int summ = 0;
    nam *pts;
    pts = pointerr;
    while (pts != NULL)
    {
        summ = summ + (pts->Num_Tourists);
        pts = pts->next;
    }
    return summ;
}

int count_dest(dest *pointer)
{
    int count = 0;
    dest *current = pointer;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int count_dat(dat *pointer)
{
    int count = 0;
    dat *current = pointer;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

struct na *exceed_premium(struct na *pointer, int n, int total)
{

    while ((count_tourists(pointer) + n) > total)
    {
        struct na *a;
        struct na *b;
        a = pointer;
        b = pointer->next;
        while (b->next != NULL)
        {
            a = a->next;
            b = b->next;
        }
        a->next = NULL;
        free(b);
    }
    return pointer;
}

/*
DATAFILE

12    C1 TS2  C2 14 C3 AA 3 C3 BB 4 C3 CC 4      C8 TS2        C2 14 C3A KK 3
C2 20 C3 DD 2 C3 EE 4        C8 TS2
C5 DD           C1 TS1 C2 12  C3 JJ 4  C3 MM 2      C2 26 C3 NN 3 C3 FD 2
C8 TS1       C8 TS2         C9

*/

/*

OUTPUT

TS2 :Leh
May 14 :11 tourists: AA BB CC
-----------------------------
TS2 :Leh
May 14 :10 tourists: KK AA BB
May 20 :6 tourists: DD EE
-----------------------------
TS1 : Darjeeling
May 12 :6 tourists: JJ MM
May 26 :No trip
-----------------------------
TS2 :Leh
May 14 :10 tourists: KK AA BB
May 20 :4 tourists: EE
-----------------------------

*/