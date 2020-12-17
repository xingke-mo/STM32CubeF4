/**
  ******************************************************************************
  * @file    USB_Device/DFU_Standalone/Src/usbd_conf.c
  * @author  MCD Application Team
  * @brief   This file implements the USB Device library callbacks and MSP
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "usbd_core.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
PCD_HandleTypeDef hpcd;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
                       PCD BSP Routines
*******************************************************************************/
/**
  * @brief  Initializes the PCD MSP.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_MspInit( PCD_HandleTypeDef *hpcd )
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    if( hpcd->Instance == USB_OTG_FS )
    {
        /* Configure USB FS GPIOs */
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /* Configure DM DP Pins */
        GPIO_InitStruct.Pin = ( GPIO_PIN_11 | GPIO_PIN_12 );
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
        HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

        /* Configure VBUS Pin */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

        /* Configure ID pin */
        GPIO_InitStruct.Pin = GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
        HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

        /* Enable USB FS Clocks */
        __HAL_RCC_USB_OTG_FS_CLK_ENABLE();

        /* Set USBFS Interrupt to the lowest priority */
        HAL_NVIC_SetPriority( OTG_FS_IRQn, 5, 0 );

        /* Enable USBFS Interrupt */
        HAL_NVIC_EnableIRQ( OTG_FS_IRQn );
    }

    else if( hpcd->Instance == USB_OTG_HS )
    {
        /* Configure USB FS GPIOs */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        __HAL_RCC_GPIOI_CLK_ENABLE();

        /* CLK */
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

        /* D0 */
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

        /* D1 D2 D3 D4 D5 D6 D7 */
        GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_5 | \
                              GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOB, &GPIO_InitStruct );

        /* STP */
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOC, &GPIO_InitStruct );

        /* NXT */
        GPIO_InitStruct.Pin = GPIO_PIN_4;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOH, &GPIO_InitStruct );

        /* DIR */
        GPIO_InitStruct.Pin = GPIO_PIN_11;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_HS;
        HAL_GPIO_Init( GPIOI, &GPIO_InitStruct );

        /* Enable USB HS Clocks */
        __HAL_RCC_USB_OTG_HS_CLK_ENABLE();
        __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE();

        /* Set USBHS Interrupt to the lowest priority */
        HAL_NVIC_SetPriority( OTG_HS_IRQn, 5, 0 );

        /* Enable USBHS Interrupt */
        HAL_NVIC_EnableIRQ( OTG_HS_IRQn );
    }
}
/**
  * @brief  DeInitializes the PCD MSP.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_MspDeInit( PCD_HandleTypeDef *hpcd )
{
    if( hpcd->Instance == USB_OTG_FS )
    {
        /* Disable USB FS Clocks */
        __HAL_RCC_USB_OTG_FS_CLK_DISABLE();
        __HAL_RCC_SYSCFG_CLK_DISABLE();
    }
    else if( hpcd->Instance == USB_OTG_HS )
    {
        /* Disable USB FS Clocks */
        __HAL_RCC_USB_OTG_HS_CLK_DISABLE();
        __HAL_RCC_SYSCFG_CLK_DISABLE();
    }
}

/*******************************************************************************
                       LL Driver Callbacks (PCD -> USB Device Library)
*******************************************************************************/


/**
  * @brief  Setup stage callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_SetupStageCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_SetupStage( hpcd->pData, ( uint8_t * )hpcd->Setup );
}

/**
  * @brief  Data Out stage callback.
  * @param  hpcd: PCD handle
  * @param  epnum: Endpoint Number
  * @retval None
  */
void HAL_PCD_DataOutStageCallback( PCD_HandleTypeDef *hpcd, uint8_t epnum )
{
    USBD_LL_DataOutStage( hpcd->pData, epnum, hpcd->OUT_ep[epnum].xfer_buff );
}

/**
  * @brief  Data In stage callback.
  * @param  hpcd: PCD handle
  * @param  epnum: Endpoint Number
  * @retval None
  */
void HAL_PCD_DataInStageCallback( PCD_HandleTypeDef *hpcd, uint8_t epnum )
{
    USBD_LL_DataInStage( hpcd->pData, epnum, hpcd->IN_ep[epnum].xfer_buff );
}

