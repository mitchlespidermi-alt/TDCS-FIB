/*
 * IntermediateDClinkF_sf.h
 *
 * Code generation for model "IntermediateDClinkF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:17:59 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_IntermediateDClinkF_sf_h_
#define RTW_HEADER_IntermediateDClinkF_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef IntermediateDClinkF_sf_COMMON_INCLUDES_
# define IntermediateDClinkF_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                IntermediateDClinkF_sf
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
#endif                                 /* IntermediateDClinkF_sf_COMMON_INCLUDES_ */

#include "IntermediateDClinkF_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T MultiportSwitchF[3];          /* '<S1>/Multiport SwitchF' */
  real_T Product3;                     /* '<S1>/Product3' */
  real_T MultiportSwitch1F[3];         /* '<S1>/Multiport Switch1F' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T MultiportSwitch2F[3];         /* '<S1>/Multiport Switch2F' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T Add4;                         /* '<S1>/Add4' */
  real_T Product4;                     /* '<S1>/Product4' */
  real_T Product6;                     /* '<S1>/Product6' */
  real_T Product7;                     /* '<S1>/Product7' */
  real_T Add5;                         /* '<S1>/Add5' */
  real_T Product5;                     /* '<S1>/Product5' */
  real_T Product8;                     /* '<S1>/Product8' */
  real_T Product9;                     /* '<S1>/Product9' */
  real_T Add6;                         /* '<S1>/Add6' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T Compare_p;                 /* '<S4>/Compare' */
  boolean_T Compare_l;                 /* '<S6>/Compare' */
  boolean_T Compare_o;                 /* '<S3>/Compare' */
  boolean_T Compare_k;                 /* '<S5>/Compare' */
  boolean_T Compare_e;                 /* '<S7>/Compare' */
  boolean_T Compare_j;                 /* '<S10>/Compare' */
  boolean_T Compare_g;                 /* '<S9>/Compare' */
  boolean_T Compare_ps;                /* '<S8>/Compare' */
  uint8_T Gain;                        /* '<S1>/Gain' */
  uint8_T Gain3;                       /* '<S1>/Gain3' */
  uint8_T Gain6;                       /* '<S1>/Gain6' */
  uint8_T Gain1;                       /* '<S1>/Gain1' */
  uint8_T Gain2;                       /* '<S1>/Gain2' */
  uint8_T Add1;                        /* '<S1>/Add1' */
  uint8_T Gain4;                       /* '<S1>/Gain4' */
  uint8_T Gain5;                       /* '<S1>/Gain5' */
  uint8_T Add2;                        /* '<S1>/Add2' */
  uint8_T Gain7;                       /* '<S1>/Gain7' */
  uint8_T Gain8;                       /* '<S1>/Gain8' */
  uint8_T Add3;                        /* '<S1>/Add3' */
} B_IntermediateDClinkF_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *In1;                         /* '<Root>/In1' */
  real_T *In2;                         /* '<Root>/In2' */
  real_T *In3;                         /* '<Root>/In3' */
  real_T *In4[3];                      /* '<Root>/In4' */
} ExternalUPtrs_IntermediateDClinkF_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out1;                        /* '<Root>/Out1' */
  real_T *Out4;                        /* '<Root>/Out4' */
  real_T *Out7;                        /* '<Root>/Out7' */
} ExtY_IntermediateDClinkF_T;

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
 * hilite_system('CRH2forBenchmark_Copy/IntermediateDClinkF')    - opens subsystem CRH2forBenchmark_Copy/IntermediateDClinkF
 * hilite_system('CRH2forBenchmark_Copy/IntermediateDClinkF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy'
 * '<S1>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF'
 * '<S2>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/ '
 * '<S3>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/  '
 * '<S4>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/    '
 * '<S5>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/     '
 * '<S6>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/                '
 * '<S7>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/                 '
 * '<S8>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/                2'
 * '<S9>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkF/    2'
 * '<S10>'  : 'CRH2forBenchmark_Copy/IntermediateDClinkF/ 2'
 */
#endif                                 /* RTW_HEADER_IntermediateDClinkF_sf_h_ */
