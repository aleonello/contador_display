/*------------------------------------------------------------------
   conta.c
   contador com 03 displays de led 7 segmentos e unidades de milhar
   Autor: Adilson Roberto Leonello
--------------------------------------------------------------------*/
#include<16F628.h>
#use delay(clock=4000000)
#fuses INTRC_IO,NOWDT,PUT,NOPROTECT,NOBROWNOUT,NOMCLR,NOLVP,NOCPD
#include<dis_led7.h>
#include<string.h>

#define DISP_REFR    5 // tempo de refresh (ms)

#define DISP_1_ON    output_high(PIN_B1)
#define DISP_1_OFF   output_low(PIN_B1)
#define DISP_2_ON    output_high(PIN_B3)
#define DISP_2_OFF   output_low(PIN_B3)
#define DISP_3_ON    output_high(PIN_B2)
#define DISP_3_OFF   output_low(PIN_B2)
#define MILHAR_ON    output_high(PIN_A2)
#define MILHAR_OFF   output_low(PIN_A2)
#define RELE_ON      output_high(PIN_B4)
#define RELE_OFF     output_low(PIN_B4)

#define ENTR1   !input(PIN_B0)
#define ENTR2   !input(PIN_A5)

void Disp_4(int16 iNumb)
{
	int iDisp1=0,iDisp2=0,iDisp3=0,iDisp4=0;
   char cNumb[5];
   memset(cNumb,0x00,sizeof(cNumb));
   sprintf(cNumb,"%ld",iNumb);

   if(strlen(cNumb)==1){
      iDisp1=cNumb[0]-48;
   }
   if(strlen(cNumb)==2){
      iDisp2=cNumb[0]-48;
      iDisp1=cNumb[1]-48;
   }
   if(strlen(cNumb)==3){
      iDisp3=cNumb[0]-48;
      iDisp2=cNumb[1]-48;
      iDisp1=cNumb[2]-48;
   }
   if(strlen(cNumb)==4){
      iDisp4=cNumb[0]-48;
      iDisp3=cNumb[1]-48;
      iDisp2=cNumb[2]-48;
      iDisp1=cNumb[3]-48;
   }

   DISP_1_ON; disp_led7(iDisp1);
   delay_ms(DISP_REFR); DISP_1_OFF;

   if(iDisp4 || iDisp2 || (!iDisp2 && iDisp3)){
      DISP_2_ON; disp_led7(iDisp2);
   }
   delay_ms(DISP_REFR); DISP_2_OFF;

   if(iDisp4 || iDisp3){
      DISP_3_ON; disp_led7(iDisp3);
   }
   delay_ms(DISP_REFR); DISP_3_OFF;

   if(iDisp4) MILHAR_ON; else MILHAR_OFF;
}

void main()
{
   int iCiclo=0;
   int16 iContador=0;
   int1 bEntr=0,bRele=0;
   delay_ms(1000); // início (correção para compilação)
   while(TRUE)
	{
      if(ENTR1 && !ENTR2 && !bEntr) bEntr=1;
      if(!ENTR1 && ENTR2 && bEntr){
         bEntr=0;
         iContador++;
         if(iContador==1500) bRele=!bRele;
         if(iContador==1501) iContador=0;
         if(bRele) RELE_ON; else RELE_OFF;
      }
      Disp_4(iContador);
   }
}

/*
   if(iDisp1<9) iDisp1++;
   else {
      iDisp1=0;
      if(iDisp2<9) iDisp2++;
      else {
         iDisp2=0;
         if(iDisp3<9) iDisp3++; 
         else {
            iDisp3=0;
            iDisp4=1;
         }
      }
   }
*/
