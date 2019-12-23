#include <stdio.h>
#include <math.h>
//declaring function
int delete_values(int arr[],int size);
int lable_encoding(int arr[],int size);
int lenier_regression(int arr[], int size);
int list_indexing(int arr[], int size);
int clustering(int arr[],int size);
int main()
{
    int a,b,i,j,g,h,k,l,f,u;
    printf("enter the value of rows\n");
    scanf(" %d", &a);
    printf("enter the value of columns\n");
    scanf(" %d", &b);
    int inp[a][b];          //for input array
    g=0;
    f=(a*b);
    int xx[f];
    int processing[f];            //converting 2d array into 1d for processing
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            printf("enter the value of array    [%d][%d]\n",i,j);
            scanf (" %d", &inp[i][j]);
            processing[g]=inp[i][j];
            g=g+1;
        }
    }


    // program for deleting multiple values from processing array or (one-hot encoding)

      f = delete_values(processing,f);
      printf("SIZE OF DATA AFTER REMOVING DUBLICATES ARE :    %d\n",f);
    //printing value
        for(j=0;j<f;j++)
        {
            printf("%d", processing[j]);
            printf("\n");
        }
    // lenierly arranging values of array
        lable_encoding(processing,f);
        printf("THE VALUES AFTER REARRANGING ARE\n");
         //printing value
        for(j=0;j<f;j++)
        {
            printf("%d", processing[j]);
            printf("\n");
        }
        u=lenier_regression(processing,f);
        printf("\n");
        printf("THE NEXT ELEMENT OF THIS ARRAY IS    %d ",u);
        //searching specific value or specific crunch from array
        list_indexing(processing,f);
        //k-clustering
        clustering(processing,f);

}

int delete_values(int arr[],int size)
{
    int i,j,k;
     for (i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i]==arr[j])
            {

                for(k=j;k<size;k++)
                {
                    arr[k]=arr[k+1];
                }
                size=size-1;
                j=j-1;
            }

        }
    }
 return(size);
}

int lable_encoding(int arr[],int size)
{
    int i,j;
    int x;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if (arr[i]<arr[j])
            {
                x=arr[j];
                arr[j]=arr[i];
                arr[i]=x;
            }
        }
    }

}

