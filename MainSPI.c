#include "stm32f4xx.h"
#include <stdio.h>

/* pinmap
	GPIOA.0 - CTS2
	GPIOA.1 - RTS2
	GPIOA.2 - TX2
	GPIOA.3 - RX2
	GPIOA.4 - NSS1
	GPIOA.5 - SCK1
	GPIOA.6 - MISO1
	GPIOA.7 - MOSI1
	GPIOB.6 - /RES (Инверсия резета)
	GPIOB.7 - /CS (Инверсия чип селекта)
	GPIOB.8	- /RD (Инверсия сигнала чтение)
	GPIOB.9 - /WR (Инверсия сигнала запись)
	GPIOB.10 - TX3
	GPIOB.11 - RX3
	GPIOB.13 - CTS3
	GPIOB.14 - RTS3
	GPIOC[0:15] - DATA BUS
	GPIOD.14 - Red LED
	GPIOD.15 - Blue LED
	GPIOE.[0:9] - Address bus
*/

<<<<<<< HEAD
void SPI2_IRQHandler (void)
{
	uint16_t SPI_data = 0, Temp = 0;
	uint8_t SPI_data1 = 0;
	if (SPI_GetITStatus(SPI2, SPI_IT_RXNE) == SET)
	{
		SPI_I2S_ClearFlag(SPI2, SPI_IT_RXNE);
		//while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET) {};
		if (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == SET)
			SPI_data = SPI_I2S_ReceiveData(SPI2);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		if (SPI_data == 0xFFFF)
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
		}		
		else
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
			Temp = SPI_data>>7;
		}
		
		//SPI_data1 = SPI_data>>8;
		USART_SendData(USART2, Temp);
		while (USART_GetFlagStatus(USART2, USART_FLAG_TC != SET)){};
		//USART_SendData(USART2, SPI_data);
		//while (USART_GetFlagStatus(USART2, USART_FLAG_TC != SET)){};
	}
}

=======
>>>>>>> master
// ********************************************************************************
void USART2_IRQHandler(void)
{
	//int i;
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
	{
			
		USART_ClearFlag(USART2, USART_IT_RXNE); //Clear RXNE interrupt flag
		
		GPIO_SetBits(GPIOD, GPIO_Pin_15); 	// Blue LED ON
		//for (i = 0; i< 1000000;i++);
		GPIO_ResetBits(GPIOD, GPIO_Pin_15); // Blue LED OFF
		USART2->DR = (USART2->DR); 		// Transmit new data
	}
}
<<<<<<< HEAD

// ********************************************************************************

// ********************************************************************************
=======

// ********************************************************************************

// ********************************************************************************
>>>>>>> master
void GPIO_Configuration(void)
{
//	int i;
	GPIO_InitTypeDef GPIOA_InitStructure;
	GPIO_InitTypeDef GPIOB_InitStructure;
	
	GPIO_InitTypeDef  ledinit;
	
	// GPIO for USART2
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // GPIOA Clock ON
	
	GPIOA_InitStructure.GPIO_OType = GPIO_OType_PP; 		// Push-pull output port
	GPIOA_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; 		// GPIOA with pull-up
	GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_AF; 		// Alternative mode GPIOA
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_2; 			// TX2 pin
	GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 	// Speed GPIOA 50MHz
	//GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_RESET);
	
	//USART2->DR = 0;
	//GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	//for (i = 0; i< 10000000;i++);
	GPIO_Init(GPIOA, &GPIOA_InitStructure); 				// Init port GPIOA
	//for (i = 0; i< 10000000;i++);
	GPIOA_InitStructure.GPIO_Pin |= GPIO_Pin_3; 			// RX2 pin
	GPIO_Init(GPIOA, &GPIOA_InitStructure); 				// Init port GPIOA
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); // Alternative mode pin 2 (TX2)
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); // Alternative mode pin 3 (RX2)
	
	// GPIO for USART3
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); // GPIOA Clock ON
	// GPIO for LED
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // GPIOD Clock ON
  
	ledinit.GPIO_Mode = GPIO_Mode_OUT;  		// Standard output port
	ledinit.GPIO_OType = GPIO_OType_PP;  		// Push-pull output port
	ledinit.GPIO_PuPd = GPIO_PuPd_NOPULL; 		// GPIOD without pull
	ledinit.GPIO_Speed = GPIO_Speed_2MHz;  	// Speed GPIOD 50MHz
	ledinit.GPIO_Pin = GPIO_Pin_15; 			// LED on pin 15
	GPIO_Init(GPIOD, &ledinit);  				// Init port GPIOD
	
	ledinit.GPIO_Pin |= GPIO_Pin_14; // LED on pin 14
	GPIO_Init(GPIOD, &ledinit);  	// Init port GPIOD
	
	//////////////////////////////////////////
	
	GPIOB_InitStructure.GPIO_OType = GPIO_OType_PP; 		// Push-pull output port
	GPIOB_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 		// GPIOA with pull-up
	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_AF; 		// Alternative mode GPIOA
	//GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_4; 			// NSS1, SCK1, MISO1 pins
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	// Speed GPIOA 2MHz
	
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_12; 
	GPIO_Init(GPIOB, &GPIOB_InitStructure); 
	
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_13; 
	GPIO_Init(GPIOB, &GPIOB_InitStructure); 
	
	GPIOB_InitStructure.GPIO_Pin |= GPIO_Pin_14; 
	GPIO_Init(GPIOB, &GPIOB_InitStructure); 
	
	//GPIOB_InitStructure.GPIO_Pin |= GPIO_Pin_15; 
	//GPIO_Init(GPIOB, &GPIOB_InitStructure); 
	
	//GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_SPI2); // Alternative mode pin 4 (NSS1)
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource12,GPIO_AF_SPI2); // Alternative mode pin 5 (SCK1)
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource13,GPIO_AF_SPI2); // Alternative mode pin 6 (MISO1)
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_SPI2); // Alternative mode pin 6 (MISO1)
}

