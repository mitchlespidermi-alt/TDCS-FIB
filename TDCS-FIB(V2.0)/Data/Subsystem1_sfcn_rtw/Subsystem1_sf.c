/*
 * Subsystem1_sf.c
 *
 * Code generation for model "Subsystem1_sf".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Jul 04 15:10:17 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "Subsystem1_sf.h"
#include "Subsystem1_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Subsystem1_malloc(SimStruct *S);

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

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  ((real_T *)ssGetDWork(S, 0))[0] = 0.0;
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Check for invalid switching between solver types */
  if (ssIsVariableStepSolver(S)) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "a solver type of variable-step "
                     "because this S-Function was created from a model with "
                     "solver type of fixed-step and it has continuous time blocks. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

  if (fabs(ssGetFixedStepSize(S) - 1.0E-5) > mxGetEps()*100*1.0E-5) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "the current fixed step size "
                     "because this S-Function was created from a model with "
                     "a fixed step size of 1.0E-5 and had both "
                     "continuous blocks and discrete blocks running at this rate. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

#  endif

  Subsystem1_malloc(S);
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
  real_T rtb_Product_m;
  real_T rtb_FaultSelec1;
  real_T rtb_FaultSelec1_m;
  real_T rtb_Add;
  boolean_T rtb_Compare;
  B_Subsystem1_T *_rtB;
  _rtB = ((B_Subsystem1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Noise0'
     *  Constant: '<S1>/NoiseSelec'
     *  Inport: '<Root>/Inport1'
     */
    if ((*(real_T *)(mxGetData(NoiseSelec(S)))) != 0.0) {
      _rtB->Switch = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
    } else {
      _rtB->Switch = 0.0;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec1' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_FaultSelec1 = 1.0;
    } else {
      rtb_FaultSelec1 = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec1' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Logic: '<S2>/Logical' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    _rtB->Logical = !((*(real_T *)(mxGetData(AddMux(S)))) - 1.0 != 0.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S2>/FaultSelec1' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_FaultSelec1_m = 1.0;
    } else {
      rtb_FaultSelec1_m = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S2>/FaultSelec1' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S2>/FaultCont1' */
    _rtB->FaultCont1 = (*(real_T *)(mxGetData(FaultType(S))));

    /* Constant: '<S2>/FaultCont' */
    _rtB->FaultCont = (*(real_T *)(mxGetData(ContantofPassiveDevice(S))));

    /* Math: '<S4>/Math Function' incorporates:
     *  Constant: '<S4>/Constant'
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
     *  Product: '<S4>/Product'
     *
     * About '<S4>/Math Function':
     *  Operator: exp
     */
    _rtB->MathFunction = exp((*(real_T *)(mxGetData(PerformanceDegradationValue
      (S)))) * ((real_T *)ssGetDWork(S, 0))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
     *  Inport: '<Root>/Inport2'
     *  Inport: '<Root>/Outside Signal1'
     */
    switch ((int32_T)_rtB->FaultCont1) {
     case 2:
      rtb_Product_m = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0];
      break;

     case 3:
      rtb_Product_m = _rtB->FaultCont;
      break;

     case 4:
      rtb_Product_m = _rtB->MathFunction;
      break;

     default:
      rtb_Product_m = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0];
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

    /* Sum: '<S1>/Add' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    rtb_Add = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] +
      rtb_Product_m;

    /* Product: '<S1>/Product' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    rtb_Product_m *= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S3>/ContantofPassiveDevice' */
    _rtB->ContantofPassiveDevice = (*(real_T *)(mxGetData(ContantofPassiveDevice
                                      (S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport Switch1' */
    switch ((int32_T)rtb_FaultSelec1) {
     case 1:
     case 2:
     case 4:
     case 5:
      /* RelationalOperator: '<S5>/Compare' incorporates:
       *  Constant: '<S5>/Constant'
       */
      rtb_Compare = (rtb_FaultSelec1_m == 5.0);

      /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
       *  Constant: '<S2>/Constant3'
       *  Logic: '<S2>/Logical '
       */
      if ((_rtB->Logical && rtb_Compare) == 0) {
        /* MultiPortSwitch: '<S2>/Multiport' incorporates:
         *  Constant: '<S2>/Constant1'
         *  Constant: '<S2>/Constant2'
         *  Logic: '<S2>/Logical Operator'
         */
        switch (((*(real_T *)(mxGetData(AddMux(S)))) - 1.0 != 0.0) &&
                rtb_Compare) {
         case 0:
          break;

         default:
          rtb_FaultSelec1_m = 5.0;
          break;
        }

        /* End of MultiPortSwitch: '<S2>/Multiport' */
      } else {
        rtb_FaultSelec1_m = 2.0;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

      /* MultiPortSwitch: '<S2>/Multiport Switch3' incorporates:
       *  Constant: '<S2>/1'
       *  Constant: '<S2>/2'
       *  Constant: '<S2>/5'
       */
      switch ((int32_T)rtb_FaultSelec1_m) {
       case 2:
        rtb_FaultSelec1 = 1.0;
        break;

       case 1:
        rtb_FaultSelec1 = 5.0;
        break;

       default:
        rtb_FaultSelec1 = 3.0;
        break;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch3' */

      /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
       *  Inport: '<Root>/Nomal'
       */
      switch ((int32_T)rtb_FaultSelec1) {
       case 1:
        /* Saturate: '<S3>/Saturation3' */
        if (rtb_Add > 1.0) {
          rtb_Product_m = 1.0;
        } else if (rtb_Add < 0.0) {
          rtb_Product_m = 0.0;
        } else {
          rtb_Product_m = rtb_Add;
        }

        /* End of Saturate: '<S3>/Saturation3' */
        break;

       case 2:
        /* Saturate: '<S6>/Saturation' */
        if (rtb_Add <= 0.0) {
          rtb_Product_m = 0.0;
        } else {
          rtb_Product_m = rtb_Add;
        }

        /* End of Saturate: '<S6>/Saturation' */
        break;

       case 3:
        /* Saturate: '<S3>/Saturation1' */
        if (rtb_Product_m <= 0.0) {
          rtb_Product_m = 0.0;
        }

        /* End of Saturate: '<S3>/Saturation1' */
        break;

       case 4:
        break;

       default:
        rtb_Product_m = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
        break;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */
      break;

     default:
      rtb_Product_m = _rtB->ContantofPassiveDevice;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch1' */

    /* Outport: '<Root>/Out' incorporates:
     *  Sum: '<S1>/NoiseAdd'
     */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Switch + rtb_Product_m;

    /* Step: '<S4>/Step' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step = 0.0;
    } else {
      _rtB->Step = 1.0;
    }

    /* End of Step: '<S4>/Step' */
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_Subsystem1_T *_rtB;
  _rtB = ((B_Subsystem1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    ((real_T *)ssGetDWork(S, 0))[0] = 1.0E-5 * _rtB->Step + ((real_T *)
      ssGetDWork(S, 0))[0];
  }

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

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'AddMux' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'ContantofPassiveDevice' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultInjectionTime' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultInjectionTime' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultType' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'NoiseSelec' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'PerformanceDegradationValue' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "Subsystem1_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 4))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0);
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
    ssSetInputPortSampleTime(S, 1, 0.0);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 1.0E-5);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 0.0);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 1)) {
    return;
  }

  /* '<S4>/Discrete-Time Integrator': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 6);

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
  ssSetSampleTime(S, 0, 0.0);
  ssSetSampleTime(S, 1, 1.0E-5);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Subsystem1_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
