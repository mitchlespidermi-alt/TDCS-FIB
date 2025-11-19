/*
 * MeasurementF_sf.h
 *
 * Code generation for model "MeasurementF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:18:47 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_MeasurementF_sf_h_
#define RTW_HEADER_MeasurementF_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef MeasurementF_sf_COMMON_INCLUDES_
# define MeasurementF_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                MeasurementF_sf
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
#endif                                 /* MeasurementF_sf_COMMON_INCLUDES_ */

#include "MeasurementF_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T NpLm;                         /* '<S1>/Np.Lm' */
  real_T Fcn;                          /* '<S2>/Fcn' */
  real_T Fcn1;                         /* '<S2>/Fcn1' */
  real_T Fcn2;                         /* '<S2>/Fcn2' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T machine;                      /* '<S1>/machine' */
  real_T Product;                      /* '<S1>/Product' */
} B_MeasurementF_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} X_MeasurementF_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} XDot_MeasurementF_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
} XDis_MeasurementF_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *is;                          /* '<Root>/is¦Á' */
  real_T *is_o;                        /* '<Root>/is¦Â' */
  real_T *ir;                          /* '<Root>/ir¦Á' */
  real_T *ir_a;                        /* '<Root>/ir¦Â' */
  real_T *TL;                          /* '<Root>/TL' */
} ExternalUPtrs_MeasurementF_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Te;                          /* '<Root>/Te' */
  real_T *u;                           /* '<Root>/¦Ø' */
  real_T *Isabc[3];                    /* '<Root>/Isabc' */
} ExtY_MeasurementF_T;

/* Parameters (auto storage) */
struct P_MeasurementF_T_ {
  real_T J;                            /* Variable: J
                                        * Referenced by: '<S1>/machine'
                                        */
  real_T Lm;                           /* Variable: Lm
                                        * Referenced by: '<S1>/Np.Lm'
                                        */
  real_T np;                           /* Variable: np
                                        * Referenced by:
                                        *   '<S1>/machine'
                                        *   '<S1>/Np.Lm'
                                        */
};

extern P_MeasurementF_T MeasurementF_DefaultP;

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
 * hilite_system('CRH2forBenchmark_Copy/Machine model/Normal ModelF/MeasurementF')    - opens subsystem CRH2forBenchmark_Copy/Machine model/Normal ModelF/MeasurementF
 * hilite_system('CRH2forBenchmark_Copy/Machine model/Normal ModelF/MeasurementF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark_Copy/Machine model/Normal ModelF'
 * '<S1>'   : 'CRH2forBenchmark_Copy/Machine model/Normal ModelF/MeasurementF'
 * '<S2>'   : 'CRH2forBenchmark_Copy/Machine model/Normal ModelF/MeasurementF/Is2//3'
 */
#endif                                 /* RTW_HEADER_MeasurementF_sf_h_ */
