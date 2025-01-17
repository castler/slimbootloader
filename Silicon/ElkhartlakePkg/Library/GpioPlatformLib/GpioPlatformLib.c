/** @file
  This file contains VER3 specific GPIO information

  Copyright (c) 2017 - 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Uefi/UefiBaseType.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
//#include <Library/SiGpioLib.h>
#include <Library/GpioNativeLib.h>
//#include <GpioLibConfig.h>
#include <Library/PchSbiAccessLib.h>
#include <Library/GpioHelpersLib.h>
#include <Register/GpioRegs.h>
#include <Register/GpioRegsVer3.h>
#include <Register/GpioPinsVer3.h>
#include <Register/PmcRegs.h>
#include <Register/PmcRegsVer3.h>

GLOBAL_REMOVE_IF_UNREFERENCED PCH_SBI_PID mGpioComSbiIds[] =
{
  PID_GPIOCOM0, PID_GPIOCOM1, PID_GPIOCOM2, PID_GPIOCOM3, PID_GPIOCOM4, PID_GPIOCOM5
};

GLOBAL_REMOVE_IF_UNREFERENCED GPIO_GROUP_TO_GPE_MAPPING mPchGpioGroupToGpeMapping[] = {
  {GPIO_VER3_GROUP_GPP_A,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_A,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_A},
  {GPIO_VER3_GROUP_GPP_B,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_B,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_B},
  {GPIO_VER3_GROUP_GPP_C,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_C,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_C},
  {GPIO_VER3_GROUP_GPP_D,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_D,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_D},
  {GPIO_VER3_GROUP_GPP_E,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_E,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_E},
  {GPIO_VER3_GROUP_GPP_F,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_F,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_F},
  {GPIO_VER3_GROUP_GPP_G,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_G,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_G},
  {GPIO_VER3_GROUP_GPP_H,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_H,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_H},
  {GPIO_VER3_GROUP_GPP_R,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_R,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_R},
  {GPIO_VER3_GROUP_GPP_S,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_S,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_S},
  {GPIO_VER3_GROUP_GPP_T,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_T,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_T},
  {GPIO_VER3_GROUP_GPP_U,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_U,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_U},
  {GPIO_VER3_GROUP_GPP_V,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPP_V,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPP_V},
  {GPIO_VER3_GROUP_GPD,     0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_GPD,    V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_GPD},
  {GPIO_VER3_GROUP_VGPIO,   0, V_EHL_PCH_PMC_PWRM_GPIO_CFG_VGPIO,  V_GPIO_VER3_PCH_GPIO_PCR_MISCCFG_GPE0_VGPIO}
};

GLOBAL_REMOVE_IF_UNREFERENCED GPIO_GROUP_TO_GPE_MAPPING mPchA0GpioGroupToGpeMapping[] = {
  {GPIO_VER3_GROUP_GPP_A,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_A,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_A},
  {GPIO_VER3_GROUP_GPP_B,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_B,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_B},
  {GPIO_VER3_GROUP_GPP_C,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_C,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_C},
  {GPIO_VER3_GROUP_GPP_D,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_D,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_D},
  {GPIO_VER3_GROUP_GPP_E,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_E,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_E},
  {GPIO_VER3_GROUP_GPP_F,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_F,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_F},
  {GPIO_VER3_GROUP_GPP_G,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_G,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_G},
  {GPIO_VER3_GROUP_GPP_H,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_H,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_H},
  {GPIO_VER3_GROUP_GPP_R,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_R,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_R},
  {GPIO_VER3_GROUP_GPP_S,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_S,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_S},
  {GPIO_VER3_GROUP_GPP_T,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_T,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_T},
  {GPIO_VER3_GROUP_GPP_U,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_U,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_U},
  {GPIO_VER3_GROUP_GPP_V,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPP_V,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPP_V},
  {GPIO_VER3_GROUP_GPD,     0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_GPD,    V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_GPD},
  {GPIO_VER3_GROUP_VGPIO,   0, V_EHL_PCH_A0_PMC_PWRM_GPIO_CFG_VGPIO,  V_GPIO_VER3_PCH_A0_GPIO_PCR_MISCCFG_GPE0_VGPIO}
};

GLOBAL_REMOVE_IF_UNREFERENCED GPIO_GROUP_INFO mPchGpioGroupInfo[] = {
  {PID_GPIOCOM0, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_GPI_GPE_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_SMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_SMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_NMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_NMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_B_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_B_PAD_MAX},  // EHL PCH GPP_B
  {PID_GPIOCOM0, R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_T_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_T_PAD_MAX},  // EHL PCH GPP_T
  {PID_GPIOCOM0, R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_G_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_G_PAD_MAX},  // EHL PCH GPP_G
  {PID_GPIOCOM1, R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_V_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_V_PAD_MAX},  // EHL PCH GPP_V
  {PID_GPIOCOM1, R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_H_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_H_PAD_MAX},  // EHL PCH GPP_H
  {PID_GPIOCOM1, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_GPI_GPE_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_SMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_SMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_NMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_NMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_D_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_D_PAD_MAX},  // EHL PCH GPP_D
  {PID_GPIOCOM1, R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_U_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_U_PAD_MAX},  // EHL PCH GPP_U
  {PID_GPIOCOM1, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_VGPIO_PAD_MAX},  // EHL PCH vGPIO
  {PID_GPIOCOM2, R_GPIO_VER3_PCH_GPIO_PCR_GPD_PAD_OWN,     R_GPIO_VER3_PCH_GPIO_PCR_GPD_HOSTSW_OWN,     R_GPIO_VER3_PCH_GPIO_PCR_GPD_GPI_IS,   R_GPIO_VER3_PCH_GPIO_PCR_GPD_GPI_IE,   R_GPIO_VER3_PCH_GPIO_PCR_GPD_GPI_GPE_STS,   R_GPIO_VER3_PCH_GPIO_PCR_GPD_GPI_GPE_EN,   NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPD_PADCFGLOCK,     R_GPIO_VER3_PCH_GPIO_PCR_GPD_PADCFGLOCKTX,     R_GPIO_VER3_PCH_GPIO_PCR_GPD_PADCFG_OFFSET,     GPIO_VER3_PCH_GPIO_GPD_PAD_MAX},    // EHL PCH GPD
  {PID_GPIOCOM3, R_GPIO_VER3_PCH_GPIO_PCR_CPU_PAD_OWN,     R_GPIO_VER3_PCH_GPIO_PCR_CPU_HOSTSW_OWN,     NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_CPU_PADCFGLOCK,     R_GPIO_VER3_PCH_GPIO_PCR_CPU_PADCFGLOCKTX,     R_GPIO_VER3_PCH_GPIO_PCR_CPU_PADCFG_OFFSET,     GPIO_VER3_PCH_GPIO_CPU_PAD_MAX},    // EHL PCH CPU
  {PID_GPIOCOM3, R_GPIO_VER3_PCH_GPIO_PCR_GPP_S_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_S_HOSTSW_OWN,   NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_S_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_S_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_S_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_S_PAD_MAX},  // EHL PCH GPP_S
  {PID_GPIOCOM3, R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_A_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_A_PAD_MAX},  // EHL PCH GPP_A
  {PID_GPIOCOM3, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_3_PAD_OWN, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_3_HOSTSW_OWN, NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_3_PADCFGLOCK, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_3_PADCFGLOCKTX, R_GPIO_VER3_PCH_GPIO_PCR_VGPIO_3_PADCFG_OFFSET, GPIO_VER3_PCH_GPIO_VGPIO_3_PAD_MAX},// EHL PCH VGPIO_3
  {PID_GPIOCOM4, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_GPI_GPE_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_SMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_SMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_NMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_NMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_C_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_C_PAD_MAX},  // EHL PCH GPP_C
  {PID_GPIOCOM4, R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_F_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_F_PAD_MAX},  // EHL PCH GPP_F
  {PID_GPIOCOM4, R_GPIO_VER3_PCH_GPIO_PCR_HVCMOS_PAD_OWN,  R_GPIO_VER3_PCH_GPIO_PCR_HVCMOS_HOSTSW_OWN,  NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_HVCMOS_PADCFGLOCK,  R_GPIO_VER3_PCH_GPIO_PCR_HVCMOS_PADCFGLOCKTX,  R_GPIO_VER3_PCH_GPIO_PCR_HVCMOS_PADCFG_OFFSET,  GPIO_VER3_PCH_GPIO_HVCMOS_PAD_MAX}, // EHL PCH HVCMOS
  {PID_GPIOCOM4, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_GPI_GPE_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_SMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_SMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_NMI_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_NMI_EN, R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_E_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_E_PAD_MAX},  // EHL PCH GPP_E
  {PID_GPIOCOM4, R_GPIO_VER3_PCH_GPIO_PCR_JTAG_PAD_OWN,    R_GPIO_VER3_PCH_GPIO_PCR_JTAG_HOSTSW_OWN,    NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_JTAG_PADCFGLOCK,    R_GPIO_VER3_PCH_GPIO_PCR_JTAG_PADCFGLOCKTX,    R_GPIO_VER3_PCH_GPIO_PCR_JTAG_PADCFG_OFFSET,    GPIO_VER3_PCH_GPIO_JTAG_PAD_MAX},   // EHL PCH JTAG
  {PID_GPIOCOM5, R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_PAD_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_HOSTSW_OWN,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_GPI_IS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_GPI_IE, R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_GPI_GPE_STS, R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_GPI_GPE_EN, NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_PADCFGLOCK,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_PADCFGLOCKTX,   R_GPIO_VER3_PCH_GPIO_PCR_GPP_R_PADCFG_OFFSET,   GPIO_VER3_PCH_GPIO_GPP_R_PAD_MAX},  // EHL PCH GPP_R
  {PID_GPIOCOM5, R_GPIO_VER3_PCH_GPIO_PCR_SPI_PAD_OWN,     R_GPIO_VER3_PCH_GPIO_PCR_SPI_HOSTSW_OWN,     NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,                   NO_REGISTER_FOR_PROPERTY,                  NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              NO_REGISTER_FOR_PROPERTY,               NO_REGISTER_FOR_PROPERTY,              R_GPIO_VER3_PCH_GPIO_PCR_SPI_PADCFGLOCK,     R_GPIO_VER3_PCH_GPIO_PCR_SPI_PADCFGLOCKTX,     R_GPIO_VER3_PCH_GPIO_PCR_SPI_PADCFG_OFFSET,     GPIO_VER3_PCH_GPIO_SPI_PAD_MAX}     // EHL PCH SPI
};

//
// GPIO_CFG_DATA DW1 fields
//
typedef struct {
  UINT32    Rsvd1:16;
  UINT32    PadNum:8;
  UINT32    GrpIdx:5;
  UINT32    Rsvd2:3;
} GPIO_CFG_DATA_DW1;

//
// GPIO_PAD Fileds
//
typedef union {
  struct {
    UINT32    PadNum      :16;
    UINT32    GrpIdx      :8;
    UINT32    ChipsetId   :4;
    UINT32    Rsvd        :4;
  } PadField;
  UINT32      Pad;
} PAD_INFO;

#define GPIO_PAD_DEF(Group,Pad)                (UINT32)(((Group) << 16) + (Pad))
#define GPIO_GROUP_DEF(GroupIndex,ChipsetId)   ((GroupIndex) | ((ChipsetId) << 8))
#define GPIO_GET_GROUP_FROM_PAD(GpioPad)       (((GpioPad) & 0x0F1F0000) >> 16)
#define GPIO_GET_GROUP_INDEX_FROM_PAD(GpioPad) GPIO_GET_GROUP_INDEX (GPIO_GET_GROUP_FROM_PAD(GpioPad))
#define GPIO_GET_PAD_NUMBER(GpioPad)           ((GpioPad) & 0x1FF)
#define GPIO_GET_CHIPSET_ID(GpioPad)           (((GpioPad) >> 24) & 0xF)
#define GPIO_GET_GROUP_INDEX(Group)            ((Group) & 0x1F)

/**
  This function gets Group to GPE0 configuration

  @param[out] GpeDw0Value       GPIO Group to GPE_DW0 assignment
  @param[out] GpeDw1Value       GPIO Group to GPE_DW1 assignment
  @param[out] GpeDw2Value       GPIO Group to GPE_DW2 assignment
**/
VOID
PmcGetGpioGpe (
  OUT UINT32    *GpeDw0Value,
  OUT UINT32    *GpeDw1Value,
  OUT UINT32    *GpeDw2Value
  )
{
  UINT32 Data32;

  Data32 = MmioRead32 ((UINTN) (PCH_PWRM_BASE_ADDRESS + R_PMC_PWRM_GPIO_CFG));

  *GpeDw0Value = ((Data32 & B_PMC_PWRM_GPIO_CFG_GPE0_DW0) >> N_PMC_PWRM_GPIO_CFG_GPE0_DW0);
  *GpeDw1Value = ((Data32 & B_PMC_PWRM_GPIO_CFG_GPE0_DW1) >> N_PMC_PWRM_GPIO_CFG_GPE0_DW1);
  *GpeDw2Value = ((Data32 & B_PMC_PWRM_GPIO_CFG_GPE0_DW2) >> N_PMC_PWRM_GPIO_CFG_GPE0_DW2);
}

