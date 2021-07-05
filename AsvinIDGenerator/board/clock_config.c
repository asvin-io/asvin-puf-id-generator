/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/
/*
 * How to set up clock using clock driver functions:
 *
 * 1. Setup clock sources.
 *
 * 2. Set up wait states of the flash.
 *
 * 3. Set up all dividers.
 *
 * 4. Set up all selectors to provide selected clocks.
 */

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v7.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 8.0.3
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

#include "fsl_power.h"
#include "fsl_clock.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
    BOARD_BootClockPLL150M();
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockFRO12M **********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockFRO12M
outputs:
- {id: System_clock.outFreq, value: 12 MHz}
settings:
- {id: ANALOG_CONTROL_FRO192M_CTRL_ENDI_FRO_96M_CFG, value: Enable}
sources:
- {id: ANACTRL.fro_hf.outFreq, value: 96 MHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockFRO12M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockFRO12M configuration
 ******************************************************************************/
void BOARD_BootClockFRO12M(void)
{
#ifndef SDK_SECONDARY_CORE
    /*!< Set up the clock sources */
    /*!< Configure FRO192M */
    POWER_DisablePD(kPDRUNCFG_PD_FRO192M);               /*!< Ensure FRO is on  */
    CLOCK_SetupFROClocking(12000000U);                   /*!< Set up FRO to the 12 MHz, just for sure */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                /*!< Switch to FRO 12MHz first to ensure we can change the clock setting */

    CLOCK_SetupFROClocking(96000000U);                   /* Enable FRO HF(96MHz) output */

    POWER_SetVoltageForFreq(12000000U);                  /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(12000000U);          /*!< Set FLASH wait states for core */

    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 0U, true);               /*!< Reset TRACECLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 1U, false);         /*!< Set TRACECLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 0U, true);               /*!< Reset SYSTICKCLKDIV0 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 1U, false);         /*!< Set SYSTICKCLKDIV0 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 0U, true);               /*!< Reset SYSTICKCLKDIV1 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 1U, false);         /*!< Set SYSTICKCLKDIV1 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 0U, true);               /*!< Reset AHBCLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 0U, true);               /*!< Reset FROHFDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 1U, false);         /*!< Set FROHFDIV divider to value 1 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                 /*!< Switch MAIN_CLK to FRO12M */

    /*< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKFRO12M_CORE_CLOCK;
#endif
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockFROHF96M *********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockFROHF96M
outputs:
- {id: FXCOM0_clock.outFreq, value: 12 MHz}
- {id: FXCOM1_clock.outFreq, value: 12 MHz}
- {id: System_clock.outFreq, value: 96 MHz}
settings:
- {id: ANALOG_CONTROL_FRO192M_CTRL_ENDI_FRO_96M_CFG, value: Enable}
- {id: SYSCON.FCCLKSEL0.sel, value: ANACTRL.fro_12m_clk}
- {id: SYSCON.FCCLKSEL1.sel, value: ANACTRL.fro_12m_clk}
- {id: SYSCON.FROHFDIV.scale, value: '2'}
- {id: SYSCON.MAINCLKSELA.sel, value: ANACTRL.fro_hf_clk}
sources:
- {id: ANACTRL.fro_hf.outFreq, value: 96 MHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockFROHF96M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockFROHF96M configuration
 ******************************************************************************/
void BOARD_BootClockFROHF96M(void)
{
#ifndef SDK_SECONDARY_CORE
    /*!< Set up the clock sources */
    /*!< Configure FRO192M */
    POWER_DisablePD(kPDRUNCFG_PD_FRO192M);               /*!< Ensure FRO is on  */
    CLOCK_SetupFROClocking(12000000U);                   /*!< Set up FRO to the 12 MHz, just for sure */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                /*!< Switch to FRO 12MHz first to ensure we can change the clock setting */

    CLOCK_SetupFROClocking(96000000U);                   /* Enable FRO HF(96MHz) output */

    POWER_SetVoltageForFreq(96000000U);                  /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(96000000U);          /*!< Set FLASH wait states for core */

    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 0U, true);               /*!< Reset TRACECLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 1U, false);         /*!< Set TRACECLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 0U, true);               /*!< Reset SYSTICKCLKDIV0 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 1U, false);         /*!< Set SYSTICKCLKDIV0 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 0U, true);               /*!< Reset SYSTICKCLKDIV1 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 1U, false);         /*!< Set SYSTICKCLKDIV1 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg0, 0U, true);               /*!< Reset FRGCTRL0_DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg0, 256U, false);         /*!< Set FRGCTRL0_DIV divider to value 256 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg1, 0U, true);               /*!< Reset FRGCTRL1_DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg1, 256U, false);         /*!< Set FRGCTRL1_DIV divider to value 256 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 0U, true);               /*!< Reset AHBCLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 0U, true);               /*!< Reset FROHFDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 2U, false);         /*!< Set FROHFDIV divider to value 2 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kFRO_HF_to_MAIN_CLK);                 /*!< Switch MAIN_CLK to FRO_HF */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);                 /*!< Switch FLEXCOMM0 to FRO12M */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM1);                 /*!< Switch FLEXCOMM1 to FRO12M */

    /*< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKFROHF96M_CORE_CLOCK;
#endif
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockPLL100M *********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockPLL100M
outputs:
- {id: System_clock.outFreq, value: 100 MHz}
settings:
- {id: PLL0_Mode, value: Normal}
- {id: ANALOG_CONTROL_FRO192M_CTRL_ENDI_FRO_96M_CFG, value: Enable}
- {id: ENABLE_CLKIN_ENA, value: Enabled}
- {id: ENABLE_SYSTEM_CLK_OUT, value: Enabled}
- {id: SYSCON.MAINCLKSELB.sel, value: SYSCON.PLL0_BYPASS}
- {id: SYSCON.PLL0CLKSEL.sel, value: SYSCON.CLK_IN_EN}
- {id: SYSCON.PLL0M_MULT.scale, value: '100', locked: true}
- {id: SYSCON.PLL0N_DIV.scale, value: '4', locked: true}
- {id: SYSCON.PLL0_PDEC.scale, value: '4', locked: true}
sources:
- {id: ANACTRL.fro_hf.outFreq, value: 96 MHz}
- {id: SYSCON.XTAL32M.outFreq, value: 16 MHz, enabled: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockPLL100M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockPLL100M configuration
 ******************************************************************************/
