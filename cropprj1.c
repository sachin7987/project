/****************project of crop estimation******************/

/****************decleration of header file******************/

#include<stdio.h> /* scanf(), printf(),fflush(),gets(),
                  puts(),fprintf(),fscanf()***/
#include<stdlib.h>/** system(cls/pause)**/
#include<conio.h>/***  getch() ***/
#include<string.h>/** strcmp(),strlwr()***/
#include<process.h>/*** exit(0) ***/

/****************decleration of structure******************/

struct crop
{
	int id;
	char name[20],type[10],season[40],month[20],vrty[100],prod[100];
	char abtcrop[100],origon[40],spclty[100];
	
}c;

/****************prototyping of function******************/
void addnew();
void search();
void edit();
void dlt();
void showall();

/****************defination of main() function******************/
int main ()
{
	int ich;
	while (1)
	{   
	    system("cls");
	    printf("\n 1.Addnew");
	    printf("\n 2.search");
	    printf("\n 3.edit");
	    printf("\n 4.delete");
	    printf("\n 5.showall");
	    printf("\n 6.exit");
		printf("\n enter your choise");
		scanf("%d",&ich) ; 
		system("cls");  
		switch (ich)
		{
		  case 1:	
		    addnew();	
		  break;
		  case 2:	
		    search();	
		  break;
		  case 3:	
		    edit();
		    printf("\n your data is edited");
		  break;
		  case 4:	
		    dlt();
		    printf("\n your data is deleted");
		  break;
		  case 5:	
		    showall();	
		  break;
		  case 6:	
		    exit(0);	
		  break;
		  default:
		  	printf("wrong choice\n");
		}
		getch();
	}
}

/****************defination of addnew() function******************/
void addnew()
{
	FILE *fptr=fopen("crop.inf","ab");
	//"ab" if file already preasent set curser at end else open new file
    // writing crop data in file (crop.inf)----RAM
   	printf("\nenter crop detail\n");
	printf("enter id=>");
	scanf("%d",&c.id);
	printf("enter name=>");
	fflush(stdin);
	gets(c.name);
	printf("enter season=>");
	gets(c.season);
    printf("enter type=>");
	gets(c.type);
	printf("enter month=>");
	gets(c.month);
	printf("enter veraity=>");
	gets(c.vrty);
	printf("enter production=>");
	gets(c.prod);
	printf(" enter about crop=>");
	gets(c.abtcrop);
    printf("enter origon=>");
	gets(c.origon);
	printf("enter specielity=>");
	gets(c.spclty);
	
	fwrite((char*)&c,1,sizeof(c),fptr);
	fclose(fptr);//save
}

/****************defination of search() function******************/
void search()
{ 
  //open file(crop.inf) for reading by mode"rb"
  FILE *fptr=fopen("crop.inf","rb");
  int ich,sid,f=0;
  char sname[20];
  printf("\n 1.search by id");
  printf("\n 2.search by name");
  printf("\nenter your choice");
  scanf("%d",&ich);
  system("cls");
  switch(ich)
  {
  	case 1:
  		printf("\nenter id");
  		scanf("%d",&sid);
  		while(fread((char*)&c,1,sizeof(c),fptr))
  		{
  			if(sid==c.id)
			  {
			  	system("cls");
			  	printf("\n id=>%d",c.id);
	            printf("\n name=>%s",c.name);
	            printf("\n type=>%s",c.type);
	            printf("\n season=>%s",c.season);
	            printf("\n veraity=>%s",c.vrty);
	            printf("\n origon=>%s",c.origon);
	            printf("\n specielity=>%s",c.spclty);
	            printf("\n about crop=>%s",c.abtcrop);
	            printf("\n months=>%s",c.month);
	            printf("\n production=>%s",c.prod);
	            f=1;
			  }
		  }
  	break ;
	case 2:
	    printf("\nenter name");
  		fflush(stdin);
  		gets(sname);
  		while(fread((char*)&c,1,sizeof(c),fptr))
  		{
  			if(!strcmp(strlwr(sname),strlwr(c.name)))
  			{
  				system("cls");
  				printf("\n id=>%d",c.id);
	            printf("\n name=>%s",c.name);
	            printf("\n type=>%s",c.type);
	            printf("\n months=>%s",c.month);
	            printf("\n season=>%s",c.season);
	            printf("\n veraity=>%s",c.vrty);
	            printf("\n origon=>%s",c.origon);
	            printf("\n specielity=>%s",c.spclty);
	            printf("\n about crop=>%s",c.abtcrop);
	            printf("\n production=>%s",c.prod);
	            f=1;	
			}
		}
  	break ;
	default :
	    printf("wrong choise");	 	
  }
if(f==0)
   printf("record not found");
fclose(fptr); //save

}