/**
  Return opcode supported for writing to GPIO lock unlock register

  @retval UINT8   Lock Opcode
**/
UINT8
EFIAPI
GpioGetLockOpcode (
  VOID
  )
{
  return GpioLockUnlock;
}

/**
  This internal procedure will check if group is within DeepSleepWell.

  @param[in]  Group               GPIO Group

  @retval GroupWell               TRUE:  This is DSW Group
                                  FALSE: This is not DSW Group
**/
BOOLEAN
GpioIsDswGroup (
  IN  GPIO_GROUP         Group
  )
{
  if (Group == GPIO_VER3_GROUP_GPD) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
  This procedure will retrieve address and length of GPIO info table

  @param[out]  GpioGroupInfoTableLength   Length of GPIO group table

  @retval Pointer to GPIO group table

**/
CONST GPIO_GROUP_INFO*
GpioGetGroupInfoTable (
  OUT UINT32              *GpioGroupInfoTableLength
  )
{
  *GpioGroupInfoTableLength = ARRAY_SIZE (mPchGpioGroupInfo);
  return mPchGpioGroupInfo;
}

/**
  Get GPIO Chipset ID specific to PCH generation and series
**/
UINT32
GpioGetThisChipsetId (
  VOID
  )
{
  return GPIO_VER3_CHIPSET_ID;
}

/**
  Get information for GPIO Group required to program GPIO and PMC for desired 1-Tier GPE mapping

  @param[out] GpioGroupToGpeMapping        Table with GPIO Group to GPE mapping
  @param[out] GpioGroupToGpeMappingLength  GPIO Group to GPE mapping table length
**/
VOID
GpioGetGroupToGpeMapping (
  OUT GPIO_GROUP_TO_GPE_MAPPING  **GpioGroupToGpeMapping,
  OUT UINT32                     *GpioGroupToGpeMappingLength
  )
{
    *GpioGroupToGpeMapping = mPchA0GpioGroupToGpeMapping;
    *GpioGroupToGpeMappingLength = ARRAY_SIZE (mPchA0GpioGroupToGpeMapping);
}

/**
  This function provides GPIO Community PortIDs

  @param[out] NativePinsTable                Table with GPIO COMMx SBI PortIDs

  @retval     Number of communities

UINT32
EFIAPI
GpioGetComSbiPortIds (
  OUT GPIO_PCH_SBI_PID    **GpioComSbiIds
  )
{
  *GpioComSbiIds = mGpioComSbiIds;
  return ARRAY_SIZE (mGpioComSbiIds);
}**/

/**
  Wrapper to full function for executing PCH SBI message

  @param[in] Pid                        Port ID of the SBI message
  @param[in] Offset                     Offset of the SBI message
  @param[in] Opcode                     Opcode
  @param[in] Posted                     Posted message
  @param[in] Fbe                        First byte enable
  @param[in] Bar                        Bar
  @param[in] Fid                        Function ID
  @param[in, out] Data32                Read/Write data
  @param[out] Response                  Response

  @retval EFI_SUCCESS                   Successfully completed.
  @retval EFI_DEVICE_ERROR              Transaction fail
  @retval EFI_INVALID_PARAMETER         Invalid parameter
  @retval EFI_TIMEOUT                   Timeout while waiting for response
**/
EFI_STATUS
EFIAPI
GpioPchSbiExecutionEx (
  IN     PCH_SBI_PID               Pid,
  IN     UINT64                         Offset,
  IN     PCH_SBI_OPCODE            Opcode,
  IN     BOOLEAN                        Posted,
  IN     UINT16                         Fbe,
  IN     UINT16                         Bar,
  IN     UINT16                         Fid,
  IN OUT UINT32                         *Data32,
  OUT    UINT8                          *Response
  )
{
  return  PchSbiExecutionEx (
            Pid,
            Offset,
            Opcode,
            Posted,
            Fbe,
            Bar,
            Fid,
            Data32,
            Response
            );
}

/**
  Get PCH PCR Address for this Register

  @param[in] Pid                        Port ID of the SBI message
  @param[in] Offset                     Offset of the Cfg Regsiter

  @retval UINT32                        Pch Pcr Address to access this register
**/
UINT32
EFIAPI
GetPchPcrAddress (
  IN     PCH_SBI_PID               Pid,
  IN     UINT32                         Offset
  )
{
  return PCH_PCR_ADDRESS (Pid, Offset);
}

/**
  Get PCH PCR Address for this Register

  @param[in] *TableLength               Table length of Type C GPIO pad

  @retval UINT32                        Array size of Type C GPIO pad
**/
GPIO_PAD*
EFIAPI
GpioGetTypeCSbuGpioPad (
  IN OUT   UINT32      *TableLength
)
{
   return NULL;
}

/**
  Get GPIO PCR Pad Cfg Offset

  @retval PAD CFG Offset
**/
UINT8
EFIAPI
GpioGetPcrPadCfgOffset(
  VOID
  )
{
  return S_GPIO_PCR_PADCFG;
}

/**
  This procedure will return GpioPad from Group and PadNumber

  @param[in] Group              GPIO group
  @param[in] PadNumber          GPIO PadNumber

  @retval GpioPad               GpioPad
**/
GPIO_PAD
EFIAPI
GpioGetGpioPadFromGroupAndPadNumber (
  IN GPIO_GROUP      Group,
  IN UINT32          PadNumber
  )
{
  return GPIO_PAD_DEF (Group,PadNumber);
}

/**
  This procedure will return GpioPad from GroupIndex and PadNumber

  @param[in] GroupIndex         GPIO GroupIndex
  @param[in] PadNumber          GPIO PadNumber

  @retval GpioPad               GpioPad
**/
GPIO_PAD
EFIAPI
GpioGetGpioPadFromGroupIndexAndPadNumber (
  IN UINT32          GroupIndex,
  IN UINT32          PadNumber
  )
{
  GPIO_GROUP Group;

  Group = GPIO_GROUP_DEF (GroupIndex, GpioGetThisChipsetId ());
  return GPIO_PAD_DEF (Group, PadNumber);
}

/**
  This procedure will get group from group index (0 based)

  @param[in] GroupIndex        Group Index

  @retval GpioGroup            Gpio Group
**/
GPIO_GROUP
GpioGetGroupFromGroupIndex (
  IN UINT32        GroupIndex
  )
{
  return GPIO_GROUP_DEF (GroupIndex, GpioGetThisChipsetId ());
}

/**
  This procedure will get group index (0 based) from group

  @param[in] GpioGroup        Gpio Group

  @retval Value               Group Index
**/
UINT32
GpioGetGroupIndexFromGroup (
  IN GPIO_GROUP        GpioGroup
  )
{
  return (UINT32) GPIO_GET_GROUP_INDEX (GpioGroup);
}

/**
  This procedure will get group number

  @param[in] GpioPad          Gpio Pad

  @retval Value               Group number
**/
GPIO_GROUP
GpioGetGroupFromGpioPad (
  IN GPIO_PAD         GpioPad
  )
{
  return GPIO_GET_GROUP_FROM_PAD (GpioPad);
}

/**
  This procedure will get group index (0 based)

  @param[in] GpioPad          Gpio Pad

  @retval Value               Group Index
**/
UINT32
GpioGetGroupIndexFromGpioPad (
  IN GPIO_PAD        GpioPad
  )
{
  return (UINT32) GPIO_GET_GROUP_INDEX_FROM_PAD (GpioPad);
}

/**
  This procedure will get pad number (0 based) from Gpio Pad

  @param[in] GpioPad          Gpio Pad

  @retval Value               Pad Number
**/
UINT32
GpioGetPadNumberFromGpioPad (
  IN GPIO_PAD        GpioPad
  )
{
  return (UINT32) GPIO_GET_PAD_NUMBER (GpioPad);
}

/**
  This procedure will get Chipset ID from Gpio Pad

  @param[in] GpioPad          Gpio Pad

  @retval Value               PCH Chipset ID
**/
UINT32
EFIAPI
GpioGetChipsetIdFromGpioPad (
  IN GPIO_PAD        GpioPad
  )
{
  return (UINT32) GPIO_GET_CHIPSET_ID (GpioPad);
}

/**
  This procedure will get Gpio Pad from Cfg Dword

  @param[in]  GpioItem         Pointer to the Gpio Cfg Data Item
  @param[out] GpioPad          Gpio Pad
**/
VOID
EFIAPI
GpioGetGpioPadFromCfgDw (
  IN  UINT32        *GpioItem,
  OUT GPIO_PAD      *GpioPad
  )
{
  GPIO_CFG_DATA_DW1    *Dw1;
  PAD_INFO              PadInfo;

  Dw1 = (GPIO_CFG_DATA_DW1 *) (&GpioItem[1]);

  PadInfo.PadField.PadNum    = (UINT16) Dw1->PadNum;
  PadInfo.PadField.GrpIdx    = (UINT8)  Dw1->GrpIdx;
  PadInfo.PadField.ChipsetId = GpioGetThisChipsetId ();
  *GpioPad = PadInfo.Pad;

  //
  // Remove PadInfo data from DW1
  //
  Dw1->PadNum = 0;
  Dw1->GrpIdx = 0;
}
