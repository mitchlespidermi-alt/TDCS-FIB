/*
 * MeasurementF_sid.h
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
 *
 * SOURCES: MeasurementF_sf.c
 */

/* statically allocated instance data for model: MeasurementF */
{
  extern P_MeasurementF_T MeasurementF_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_MeasurementF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_MeasurementF_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &MeasurementF_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2991729852U);
    ssSetChecksumVal(rts, 1, 595551066U);
    ssSetChecksumVal(rts, 2, 1492898802U);
    ssSetChecksumVal(rts, 3, 42023051U);
  }
}
