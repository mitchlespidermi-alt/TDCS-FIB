/*
 * MeasurementN_sf_data.c
 *
 * Code generation for model "MeasurementN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:26:18 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "MeasurementN_sf.h"
#include "MeasurementN_sf_private.h"

/* Block parameters (auto storage) */
P_MeasurementN_T MeasurementN_DefaultP = {
  0.4,                                 /* Variable: J
                                        * Referenced by: '<S1>/machine'
                                        */
  0.032848,                            /* Variable: Lm
                                        * Referenced by: '<S1>/Np.Lm'
                                        */
  2.0                                  /* Variable: np
                                        * Referenced by:
                                        *   '<S1>/machine'
                                        *   '<S1>/Np.Lm'
                                        */
};
