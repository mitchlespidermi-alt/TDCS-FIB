/*
 * r2sN_sid.h
 *
 * Code generation for model "r2sN_sf".
 *
 * Model version              : 1.165
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Jul 24 15:37:15 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: r2sN_sf.c
 */

/* statically allocated instance data for model: r2sN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_r2sN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_r2sN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1246759640U);
    ssSetChecksumVal(rts, 1, 4184305467U);
    ssSetChecksumVal(rts, 2, 56831874U);
    ssSetChecksumVal(rts, 3, 200160U);
  }
}
