/*
 * SABF_sf.h
 *
 * Code generation for model "SABF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:16:21 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_SABF_sf_h_
#define RTW_HEADER_SABF_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef SABF_sf_COMMON_INCLUDES_
# define SABF_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                SABF_sf
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
#endif                                 /* SABF_sf_COMMON_INCLUDES_ */

#include "SABF_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T P;                            /* '<Root>/SABF' */
  real_T O;                            /* '<Root>/SABF' */
  real_T N;                            /* '<Root>/SABF' */
} B_SABF_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *SA;                          /* '<Root>/SA' */
  real_T *SB;                          /* '<Root>/SB' */
} ExternalUPtrs_SABF_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *P;                           /* '<Root>/P' */
  real_T *O;                           /* '<Root>/O' */
  real_T *N;                           /* '<Root>/N' */
} ExtY_SABF_T;

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
 * hilite_system('CRH2forBenchmark_Copy/ConverterF/Rectifier/RecSubF/SABF')    - opens subsystem CRH2forBenchmark_Copy/ConverterF/Rectifier/RecSubF/SABF
 * hilite_system('CRH2forBenchmark_Copy/ConverterF/Rectifier/RecSubF/SABF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy/ConverterF/Rectifier/RecSubF'
 * '<S1>'   : 'CRH2forBenchmark_Copy/ConverterF/Rectifier/RecSubF/SABF'
 */
#endif                                 /* RTW_HEADER_SABF_sf_h_ */
