/*
 * SABN_sf.h
 *
 * Code generation for model "SABN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:23:20 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_SABN_sf_h_
#define RTW_HEADER_SABN_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef SABN_sf_COMMON_INCLUDES_
# define SABN_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                SABN_sf
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
#endif                                 /* SABN_sf_COMMON_INCLUDES_ */

#include "SABN_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T P;                            /* '<Root>/SABN' */
  real_T O;                            /* '<Root>/SABN' */
  real_T N;                            /* '<Root>/SABN' */
} B_SABN_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *SA;                          /* '<Root>/SA' */
  real_T *SB;                          /* '<Root>/SB' */
} ExternalUPtrs_SABN_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *P;                           /* '<Root>/P' */
  real_T *O;                           /* '<Root>/O' */
  real_T *N;                           /* '<Root>/N' */
} ExtY_SABN_T;

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
 * hilite_system('CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SABN')    - opens subsystem CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SABN
 * hilite_system('CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SABN/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN'
 * '<S1>'   : 'CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SABN'
 */
#endif                                 /* RTW_HEADER_SABN_sf_h_ */
