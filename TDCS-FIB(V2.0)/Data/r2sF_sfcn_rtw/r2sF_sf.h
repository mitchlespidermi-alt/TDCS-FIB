/*
 * r2sF_sf.h
 *
 * Code generation for model "r2sF_sf".
 *
 * Model version              : 1.165
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Jul 24 15:35:53 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_r2sF_sf_h_
#define RTW_HEADER_r2sF_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef r2sF_sf_COMMON_INCLUDES_
# define r2sF_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                r2sF_sf
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
#endif                                 /* r2sF_sf_COMMON_INCLUDES_ */

#include "r2sF_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Fcn1;                         /* '<S1>/Fcn1' */
  real_T Fcn;                          /* '<S1>/Fcn' */
} B_r2sF_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Ua;                          /* '<Root>/Ua' */
  real_T *Ub;                          /* '<Root>/Ub' */
  real_T *Uc;                          /* '<Root>/Uc' */
} ExternalUPtrs_r2sF_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Us;                          /* '<Root>/Us¦Á' */
  real_T *Us_p;                        /* '<Root>/Us¦Â' */
} ExtY_r2sF_T;

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
 * hilite_system('CRH2forBenchmark_Copy/Machine model/Normal ModelF/r2sF')    - opens subsystem CRH2forBenchmark_Copy/Machine model/Normal ModelF/r2sF
 * hilite_system('CRH2forBenchmark_Copy/Machine model/Normal ModelF/r2sF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy/Machine model/Normal ModelF'
 * '<S1>'   : 'CRH2forBenchmark_Copy/Machine model/Normal ModelF/r2sF'
 */
#endif                                 /* RTW_HEADER_r2sF_sf_h_ */
