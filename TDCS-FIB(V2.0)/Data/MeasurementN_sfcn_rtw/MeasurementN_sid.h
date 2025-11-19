/*
 * MeasurementN_sid.h
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
 *
 * SOURCES: MeasurementN_sf.c
 */

/* statically allocated instance data for model: MeasurementN */
{
  extern P_MeasurementN_T MeasurementN_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_MeasurementN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_MeasurementN_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &MeasurementN_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1147727619U);
    ssSetChecksumVal(rts, 1, 607221941U);
    ssSetChecksumVal(rts, 2, 2504028915U);
    ssSetChecksumVal(rts, 3, 3417969091U);
  }
}
