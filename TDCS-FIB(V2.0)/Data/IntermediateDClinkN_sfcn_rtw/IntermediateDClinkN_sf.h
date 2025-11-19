/*
 * IntermediateDClinkN_sf.h
 *
 * Code generation for model "IntermediateDClinkN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:25:25 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_IntermediateDClinkN_sf_h_
#define RTW_HEADER_IntermediateDClinkN_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef IntermediateDClinkN_sf_COMMON_INCLUDES_
# define IntermediateDClinkN_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                IntermediateDClinkN_sf
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
#endif                                 /* IntermediateDClinkN_sf_COMMON_INCLUDES_ */

#include "IntermediateDClinkN_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T MultiportSwitch[3];           /* '<S1>/Multiport Switch' */
  real_T Product3;                     /* '<S1>/Product3' */
  real_T MultiportSwitch1[3];          /* '<S1>/Multiport Switch1' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T MultiportSwitch2[3];          /* '<S1>/Multiport Switch2' */
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
  boolean_T Compare_n;                 /* '<S4>/Compare' */
  boolean_T Compare_g;                 /* '<S6>/Compare' */
  boolean_T Compare_h;                 /* '<S3>/Compare' */
  boolean_T Compare_ns;                /* '<S5>/Compare' */
  boolean_T Compare_k;                 /* '<S7>/Compare' */
  boolean_T Compare_p;                 /* '<S10>/Compare' */
  boolean_T Compare_i;                 /* '<S9>/Compare' */
  boolean_T Compare_b;                 /* '<S8>/Compare' */
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
} B_IntermediateDClinkN_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *In1;                         /* '<Root>/In1' */
  real_T *In2;                         /* '<Root>/In2' */
  real_T *In3;                         /* '<Root>/In3' */
  real_T *In4[3];                      /* '<Root>/In4' */
} ExternalUPtrs_IntermediateDClinkN_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out1;                        /* '<Root>/Out1' */
  real_T *Out4;                        /* '<Root>/Out4' */
  real_T *Out7;                        /* '<Root>/Out7' */
} ExtY_IntermediateDClinkN_T;

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
 * hilite_system('CRH2forBenchmark_Copy/IntermediateDClinkN')    - opens subsystem CRH2forBenchmark_Copy/IntermediateDClinkN
 * hilite_system('CRH2forBenchmark_Copy/IntermediateDClinkN/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy'
 * '<S1>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN'
 * '<S2>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/ '
 * '<S3>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/  '
 * '<S4>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/    '
 * '<S5>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/     '
 * '<S6>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/                '
 * '<S7>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/                 '
 * '<S8>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/                2'
 * '<S9>'   : 'CRH2forBenchmark_Copy/IntermediateDClinkN/    2'
 * '<S10>'  : 'CRH2forBenchmark_Copy/IntermediateDClinkN/ 2'
 */
#endif                                 /* RTW_HEADER_IntermediateDClinkN_sf_h_ */
