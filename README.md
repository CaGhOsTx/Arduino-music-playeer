# Arduino-music-playeer
A simple arduino based "music" player  
The player works as follows:  
  1. The user must enter the "score" string which is a sequence of characters representing a note  
  must be written like this: (note name)(note degree)(octave) so -> C/4 ; C#4 ; Cb4 etc.  
  possible note names : A, B, C, D, E, F, G  
  possible note degrees : b, /, #  
  possible octaves(piano): 0 through 8  
  2. The user must enter the "noteLength" string which is a sequence of characters representing tempo notation  
   must be written like this: (first digit)(second digit)(modifier) so -> 04/ ; 08. ; 16t etc  
   possible tempo notes : 01, 02, 04, 08, 16, 32  
   possible modifiers : T -triple duration | D - double duration | . - 1.5 duration | / - no modifier | t - triplet duration (0.33)  
   3. The user must input tempo  
   tempo is in bpm format so a quarter note lasts 1 second if the tempo is 60 beats per minute.  
   
I have already converted some sheet music to this format so you can try this :  

MERRY CHRISTMAS  

score : C/4 F/4 F/4 G/4 F/4 E/4 D/4 Bb3 D/4 G/4 G/4 A/4 G/4 F/4 E/4 C/4 C/4 A/4 A/4 Bb4 A/4 G/4 F/4 D/4 C/4 C/4 D/4 Bb4 E/4 F/4 C/4 F/4 F/4 F/4 E/4 E/4 F/4 E/4 D/4 C/4 C/4 A/4 G/4 F/4 C/5 C/4 C/4 C/4 D/4 G/4 E/4 F/4  
noteLength : 04/ 04/ 08/ 08/ 08/ 08/ 04/ 04/ 04/ 04/ 08/ 08/ 08/ 08/ 04/ 04/ 04/ 04/ 08/ 08/ 08/ 08/ 04/ 04/ 08/ 08/ 04/ 04/ 04/ 02/ 04/ 04/ 04/ 04/ 02/ 04/ 04/ 04/ 04/ 02/ 04/ 04/ 04/ 04/ 04/ 04/ 08/ 08/ 04/ 04/ 04/ 02/  
original tempo : 140  
