/*
 * SFI0_sf.h
 *
 * Code generation for model "SFI0_sf".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 14:43:03 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_SFI0_sf_h_
#define RTW_HEADER_SFI0_sf_h_
#ifndef SFI0_sf_COMMON_INCLUDES_
# define SFI0_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                SFI0_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
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
#endif                                 /* SFI0_sf_COMMON_INCLUDES_ */

#include "SFI0_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T ST_OF_GA_Cont;                /* '<S3>/ST_OF_GA_Cont' */
  real_T Constant;                     /* '<S9>/Constant' */
  real_T Constant1;                    /* '<S9>/Constant1' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Constant_f;                   /* '<S5>/Constant' */
  real_T FaultCont;                    /* '<S2>/FaultCont' */
  real_T Multiport1;                   /* '<S3>/Multiport1' */
  real_T Switch;                       /* '<S1>/Switch' */
  boolean_T LogicalOperator;           /* '<S8>/Logical Operator' */
  boolean_T Logical;                   /* '<S3>/Logical' */
} B_SFI0_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Nomal;                       /* '<Root>/Nomal' */
  real_T *OutsideSignal;               /* '<Root>/Outside Signal' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
  real_T *Inport2;                     /* '<Root>/Inport2' */
} ExternalUPtrs_SFI0_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out;                         /* '<Root>/Out' */
} ExtY_SFI0_T;

/* Parameters (auto storage) */
struct P_SFI0_T_ {
  real_T AddMux;                       /* Variable: AddMux
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Comp_ConV;                    /* Variable: Comp_ConV
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T DriftFault[2];                /* Variable: DriftFault
                                        * Referenced by:
                                        *   '<S9>/Constant1'
                                        *   '<S9>/Step'
                                        */
  real_T FaultCont;                    /* Variable: FaultCont
                                        * Referenced by:
                                        *   '<S2>/FaultCont'
                                        *   '<S3>/ST_OF_GA_Cont'
                                        */
  real_T FaultInjectionTime;           /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Shock_Fault'
                                        *   '<S9>/Constant'
                                        *   '<S9>/Step'
                                        */
  real_T FaultType;                    /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S8>/FaultType'
                                        */
  real_T NoiseSelec;                   /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  real_T ShockGain;                    /* Variable: ShockGain
                                        * Referenced by: '<S3>/Shock_Fault'
                                        */
  real_T Variance;                     /* Variable: Variance
                                        * Referenced by: '<S3>/Random Number'
                                        */
};

extern P_SFI0_T SFI0_DefaultP;

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
 * hilite_system('SFI/SFI')    - opens subsystem SFI/SFI
 * hilite_system('SFI/SFI/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SFI'
 * '<S1>'   : 'SFI/SFI'
 * '<S2>'   : 'SFI/SFI/MuxCompare'
 * '<S3>'   : 'SFI/SFI/SFI'
 * '<S4>'   : 'SFI/SFI/MuxCompare/AddComp'
 * '<S5>'   : 'SFI/SFI/MuxCompare/AddComp/Min'
 * '<S6>'   : 'SFI/SFI/SFI/Compare To Constant'
 * '<S7>'   : 'SFI/SFI/SFI/Compare To Constant1'
 * '<S8>'   : 'SFI/SFI/SFI/NO_SH_OP'
 * '<S9>'   : 'SFI/SFI/SFI/Ramp_Fault'
 * '<S10>'  : 'SFI/SFI/SFI/NO_SH_OP/Compare To Constant'
 * '<S11>'  : 'SFI/SFI/SFI/NO_SH_OP/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_SFI0_sf_h_ */
