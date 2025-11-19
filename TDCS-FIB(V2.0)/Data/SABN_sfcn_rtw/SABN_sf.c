/*
 * SABN_sf.c
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
#include <math.h>
#include "SABN_sf.h"
#include "SABN_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *SABN_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  SABN_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  B_SABN_T *_rtB;
  _rtB = ((B_SABN_T *) ssGetLocalBlockIO(S));

  /* MATLAB Function: '<Root>/SABN' incorporates:
   *  Inport: '<Root>/SA'
   *  Inport: '<Root>/SB'
   */
  /* MATLAB Function 'SABN': '<S1>:1' */
  /* '<S1>:1:3' */
  _rtB->P = 0.0;

  /* '<S1>:1:3' */
  _rtB->O = 0.0;

  /* '<S1>:1:3' */
  _rtB->N = 0.0;
  if (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == *((const real_T **)
       ssGetInputPortSignalPtrs(S, 1))[0]) {
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    _rtB->P = 0.0;

    /* '<S1>:1:5' */
    _rtB->O = 0.0;

    /* '<S1>:1:5' */
    _rtB->N = 0.0;
  } else if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == 1.0) && (*
              ((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == 0.0)) {
    /* '<S1>:1:7' */
    /* '<S1>:1:8' */
    _rtB->P = 1.0;

    /* '<S1>:1:8' */
    _rtB->O = -1.0;

    /* '<S1>:1:8' */
    _rtB->N = 0.0;
  } else if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == 1.0) && (*
              ((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == -1.0)) {
    /* '<S1>:1:10' */
    /* '<S1>:1:11' */
    _rtB->P = 1.0;

    /* '<S1>:1:11' */
    _rtB->O = 0.0;

    /* '<S1>:1:11' */
    _rtB->N = -1.0;
  } else if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == 0.0) && (*
              ((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == 1.0)) {
    /* '<S1>:1:13' */
    /* '<S1>:1:14' */
    _rtB->P = -1.0;

    /* '<S1>:1:14' */
    _rtB->O = 1.0;

    /* '<S1>:1:14' */
    _rtB->N = 0.0;
  } else if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == 0.0) && (*
              ((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == -1.0)) {
    /* '<S1>:1:16' */
    /* '<S1>:1:17' */
    _rtB->P = 0.0;

    /* '<S1>:1:17' */
    _rtB->O = 1.0;

    /* '<S1>:1:17' */
    _rtB->N = -1.0;
  } else if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == -1.0) &&
             (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == 1.0)) {
    /* '<S1>:1:19' */
    /* '<S1>:1:20' */
    _rtB->P = -1.0;

    /* '<S1>:1:20' */
    _rtB->O = 0.0;

    /* '<S1>:1:20' */
    _rtB->N = 1.0;
  } else {
    if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == -1.0) && (*((
           const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] == 0.0)) {
      /* '<S1>:1:22' */
      /* '<S1>:1:23' */
      _rtB->P = 0.0;

      /* '<S1>:1:23' */
      _rtB->O = -1.0;

      /* '<S1>:1:23' */
      _rtB->N = 1.0;
    }
  }

  /* End of MATLAB Function: '<Root>/SABN' */

  /* Outport: '<Root>/P' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->P;

  /* Outport: '<Root>/O' */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->O;

  /* Outport: '<Root>/N' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->N;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "SABN_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 3))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 2))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 1.0E-5);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 1.0E-5);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 1.0E-5);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               SABN_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
