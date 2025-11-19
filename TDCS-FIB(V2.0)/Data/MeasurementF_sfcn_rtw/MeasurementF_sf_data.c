/*
 * MeasurementF_sf_data.c
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
#include "MeasurementF_sf.h"
#include "MeasurementF_sf_private.h"

/* Block parameters (auto storage) */
P_MeasurementF_T MeasurementF_DefaultP = {
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
