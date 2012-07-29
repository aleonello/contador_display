/*------------------------------------------------------------------
   display_led7.h
   biblioteca para display de led de 7 segmentos
   Autor: Adilson Roberto Leonello
--------------------------------------------------------------------*/
/* ..::Mapeamento::..

           CIMA(12)
           --------
          |       |
 ESQ_C(6) |       | DIR_C(11)
           MEIO(13)
           --------
 ESQ_B(17)|       | DIR_B(10)
          |       |
           --------
           BAIXO(9)
*/
/* ..::Definições do display::.. */

#define CIMA   PIN_A7
#define MEIO   PIN_B5
#define BAIXO  PIN_A1
#define ESQ_C  PIN_B6
#define ESQ_B  PIN_B7
#define DIR_C  PIN_A0
#define DIR_B  PIN_A6

void disp_led7(int num)
{
   switch(num)
   {
   case 0x00://0
   output_low(MEIO); output_high(ESQ_C); output_high(ESQ_B); output_high(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x01://1
      output_low(ESQ_C); output_low(MEIO); output_low(ESQ_B); output_low(BAIXO); output_low(CIMA); output_high(DIR_B); output_high(DIR_C);
   break;
   case 0x02://2
      output_low(ESQ_C); output_low(DIR_B); output_high(MEIO); output_high(ESQ_B); output_high(BAIXO); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x03://3
      output_low(ESQ_C); output_low(ESQ_B); output_high(MEIO); output_high(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x04://4
      output_low(ESQ_B); output_low(BAIXO); output_low(CIMA); output_high(ESQ_C); output_high(MEIO); output_high(DIR_B); output_high(DIR_C);
   break;
   case 0x05://5
      output_low(ESQ_B); output_low(DIR_C); output_high(ESQ_C); output_high(MEIO); output_high(BAIXO); output_high(DIR_B); output_high(CIMA);
   break;
   case 0x06://6
      output_low(DIR_C); output_high(ESQ_C); output_high(MEIO); output_high(ESQ_B); output_high(BAIXO); output_high(DIR_B); output_high(CIMA);
   break;
   case 0x07://7
      output_low(ESQ_C); output_low(MEIO); output_low(ESQ_B); output_low(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x08://8
      output_high(ESQ_C); output_high(MEIO); output_high(ESQ_B); output_high(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x09://9
      output_low(ESQ_B); output_high(ESQ_C); output_high(MEIO); output_high(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x0A://A
      output_high(ESQ_B); output_high(ESQ_C); output_high(MEIO); output_low(BAIXO); output_high(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x0B://P
      output_high(ESQ_B); output_high(ESQ_C); output_high(MEIO); output_low(BAIXO); output_low(DIR_B); output_high(DIR_C); output_high(CIMA);
   break;
   case 0x0C://C
      output_high(ESQ_B); output_high(ESQ_C); output_low(MEIO); output_high(BAIXO); output_low(DIR_B); output_low(DIR_C); output_high(CIMA);
   break;
   case 0x0E://E
      output_high(ESQ_B); output_high(ESQ_C); output_high(MEIO); output_high(BAIXO); output_low(DIR_B); output_low(DIR_C); output_high(CIMA);
   break;
   case 0x0D://desligado
      output_low(ESQ_B); output_low(ESQ_C); output_low(BAIXO); output_low(DIR_B); output_low(DIR_C); output_low(CIMA); output_low(MEIO);
   break;
   }
}