/****************defination of edit() function******************/
void edit()
{
	int f=0;
	char sname[20];
	FILE *fptr1=fopen("crop.inf","rb");//open file(crop.inf) for reading
    FILE *fptr2=fopen("temp.inf","ab");//open file(crop.inf) for writing
    printf("/n enter name=>");
	fflush(stdin);
	gets(sname); 
    while(fread((char*)&c,1,sizeof(c),fptr1))
    {
    	if(!strcmp(strlwr(sname),strlwr(c.name)))
    	{
    		system("cls");
  				printf("\n id=>%d",c.id);
	            printf("\n name=>%s",c.name);
	            printf("\n type=>%s",c.type);
	            printf("\n season=>%s",c.season);
	            printf("\n veraity=>%s",c.vrty);
	            printf("\n origon=>%s",c.origon);
	            printf("\n specielity=>%s",c.spclty);
	            printf("\n about crop=>%s",c.abtcrop);
	            printf("\n months=>%s",c.month);
	            printf("\n production=>%s",c.prod);
	            f=1;	
			//new input
			   	printf("\nenter new detail of crop \n");
	            printf("enter id=>");
	            scanf("%d",&c.id);
            	printf("\nenter name=>");
            	fflush(stdin);
            	gets(c.name);
            	printf("\n enter season=>");
            	gets(c.season);
                printf("\n enter type=>");
            	gets(c.type);
               	printf("\n enter month=>");
             	gets(c.month);
            	printf("\n enter veraity=>");
            	gets(c.vrty);
            	printf("\n enter production=>");
            	gets(c.prod);
             	printf("\n enter about crop=>");
            	gets(c.abtcrop);
                printf("\n enter origon=>");
            	gets(c.origon);
              	printf("\n enter specielity=>");
               	gets(c.spclty);
	
            	fwrite((char*)&c,1,sizeof(c),fptr2);			
		}
		else 
		  	fwrite((char*)&c,1,sizeof(c),fptr2);
	}
	if(f==0)
	printf("record not found");
fclose(fptr1); //save
fclose(fptr2); //save
remove("crop.inf");
rename("temp.inf","crop.inf"); 	

}

/****************defination of dlt() function******************/
void dlt()
{
	int f=0;
	char sname[20];
	FILE *fptr1=fopen("crop.inf","rb");//open file(crop.inf) for reading
    FILE *fptr2=fopen("temp.inf","ab");//open file(crop.inf) for writing
    printf("/n enter name=>");
	fflush(stdin);
	gets(sname); 
    while(fread((char*)&c,1,sizeof(c),fptr1))
    {
    	if(strcmp(strlwr(sname),strlwr(c.name)))
    	{
        fwrite((char*)&c,1,sizeof(c),fptr2);
		}
		else
		{
		f=1;
		}
    }
if(f==0)
	printf("record not found");
fclose(fptr1); //save
fclose(fptr2); //save
remove("crop.inf");
rename("temp.inf","crop.inf");  
}

/****************defination of showall() function******************/
void showall()
{
	//open file(crop.inf) for reading by mode"rb"
  FILE *fptr=fopen("crop.inf","rb");
  
	while(fread((char*)&c,1,sizeof(c),fptr))
  		{
  				
  				printf("\n id=>%d",c.id);
	            printf("\n name=>%s",c.name);
	            printf("\n type=>%s",c.type);
	            printf("\n season=>%s",c.season);
	            printf("\n veraity=>%s",c.vrty);
	            printf("\n origon=>%s",c.origon);
	            printf("\n specielity=>%s",c.spclty);
	            printf("\n about crop=>%s",c.abtcrop);
	            printf("\n months=>%s",c.month);
	            printf("\n production=>%s\n",c.prod);
		}
  fclose(fptr);	
}


