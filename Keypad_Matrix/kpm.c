#include<lpc22xx.h>
#include"macro_defines.h"
#include"kpm_defines.h"
#include"types.h"
#include"lcd_defines.h"
#include"kpm.h"
#include"lcd.h"
#include"delay.h"
U8 kpmlut[4][4]={
                  {'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}
                };
void Init_Kpm(void)
{
        WRITENIBBLE(IODIR1,ROWs_4,15);
}
U32 ColScan(void)
{
return (READNIBBLE(IOPIN1,COLs_4)<15)? 0:1;
}
U32 RowCheck(void)
{
U32 r;
for(r=0;r<=3;r++)
{
WRITENIBBLE(IOPIN1,ROWs_4,~(1<<r));
if(ColScan()==0)
break;
}
WRITENIBBLE(IOPIN1,ROWs_4,0);
return r;
}
U32 ColCheck(void)
{
U32 c;
for(c=0;c<=3;c++)
{
if(READBIT(IOPIN1,COL0+c)==0)
{
return c;
}
}
return c;
}