int lenier_regression(int arr[], int size)
{
   int x,y,t,z,u,q,a,b,c,i;
   x= (arr[1]-arr[0]);
   y= (arr[2]-arr[1]);
   //if values are in arithmetic sequence
   if (x==y)
   {
       printf("DO YOU WANT NEXT VALUE IN THE SEQUENCE OR YOU WANT A SPECIFIC VALUE ?\n");
       printf("\n");
       printf("PRESS 1 FOR NEXT VALUE AND 2 FOR SPECIFIC NUMBER OF VALUE\n");
       scanf(" %d", &z );
       if (z==1)
       {
           t=(arr[size-1]+x);
           return t;
       }
       else if (z==2)
       {
           printf("WHICH VALUE IN SEQUENCE YOU WANT TO KNOW\n");
           scanf(" %d", &u);
           t=(arr[0]+ (x*(u-1)));
           return t;
       }
   }
   //if values are in geomatric sequence

  else if (x!=y)
   {
       a=(arr[1]/arr[0]);
       if (arr[0]==a)
       {
           printf("DO YOU WANT NEXT VALUE IN THE SEQUENCE OR YOU WANT A SPECIFIC VALUE ?\n");
           printf("\n");
           printf("PRESS 1 FOR NEXT VALUE AND 2 FOR SPECIFIC NUMBER OF VALUE\n");
           scanf(" %d", &z );
           if (z==1)
         {
           t=(arr[size-1]*(arr[0]));
           return t;
         }
           else if (z==2)
         {

           printf("WHICH VALUE IN SEQUENCE YOU WANT TO KNOW\n");
           scanf(" %d", &u);
           z=(u-1);
           z=pow(arr[0],z);
           t=(arr[0]*z);
           return t;
         }
   }
   else if(arr[0]!=a)
   {
     b=(arr[0]+arr[1]);
     if (arr[2]==b)
    {
           printf("DO YOU WANT NEXT VALUE IN THE SEQUENCE OR YOU WANT A SPECIFIC VALUE ?\n");
           printf("\n");
           printf("PRESS 1 FOR NEXT VALUE AND 2 FOR SPECIFIC NUMBER OF VALUE\n");
           scanf(" %d", &z );
           if (z==1)
         {
            t=(arr[size-1]+(arr[size-2]));
            return t;
         }
     }
      else if (z==2)
         {

           printf("WHICH VALUE IN SEQUENCE YOU WANT TO KNOW\n");
           scanf(" %d", &u);
           q=u-size;
           for (i=0;i<q;i++)
           {
               a=arr[size-2];
               b=arr[size-1];
               t=a+b;
               a=b;
               b=t;
               return t;
           }

         }
   }

}



}
int list_indexing(int arr[], int size)
{
    int a,i,b,j;
    int flag=0;
    int x=0;
    printf("\n\nPLEASE ENTER THE NUMBER YOU WANT TO SEARCH FROM YOUR GIVEN LIST\n");
    scanf(" %d" , &a);
    for (i=0;i<size;i++)
    {
        if (arr[i]==a)
        {
            printf("\n                                    YOUR NUMBER HAS FOUND \n\n");
            printf(" which pattern you want to print??\n\n press the relevant key from your keypad\n\n");
            printf(" 1..ALL NUMBER EXCEPT THIS\n\n 2.. ONLY THIS NUMBER\n\n 3.. FROM THIS NUMBER ONWORDS\n\n 4.. FROM THIS NUMBER BACKWORDS\n\n 5..SKIP 1 ENTERIES BETWEEN NUMBERS\n\n 6.. EVEN NUMBER FROM FARWORD\n\n 7..ODD NUMBERS FOOM FARWORD\n\n 8..EVEN NUMBER FROM BACKWORD\n\n 9..ODD NUMBER FROM BACKWORD\n\n");
            scanf(" %d" , &b);
            if (b==1)
            {
                printf("THE NUMBERS WITHOUT THE ENTERED NUMBER ARE \n ");
                for (j=0;j<size;j++)
                {
                    if (arr[j]==a)
                    {
                        continue;
                    }
                    else

                        printf(" %d\n", arr[j]);
                }

            }
            else if (b==2)
            {
                printf(" THE NUMBER IS\n    %d", arr[i]);

            }
            else if (b==3)
            {
                if ((i+1)<size)
                {
                printf("THE NUMBER ONWORDS ARE\n");
                for (j=i+1;j<size;j++)
                {
                    printf("%d\n", arr[j]);
                }
                }
                else
                    printf("THE ENTERED NUMBER IS LAST IN THE LIST\n ");

            }
            else if (b==4)
            {
                if((i-1)>0)
                {
                printf("THE NUMBER BACKWORDS ARE\n");
                for (j=i-1;j>=0;j--)
                {
                    printf("%d\n", arr[j]);
                }
                }
                else
                    printf("THE ENTERED NUMBER IS FIRST IN THE LIST\n");

            }
            else if (b==5)
            {
                if ((i+1)<size)
                {
                    printf("THE NUMBERS AFTER SKIPPING ONE VALUES ARE \n");
                for (j=i+1;j<size;j=j+2)
                {
                    printf(" %d", arr[j]);
                }
                }
                else
                    printf("THE ENTERED NUMBER IS LAST IN THE LIST\n");

            }
            else if (b==6)
            {
                if ((i+1)<size)
                {
                    printf("THE NUMBERS ONWORDS AFTER SKIPPING ODD VALUES ARE \n");
                   for (j=i+1;j<size;j++)
                   {
                       if ((arr[j]%2)==0)
                       {
                         printf(" %d", arr[j]);
                       }
                   }
                }
                else
                    printf("THE ENTERED NUMBER IS LAST IN THE LIST\n");

            }
            else if (b==7)
            {
                if ((i+1)<size)
                {
                    printf("THE NUMBERS ONWORDS AFTER SKIPPING EVEN VALUES ARE \n");
                   for (j=i+1;j<size;j++)
                   {
                       if ((arr[j]%2)!=0)
                       {
                         printf(" %d", arr[j]);
                       }
                   }
                }
                else
                    printf("THE ENTERED NUMBER IS LAST IN THE LIST\n");

            }
            else if (b==8)
            {
                if ((i+1)>0)
                {
                    printf("THE NUMBERS BACKWORDS AFTER SKIPPING ODD VALUES ARE \n");
                   for (j=i-1;j>=0;j--)
                   {
                       if ((arr[j]%2)==0)
                       {
                         printf(" %d", arr[j]);
                       }
                   }
                }
                else
                    printf("THE ENTERED NUMBER IS FIRST IN THE LIST\n");


            }
            else if (b==9)
            {
                if ((i-1)>0)
                {
                    printf("THE NUMBERS BACKWORDS AFTER SKIPPING ODD VALUES ARE \n");
                   for (j=i-1;j>=0;j--)
                   {
                       if ((arr[j]%2)!=0)
                       {
                         printf(" %d", arr[j]);
                       }
                   }
                }
                else
                    printf("THE ENTERED NUMBER IS FIRST IN THE LIST\n");


            }


        }

    }


}
int clustering(int arr[],int size)
{
 int i,j,b,x,v,w,h;
 int current_means[10];
 int previous_means[10];
 int elements_count[10];
 int aa[10];
 printf(" \n\n");
 printf("how many clusters you want\n");
 scanf(" %d", &b);
 int bb[b];
 x=(size/b);
 x=(x-1);
 for (i=0;i<b;i++)
 {
     bb[i]=aa[x];
     printf("%d",  bb[i]);
     printf("\n");
     x=x+x;
 }
 int zz=0;   //for controlling the elements of random value array (bb)
 int tt=0;   // for controlling the rows of 2d array
 int uu=0;   // for controlling the columns of 2d array
 int xx=0;     // no. of elements used to print 2 d array via loop
 int as=0;     // for element count array
 int arr1[b-1][tt];
 int sum=0;
 label:
for (i=0;i<size;i++)
{
    if (bb[zz]>=aa[i])
    {
      v=bb[zz]-aa[i];
    }
    else if (bb[zz]<aa[i])
    {
      v=aa[i]-bb[zz];
    }
     if (bb[zz+1]>=aa[i])
    {
      w=bb[zz+1]-aa[i];
    }
    else if (bb[zz+1]<aa[i])
    {
      w=aa[i]-bb[zz+1];
    }
    if (v<w)
    {
        arr1[uu][tt]=aa[i];
        printf(" %d %d% d", uu , tt , arr1[uu][tt]);
        sum=sum+aa[i];
        if (i==10-1)
        {
           elements_count[as]=tt;
           current_means[as]=(sum/elements_count[as]);
          // printf(" %d " , current_means[as]);
           for (j=0;j<b;j++)
           {
               if (current_means[j]==previous_means[j])
               {
                   for (h=j+1;h<b;h++)
                   {
                       if (current_means[h]==previous_means[h])
                       {
                           for (i=0;i<=uu;i++)
                           {
                              for (j=0;j<=elements_count[i];j++)
                            {
                                printf(" %d", arr1[i][j]);
                            }
                              printf("\n");
                           }

                       }
                       else if (current_means[h]!=previous_means[h])
                       {
                           for (j=0;j<b;j++)
                           {
                               previous_means[j]=current_means[j];
                               bb[j]=previous_means[j];
                               goto label;
                           }
                       }
                   }
               }
           }
        }
        tt=tt+1;

    }
    else if (w<v)
    {
        if ((zz<b)&&(zz!=b))
        {
            zz=zz+1;
        }
        uu=uu+1;
        elements_count[as]=tt;
        current_means[as]=(sum/elements_count[as]);
        //printf(" %d " , current_means[as]);
        as=as+1;
        sum=0;
        tt=0;
        arr1[uu][tt]=aa[i];
        tt=tt+1;
    }



}

}