void BOARD_BootClockPLL100M(void)
{
#ifndef SDK_SECONDARY_CORE
    /*!< Set up the clock sources */
    /*!< Configure FRO192M */
    POWER_DisablePD(kPDRUNCFG_PD_FRO192M);               /*!< Ensure FRO is on  */
    CLOCK_SetupFROClocking(12000000U);                   /*!< Set up FRO to the 12 MHz, just for sure */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                /*!< Switch to FRO 12MHz first to ensure we can change the clock setting */

    CLOCK_SetupFROClocking(96000000U);                   /* Enable FRO HF(96MHz) output */

    /*!< Configure XTAL32M */
    POWER_DisablePD(kPDRUNCFG_PD_XTAL32M);                        /* Ensure XTAL32M is powered */
    POWER_DisablePD(kPDRUNCFG_PD_LDOXO32M);                       /* Ensure XTAL32M is powered */
    CLOCK_SetupExtClocking(16000000U);                            /* Enable clk_in clock */
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK;       /* Enable clk_in from XTAL32M clock  */
    ANACTRL->XO32M_CTRL |= ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_MASK;    /* Enable clk_in to system  */

    POWER_SetVoltageForFreq(100000000U);                  /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(100000000U);          /*!< Set FLASH wait states for core */

    /*!< Set up PLL */
    CLOCK_AttachClk(kEXT_CLK_to_PLL0);                    /*!< Switch PLL0CLKSEL to EXT_CLK */
    POWER_DisablePD(kPDRUNCFG_PD_PLL0);                  /* Ensure PLL is on  */
    POWER_DisablePD(kPDRUNCFG_PD_PLL0_SSCG);
    const pll_setup_t pll0Setup = {
        .pllctrl = SYSCON_PLL0CTRL_CLKEN_MASK | SYSCON_PLL0CTRL_SELI(53U) | SYSCON_PLL0CTRL_SELP(26U),
        .pllndec = SYSCON_PLL0NDEC_NDIV(4U),
        .pllpdec = SYSCON_PLL0PDEC_PDIV(2U),
        .pllsscg = {0x0U,(SYSCON_PLL0SSCG1_MDIV_EXT(100U) | SYSCON_PLL0SSCG1_SEL_EXT_MASK)},
        .pllRate = 100000000U,
        .flags =  PLL_SETUPFLAG_WAITLOCK
    };
    CLOCK_SetPLL0Freq(&pll0Setup);                       /*!< Configure PLL0 to the desired values */

    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 0U, true);               /*!< Reset TRACECLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 1U, false);         /*!< Set TRACECLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 0U, true);               /*!< Reset SYSTICKCLKDIV0 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 1U, false);         /*!< Set SYSTICKCLKDIV0 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 0U, true);               /*!< Reset SYSTICKCLKDIV1 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 1U, false);         /*!< Set SYSTICKCLKDIV1 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 0U, true);               /*!< Reset AHBCLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 0U, true);               /*!< Reset FROHFDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFrohfClk, 1U, false);         /*!< Set FROHFDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 0U, true);               /*!< Reset PLL0DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 1U, false);         /*!< Set PLL0DIV divider to value 1 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kPLL0_to_MAIN_CLK);                 /*!< Switch MAIN_CLK to PLL0 */

    /*< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKPLL100M_CORE_CLOCK;
#endif
}

/*******************************************************************************
 ******************** Configuration BOARD_BootClockPLL150M *********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockPLL150M
called_from_default_init: true
outputs:
- {id: FXCOM0_clock.outFreq, value: 12 MHz}
- {id: FXCOM1_clock.outFreq, value: 12 MHz}
- {id: System_clock.outFreq, value: 150 MHz}
settings:
- {id: PLL0_Mode, value: Normal}
- {id: ENABLE_CLKIN_ENA, value: Enabled}
- {id: ENABLE_SYSTEM_CLK_OUT, value: Enabled}
- {id: SYSCON.FCCLKSEL0.sel, value: ANACTRL.fro_12m_clk}
- {id: SYSCON.FCCLKSEL1.sel, value: ANACTRL.fro_12m_clk}
- {id: SYSCON.MAINCLKSELB.sel, value: SYSCON.PLL0_BYPASS}
- {id: SYSCON.PLL0CLKSEL.sel, value: SYSCON.CLK_IN_EN}
- {id: SYSCON.PLL0M_MULT.scale, value: '150', locked: true}
- {id: SYSCON.PLL0N_DIV.scale, value: '8', locked: true}
- {id: SYSCON.PLL0_PDEC.scale, value: '2', locked: true}
sources:
- {id: SYSCON.XTAL32M.outFreq, value: 16 MHz, enabled: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockPLL150M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockPLL150M configuration
 ******************************************************************************/
