/*
 * Subsystem1_sf.h
 *
 * Code generation for model "Subsystem1_sf".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Jul 04 15:10:17 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Subsystem1_sf_h_
#define RTW_HEADER_Subsystem1_sf_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Subsystem1_sf_COMMON_INCLUDES_
# define Subsystem1_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                Subsystem1_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* Subsystem1_sf_COMMON_INCLUDES_ */

#include "Subsystem1_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Switch;                       /* '<S1>/Switch' */
  real_T FaultCont1;                   /* '<S2>/FaultCont1' */
  real_T FaultCont;                    /* '<S2>/FaultCont' */
  real_T MathFunction;                 /* '<S4>/Math Function' */
  real_T ContantofPassiveDevice;       /* '<S3>/ContantofPassiveDevice' */
  real_T Step;                         /* '<S4>/Step' */
  boolean_T Logical;                   /* '<S2>/Logical' */
} B_Subsystem1_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Nomal;                       /* '<Root>/Nomal' */
  real_T *OutsideSignal1;              /* '<Root>/Outside Signal1' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
  real_T *Inport2;                     /* '<Root>/Inport2' */
} ExternalUPtrs_Subsystem1_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out;                         /* '<Root>/Out' */
} ExtY_Subsystem1_T;

/* Parameters (auto storage) */
struct P_Subsystem1_T_ {
  real_T AddMux;                       /* Variable: AddMux
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T ContantofPassiveDevice;       /* Variable: ContantofPassiveDevice
                                        * Referenced by:
                                        *   '<S2>/FaultCont'
                                        *   '<S3>/ContantofPassiveDevice'
                                        */
  real_T FaultInjectionTime;           /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec1'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S4>/Step'
                                        */
  real_T FaultType;                    /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultCont1'
                                        *   '<S2>/FaultSelec1'
                                        *   '<S3>/FaultSelec1'
                                        */
  real_T NoiseSelec;                   /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  real_T PerformanceDegradationValue;  /* Variable: PerformanceDegradationValue
                                        * Referenced by: '<S4>/Constant'
                                        */
};

extern P_Subsystem1_T Subsystem1_DefaultP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('CFI20161127/Subsystem1')    - opens subsystem CFI20161127/Subsystem1
 * hilite_system('CFI20161127/Subsystem1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CFI20161127'
 * '<S1>'   : 'CFI20161127/Subsystem1'
 * '<S2>'   : 'CFI20161127/Subsystem1/CFI'
 * '<S3>'   : 'CFI20161127/Subsystem1/Logic Operation'
 * '<S4>'   : 'CFI20161127/Subsystem1/CFI/Aging'
 * '<S5>'   : 'CFI20161127/Subsystem1/CFI/Compare To Constant'
 * '<S6>'   : 'CFI20161127/Subsystem1/Logic Operation/Sauration'
 * '<S7>'   : 'CFI20161127/Subsystem1/Logic Operation/Slope-Sauration'
 */
#endif                                 /* RTW_HEADER_Subsystem1_sf_h_ */
