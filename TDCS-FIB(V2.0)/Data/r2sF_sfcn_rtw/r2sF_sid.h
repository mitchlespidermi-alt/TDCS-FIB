/*
 * r2sF_sid.h
 *
 * Code generation for model "r2sF_sf".
 *
 * Model version              : 1.165
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Jul 24 15:35:53 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: r2sF_sf.c
 */

/* statically allocated instance data for model: r2sF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_r2sF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_r2sF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 402304130U);
    ssSetChecksumVal(rts, 1, 2527959765U);
    ssSetChecksumVal(rts, 2, 3654136867U);
    ssSetChecksumVal(rts, 3, 1893692327U);
  }
}