void BOARD_BootClockPLL150M(void)
{
#ifndef SDK_SECONDARY_CORE
    /*!< Set up the clock sources */
    /*!< Configure FRO192M */
    POWER_DisablePD(kPDRUNCFG_PD_FRO192M);               /*!< Ensure FRO is on  */
    CLOCK_SetupFROClocking(12000000U);                   /*!< Set up FRO to the 12 MHz, just for sure */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                /*!< Switch to FRO 12MHz first to ensure we can change the clock setting */

    /*!< Configure XTAL32M */
    POWER_DisablePD(kPDRUNCFG_PD_XTAL32M);                        /* Ensure XTAL32M is powered */
    POWER_DisablePD(kPDRUNCFG_PD_LDOXO32M);                       /* Ensure XTAL32M is powered */
    CLOCK_SetupExtClocking(16000000U);                            /* Enable clk_in clock */
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK;       /* Enable clk_in from XTAL32M clock  */
    ANACTRL->XO32M_CTRL |= ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_MASK;    /* Enable clk_in to system  */

    POWER_SetVoltageForFreq(150000000U);                  /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(150000000U);          /*!< Set FLASH wait states for core */

    /*!< Set up PLL */
    CLOCK_AttachClk(kEXT_CLK_to_PLL0);                    /*!< Switch PLL0CLKSEL to EXT_CLK */
    POWER_DisablePD(kPDRUNCFG_PD_PLL0);                  /* Ensure PLL is on  */
    POWER_DisablePD(kPDRUNCFG_PD_PLL0_SSCG);
    const pll_setup_t pll0Setup = {
        .pllctrl = SYSCON_PLL0CTRL_CLKEN_MASK | SYSCON_PLL0CTRL_SELI(53U) | SYSCON_PLL0CTRL_SELP(31U),
        .pllndec = SYSCON_PLL0NDEC_NDIV(8U),
        .pllpdec = SYSCON_PLL0PDEC_PDIV(1U),
        .pllsscg = {0x0U,(SYSCON_PLL0SSCG1_MDIV_EXT(150U) | SYSCON_PLL0SSCG1_SEL_EXT_MASK)},
        .pllRate = 150000000U,
        .flags =  PLL_SETUPFLAG_WAITLOCK
    };
    CLOCK_SetPLL0Freq(&pll0Setup);                       /*!< Configure PLL0 to the desired values */

    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 0U, true);               /*!< Reset TRACECLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 1U, false);         /*!< Set TRACECLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 0U, true);               /*!< Reset SYSTICKCLKDIV0 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 1U, false);         /*!< Set SYSTICKCLKDIV0 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 0U, true);               /*!< Reset SYSTICKCLKDIV1 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 1U, false);         /*!< Set SYSTICKCLKDIV1 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg0, 0U, true);               /*!< Reset FRGCTRL0_DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg0, 256U, false);         /*!< Set FRGCTRL0_DIV divider to value 256 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg1, 0U, true);               /*!< Reset FRGCTRL1_DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivFlexFrg1, 256U, false);         /*!< Set FRGCTRL1_DIV divider to value 256 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 0U, true);               /*!< Reset AHBCLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 0U, true);               /*!< Reset PLL0DIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 1U, false);         /*!< Set PLL0DIV divider to value 1 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kPLL0_to_MAIN_CLK);                 /*!< Switch MAIN_CLK to PLL0 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);                 /*!< Switch FLEXCOMM0 to FRO12M */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM1);                 /*!< Switch FLEXCOMM1 to FRO12M */

    /*< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKPLL150M_CORE_CLOCK;
#endif
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockPLL1_150M ********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockPLL1_150M
outputs:
- {id: System_clock.outFreq, value: 150 MHz}
settings:
- {id: PLL1_Mode, value: Normal}
- {id: ENABLE_CLKIN_ENA, value: Enabled}
- {id: ENABLE_SYSTEM_CLK_OUT, value: Enabled}
- {id: SYSCON.MAINCLKSELB.sel, value: SYSCON.PLL1_BYPASS}
- {id: SYSCON.PLL1CLKSEL.sel, value: SYSCON.CLK_IN_EN}
- {id: SYSCON.PLL1M_MULT.scale, value: '150', locked: true}
- {id: SYSCON.PLL1N_DIV.scale, value: '8', locked: true}
- {id: SYSCON.PLL1_PDEC.scale, value: '2', locked: true}
sources:
- {id: SYSCON.XTAL32M.outFreq, value: 16 MHz, enabled: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockPLL1_150M configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockPLL1_150M configuration
 ******************************************************************************/
