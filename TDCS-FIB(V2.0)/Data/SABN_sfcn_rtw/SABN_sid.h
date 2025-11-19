/*
 * SABN_sid.h
 *
 * Code generation for model "SABN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:23:20 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SABN_sf.c
 */

/* statically allocated instance data for model: SABN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_SABN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_SABN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 4254165217U);
    ssSetChecksumVal(rts, 1, 1513846389U);
    ssSetChecksumVal(rts, 2, 1664803625U);
    ssSetChecksumVal(rts, 3, 728416199U);
  }
}
