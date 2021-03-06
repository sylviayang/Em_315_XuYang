#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
  

//====================================================

int main (void) 
{

	//----------变量定义-------------
		XGpio led,push; //2个GPIO  led灯 和 button(push)
		int i,psb_check;//psb_check为push的返回值

	    xil_printf("-- Start of the Program --\r\n");
	    xil_printf("result");
	    //GPIO口的初始化 及 输入输出设置
		XGpio_Initialize(&led,XPAR_SW_4BIT_DEVICE_ID);
		XGpio_SetDataDirection(&led,1,0x00000000);//led  0是输出

		XGpio_Initialize(&push, XPAR_BTNS_4BIT_DEVICE_ID);
		XGpio_SetDataDirection(&push, 1, 0xffffffff);//button 1是输入


		//try 1  按1亮
		while (1)
		{
	        //按下button,得到按下哪个按钮
			psb_check = XGpio_DiscreteRead(&push,1);
			xil_printf("psb_check %x\r\n",psb_check);

			if(psb_check==1)
			{
				//写入led
				XGpio_DiscreteWrite(&led,1,0xffffffff);
			}
			else
			{
				XGpio_DiscreteWrite(&led,1,0x00000000);
			}

		    for (i=0; i<9999999; i++);
		}

}
 
