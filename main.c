#include <hidef.h>      /* common defines and macros */
#include <mc9s12dt256b.h>     /* derivative information */
#include "lcd.h"
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"

void putInt(int n){
if (n<0){
   LCDPutChar('-');
   n*=-1;
}
LCDPutChar('0'+n/10);
LCDPutChar('0'+n%10);
return;
}

static int count;
void main(void) {
  /* put your own code here */
  long int j;
  PIEP=0x01;
  PIEJ=0x80;
  DDRP=0x00;
  DDRJ=0x00;
  PPSP=0xFF;
  PPSJ=0x80;
  LCDInit();
  LCDClearDisplay();
  EnableInterrupts;

  for(;;) {
  for(j=0;j<30000;j++) 
   {
   }
  LCDClearDisplay();
  putInt(count);
  
  } /* wait forever */
  /* please make sure that you never leave this function */
}
void interrupt 56 ISR_A()
{
   if (PTJ_PTJ7==1) {
      if (PTP_PTP0==1) {
      count--;  
      }
      else {
      count++;  
      }
   }
   else if (PTJ_PTJ7==0){
      if (PTP_PTP0==1) {
      count++; 
      }
      else {
      count--;  
      }
   }
   
   if (PPSP==0xFF)
      PPSP=0x00;
   else
      PPSP=0xFF;
   
   PIFP=0xFF;
   
}
void interrupt 24 ISR_B()
{
   if (PTJ_PTJ7==1) {
      if (PTP_PTP0==1) {
      count++;  
      }
      else {
      count--;  
      }
   }
   else if (PTJ_PTJ7==0){
      if (PTP_PTP0==1) {
      count--; 
      }
      else {
      count++;  
      }
   }

   if (PPSJ==0x80)
      PPSJ=0x00;
   else
      PPSJ=0x80;

   PIFJ=0xFF;
}