// ********************************************************************************

void SPI_Configuration(void)
{
	
	SPI_InitTypeDef SPI2_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	
	SPI2_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI2_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI2_InitStructure.SPI_CPOL = SPI_CPOL_High;
	//SPI1_InitStructure.SPI_CRCPolynomial = 7;
	SPI2_InitStructure.SPI_DataSize = SPI_DataSize_16b;
	SPI2_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI2_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI2_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI2_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI2, &SPI2_InitStructure);
	
	SPI_Cmd(SPI2, ENABLE);
	//SPI_NSSInternalSoftwareConfig(SPI2, SPI_NSSInternalSoft_Set);
	NVIC_EnableIRQ(SPI2_IRQn);
	
<<<<<<< HEAD
	SPI_I2S_ITConfig(SPI2, SPI_IT_RXNE , ENABLE);
=======
	SPI_I2S_ITConfig(SPI2, SPI_FLAG_RXNE , ENABLE);
>>>>>>> master
	
}

// ********************************************************************************

void USART_Configuration(void)
{
	
	USART_InitTypeDef USART2_InitStructure;
	
	// Init USART2
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);		// USART2 Clock ON 
	
	USART2_InitStructure.USART_BaudRate = 115200*3; 				// BaudRate for USART2 = 230400
	USART2_InitStructure.USART_WordLength = USART_WordLength_8b;	// WordLength 8 bit
	USART2_InitStructure.USART_StopBits = USART_StopBits_1; 		// With 1 stop bit
	USART2_InitStructure.USART_Parity = USART_Parity_No; 		// Without parity
	USART2_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // Handshake ON
	USART2_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // USART2 work at TX and RX mode
	USART_Init(USART2, &USART2_InitStructure); // Init USART2
	
	NVIC_EnableIRQ(USART2_IRQn); // Interrupt for USART2 ON
 
	USART_Cmd(USART2, ENABLE); 	 // USART2 On
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // Interrupt RXNE for USART2 ON
}

// ********************************************************************************

int main(void)
{
	int i;
	uint16_t SPI_data = 0, SPI_data1 = 0;
	GPIO_Configuration();
	//GPIO_SetBits(GPIOD, GPIO_Pin_14);
	//for (i = 0; i< 10000000;i++);	
	USART_Configuration();
	SPI_Configuration();
	//for (i = 0; i< 10000000;i++);
	//GPIO_ResetBits(GPIOD, GPIO_Pin_14); 
	__enable_irq (); // All interrupt ON
	//for (i = 0; i< 10000000;i++);
	USART2->DR = '!'; // Test data
	//USART_SendData (USART3, 'w'); // Test data
	/*
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	SPI_I2S_SendData(SPI2, 2);
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET) {};
	
	SPI_data = SPI_I2S_ReceiveData(SPI2);
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET) {};
	
	if (SPI_data == 2)
		GPIO_SetBits(GPIOD, GPIO_Pin_15); 
	else
		GPIO_SetBits(GPIOD, GPIO_Pin_14);
		
	GPIO_SetBits(GPIOB, GPIO_Pin_12);

	USART_SendData(USART2, SPI_data);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE == SET)){};
	USART_SendData(USART2, SPI_data);		*/
<<<<<<< HEAD
	while (1)
	{
		for (i = 0; i< 10000000;i++);
		
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		
		SPI_I2S_SendData(SPI2, 2);
		
=======
	for (i = 0; i< 1000000;i++);
	while (1)
	{
		for (i = 0; i< 1000000;i++);
		//while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET) {};
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		SPI_I2S_SendData(SPI2, 2);
		if (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == SET)
			SPI_data = SPI_I2S_ReceiveData(SPI2);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		
		if (SPI_data == 0xFFFF)
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
		}		
		else
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
		}
		SPI_data1 = SPI_data>>8;
		USART_SendData(USART2, SPI_data1);
		while (USART_GetFlagStatus(USART2, USART_FLAG_TC != SET)){};
		USART_SendData(USART2, SPI_data);
		while (USART_GetFlagStatus(USART2, USART_FLAG_TC != SET)){};
		for (i = 0; i< 10000000;i++);
>>>>>>> master
		
	}
}

