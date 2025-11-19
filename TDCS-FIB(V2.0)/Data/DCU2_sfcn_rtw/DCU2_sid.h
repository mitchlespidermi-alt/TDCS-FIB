/*
 * DCU2_sid.h
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
 *
 * SOURCES: DCU2_sf.c
 */

/* statically allocated instance data for model: DCU2 */
{
  extern P_DCU2_T DCU2_DefaultP;
  extern const ConstB_DCU2_T DCU2_Invariant;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_DCU2_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_DCU2_T));
    }

    _ssSetConstBlockIO(rts, &DCU2_Invariant);

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &DCU2_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1676020083U);
    ssSetChecksumVal(rts, 1, 3642293473U);
    ssSetChecksumVal(rts, 2, 117469499U);
    ssSetChecksumVal(rts, 3, 4196989266U);
  }
}
