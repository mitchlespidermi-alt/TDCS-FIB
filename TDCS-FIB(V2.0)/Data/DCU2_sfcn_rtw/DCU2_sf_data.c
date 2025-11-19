/*
 * DCU2_sf_data.c
 *
 * Code generation for model "DCU2_sf".
 *
 * Model version              : 1.77
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Oct 31 17:24:19 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "DCU2_sf.h"
#include "DCU2_sf_private.h"

/* Invariant block signals (auto storage) */
const ConstB_DCU2_T DCU2_Invariant = {
  92.2944
  ,                                    /* '<S84>/Product' */
  92.2944
  ,                                    /* '<S75>/Product' */
  92.2944
  ,                                    /* '<S67>/Product' */
  92.2944
  ,                                    /* '<S62>/Product' */
  0.62831853071795862
  /* '<S87>/Product3' */
};

/* Block parameters (auto storage) */
P_DCU2_T DCU2_DefaultP = {
  0.0,                                 /* Variable: KIM
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  0.0,                                 /* Variable: KIT
                                        * Referenced by: '<S19>/Integral Gain'
                                        */
  5.0,                                 /* Variable: KPM
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  9.0,                                 /* Variable: KPT
                                        * Referenced by: '<S19>/Proportional Gain'
                                        */
  0.0001,                              /* Variable: Ts
                                        * Referenced by: '<S10>/Ts'
                                        */
  200.0,                               /* Variable: Vge
                                        * Referenced by:
                                        *   '<S65>/Constant1'
                                        *   '<S75>/Constant8'
                                        *   '<S84>/Constant5'
                                        */
  2.0,                                 /* Variable: np
                                        * Referenced by: '<S2>/Gain'
                                        */
  1.8576                               /* Variable: phir
                                        * Referenced by: '<S9>/perpetual'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_DCU2_T DCU2_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S30>/Look-Up Table1'
   */
  { 0.0, 0.0001 },

  /* Expression: rep_seq_y
   * Referenced by: '<S91>/Look-Up Table1'
   */
  { 0.0, 1838.4776310850234, 0.0 },

  /* Pooled Parameter (Expression: rep_seq_t - min(rep_seq_t))
   * Referenced by:
   *   '<S90>/Look-Up Table1'
   *   '<S91>/Look-Up Table1'
   */
  { 0.0, 0.0004, 0.0008 },

  /* Expression: rep_seq_y
   * Referenced by: '<S90>/Look-Up Table1'
   */
  { 1838.4776310850234, 0.0, 1838.4776310850234 }
};
