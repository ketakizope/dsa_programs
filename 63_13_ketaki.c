#include<stdio.h>
#include<conio.h>
#define Max 7
int queue [Max];
int f=-1;
int r=1;
void insertion();
void deletion();
void display();
void main();
{
int ch;
do{
printf("1.Insertion\n2.Deletion\n3.Display/n4.End/n");
printf("Enter a choice\n"); 
scanf("%d "&ch);

Switch(ch)
{
Case 1: insertion();
break;
case 2: Deletion ();
break;

case 3: Display ();
break;

Case 4: Printf("Bye-Bye")
 break;

default: ("Enter a valid choice");
break;
while(ch!=4)
getch();
}
void insertion()
if (( f == 0 && r == max-1) || (r==f-1))
{
printf ("Queue is full \n");
}
else
{
if (r==-1) && F == -1)
{
r=0;
f=0;
}
else if (r == max-1 && f!=0)
{
r = 0
}
else {
r++;
}
}
printf("Enter a value \n"); 
Scanf("%d", & que [r]);
}

void deletion()
{
if (f == -1 && r == -1)
{
printf("Empty \n");
}
else if (r==f)
{
r =- 1;
f =- 1;
}
else if (f == max-1)
{
f = 0;
}
else 
{
f++;
}
}
void display()
{
if (f == -1 && r == -1)
{
printf("Queue is empty\n");
}
else 
{
if (f <= r)
{
for (i = f; i <= r; i++)
{
printf("%d", que[i]);
}
else
{
for(i = f; i <= max-1; i++)
{
printf("%d", que[i]);
}
for ( i = 0; i <=r ; i++ )
{
printf("%d", que[i]);
}
}
}
