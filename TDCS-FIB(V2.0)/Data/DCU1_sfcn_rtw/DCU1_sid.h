/*
 * DCU1_sid.h
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
 *
 * SOURCES: DCU1_sf.c
 */

/* statically allocated instance data for model: DCU1 */
{
  extern P_DCU1_T DCU1_DefaultP;
  extern const ConstB_DCU1_T DCU1_Invariant;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_DCU1_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_DCU1_T));
    }

    _ssSetConstBlockIO(rts, &DCU1_Invariant);

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &DCU1_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 976881234U);
    ssSetChecksumVal(rts, 1, 2821876106U);
    ssSetChecksumVal(rts, 2, 718134262U);
    ssSetChecksumVal(rts, 3, 1633380478U);
  }
}
