#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/ECU_layer_intialize.c MCAL_Layer/ADC/adc.c MCAL_Layer/CCP1/CCP1.c MCAL_Layer/EEPROM/hal_EEPROM.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/Interrupt/Interrupt_manager.c MCAL_Layer/Interrupt/Internal_Interrupt.c MCAL_Layer/Interrupt/External_Interrupt.c MCAL_Layer/Timer0/timer0.c MCAL_Layer/Timer1/Timer1.c MCAL_Layer/Timer2/Timer2.c MCAL_Layer/Timer3/Timer3.c application.c MCAL_Layer/device_config.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1

# Source Files
SOURCEFILES=ECU_Layer/ECU_layer_intialize.c MCAL_Layer/ADC/adc.c MCAL_Layer/CCP1/CCP1.c MCAL_Layer/EEPROM/hal_EEPROM.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/Interrupt/Interrupt_manager.c MCAL_Layer/Interrupt/Internal_Interrupt.c MCAL_Layer/Interrupt/External_Interrupt.c MCAL_Layer/Timer0/timer0.c MCAL_Layer/Timer1/Timer1.c MCAL_Layer/Timer2/Timer2.c MCAL_Layer/Timer3/Timer3.c application.c MCAL_Layer/device_config.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1: ECU_Layer/ECU_layer_intialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 ECU_Layer/ECU_layer_intialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.d ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/adc.p1: MCAL_Layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 MCAL_Layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/adc.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1: MCAL_Layer/CCP1/CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 MCAL_Layer/CCP1/CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.d ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1: MCAL_Layer/EEPROM/hal_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 MCAL_Layer/EEPROM/hal_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1: MCAL_Layer/Interrupt/Interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 MCAL_Layer/Interrupt/Interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1: MCAL_Layer/Interrupt/Internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 MCAL_Layer/Interrupt/Internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1: MCAL_Layer/Interrupt/External_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 MCAL_Layer/Interrupt/External_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1: MCAL_Layer/Timer0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 MCAL_Layer/Timer0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.d ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1: MCAL_Layer/Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 MCAL_Layer/Timer1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1: MCAL_Layer/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 MCAL_Layer/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1: MCAL_Layer/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 MCAL_Layer/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1: ECU_Layer/ECU_layer_intialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1 ECU_Layer/ECU_layer_intialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.d ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_layer_intialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/adc.p1: MCAL_Layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 MCAL_Layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/adc.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1: MCAL_Layer/CCP1/CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1 MCAL_Layer/CCP1/CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.d ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1: MCAL_Layer/EEPROM/hal_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1 MCAL_Layer/EEPROM/hal_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1: MCAL_Layer/Interrupt/Interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1 MCAL_Layer/Interrupt/Interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1: MCAL_Layer/Interrupt/Internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1 MCAL_Layer/Interrupt/Internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1: MCAL_Layer/Interrupt/External_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1 MCAL_Layer/Interrupt/External_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/External_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1: MCAL_Layer/Timer0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1 MCAL_Layer/Timer0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.d ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1: MCAL_Layer/Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1 MCAL_Layer/Timer1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1: MCAL_Layer/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1 MCAL_Layer/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1: MCAL_Layer/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1 MCAL_Layer/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto -wa,-DLIMIT=5046324000     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -wa,-DLIMIT=5046324000 -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/application.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -wa,-DLIMIT=5046324000 -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
