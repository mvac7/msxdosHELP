# MSX-DOS 1 HELP

Author: mvac7/303bcn

Architecture: MSX

Format: .COM (MSX-DOS)

Programming language: C (SDCC)


## History of versions:
- v1.0 03/07/2018<



## 1. Description

Application to query the list and operation of MSX-DOS v1 commands.

This project is an Open Source and freeware. You can distribute this software 
wherever you want, as long as it remains freeware.

Texts based on the MSX2 Technical Handbook and MSX Resource Center Wiki.
https://www.konamiman.com/msx/msx2th/th-3.txt
https://www.msx.org/wiki/MSX-DOS_Commands



## 2. Acknowledgments
  
Thanks for Info & help, to:

* Fubu > http://www.gamerachan.org/fubu/
* Avelino Herrera > http://msx.atlantes.org/index_es.html
* Nerlaska > http://albertodehoyonebot.blogspot.com.es
* Konamiman > https://www.konamiman.com
* MSX Assembly Page > http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > http://nocash.emubase.de/portar.htm
* MSX Resource Center > http://www.msx.org/
* Karoshi MSX Community > http://karoshi.auic.es/
* BlueMSX >> http://www.bluemsx.com/
* OpenMSX >> http://openmsx.sourceforge.net/
* Meisei  >> ?



## 3. Requirements

* Small Device C Compiler (SDCC) v3.6 http://sdcc.sourceforge.net/
* Hex2bin v2.2 http://hex2bin.sourceforge.net/ 



## 4. How to use

Syntax:

HELP [?][LIST|L][<command>]
  
* __?__         About the application
* __LIST__      Displays the list of commands with a short description
* __L__         The same as LIST 
* __<command>__ It shows information about the use of a MSXDOS command

Examples:

```  
 A>HELP LIST
```

```
 A>HELP DIR
```
