/*
 * DCU1_sf.c
 *
 * Code generation for model "DCU1_sf".
 *
 * Model version              : 1.77
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Oct 31 17:21:50 2016
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
#include "DCU1_sf.h"
#include "DCU1_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *DCU1_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static real_T DCU1_rt_hypotd_snf(real_T u0, real_T u1);
static real_T DCU1_rt_atan2d_snf(real_T u0, real_T u1);
static real_T DCU1_rt_roundd_snf(real_T u);
static real_T DCU1_rt_remd_snf(real_T u0, real_T u1);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";
real_T DCU1_look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

static real_T DCU1_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  real_T b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

static real_T DCU1_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static real_T DCU1_rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static real_T DCU1_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T y_0;
  real_T u;
  boolean_T y_1;
  u = u0;
  y_0 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
  u = u1;
  y_1 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
  if (!(y_0 && y_1)) {
    y = (rtNaN);
  } else {
    u = u1;
    if (u < 0.0) {
      u = ceil(u);
    } else {
      u = floor(u);
    }

    if ((u1 != 0.0) && (u1 != u)) {
      u = u0 / u1;
      if (fabs(u - DCU1_rt_roundd_snf(u)) <= DBL_EPSILON * fabs(u)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  ((real_T *)ssGetDWork(S, 0))[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
  ((real_T *)ssGetDWork(S, 1))[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Integrator' */
  ((real_T *)ssGetDWork(S, 2))[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
  ((real_T *)ssGetDWork(S, 3))[0] = 0.0;
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

  DCU1_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    B_DCU1_T *_rtB;
    _rtB = ((B_DCU1_T *) ssGetLocalBlockIO(S));

    /* Start for Constant: '<S10>/Ts' */
    _rtB->Ts = (*(real_T *)(mxGetData(Ts(S))));
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T A;
  int32_T i;
  real_T u1;
  real_T u2;
  B_DCU1_T *_rtB;
  _rtB = ((B_DCU1_T *) ssGetLocalBlockIO(S));
  if (ssIsContinuousTask(S, tid)) {
    /* Gain: '<S2>/Gain' incorporates:
     *  Inport: '<Root>/Inport8'
     */
    A = 3.036 * (*(real_T *)(mxGetData(np(S))));
    A = 2.952 / A;
    _rtB->Gain = A * *((const real_T **)ssGetInputPortSignalPtrs(S, 8))[0];
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S65>/Constant1' */
    _rtB->Constant1 = (*(real_T *)(mxGetData(Vge(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sum: '<S65>/Sum' */
    _rtB->Sum = _rtB->Constant1 - _rtB->Gain;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* RelationalOperator: '<S64>/Compare' incorporates:
     *  Constant: '<S64>/Constant'
     *  Inport: '<Root>/Commander'
     */
    _rtB->Compare = (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] ==
                     2.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/C'
     */
    if (_rtB->Compare) {
      /* RelationalOperator: '<S72>/Compare' incorporates:
       *  Constant: '<S72>/Constant'
       */
      _rtB->Compare_c = (_rtB->Sum <= (-5.0));

      /* Gain: '<S68>/Gain1' */
      _rtB->Gain1_n = _rtB->Compare_c ? (real_T)((uint8_T)128U) * 0.015625 : 0.0;

      /* RelationalOperator: '<S71>/Compare' incorporates:
       *  Constant: '<S71>/Constant'
       */
      _rtB->Compare_o = (_rtB->Sum >= 5.0);

      /* Gain: '<S68>/Gain' */
      _rtB->Gain_dk = _rtB->Compare_o ? (real_T)((uint8_T)128U) * 0.0078125 :
        0.0;

      /* Sum: '<S68>/Add' */
      _rtB->Add_oh = _rtB->Gain_dk + _rtB->Gain1_n;

      /* Sum: '<S68>/Add1' incorporates:
       *  Constant: '<S68>/Constant1'
       */
      _rtB->Add1_n = 1.0 + _rtB->Add_oh;
      _rtB->Switch = _rtB->Add1_n;
    } else {
      _rtB->Switch = 1.0;
    }

    /* End of Switch: '<S11>/Switch' */

    /* MultiPortSwitch: '<S11>/Multiport Switch 1' incorporates:
     *  Constant: '<S11>/Braking'
     *  Constant: '<S11>/Traction'
     *  Inport: '<Root>/Commander'
     */
    switch ((int32_T)_rtB->Switch) {
     case 1:
      _rtB->MultiportSwitch1 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
        [0];
      break;

     case 2:
      _rtB->MultiportSwitch1 = 3.0;
      break;

     default:
      _rtB->MultiportSwitch1 = 4.0;
      break;
    }

    /* End of MultiPortSwitch: '<S11>/Multiport Switch 1' */

    /* RelationalOperator: '<S76>/Compare' incorporates:
     *  Constant: '<S76>/Constant'
     */
    _rtB->Compare_n = (_rtB->Sum < 5.0);

    /* RelationalOperator: '<S77>/Compare' incorporates:
     *  Constant: '<S77>/Constant'
     */
    _rtB->Compare_n5 = (_rtB->Sum > 1.0);

    /* Logic: '<S70>/Logical Operator2' */
    _rtB->LogicalOperator2 = (_rtB->Compare_n && _rtB->Compare_n5);

    /* Gain: '<S70>/Gain' */
    _rtB->Gain_c = _rtB->LogicalOperator2 ? (real_T)((uint8_T)128U) * 0.0078125 :
      0.0;

    /* RelationalOperator: '<S78>/Compare' incorporates:
     *  Constant: '<S78>/Constant'
     */
    _rtB->Compare_f = (_rtB->Sum <= 1.0);

    /* RelationalOperator: '<S79>/Compare' incorporates:
     *  Constant: '<S79>/Constant'
     */
    _rtB->Compare_e = (_rtB->Sum > 0.0);

    /* Logic: '<S70>/Logical Operator3' */
    _rtB->LogicalOperator3 = (_rtB->Compare_f && _rtB->Compare_e);

    /* Gain: '<S70>/Gain1' */
    _rtB->Gain1 = _rtB->LogicalOperator3 ? (real_T)((uint8_T)128U) * 0.015625 :
      0.0;

    /* RelationalOperator: '<S82>/Compare' incorporates:
     *  Constant: '<S82>/Constant'
     */
    _rtB->Compare_ew = (_rtB->Sum <= 0.0);

    /* RelationalOperator: '<S83>/Compare' incorporates:
     *  Constant: '<S83>/Constant'
     */
    _rtB->Compare_k = (_rtB->Sum > (-2.0));

    /* Logic: '<S70>/Logical Operator1' */
    _rtB->LogicalOperator1 = (_rtB->Compare_ew && _rtB->Compare_k);

    /* Gain: '<S70>/Gain3' */
    _rtB->Gain3 = _rtB->LogicalOperator1 ? (real_T)((uint8_T)192U) * 0.015625 :
      0.0;

    /* RelationalOperator: '<S80>/Compare' incorporates:
     *  Constant: '<S80>/Constant'
     */
    _rtB->Compare_p = (_rtB->Sum <= (-2.0));

    /* RelationalOperator: '<S81>/Compare' incorporates:
     *  Constant: '<S81>/Constant'
     */
    _rtB->Compare_b = (_rtB->Sum > (-5.0));

    /* Logic: '<S70>/Logical Operator' */
    _rtB->LogicalOperator = (_rtB->Compare_p && _rtB->Compare_b);

    /* Gain: '<S70>/Gain2' */
    _rtB->Gain2 = _rtB->LogicalOperator ? (real_T)((uint8_T)128U) * 0.03125 :
      0.0;

    /* Sum: '<S70>/Add' */
    _rtB->Add = ((_rtB->Gain_c + _rtB->Gain1) + _rtB->Gain3) + _rtB->Gain2;

    /* Sum: '<S70>/Add1' incorporates:
     *  Constant: '<S70>/Constant'
     */
    _rtB->Add1 = _rtB->Add + 1.0;

    /* RelationalOperator: '<S73>/Compare' incorporates:
     *  Constant: '<S73>/Constant'
     */
    _rtB->Compare_h = (_rtB->Add1 == 4.0);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Sum: '<S84>/Add 1' incorporates:
     *  Constant: '<S84>/Constant4'
     *  Constant: '<S84>/Constant5'
     */
    _rtB->Add1_m = (*(real_T *)(mxGetData(Vge(S)))) - 5.0;

    /* Product: '<S84>/Divide 1' incorporates:
     *  Constant: '<S84>/Constant3'
     */
    _rtB->Divide1 = 1.625E+7 / _rtB->Add1_m;

    /* Product: '<S84>/Product2' incorporates:
     *  Constant: '<S84>/Constant2'
     */
    _rtB->Product2 = _rtB->Add1_m * 360.0;

    /* Sum: '<S84>/Add' incorporates:
     *  Constant: '<S84>/Constant1'
     */
    _rtB->Add_m = 176000.0 - _rtB->Product2;

    /* Switch: '<S84>/Switch' */
    if (_rtB->Add1_m > 125.0) {
      _rtB->Switch_g = _rtB->Divide1;
    } else {
      _rtB->Switch_g = _rtB->Add_m;
    }

    /* End of Switch: '<S84>/Switch' */

    /* Product: '<S84>/Product 1' incorporates:
     *  Constant: '<S84>/d'
     */
    _rtB->Product1 = _rtB->Switch_g * 0.82;

    /* Product: '<S84>/Divide' */
    _rtB->Divide = _rtB->Product1 / DCU1_rtC(S)->Product;

    /* Sum: '<S75>/Add2' incorporates:
     *  Constant: '<S75>/Constant6'
     *  Constant: '<S75>/Constant8'
     */
    _rtB->Add2 = (*(real_T *)(mxGetData(Vge(S)))) - 5.0;

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/Constant1'
     */
    if (_rtB->Add2 > 70.0) {
      /* Sum: '<S75>/Add' incorporates:
       *  Constant: '<S75>/Constant3'
       *  Constant: '<S75>/Constant8'
       */
      _rtB->Add_op = 70.0 - (*(real_T *)(mxGetData(Vge(S))));

      /* Product: '<S75>/Divide1' incorporates:
       *  Constant: '<S75>/Constant2'
       */
      _rtB->Divide1_c = 1.0 / 2.0 * _rtB->Add_op;

      /* Sum: '<S75>/Add1' incorporates:
       *  Constant: '<S75>/Constant4'
       */
      _rtB->Add1_o = _rtB->Divide1_c + 172.0;

      /* Product: '<S75>/Divide2' incorporates:
       *  Constant: '<S75>/Constant5'
       */
      _rtB->Divide2 = 1000.0 * _rtB->Add1_o;
      _rtB->Switch_o = _rtB->Divide2;
    } else {
      _rtB->Switch_o = 172000.0;
    }

    /* End of Switch: '<S75>/Switch' */

    /* Product: '<S75>/Product1' incorporates:
     *  Constant: '<S75>/d'
     */
    _rtB->Product1_b = _rtB->Switch_o * 0.82;

    /* Product: '<S75>/Divide' */
    _rtB->Divide_c = _rtB->Product1_b / DCU1_rtC(S)->Product_k;

    /* Product: '<S75>/Product2' incorporates:
     *  Constant: '<S75>/Constant7'
     */
    _rtB->Product2_h = _rtB->Divide_c * (-1.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S65>/Constant2 '
     */
    if (_rtB->Compare_h) {
      _rtB->Switch_j = 0.0;
    } else {
      /* MultiPortSwitch: '<S68>/Multiport Switch' incorporates:
       *  Constant: '<S68>/Constant'
       *  Constant: '<S68>/Constant2'
       */
      switch ((int32_T)_rtB->Add1) {
       case 1:
        _rtB->MultiportSwitch_i = 1.0;
        break;

       case 2:
        /* Sum: '<S74>/Add 2' incorporates:
         *  Constant: '<S74>/Constant'
         */
        _rtB->Add2_d = _rtB->Sum - 1.0;

        /* Sum: '<S74>/Add 1' incorporates:
         *  Inport: '<Root>/Inport6'
         */
        _rtB->Add1_fc = _rtB->Divide - *((const real_T **)
          ssGetInputPortSignalPtrs(S, 6))[0];

        /* Product: '<S74>/Divide1' incorporates:
         *  Constant: '<S74>/Constant1'
         */
        _rtB->Divide1_j = _rtB->Add1_fc * _rtB->Add2_d / 4.0;

        /* Sum: '<S74>/Add3' incorporates:
         *  Inport: '<Root>/Inport6'
         */
        _rtB->Add3_e = *((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0] +
          _rtB->Divide1_j;
        _rtB->MultiportSwitch_i = _rtB->Add3_e;
        break;

       case 3:
        /* Product: '<S68>/Product' incorporates:
         *  Inport: '<Root>/Inport6'
         */
        _rtB->Product_k = _rtB->Sum * *((const real_T **)
          ssGetInputPortSignalPtrs(S, 6))[0];
        _rtB->MultiportSwitch_i = _rtB->Product_k;
        break;

       case 4:
        _rtB->MultiportSwitch_i = 0.0;
        break;

       default:
        /* Sum: '<S69>/Add1' incorporates:
         *  Constant: '<S69>/Constant'
         */
        _rtB->Add1_i = _rtB->Sum + 2.0;

        /* Product: '<S69>/Divide2' incorporates:
         *  Constant: '<S69>/Constant1'
         */
        _rtB->Divide2_c = _rtB->Product2_h * _rtB->Add1_i / 3.0;
        _rtB->MultiportSwitch_i = _rtB->Divide2_c;
        break;
      }

      /* End of MultiPortSwitch: '<S68>/Multiport Switch' */
      _rtB->Switch_j = _rtB->MultiportSwitch_i;
    }

    /* End of Switch: '<S65>/Switch' */

    /* Saturate: '<S67>/Saturation' */
    A = _rtB->Gain;
    if ((A <= 1.0) || rtIsNaN(1.0)) {
      _rtB->Saturation = 1.0;
    } else {
      _rtB->Saturation = A;
    }

    /* End of Saturate: '<S67>/Saturation' */

    /* Switch: '<S67>/Switch' */
    if (_rtB->Saturation > 125.0) {
      /* Product: '<S67>/Divide1' incorporates:
       *  Constant: '<S67>/Constant3'
       */
      _rtB->Divide1_h = 1.625E+7 / _rtB->Saturation;
      _rtB->Switch_n = _rtB->Divide1_h;
    } else {
      /* Product: '<S67>/Product2' incorporates:
       *  Constant: '<S67>/Constant2'
       */
      _rtB->Product2_m = _rtB->Saturation * 360.0;

      /* Sum: '<S67>/Add' incorporates:
       *  Constant: '<S67>/Constant1'
       */
      _rtB->Add_of = 176000.0 - _rtB->Product2_m;
      _rtB->Switch_n = _rtB->Add_of;
    }

    /* End of Switch: '<S67>/Switch' */

    /* Product: '<S67>/Product1' incorporates:
     *  Constant: '<S67>/d'
     */
    _rtB->Product1_h = _rtB->Switch_n * 0.82;

    /* Product: '<S67>/Divide ' */
    _rtB->Divide_k = _rtB->Product1_h / DCU1_rtC(S)->Product_d;

    /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
     *  Constant: '<S11>/Constant 1'
     */
    switch ((int32_T)_rtB->MultiportSwitch1) {
     case 1:
      _rtB->MultiportSwitch = 0.0;
      break;

     case 2:
      _rtB->MultiportSwitch = _rtB->Switch_j;
      break;

     case 3:
      _rtB->MultiportSwitch = _rtB->Divide_k;
      break;

     default:
      /* Switch: '<S62>/Switch' incorporates:
       *  Constant: '<S62>/Constant1'
       */
      if (_rtB->Gain > 70.0) {
        /* Sum: '<S62>/Add' incorporates:
         *  Constant: '<S62>/Constant3'
         */
        _rtB->Add_j = 70.0 - _rtB->Gain;

        /* Product: '<S62>/Divide1' incorporates:
         *  Constant: '<S62>/Constant2'
         */
        _rtB->Divide1_g = 1.0 / 2.0 * _rtB->Add_j;

        /* Sum: '<S62>/Add1' incorporates:
         *  Constant: '<S62>/Constant4'
         */
        _rtB->Add1_g = _rtB->Divide1_g + 172.0;

        /* Product: '<S62>/Divide2' incorporates:
         *  Constant: '<S62>/Constant5'
         */
        _rtB->Divide2_f = 1000.0 * _rtB->Add1_g;
        _rtB->Switch_jh = _rtB->Divide2_f;
      } else {
        _rtB->Switch_jh = 172000.0;
      }

      /* End of Switch: '<S62>/Switch' */

      /* Product: '<S62>/Product1' incorporates:
       *  Constant: '<S62>/d'
       */
      _rtB->Product1_c = _rtB->Switch_jh * 0.82;

      /* Product: '<S62>/Divide' */
      _rtB->Divide_l = _rtB->Product1_c / DCU1_rtC(S)->Product_dd;

      /* Product: '<S62>/Divide3' incorporates:
       *  Constant: '<S62>/Constant6'
       */
      _rtB->Divide3 = _rtB->Divide_l * (-1.0);
      _rtB->MultiportSwitch = _rtB->Divide3;
      break;
    }

    /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

    /* Saturate: '<S9>/Saturation' */
    A = _rtB->Gain;
    if ((A <= 1.0) || rtIsNaN(1.0)) {
      _rtB->Saturation_h = 1.0;
    } else {
      _rtB->Saturation_h = A;
    }

    /* End of Saturate: '<S9>/Saturation' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S9>/perpetual' */
    _rtB->perpetual = (*(real_T *)(mxGetData(phir(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* RelationalOperator: '<S63>/Compare' incorporates:
     *  Constant: '<S63>/Constant'
     */
    _rtB->Compare_bb = (_rtB->MultiportSwitch1 > 3.0);

    /* Switch: '<S9>/Switch1' incorporates:
     *  Switch: '<S9>/Switch2'
     */
    if (_rtB->Compare_bb) {
      /* Switch: '<S9>/Switch' */
      if (_rtB->Saturation_h > 200.0) {
        /* Fcn: '<S9>/Fcn' */
        _rtB->Fcn_i = 371.52 / _rtB->Saturation_h;
        _rtB->Switch_jhq = _rtB->Fcn_i;
      } else {
        _rtB->Switch_jhq = _rtB->perpetual;
      }

      /* End of Switch: '<S9>/Switch' */
      _rtB->Switch1 = _rtB->Switch_jhq;
    } else {
      if (_rtB->Saturation_h > 175.0) {
        /* Fcn: '<S9>/Fcn1' incorporates:
         *  Switch: '<S9>/Switch2'
         */
        _rtB->Fcn1_i = 325.08 / _rtB->Saturation_h;

        /* Switch: '<S9>/Switch2' */
        _rtB->Switch2 = _rtB->Fcn1_i;
      } else {
        /* Switch: '<S9>/Switch2' */
        _rtB->Switch2 = _rtB->perpetual;
      }

      _rtB->Switch1 = _rtB->Switch2;
    }

    /* End of Switch: '<S9>/Switch1' */

    /* Fcn: '<S12>/Fcn' */
    _rtB->Fcn = 2.0 * _rtB->MultiportSwitch * 0.034142000000000006 / (0.197088 *
      _rtB->Switch1);

    /* Fcn: '<S12>/Fcn1' */
    _rtB->Fcn1 = 2.0 * _rtB->Switch1 / 0.098544;

    /* Fcn: '<S12>/Fcn2' */
    _rtB->Fcn2 = _rtB->Fcn * 0.146 / (0.034142000000000006 * _rtB->Fcn1);

    /* Gain: '<S7>/Gain' incorporates:
     *  Inport: '<Root>/Inport8'
     */
    _rtB->Gain_h = 2.0 * *((const real_T **)ssGetInputPortSignalPtrs(S, 8))[0];

    /* Sum: '<S7>/Sum1' */
    _rtB->Sum1 = _rtB->Fcn2 + _rtB->Gain_h;

    /* Fcn: '<S13>/Fcn1' */
    _rtB->Fcn1_c = _rtB->Sum1 * _rtB->Fcn1 * 0.0342654 + 0.114 * _rtB->Fcn;

    /* Fcn: '<S15>/C1' incorporates:
     *  Inport: '<Root>/Inport7'
     */
    _rtB->C1 = ((*((const real_T **)ssGetInputPortSignalPtrs(S, 7))[0] - *((
      const real_T **)ssGetInputPortSignalPtrs(S, 7))[1] / 2.0) - *((const
      real_T **)ssGetInputPortSignalPtrs(S, 7))[2] / 2.0) * 0.816496580927726;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    _rtB->DiscreteTimeIntegrator = ((real_T *)ssGetDWork(S, 0))[0];

    /* Trigonometry: '<S14>/Trigonometric Function' */
    _rtB->TrigonometricFunction = cos(_rtB->DiscreteTimeIntegrator);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S14>/Product' */
    _rtB->Product = _rtB->C1 * _rtB->TrigonometricFunction;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Trigonometry: '<S14>/Trigonometric Function1' */
    _rtB->TrigonometricFunction1 = sin(_rtB->DiscreteTimeIntegrator);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Fcn: '<S15>/C2' incorporates:
     *  Inport: '<Root>/Inport7'
     */
    _rtB->C2 = ((0.0 * *((const real_T **)ssGetInputPortSignalPtrs(S, 7))[0] +
                 0.8660254037844386 * *((const real_T **)
      ssGetInputPortSignalPtrs(S, 7))[1]) - 0.8660254037844386 * *((const real_T
      **)ssGetInputPortSignalPtrs(S, 7))[2]) * 0.816496580927726;

    /* Product: '<S14>/Product3' */
    _rtB->Product3 = _rtB->TrigonometricFunction1 * _rtB->C2;

    /* Sum: '<S14>/Add' */
    _rtB->Add_o = _rtB->Product + _rtB->Product3;

    /* Sum: '<S16>/Sum' */
    _rtB->Sum_g = _rtB->Fcn1 - _rtB->Add_o;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S18>/Proportional Gain' */
    _rtB->ProportionalGain = (*(real_T *)(mxGetData(KPM(S)))) * _rtB->Sum_g;

    /* Gain: '<S18>/Integral Gain' */
    _rtB->IntegralGain = (*(real_T *)(mxGetData(KIM(S)))) * _rtB->Sum_g;

    /* DiscreteIntegrator: '<S18>/Integrator' */
    _rtB->Integrator = 5.0E-6 * _rtB->IntegralGain + ((real_T *)ssGetDWork(S, 1))
      [0];

    /* Sum: '<S18>/Sum' */
    _rtB->Sum_m = _rtB->ProportionalGain + _rtB->Integrator;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sum: '<S2>/Sum1' */
    _rtB->Sum1_l = _rtB->Fcn1_c + _rtB->Sum_m;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Trigonometry: '<S4>/Trigonometric Function' */
    _rtB->TrigonometricFunction_i = cos(_rtB->DiscreteTimeIntegrator);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S4>/Product' */
    _rtB->Product_o = _rtB->Sum1_l * _rtB->TrigonometricFunction_i;

    /* Fcn: '<S13>/Fcn' */
    _rtB->Fcn_o = 0.114 * _rtB->Fcn1 - _rtB->Sum1 * 0.0342654 * _rtB->Fcn *
      0.077698106842771564;

    /* Product: '<S14>/Product2' */
    _rtB->Product2_e = _rtB->TrigonometricFunction * _rtB->C2;

    /* Product: '<S14>/Product1' */
    _rtB->Product1_k = _rtB->TrigonometricFunction1 * _rtB->C1;

    /* Sum: '<S14>/Add1' */
    _rtB->Add1_p = _rtB->Product2_e - _rtB->Product1_k;

    /* Sum: '<S17>/Sum' */
    _rtB->Sum_g4 = _rtB->Fcn - _rtB->Add1_p;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S19>/Proportional Gain' */
    _rtB->ProportionalGain_g = (*(real_T *)(mxGetData(KPT(S)))) * _rtB->Sum_g4;

    /* Gain: '<S19>/Integral Gain' */
    _rtB->IntegralGain_o = (*(real_T *)(mxGetData(KIT(S)))) * _rtB->Sum_g4;

    /* DiscreteIntegrator: '<S19>/Integrator' */
    _rtB->Integrator_b = 5.0E-6 * _rtB->IntegralGain_o + ((real_T *)ssGetDWork(S,
      2))[0];

    /* Sum: '<S19>/Sum' */
    _rtB->Sum_b = _rtB->ProportionalGain_g + _rtB->Integrator_b;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sum: '<S2>/Sum' */
    _rtB->Sum_i = _rtB->Fcn_o + _rtB->Sum_b;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Trigonometry: '<S4>/Trigonometric Function1' */
    _rtB->TrigonometricFunction1_m = sin(_rtB->DiscreteTimeIntegrator);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S4>/Product3' */
    _rtB->Product3_k = _rtB->Sum_i * _rtB->TrigonometricFunction1_m;

    /* Sum: '<S4>/Add' */
    _rtB->Add_h = _rtB->Product_o - _rtB->Product3_k;

    /* Product: '<S4>/Product1' */
    _rtB->Product1_m = _rtB->Sum_i * _rtB->TrigonometricFunction_i;

    /* Product: '<S4>/Product2' */
    _rtB->Product2_d = _rtB->Sum1_l * _rtB->TrigonometricFunction1_m;

    /* Sum: '<S4>/Add1' */
    _rtB->Add1_pf = _rtB->Product1_m + _rtB->Product2_d;

    /* RealImagToComplex: '<S20>/Real-Imag to Complex' */
    _rtB->RealImagtoComplex.re = _rtB->Add_h;
    _rtB->RealImagtoComplex.im = _rtB->Add1_pf;

    /* ComplexToMagnitudeAngle: '<S20>/Complex to Magnitude-Angle' */
    _rtB->ComplextoMagnitudeAngle_o1 = DCU1_rt_hypotd_snf
      (_rtB->RealImagtoComplex.re, _rtB->RealImagtoComplex.im);
    _rtB->ComplextoMagnitudeAngle_o2 = DCU1_rt_atan2d_snf
      (_rtB->RealImagtoComplex.im, _rtB->RealImagtoComplex.re);

    /* Saturate: '<S20>/Saturation' */
    A = _rtB->ComplextoMagnitudeAngle_o2;
    u1 = (-3.1415926535897931);
    u2 = 3.1415926535897931;
    if (A > u2) {
      _rtB->Saturation_g = u2;
    } else if (A < u1) {
      _rtB->Saturation_g = u1;
    } else {
      _rtB->Saturation_g = A;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Constant: '<S22>/Constant'
     */
    _rtB->RelationalOperator = (_rtB->Saturation_g > 0.0);

    /* RelationalOperator: '<S22>/Relational Operator1' incorporates:
     *  Constant: '<S22>/Constant1'
     */
    _rtB->RelationalOperator1 = (_rtB->Saturation_g <= 1.0471975511965976);

    /* Logic: '<S22>/Logical Operator' */
    _rtB->LogicalOperator_a = (_rtB->RelationalOperator &&
      _rtB->RelationalOperator1);

    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    _rtB->DataTypeConversion = _rtB->LogicalOperator_a;

    /* Gain: '<S22>/Gain' */
    _rtB->Gain_d = 1.0 * _rtB->DataTypeConversion;

    /* RelationalOperator: '<S22>/Relational Operator2' incorporates:
     *  Constant: '<S22>/Constant11'
     */
    _rtB->RelationalOperator2 = (_rtB->Saturation_g > 1.0471975511965976);

    /* RelationalOperator: '<S22>/Relational Operator3' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    _rtB->RelationalOperator3 = (_rtB->Saturation_g <= 2.0943951023931953);

    /* Logic: '<S22>/Logical Operator1' */
    _rtB->LogicalOperator1_n = (_rtB->RelationalOperator2 &&
      _rtB->RelationalOperator3);

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    _rtB->DataTypeConversion1 = _rtB->LogicalOperator1_n;

    /* Gain: '<S22>/Gain1' */
    _rtB->Gain1_b = 2.0 * _rtB->DataTypeConversion1;

    /* RelationalOperator: '<S22>/Relational Operator4' incorporates:
     *  Constant: '<S22>/Constant3'
     */
    _rtB->RelationalOperator4 = (_rtB->Saturation_g > 2.0943951023931953);

    /* RelationalOperator: '<S22>/Relational Operator5' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    _rtB->RelationalOperator5 = (_rtB->Saturation_g <= 3.1415926535897931);

    /* Logic: '<S22>/Logical Operator2' */
    _rtB->LogicalOperator2_o = (_rtB->RelationalOperator4 &&
      _rtB->RelationalOperator5);

    /* DataTypeConversion: '<S22>/Data Type Conversion2' */
    _rtB->DataTypeConversion2 = _rtB->LogicalOperator2_o;

    /* Gain: '<S22>/Gain2' */
    _rtB->Gain2_e = 3.0 * _rtB->DataTypeConversion2;

    /* RelationalOperator: '<S22>/Relational Operator6' incorporates:
     *  Constant: '<S22>/Constant5'
     */
    _rtB->RelationalOperator6 = (_rtB->Saturation_g >= (-3.1415926535897931));

    /* RelationalOperator: '<S22>/Relational Operator7' incorporates:
     *  Constant: '<S22>/Constant6'
     */
    _rtB->RelationalOperator7 = (_rtB->Saturation_g <= (-2.0943951023931953));

    /* Logic: '<S22>/Logical Operator3' */
    _rtB->LogicalOperator3_m = (_rtB->RelationalOperator6 &&
      _rtB->RelationalOperator7);

    /* DataTypeConversion: '<S22>/Data Type Conversion3' */
    _rtB->DataTypeConversion3 = _rtB->LogicalOperator3_m;

    /* Gain: '<S22>/Gain3' */
    _rtB->Gain3_o = 4.0 * _rtB->DataTypeConversion3;

    /* RelationalOperator: '<S22>/Relational Operator8' incorporates:
     *  Constant: '<S22>/Constant7'
     */
    _rtB->RelationalOperator8 = (_rtB->Saturation_g > (-2.0943951023931953));

    /* RelationalOperator: '<S22>/Relational Operator9' incorporates:
     *  Constant: '<S22>/Constant8'
     */
    _rtB->RelationalOperator9 = (_rtB->Saturation_g <= (-1.0471975511965976));

    /* Logic: '<S22>/Logical Operator4' */
    _rtB->LogicalOperator4 = (_rtB->RelationalOperator8 &&
      _rtB->RelationalOperator9);

    /* DataTypeConversion: '<S22>/Data Type Conversion4' */
    _rtB->DataTypeConversion4 = _rtB->LogicalOperator4;

    /* Gain: '<S22>/Gain4' */
    _rtB->Gain4 = 5.0 * _rtB->DataTypeConversion4;

    /* RelationalOperator: '<S22>/Relational Operator10' incorporates:
     *  Constant: '<S22>/Constant9'
     */
    _rtB->RelationalOperator10 = (_rtB->Saturation_g > (-1.0471975511965976));

    /* RelationalOperator: '<S22>/Relational Operator11' incorporates:
     *  Constant: '<S22>/Constant10'
     */
    _rtB->RelationalOperator11 = (_rtB->Saturation_g <= 0.0);

    /* Logic: '<S22>/Logical Operator5' */
    _rtB->LogicalOperator5 = (_rtB->RelationalOperator10 &&
      _rtB->RelationalOperator11);

    /* DataTypeConversion: '<S22>/Data Type Conversion5' */
    _rtB->DataTypeConversion5 = _rtB->LogicalOperator5;

    /* Gain: '<S22>/Gain5' */
    _rtB->Gain5 = 6.0 * _rtB->DataTypeConversion5;

    /* Sum: '<S22>/Add' */
    _rtB->Add_b = ((((_rtB->Gain_d + _rtB->Gain1_b) + _rtB->Gain2_e) +
                    _rtB->Gain3_o) + _rtB->Gain4) + _rtB->Gain5;

    /* RelationalOperator: '<S23>/Relational Operator' incorporates:
     *  Constant: '<S23>/Constant'
     */
    _rtB->RelationalOperator_p = (_rtB->Saturation_g >= 0.0);

    /* Switch: '<S23>/Switch' */
    if (_rtB->RelationalOperator_p) {
      _rtB->Switch_nm = _rtB->Add_b;
    } else {
      /* Fcn: '<S23>/Fcn' */
      _rtB->Fcn_a = _rtB->Add_b - 6.0;
      _rtB->Switch_nm = _rtB->Fcn_a;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Gain: '<S23>/Gain' */
    _rtB->Gain_n = 1.0471975511965976 * _rtB->Switch_nm;

    /* Sum: '<S23>/Add' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    _rtB->Add_i = (_rtB->Saturation_g - _rtB->Gain_n) + 1.0471975511965976;

    /* Sum: '<S3>/Add' incorporates:
     *  Inport: '<Root>/Inport2'
     *  Inport: '<Root>/Inport5'
     */
    _rtB->Add_f = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] + *((
      const real_T **)ssGetInputPortSignalPtrs(S, 5))[0];

    /* Fcn: '<S20>/Fcn' */
    _rtB->Fcn_g = 1.5 * _rtB->ComplextoMagnitudeAngle_o1 / (_rtB->Add_f + 1.0);

    /* Saturate: '<S20>/Saturation1' */
    A = _rtB->Fcn_g;
    u1 = 0.0;
    u2 = 1.0;
    if (A > u2) {
      _rtB->Saturation1 = u2;
    } else if (A < u1) {
      _rtB->Saturation1 = u1;
    } else {
      _rtB->Saturation1 = A;
    }

    /* End of Saturate: '<S20>/Saturation1' */

    /* MATLAB Function: '<S20>/Section-n1' */
    /* MATLAB Function 'DCU1/DCU-Inverter/SVPWM Genratorfxy/Reference voltage orientation /Section-n1': '<S24>:1' */
    /* '<S24>:1:2' */
    /* '<S24>:1:3' */
    /* '<S24>:1:4' */
    if (cos(0.52359877559829882 - _rtB->Add_i) * _rtB->Saturation1 <
        0.4330127018922193) {
      /* '<S24>:1:5' */
      /* '<S24>:1:6' */
      _rtB->n = 1.0;
    } else if (sin(1.0471975511965976 - _rtB->Add_i) * _rtB->Saturation1 >
               0.4330127018922193) {
      /* '<S24>:1:7' */
      /* '<S24>:1:8' */
      _rtB->n = 3.0;
    } else if (_rtB->Saturation1 * sin(_rtB->Add_i) > 0.4330127018922193) {
      /* '<S24>:1:9' */
      /* '<S24>:1:10' */
      _rtB->n = 4.0;
    } else {
      /* '<S24>:1:11' */
      _rtB->n = 2.0;
    }

    /* End of MATLAB Function: '<S20>/Section-n1' */

    /* Clock: '<S30>/Clock' */
    _rtB->Clock = ssGetT(S);

    /* Sum: '<S30>/Sum' incorporates:
     *  S-Function (sfun_tstart): '<S30>/startTime'
     */
    _rtB->Sum_m1 = _rtB->Clock - ssGetTStart(S);

    /* Math: '<S30>/Math Function' incorporates:
     *  Constant: '<S30>/Constant'
     */
    _rtB->MathFunction = DCU1_rt_remd_snf(_rtB->Sum_m1, 0.0001);

    /* Lookup_n-D: '<S30>/Look-Up Table1' */
    _rtB->LookUpTable1 = DCU1_look1_binlxpw(_rtB->MathFunction,
      DCU1_ConstP.pooled31, DCU1_ConstP.pooled31, 1U);

    /* SignalConversion: '<S30>/Output' */
    _rtB->Output = _rtB->LookUpTable1;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S10>/Ts' */
    _rtB->Ts = (*(real_T *)(mxGetData(Ts(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MATLAB Function: '<S25>/Section-n' */
    /* MATLAB Function 'DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggered/Section-n': '<S28>:1' */
    /* '<S28>:1:2' */
    _rtB->Ta = 0.0;

    /* '<S28>:1:3' */
    _rtB->Tb = 0.0;

    /* '<S28>:1:4' */
    _rtB->Tc = 0.0;
    switch ((int32_T)_rtB->n) {
     case 1:
      /* '<S28>:1:7' */
      _rtB->Ta = 2.0 * _rtB->Saturation1 * _rtB->Ts * (cos(_rtB->Add_i) - sin
        (_rtB->Add_i) / 1.7320508075688772);

      /* '<S28>:1:8' */
      _rtB->Tb = _rtB->Saturation1 * _rtB->Ts * 4.0 * sin(_rtB->Add_i) /
        1.7320508075688772;

      /* '<S28>:1:9' */
      _rtB->Tc = (1.0 - (sin(_rtB->Add_i) / 1.7320508075688772 + cos(_rtB->Add_i))
                  * (2.0 * _rtB->Saturation1)) * _rtB->Ts;
      break;

     case 2:
      /* '<S28>:1:11' */
      _rtB->Ta = (1.0 - 4.0 * _rtB->Saturation1 * sin(_rtB->Add_i) /
                  1.7320508075688772) * _rtB->Ts;

      /* '<S28>:1:12' */
      _rtB->Tb = (1.0 - (cos(_rtB->Add_i) - sin(_rtB->Add_i) /
                         1.7320508075688772) * (2.0 * _rtB->Saturation1)) *
        _rtB->Ts;

      /* '<S28>:1:13' */
      _rtB->Tc = ((sin(_rtB->Add_i) / 1.7320508075688772 + cos(_rtB->Add_i)) *
                  (2.0 * _rtB->Saturation1) + -1.0) * _rtB->Ts;
      break;

     case 3:
      /* '<S28>:1:15' */
      _rtB->Ta = (2.0 - (sin(_rtB->Add_i) / 1.7320508075688772 + cos(_rtB->Add_i))
                  * (2.0 * _rtB->Saturation1)) * _rtB->Ts;

      /* '<S28>:1:16' */
      _rtB->Tb = ((cos(_rtB->Add_i) - sin(_rtB->Add_i) / 1.7320508075688772) *
                  (2.0 * _rtB->Saturation1) + -1.0) * _rtB->Ts;

      /* '<S28>:1:17' */
      _rtB->Tc = 4.0 * _rtB->Ts * _rtB->Saturation1 * sin(_rtB->Add_i) /
        1.7320508075688772;
      break;

     case 4:
      /* '<S28>:1:19' */
      _rtB->Ta = (2.0 - (sin(_rtB->Add_i) / 1.7320508075688772 + cos(_rtB->Add_i))
                  * (2.0 * _rtB->Saturation1)) * _rtB->Ts;

      /* '<S28>:1:20' */
      _rtB->Tb = 2.0 * _rtB->Ts * _rtB->Saturation1 * (cos(_rtB->Add_i) - sin
        (_rtB->Add_i) / 1.7320508075688772);

      /* '<S28>:1:21' */
      _rtB->Tc = (4.0 * _rtB->Saturation1 * sin(_rtB->Add_i) /
                  1.7320508075688772 + -1.0) * _rtB->Ts;
      break;
    }

    /* End of MATLAB Function: '<S25>/Section-n' */

    /* MultiPortSwitch: '<S27>/Multiport Switch' */
    switch ((int32_T)_rtB->Add_b) {
     case 1:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tc;
      _rtB->MultiportSwitch_h[2] = _rtB->Tb;
      break;

     case 2:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tb;
      _rtB->MultiportSwitch_h[2] = _rtB->Tc;
      break;

     case 3:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tc;
      _rtB->MultiportSwitch_h[2] = _rtB->Tb;
      break;

     case 4:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tb;
      _rtB->MultiportSwitch_h[2] = _rtB->Tc;
      break;

     case 5:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tc;
      _rtB->MultiportSwitch_h[2] = _rtB->Tb;
      break;

     default:
      _rtB->MultiportSwitch_h[0] = _rtB->Ta;
      _rtB->MultiportSwitch_h[1] = _rtB->Tb;
      _rtB->MultiportSwitch_h[2] = _rtB->Tc;
      break;
    }

    /* End of MultiPortSwitch: '<S27>/Multiport Switch' */

    /* Gain: '<S31>/Gain1' */
    _rtB->Gain1_d = 0.25 * _rtB->MultiportSwitch_h[0];

    /* RelationalOperator: '<S31>/Relational Operator' */
    _rtB->RelationalOperator_h = (_rtB->Output > _rtB->Gain1_d);

    /* Gain: '<S31>/Gain2' */
    _rtB->Gain2_et = 0.5 * _rtB->MultiportSwitch_h[1];

    /* Sum: '<S31>/Add1' */
    _rtB->Add1_f = _rtB->Gain1_d + _rtB->Gain2_et;

    /* RelationalOperator: '<S31>/Relational Operator1' */
    _rtB->RelationalOperator1_l = (_rtB->Output > _rtB->Add1_f);

    /* Gain: '<S31>/Gain3' */
    _rtB->Gain3_f = 0.5 * _rtB->MultiportSwitch_h[2];

    /* Sum: '<S31>/Add2' */
    _rtB->Add2_a = _rtB->Add1_f + _rtB->Gain3_f;

    /* RelationalOperator: '<S31>/Relational Operator2' */
    _rtB->RelationalOperator2_o = (_rtB->Output > _rtB->Add2_a);

    /* Gain: '<S31>/Gain4' */
    _rtB->Gain4_n = 0.5 * _rtB->MultiportSwitch_h[0];

    /* Sum: '<S31>/Add3' */
    _rtB->Add3 = _rtB->Add2_a + _rtB->Gain4_n;

    /* RelationalOperator: '<S31>/Relational Operator3' */
    _rtB->RelationalOperator3_p = (_rtB->Output > _rtB->Add3);

    /* Sum: '<S31>/Add4' */
    _rtB->Add4 = _rtB->Add3 + _rtB->Gain3_f;

    /* RelationalOperator: '<S31>/Relational Operator4' */
    _rtB->RelationalOperator4_j = (_rtB->Output > _rtB->Add4);

    /* Sum: '<S31>/Add5' */
    _rtB->Add5 = _rtB->Add4 + _rtB->Gain2_et;

    /* RelationalOperator: '<S31>/Relational Operator5' */
    _rtB->RelationalOperator5_l = (_rtB->Output > _rtB->Add5);

    /* DataTypeConversion: '<S31>/Data Type Conversion' */
    _rtB->DataTypeConversion_i[0] = _rtB->RelationalOperator_h;
    _rtB->DataTypeConversion_i[1] = _rtB->RelationalOperator1_l;
    _rtB->DataTypeConversion_i[2] = _rtB->RelationalOperator2_o;
    _rtB->DataTypeConversion_i[3] = _rtB->RelationalOperator3_p;
    _rtB->DataTypeConversion_i[4] = _rtB->RelationalOperator4_j;
    _rtB->DataTypeConversion_i[5] = _rtB->RelationalOperator5_l;

    /* Gain: '<S31>/Gain5' */
    for (i = 0; i < 6; i++) {
      _rtB->Gain5_l[i] = 1.0 * _rtB->DataTypeConversion_i[i];
    }

    /* End of Gain: '<S31>/Gain5' */

    /* Sum: '<S31>/Add6' */
    _rtB->Add6 = ((((_rtB->Gain5_l[0] + _rtB->Gain5_l[1]) + _rtB->Gain5_l[2]) +
                   _rtB->Gain5_l[3]) + _rtB->Gain5_l[4]) + _rtB->Gain5_l[5];

    /* Sum: '<S31>/Add7' incorporates:
     *  Constant: '<S31>/Constant'
     */
    _rtB->Add7 = _rtB->Add6 + 1.0;

    /* MultiPortSwitch: '<S29>/Multiport Switch' */
    switch ((int32_T)_rtB->Add_b) {
     case 1:
      /* MultiPortSwitch: '<S32>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
         *  Constant: '<S38>/Us1'
         *  Constant: '<S38>/Us2'
         *  Constant: '<S38>/Us3'
         *  Constant: '<S38>/Us4'
         *  Constant: '<S38>/Us5'
         *  Constant: '<S38>/Us6'
         *  Constant: '<S38>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_d[0] = 1.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_d[0] = 0.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_d[0] = 0.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_d[0] = 0.0;
          _rtB->MultiportSwitch_d[1] = (-1.0);
          _rtB->MultiportSwitch_d[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_d[0] = 0.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_d[0] = 0.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_d[0] = 1.0;
          _rtB->MultiportSwitch_d[1] = 0.0;
          _rtB->MultiportSwitch_d[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S38>/Multiport Switch' */
        _rtB->MultiportSwitch_bm[0] = _rtB->MultiportSwitch_d[0];
        _rtB->MultiportSwitch_bm[1] = _rtB->MultiportSwitch_d[1];
        _rtB->MultiportSwitch_bm[2] = _rtB->MultiportSwitch_d[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S39>/Multiport Switch' incorporates:
         *  Constant: '<S39>/Us1'
         *  Constant: '<S39>/Us2'
         *  Constant: '<S39>/Us3'
         *  Constant: '<S39>/Us4'
         *  Constant: '<S39>/Us5'
         *  Constant: '<S39>/Us6'
         *  Constant: '<S39>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_m[0] = 1.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_m[0] = 1.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = (-1.0);
          break;

         case 3:
          _rtB->MultiportSwitch_m[0] = 0.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_m[0] = 0.0;
          _rtB->MultiportSwitch_m[1] = (-1.0);
          _rtB->MultiportSwitch_m[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_m[0] = 0.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_m[0] = 1.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = (-1.0);
          break;

         default:
          _rtB->MultiportSwitch_m[0] = 1.0;
          _rtB->MultiportSwitch_m[1] = 0.0;
          _rtB->MultiportSwitch_m[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S39>/Multiport Switch' */
        _rtB->MultiportSwitch_bm[0] = _rtB->MultiportSwitch_m[0];
        _rtB->MultiportSwitch_bm[1] = _rtB->MultiportSwitch_m[1];
        _rtB->MultiportSwitch_bm[2] = _rtB->MultiportSwitch_m[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S40>/Multiport Switch' incorporates:
         *  Constant: '<S40>/Us1'
         *  Constant: '<S40>/Us2'
         *  Constant: '<S40>/Us3'
         *  Constant: '<S40>/Us4'
         *  Constant: '<S40>/Us5'
         *  Constant: '<S40>/Us6'
         *  Constant: '<S40>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = 0.0;
          _rtB->MultiportSwitch_f[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = 0.0;
          _rtB->MultiportSwitch_f[2] = (-1.0);
          break;

         case 3:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = (-1.0);
          _rtB->MultiportSwitch_f[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_f[0] = 0.0;
          _rtB->MultiportSwitch_f[1] = (-1.0);
          _rtB->MultiportSwitch_f[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = (-1.0);
          _rtB->MultiportSwitch_f[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = 0.0;
          _rtB->MultiportSwitch_f[2] = (-1.0);
          break;

         default:
          _rtB->MultiportSwitch_f[0] = 1.0;
          _rtB->MultiportSwitch_f[1] = 0.0;
          _rtB->MultiportSwitch_f[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S40>/Multiport Switch' */
        _rtB->MultiportSwitch_bm[0] = _rtB->MultiportSwitch_f[0];
        _rtB->MultiportSwitch_bm[1] = _rtB->MultiportSwitch_f[1];
        _rtB->MultiportSwitch_bm[2] = _rtB->MultiportSwitch_f[2];
        break;

       default:
        /* MultiPortSwitch: '<S41>/Multiport Switch' incorporates:
         *  Constant: '<S41>/Us1'
         *  Constant: '<S41>/Us2'
         *  Constant: '<S41>/Us3'
         *  Constant: '<S41>/Us4'
         *  Constant: '<S41>/Us5'
         *  Constant: '<S41>/Us6'
         *  Constant: '<S41>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 1.0;
          _rtB->MultiportSwitch_e[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 1.0;
          _rtB->MultiportSwitch_e[2] = (-1.0);
          break;

         case 3:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 0.0;
          _rtB->MultiportSwitch_e[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_e[0] = 0.0;
          _rtB->MultiportSwitch_e[1] = 0.0;
          _rtB->MultiportSwitch_e[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 0.0;
          _rtB->MultiportSwitch_e[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 1.0;
          _rtB->MultiportSwitch_e[2] = (-1.0);
          break;

         default:
          _rtB->MultiportSwitch_e[0] = 1.0;
          _rtB->MultiportSwitch_e[1] = 1.0;
          _rtB->MultiportSwitch_e[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S41>/Multiport Switch' */
        _rtB->MultiportSwitch_bm[0] = _rtB->MultiportSwitch_e[0];
        _rtB->MultiportSwitch_bm[1] = _rtB->MultiportSwitch_e[1];
        _rtB->MultiportSwitch_bm[2] = _rtB->MultiportSwitch_e[2];
        break;
      }

      /* End of MultiPortSwitch: '<S32>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_bm[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_bm[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_bm[2];
      break;

     case 2:
      /* MultiPortSwitch: '<S33>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S42>/Multiport Switch' incorporates:
         *  Constant: '<S42>/Us1'
         *  Constant: '<S42>/Us2'
         *  Constant: '<S42>/Us3'
         *  Constant: '<S42>/Us4'
         *  Constant: '<S42>/Us5'
         *  Constant: '<S42>/Us6'
         *  Constant: '<S42>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_c[0] = 1.0;
          _rtB->MultiportSwitch_c[1] = 1.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_c[0] = 0.0;
          _rtB->MultiportSwitch_c[1] = 1.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_c[0] = 0.0;
          _rtB->MultiportSwitch_c[1] = 0.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_c[0] = 0.0;
          _rtB->MultiportSwitch_c[1] = 0.0;
          _rtB->MultiportSwitch_c[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_c[0] = 0.0;
          _rtB->MultiportSwitch_c[1] = 0.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_c[0] = 0.0;
          _rtB->MultiportSwitch_c[1] = 1.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_c[0] = 1.0;
          _rtB->MultiportSwitch_c[1] = 1.0;
          _rtB->MultiportSwitch_c[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S42>/Multiport Switch' */
        _rtB->MultiportSwitch_k[0] = _rtB->MultiportSwitch_c[0];
        _rtB->MultiportSwitch_k[1] = _rtB->MultiportSwitch_c[1];
        _rtB->MultiportSwitch_k[2] = _rtB->MultiportSwitch_c[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
         *  Constant: '<S43>/Us1'
         *  Constant: '<S43>/Us2'
         *  Constant: '<S43>/Us3'
         *  Constant: '<S43>/Us4'
         *  Constant: '<S43>/Us5'
         *  Constant: '<S43>/Us6'
         *  Constant: '<S43>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_bmk[0] = 1.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_bmk[0] = 0.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_bmk[0] = 0.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_bmk[0] = 0.0;
          _rtB->MultiportSwitch_bmk[1] = 0.0;
          _rtB->MultiportSwitch_bmk[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_bmk[0] = 0.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_bmk[0] = 0.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_bmk[0] = 1.0;
          _rtB->MultiportSwitch_bmk[1] = 1.0;
          _rtB->MultiportSwitch_bmk[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S43>/Multiport Switch' */
        _rtB->MultiportSwitch_k[0] = _rtB->MultiportSwitch_bmk[0];
        _rtB->MultiportSwitch_k[1] = _rtB->MultiportSwitch_bmk[1];
        _rtB->MultiportSwitch_k[2] = _rtB->MultiportSwitch_bmk[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S44>/Multiport Switch' incorporates:
         *  Constant: '<S44>/Us1'
         *  Constant: '<S44>/Us2'
         *  Constant: '<S44>/Us3'
         *  Constant: '<S44>/Us4'
         *  Constant: '<S44>/Us5'
         *  Constant: '<S44>/Us6'
         *  Constant: '<S44>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_mm[0] = 1.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_mm[0] = 1.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = (-1.0);
          break;

         case 3:
          _rtB->MultiportSwitch_mm[0] = 0.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_mm[0] = 0.0;
          _rtB->MultiportSwitch_mm[1] = 0.0;
          _rtB->MultiportSwitch_mm[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_mm[0] = 0.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_mm[0] = 1.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = (-1.0);
          break;

         default:
          _rtB->MultiportSwitch_mm[0] = 1.0;
          _rtB->MultiportSwitch_mm[1] = 1.0;
          _rtB->MultiportSwitch_mm[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S44>/Multiport Switch' */
        _rtB->MultiportSwitch_k[0] = _rtB->MultiportSwitch_mm[0];
        _rtB->MultiportSwitch_k[1] = _rtB->MultiportSwitch_mm[1];
        _rtB->MultiportSwitch_k[2] = _rtB->MultiportSwitch_mm[2];
        break;

       default:
        /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
         *  Constant: '<S45>/Us1'
         *  Constant: '<S45>/Us2'
         *  Constant: '<S45>/Us3'
         *  Constant: '<S45>/Us4'
         *  Constant: '<S45>/Us5'
         *  Constant: '<S45>/Us6'
         *  Constant: '<S45>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_n[0] = 0.0;
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_n[0] = 0.0;
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = (-1.0);
          break;

         case 3:
          _rtB->MultiportSwitch_n[0] = (-1.0);
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_n[0] = (-1.0);
          _rtB->MultiportSwitch_n[1] = 0.0;
          _rtB->MultiportSwitch_n[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_n[0] = (-1.0);
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_n[0] = 0.0;
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = (-1.0);
          break;

         default:
          _rtB->MultiportSwitch_n[0] = 0.0;
          _rtB->MultiportSwitch_n[1] = 1.0;
          _rtB->MultiportSwitch_n[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S45>/Multiport Switch' */
        _rtB->MultiportSwitch_k[0] = _rtB->MultiportSwitch_n[0];
        _rtB->MultiportSwitch_k[1] = _rtB->MultiportSwitch_n[1];
        _rtB->MultiportSwitch_k[2] = _rtB->MultiportSwitch_n[2];
        break;
      }

      /* End of MultiPortSwitch: '<S33>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_k[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_k[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_k[2];
      break;

     case 3:
      /* MultiPortSwitch: '<S34>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
         *  Constant: '<S46>/Us1'
         *  Constant: '<S46>/Us2'
         *  Constant: '<S46>/Us3'
         *  Constant: '<S46>/Us4'
         *  Constant: '<S46>/Us5'
         *  Constant: '<S46>/Us6'
         *  Constant: '<S46>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_br[0] = 0.0;
          _rtB->MultiportSwitch_br[1] = 1.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_br[0] = 0.0;
          _rtB->MultiportSwitch_br[1] = 0.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_br[0] = (-1.0);
          _rtB->MultiportSwitch_br[1] = 0.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_br[0] = (-1.0);
          _rtB->MultiportSwitch_br[1] = 0.0;
          _rtB->MultiportSwitch_br[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_br[0] = (-1.0);
          _rtB->MultiportSwitch_br[1] = 0.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_br[0] = 0.0;
          _rtB->MultiportSwitch_br[1] = 0.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_br[0] = 0.0;
          _rtB->MultiportSwitch_br[1] = 1.0;
          _rtB->MultiportSwitch_br[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S46>/Multiport Switch' */
        _rtB->MultiportSwitch_lq[0] = _rtB->MultiportSwitch_br[0];
        _rtB->MultiportSwitch_lq[1] = _rtB->MultiportSwitch_br[1];
        _rtB->MultiportSwitch_lq[2] = _rtB->MultiportSwitch_br[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S47>/Multiport Switch' incorporates:
         *  Constant: '<S47>/Us1'
         *  Constant: '<S47>/Us2'
         *  Constant: '<S47>/Us3'
         *  Constant: '<S47>/Us4'
         *  Constant: '<S47>/Us5'
         *  Constant: '<S47>/Us6'
         *  Constant: '<S47>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_p[0] = 0.0;
          _rtB->MultiportSwitch_p[1] = 1.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_p[0] = (-1.0);
          _rtB->MultiportSwitch_p[1] = 1.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_p[0] = (-1.0);
          _rtB->MultiportSwitch_p[1] = 0.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_p[0] = (-1.0);
          _rtB->MultiportSwitch_p[1] = 0.0;
          _rtB->MultiportSwitch_p[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_p[0] = (-1.0);
          _rtB->MultiportSwitch_p[1] = 0.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_p[0] = (-1.0);
          _rtB->MultiportSwitch_p[1] = 1.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_p[0] = 0.0;
          _rtB->MultiportSwitch_p[1] = 1.0;
          _rtB->MultiportSwitch_p[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S47>/Multiport Switch' */
        _rtB->MultiportSwitch_lq[0] = _rtB->MultiportSwitch_p[0];
        _rtB->MultiportSwitch_lq[1] = _rtB->MultiportSwitch_p[1];
        _rtB->MultiportSwitch_lq[2] = _rtB->MultiportSwitch_p[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S48>/Multiport Switch' incorporates:
         *  Constant: '<S48>/Us1'
         *  Constant: '<S48>/Us2'
         *  Constant: '<S48>/Us3'
         *  Constant: '<S48>/Us4'
         *  Constant: '<S48>/Us5'
         *  Constant: '<S48>/Us6'
         *  Constant: '<S48>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_bk[0] = 0.0;
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_bk[0] = (-1.0);
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_bk[0] = (-1.0);
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_bk[0] = (-1.0);
          _rtB->MultiportSwitch_bk[1] = 0.0;
          _rtB->MultiportSwitch_bk[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_bk[0] = (-1.0);
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_bk[0] = (-1.0);
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_bk[0] = 0.0;
          _rtB->MultiportSwitch_bk[1] = 1.0;
          _rtB->MultiportSwitch_bk[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S48>/Multiport Switch' */
        _rtB->MultiportSwitch_lq[0] = _rtB->MultiportSwitch_bk[0];
        _rtB->MultiportSwitch_lq[1] = _rtB->MultiportSwitch_bk[1];
        _rtB->MultiportSwitch_lq[2] = _rtB->MultiportSwitch_bk[2];
        break;

       default:
        /* MultiPortSwitch: '<S49>/Multiport Switch' incorporates:
         *  Constant: '<S49>/Us1'
         *  Constant: '<S49>/Us2'
         *  Constant: '<S49>/Us3'
         *  Constant: '<S49>/Us4'
         *  Constant: '<S49>/Us5'
         *  Constant: '<S49>/Us6'
         *  Constant: '<S49>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_bd[0] = 0.0;
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_bd[0] = (-1.0);
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_bd[0] = (-1.0);
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_bd[0] = (-1.0);
          _rtB->MultiportSwitch_bd[1] = 0.0;
          _rtB->MultiportSwitch_bd[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_bd[0] = (-1.0);
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_bd[0] = (-1.0);
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_bd[0] = 0.0;
          _rtB->MultiportSwitch_bd[1] = 1.0;
          _rtB->MultiportSwitch_bd[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S49>/Multiport Switch' */
        _rtB->MultiportSwitch_lq[0] = _rtB->MultiportSwitch_bd[0];
        _rtB->MultiportSwitch_lq[1] = _rtB->MultiportSwitch_bd[1];
        _rtB->MultiportSwitch_lq[2] = _rtB->MultiportSwitch_bd[2];
        break;
      }

      /* End of MultiPortSwitch: '<S34>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_lq[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_lq[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_lq[2];
      break;

     case 4:
      /* MultiPortSwitch: '<S35>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S50>/Multiport Switch' incorporates:
         *  Constant: '<S50>/Us1'
         *  Constant: '<S50>/Us2'
         *  Constant: '<S50>/Us3'
         *  Constant: '<S50>/Us4'
         *  Constant: '<S50>/Us5'
         *  Constant: '<S50>/Us6'
         *  Constant: '<S50>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 1.0;
          _rtB->MultiportSwitch_hc[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 0.0;
          _rtB->MultiportSwitch_hc[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 0.0;
          _rtB->MultiportSwitch_hc[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_hc[0] = (-1.0);
          _rtB->MultiportSwitch_hc[1] = 0.0;
          _rtB->MultiportSwitch_hc[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 0.0;
          _rtB->MultiportSwitch_hc[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 0.0;
          _rtB->MultiportSwitch_hc[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_hc[0] = 0.0;
          _rtB->MultiportSwitch_hc[1] = 1.0;
          _rtB->MultiportSwitch_hc[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S50>/Multiport Switch' */
        _rtB->MultiportSwitch_fx[0] = _rtB->MultiportSwitch_hc[0];
        _rtB->MultiportSwitch_fx[1] = _rtB->MultiportSwitch_hc[1];
        _rtB->MultiportSwitch_fx[2] = _rtB->MultiportSwitch_hc[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S51>/Multiport Switch' incorporates:
         *  Constant: '<S51>/Us1'
         *  Constant: '<S51>/Us2'
         *  Constant: '<S51>/Us3'
         *  Constant: '<S51>/Us4'
         *  Constant: '<S51>/Us5'
         *  Constant: '<S51>/Us6'
         *  Constant: '<S51>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_dg[0] = 0.0;
          _rtB->MultiportSwitch_dg[1] = 1.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_dg[0] = 0.0;
          _rtB->MultiportSwitch_dg[1] = 0.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_dg[0] = (-1.0);
          _rtB->MultiportSwitch_dg[1] = 0.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;

         case 4:
          _rtB->MultiportSwitch_dg[0] = (-1.0);
          _rtB->MultiportSwitch_dg[1] = 0.0;
          _rtB->MultiportSwitch_dg[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_dg[0] = (-1.0);
          _rtB->MultiportSwitch_dg[1] = 0.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;

         case 6:
          _rtB->MultiportSwitch_dg[0] = 0.0;
          _rtB->MultiportSwitch_dg[1] = 0.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_dg[0] = 0.0;
          _rtB->MultiportSwitch_dg[1] = 1.0;
          _rtB->MultiportSwitch_dg[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S51>/Multiport Switch' */
        _rtB->MultiportSwitch_fx[0] = _rtB->MultiportSwitch_dg[0];
        _rtB->MultiportSwitch_fx[1] = _rtB->MultiportSwitch_dg[1];
        _rtB->MultiportSwitch_fx[2] = _rtB->MultiportSwitch_dg[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
         *  Constant: '<S52>/Us1'
         *  Constant: '<S52>/Us2'
         *  Constant: '<S52>/Us3'
         *  Constant: '<S52>/Us4'
         *  Constant: '<S52>/Us5'
         *  Constant: '<S52>/Us6'
         *  Constant: '<S52>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_c2[0] = 0.0;
          _rtB->MultiportSwitch_c2[1] = 1.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_c2[0] = (-1.0);
          _rtB->MultiportSwitch_c2[1] = 1.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_c2[0] = (-1.0);
          _rtB->MultiportSwitch_c2[1] = 0.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;

         case 4:
          _rtB->MultiportSwitch_c2[0] = (-1.0);
          _rtB->MultiportSwitch_c2[1] = 0.0;
          _rtB->MultiportSwitch_c2[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_c2[0] = (-1.0);
          _rtB->MultiportSwitch_c2[1] = 0.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;

         case 6:
          _rtB->MultiportSwitch_c2[0] = (-1.0);
          _rtB->MultiportSwitch_c2[1] = 1.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_c2[0] = 0.0;
          _rtB->MultiportSwitch_c2[1] = 1.0;
          _rtB->MultiportSwitch_c2[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S52>/Multiport Switch' */
        _rtB->MultiportSwitch_fx[0] = _rtB->MultiportSwitch_c2[0];
        _rtB->MultiportSwitch_fx[1] = _rtB->MultiportSwitch_c2[1];
        _rtB->MultiportSwitch_fx[2] = _rtB->MultiportSwitch_c2[2];
        break;

       default:
        /* MultiPortSwitch: '<S53>/Multiport Switch' incorporates:
         *  Constant: '<S53>/Us1'
         *  Constant: '<S53>/Us2'
         *  Constant: '<S53>/Us3'
         *  Constant: '<S53>/Us4'
         *  Constant: '<S53>/Us5'
         *  Constant: '<S53>/Us6'
         *  Constant: '<S53>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_h3[0] = 0.0;
          _rtB->MultiportSwitch_h3[1] = 0.0;
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_h3[0] = (-1.0);
          _rtB->MultiportSwitch_h3[1] = 0.0;
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_h3[0] = (-1.0);
          _rtB->MultiportSwitch_h3[1] = (-1.0);
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;

         case 4:
          _rtB->MultiportSwitch_h3[0] = (-1.0);
          _rtB->MultiportSwitch_h3[1] = (-1.0);
          _rtB->MultiportSwitch_h3[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_h3[0] = (-1.0);
          _rtB->MultiportSwitch_h3[1] = (-1.0);
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;

         case 6:
          _rtB->MultiportSwitch_h3[0] = (-1.0);
          _rtB->MultiportSwitch_h3[1] = 0.0;
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_h3[0] = 0.0;
          _rtB->MultiportSwitch_h3[1] = 0.0;
          _rtB->MultiportSwitch_h3[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S53>/Multiport Switch' */
        _rtB->MultiportSwitch_fx[0] = _rtB->MultiportSwitch_h3[0];
        _rtB->MultiportSwitch_fx[1] = _rtB->MultiportSwitch_h3[1];
        _rtB->MultiportSwitch_fx[2] = _rtB->MultiportSwitch_h3[2];
        break;
      }

      /* End of MultiPortSwitch: '<S35>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_fx[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_fx[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_fx[2];
      break;

     case 5:
      /* MultiPortSwitch: '<S36>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S54>/Multiport Switch' incorporates:
         *  Constant: '<S54>/Us1'
         *  Constant: '<S54>/Us2'
         *  Constant: '<S54>/Us3'
         *  Constant: '<S54>/Us4'
         *  Constant: '<S54>/Us5'
         *  Constant: '<S54>/Us6'
         *  Constant: '<S54>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = 0.0;
          _rtB->MultiportSwitch_g[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = 0.0;
          _rtB->MultiportSwitch_g[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = (-1.0);
          _rtB->MultiportSwitch_g[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_g[0] = (-1.0);
          _rtB->MultiportSwitch_g[1] = (-1.0);
          _rtB->MultiportSwitch_g[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = (-1.0);
          _rtB->MultiportSwitch_g[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = 0.0;
          _rtB->MultiportSwitch_g[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_g[0] = 0.0;
          _rtB->MultiportSwitch_g[1] = 0.0;
          _rtB->MultiportSwitch_g[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S54>/Multiport Switch' */
        _rtB->MultiportSwitch_kn[0] = _rtB->MultiportSwitch_g[0];
        _rtB->MultiportSwitch_kn[1] = _rtB->MultiportSwitch_g[1];
        _rtB->MultiportSwitch_kn[2] = _rtB->MultiportSwitch_g[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S55>/Multiport Switch' incorporates:
         *  Constant: '<S55>/Us1'
         *  Constant: '<S55>/Us2'
         *  Constant: '<S55>/Us3'
         *  Constant: '<S55>/Us4'
         *  Constant: '<S55>/Us5'
         *  Constant: '<S55>/Us6'
         *  Constant: '<S55>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = 0.0;
          _rtB->MultiportSwitch_mh[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = (-1.0);
          _rtB->MultiportSwitch_mh[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = (-1.0);
          _rtB->MultiportSwitch_mh[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_mh[0] = (-1.0);
          _rtB->MultiportSwitch_mh[1] = (-1.0);
          _rtB->MultiportSwitch_mh[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = (-1.0);
          _rtB->MultiportSwitch_mh[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = (-1.0);
          _rtB->MultiportSwitch_mh[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_mh[0] = 0.0;
          _rtB->MultiportSwitch_mh[1] = 0.0;
          _rtB->MultiportSwitch_mh[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S55>/Multiport Switch' */
        _rtB->MultiportSwitch_kn[0] = _rtB->MultiportSwitch_mh[0];
        _rtB->MultiportSwitch_kn[1] = _rtB->MultiportSwitch_mh[1];
        _rtB->MultiportSwitch_kn[2] = _rtB->MultiportSwitch_mh[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S56>/Multiport Switch' incorporates:
         *  Constant: '<S56>/Us1'
         *  Constant: '<S56>/Us2'
         *  Constant: '<S56>/Us3'
         *  Constant: '<S56>/Us4'
         *  Constant: '<S56>/Us5'
         *  Constant: '<S56>/Us6'
         *  Constant: '<S56>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_k2[0] = 0.0;
          _rtB->MultiportSwitch_k2[1] = 0.0;
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_k2[0] = 0.0;
          _rtB->MultiportSwitch_k2[1] = (-1.0);
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_k2[0] = (-1.0);
          _rtB->MultiportSwitch_k2[1] = (-1.0);
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;

         case 4:
          _rtB->MultiportSwitch_k2[0] = (-1.0);
          _rtB->MultiportSwitch_k2[1] = (-1.0);
          _rtB->MultiportSwitch_k2[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_k2[0] = (-1.0);
          _rtB->MultiportSwitch_k2[1] = (-1.0);
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;

         case 6:
          _rtB->MultiportSwitch_k2[0] = 0.0;
          _rtB->MultiportSwitch_k2[1] = (-1.0);
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_k2[0] = 0.0;
          _rtB->MultiportSwitch_k2[1] = 0.0;
          _rtB->MultiportSwitch_k2[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S56>/Multiport Switch' */
        _rtB->MultiportSwitch_kn[0] = _rtB->MultiportSwitch_k2[0];
        _rtB->MultiportSwitch_kn[1] = _rtB->MultiportSwitch_k2[1];
        _rtB->MultiportSwitch_kn[2] = _rtB->MultiportSwitch_k2[2];
        break;

       default:
        /* MultiPortSwitch: '<S57>/Multiport Switch' incorporates:
         *  Constant: '<S57>/Us1'
         *  Constant: '<S57>/Us2'
         *  Constant: '<S57>/Us3'
         *  Constant: '<S57>/Us4'
         *  Constant: '<S57>/Us5'
         *  Constant: '<S57>/Us6'
         *  Constant: '<S57>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_b0[0] = 1.0;
          _rtB->MultiportSwitch_b0[1] = 0.0;
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_b0[0] = 1.0;
          _rtB->MultiportSwitch_b0[1] = (-1.0);
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_b0[0] = 0.0;
          _rtB->MultiportSwitch_b0[1] = (-1.0);
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;

         case 4:
          _rtB->MultiportSwitch_b0[0] = 0.0;
          _rtB->MultiportSwitch_b0[1] = (-1.0);
          _rtB->MultiportSwitch_b0[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_b0[0] = 0.0;
          _rtB->MultiportSwitch_b0[1] = (-1.0);
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;

         case 6:
          _rtB->MultiportSwitch_b0[0] = 1.0;
          _rtB->MultiportSwitch_b0[1] = (-1.0);
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_b0[0] = 1.0;
          _rtB->MultiportSwitch_b0[1] = 0.0;
          _rtB->MultiportSwitch_b0[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S57>/Multiport Switch' */
        _rtB->MultiportSwitch_kn[0] = _rtB->MultiportSwitch_b0[0];
        _rtB->MultiportSwitch_kn[1] = _rtB->MultiportSwitch_b0[1];
        _rtB->MultiportSwitch_kn[2] = _rtB->MultiportSwitch_b0[2];
        break;
      }

      /* End of MultiPortSwitch: '<S36>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_kn[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_kn[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_kn[2];
      break;

     default:
      /* MultiPortSwitch: '<S37>/Multiport Switch' */
      switch ((int32_T)_rtB->n) {
       case 1:
        /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
         *  Constant: '<S58>/Us1'
         *  Constant: '<S58>/Us2'
         *  Constant: '<S58>/Us3'
         *  Constant: '<S58>/Us4'
         *  Constant: '<S58>/Us5'
         *  Constant: '<S58>/Us6'
         *  Constant: '<S58>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_h1[0] = 1.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_h1[0] = 1.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_h1[0] = 0.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_h1[0] = 0.0;
          _rtB->MultiportSwitch_h1[1] = (-1.0);
          _rtB->MultiportSwitch_h1[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_h1[0] = 0.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_h1[0] = 1.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_h1[0] = 1.0;
          _rtB->MultiportSwitch_h1[1] = 0.0;
          _rtB->MultiportSwitch_h1[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S58>/Multiport Switch' */
        _rtB->MultiportSwitch_gd[0] = _rtB->MultiportSwitch_h1[0];
        _rtB->MultiportSwitch_gd[1] = _rtB->MultiportSwitch_h1[1];
        _rtB->MultiportSwitch_gd[2] = _rtB->MultiportSwitch_h1[2];
        break;

       case 2:
        /* MultiPortSwitch: '<S59>/Multiport Switch' incorporates:
         *  Constant: '<S59>/Us1'
         *  Constant: '<S59>/Us2'
         *  Constant: '<S59>/Us3'
         *  Constant: '<S59>/Us4'
         *  Constant: '<S59>/Us5'
         *  Constant: '<S59>/Us6'
         *  Constant: '<S59>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = 0.0;
          _rtB->MultiportSwitch_a[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = 0.0;
          _rtB->MultiportSwitch_a[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = (-1.0);
          _rtB->MultiportSwitch_a[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_a[0] = 0.0;
          _rtB->MultiportSwitch_a[1] = (-1.0);
          _rtB->MultiportSwitch_a[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = (-1.0);
          _rtB->MultiportSwitch_a[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = 0.0;
          _rtB->MultiportSwitch_a[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_a[0] = 1.0;
          _rtB->MultiportSwitch_a[1] = 0.0;
          _rtB->MultiportSwitch_a[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S59>/Multiport Switch' */
        _rtB->MultiportSwitch_gd[0] = _rtB->MultiportSwitch_a[0];
        _rtB->MultiportSwitch_gd[1] = _rtB->MultiportSwitch_a[1];
        _rtB->MultiportSwitch_gd[2] = _rtB->MultiportSwitch_a[2];
        break;

       case 3:
        /* MultiPortSwitch: '<S60>/Multiport Switch' incorporates:
         *  Constant: '<S60>/Us1'
         *  Constant: '<S60>/Us2'
         *  Constant: '<S60>/Us3'
         *  Constant: '<S60>/Us4'
         *  Constant: '<S60>/Us5'
         *  Constant: '<S60>/Us6'
         *  Constant: '<S60>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = 0.0;
          _rtB->MultiportSwitch_hr[2] = 1.0;
          break;

         case 2:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = (-1.0);
          _rtB->MultiportSwitch_hr[2] = 1.0;
          break;

         case 3:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = (-1.0);
          _rtB->MultiportSwitch_hr[2] = 0.0;
          break;

         case 4:
          _rtB->MultiportSwitch_hr[0] = 0.0;
          _rtB->MultiportSwitch_hr[1] = (-1.0);
          _rtB->MultiportSwitch_hr[2] = 0.0;
          break;

         case 5:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = (-1.0);
          _rtB->MultiportSwitch_hr[2] = 0.0;
          break;

         case 6:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = (-1.0);
          _rtB->MultiportSwitch_hr[2] = 1.0;
          break;

         default:
          _rtB->MultiportSwitch_hr[0] = 1.0;
          _rtB->MultiportSwitch_hr[1] = 0.0;
          _rtB->MultiportSwitch_hr[2] = 1.0;
          break;
        }

        /* End of MultiPortSwitch: '<S60>/Multiport Switch' */
        _rtB->MultiportSwitch_gd[0] = _rtB->MultiportSwitch_hr[0];
        _rtB->MultiportSwitch_gd[1] = _rtB->MultiportSwitch_hr[1];
        _rtB->MultiportSwitch_gd[2] = _rtB->MultiportSwitch_hr[2];
        break;

       default:
        /* MultiPortSwitch: '<S61>/Multiport Switch' incorporates:
         *  Constant: '<S61>/Us1'
         *  Constant: '<S61>/Us2'
         *  Constant: '<S61>/Us3'
         *  Constant: '<S61>/Us4'
         *  Constant: '<S61>/Us5'
         *  Constant: '<S61>/Us6'
         *  Constant: '<S61>/Us7'
         */
        switch ((int32_T)_rtB->Add7) {
         case 1:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = 0.0;
          _rtB->MultiportSwitch_cm[2] = 0.0;
          break;

         case 2:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = (-1.0);
          _rtB->MultiportSwitch_cm[2] = 0.0;
          break;

         case 3:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = (-1.0);
          _rtB->MultiportSwitch_cm[2] = (-1.0);
          break;

         case 4:
          _rtB->MultiportSwitch_cm[0] = 0.0;
          _rtB->MultiportSwitch_cm[1] = (-1.0);
          _rtB->MultiportSwitch_cm[2] = (-1.0);
          break;

         case 5:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = (-1.0);
          _rtB->MultiportSwitch_cm[2] = (-1.0);
          break;

         case 6:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = (-1.0);
          _rtB->MultiportSwitch_cm[2] = 0.0;
          break;

         default:
          _rtB->MultiportSwitch_cm[0] = 1.0;
          _rtB->MultiportSwitch_cm[1] = 0.0;
          _rtB->MultiportSwitch_cm[2] = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S61>/Multiport Switch' */
        _rtB->MultiportSwitch_gd[0] = _rtB->MultiportSwitch_cm[0];
        _rtB->MultiportSwitch_gd[1] = _rtB->MultiportSwitch_cm[1];
        _rtB->MultiportSwitch_gd[2] = _rtB->MultiportSwitch_cm[2];
        break;
      }

      /* End of MultiPortSwitch: '<S37>/Multiport Switch' */
      _rtB->MultiportSwitch_b[0] = _rtB->MultiportSwitch_gd[0];
      _rtB->MultiportSwitch_b[1] = _rtB->MultiportSwitch_gd[1];
      _rtB->MultiportSwitch_b[2] = _rtB->MultiportSwitch_gd[2];
      break;
    }

    /* End of MultiPortSwitch: '<S29>/Multiport Switch' */

    /* Outport: '<Root>/SPWM1' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->MultiportSwitch_b[0];
    ((real_T *)ssGetOutputPortSignal(S, 0))[1] = _rtB->MultiportSwitch_b[1];
    ((real_T *)ssGetOutputPortSignal(S, 0))[2] = _rtB->MultiportSwitch_b[2];

    /* Clock: '<S91>/Clock' */
    _rtB->Clock_n = ssGetT(S);

    /* Sum: '<S91>/Sum' incorporates:
     *  S-Function (sfun_tstart): '<S91>/startTime'
     */
    _rtB->Sum_c = _rtB->Clock_n - ssGetTStart(S);

    /* Math: '<S91>/Math Function' incorporates:
     *  Constant: '<S91>/Constant'
     */
    _rtB->MathFunction_a = DCU1_rt_remd_snf(_rtB->Sum_c, 0.0008);

    /* Lookup_n-D: '<S91>/Look-Up Table1' */
    _rtB->LookUpTable1_l = DCU1_look1_binlxpw(_rtB->MathFunction_a,
      DCU1_ConstP.pooled59, DCU1_ConstP.LookUpTable1_tableDat, 2U);

    /* SignalConversion: '<S91>/Output' */
    _rtB->Output_g = _rtB->LookUpTable1_l;

    /* Sum: '<S87>/Sum' incorporates:
     *  Constant: '<S1>/Ud+'
     */
    _rtB->Sum_cb = 2600.0 - _rtB->Add_f;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* DiscreteIntegrator: '<S92>/Integrator' */
    _rtB->Integrator_m = ((real_T *)ssGetDWork(S, 3))[0];

    /* Sum: '<S92>/Sum' */
    _rtB->Sum_mi = _rtB->Sum_cb + _rtB->Integrator_m;

    /* Gain: '<S92>/Proportional Gain' */
    _rtB->ProportionalGain_l = 0.5 * _rtB->Sum_mi;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S87>/Divide' incorporates:
     *  Constant: '<S87>/w1'
     *  Inport: '<Root>/Inport1'
     */
    _rtB->Divide_i = _rtB->Add_f * *((const real_T **)ssGetInputPortSignalPtrs(S,
      1))[0] / 1500.0;

    /* Sum: '<S87>/Sum1' */
    _rtB->Sum1_d = _rtB->ProportionalGain_l + _rtB->Divide_i;

    /* Clock: '<S87>/Clock' */
    _rtB->Clock_c = ssGetT(S);

    /* Product: '<S87>/Product2' incorporates:
     *  Constant: '<S87>/w'
     */
    _rtB->Product2_do = 314.15926535897933 * _rtB->Clock_c;

    /* Trigonometry: '<S87>/Sin(wt)' */
    _rtB->Sinwt = sin(_rtB->Product2_do);

    /* Product: '<S87>/Product1' */
    _rtB->Product1_g = _rtB->Sum1_d * _rtB->Sinwt;

    /* Sum: '<S87>/Sum2' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    _rtB->Sum2 = _rtB->Product1_g - *((const real_T **)ssGetInputPortSignalPtrs
      (S, 4))[0];

    /* Gain: '<S87>/G' */
    _rtB->G = 0.9 * _rtB->Sum2;

    /* Product: '<S87>/Product5' incorporates:
     *  Constant: '<S87>/Rn'
     */
    _rtB->Product5 = _rtB->Sum1_d * 0.2 * _rtB->Sinwt;

    /* Trigonometry: '<S87>/Cos(wt)' */
    _rtB->Coswt = cos(_rtB->Product2_do);

    /* Product: '<S87>/Product4' */
    _rtB->Product4 = _rtB->Sum1_d * DCU1_rtC(S)->Product3 * _rtB->Coswt;

    /* Sum: '<S87>/Add' incorporates:
     *  Inport: '<Root>/Inport3'
     */
    _rtB->Add_hq = (*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] -
                    _rtB->Product5) - _rtB->Product4;

    /* Sum: '<S87>/Sum3' */
    _rtB->Sum3 = _rtB->Add_hq - _rtB->G;

    /* Gain: '<S87>/G1' */
    _rtB->G1 = 1.0 * _rtB->Sum3;

    /* Gain: '<S86>/Uza7' */
    _rtB->Uza7 = 1.0 * _rtB->G1;

    /* RelationalOperator: '<S86>/Relational Operator' */
    _rtB->RelationalOperator_g = (_rtB->Output_g <= _rtB->Uza7);

    /* Gain: '<S86>/Uza1' */
    _rtB->Uza1 = (uint8_T)(_rtB->RelationalOperator_g ? ((uint8_T)128U) : 0);

    /* Gain: '<S86>/Uza' */
    _rtB->Uza = (-1.0) * _rtB->Output_g;

    /* RelationalOperator: '<S86>/Relational Operator1' */
    _rtB->RelationalOperator1_e = (_rtB->Uza >= _rtB->Uza7);

    /* Gain: '<S86>/Uza2' */
    _rtB->Uza2 = (int8_T)(_rtB->RelationalOperator1_e ? (-128) : 0);

    /* Sum: '<S86>/Add' */
    _rtB->Add_c = (int8_T)((_rtB->Uza1 + _rtB->Uza2) >> 1);

    /* Clock: '<S90>/Clock' */
    _rtB->Clock_k = ssGetT(S);

    /* Sum: '<S90>/Sum' incorporates:
     *  S-Function (sfun_tstart): '<S90>/startTime'
     */
    _rtB->Sum_f = _rtB->Clock_k - ssGetTStart(S);

    /* Math: '<S90>/Math Function' incorporates:
     *  Constant: '<S90>/Constant'
     */
    _rtB->MathFunction_l = DCU1_rt_remd_snf(_rtB->Sum_f, 0.0008);

    /* Lookup_n-D: '<S90>/Look-Up Table1' */
    _rtB->LookUpTable1_ll = DCU1_look1_binlxpw(_rtB->MathFunction_l,
      DCU1_ConstP.pooled59, DCU1_ConstP.LookUpTable1_tableD_l, 2U);

    /* SignalConversion: '<S90>/Output' */
    _rtB->Output_c = _rtB->LookUpTable1_ll;

    /* Gain: '<S86>/Uza3' */
    _rtB->Uza3 = (-1.0) * _rtB->G1;

    /* RelationalOperator: '<S86>/Relational Operator2' */
    _rtB->RelationalOperator2_i = (_rtB->Output_c <= _rtB->Uza3);

    /* Gain: '<S86>/Uza5' */
    _rtB->Uza5 = (uint8_T)(_rtB->RelationalOperator2_i ? ((uint8_T)128U) : 0);

    /* Gain: '<S86>/Uza4' */
    _rtB->Uza4 = (-1.0) * _rtB->Output_c;

    /* RelationalOperator: '<S86>/Relational Operator3' */
    _rtB->RelationalOperator3_l = (_rtB->Uza4 >= _rtB->Uza3);

    /* Gain: '<S86>/Uza6' */
    _rtB->Uza6 = (int8_T)(_rtB->RelationalOperator3_l ? (-128) : 0);

    /* Sum: '<S86>/Add1' */
    _rtB->Add1_b = (int8_T)((_rtB->Uza5 + _rtB->Uza6) >> 1);

    /* Sum: '<S85>/Add' incorporates:
     *  Inport: '<Root>/Inport2'
     *  Inport: '<Root>/Inport5'
     */
    _rtB->Add_l = *((const real_T **)ssGetInputPortSignalPtrs(S, 5))[0] - *((
      const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
  }

  /* Relay: '<S85>/Relay' */
  if (ssIsMajorTimeStep(S)) {
    if (_rtB->Add_l >= 1.0) {
      ((boolean_T *)ssGetDWork(S, 22))[0] = true;
    } else {
      if (_rtB->Add_l <= (-1.0)) {
        ((boolean_T *)ssGetDWork(S, 22))[0] = false;
      }
    }
  }

  if (((boolean_T *)ssGetDWork(S, 22))[0]) {
    _rtB->Relay = 1.0;
  } else {
    _rtB->Relay = (-1.0);
  }

  /* End of Relay: '<S85>/Relay' */
  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S85>/Product' incorporates:
     *  Inport: '<Root>/Inport3'
     *  Inport: '<Root>/Inport4'
     */
    _rtB->Product_b = *((const real_T **)ssGetInputPortSignalPtrs(S, 4))[0] *
      _rtB->Relay * *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0];

    /* MATLAB Function: '<S85>/NPC-Function' */
    /* MATLAB Function 'DCU1/DCU-Rectifier/NPC-fengxiaoyun/NPC-Function': '<S88>:1' */
    /* '<S88>:1:3' */
    _rtB->FLAG = 1.0;
    if (_rtB->Product_b > 0.0) {
      /* '<S88>:1:4' */
      if ((_rtB->Add_c == 64) && (_rtB->Add1_b == 0)) {
        /* '<S88>:1:6' */
        _rtB->FLAG = 2.0;
      } else {
        if ((_rtB->Add_c == 0) && (_rtB->Add1_b == 64)) {
          /* '<S88>:1:8' */
          _rtB->FLAG = 3.0;
        }
      }
    } else {
      if (_rtB->Product_b < 0.0) {
        /* '<S88>:1:11' */
        if ((_rtB->Add_c == 0) && (_rtB->Add1_b == -64)) {
          /* '<S88>:1:13' */
          _rtB->FLAG = 4.0;
        } else {
          if ((_rtB->Add_c == -64) && (_rtB->Add1_b == 0)) {
            /* '<S88>:1:15' */
            _rtB->FLAG = 5.0;
          }
        }
      }
    }

    /* End of MATLAB Function: '<S85>/NPC-Function' */

    /* MultiPortSwitch: '<S85>/Multiport Switch' incorporates:
     *  Constant: '<S85>/Constant'
     *  Constant: '<S85>/Constant1'
     *  Constant: '<S85>/Constant2'
     *  Constant: '<S85>/Constant3'
     */
    switch ((int32_T)_rtB->FLAG) {
     case 1:
      _rtB->MultiportSwitch_o[0] = (real_T)_rtB->Add_c * 0.015625;
      _rtB->MultiportSwitch_o[1] = (real_T)_rtB->Add1_b * 0.015625;
      break;

     case 2:
      _rtB->MultiportSwitch_o[0] = 0.0;
      _rtB->MultiportSwitch_o[1] = (-1.0);
      break;

     case 3:
      _rtB->MultiportSwitch_o[0] = (-1.0);
      _rtB->MultiportSwitch_o[1] = 0.0;
      break;

     case 4:
      _rtB->MultiportSwitch_o[0] = 1.0;
      _rtB->MultiportSwitch_o[1] = 0.0;
      break;

     default:
      _rtB->MultiportSwitch_o[0] = 0.0;
      _rtB->MultiportSwitch_o[1] = 1.0;
      break;
    }

    /* End of MultiPortSwitch: '<S85>/Multiport Switch' */

    /* Sum: '<S89>/Add' incorporates:
     *  Constant: '<S89>/Constant'
     */
    _rtB->Add_n[0] = _rtB->MultiportSwitch_o[0] + 2.0;
    _rtB->Add_n[1] = _rtB->MultiportSwitch_o[1] + 2.0;

    /* MultiPortSwitch: '<S89>/Multiport Switch' incorporates:
     *  Constant: '<S89>/S = -Ud'
     *  Constant: '<S89>/S = 0'
     *  Constant: '<S89>/S = Ud'
     */
    switch ((int32_T)_rtB->Add_n[0]) {
     case 1:
      _rtB->MultiportSwitch_l[0] = 0.0;
      _rtB->MultiportSwitch_l[1] = 0.0;
      _rtB->MultiportSwitch_l[2] = 1.0;
      _rtB->MultiportSwitch_l[3] = 1.0;
      break;

     case 2:
      _rtB->MultiportSwitch_l[0] = 0.0;
      _rtB->MultiportSwitch_l[1] = 1.0;
      _rtB->MultiportSwitch_l[2] = 1.0;
      _rtB->MultiportSwitch_l[3] = 0.0;
      break;

     default:
      _rtB->MultiportSwitch_l[0] = 1.0;
      _rtB->MultiportSwitch_l[1] = 1.0;
      _rtB->MultiportSwitch_l[2] = 0.0;
      _rtB->MultiportSwitch_l[3] = 0.0;
      break;
    }

    /* End of MultiPortSwitch: '<S89>/Multiport Switch' */

    /* MultiPortSwitch: '<S89>/Multiport Switch1' incorporates:
     *  Constant: '<S89>/S = -Ud'
     *  Constant: '<S89>/S = 0'
     *  Constant: '<S89>/S = Ud'
     */
    switch ((int32_T)_rtB->Add_n[1]) {
     case 1:
      _rtB->MultiportSwitch1_g[0] = 0.0;
      _rtB->MultiportSwitch1_g[1] = 0.0;
      _rtB->MultiportSwitch1_g[2] = 1.0;
      _rtB->MultiportSwitch1_g[3] = 1.0;
      break;

     case 2:
      _rtB->MultiportSwitch1_g[0] = 0.0;
      _rtB->MultiportSwitch1_g[1] = 1.0;
      _rtB->MultiportSwitch1_g[2] = 1.0;
      _rtB->MultiportSwitch1_g[3] = 0.0;
      break;

     default:
      _rtB->MultiportSwitch1_g[0] = 1.0;
      _rtB->MultiportSwitch1_g[1] = 1.0;
      _rtB->MultiportSwitch1_g[2] = 0.0;
      _rtB->MultiportSwitch1_g[3] = 0.0;
      break;
    }

    /* End of MultiPortSwitch: '<S89>/Multiport Switch1' */

    /* Outport: '<Root>/SPWM' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->MultiportSwitch_l[0];
    ((real_T *)ssGetOutputPortSignal(S, 1))[1] = _rtB->MultiportSwitch_l[1];
    ((real_T *)ssGetOutputPortSignal(S, 1))[2] = _rtB->MultiportSwitch_l[2];
    ((real_T *)ssGetOutputPortSignal(S, 1))[3] = _rtB->MultiportSwitch_l[3];
    ((real_T *)ssGetOutputPortSignal(S, 1))[4] = _rtB->MultiportSwitch1_g[0];
    ((real_T *)ssGetOutputPortSignal(S, 1))[5] = _rtB->MultiportSwitch1_g[1];
    ((real_T *)ssGetOutputPortSignal(S, 1))[6] = _rtB->MultiportSwitch1_g[2];
    ((real_T *)ssGetOutputPortSignal(S, 1))[7] = _rtB->MultiportSwitch1_g[3];
  }

  if (ssIsSampleHit(S, 1, tid)) {
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sin: '<S86>/Sine Wave' */
    _rtB->SineWave = sin(628.31853071795865 * ssGetTaskTime(S,0) + 0.0) * 1830.0
      + 0.0;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S92>/Integral Gain' */
    _rtB->IntegralGain_h = 9.0 * _rtB->Sum_cb;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_DCU1_T *_rtB;
  _rtB = ((B_DCU1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    ((real_T *)ssGetDWork(S, 0))[0] = 1.0E-5 * _rtB->Sum1 + ((real_T *)
      ssGetDWork(S, 0))[0];

    /* Update for DiscreteIntegrator: '<S18>/Integrator' */
    ((real_T *)ssGetDWork(S, 1))[0] = 5.0E-6 * _rtB->IntegralGain +
      _rtB->Integrator;

    /* Update for DiscreteIntegrator: '<S19>/Integrator' */
    ((real_T *)ssGetDWork(S, 2))[0] = 5.0E-6 * _rtB->IntegralGain_o +
      _rtB->Integrator_b;

    /* Update for DiscreteIntegrator: '<S92>/Integrator' */
    ((real_T *)ssGetDWork(S, 3))[0] = 1.0E-5 * _rtB->IntegralGain_h + ((real_T *)
      ssGetDWork(S, 3))[0];
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
  /* Parameter check for 'KIM' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'KIM' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'KIM' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'KIM' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'KIT' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'KIT' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'KIT' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'KIT' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'KPM' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'KPM' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'KPM' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'KPM' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'KPT' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'KPT' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'KPT' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'KPT' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Ts' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'Ts' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'Ts' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Ts' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Vge' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'Vge' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'Vge' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Vge' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'np' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'phir' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'phir' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'phir' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'phir' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "DCU1_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 2))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 8))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 9))
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
    ssSetInputPortSampleTime(S, 2, 0.0);
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
    ssSetInputPortSampleTime(S, 3, 1.0E-5);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortSampleTime(S, 4, 0.0);
    ssSetInputPortOffsetTime(S, 4, 0.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortSampleTime(S, 5, 0.0);
    ssSetInputPortOffsetTime(S, 5, 0.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 0.0);
    ssSetInputPortOffsetTime(S, 6, 0.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 7 */
  {
    if (!ssSetInputPortVectorDimension(S, 7, 3))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 7, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortSampleTime(S, 7, 0.0);
    ssSetInputPortOffsetTime(S, 7, 0.0);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 8 */
  {
    if (!ssSetInputPortVectorDimension(S, 8, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 8, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortSampleTime(S, 8, 0.0);
    ssSetInputPortOffsetTime(S, 8, 0.0);
    ssSetInputPortOverWritable(S, 8, 0);
    ssSetInputPortOptimOpts(S, 8, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 23)) {
    return;
  }

  /* '<S7>/Discrete-Time Integrator': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* '<S18>/Integrator': DSTATE */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkUsedAsDState(S, 1, 1);

  /* '<S19>/Integrator': DSTATE */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkUsedAsDState(S, 2, 1);

  /* '<S92>/Integrator': DSTATE */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);
  ssSetDWorkUsedAsDState(S, 3, 1);

  /* '<S11>/Scope1': PWORK */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);
  ssSetDWorkDataType(S, 4, SS_POINTER);

  /* '<S11>/Scope2': PWORK */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkDataType(S, 5, SS_POINTER);

  /* '<S11>/Scope3': PWORK */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 1);
  ssSetDWorkDataType(S, 6, SS_POINTER);

  /* '<S11>/Scope4': PWORK */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 1);
  ssSetDWorkDataType(S, 7, SS_POINTER);

  /* '<S84>/Scope': PWORK */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 1);
  ssSetDWorkDataType(S, 8, SS_POINTER);

  /* '<S84>/Scope1': PWORK */
  ssSetDWorkName(S, 9, "DWORK9");
  ssSetDWorkWidth(S, 9, 1);
  ssSetDWorkDataType(S, 9, SS_POINTER);

  /* '<S84>/Scope2': PWORK */
  ssSetDWorkName(S, 10, "DWORK10");
  ssSetDWorkWidth(S, 10, 1);
  ssSetDWorkDataType(S, 10, SS_POINTER);

  /* '<S84>/Scope3': PWORK */
  ssSetDWorkName(S, 11, "DWORK11");
  ssSetDWorkWidth(S, 11, 1);
  ssSetDWorkDataType(S, 11, SS_POINTER);

  /* '<S84>/Scope4': PWORK */
  ssSetDWorkName(S, 12, "DWORK12");
  ssSetDWorkWidth(S, 12, 1);
  ssSetDWorkDataType(S, 12, SS_POINTER);

  /* '<S84>/Scope5': PWORK */
  ssSetDWorkName(S, 13, "DWORK13");
  ssSetDWorkWidth(S, 13, 1);
  ssSetDWorkDataType(S, 13, SS_POINTER);

  /* '<S84>/Scope6': PWORK */
  ssSetDWorkName(S, 14, "DWORK14");
  ssSetDWorkWidth(S, 14, 1);
  ssSetDWorkDataType(S, 14, SS_POINTER);

  /* '<S84>/Scope7': PWORK */
  ssSetDWorkName(S, 15, "DWORK15");
  ssSetDWorkWidth(S, 15, 1);
  ssSetDWorkDataType(S, 15, SS_POINTER);

  /* '<S89>/Scope': PWORK */
  ssSetDWorkName(S, 16, "DWORK16");
  ssSetDWorkWidth(S, 16, 1);
  ssSetDWorkDataType(S, 16, SS_POINTER);

  /* '<S86>/Scope': PWORK */
  ssSetDWorkName(S, 17, "DWORK17");
  ssSetDWorkWidth(S, 17, 1);
  ssSetDWorkDataType(S, 17, SS_POINTER);

  /* '<S86>/Scope1': PWORK */
  ssSetDWorkName(S, 18, "DWORK18");
  ssSetDWorkWidth(S, 18, 1);
  ssSetDWorkDataType(S, 18, SS_POINTER);

  /* '<S86>/Scope2': PWORK */
  ssSetDWorkName(S, 19, "DWORK19");
  ssSetDWorkWidth(S, 19, 1);
  ssSetDWorkDataType(S, 19, SS_POINTER);

  /* '<S86>/Scope3': PWORK */
  ssSetDWorkName(S, 20, "DWORK20");
  ssSetDWorkWidth(S, 20, 1);
  ssSetDWorkDataType(S, 20, SS_POINTER);

  /* '<S86>/Add': DWORK1 */
  ssSetDWorkName(S, 21, "DWORK21");
  ssSetDWorkWidth(S, 21, 1);
  ssSetDWorkDataType(S, 21, SS_INT32);

  /* '<S85>/Relay': Mode */
  ssSetDWorkName(S, 22, "DWORK22");
  ssSetDWorkWidth(S, 22, 1);
  ssSetDWorkDataType(S, 22, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 8);

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
    ssSupportsMultipleExecInstances(S, false);
    ssRegisterMsgForNotSupportingMultiExecInst(S,
      "<diag_root><diag id=\"Simulink:blocks:BlockDoesNotSupportMultiExecInstances\"><arguments><arg type=\"encoded\">RABDAFUAMQAvAEQAQwBVADEALwBEAEMAVQAtAEkAbgB2AGUAcgB0AGUAcgAvAFMAVgBQAFcATQAgAEcAZQBuAHIAYQB0AG8AcgBmAHgAeQAvAFQAaQBtAGUAIABTAGUAdAB0AGkAbgBnAC8AVAByAGkAZwBnAGwAZQAgAEcAZQBuAGUAcgBhAHQAbwByAC8AUgBlAHAAZQBhAHQAaQBuAGcAIABTAGUAcQB1AGUAbgBjAGUALwBzAHQAYQByAHQAVABpAG0AZQAAAA==</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments></diag>\n</diag_root>");
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
# define S_FUNCTION_NAME               DCU1_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
