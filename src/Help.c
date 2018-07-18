/* =============================================================================
   MSX-DOS1 HELP
   Version: 1.0
   Date: 03/07/2018
   Author: mvac7/303bcn
   Architecture: MSX
   Format: .COM (MSX-DOS1)
   Programming language: C (SDCC)
   WEB: 
   mail: mvac7303b@gmail.com

   Description:
     
   
   History of versions:
   - v1 30/07/2018<

============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxBIOS.h"
#include "../include/msxsystemvars.h"
#include "../include/msxDOS.h"

#include "../include/textmode.h"




#define  HALT __asm halt __endasm   //wait for the next interrupt


// Definitions of Labels -------------------------------------------------------
#define  _SYSTEM 0x0005




//  definition of functions  ---------------------------------------------------
void SYSTEM(char code);

void WAIT(uint cicles);
char INKEY();
char PEEK(uint address);

boolean strcmp(char* string1, char* string2);

void printLine();

void upperCase(char* string);

void showHelp();
void showCommand(char comcode);

void showLIST();
void showDATE();
void showDIR();
void showMODE();




// constants  ------------------------------------------------------------------


//const char text01[] = "MSX-DOS 1 Help v1.0";

const char COMMANDS[16][7] ={"LIST","BASIC","COPY","DATE","DEL","DIR","ERASE","FORMAT","MODE","PAUSE","REM","RENAME","REN","TIME","TYPE","VERIFY"};

const char STRINGS_List[15][38] ={ 
"BASIC  Goto MSX-BASIC\n",
"COPY   Copies file(s) specified\n",
"DATE   Displays and sets date\n",
"DEL    Deletes file(s)\n", 
"DIR    Lists the files from disk\n",
"ERASE  The same as DEL\n",
"FORMAT Initializes or erases a disk\n",
"MODE   Sets display screen mode\n",
"PAUSE  Wait for a key to be pressed\n",
"REM    Comment in a batch file\n",
"RENAME Change the name of a file\n",
"REN    The same as RENAME\n",
"TIME   Displays and sets time\n",
"TYPE   Prints the contents of a file\n",
"VERIFY Sets/Resets verify mode"
};

//? about this app
const char STRINGS_help[]="MSX-DOS 1 Help v1.0 03/07/2018\ncode by mvac7/303bcn\nreview by FUBU\n\nUsage: HELP [?][LIST|L][<command>]\n\n ? About the application\n LIST Displays the list of commands\n L    The same as LIST\n <command> Info about the command";

const char STRINGS_BASIC[] = "Returns to MSX-BASIC environment and can optionally start a BASIC program.\nSyntax:\n BASIC [<file>]\nExample:\n A>BASIC DEMO.BAS";

const char STRINGS_COPY[] = "Copies one or more files.\nSyntax:\n COPY [<file>] [<file>]\nExample:\n A>COPY DEMO.BAS HELLOW.BAS\n A>COPY A:*.* B:";

const char STRINGS_DATE[12][38] ={ 
"Displays the date and optionally",
" modifies it.\nSyntax:\n",
" DATE [<date>]\nParameter:\n",
"<date> it can be 3 different formats,",
" depends from the country for which",
" the computer was released.\n",
"DD/MM/YY Brazil, Egypt, France,",
" Germany & Kuwait\n",
"MM/DD/YY Argentina, Saudi Arabia,",
" Soviet countries, USA & Spain\n",
"YY/MM/DD Japan & Korea\n",
"Example:\n A>DATE\n A>DATE 07.21.18"
};

const char STRINGS_DEL[] = "Removes one or more files from disk\nSyntax:\n DEL [<file>]\nExample:\n A>DEL HELLOW.BAS\n A>DEL B:*.TXT";

const char STRINGS_ERASE[] = "Removes one or more files from disk\nSyntax:\n ERASE [<file>]\nExample:\n A>ERASE HELLOW.BAS\n A>ERASE B:*.TXT";

const char STRINGS_DIR[9][35] ={ 
"Lists the files from disk\n",
"Syntax:\n",
" DIR [Drive:][file][/P][/W]\n",
"Parameter:\n",
" [/P] Pauses after each screen",
" full of information\n",
" [/W] wide list format, displaying",
" file names in columns\n",
"Example:\n A>DIR /W\n A>DIR B:*.BAS"
};

const char STRINGS_FORMAT[] = "Initializes a diskette in MSX-DOS format\nSyntax:\n FORMAT\nExample:\n A>FORMAT";

const char STRINGS_MODE[8][30] ={ 
"Change the number of columns",
" and the screen mode.\n", 
"Syntax:\n MODE [<columns>]\n",
"Parameter:\n",
"  1 to 32 > SCREEN 1\n",
" 33 to 40 > SCREEN 0 40col.\n",
" 41 to 80 > SCREEN 0 80col.\n",
"Example:\n A>MODE 40"
};

const char STRINGS_PAUSE[] = "Pauses a batch command operation\nSyntax:\n PAUSE";

const char STRINGS_REM[] = "Write a comment in the batch command\nSyntax:\n REM [<comment>]\nExample:\n REM it's a fine day";

const char STRINGS_RENAME[] = "Change the name of one or more files\nSyntax:\n RENAME [<file>] [<file>]\nExample:\n A>RENAME B:AYUDA.EXE HELP1.COM\n A>RENAME *.SC? *.PIC";

const char STRINGS_REN[] = "Change the name of one or more files\nSyntax:\n REN [<file>] [<file>]\nExample:\n A>REN PHOTO001.PIC IMAGE01.SC2\n A>REN B:*.BIN *.COM";

const char STRINGS_TIME[] = "Displays or modifies time\nSyntax:\n TIME [<hour>[:<minute>[:<second>]]][A|P]\nExample:\n A>TIME 22\n A>TIME 1:16P";

const char STRINGS_TYPE[] ="Prints the contents of a file.\nSyntax:\n TYPE [<file>]\nExample:\n A>TYPE README.TXT";

const char STRINGS_VERIFY[] ="Sets/resets the verify mode.\nDefault is off.\nSyntax:\n VERIFY [ON|OFF]\nExample:\n A>VERIFY ON";



// Functions -------------------------------------------------------------------


//
char main(char** argv, int argc) 
{
  char i=0;
  char comcode=128;
  
  if (argc>0)
  {
/*for(i=0;i<argc;i++){
      PrintFNumber(i,32,4);
      PRINT(">");
      PRINT(argv[i]);
      PRINT("<\n\r");
    }*/
    upperCase(argv[0]);
    while(i<16 && comcode==128){      
      if(strcmp(argv[0],COMMANDS[i])==true) comcode=i;
      i++;   
    } 
    if(comcode==128){
      if(strcmp(argv[0],"L")==true) showCommand(0);
      else showHelp();  // ? or nothing
    }else showCommand(comcode);
  
  }else{
    // print a list of commands
    showHelp();
  }
  
  
  return _TERM0; //return to DOS  
}



