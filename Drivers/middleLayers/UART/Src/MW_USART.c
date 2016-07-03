/*
 * USART.c
 *
 *  Created on: 2016/06/01
 *      Author: evaota
 */
#include "MW_USART.h"

UART_HandleTypeDef huart1 = {
  .Instance = USART1,
  .Init = {
    .BaudRate = 115200,
    .WordLength = UART_WORDLENGTH_8B,
    .StopBits = UART_STOPBITS_1,
    .Parity = UART_PARITY_NONE,
    .Mode = UART_MODE_TX_RX,
    .HwFlowCtl = UART_HWCONTROL_NONE,
    .OverSampling = UART_OVERSAMPLING_16
  },
};

UART_HandleTypeDef huart2 = {
  .Instance = USART2,
  .Init = {
    .BaudRate = 115200,
    .WordLength = UART_WORDLENGTH_8B,
    .StopBits = UART_STOPBITS_1,
    .Parity = UART_PARITY_NONE,
    .Mode = UART_MODE_TX_RX,
    .HwFlowCtl = UART_HWCONTROL_NONE,
    .OverSampling = UART_OVERSAMPLING_16
  },
};

UART_HandleTypeDef huart3 = {
  .Instance = USART3,
  .Init = {
    .BaudRate = 115200,
    .WordLength = UART_WORDLENGTH_8B,
    .StopBits = UART_STOPBITS_1,
    .Parity = UART_PARITY_NONE,
    .Mode = UART_MODE_TX_RX,
    .HwFlowCtl = UART_HWCONTROL_NONE,
    .OverSampling = UART_OVERSAMPLING_16
  },
};

static UART_HandleTypeDef *uartid[3] = {
  &huart1,
  &huart2,
  &huart3
};

void MW_SetUSARTMode(usartid_t id, uint32_t Mode){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.Mode = Mode;
}

void MW_SetUSARTHwFlowCtl(usartid_t id, uint32_t HwFlowCtl){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.HwFlowCtl = HwFlowCtl;
}

void MW_SetUSARTParity(usartid_t id, uint32_t Parity){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.Parity = Parity;
}

void MW_SetUSARTStopBits(usartid_t id, uint32_t StopBits){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.StopBits = StopBits;
}

void MW_SetUSARTWordLength(usartid_t id, uint32_t WordLength){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.WordLength = WordLength;
}

void MW_SetUSARTBaudRate(usartid_t id, uint32_t BaudRate){
  assert_param(IS_USART_ID(id));
  uartid[(uint32_t)id]->Init.BaudRate = BaudRate;
}

/* USART init function */
void MW_USARTInit(usartid_t id){
  if( HAL_UART_Init(uartid[(uint32_t)id]) != HAL_OK ){
    /* Error_Handler(); */
  }
}

int32_t MW_USART1Transmit(uint8_t *str, uint16_t datanum){
  if( HAL_UART_Transmit(&huart1, str, datanum, 0xFFFF) != HAL_OK ){
    return -1;
  }
  return 0;
}

int32_t MW_USART1Receive(void){
  uint8_t c;
  if( HAL_UART_Receive(&huart1, &c, 1, 100) != HAL_OK ){
    return -1;
  }
  return (uint32_t)c;
}

int32_t MW_USART2Transmit(uint8_t *str, uint16_t datanum){
  if( HAL_UART_Transmit_DMA(&huart2, str, datanum) != HAL_OK ){
    return -1;
  }
  return 0;
}

int32_t MW_USART2Receive(void){
  uint8_t c;
  if( HAL_UART_Receive(&huart2, &c, 1, 100) != HAL_OK ){
    return -1;
  }
  return (uint32_t)c;
}

int32_t MW_USART3Transmit(uint8_t *str, uint16_t datanum){
  if( HAL_UART_Transmit(&huart3, str, datanum, 0xFFFF) != HAL_OK ){
    return -1;
  }
  return 0;
}

int32_t MW_USART3Receive(void){
  uint8_t c;
  if( HAL_UART_Receive(&huart3, &c, 1, 100) != HAL_OK ){
    return -1;
  }
  return (uint32_t)c;
}

void MW_Puts(char *str, uint32_t len){
  MW_USART2Transmit((uint8_t*)str, len);
}

