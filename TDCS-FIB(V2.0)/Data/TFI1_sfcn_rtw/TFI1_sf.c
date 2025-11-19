/*
 * TFI1_sf.c
 *
 * Code generation for model "TFI1_sf".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 20:55:06 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "TFI1_sf.h"
#include "TFI1_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *TFI1_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void TFI1_dec2bin(real_T d, char_T s_data[52], int32_T s_sizes[2]);
static real_T TFI1_bin2dec(const char_T s_data[52], const int32_T s_sizes[2]);
static void TFI1_dec2bin_c(real_T d, char_T s_data[52], int32_T s_sizes[2]);
static real_T TFI1_rand(SimStruct *S);
static real_T TFI1_bin2dec_d(const char_T s_data[52], const int32_T s_sizes[2]);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void TFI1_dec2bin(real_T d, char_T s_data[52], int32_T s_sizes[2])
{
  real_T di;
  real_T olddi;
  int32_T j;
  int32_T firstcol;
  boolean_T p;
  boolean_T exitg;
  char_T s_data_0[52];
  s_sizes[0] = 1;
  s_sizes[1] = 52;
  for (j = 0; j < 52; j++) {
    s_data[j] = '0';
  }

  di = d;
  j = 52;
  exitg = FALSE;
  while ((!exitg) && (j > 0)) {
    olddi = di;
    di = floor(di / 2.0);
    if (2.0 * di < olddi) {
      s_data[j - 1] = '1';
    }

    if (di > 0.0) {
      j--;
    } else {
      exitg = TRUE;
    }
  }

  firstcol = 37;
  j = 1;
  exitg = FALSE;
  while ((!exitg) && (j <= 36)) {
    p = FALSE;
    if (s_data[j - 1] != '0') {
      p = TRUE;
    }

    if (p) {
      firstcol = j;
      exitg = TRUE;
    } else {
      j++;
    }
  }

  if (firstcol > 1) {
    for (j = firstcol; j < 53; j++) {
      s_data[j - firstcol] = s_data[j - 1];
    }

    firstcol = 53 - firstcol;
    for (j = 0; j < firstcol; j++) {
      s_data_0[j] = s_data[j];
    }

    s_sizes[0] = 1;
    s_sizes[1] = firstcol;
    for (j = 0; j < firstcol; j++) {
      s_data[j] = s_data_0[j];
    }
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static real_T TFI1_bin2dec(const char_T s_data[52], const int32_T s_sizes[2])
{
  real_T x;
  real_T p;
  int32_T j;
  x = 0.0;
  p = 1.0;
  for (j = 0; j < s_sizes[1]; j++) {
    if (s_data[((s_sizes[1] - j) - 1) * s_sizes[0]] == '1') {
      x += p;
    }

    p += p;
  }

  return x;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static void TFI1_dec2bin_c(real_T d, char_T s_data[52], int32_T s_sizes[2])
{
  real_T di;
  real_T olddi;
  int32_T j;
  int32_T firstcol;
  boolean_T p;
  boolean_T exitg;
  char_T s_data_0[52];
  s_sizes[0] = 1;
  s_sizes[1] = 52;
  for (j = 0; j < 52; j++) {
    s_data[j] = '0';
  }

  di = d;
  j = 52;
  exitg = FALSE;
  while ((!exitg) && (j > 0)) {
    olddi = di;
    di = floor(di / 2.0);
    if (2.0 * di < olddi) {
      s_data[j - 1] = '1';
    }

    if (di > 0.0) {
      j--;
    } else {
      exitg = TRUE;
    }
  }

  firstcol = 37;
  j = 1;
  exitg = FALSE;
  while ((!exitg) && (j <= 36)) {
    p = FALSE;
    if (s_data[j - 1] != '0') {
      p = TRUE;
    }

    if (p) {
      firstcol = j;
      exitg = TRUE;
    } else {
      j++;
    }
  }

  if (firstcol > 1) {
    for (j = firstcol; j < 53; j++) {
      s_data[j - firstcol] = s_data[j - 1];
    }

    firstcol = 53 - firstcol;
    for (j = 0; j < firstcol; j++) {
      s_data_0[j] = s_data[j];
    }

    s_sizes[0] = 1;
    s_sizes[1] = firstcol;
    for (j = 0; j < firstcol; j++) {
      s_data[j] = s_data_0[j];
    }
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static real_T TFI1_rand(SimStruct *S)
{
  real_T b_r;
  uint32_T u[2];
  uint32_T y;
  int32_T j;
  int32_T k;
  boolean_T b_isvalid;
  uint32_T c_r;
  int32_T exitg;
  boolean_T exitg_0;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg = 0;
    u[0] = 0U;
    u[1] = 0U;
    for (j = 0; j < 2; j++) {
      c_r = ((uint32_T *)ssGetDWork(S, 0))[624] + 1U;
      if (c_r >= 625U) {
        for (k = 0; k < 227; k++) {
          y = (((uint32_T *)ssGetDWork(S, 0))[1 + k] & 2147483647U) |
            (((uint32_T *)ssGetDWork(S, 0))[k] & 2147483648U);
          if ((int32_T)(y & 1U) == 0) {
            c_r = y >> 1U;
          } else {
            c_r = y >> 1U ^ 2567483615U;
          }

          ((uint32_T *)ssGetDWork(S, 0))[k] = ((uint32_T *)ssGetDWork(S, 0))[397
            + k] ^ c_r;
        }

        for (k = 0; k < 396; k++) {
          y = (((uint32_T *)ssGetDWork(S, 0))[227 + k] & 2147483648U) |
            (((uint32_T *)ssGetDWork(S, 0))[228 + k] & 2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            c_r = y >> 1U;
          } else {
            c_r = y >> 1U ^ 2567483615U;
          }

          ((uint32_T *)ssGetDWork(S, 0))[227 + k] = ((uint32_T *)ssGetDWork(S, 0))
            [k] ^ c_r;
        }

        y = (((uint32_T *)ssGetDWork(S, 0))[623] & 2147483648U) | (((uint32_T *)
          ssGetDWork(S, 0))[0] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          c_r = y >> 1U;
        } else {
          c_r = y >> 1U ^ 2567483615U;
        }

        ((uint32_T *)ssGetDWork(S, 0))[623] = ((uint32_T *)ssGetDWork(S, 0))[396]
          ^ c_r;
        c_r = 1U;
      }

      y = ((uint32_T *)ssGetDWork(S, 0))[(int32_T)c_r - 1];
      ((uint32_T *)ssGetDWork(S, 0))[624] = c_r;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[j] = y;
    }

    b_r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (b_r == 0.0) {
      if ((((uint32_T *)ssGetDWork(S, 0))[624] >= 1U) && (((uint32_T *)
            ssGetDWork(S, 0))[624] < 625U)) {
        b_isvalid = TRUE;
      } else {
        b_isvalid = FALSE;
      }

      if (b_isvalid) {
        b_isvalid = FALSE;
        k = 1;
        exitg_0 = FALSE;
        while ((!exitg_0) && (k < 625)) {
          if (((uint32_T *)ssGetDWork(S, 0))[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = TRUE;
            exitg_0 = TRUE;
          }
        }
      }

      if (!b_isvalid) {
        c_r = 5489U;
        ((uint32_T *)ssGetDWork(S, 0))[0] = 5489U;
        for (k = 0; k < 623; k++) {
          c_r = ((c_r >> 30U ^ c_r) * 1812433253U + k) + 1U;
          ((uint32_T *)ssGetDWork(S, 0))[1 + k] = c_r;
        }

        ((uint32_T *)ssGetDWork(S, 0))[624] = 624U;
      }
    } else {
      exitg = 1;
    }
  } while (exitg == 0);

  return b_r;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static real_T TFI1_bin2dec_d(const char_T s_data[52], const int32_T s_sizes[2])
{
  real_T x;
  real_T p;
  int32_T j;
  x = 0.0;
  p = 1.0;
  for (j = 0; j < s_sizes[1]; j++) {
    if (s_data[((s_sizes[1] - j) - 1) * s_sizes[0]] == '1') {
      x += p;
    }

    p += p;
  }

  return x;
}

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  uint32_T r;
  int32_T mti;

  /* InitializeConditions for MATLAB Function: '<S2>/MATLAB Function1' */
  memset(&((uint32_T *)ssGetDWork(S, 0))[0], 0, 625U * sizeof(uint32_T));
  r = 5489U;
  ((uint32_T *)ssGetDWork(S, 0))[0] = 5489U;
  for (mti = 0; mti < 623; mti++) {
    r = ((r >> 30U ^ r) * 1812433253U + mti) + 1U;
    ((uint32_T *)ssGetDWork(S, 0))[1 + mti] = r;
  }

  ((uint32_T *)ssGetDWork(S, 0))[624] = 624U;

  /* End of InitializeConditions for MATLAB Function: '<S2>/MATLAB Function1' */
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

  TFI1_malloc(S);
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
  real_T randdata;
  char_T bin_data[52];
  int32_T bin_sizes[2];
  B_TFI1_T *_rtB;
  _rtB = ((B_TFI1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S11>/Constant' */
    _rtB->Constant = (*(real_T *)(mxGetData(Comp_ConV(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec' */
    randdata = ssGetTaskTime(S,0);
    if (randdata < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->FaultSelec = 1.0;
    } else {
      _rtB->FaultSelec = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec' */

    /* Step: '<S16>/Step' */
    randdata = ssGetTaskTime(S,0);
    if (randdata < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step = 0.0;
    } else {
      _rtB->Step = 1.0;
    }

    /* End of Step: '<S16>/Step' */

    /* Clock: '<S16>/Clock' */
    ((B_TFI1_T *) ssGetLocalBlockIO(S))->Clock = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S16>/Constant' */
    _rtB->Constant_h = (*(real_T *)(mxGetData(FaultInjectionTime(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
     *  Constant: '<S3>/0'
     *  Inport: '<Root>/Outside Signal'
     */
    switch ((int32_T)_rtB->FaultSelec) {
     case 1:
     case 3:
     case 4:
      _rtB->MultiportSwitch = 0.0;
      break;

     case 2:
      /* Sum: '<S16>/Sum' */
      _rtB->Sum = _rtB->Clock - _rtB->Constant_h;

      /* Product: '<S16>/Product' */
      _rtB->Product_c = _rtB->Step * _rtB->Sum;

      /* Sum: '<S16>/Output' incorporates:
       *  Constant: '<S16>/Constant1'
       */
      _rtB->Output = _rtB->Product_c + 0.0;

      /* Fcn: '<S3>/Fcn' */
      _rtB->Fcn = (exp(-500.0 * _rtB->Output) - exp(-1000.0 * _rtB->Output)) *
        25.0;
      _rtB->MultiportSwitch = _rtB->Fcn;
      break;

     default:
      _rtB->MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
        [0];
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

    /* Sum: '<S1>/Add' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    _rtB->Add = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] +
      _rtB->MultiportSwitch;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S4>/Constant' */
    _rtB->Constant_hf = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S10>/Constant' */
    _rtB->Constant_g = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S4>/Constant1' */
    _rtB->Constant1 = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S13>/Constant' */
    _rtB->Constant_n = (*(real_T *)(mxGetData(Comp_ConV(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S1>/Product' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    _rtB->Product = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] *
      _rtB->MultiportSwitch;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S8>/Constant2' */
    _rtB->Constant2 = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S12>/Constant' */
    _rtB->Constant_b = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S8>/Constant3' */
    _rtB->Constant3 = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Logic: '<S3>/Logical' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    randdata = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Logical = !(randdata != 0.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec1' */
    randdata = ssGetTaskTime(S,0);
    if (randdata < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->FaultSelec1 = 1.0;
    } else {
      _rtB->FaultSelec1 = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec1' */

    /* RelationalOperator: '<S14>/Compare' incorporates:
     *  Constant: '<S14>/Constant'
     */
    _rtB->Compare = (_rtB->FaultSelec1 == 5.0);

    /* Logic: '<S3>/Logical ' */
    _rtB->Logical_b = (_rtB->Logical && _rtB->Compare);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* RelationalOperator: '<S15>/Compare' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S3>/Constant2'
     */
    randdata = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Compare_n = (randdata == 5.0);

    /* MultiPortSwitch: '<S3>/Multiport1' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Constant: '<S3>/Constant4'
     */
    if (_rtB->Compare_n == 0) {
      _rtB->Multiport1 = 5.0;
    } else {
      _rtB->Multiport1 = 6.0;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport1' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport  ' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    if (_rtB->Logical_b == 0) {
      /* Logic: '<S3>/Logical Operator' incorporates:
       *  Constant: '<S3>/Constant2'
       */
      randdata = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
      _rtB->LogicalOperator = ((randdata != 0.0) && _rtB->Compare);

      /* MultiPortSwitch: '<S3>/Multiport' */
      if (_rtB->LogicalOperator == 0) {
        _rtB->Multiport_g = _rtB->FaultSelec1;
      } else {
        _rtB->Multiport_g = _rtB->Multiport1;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport' */
      _rtB->Multiport = _rtB->Multiport_g;
    } else {
      _rtB->Multiport = 2.0;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport  ' */

    /* MultiPortSwitch: '<S3>/Multiport Switch1' incorporates:
     *  Constant: '<S3>/ '
     *  Constant: '<S3>/  '
     *  Constant: '<S3>/   '
     *  Constant: '<S3>/   1'
     */
    switch ((int32_T)_rtB->Multiport) {
     case 1:
     case 3:
     case 4:
      _rtB->MultiportSwitch1 = 7.0;
      break;

     case 2:
      _rtB->MultiportSwitch1 = 1.0;
      break;

     case 5:
      _rtB->MultiportSwitch1 = 4.0;
      break;

     default:
      _rtB->MultiportSwitch1 = 8.0;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch1' */

    /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    switch ((int32_T)_rtB->MultiportSwitch1) {
     case 1:
      _rtB->MultiportSwitch2 = _rtB->Add;
      break;

     case 2:
      /* RelationalOperator: '<S11>/Compare' */
      _rtB->Compare_k = (_rtB->Add >= _rtB->Constant);

      /* MultiPortSwitch: '<S4>/Switch' */
      if (_rtB->Compare_k == 0) {
        _rtB->Switch_k = _rtB->Add;
      } else {
        _rtB->Switch_k = _rtB->Constant_hf;
      }

      /* End of MultiPortSwitch: '<S4>/Switch' */
      _rtB->MultiportSwitch2 = _rtB->Switch_k;
      break;

     case 3:
      /* RelationalOperator: '<S10>/Compare' */
      _rtB->Compare_a = (_rtB->Add <= _rtB->Constant_g);

      /* MultiPortSwitch: '<S4>/Switch2' */
      if (_rtB->Compare_a == 0) {
        _rtB->Switch2 = _rtB->Add;
      } else {
        _rtB->Switch2 = _rtB->Constant1;
      }

      /* End of MultiPortSwitch: '<S4>/Switch2' */
      _rtB->MultiportSwitch2 = _rtB->Switch2;
      break;

     case 4:
      _rtB->MultiportSwitch2 = _rtB->Product;
      break;

     case 5:
      /* RelationalOperator: '<S13>/Compare' */
      _rtB->Compare_b = (_rtB->Product >= _rtB->Constant_n);

      /* MultiPortSwitch: '<S8>/Switch3' */
      if (_rtB->Compare_b == 0) {
        _rtB->Switch3 = _rtB->Product;
      } else {
        _rtB->Switch3 = _rtB->Constant2;
      }

      /* End of MultiPortSwitch: '<S8>/Switch3' */
      _rtB->MultiportSwitch2 = _rtB->Switch3;
      break;

     case 6:
      /* RelationalOperator: '<S12>/Compare' */
      _rtB->Compare_j = (_rtB->Product <= _rtB->Constant_b);

      /* MultiPortSwitch: '<S8>/Switch4' */
      if (_rtB->Compare_j == 0) {
        _rtB->Switch4 = _rtB->Product;
      } else {
        _rtB->Switch4 = _rtB->Constant3;
      }

      /* End of MultiPortSwitch: '<S8>/Switch4' */
      _rtB->MultiportSwitch2 = _rtB->Switch4;
      break;

     case 7:
      _rtB->MultiportSwitch2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
        [0];
      break;

     default:
      _rtB->MultiportSwitch2 = _rtB->MultiportSwitch;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

    /* Step: '<S9>/Step' */
    randdata = ssGetTaskTime(S,0);
    if (randdata < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step_f = 0.0;
    } else {
      _rtB->Step_f = 1.0;
    }

    /* End of Step: '<S9>/Step' */

    /* Clock: '<S9>/Clock' */
    ((B_TFI1_T *) ssGetLocalBlockIO(S))->Clock_l = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S9>/Constant' */
    _rtB->Constant_p = (*(real_T *)(mxGetData(FaultInjectionTime(S))));

    /* Constant: '<S5>/Constant' */
    _rtB->Constant_ha = (*(real_T *)(mxGetData(TH(S))));

    /* Sum: '<S2>/Add1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     */
    _rtB->Add1 = 18.0 - (*(real_T *)(mxGetData(InvertBit(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S2>/FaultSelec' */
    randdata = ssGetTaskTime(S,0);
    if (randdata < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->FaultSelec_a = 1.0;
    } else {
      _rtB->FaultSelec_a = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S2>/FaultSelec' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  Inport: '<Root>/Inport2'
     */
    randdata = _rtB->Add1;

    /* MATLAB Function 'TFI1/Logic Operation/MATLAB Function': '<S6>:1' */
    /* FA Summary of this function goes here */
    /*    Detailed explanation goes here */
    if (_rtB->Add1 == 17.0) {
      /* '<S6>:1:4' */
      /* '<S6>:1:5' */
      randdata = 1.0;
    }

    if (*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] < 0.0) {
      /* '<S6>:1:7' */
      /* '<S6>:1:8' */
      /* '<S6>:1:9' */
      TFI1_dec2bin(-*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0],
                   bin_data, bin_sizes);
      if (bin_data[(int32_T)randdata - 1] == '1') {
        /* '<S6>:1:12' */
        /* '<S6>:1:13' */
        bin_data[(int32_T)randdata - 1] = '0';
      } else {
        /* '<S6>:1:15' */
        bin_data[(int32_T)randdata - 1] = '1';
      }

      /*      bin; */
      /* '<S6>:1:18' */
      randdata = TFI1_bin2dec(bin_data, bin_sizes);

      /* '<S6>:1:19' */
      randdata = -randdata;
    } else {
      /* '<S6>:1:21' */
      TFI1_dec2bin(*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0],
                   bin_data, bin_sizes);
      if (bin_data[(int32_T)randdata - 1] == '1') {
        /* '<S6>:1:24' */
        /* '<S6>:1:25' */
        bin_data[(int32_T)randdata - 1] = '0';
      } else {
        /* '<S6>:1:27' */
        bin_data[(int32_T)randdata - 1] = '1';
      }

      /*      bin; */
      /* '<S6>:1:30' */
      randdata = TFI1_bin2dec(bin_data, bin_sizes);
    }

    _rtB->y_b = randdata;

    /* End of MATLAB Function: '<S2>/MATLAB Function' */

    /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
     *  Inport: '<Root>/Inport2'
     */
    /* MATLAB Function 'TFI1/Logic Operation/MATLAB Function1': '<S7>:1' */
    /* FA Summary of this function goes here */
    /*    Detailed explanation goes here */
    if (*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] < 0.0) {
      /* '<S7>:1:4' */
      /* '<S7>:1:5' */
      /* '<S7>:1:6' */
      TFI1_dec2bin_c(-*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0],
                     bin_data, bin_sizes);

      /* '<S7>:1:7' */
      randdata = TFI1_rand(S);
      randdata = floor(randdata * 16.0);
      if (bin_data[(int32_T)(1.0 + randdata) - 1] == '1') {
        /* '<S7>:1:9' */
        /* '<S7>:1:10' */
        bin_data[(int32_T)(1.0 + randdata) - 1] = '0';
      } else {
        /* '<S7>:1:12' */
        bin_data[(int32_T)(1.0 + randdata) - 1] = '1';
      }

      /*   bin; */
      /* '<S7>:1:15' */
      randdata = TFI1_bin2dec_d(bin_data, bin_sizes);

      /* '<S7>:1:16' */
      randdata = -randdata;
    } else {
      /* '<S7>:1:18' */
      TFI1_dec2bin_c(*((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0],
                     bin_data, bin_sizes);

      /* '<S7>:1:19' */
      randdata = TFI1_rand(S);
      randdata = floor(randdata * 16.0);
      if (bin_data[(int32_T)(1.0 + randdata) - 1] == '1') {
        /* '<S7>:1:21' */
        /* '<S7>:1:22' */
        bin_data[(int32_T)(1.0 + randdata) - 1] = '0';
      } else {
        /* '<S7>:1:24' */
        bin_data[(int32_T)(1.0 + randdata) - 1] = '1';
      }

      /*   bin; */
      /* '<S7>:1:27' */
      randdata = TFI1_bin2dec_d(bin_data, bin_sizes);
    }

    _rtB->y = randdata;

    /* End of MATLAB Function: '<S2>/MATLAB Function1' */

    /* MultiPortSwitch: '<S2>/Multiport Switch3' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    if ((int32_T)(*(real_T *)(mxGetData(InvertBit(S)))) == 1) {
      _rtB->MultiportSwitch3 = _rtB->y;
    } else {
      _rtB->MultiportSwitch3 = _rtB->y_b;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch3' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S2>/Multiport Switch1' */
    switch ((int32_T)_rtB->FaultSelec_a) {
     case 1:
     case 2:
     case 5:
      _rtB->MultiportSwitch1_i = _rtB->MultiportSwitch2;
      break;

     case 3:
      /* Sum: '<S9>/Sum' */
      _rtB->Sum_n = _rtB->Clock_l - _rtB->Constant_p;

      /* Product: '<S9>/Product' */
      _rtB->Product_k = _rtB->Step_f * _rtB->Sum_n;

      /* Sum: '<S9>/Output' incorporates:
       *  Constant: '<S9>/Constant1'
       */
      _rtB->Output_j = _rtB->Product_k + 0.0;

      /* Fcn: '<S2>/Fcn' */
      _rtB->Fcn_b = (exp(-500.0 * _rtB->Output_j) - exp(-1000.0 * _rtB->Output_j))
        * 25.0;

      /* RelationalOperator: '<S5>/Compare' */
      _rtB->Compare_o = (_rtB->Fcn_b >= _rtB->Constant_ha);

      /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
       *  Constant: '<S2>/Constant'
       */
      if (_rtB->Compare_o == 0) {
        _rtB->MultiportSwitch_d = _rtB->MultiportSwitch2;
      } else {
        _rtB->MultiportSwitch_d = 1.0;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch' */
      _rtB->MultiportSwitch1_i = _rtB->MultiportSwitch_d;
      break;

     default:
      _rtB->MultiportSwitch1_i = _rtB->MultiportSwitch3;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch1' */
  }

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
    /* Sum: '<S1>/NoiseAdd' */
    _rtB->NoiseAdd = _rtB->Switch + _rtB->MultiportSwitch1_i;

    /* Outport: '<Root>/Out' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->NoiseAdd;

    /* Outport: '<Root>/Outport3' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->MultiportSwitch2;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
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

  /* Parameter check for 'Comp_ConV' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a [1x1] array.");
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

  /* Parameter check for 'InvertBit' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'InvertBit' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'InvertBit' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'InvertBit' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'NoiseSelec' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'TH' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'TH' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'TH' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'TH' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "TFI1_mid.h"
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
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

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
    ssSetInputPortSampleTime(S, 3, 1.0E-5);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 1)) {
    return;
  }

  /* '<S2>/MATLAB Function1': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 625);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 7);

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
# define S_FUNCTION_NAME               TFI1_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