void SYSTEM(char code)
{
code;
__asm
	push IX
	ld IX,#0
	add IX,SP

	ld C,4(ix)
	call _SYSTEM
  
	pop IX
__endasm; 
}



/* =============================================================================
One character input (waiting)
============================================================================= */
char INKEY(){
__asm
  push IX
  ld   IX,#0
  add  IX,SP
    
  ;call CHGET
  ld   IX,#CHGET
  ld   IY,(#EXPTBL-1)
  call CALSLT ;acces to MSX BIOS
  ei
  
  ld   L,A
  pop  IX
__endasm;
}



// Generates a pause in the execution of n interruptions.
// PAL: 50=1second. ; NTSC: 60=1second. 
void WAIT(uint cicles)
{
  uint i;
  for(i=0;i<cicles;i++) HALT;
  return;
}


char PEEK(uint address)
{
address;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
    
  ld   L,4(ix)
  ld   H,5(ix)
  ld   A,(hl)

  ld   L,A

  pop  IX
__endasm;
}



void printLine()
{
  char i;
  //char _width = PEEK(LINLEN);
  bchput('\r');
  bchput('\n');
  for(i=0;i<PEEK(LINLEN);i++) bchput('-'); //PRINT("-");
}



void upperCase(char* string)
{
  char character;
  
  while(*(string))
  {
    character=*(string);
    if(character>96 && character<123) *(string) = character-32;
    string++;
  }
   
}



boolean strcmp(char* string1, char* string2)
{
  char index = 0;

  while (string1[index]!='\0' && string2[index]!='\0' && string1[index] == string2[index]) index++;

  if (string1[index]!='\0' || string2[index]!='\0') return false;

  return true;
}



void showCommand(char comcode)
{

  PRINT(COMMANDS[comcode]);
  //PRINT("\n");
  printLine();  

  switch(comcode) 
  {
    case 1:
      PRINT(STRINGS_BASIC);
      break;
    case 2:
      PRINT(STRINGS_COPY);
      break;
    case 3:
      showDATE();
      break;
    case 4:
      PRINT(STRINGS_DEL);
      break;
    case 5:
      showDIR();
      break;
    case 6:
      PRINT(STRINGS_ERASE);
      break;
    case 7:
      PRINT(STRINGS_FORMAT);
      break;
    case 8:
      showMODE();
      break;
    case 9:
      PRINT(STRINGS_PAUSE);
      break;
    case 10:
      PRINT(STRINGS_REM);
      break;
    case 11:
      PRINT(STRINGS_RENAME);
      break;
    case 12:
      PRINT(STRINGS_REN);
      break;
    case 13:
      PRINT(STRINGS_TIME);
      break;
    case 14:
      PRINT(STRINGS_TYPE);
      break;
    case 15:
      PRINT(STRINGS_VERIFY);
      break;
    default:
      showLIST();    
  }
  PRINT("\n");

}


void showHelp()
{
  PRINT(STRINGS_help);
}


void showLIST()
{
  char i;
  for(i=0;i<15;i++){
    PRINT(STRINGS_List[i]);
  } 
}


void showDATE()
{
  char i;
  for(i=0;i<12;i++) PRINT(STRINGS_DATE[i]);
}


void showDIR()
{
  char i;
  for(i=0;i<9;i++) PRINT(STRINGS_DIR[i]);
}


void showMODE()
{
  char i;
  for(i=0;i<8;i++) PRINT(STRINGS_MODE[i]);
}

