:� � (O!� �K�  	6 !/ �( ��!�  �! W�� �~���  #��u �t�#�#y�(�~���  6 #�#�!  ���pbE�  � �������!  �9��;��ݾݞ���8�~�w��~�w��n��f�^#V������ �6� �6� yր >��w�{�0A�~��(;�!B��N��F��	��n��f�F#f����h������- K�~���w��~�� �w���~��($�n��f�N#F!u�����- 	��3�U3�Xy�3�U3�X. �����LIST   BASIC  COPY   DATE   DEL    DIR    ERASE  FORMAT MODE   PAUSE  REM    RENAME REN    TIME   TYPE   VERIFY BASIC  Goto MSX-BASIC
                COPY   Copies file(s) specified
      DATE   Displays and sets date
        DEL    Deletes file(s)
               DIR    Lists the files from disk
     ERASE  The same as DEL
               FORMAT Initializes or erases a disk
  MODE   Sets display screen mode
      PAUSE  Wait for a key to be pressed
  REM    Comment in a batch file
       RENAME Change the name of a file
     REN    The same as RENAME
            TIME   Displays and sets time
        TYPE   Prints the contents of a file
 VERIFY Sets/Resets verify mode        MSX-DOS 1 Help v1.0 03/07/2018
code by mvac7/303bcn
review by FUBU

Usage: HELP [?][LIST|L][<command>]

 ? About the application
 LIST Displays the list of commands
 L    The same as LIST
 <command> Info about the command Returns to MSX-BASIC environment and can optionally start a BASIC program.
Syntax:
 BASIC [<file>]
Example:
 A>BASIC DEMO.BAS Copies one or more files.
Syntax:
 COPY [<file>] [<file>]
Example:
 A>COPY DEMO.BAS HELLOW.BAS
 A>COPY A:*.* B: Displays the date and optionally       modifies it.
Syntax:
                 DATE [<date>]
Parameter:
            <date> it can be 3 different formats,  depends from the country for which    the computer was released.
          DD/MM/YY Brazil, Egypt, France,        Germany & Kuwait
                    MM/DD/YY Argentina, Saudi Arabia,      Soviet countries, USA & Spain
       YY/MM/DD Japan & Korea
               Example:
 A>DATE
 A>DATE 07.21.18     Removes one or more files from disk
Syntax:
 DEL [<file>]
Example:
 A>DEL HELLOW.BAS
 A>DEL B:*.TXT Removes one or more files from disk
Syntax:
 ERASE [<file>]
Example:
 A>ERASE HELLOW.BAS
 A>ERASE B:*.TXT Lists the files from disk
         Syntax:
                            DIR [Drive:][file][/P][/W]
       Parameter:
                         [/P] Pauses after each screen      full of information
               [/W] wide list format, displaying  file names in columns
            Example:
 A>DIR /W
 A>DIR B:*.BAS  Initializes a diskette in MSX-DOS format
Syntax:
 FORMAT
Example:
 A>FORMAT Change the number of columns   and the screen mode.
        Syntax:
 MODE [<columns>]
    Parameter:
                     1 to 32 > SCREEN 1
          33 to 40 > SCREEN 0 40col.
   41 to 80 > SCREEN 0 80col.
  Example:
 A>MODE 40           Pauses a batch command operation
Syntax:
 PAUSE Write a comment in the batch command
Syntax:
 REM [<comment>]
Example:
 REM it's a fine day Change the name of one or more files
Syntax:
 RENAME [<file>] [<file>]
Example:
 A>RENAME B:AYUDA.EXE HELP1.COM
 A>RENAME *.SC? *.PIC Change the name of one or more files
Syntax:
 REN [<file>] [<file>]
Example:
 A>REN PHOTO001.PIC IMAGE01.SC2
 A>REN B:*.BIN *.COM Displays or modifies time
Syntax:
 TIME [<hour>[:<minute>[:<second>]]][A|P]
Example:
 A>TIME 22
 A>TIME 1:16P Prints the contents of a file.
Syntax:
 TYPE [<file>]
Example:
 A>TYPE README.TXT Sets/resets the verify mode.
Default is off.
Syntax:
 VERIFY [ON|OFF]
Example:
 A>VERIFY ON L ���!  �9�N� ������!  �9�!� �*��� �o���  ! 9y�x#��v����!  �9�n�f~o���>�3��3>
�3��3 �!���ͱ��y���>-�3��3������
��_>`�0{�{0���; ! 9~#fo 	F�! �9�~ �_�~� Wx�(3�3�!  �9�~ �(	x��  �x� �(. .3����!  �9B�^ kb))	��x����~��H>ݖ�H�^ !��þ������������������ �*�4�>!���x��K!H��x��K��K!���x�g͝b!���x�X!�
��x�NͻI!���x�?!���x�5!Q��x�+!���x�!!Y��x�!���x�!��x��a!V��x����
 !���x��   !�����x���!& �y�8��   !�����x���!& �y�8��   !N	����x���!# �y�	8��   !�
����x���! �y�8����:��2���!l �*��� ������:��2���!o �*��� �������!  �9�~2��������!  �9�!���~�w �~�w�~�w�!b �*��� �������!� �*��� �������!  �9�~<g�~<o�!� �*��� ��������
��Wz�
 �>
�3��3>�3��3����3��3�����!  �9!��9�!  9MD6 i`#6 i`##6 i`###6 ! 	6 ! 	6 YP�> �3��n�f�͌��3�
�(Wz� (���3��3����������!  �9!��9�!  9MD6 i`#6 i`##6 i`###6 ! 	6 ! 	6 YP��~�3��n�f�͌��3�>ݖ0�6�~� �6>ݖ_�Vj}�(k& 	~���3��3�����������!  �9�n�f�^�V�~2���������������H>02������>/<	8��B�0 :��>02�������!  �9�~�!� �*��� ����