/**
  * @brief  SOF callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_SOFCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_SOF( hpcd->pData );
}

/**
  * @brief  Reset callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ResetCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_SpeedTypeDef speed = USBD_SPEED_FULL;

    /* Set USB Current Speed */
    switch( hpcd->Init.speed )
    {
    case PCD_SPEED_HIGH:
        speed = USBD_SPEED_HIGH;
        break;

    case PCD_SPEED_FULL:
        speed = USBD_SPEED_FULL;
        break;

    default:
        speed = USBD_SPEED_FULL;
        break;
    }

    USBD_LL_SetSpeed( hpcd->pData, speed );

    /* Reset Device */
    USBD_LL_Reset( hpcd->pData );
}

/**
  * @brief  Suspend callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_SuspendCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_Suspend( hpcd->pData );
}

/**
  * @brief  Resume callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ResumeCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_Resume( hpcd->pData );
}

/**
  * @brief  ISOC Out Incomplete callback.
  * @param  hpcd: PCD handle
  * @param  epnum: Endpoint Number
  * @retval None
  */
void HAL_PCD_ISOOUTIncompleteCallback( PCD_HandleTypeDef *hpcd, uint8_t epnum )
{
    USBD_LL_IsoOUTIncomplete( hpcd->pData, epnum );
}

/**
  * @brief  ISOC In Incomplete callback.
  * @param  hpcd: PCD handle
  * @param  epnum: Endpoint Number
  * @retval None
  */
void HAL_PCD_ISOINIncompleteCallback( PCD_HandleTypeDef *hpcd, uint8_t epnum )
{
    USBD_LL_IsoINIncomplete( hpcd->pData, epnum );
}

/**
  * @brief  Connect callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ConnectCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_DevConnected( hpcd->pData );
}

/**
  * @brief  Disconnect callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_DisconnectCallback( PCD_HandleTypeDef *hpcd )
{
    USBD_LL_DevDisconnected( hpcd->pData );
}

/*******************************************************************************
                       LL Driver Interface (USB Device Library --> PCD)
*******************************************************************************/
/**
  * @brief  Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef  USBD_LL_Init( USBD_HandleTypeDef *pdev )
{
    /* Change Systick prioity */
    NVIC_SetPriority( SysTick_IRQn, 0 );

#ifdef USE_USB_FS
    /*Set LL Driver parameters */
    hpcd.Instance = USB_OTG_FS;
    hpcd.Init.dev_endpoints = 3;
    hpcd.Init.use_dedicated_ep1 = 0;
    hpcd.Init.dma_enable = 0;
    hpcd.Init.low_power_enable = 0;
    hpcd.Init.phy_itface = PCD_PHY_EMBEDDED;
    hpcd.Init.Sof_enable = 0;
    hpcd.Init.speed = PCD_SPEED_FULL;
    hpcd.Init.vbus_sensing_enable = 1;
    /* Link The driver to the stack */
    hpcd.pData = pdev;
    pdev->pData = &hpcd;
    /*Initialize LL Driver */
    HAL_PCD_Init( &hpcd );

    HAL_PCDEx_SetRxFiFo( &hpcd, 0xA0 );
    HAL_PCDEx_SetTxFiFo( &hpcd, 0, 0xA0 );
#endif
#ifdef USE_USB_HS
    /*Set LL Driver parameters */
    hpcd.Instance = USB_OTG_HS;
    hpcd.Init.dev_endpoints = 6;
    hpcd.Init.use_dedicated_ep1 = 0;

    /* In High Speed mode, it is not possible to use USB-DMA for writing/reading to/from Flash memory
      because the USB HS DMA is not connected (at product level) to this memory
      (refer to RM0090 reference manual for more details).
      If USB-DMA mode is enabled, an intermediate buffer must be used to interface between
      memory and DMA controller. This may result in performance degradation for
      transfers relative to flash memory in High Speed mode.
      It is advised to disable USB-DMA mode if it is not used for other interfaces. */
    hpcd.Init.dma_enable = 0;

    hpcd.Init.low_power_enable = 0;
    hpcd.Init.phy_itface = PCD_PHY_ULPI;
    hpcd.Init.Sof_enable = 0;
    hpcd.Init.speed = PCD_SPEED_HIGH;
    hpcd.Init.vbus_sensing_enable = 1;
    /* Link The driver to the stack */
    hpcd.pData = pdev;
    pdev->pData = &hpcd;
    /*Initialize LL Driver */
    HAL_PCD_Init( &hpcd );

    HAL_PCDEx_SetRxFiFo( &hpcd, 0x200 );
    HAL_PCDEx_SetTxFiFo( &hpcd, 0, 0x200 );
