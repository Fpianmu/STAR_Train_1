#include "stm32f10x.h"
#include "valuepack.h"
#include "OLED.h"
#include "Delay.h"

// 首先需要有 发送数据包 和 接收数据包  数据包中有不同类型变量的数组，可以在valuepack.h中定义数据包的结构

TxPack txpack;
RxPack rxpack;

int main(void)
{

	// 初始化串口 设置波特率
	initValuePack(9600);	
	OLED_Init();
	
	while(1)
	{

		// 延时一段时间
		for(int i=0;i<100000;i++)
		{}
		OLED_ShowString(5,5,"TEST");
///////////////////////////////////////////////////////////////////////////////////////////////////////
/// 数据收发部分

			if(readValuePack(&rxpack))
			{
			
				// 在此读取手机传来的数据
				
				// 这里是将接收的数据原样回传
				
				txpack.integers[0] = rxpack.integers[0];
				
			
				OLED_ShowNum(10,5,rxpack.integers[0],3);
				// 也可以把 sendValuePack放在这，这样就只有当接收到手机传来的数据包后才回传数据
				sendValuePack(&txpack);
				
			}
			
			// 在此对数据包赋值并将数据发送到手机
			//sendValuePack(&txpack);
			

/// 数据收发结束
///////////////////////////////////////////////////////////////////////////////////////////////////////
			
	}
}



