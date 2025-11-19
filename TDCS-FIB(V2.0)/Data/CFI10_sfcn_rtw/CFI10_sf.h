/*
 * CFI10_sf.h
 *
 * Code generation for model "CFI10_sf".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Apr 08 09:38:52 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_CFI10_sf_h_
#define RTW_HEADER_CFI10_sf_h_
#ifndef CFI10_sf_COMMON_INCLUDES_
# define CFI10_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define S_FUNCTION_NAME                CFI10_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
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
#endif                                 /* CFI10_sf_COMMON_INCLUDES_ */

#include "CFI10_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T FaultCont1;                   /* '<S2>/FaultCont1' */
  real_T FaultCont;                    /* '<S2>/FaultCont' */
  real_T Step;                         /* '<S6>/Step' */
  real_T Clock;                        /* '<S6>/Clock' */
  real_T Constant;                     /* '<S6>/Constant' */
  real_T MultiportSwitch;              /* '<S2>/Multiport Switch' */
  real_T Add;                          /* '<S1>/Add' */
  real_T ContantofPassiveDevice;       /* '<S3>/ContantofPassiveDevice' */
  real_T FaultSelec1;                  /* '<S3>/FaultSelec1' */
  real_T FaultSelec1_n;                /* '<S2>/FaultSelec1' */
  real_T Multiport1;                   /* '<S2>/Multiport1' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T MultiportSwitch1;             /* '<S3>/Multiport Switch1' */
  real_T Switch;                       /* '<S1>/Switch' */
  real_T NoiseAdd;                     /* '<S1>/NoiseAdd' */
  real_T MultiportSwitch2;             /* '<S2>/Multiport Switch2' */
  real_T MultiportSwitch3;             /* '<S2>/Multiport Switch3' */
  real_T MultiportSwitch2_d;           /* '<S3>/Multiport Switch2' */
  real_T Saturation;                   /* '<S7>/Saturation' */
  real_T Multiport;                    /* '<S2>/Multiport' */
  real_T Sum;                          /* '<S6>/Sum' */
  real_T Product;                      /* '<S6>/Product' */
  real_T Output;                       /* '<S6>/Output' */
  boolean_T Logical;                   /* '<S2>/Logical' */
  boolean_T Compare;                   /* '<S5>/Compare' */
  boolean_T Compare_o;                 /* '<S4>/Compare' */
  boolean_T Logical_p;                 /* '<S2>/Logical ' */
  boolean_T LogicalOperator;           /* '<S2>/Logical Operator' */
} B_CFI10_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Nomal;                       /* '<Root>/Nomal' */
  real_T *OutsideSignal1;              /* '<Root>/Outside Signal1' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
  real_T *Inport2;                     /* '<Root>/Inport2' */
} ExternalUPtrs_CFI10_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out;                         /* '<Root>/Out' */
} ExtY_CFI10_T;

/* Parameters (auto storage) */
struct P_CFI10_T_ {
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
                                        *   '<S6>/Constant'
                                        *   '<S6>/Step'
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
                                        * Referenced by: '<S6>/Step'
                                        */
};

extern P_CFI10_T CFI10_DefaultP;

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
 * hilite_system('CFI1/CFI1')    - opens subsystem CFI1/CFI1
 * hilite_system('CFI1/CFI1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CFI1'
 * '<S1>'   : 'CFI1/CFI1'
 * '<S2>'   : 'CFI1/CFI1/CFI'
 * '<S3>'   : 'CFI1/CFI1/Logic Operation'
 * '<S4>'   : 'CFI1/CFI1/CFI/Compare To Constant'
 * '<S5>'   : 'CFI1/CFI1/CFI/Compare To Constant1'
 * '<S6>'   : 'CFI1/CFI1/CFI/Ramp'
 * '<S7>'   : 'CFI1/CFI1/Logic Operation/Sauration'
 * '<S8>'   : 'CFI1/CFI1/Logic Operation/Slope-Sauration'
 */
#endif                                 /* RTW_HEADER_CFI10_sf_h_ */