#endif
    return USBD_OK;
}

/**
  * @brief  De-Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_DeInit( USBD_HandleTypeDef *pdev )
{
    HAL_PCD_DeInit( pdev->pData );
    return USBD_OK;
}

/**
  * @brief  Starts the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Start( USBD_HandleTypeDef *pdev )
{
    HAL_PCD_Start( pdev->pData );
    return USBD_OK;
}

/**
  * @brief  Stops the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Stop( USBD_HandleTypeDef *pdev )
{
    HAL_PCD_Stop( pdev->pData );
    return USBD_OK;
}

/**
  * @brief  Opens an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  ep_type: Endpoint Type
  * @param  ep_mps: Endpoint Max Packet Size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_OpenEP( USBD_HandleTypeDef *pdev,
                                   uint8_t  ep_addr,
                                   uint8_t  ep_type,
                                   uint16_t ep_mps )
{
    HAL_PCD_EP_Open( pdev->pData, ep_addr, ep_mps, ep_type );
    return USBD_OK;
}

/**
  * @brief  Closes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_CloseEP( USBD_HandleTypeDef *pdev, uint8_t ep_addr )
{
    HAL_PCD_EP_Close( pdev->pData, ep_addr );
    return USBD_OK;
}

/**
  * @brief  Flushes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_FlushEP( USBD_HandleTypeDef *pdev, uint8_t ep_addr )
{
    HAL_PCD_EP_Flush( pdev->pData, ep_addr );
    return USBD_OK;
}

/**
  * @brief  Sets a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_StallEP( USBD_HandleTypeDef *pdev, uint8_t ep_addr )
{
    HAL_PCD_EP_SetStall( pdev->pData, ep_addr );
    return USBD_OK;
}

/**
  * @brief  Clears a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_ClearStallEP( USBD_HandleTypeDef *pdev, uint8_t ep_addr )
{
    HAL_PCD_EP_ClrStall( pdev->pData, ep_addr );
    return USBD_OK;
}

/**
  * @brief  Returns Stall condition.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Stall (1: yes, 0: No)
  */
uint8_t USBD_LL_IsStallEP( USBD_HandleTypeDef *pdev, uint8_t ep_addr )
{
    PCD_HandleTypeDef *hpcd = pdev->pData;

    if( ( ep_addr & 0x80 ) == 0x80 )
    {
        return hpcd->IN_ep[ep_addr & 0x7F].is_stall;
    }
    else
    {
        return hpcd->OUT_ep[ep_addr & 0x7F].is_stall;
    }
}

/**
  * @brief  Assigns an USB address to the device
  * @param  pdev: Device handle
  * @param  dev_addr: USB address
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_SetUSBAddress( USBD_HandleTypeDef *pdev, uint8_t dev_addr )
{
    HAL_PCD_SetAddress( pdev->pData, dev_addr );
    return USBD_OK;
}

/**
  * @brief  Transmits data over an endpoint
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf: Pointer to data to be sent
  * @param  size: Data size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Transmit( USBD_HandleTypeDef *pdev,
                                     uint8_t  ep_addr,
                                     uint8_t  *pbuf,
                                     uint32_t  size )

{
    HAL_PCD_EP_Transmit( pdev->pData, ep_addr, pbuf, size );
    return USBD_OK;
}

/**
  * @brief  Prepares an endpoint for reception
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf:pointer to data to be received
  * @param  size: data size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_PrepareReceive( USBD_HandleTypeDef *pdev,
        uint8_t  ep_addr,
        uint8_t  *pbuf,
        uint32_t  size )
{
    HAL_PCD_EP_Receive( pdev->pData, ep_addr, pbuf, size );
    return USBD_OK;
}

/**
  * @brief  Returns the last transfered packet size.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Recived Data Size
  */
uint32_t USBD_LL_GetRxDataSize( USBD_HandleTypeDef *pdev, uint8_t  ep_addr )
{
    return HAL_PCD_EP_GetRxCount( pdev->pData, ep_addr );
}

/**
  * @brief  Delay routine for the USB Device Library
  * @param  Delay: Delay in ms
  * @retval None
  */
void  USBD_LL_Delay( uint32_t Delay )
{
    HAL_Delay( Delay );
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
