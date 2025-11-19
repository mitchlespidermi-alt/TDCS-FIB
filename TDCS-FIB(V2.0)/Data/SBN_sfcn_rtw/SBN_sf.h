/*
 * SBN_sf.h
 *
 * Code generation for model "SBN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:23:00 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_SBN_sf_h_
#define RTW_HEADER_SBN_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef SBN_sf_COMMON_INCLUDES_
# define SBN_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                SBN_sf
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
#endif                                 /* SBN_sf_COMMON_INCLUDES_ */

#include "SBN_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T TmpSignalConversionAtBittoInteg[4];
  real_T BittoIntegerConverter;        /* '<S1>/Bit to Integer Converter' */
  real_T MultiportSwitch1;             /* '<S1>/Multiport Switch1' */
  real_T MultiportSwitch3;             /* '<S1>/Multiport Switch3' */
  real_T MultiportSwitch5;             /* '<S1>/Multiport Switch5' */
  real_T MultiportSwitch2;             /* '<S1>/Multiport Switch2' */
  real_T MultiportSwitch4;             /* '<S1>/Multiport Switch4' */
  boolean_T RelationalOperator7;       /* '<S1>/Relational Operator7' */
  boolean_T RelationalOperator4;       /* '<S1>/Relational Operator4' */
  boolean_T RelationalOperator5;       /* '<S1>/Relational Operator5' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T RelationalOperator6;       /* '<S1>/Relational Operator6' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
} B_SBN_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Tb1;                         /* '<Root>/Tb1' */
  real_T *Tb2;                         /* '<Root>/Tb2' */
  real_T *Tb3;                         /* '<Root>/Tb3' */
  real_T *Tb4;                         /* '<Root>/Tb4' */
  real_T *In;                          /* '<Root>/In' */
} ExternalUPtrs_SBN_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *SB;                          /* '<Root>/SB' */
} ExtY_SBN_T;

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
 * hilite_system('CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SBN')    - opens subsystem CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SBN
 * hilite_system('CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SBN/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN'
 * '<S1>'   : 'CRH2forBenchmark_Copy/ConverterN/Rectifier/RecSubN/SBN'
 */
#endif                                 /* RTW_HEADER_SBN_sf_h_ */