void BOARD_BootClockPLL1_150M(void)
{
#ifndef SDK_SECONDARY_CORE
    /*!< Set up the clock sources */
    /*!< Configure FRO192M */
    POWER_DisablePD(kPDRUNCFG_PD_FRO192M);               /*!< Ensure FRO is on  */
    CLOCK_SetupFROClocking(12000000U);                   /*!< Set up FRO to the 12 MHz, just for sure */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                /*!< Switch to FRO 12MHz first to ensure we can change the clock setting */

    /*!< Configure XTAL32M */
    POWER_DisablePD(kPDRUNCFG_PD_XTAL32M);                        /* Ensure XTAL32M is powered */
    POWER_DisablePD(kPDRUNCFG_PD_LDOXO32M);                       /* Ensure XTAL32M is powered */
    CLOCK_SetupExtClocking(16000000U);                            /* Enable clk_in clock */
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK;       /* Enable clk_in from XTAL32M clock  */
    ANACTRL->XO32M_CTRL |= ANACTRL_XO32M_CTRL_ENABLE_SYSTEM_CLK_OUT_MASK;    /* Enable clk_in to system  */

    POWER_SetVoltageForFreq(150000000U);                  /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(150000000U);          /*!< Set FLASH wait states for core */

    /*!< Set up PLL1 */
    CLOCK_AttachClk(kEXT_CLK_to_PLL1);                    /*!< Switch PLL1CLKSEL to EXT_CLK */
    POWER_DisablePD(kPDRUNCFG_PD_PLL1);                  /* Ensure PLL is on  */
    const pll_setup_t pll1Setup = {
        .pllctrl = SYSCON_PLL1CTRL_CLKEN_MASK | SYSCON_PLL1CTRL_SELI(53U) | SYSCON_PLL1CTRL_SELP(31U),
        .pllndec = SYSCON_PLL1NDEC_NDIV(8U),
        .pllpdec = SYSCON_PLL1PDEC_PDIV(1U),
        .pllmdec = SYSCON_PLL1MDEC_MDIV(150U),
        .pllRate = 150000000U,
        .flags =  PLL_SETUPFLAG_WAITLOCK
    };
    CLOCK_SetPLL1Freq(&pll1Setup);                        /*!< Configure PLL1 to the desired values */

    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 0U, true);               /*!< Reset TRACECLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivArmTrClkDiv, 1U, false);         /*!< Set TRACECLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 0U, true);               /*!< Reset SYSTICKCLKDIV0 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk0, 1U, false);         /*!< Set SYSTICKCLKDIV0 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 0U, true);               /*!< Reset SYSTICKCLKDIV1 divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivSystickClk1, 1U, false);         /*!< Set SYSTICKCLKDIV1 divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 0U, true);               /*!< Reset AHBCLKDIV divider counter and halt it */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);         /*!< Set AHBCLKDIV divider to value 1 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kPLL1_to_MAIN_CLK);                 /*!< Switch MAIN_CLK to PLL1 */

    /*< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKPLL1_150M_CORE_CLOCK;
#endif
}

